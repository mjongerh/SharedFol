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

#include "TInterpreter.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH2.h"
#include "TNtuple.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TSystem.h"
#include "TInterpreter.h"

void Lc_plots()
{

  Double_t xAxis2[11] = {0, 1, 2, 3, 4, 5, 6, 8, 12, 24, 36};

  TCanvas* Canvas_1 = new TCanvas("Canvas_1", "Canvas_1", 367, 161, 1295, 807);
  TH1D* hBkgPerEvent__2 = new TH1D("hBkgPerEvent__2", "", 10, xAxis2);
  hBkgPerEvent__2->SetBinContent(2, 0.0721559);
  hBkgPerEvent__2->SetBinContent(3, 0.0470498);
  hBkgPerEvent__2->SetBinContent(4, 0.0161972);
  hBkgPerEvent__2->SetBinContent(5, 0.00639254);
  hBkgPerEvent__2->SetBinContent(6, 0.0032242);
  hBkgPerEvent__2->SetBinContent(7, 0.00206754);
  hBkgPerEvent__2->SetBinContent(8, 0.00132713);
  hBkgPerEvent__2->SetBinContent(9, 0.000547367);
  hBkgPerEvent__2->SetBinContent(10, 0.000132626);
  hBkgPerEvent__2->SetEntries(9);
  hBkgPerEvent__2->SetStats(0);

  auto ci = TColor::GetColor("#ff0000");
  hBkgPerEvent__2->SetLineColor(ci);
  hBkgPerEvent__2->SetLineWidth(3);
  hBkgPerEvent__2->GetXaxis()->SetTitle("p_{T}(#Lambda_{c}^{+})(GeV/c)");
  hBkgPerEvent__2->GetXaxis()->SetLabelFont(42);
  hBkgPerEvent__2->GetXaxis()->SetLabelOffset(0.015);
  hBkgPerEvent__2->GetXaxis()->SetTitleSize(0.045);
  hBkgPerEvent__2->GetXaxis()->SetTitleOffset(1);
  hBkgPerEvent__2->GetXaxis()->SetTitleFont(42);
  hBkgPerEvent__2->GetYaxis()->SetTitle("Bkg/nEvents");
  hBkgPerEvent__2->GetYaxis()->CenterTitle(true);
  hBkgPerEvent__2->GetYaxis()->SetLabelFont(42);
  hBkgPerEvent__2->GetYaxis()->SetLabelOffset(0.01);
  hBkgPerEvent__2->GetYaxis()->SetTitleSize(0.045);
  hBkgPerEvent__2->GetYaxis()->SetTitleOffset(0.8);
  hBkgPerEvent__2->GetYaxis()->SetTitleFont(42);
  hBkgPerEvent__2->GetZaxis()->SetLabelFont(42);
  hBkgPerEvent__2->GetZaxis()->SetTitleOffset(1);
  hBkgPerEvent__2->GetZaxis()->SetTitleFont(42);
  hBkgPerEvent__2->Draw("");

  TCanvas* Canvas_2 = new TCanvas("Canvas_2", "Canvas_1", 367, 161, 1295, 807);
  TH1F* histosignal__1 = new TH1F("histosignal__1", "", 10, xAxis2);
  histosignal__1->SetBinContent(1, 4.92914e+08/3.8e10);
  histosignal__1->SetBinContent(2, 2.21432e+09/3.8e10);
  histosignal__1->SetBinContent(3, 3.10382e+09/3.8e10);
  histosignal__1->SetBinContent(4, 2.82725e+09/3.8e10);
  histosignal__1->SetBinContent(5, 2.23624e+09/3.8e10);
  histosignal__1->SetBinContent(6, 1.35756e+09/3.8e10);
  histosignal__1->SetBinContent(7, 1.48177e+09/3.8e10);
  histosignal__1->SetBinContent(8, 7.71874e+08/3.8e10);
  histosignal__1->SetBinContent(9, 1.46573e+08/3.8e10);
  histosignal__1->SetBinContent(10, 1.36606e+07/3.8e10));
  histosignal__1->SetBinError(2, 25476.9/3.8e10));
  histosignal__1->SetBinError(3, 14678.1/3.8e10));
  histosignal__1->SetBinError(4, 9457.04/3.8e10));
  histosignal__1->SetBinError(5, 7514.49/3.8e10));
  histosignal__1->SetBinError(6, 8792.39/3.8e10));
  histosignal__1->SetBinError(7, 6455.13/3.8e10));
  histosignal__1->SetBinError(8, 9924.99/3.8e10));
  histosignal__1->SetBinError(9, 33541.4/3.8e10));
  histosignal__1->SetBinError(10, 177081/3.8e10));

  auto ci2 = TColor::GetColor("#0000ff");

  histosignal__1->SetLineColor(ci2);
  histosignal__1->SetLineWidth(3);
  histosignal__1->GetXaxis()->SetTitle("p_{T}(#Lambda_{c}^{+})(GeV/c)");
  histosignal__1->GetXaxis()->SetLabelFont(42);
  histosignal__1->GetXaxis()->SetLabelOffset(0.015);
  histosignal__1->GetXaxis()->SetTitleSize(0.045);
  histosignal__1->GetXaxis()->SetTitleOffset(1);
  histosignal__1->GetXaxis()->SetTitleFont(42);
  histosignal__1->GetYaxis()->SetTitle("Sig/nEvents");
  histosignal__1->GetYaxis()->CenterTitle(true);
  histosignal__1->GetYaxis()->SetLabelFont(42);
  histosignal__1->GetYaxis()->SetLabelOffset(0.01);
  histosignal__1->GetYaxis()->SetTitleSize(0.045);
  histosignal__1->GetYaxis()->SetTitleOffset(0.8);
  histosignal__1->GetYaxis()->SetTitleFont(42);
  histosignal__1->GetZaxis()->SetLabelFont(42);
  histosignal__1->GetZaxis()->SetTitleOffset(1);
  histosignal__1->GetZaxis()->SetTitleFont(42);
  histosignal__1->Draw("");

}