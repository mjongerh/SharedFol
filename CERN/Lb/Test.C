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

void Test() {
    TFile oldFile("./output/Pt5.0/TMVA.root");
    //void TMVA::mvaeffs(TString dataset, TString fin, Float_t nsignal, Float_t nbackground, Bool_t useTMVAStyle, TString formula)
    TMVA::mvaeffs("./output/Pt5.0/dataset/dataset", "./output/Pt5.0/TMVA.root", 100.0, 1000.0, kTRUE, "S/sqrt(S+B)");
  
}