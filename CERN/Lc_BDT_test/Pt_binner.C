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

void Pt_binner()
{
  TString oldfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/Lc_signal_NEW_100files.root";
  TString newfileDir = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/PtBinTest/";
  TString newfileNamePrefix = "Lc_binTest_signal";

  // PtBins - settings
  const Int_t nPtBins = 7;
  Float_t ptBins[nPtBins + 1] = {0., 1., 2., 4., 6., 8., 12., 100.};

  TFile oldFile(oldfileName);
  TTree* oldtree;

  TString objectstring = "O2hfcandp3full";
  oldFile.GetObject(objectstring, oldtree);
  if (oldtree == nullptr) {
      printf("tree not found");
  }
  Long64_t nentries = oldtree->GetEntries();
  float PtEntry;
  oldtree->SetBranchAddress("fPt", &PtEntry);

for (int i = 0; i < nPtBins; i++) {
  Float_t PtLow = ptBins[i];
  Float_t PtHigh = ptBins[i + 1];

    TString newfileName = newfileDir +newfileNamePrefix + Form("_Pt%.0f.root", PtLow);
    TFile newFile(newfileName, "RECREATE");
    TTree* newtree = oldtree->CloneTree(0);
    newtree->SetName("O2hfcandp3full");

    for (Long64_t i = 0; i < nentries; i++) {
      oldtree->GetEntry(i);
      if (PtEntry >= PtLow && PtEntry < PtHigh)
        newtree->Fill();
    }
    newFile.Write();
}

  

}