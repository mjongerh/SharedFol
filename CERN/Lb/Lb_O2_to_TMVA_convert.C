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

void Lb_O2_to_TMVA_convert()
{
  TString oldfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2.root";
  TString tempfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_TMP.root";
  //TString newfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_converted.root";
  TString newfileDir = "/home/mjongerh/Lb_data/Trees/";
  TString newfileNamePrefix = "Lb_binned_signal";
  
  TString createdir = "mkdir -p " + newfileDir; //create directory if it doesn't exist yet
  gSystem->Exec(function);
  
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
  TFile oldFile(oldfileName);
  TTree* tmptree;

  TString objectstring = "O2hfcandlbfull"; //will probably complain, since object does not exist. only the leaves are placed in the tmpfile
  tempfileName.GetObject(objectstring, tmptree);
  if (tmptree == nullptr) {
    printf("tree not found");
  }
  Long64_t nentries = tmptree->GetEntries();
  float PtEntry;
  oldtree->SetBranchAddress("fPt", &PtEntry);

  for (int i = 0; i < nPtBins; i++) {
    Float_t PtLow = ptBins[i];
    Float_t PtHigh = ptBins[i + 1];

    TString newfileName = newfileDir + newfileNamePrefix + Form("_Pt%.0f.root", PtLow);
    TFile newFile(newfileName, "RECREATE");
    TTree* newtree = tmptree->CloneTree(0);
    newtree->SetName("O2hfcandlbfull");

    for (Long64_t i = 0; i < nentries; i++) {
      tmptree->GetEntry(i);
      if (PtEntry >= PtLow && PtEntry < PtHigh)
        newtree->Fill();
    }
    newFile.Write();
  }

  TString function = "rm " + tempfileName;
  gSystem->Exec(function);
}