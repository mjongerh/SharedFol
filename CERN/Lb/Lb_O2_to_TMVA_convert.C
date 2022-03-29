#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TClass.h"

/// <summary>
/// Macro to convert the output of an O2 task, to split root files for Pt bins and sig/bkg, to be used for TMVA
/// </summary>
void Lb_O2_to_TMVA_convert()
{
  TString oldfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2.root";
  TString tempfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_TMP.root";
  //TString newfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_converted.root";
  TString newfileDir = "/home/mjongerh/Lb_data/LbStrictPIDcutSel_data/Trees/";
  TString newfileNamePrefix = "Lb_binned";
  
  TString createdir = "mkdir -p " + newfileDir; //create directory if it doesn't exist yet
  gSystem->Exec(createdir);
  
  // PtBins - settings
  const Int_t nPtBins = 12;
  Float_t ptBins[nPtBins + 1] = {0., 0.5, 1., 2., 3., 4., 5., 7., 10., 13., 16., 20., 24.};

  TFile oldFile(oldfileName);
  TTree* oldtree;
  TList* list = new TList;

  for (int i = 0; i < 6000; i++) {          //Merge all output from all AOD files and only take relevant tree
    TString objectstring = Form("DF_%d/O2hfcandlbfull", i);
    oldFile.GetObject(objectstring, oldtree);
    if (oldtree == nullptr) {
      continue;
    }
    list->Add(oldtree);
  }
  TFile TMPFile(tempfileName, "RECREATE");

  auto newtree = TTree::MergeTrees(list);
  newtree->SetName("O2hfcandlbfull");

  TMPFile.Write();

  TTree* tmptree;

  TMPFile.GetObject("O2hfcandlbfull", tmptree);
  if (tmptree == nullptr) {
    printf("tree not found");
  }
  
  Long64_t nentries = tmptree->GetEntries();
  float PtEntry;
  tmptree->SetBranchAddress("fPt", &PtEntry);
  Char_t MCflagEntry;
  tmptree->SetBranchAddress("fMCflag", &MCflagEntry);

  for (int i = 0; i < nPtBins; i++) { //Split all events into different Pt bins
    Float_t PtLow = ptBins[i];
    Float_t PtHigh = ptBins[i + 1];
    TString SB = "_bkg";
    for (Int_t j = 0; j < 2; j++){ //j==1 signal, j==0 bkg
      if (j == 1) SB = "_signal";

      TString newfileName = newfileDir + newfileNamePrefix + SB + Form("_Pt%.1f.root", PtLow);
      TFile newFile(newfileName, "RECREATE");
      TTree* newtree = tmptree->CloneTree(0);
      newtree->SetName("O2hfcandlbfull");

      for (Long64_t i = 0; i < nentries; i++) {
        tmptree->GetEntry(i);
        if ((Float_t)MCflagEntry != j) continue; //skip if not correct sig/bkg
        if (PtEntry >= PtLow && PtEntry < PtHigh)
          newtree->Fill();
      }
      newFile.Write();
    }
  }

  TString DelTMPFile = "rm " + tempfileName;
  gSystem->Exec(DelTMPFile);
}