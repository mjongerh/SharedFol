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

//#include "/home/mjongerh/alice/O2/Framework/runDataProcessing.h"
//#include "/home/mjongerh/alice/O2/Framework/AnalysisTask.h"
//#include "/home/mjongerh/alice/O2/Detectors/Vertexing/include/DetectorsVertexing/DCAFitterN.h"
//#include "/home/mjongerh/alice/O2/AnalysisDataModel/include/AnalysisDataModel/HFSecondaryVertex.h"
//#include "/home/mjongerh/alice/O2/AnalysisDataModel/include/AnalysisDataModel/HFCandidateSelectionTables.h"
//#include "/home/mjongerh/alice/O2/Analysis/Core/include/AnalysisCore/trackUtilities.h"
//#include "/home/mjongerh/alice/O2/DataFormats/Reconstruction/include/ReconstructionDataFormats/DCA.h"

void TreeDataStripper() {
  TString oldfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2.root";
  TString newfileName = "/home/mjongerh/alice/Run3Analysisvalidation/codeHF/AnalysisResults_trees_O2_stripped.root";

  TFile oldFile(oldfileName);
  //oldFile.cd("DF_0");
  TTree* oldtree;
  TFile newFile(newfileName, "RECREATE");

   for (int i = 0; i < 6000; i++) {
    TString objectstring = Form("DF_%d/O2hfcandp3full", i);
     oldFile.GetObject(objectstring, oldtree);
    if (oldtree == nullptr) {
      continue;
    }

    auto newtree = oldtree->CloneTree();
    newtree->Print();

    /*oldFile.GetObject("DF_0/O2hfcandp3fullp", oldtree);
    newtree = oldtree->CloneTree();
    newtree->Print();

    oldFile.GetObject("DF_0/O2hfcandp3fulle", oldtree);
    newtree = oldtree->CloneTree();
    newtree->Print();*/
  }

  newFile.Write();
}