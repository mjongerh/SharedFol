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
  Double_t NEventsPbPb = 55000000000.0;
    //=========Macro generated from canvas: Canvas_1/Canvas_1
    //=========  (Mon Dec 20 12:50:06 2021) by ROOT version 6.25/01
    TCanvas* Canvas_1 = new TCanvas("Canvas_1", "Canvas_1", 367, 161, 1295, 807);
    Canvas_1->Range(-3, -0.04304262, 27, 0.3873835);
    Canvas_1->SetFillColor(0);
    Canvas_1->SetBorderMode(0);
    Canvas_1->SetBorderSize(2);
    Canvas_1->SetFrameBorderMode(0);
    Canvas_1->SetFrameBorderMode(0);

    TH1F* eff__1 = new TH1F("eff__1", "recon. eff. Lb", 12, xAxis1);
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

    TH1F* eff__2 = new TH1F("eff__2", "recon. eff. Lb", 12, xAxis1); // After BDT cut
    eff__2->SetBinContent(3, 0.0005337445 * 0.8185);
    eff__2->SetBinContent(4, 0.004258425 * 0.9417);
    eff__2->SetBinContent(5, 0.0125 * 0.9734);
    eff__2->SetBinContent(6, 0.02934313 * 0.9706);
    eff__2->SetBinContent(7, 0.05736706 * 0.9767);
    eff__2->SetBinContent(8, 0.1166735 * 0.974);
    eff__2->SetBinContent(9, 0.1777021 * 0.9838);
    eff__2->SetBinContent(10, 0.2242961 * 0.9684);
    eff__2->SetBinContent(11, 0.2565476 * 0.9612);
    eff__2->SetBinContent(12, 0.3043478*0.8776);
    eff__2->SetBinError(3, 0.0001779623 * 0.8185);
    eff__2->SetBinError(4, 0.0004164637 * 0.9417);
    eff__2->SetBinError(5, 0.0006944974 * 0.9734);
    eff__2->SetBinError(6, 0.001142488 * 0.9706);
    eff__2->SetBinError(7, 0.001377074 * 0.9767);
    eff__2->SetBinError(8, 0.002443946 * 0.974);
    eff__2->SetBinError(9, 0.005137535 * 0.9838);
    eff__2->SetBinError(10, 0.009320557 * 0.9684);
    eff__2->SetBinError(11, 0.0138522 * 0.9612);
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

    // bkg per event of pp 14TeV
    TH1D* hBkgPerEvent__1 = new TH1D("hBkgPerEvent__1", "Lb bkg per event of pp 14TeV", 12, xAxis1);
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

    TH1D* hBkgPerEvent__2 = new TH1D("hBkgPerEvent__2", "Lb bkg per event of pp 14TeV after BDT", 12, xAxis1);
    hBkgPerEvent__2->SetBinContent(2, 2.10095e-06*0.0);
    hBkgPerEvent__2->SetBinContent(3, 1.39038e-06*0.0);
    hBkgPerEvent__2->SetBinContent(4, 2.174787e-06*0.0);
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

   TH1F* histosignal__1 = new TH1F("histosignal__1", "Lb signal pp per event", 12, xAxis1);
    histosignal__1->SetBinContent(3, 6697.72 / NEvents);
    histosignal__1->SetBinContent(4, 63696.8 / NEvents);
    histosignal__1->SetBinContent(5, 177490 / NEvents);
    histosignal__1->SetBinContent(6, 361081 / NEvents);
    histosignal__1->SetBinContent(7, 989169 / NEvents);
    histosignal__1->SetBinContent(8, 1.41772e+06 / NEvents);
    histosignal__1->SetBinContent(9, 745128 / NEvents);
    histosignal__1->SetBinContent(10, 355022 / NEvents);
    histosignal__1->SetBinContent(11, 201716 / NEvents);
    histosignal__1->SetBinContent(12, 78533.6 / NEvents);


    Int_t ci;      // for color index setting
    TColor* color; // for color definition with alpha
    ci = TColor::GetColor("#000099");
    histosignal__1->SetLineColor(ci);
    histosignal__1->GetXaxis()->SetTitle("p_{T} (GeV)");
    histosignal__1->GetXaxis()->SetRange(1, 100);
    histosignal__1->GetXaxis()->SetLabelFont(42);
    histosignal__1->GetXaxis()->SetTitleOffset(1);
    histosignal__1->GetXaxis()->SetTitleFont(42);
    histosignal__1->GetYaxis()->SetTitle("Lb signal per event");
    histosignal__1->GetYaxis()->SetLabelFont(42);
    histosignal__1->GetYaxis()->SetTitleFont(42);
    histosignal__1->GetZaxis()->SetLabelFont(42);
    histosignal__1->GetZaxis()->SetTitleOffset(1);
    histosignal__1->GetZaxis()->SetTitleFont(42);
    histosignal__1->Draw("");

    histosignal__1->SetEntries(100011);

    TH1F* histosignal__2 = new TH1F("histosignal__2", "Lb signal pp per event after BDT cut", 12, xAxis1);
    histosignal__2->SetBinContent(3, 6697.72 / NEvents * 0.4382);
    histosignal__2->SetBinContent(4, 63696.8 / NEvents * 0.7008);
    histosignal__2->SetBinContent(5, 177490 / NEvents * 0.70032);
    histosignal__2->SetBinContent(6, 361081 / NEvents * 0.7067);
    histosignal__2->SetBinContent(7, 989169 / NEvents * 0.8187);
    histosignal__2->SetBinContent(8, 1.41772e+06 / NEvents * 0.8563);
    histosignal__2->SetBinContent(9, 745128 / NEvents * 0.8819);
    histosignal__2->SetBinContent(10, 355022 / NEvents * 0.9);
    histosignal__2->SetBinContent(11, 201716 / NEvents * 0.8836);
    histosignal__2->SetBinContent(12, 78533.6 / NEvents * 0.85);

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
    
    TH1F* histosignf__2 = new TH1F("histosignf__2", "Significance Lb in pp 14TeV, Nevt=210E12", 12, xAxis1);
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
    histosignf__2->SetMarkerColor(4);
    histosignf__2->SetMarkerStyle(4);
    histosignf__2->SetMarkerSize(1.3);
    histosignf__2->GetYaxis()->SetRangeUser(0.1, 1000);

    histosignf__1->SetLineColor(ci);
    histosignf__1->SetLineWidth(2);
    histosignf__1->SetMarkerColor(2);
    histosignf__1->SetMarkerStyle(5);
    histosignf__1->SetMarkerSize(1.3);

    histosignf__1->SetStats(0);
    histosignf__2->SetStats(0);

    histosignf__2->SetLineColor(ci2);
    histosignf__2->SetLineWidth(2);
    histosignf__2->Draw("");
    histosignf__1->Draw("same");

    auto legend4 = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend4->AddEntry(histosignf__1, "Panos' cuts", "lep");
    legend4->AddEntry(histosignf__2, "+BDT cut", "lep");
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

    TH1F* histosignf__3 = new TH1F("histosignf__3", "Significance Lb in PbPb 5.02TeV, Nevt=3.8E10", 12, xAxis1);
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

    //Lb PbPb 5.02TeV with 270E9 events
    TCanvas* Canvas_6 = new TCanvas("Canvas_6", "Canvas_6", 1143, 281, 798, 757);
    Canvas_6->Range(-3, -17.34724, 27, 156.1252);
    Canvas_6->SetFillColor(0);
    Canvas_6->SetBorderMode(0);
    Canvas_6->SetBorderSize(2);
    Canvas_6->SetFrameBorderMode(0);
    Canvas_6->SetFrameBorderMode(0);

    TH1F* histosignf__5 = new TH1F("histosignf__5", "Significance Lb in PbPb 5.02TeV, Nevt=55E9", 12, xAxis1);
    histosignf__5->SetBinContent(3, 0.531148823);
    histosignf__5->SetBinContent(4, 5.077095135);
    histosignf__5->SetBinContent(5, 13.81916176);
    histosignf__5->SetBinContent(6, 28.91592885);
    histosignf__5->SetBinContent(7, 68.8101678);
    histosignf__5->SetBinContent(8, 94.28012543);
    histosignf__5->SetBinContent(9, 54.36253561);
    histosignf__5->SetBinContent(10, 13.07417988);
    histosignf__5->SetBinContent(11, 14.92990785);
    histosignf__5->SetBinContent(13, 1.31619e-07);

    TH1F* histosignf__6 = new TH1F("histosignf__6", "Significance Lb in PbPb 5.02TeV, Nevt=55E9", 12, xAxis1);
    histosignf__6->SetBinContent(3, 10.941); // after BDT
    histosignf__6->SetBinContent(4, 39.821);
    histosignf__6->SetBinContent(5, 68.641);
    histosignf__6->SetBinContent(6, 101.836);
    histosignf__6->SetBinContent(7, 172.874);
    histosignf__6->SetBinContent(8, 204.881);
    histosignf__6->SetBinContent(9, 142.672);
    histosignf__6->SetBinContent(10, 62.694);
    histosignf__6->SetBinContent(11, 57.373);
    histosignf__6->SetBinContent(13, 1.31619e-07);

    histosignf__5->SetLineWidth(2);
    histosignf__5->GetXaxis()->SetTitle("p_{T} (GeV)");
    histosignf__5->GetXaxis()->SetRange(1, 100);
    histosignf__5->GetXaxis()->SetLabelFont(42);
    histosignf__5->GetXaxis()->SetTitleOffset(1);
    histosignf__5->GetXaxis()->SetTitleFont(42);
    histosignf__5->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
    histosignf__5->GetYaxis()->SetLabelFont(42);
    histosignf__5->GetYaxis()->SetTitleFont(42);
    histosignf__5->GetZaxis()->SetLabelFont(42);
    histosignf__5->GetZaxis()->SetTitleOffset(1);
    histosignf__5->GetZaxis()->SetTitleFont(42);
    
    histosignf__5->SetLineColor(ci);
    histosignf__5->SetLineWidth(2);
    histosignf__6->Draw("");
    histosignf__5->Draw("same");

    auto legend6 = new TLegend(0.1, 0.7, 0.48, 0.9);
    legend6->AddEntry(histosignf__3, "Panos' cuts", "f");
    legend6->AddEntry(histosignf__4, "+BDT cut", "f");
    legend6->Draw("");

    Canvas_6->cd();
    Canvas_6->Modified();
    Canvas_6->SetSelected(Canvas_1);

    //Lb PbPb 5.02TeV 30-50% with 55E9 events and variable Raa
    TCanvas* Canvas_7 = new TCanvas("Canvas_7", "Canvas_7", 1143, 281, 798, 757);
    Canvas_7->Range(-3, -17.34724, 27, 156.1252);
    Canvas_7->SetFillColor(0);
    Canvas_7->SetBorderMode(0);
    Canvas_7->SetBorderSize(2);
    Canvas_7->SetFrameBorderMode(0);
    Canvas_7->SetFrameBorderMode(0);

    TH1F* histosignf__7 = new TH1F("histosignf__7", "Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9", 12, xAxis1);
    histosignf__7->SetBinContent(3, 1.476411422);
    histosignf__7->SetBinContent(4, 19.83811666);
    histosignf__7->SetBinContent(5, 47.37049454);
    histosignf__7->SetBinContent(6, 70.70376854);
    histosignf__7->SetBinContent(7, 124.3875541);
    histosignf__7->SetBinContent(8, 152.0880488);
    histosignf__7->SetBinContent(9, 90.89947862);
    histosignf__7->SetBinContent(10, 45.30123391);
    histosignf__7->SetBinContent(11, 24.97200691);
    histosignf__7->SetBinContent(12, 8.835840788);

    histosignf__7->SetBinError(3, 0.194308477);
    histosignf__7->SetBinError(4, 2.645205765);
    histosignf__7->SetBinError(5, 6.724885959);
    histosignf__7->SetBinError(6, 10.16588564);
    histosignf__7->SetBinError(7, 12.34927916);
    histosignf__7->SetBinError(8, 11.83167705);
    histosignf__7->SetBinError(9, 7.320726785);
    histosignf__7->SetBinError(10, 3.761962422);
    histosignf__7->SetBinError(11, 1.948953026);
    histosignf__7->SetBinError(12, 0.711725044);

    TH1F* histosignf__8 = new TH1F("histosignf__8", "Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9", 12, xAxis1);
    histosignf__8->SetBinContent(3, 14.6981); // after BDT
    histosignf__8->SetBinContent(4, 60.4933);
    histosignf__8->SetBinContent(5, 99.1656);
    histosignf__8->SetBinContent(6, 122.633);
    histosignf__8->SetBinContent(7, 181.512);
    histosignf__8->SetBinContent(8, 207.957);
    histosignf__8->SetBinContent(9, 146.071);
    histosignf__8->SetBinContent(10, 93.3654);
    histosignf__8->SetBinContent(11, 64.3722);
    histosignf__8->SetBinContent(12, 31.6456);

    histosignf__8->SetBinError(3, 1.933428366); // after BDT
    histosignf__8->SetBinError(4, 8.065706427);
    histosignf__8->SetBinError(5, 14.07779787);
    histosignf__8->SetBinError(6, 17.63314224);
    histosignf__8->SetBinError(7, 18.02152923);
    histosignf__8->SetBinError(8, 16.17749439);
    histosignf__8->SetBinError(9, 11.76424342);
    histosignf__8->SetBinError(10, 7.753200141);
    histosignf__8->SetBinError(11, 5.023994727);
    histosignf__8->SetBinError(12, 2.549194909);

    histosignf__8->SetLineWidth(2);
    histosignf__8->GetXaxis()->SetTitle("p_{T} (GeV)");
    histosignf__8->GetXaxis()->SetRange(1, 100);
    histosignf__8->GetXaxis()->SetLabelFont(42);
    histosignf__8->GetXaxis()->SetTitleOffset(1);
    histosignf__8->GetXaxis()->SetTitleFont(42);
    histosignf__8->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
    histosignf__8->GetYaxis()->SetLabelFont(42);
    histosignf__8->GetYaxis()->SetTitleFont(42);
    histosignf__8->GetZaxis()->SetLabelFont(42);
    histosignf__8->GetZaxis()->SetTitleOffset(1);
    histosignf__8->GetZaxis()->SetTitleFont(42);
    histosignf__8->SetMarkerColor(4);
    histosignf__8->SetMarkerStyle(4);
    histosignf__8->SetMarkerSize(1.3);
    
    histosignf__7->SetLineColor(ci);
    histosignf__7->SetLineWidth(2);
    histosignf__7->SetMarkerColor(2);
    histosignf__7->SetMarkerStyle(5);
    histosignf__7->SetMarkerSize(1.3);

    histosignf__7->SetStats(0);
    histosignf__8->SetStats(0);
    histosignf__8->Draw("");
    histosignf__7->Draw("same");

    auto legend7 = new TLegend(0.1, 0.7, 0.48, 0.9);
    TLegendEntry* entry = legend7->AddEntry(histosignf__7, "Panos' cuts", "lep");
    entry->SetMarkerStyle(5);
    entry = legend7->AddEntry(histosignf__8, "+BDT cut", "lep");
    entry->SetMarkerStyle(4);
    legend7->Draw("");

    Canvas_7->cd();
    Canvas_7->Modified();
    Canvas_7->SetSelected(Canvas_7);

    TH1D* hBkgPerEvent__3 = new TH1D("hBkgPerEvent__3", "Lb bkg per event PbPb 5.02Tev 30-50%", 12, xAxis1);
    hBkgPerEvent__3->SetBinContent(3, 6.858217e-07);
    hBkgPerEvent__3->SetBinContent(4, 6.716679e-07);
    hBkgPerEvent__3->SetBinContent(5, 6.899283e-07);
    hBkgPerEvent__3->SetBinContent(6, 6.277193e-07);
    hBkgPerEvent__3->SetBinContent(7, 7.673098e-07);
    hBkgPerEvent__3->SetBinContent(8, 7.971997e-07);
    hBkgPerEvent__3->SetBinContent(9, 7.170778e-07);
    hBkgPerEvent__3->SetBinContent(10, 7.33937e-07);
    hBkgPerEvent__3->SetBinContent(11, 7.62791e-07);
    hBkgPerEvent__3->SetBinContent(12, 7.205936e-07);
    hBkgPerEvent__3->SetEntries(11);
    hBkgPerEvent__3->SetStats(0);

    TH1D* hBkgPerEvent__4 = new TH1D("hBkgPerEvent__4", "Lb bkg per event PbPb 5.02Tev 30-50% after BDT cut", 12, xAxis1);
    hBkgPerEvent__4->SetBinContent(3, 6.858217e-07 * 0.00057);
    hBkgPerEvent__4->SetBinContent(4, 6.716679e-07 * 0.003398);
    hBkgPerEvent__4->SetBinContent(5, 6.899283e-07 * 0.008336);
    hBkgPerEvent__4->SetBinContent(6, 6.277193e-07 * 0.01087);
    hBkgPerEvent__4->SetBinContent(7, 7.673098e-07 * 0.01654);
    hBkgPerEvent__4->SetBinContent(8, 7.971997e-07 * 0.02382);
    hBkgPerEvent__4->SetBinContent(9, 7.170778e-07 * 0.03474);
    hBkgPerEvent__4->SetBinContent(10, 7.33937e-07 * 0.0329);
    hBkgPerEvent__4->SetBinContent(11, 7.62791e-07 * 0.03251);
    hBkgPerEvent__4->SetBinContent(12, 7.205936e-07 * 0.02582);
    hBkgPerEvent__4->SetEntries(11);
    hBkgPerEvent__4->SetStats(0);

    hBkgPerEvent__3->SetLineColor(ci);
    hBkgPerEvent__3->SetLineWidth(3);
    hBkgPerEvent__3->GetXaxis()->SetTitle("p_{T}(GeV/c)");
    hBkgPerEvent__3->GetXaxis()->SetLabelFont(42);
    hBkgPerEvent__3->GetXaxis()->SetLabelOffset(0.015);
    hBkgPerEvent__3->GetXaxis()->SetTitleSize(0.045);
    hBkgPerEvent__3->GetXaxis()->SetTitleOffset(1);
    hBkgPerEvent__3->GetXaxis()->SetTitleFont(42);
    hBkgPerEvent__3->GetYaxis()->SetTitle("Bkg/nEvents");
    hBkgPerEvent__3->GetYaxis()->CenterTitle(true);
    hBkgPerEvent__3->GetYaxis()->SetLabelFont(42);
    hBkgPerEvent__3->GetYaxis()->SetLabelOffset(0.01);
    hBkgPerEvent__3->GetYaxis()->SetTitleSize(0.045);
    hBkgPerEvent__3->GetYaxis()->SetTitleOffset(0.8);
    hBkgPerEvent__3->GetYaxis()->SetTitleFont(42);
    hBkgPerEvent__3->GetZaxis()->SetLabelFont(42);
    hBkgPerEvent__3->GetZaxis()->SetTitleOffset(1);
    hBkgPerEvent__3->GetZaxis()->SetTitleFont(42);

    TH1F* histosignal__3 = new TH1F("histosignal__3", "Lb signal per event PbPb 5.02Tev 30-50%", 12, xAxis2);
    histosignal__3->SetBinContent(3, 287.836 / NEventsPbPb);
    histosignal__3->SetBinContent(4, 4014.78 / NEventsPbPb);
    histosignal__3->SetBinContent(5, 10417.6 / NEventsPbPb);
    histosignal__3->SetBinContent(6, 15872.5 / NEventsPbPb);
    histosignal__3->SetBinContent(7, 34434.6 / NEventsPbPb);
    histosignal__3->SetBinContent(8, 45446.8 / NEventsPbPb);
    histosignal__3->SetBinContent(9, 22650.1 / NEventsPbPb);
    histosignal__3->SetBinContent(10, 10218.3 / NEventsPbPb);
    histosignal__3->SetBinContent(11, 5436.2 / NEventsPbPb);
    histosignal__3->SetBinContent(12, 1943.32 / NEventsPbPb);

    TH1F* histosignal__4 = new TH1F("histosignal__4", "Lb signal per event PbPb 5.02Tev 30-50% after BDT cut", 12, xAxis2);
    histosignal__4->SetBinContent(3, 287.836 * 0.8185 / NEventsPbPb);
    histosignal__4->SetBinContent(4, 4014.78 * 0.9417 / NEventsPbPb);
    histosignal__4->SetBinContent(5, 10417.6 * 0.9734 / NEventsPbPb);
    histosignal__4->SetBinContent(6, 15872.5 * 0.9706 / NEventsPbPb);
    histosignal__4->SetBinContent(7, 34434.6 * 0.9767 / NEventsPbPb);
    histosignal__4->SetBinContent(8, 45446.8 * 0.974 / NEventsPbPb);
    histosignal__4->SetBinContent(9, 22650.1 * 0.9838 / NEventsPbPb);
    histosignal__4->SetBinContent(10, 10218.3 * 0.9684 / NEventsPbPb);
    histosignal__4->SetBinContent(11, 5436.2 * 0.9612 / NEventsPbPb);
    histosignal__4->SetBinContent(12, 1943.32 * 0.8776 / NEventsPbPb);


    histosignal__3->SetLineColor(ci);
    histosignal__3->GetXaxis()->SetTitle("p_{T} (GeV)");
    histosignal__3->GetXaxis()->SetRange(1, 100);
    histosignal__3->GetXaxis()->SetLabelFont(42);
    histosignal__3->GetXaxis()->SetTitleOffset(1);
    histosignal__3->GetXaxis()->SetTitleFont(42);
    histosignal__3->GetYaxis()->SetTitle("Lb d#sigma^{PYTHIA}/dp_{T} (#mu b/GeV)");
    histosignal__3->GetYaxis()->SetLabelFont(42);
    histosignal__3->GetYaxis()->SetTitleFont(42);
    histosignal__3->GetZaxis()->SetLabelFont(42);
    histosignal__3->GetZaxis()->SetTitleOffset(1);
    histosignal__3->GetZaxis()->SetTitleFont(42);


    /// <summary>
    /// Write to file
    /// </summary>
    TFile TMPFile("Lb_histograms.root", "RECREATE");
    TMPFile.WriteObject(histosignf__8, "Lb_PbPb_signBDT");
    TMPFile.WriteObject(histosignf__7, "Lb_PbPb_sign");
    TMPFile.WriteObject(histosignf__2, "Lb_pp_signBDT");
    TMPFile.WriteObject(histosignf__1, "Lb_pp_sign");
    TMPFile.WriteObject(hBkgPerEvent__1, "Lb_pp_bkgperevent");
    TMPFile.WriteObject(hBkgPerEvent__2, "Lb_pp_bkgpereventBDT");
    TMPFile.WriteObject(histosignal__1, "Lb_pp_sigperevent");
    TMPFile.WriteObject(histosignal__2, "Lb_pp_sigpereventBDT");
    TMPFile.WriteObject(eff__1, "Lb_reconeff");
    TMPFile.WriteObject(eff__2, "Lb_reconeffBDT");
    TMPFile.WriteObject(histosignal__3, "Lb_PbPb_sigperevent");
    TMPFile.WriteObject(histosignal__4, "Lb_PbPb_sigpereventBDT");
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