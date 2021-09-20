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
  TH1D* oldhist = (TH1D*)oldFile->Get("dataset/Method_BDT/DBT/MVA_BDT_effBvsS");


  TCanvas* c1 = new TCanvas("c1", "A Simple Graph Example", 200, 10, 500, 300);
  Double_t x[100], y[100]; //x: false positive (background eff), y: True positive (signal eff)
  Int_t n = 100;
  for (Int_t i = 0; i < n; i++) {
    x[i] = oldhist->GetBinContent(i);
    y[i] = oldhist->GetBinCenter(i);
  }
  TGraph* gr = new TGraph(n, x, y);
  gr->GetXAxis()->SetTitle("False positive rate (bkg eff.)");
  gr->GetYAxis()->SetTitle("True positive rate (signal eff.)");
  gr->Draw("AC");
}