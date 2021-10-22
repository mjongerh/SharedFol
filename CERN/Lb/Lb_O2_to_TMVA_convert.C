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

void TreeDataStripper()
{
  TString oldfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2.root";
  TString newfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_stripped.root";

  TFile oldFile(oldfileName);
  TTree* oldtree;
  TList* list = new TList;

  for (int i = 0; i < 6000; i++) {
    TString objectstring = Form("DF_%d/O2hfcandp3full", i);
    oldFile.GetObject(objectstring, oldtree);
    if (oldtree == nullptr) {
      continue;
    }
    list->Add(oldtree);
  }
  TFile newFile(newfileName, "RECREATE");

  auto newtree = TTree::MergeTrees(list);
  newtree->SetName("O2hfcandp3full");

  newFile.Write();
}