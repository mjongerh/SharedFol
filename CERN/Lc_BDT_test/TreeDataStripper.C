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

void TreeDataStripper() {
  TString oldfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2.root";
  TString newfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_stripped.root";

  TFile oldFile(oldfileName);
  oldFile->cd("DF_0");
  TTree* oldtree;
  oldFile.GetObject("T", oldtree);

  TFile newFile(newfileName, "recreate");
  auto newtree = oldtree->CloneTree();

  newtree->Print();
  newFile.Write();
}