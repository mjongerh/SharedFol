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

void TEMP() {
    //=========Macro generated from canvas: Canvas_1/Canvas_1
    //=========  (Mon Dec 20 12:50:06 2021) by ROOT version 6.25/01
    TCanvas* Canvas_1 = new TCanvas("Canvas_1", "Canvas_1", 367, 161, 1295, 807);
    Canvas_1->Range(-3, -0.04304262, 27, 0.3873835);
    Canvas_1->SetFillColor(0);
    Canvas_1->SetBorderMode(0);
    Canvas_1->SetBorderSize(2);
    Canvas_1->SetFrameBorderMode(0);
    Canvas_1->SetFrameBorderMode(0);
    Double_t xAxis1[13] = {0, 0.5, 1, 2, 3, 4, 5, 7, 10, 13, 16, 20, 24};

    TH1F* eff__1 = new TH1F("eff__1", "", 12, xAxis1);
    eff__1->SetBinContent(3, 0.0005337445);
    eff__1->SetBinContent(4, 0.004258425);
    eff__1->SetBinContent(5, 0.0125);
    eff__1->SetBinContent(6, 0.02934313);
    eff__1->SetBinContent(7, 0.05736706);
    eff__1->SetBinContent(8, 0.1166735);
    eff__1->SetBinContent(9, 0.1777021);
    eff__1->SetBinContent(10, 0.2242961);
    eff__1->SetBinContent(11, 0.2565476);
    eff__1->SetBinContent(12, 0.3043478);
    eff__1->SetBinError(3, 0.0001779623);
    eff__1->SetBinError(4, 0.0004164637);
    eff__1->SetBinError(5, 0.0006944974);
    eff__1->SetBinError(6, 0.001142488);
    eff__1->SetBinError(7, 0.001377074);
    eff__1->SetBinError(8, 0.002443946);
    eff__1->SetBinError(9, 0.005137535);
    eff__1->SetBinError(10, 0.009320557);
    eff__1->SetBinError(11, 0.0138522);
    eff__1->SetBinError(12, 0.02359593);
    eff__1->SetEntries(1606.869);
    eff__1->SetStats(0);

    TH1F* eff__2 = new TH1F("eff__2", "", 12, xAxis1); // After BDT cut
    eff__2->SetBinContent(3, 0.0005337445*0.0);
    eff__2->SetBinContent(4, 0.004258425*0.0);
    eff__2->SetBinContent(5, 0.0125*0.5244);
    eff__2->SetBinContent(6, 0.02934313*0.6238);
    eff__2->SetBinContent(7, 0.05736706*0.7508);
    eff__2->SetBinContent(8, 0.1166735*0.8071);
    eff__2->SetBinContent(9, 0.1777021*0.8819);
    eff__2->SetBinContent(10, 0.2242961*0.9);
    eff__2->SetBinContent(11, 0.2565476*0.8836);
    eff__2->SetBinContent(12, 0.3043478*0.8776);
    eff__2->SetBinError(3, 0.0001779623 * 0.0);
    eff__2->SetBinError(4, 0.0004164637 * 0.0);
    eff__2->SetBinError(5, 0.0006944974 * 0.5244);
    eff__2->SetBinError(6, 0.001142488 * 0.6238);
    eff__2->SetBinError(7, 0.001377074 * 0.7508);
    eff__2->SetBinError(8, 0.002443946 * 0.8071);
    eff__2->SetBinError(9, 0.005137535 * 0.8819);
    eff__2->SetBinError(10, 0.009320557 * 0.9);
    eff__2->SetBinError(11, 0.0138522 * 0.8836);
    eff__2->SetBinError(12, 0.02359593 * 0.8776);
    eff__2->SetEntries(1606.869);
    eff__2->SetStats(0);

    Int_t ci;      // for color index setting
    TColor* color; // for color definition with alpha
    ci = TColor::GetColor("#ff0000");
    eff__1->SetLineColor(ci);
    eff__1->SetLineWidth(2);
    eff__1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    eff__1->GetXaxis()->SetRange(1, 300);
    eff__1->GetXaxis()->SetLabelFont(42);
    eff__1->GetXaxis()->SetLabelOffset(0.015);
    eff__1->GetXaxis()->SetTitleSize(0.045);
    eff__1->GetXaxis()->SetTitleOffset(1);
    eff__1->GetXaxis()->SetTitleFont(42);
    eff__1->GetYaxis()->SetTitle(" Reconstruction Efficiency");
    eff__1->GetYaxis()->CenterTitle(true);
    eff__1->GetYaxis()->SetLabelFont(42);
    eff__1->GetYaxis()->SetLabelOffset(0.01);
    eff__1->GetYaxis()->SetTitleSize(0.045);
    eff__1->GetYaxis()->SetTitleOffset(0.8);
    eff__1->GetYaxis()->SetTitleFont(42);
    eff__1->GetZaxis()->SetLabelFont(42);
    eff__1->GetZaxis()->SetTitleOffset(1);
    eff__1->GetZaxis()->SetTitleFont(42);
    
    ci2 = TColor::GetColor("#00ff00");
    eff__2->SetLineColor(ci2);
    eff__2->SetLineWidth(2);

    auto legend = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend->AddEntry(eff__1, "Panos' cuts", "f");
    legend->AddEntry(eff__2, "+BDT", "f");
    legend->Draw();

    eff__1->Draw("");
    eff__2->Draw("");
    Canvas_1->Modified();
    Canvas_1->cd();
    Canvas_1->SetSelected(Canvas_1);
}

/*
  TFile oldFile("./Trees/Trees/Lb_binned_bkg_Pt5.00.root");
  TTree* oldtree;
  oldFile.GetObject("O2hfcandlbfull", oldtree);
  int entries = oldtree->GetEntries();
  float chi2PCAEntry;
  oldtree->SetBranchAddress("fChi2PCA", &chi2PCAEntry);

  TCanvas* c1 = new TCanvas("c1", "Histogram Drawing Options", 200, 10, 700, 900);
  auto Histo = new TH1F("Histo", "Chi2PCA",100, 0.0, 0.0000012);
  for (int i = 0; i < entries; i++) {
    oldtree->GetEntry(i);
    Histo->Fill(chi2PCAEntry);
  }
  Histo->Draw();
  
  c1->Modified();
  c1->Update();
  TFile myfile("temp.root", "RECREATE");
  Histo->Write();
  gBenchmark->Show("temp");
*/