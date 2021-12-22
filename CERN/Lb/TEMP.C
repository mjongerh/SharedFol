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
    Double_t xAxis1[13] = {0, 0.5, 1, 2, 3, 4, 5, 7, 10, 13, 16, 20, 24};
  Double_t NEvents = 210000000000000.0;
    //=========Macro generated from canvas: Canvas_1/Canvas_1
    //=========  (Mon Dec 20 12:50:06 2021) by ROOT version 6.25/01
    TCanvas* Canvas_1 = new TCanvas("Canvas_1", "Canvas_1", 367, 161, 1295, 807);
    Canvas_1->Range(-3, -0.04304262, 27, 0.3873835);
    Canvas_1->SetFillColor(0);
    Canvas_1->SetBorderMode(0);
    Canvas_1->SetBorderSize(2);
    Canvas_1->SetFrameBorderMode(0);
    Canvas_1->SetFrameBorderMode(0);

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
    
    Int_t ci2;
    ci2 = TColor::GetColor("#0000ff");
    eff__2->SetLineColor(ci2);
    eff__2->SetLineWidth(2);

    eff__1->Draw("");
    eff__2->Draw("same");
    auto legend1 = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend1->AddEntry(eff__1, "Panos' cuts", "f");
    legend1->AddEntry(eff__2, "+BDT cut", "f");
    legend1->Draw("");

    Canvas_1->Modified();
    Canvas_1->cd();
    Canvas_1->SetSelected(Canvas_1);

    TCanvas* Canvas_2 = new TCanvas("Canvas_2", "Canvas_2", 422, 161, 944, 763);
    Canvas_2->Range(-3, 1.0e-10, 27, 1.0e-6);
    Canvas_2->SetLogy();
    Canvas_2->SetFillColor(0);
    Canvas_2->SetBorderMode(0);
    Canvas_2->SetBorderSize(2);
    Canvas_2->SetFrameBorderMode(0);
    Canvas_2->SetFrameBorderMode(0);

    TH1D* hBkgPerEvent__1 = new TH1D("hBkgPerEvent__1", "", 12, xAxis1);
    hBkgPerEvent__1->SetBinContent(2, 2.10095e-06);
    hBkgPerEvent__1->SetBinContent(3, 1.39038e-06);
    hBkgPerEvent__1->SetBinContent(4, 2.174787e-06);
    hBkgPerEvent__1->SetBinContent(5, 1.964767e-06);
    hBkgPerEvent__1->SetBinContent(6, 1.324055e-06);
    hBkgPerEvent__1->SetBinContent(7, 1.859376e-06);
    hBkgPerEvent__1->SetBinContent(8, 2.196035e-06);
    hBkgPerEvent__1->SetBinContent(9, 1.062691e-06);
    hBkgPerEvent__1->SetBinContent(10, 1.670859e-06);
    hBkgPerEvent__1->SetBinContent(11, 2.041053e-06);
    hBkgPerEvent__1->SetBinContent(12, 2.162131e-06);
    hBkgPerEvent__1->SetEntries(11);
    hBkgPerEvent__1->SetStats(0);

    TH1D* hBkgPerEvent__2 = new TH1D("hBkgPerEvent__2", "", 12, xAxis1);
    //hBkgPerEvent__2->SetBinContent(2, 2.10095e-06*0.0);
    //hBkgPerEvent__2->SetBinContent(3, 1.39038e-06*0.0);
    //hBkgPerEvent__2->SetBinContent(4, 2.174787e-06*0.0);
    hBkgPerEvent__2->SetBinContent(5, 1.964767e-06*0.00028);
    hBkgPerEvent__2->SetBinContent(6, 1.324055e-06*0.000802);
    hBkgPerEvent__2->SetBinContent(7, 1.859376e-06*0.002942);
    hBkgPerEvent__2->SetBinContent(8, 2.196035e-06*0.006728);
    hBkgPerEvent__2->SetBinContent(9, 1.062691e-06*0.01492);
    hBkgPerEvent__2->SetBinContent(10, 1.670859e-06*0.02216);
    hBkgPerEvent__2->SetBinContent(11, 2.041053e-06*0.02539);
    hBkgPerEvent__2->SetBinContent(12, 2.162131e-06*0.02582);
    hBkgPerEvent__2->SetEntries(11);
    hBkgPerEvent__2->SetStats(0);

    hBkgPerEvent__1->SetLineColor(ci);
    hBkgPerEvent__1->SetLineWidth(3);
    hBkgPerEvent__1->GetXaxis()->SetTitle("p_{T}(#lambda_b^0)(GeV/c)");
    hBkgPerEvent__1->GetXaxis()->SetLabelFont(42);
    hBkgPerEvent__1->GetXaxis()->SetLabelOffset(0.015);
    hBkgPerEvent__1->GetXaxis()->SetTitleSize(0.045);
    hBkgPerEvent__1->GetXaxis()->SetTitleOffset(1);
    hBkgPerEvent__1->GetXaxis()->SetTitleFont(42);
    hBkgPerEvent__1->GetYaxis()->SetTitle("Bkg/nEvents");
    hBkgPerEvent__1->GetYaxis()->CenterTitle(true);
    hBkgPerEvent__1->GetYaxis()->SetLabelFont(42);
    hBkgPerEvent__1->GetYaxis()->SetLabelOffset(0.01);
    hBkgPerEvent__1->GetYaxis()->SetTitleSize(0.045);
    hBkgPerEvent__1->GetYaxis()->SetTitleOffset(0.8);
    hBkgPerEvent__1->GetYaxis()->SetTitleFont(42);
    hBkgPerEvent__1->GetZaxis()->SetLabelFont(42);
    hBkgPerEvent__1->GetZaxis()->SetTitleOffset(1);
    hBkgPerEvent__1->GetZaxis()->SetTitleFont(42);
    
    hBkgPerEvent__2->SetLineColor(ci2);
    hBkgPerEvent__2->SetLineWidth(2);

    hBkgPerEvent__2->Draw("");
    hBkgPerEvent__1->Draw("same");
    auto legend2 = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend2->AddEntry(hBkgPerEvent__1, "Panos' cuts", "f");
    legend2->AddEntry(hBkgPerEvent__2, "+BDT cut", "f");
    legend2->Draw("");

    Canvas_2->Modified();
    Canvas_2->cd();
    Canvas_2->SetSelected(Canvas_2);

    TCanvas* Canvas_3 = new TCanvas("Canvas_3", "Canvas_3", 422, 161, 944, 763);
    Canvas_3->SetFillColor(0);
    Canvas_3->SetBorderMode(0);
    Canvas_3->SetBorderSize(2);
    Canvas_3->SetFrameBorderMode(0);
    Canvas_3->SetFrameBorderMode(0);

    TH1F* histosignal__1 = new TH1F("histosignal__1", "", 12, xAxis1);
    histosignal__1->SetBinContent(5, 7983.665 / NEvents);
    histosignal__1->SetBinContent(6, 60466.08 / NEvents);
    histosignal__1->SetBinContent(7, 153818.3 / NEvents);
    histosignal__1->SetBinContent(8, 505957.7 / NEvents);
    histosignal__1->SetBinContent(9, 697078.5 / NEvents);
    histosignal__1->SetBinContent(10, 489227.4 / NEvents);
    histosignal__1->SetBinContent(11, 281272 / NEvents);
    histosignal__1->SetBinContent(12, 176357.4 / NEvents);

    histosignal__1->SetEntries(100011);

    TH1F* histosignal__2 = new TH1F("histosignal__2", "", 12, xAxis1);
    histosignal__2->SetBinContent(5, 7983.665 * 0.5244 / NEvents);
    histosignal__2->SetBinContent(6, 60466.08*0.6238 / NEvents);
    histosignal__2->SetBinContent(7, 153818.3*0.7508 / NEvents);
    histosignal__2->SetBinContent(8, 505957.7*0.8071 / NEvents);
    histosignal__2->SetBinContent(9, 697078.5*0.8819 / NEvents);
    histosignal__2->SetBinContent(10, 489227.4 * 0.9 / NEvents);
    histosignal__2->SetBinContent(11, 281272 * 0.8836 / NEvents);
    histosignal__2->SetBinContent(12, 176357.4 * 0.8776 / NEvents);
    histosignal__2->SetEntries(100011);

    histosignal__1->SetLineColor(ci);
    histosignal__1->GetXaxis()->SetTitle("p_{T} (GeV)");
    histosignal__1->GetXaxis()->SetRange(1, 100);
    histosignal__1->GetXaxis()->SetLabelFont(42);
    histosignal__1->GetXaxis()->SetTitleOffset(1);
    histosignal__1->GetXaxis()->SetTitleFont(42);
    histosignal__1->GetYaxis()->SetTitle("N #lambda_b^0 signal events per event");
    histosignal__1->GetYaxis()->SetLabelFont(42);
    histosignal__1->GetYaxis()->SetTitleFont(42);
    histosignal__1->GetZaxis()->SetLabelFont(42);
    histosignal__1->GetZaxis()->SetTitleOffset(1);
    histosignal__1->GetZaxis()->SetTitleFont(42);
    

    histosignal__2->SetLineColor(ci2);
    histosignal__2->SetLineWidth(2);

    histosignal__1->Draw("");
    histosignal__2->Draw("same");
    auto legend3 = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend3->AddEntry(hBkgPerEvent__1, "Panos' cuts", "f");
    legend3->AddEntry(hBkgPerEvent__2, "+BDT cut", "f");
    legend3->Draw("");

    Canvas_3->Modified();
    Canvas_3->cd();
    Canvas_3->SetSelected(Canvas_3);

    TCanvas* Canvas_4 = new TCanvas("Canvas_4", "Canvas_4", 422, 161, 944, 763);
    Canvas_4->Range(-3, 1.0, 27, 1000.0);
    Canvas_4->SetLogy();
    Canvas_4->SetFillColor(0);
    Canvas_4->SetBorderMode(0);
    Canvas_4->SetBorderSize(2);
    Canvas_4->SetFrameBorderMode(0);
    Canvas_4->SetFrameBorderMode(0);

    TH1F* histosignf__1 = new TH1F("histosignf__1", "", 12, xAxis1);
    histosignf__1->SetBinContent(3, 0.4672185);
    histosignf__1->SetBinContent(4, 2.829209);
    histosignf__1->SetBinContent(5, 7.571151);
    histosignf__1->SetBinContent(6, 30.31494);
    histosignf__1->SetBinContent(7, 35.24529);
    histosignf__1->SetBinContent(8, 22.76938);
    histosignf__1->SetBinContent(9, 18.81654);
    histosignf__1->SetBinContent(10, 9.412499);
    histosignf__1->SetBinContent(11, 3.197298);
    histosignf__1->SetBinContent(12, 1.019512);
    histosignf__1->SetEntries(100011);
    
    TH1F* histosignf__2 = new TH1F("histosignf__2", "Significance Lb in pp 14TeV", 12, xAxis1);
    histosignf__2->SetBinContent(3, 22.9432);
    histosignf__2->SetBinContent(4, 115.355);
    histosignf__2->SetBinContent(5, 211.364);
    histosignf__2->SetBinContent(6, 340.51);
    histosignf__2->SetBinContent(7, 543.251);
    histosignf__2->SetBinContent(8, 557.119);
    histosignf__2->SetBinContent(9, 329.195);
    histosignf__2->SetBinContent(10, 112.282);
    histosignf__2->SetBinContent(11, 53.5673);
    histosignf__2->SetBinContent(12, 23.1136);
    histosignf__2->SetEntries(100011);

    histosignf__1->SetLineColor(ci);
    histosignf__1->SetLineWidth(2);
    histosignf__2->GetXaxis()->SetTitle("p_{T} (GeV)");
    histosignf__2->GetXaxis()->SetRange(1, 1000);
    histosignf__2->GetXaxis()->SetLabelFont(42);
    histosignf__2->GetXaxis()->SetTitleOffset(1);
    histosignf__2->GetXaxis()->SetTitleFont(42);
    histosignf__2->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
    histosignf__2->GetYaxis()->SetLabelFont(42);
    histosignf__2->GetYaxis()->SetTitleFont(42);
    histosignf__2->GetZaxis()->SetLabelFont(42);
    histosignf__2->GetZaxis()->SetTitleOffset(1);
    histosignf__2->GetZaxis()->SetTitleFont(42);
    
    histosignf__2->GetYaxis()->SetRangeUser(0.1, 1000);

    histosignf__2->SetLineColor(ci2);
    histosignf__2->SetLineWidth(2);
    histosignf__2->Draw("");
    histosignf__1->Draw("same");

    auto legend4 = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend4->AddEntry(histosignf__1, "Panos' cuts", "f");
    legend4->AddEntry(histosignf__2, "+BDT cut", "f");
    legend4->Draw("");

    Canvas_4->Modified();
    Canvas_4->cd();
    Canvas_4->SetSelected(Canvas_4);

    TCanvas* Canvas_5 = new TCanvas("Canvas_5", "Canvas_1", 1143, 281, 798, 757);
    Canvas_5->Range(-3, -17.34724, 27, 156.1252);
    Canvas_5->SetFillColor(0);
    Canvas_5->SetBorderMode(0);
    Canvas_5->SetBorderSize(2);
    Canvas_5->SetFrameBorderMode(0);
    Canvas_5->SetFrameBorderMode(0);

    TH1F* histosignf__3 = new TH1F("histosignf__3", "Significance Lb in pp 14TeV", 12, xAxis1);
    histosignf__3->SetBinContent(3, 0.9710867);
    histosignf__3->SetBinContent(4, 9.098567);
    histosignf__3->SetBinContent(5, 23.91249);
    histosignf__3->SetBinContent(6, 47.17467);
    histosignf__3->SetBinContent(7, 101.5759);
    histosignf__3->SetBinContent(8, 132.1695);
    histosignf__3->SetBinContent(9, 82.77902);
    histosignf__3->SetBinContent(10, 23.33332);
    histosignf__3->SetBinContent(11, 25.79671);
    histosignf__3->SetBinContent(13, 1.31619e-07);

    TH1F* histosignf__4 = new TH1F("histosignf__4", "Significance Lb in PbPb 5.02TeV, Nevt=3.8E10", 12, xAxis1);
    histosignf__4->SetBinContent(3, 10.765); //after BDT
    histosignf__4->SetBinContent(4, 36.5129);
    histosignf__4->SetBinContent(5, 62.2044);
    histosignf__4->SetBinContent(6, 89.5211);
    histosignf__4->SetBinContent(7, 149.382);
    histosignf__4->SetBinContent(8, 178.551);
    histosignf__4->SetBinContent(9, 128.045);
    histosignf__4->SetBinContent(10, 75.2491);
    histosignf__4->SetBinContent(11, 61.535);
    histosignf__4->SetBinContent(13, 1.31619e-07);

    histosignf__4->SetLineWidth(2);
    histosignf__4->GetXaxis()->SetTitle("p_{T} (GeV)");
    histosignf__4->GetXaxis()->SetRange(1, 100);
    histosignf__4->GetXaxis()->SetLabelFont(42);
    histosignf__4->GetXaxis()->SetTitleOffset(1);
    histosignf__4->GetXaxis()->SetTitleFont(42);
    histosignf__4->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
    histosignf__4->GetYaxis()->SetLabelFont(42);
    histosignf__4->GetYaxis()->SetTitleFont(42);
    histosignf__4->GetZaxis()->SetLabelFont(42);
    histosignf__4->GetZaxis()->SetTitleOffset(1);
    histosignf__4->GetZaxis()->SetTitleFont(42);
    
    histosignf__3->SetLineColor(ci);
    histosignf__3->SetLineWidth(2);
    histosignf__4->Draw("");
    histosignf__3->Draw("same");

    auto legend5 = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend5->AddEntry(histosignf__3, "Panos' cuts", "f");
    legend5->AddEntry(histosignf__4, "+BDT cut", "f");
    legend5->Draw("");

    Canvas_5->cd();
    Canvas_5->Modified();
    Canvas_5->SetSelected(Canvas_1);
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