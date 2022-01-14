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
  TFile finput("./outputstrictcut/foutputLambda_b_PbPb_varRaa.root"); 
  TH1F* hbkg = (TH1F*)finput.Get("hBkgPerEvent");
  TH1F* hsig = (TH1F*)finput.Get("histosignal");
  Double_t PtBins[13] = {0., 0.5, 1., 2., 3., 4., 5., 7., 10., 13., 16., 20., 24.};
  long Nevents = 55000000000;//PbPb new //pp = 210 000 000 000 000; //PbPb old = 38 376 000 000
  for (Int_t i = 0; i < 12; i++) {
    cout << "Pt " << PtBins[i] << endl
         << " sig " << hsig->GetBinContent(i + 1) << " pm " << hsig->GetBinError(i + 1) << endl
         << " bkg " << hbkg->GetBinContent(i+1)*Nevents << endl;
  }
    
    
    // test to use mvaeffs in a macro
    //gROOT->SetBatch(kTRUE);
    ////TFile oldFile("./output/Pt5.0/TMVA.root");
    //TMVA::mvas("./output/Pt5.0/dataset/dataset", "./output/Pt5.0/TMVA.root", static_cast<TMVA::HistType>(3));
    //gROOT->SetBatch(kTRUE);
    ////void TMVA::mvaeffs(TString dataset, TString fin, Float_t nsignal, Float_t nbackground, Bool_t useTMVAStyle, TString formula)
    //TMVA::mvaeffs("./output/Pt5.0/dataset/dataset", "./output/Pt5.0/TMVA.root", 100.0, 1000.0, kTRUE, "S/sqrt(S+B)");
  
}