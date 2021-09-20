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

void HistoMaker() {
  TString oldfileDir = "~/Desktop/SharedFol/CERN/Lc_BDT_test/output/";
  TString filename = oldfileDir + "Pt1/TMVA.root";
  TFile* oldFile = new TFile(filename);
  TH1D* oldhist = (TH1D*)oldFile->Get("dataset/Method_BDT/BDT/MVA_BDT_effBvsS");


  Double_t x[101], y[101]; //x: false positive (background eff), y: True positive (signal eff)
  Int_t n = 100;
  for (Int_t i = 0; i < n; i++) {
    x[i] = oldhist->GetBinContent(i+1);
    y[i] = oldhist->GetBinCenter(i+1);
  }
  x[100] = 1.0;
  y[100] = 1.0;
  TCanvas* c1 = new TCanvas("c1", "A Simple Graph Example", 200, 10, 500, 300);
  TGraph* gr = new TGraph(n+1, x, y);
  gr->GetXaxis()->SetTitle("False positive rate (bkg eff.)");
  gr->GetYaxis()->SetTitle("True positive rate (signal eff.)");
  gr->Draw("AC");
}