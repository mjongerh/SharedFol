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

#include "/home/mjongerh/alice/Run3Analysisvalidation/Framework/runDataProcessing.h"
#include "/home/mjongerh/alice/Run3Analysisvalidation/Framework/AnalysisTask.h"
#include "/home/mjongerh/alice/O2/Detectors/Vertexing/include/DetectorsVertexing/DCAFitterN.h"
#include "AnalysisDataModel/HFSecondaryVertex.h"
#include "AnalysisDataModel/HFCandidateSelectionTables.h"
#include "AnalysisCore/trackUtilities.h"
#include "/home/mjongerh/alice/O2/DataFormats/Reconstruction/include/ReconstructionDataFormats/DCA.h"


void TreeDataStripper() {
  TString oldfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2.root";
  TString newfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_stripped.root";

  TFile oldFile(oldfileName);
  oldFile.cd("DF_0");
  TTree* oldtree;
  oldFile.GetObject("T", oldtree);

  TFile newFile(newfileName, "recreate");
  auto newtree = oldtree->CloneTree();

  newtree->Print();
  newFile.Write();
}