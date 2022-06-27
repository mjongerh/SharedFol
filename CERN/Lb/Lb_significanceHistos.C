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

void Lb_significanceHistos()
{
  Double_t xAxis1[13] = {0, 0.5, 1, 2, 3, 4, 5, 7, 10, 13, 16, 20, 24};
  Double_t NEvents = 1260000000000000.0 ;//pp // old value = 210000000000000.0
  double factor = 6.0 / sqrt(6.0); //convert from old to new significance
  Double_t NEventsPbPb = 55000000000.0;

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

  TH1F* eff__2 = new TH1F("eff__2", "recon. eff. Lb PbPb after BDT", 12, xAxis1); // After BDT cut
  eff__2->SetBinContent(3, 0.0005337445 * 0.8185);
  eff__2->SetBinContent(4, 0.004258425 * 0.9417);
  eff__2->SetBinContent(5, 0.0125 * 0.9734);
  eff__2->SetBinContent(6, 0.02934313 * 0.9706);
  eff__2->SetBinContent(7, 0.05736706 * 0.9767);
  eff__2->SetBinContent(8, 0.1166735 * 0.974);
  eff__2->SetBinContent(9, 0.1777021 * 0.9838);
  eff__2->SetBinContent(10, 0.2242961 * 0.9684);
  eff__2->SetBinContent(11, 0.2565476 * 0.9612);
  eff__2->SetBinContent(12, 0.3043478 * 0.8776);
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
  legend1->AddEntry(eff__1, "pre-cuts", "f");
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
  TH1D* hBkgPerEvent__1 = new TH1D("hBkgPerEvent__1", "#Lambda_{b}^{0} background yield p-p #sqrt{s}=14.0TeV", 12, xAxis1);
  hBkgPerEvent__1->SetBinContent(2, 2.65e+9 / NEvents);
  hBkgPerEvent__1->SetBinContent(3, 1.75e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(4, 2.74e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(5, 2.48e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(6, 1.67e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(7, 2.34e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(8, 2.77e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(9, 1.34e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(10, 2.11e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(11, 2.57e+9/ NEvents);
  hBkgPerEvent__1->SetBinContent(12, 2.72e+9/ NEvents);
  hBkgPerEvent__1->SetEntries(11);
  hBkgPerEvent__1->SetStats(0);

  TH1D* hBkgPerEvent__2 = new TH1D("hBkgPerEvent__2", "Lb bkg per event of pp 14TeV after BDT", 12, xAxis1);
  hBkgPerEvent__2->SetBinContent(3, 1.23e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(4, 1.60577478e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(5, 3.59705551e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(6, 4.05232984e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(7, 8.94720666e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(8, 1.130320317e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(9, 5.76970791e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(10, 7.27163712e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(11, 9.13221323e+8 / NEvents);
  hBkgPerEvent__2->SetBinContent(12, 7.97124913e+8 / NEvents);
  hBkgPerEvent__2->SetEntries(11);
  hBkgPerEvent__2->SetStats(0);

  hBkgPerEvent__1->SetLineColor(ci);
  hBkgPerEvent__1->SetLineWidth(3);
  hBkgPerEvent__1->GetXaxis()->SetTitle("p_{T}(#Lambda_{b}^{0})(GeV/c)");
  hBkgPerEvent__1->GetXaxis()->SetLabelFont(42);
  hBkgPerEvent__1->GetXaxis()->SetLabelOffset(0.015);
  hBkgPerEvent__1->GetXaxis()->SetTitleSize(0.045);
  hBkgPerEvent__1->GetXaxis()->SetTitleOffset(1);
  hBkgPerEvent__1->GetXaxis()->SetTitleFont(42);
  hBkgPerEvent__1->GetYaxis()->SetTitle("#Lambda_{b}^{0} background events per collision");
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
  legend2->AddEntry(hBkgPerEvent__1, "pre-cuts", "f");
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

  TH1F* histosignal__1 = new TH1F("histosignal__1", "#Lambda_{b}^{0} signal yield p-p #sqrt{s}=14.0TeV", 12, xAxis1);
  histosignal__1->SetBinContent(3, 40186.32 / NEvents);
  histosignal__1->SetBinContent(4, 382180.8 / NEvents);
  histosignal__1->SetBinContent(5, 1064940 / NEvents);
  histosignal__1->SetBinContent(6, 2166486 / NEvents);
  histosignal__1->SetBinContent(7, 5935014 / NEvents);
  histosignal__1->SetBinContent(8, 8.51e+06 / NEvents);
  histosignal__1->SetBinContent(9, 4470768 / NEvents);
  histosignal__1->SetBinContent(10, 2130132 / NEvents);
  histosignal__1->SetBinContent(11, 1210296 / NEvents);
  histosignal__1->SetBinContent(12, 471201.6 / NEvents);

  histosignal__1->SetBinError(3, histosignal__1->GetBinContent(3) * sqrt(0.1717));
  histosignal__1->SetBinError(4, histosignal__1->GetBinContent(4) * sqrt(0.1737));
  histosignal__1->SetBinError(5, histosignal__1->GetBinContent(5) * sqrt(0.1755));
  histosignal__1->SetBinError(6, histosignal__1->GetBinContent(6) * sqrt(0.1771));
  histosignal__1->SetBinError(7, histosignal__1->GetBinContent(7) * sqrt(0.1785));
  histosignal__1->SetBinError(8, histosignal__1->GetBinContent(8) * sqrt(0.1807));
  histosignal__1->SetBinError(9, histosignal__1->GetBinContent(9) * sqrt(0.1826));
  histosignal__1->SetBinError(10, histosignal__1->GetBinContent(10) * sqrt(0.1827));
  histosignal__1->SetBinError(11, histosignal__1->GetBinContent(11) * sqrt(0.1811));
  histosignal__1->SetBinError(12, histosignal__1->GetBinContent(12) * sqrt(0.1761));

  histosignal__1->SetLineColor(kBlue);
  histosignal__1->SetLineWidth(3);
  histosignal__1->GetXaxis()->SetTitle("p_{T}(#Lambda_{b}^{0}) (GeV/c)");
  histosignal__1->GetXaxis()->SetRange(1, 100);
  histosignal__1->GetXaxis()->SetLabelFont(42);
  histosignal__1->GetXaxis()->SetTitleOffset(1);
  histosignal__1->GetXaxis()->SetTitleFont(42);
  histosignal__1->GetYaxis()->SetTitle("#Lambda_{b}^{0} signal events per collision");
  histosignal__1->GetYaxis()->SetLabelFont(42);
  histosignal__1->GetYaxis()->SetTitleFont(42);
  histosignal__1->GetZaxis()->SetLabelFont(42);
  histosignal__1->GetZaxis()->SetTitleOffset(1);
  histosignal__1->GetZaxis()->SetTitleFont(42);
  histosignal__1->Draw("");

  histosignal__1->SetEntries(100011);

  TH1F* histosignal__2 = new TH1F("histosignal__2", "Lb signal pp per event after BDT cut", 12, xAxis1);
  histosignal__2->SetBinContent(3, 34962.098 / NEvents);
  histosignal__2->SetBinContent(4, 309948.6288 / NEvents);
  histosignal__2->SetBinContent(5, 886349.562 / NEvents);
  histosignal__2->SetBinContent(6, 1853212.124 / NEvents);
  histosignal__2->SetBinContent(7, 5203820.275 / NEvents);
  histosignal__2->SetBinContent(8, 7332447.84 / NEvents);
  histosignal__2->SetBinContent(9, 3670053.451 / NEvents);
  histosignal__2->SetBinContent(10, 1719655.564 / NEvents);
  histosignal__2->SetBinContent(11, 1111898.935 / NEvents);
  histosignal__2->SetBinContent(12, 450845.6909 / NEvents);

  histosignal__2->SetLineColor(ci2);
  histosignal__2->SetLineWidth(2);

  histosignal__1->Draw("");
  histosignal__2->Draw("same");
  auto legend3 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend3->AddEntry(histosignal__1, "pre-cuts", "f");
  legend3->AddEntry(histosignal__2, "+BDT cut", "f");
  legend3->Draw("");

  Canvas_3->Modified();
  Canvas_3->cd();
  Canvas_3->SetSelected(Canvas_3);
  

  TCanvas* Canvas_5 = new TCanvas("Canvas_5", "Significance Lb in pp 14TeV, Nevt=1.26E15", 1143, 281, 798, 757);
  Canvas_5->Range(-3, -17.34724, 27, 156.1252);
  Canvas_5->SetFillColor(0);
  Canvas_5->SetBorderMode(0);
  Canvas_5->SetBorderSize(2);
  Canvas_5->SetFrameBorderMode(0);
  Canvas_5->SetFrameBorderMode(0);

  TH1F* histosignf__9 = new TH1F("histosignf__9", "#Lambda_{b}^{0} significance p-p #sqrt{s}=14.0TeV, Nevt=1.26E15", 12, xAxis1);
    histosignf__9->SetBinContent(3, 6.84E-01);
    histosignf__9->SetBinContent(4, 5.19E+00);
    histosignf__9->SetBinContent(5, 1.52E+01);
    histosignf__9->SetBinContent(6, 3.76E+01);
    histosignf__9->SetBinContent(7, 8.69E+01);
    histosignf__9->SetBinContent(8, 1.14E+02);
    histosignf__9->SetBinContent(9, 8.65E+01);
    histosignf__9->SetBinContent(10, 3.30E+01);
    histosignf__9->SetBinContent(11, 1.70E+01);
    histosignf__9->SetBinContent(12, 6.49E+00);
             
             

    histosignf__9->SetBinError(3,  sqrt(pow(0.280879212,2) + pow(0.050227726, 2)));
    histosignf__9->SetBinError(4,  sqrt(pow(2.142395703,2) + pow(0.381397120, 2)));
    histosignf__9->SetBinError(5,  sqrt(pow(6.296031414,2) + pow(1.116627482, 2)));
    histosignf__9->SetBinError(6,  sqrt(pow(15.62671055,2) + pow(2.762959635, 2)));
    histosignf__9->SetBinError(7,  sqrt(pow(36.15358918,2) + pow(6.377042234, 2)));
    histosignf__9->SetBinError(8,  sqrt(pow(47.75482834,2) + pow(8.399906833, 2)));
    histosignf__9->SetBinError(9,  sqrt(pow(36.05526537,2) + pow(6.346664854, 2)));
    histosignf__9->SetBinError(10, sqrt(pow(13.65866820,2) + pow(2.420405603, 2)));
    histosignf__9->SetBinError(11, sqrt(pow(6.960821744,2) + pow(1.249548841, 2)));
    histosignf__9->SetBinError(12, sqrt(pow(2.582050103,2) + pow(0.476671378, 2)));

  TH1F* histosignf__10 = new TH1F("histosignf__10", "Significance Lb in pp 14TeV, Nevt=1.26E15 after BDT cut", 12, xAxis1);
  histosignf__10->SetBinContent(3, 3.157/1.41);
  histosignf__10->SetBinContent(4, 24.436/1.41);
  histosignf__10->SetBinContent(5, 46.676/1.41);
  histosignf__10->SetBinContent(6, 91.851/1.41);
  histosignf__10->SetBinContent(7, 173.468/1.41);
  histosignf__10->SetBinContent(8, 217.392/1.41);
  histosignf__10->SetBinContent(9, 152.307/1.41);
  histosignf__10->SetBinContent(10, 63.696/1.41);
  histosignf__10->SetBinContent(11, 36.772/1.41);
  histosignf__10->SetBinContent(12, 15.964/1.41);
  
  histosignf__10->SetLineWidth(2);
  histosignf__10->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  histosignf__10->GetXaxis()->SetRange(1, 100);
  histosignf__10->GetXaxis()->SetLabelFont(42);
  histosignf__10->GetXaxis()->SetTitleOffset(1);
  histosignf__10->GetXaxis()->SetTitleFont(42);
  histosignf__10->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  histosignf__10->GetYaxis()->SetLabelFont(42);
  histosignf__10->GetYaxis()->SetTitleFont(42);
  histosignf__10->GetZaxis()->SetLabelFont(42);
  histosignf__10->GetZaxis()->SetTitleOffset(1);
  histosignf__10->GetZaxis()->SetTitleFont(42);
  histosignf__10->SetMarkerColor(4);
  histosignf__10->SetMarkerStyle(4);
  histosignf__10->SetMarkerSize(1.3);

  histosignf__9->SetLineColor(ci);
  histosignf__9->SetLineWidth(2);
  histosignf__9->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  histosignf__9->GetXaxis()->SetRange(1, 100);
  histosignf__9->GetXaxis()->SetLabelFont(42);
  histosignf__9->GetXaxis()->SetTitleOffset(1);
  histosignf__9->GetXaxis()->SetTitleFont(42);
  histosignf__9->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  histosignf__9->GetYaxis()->SetLabelFont(42);
  histosignf__9->GetYaxis()->SetTitleFont(42);
  histosignf__9->SetMarkerColor(2);
  histosignf__9->SetMarkerStyle(5);
  histosignf__9->SetMarkerSize(1.3);

  histosignf__9->SetStats(0);
  histosignf__10->SetStats(0);
  histosignf__10->Draw("");
  histosignf__9->Draw("same");

  auto legend5 = new TLegend(0.1, 0.7, 0.48, 0.9);
  TLegendEntry* entry1 = legend5->AddEntry(histosignf__9, "pre-cuts", "lep");
  entry1->SetMarkerStyle(5);
  entry1 = legend5->AddEntry(histosignf__10, "+BDT cut", "lep");
  entry1->SetMarkerStyle(4);
  legend5->Draw("");

  Canvas_5->cd();
  Canvas_5->Modified();
  Canvas_5->SetSelected(Canvas_5);

    // systematic error
  TCanvas* Canvas_76 = new TCanvas("Canvas_76", "Double error Significance Lb in pp 14TeV, Nevt=1.26E15", 1143, 281, 798, 757);
  //only pythia
  double px[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double py[12] = {.0, .0, 3.156707877, 24.43591843, 46.67636746, 91.85058874, 173.4679533, 217.3922808, 152.3065561, 63.69604236, 36.77164548, 15.96400849};
  double pexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double pexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* peylstat = new double[12]{0.0, 0.0, 0.231876766, 1.793473105, 3.424898467, 6.732510142, 12.707102, 15.91941221, 11.15394861, 4.673955431, 2.699812803, 1.172475893};
  double* peyhstat = new double[12]{0.0, 0.0, 0.231876766, 1.793473105, 3.424898467, 6.732510142, 12.707102, 15.91941221, 11.15394861, 4.673955431, 2.699812803, 1.172475893};

  double* peylsys = new double[12]{0.0, 0.0, 0.290650541, 2.360410569, 4.766151681, 9.950785586, 20.42055945, 29.72182605, 24.92375308, 12.27021025, 8.326135594, 4.267450527};
  double* peyhsys = new double[12]{0.0, 0.0, 0.290650541, 2.360410569, 4.766151681, 9.950785586, 20.42055945, 29.72182605, 24.92375308, 12.27021025, 8.326135594, 4.267450527};


  TGraphMultiErrors* gSignf_pp14p0_DoubleError = new TGraphMultiErrors("gSignf_pp14p0_DoubleError", "Double error Significance Lb in pp 14TeV, Nevt=1.26E15", 12, px, py, pexl, pexh, peylstat, peyhstat);
  gSignf_pp14p0_DoubleError->AddYError(12, peylsys, peyhsys);
  gSignf_pp14p0_DoubleError->SetMarkerStyle(4);
  gSignf_pp14p0_DoubleError->SetLineColor(kRed);
  gSignf_pp14p0_DoubleError->GetAttLine(0)->SetLineColor(kRed);
  gSignf_pp14p0_DoubleError->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_pp14p0_DoubleError->GetAttFill(1)->SetFillStyle(0);
  gSignf_pp14p0_DoubleError->GetXaxis()->SetTitle("p_{T} (GeV)");
  gSignf_pp14p0_DoubleError->GetXaxis()->SetRange(1, 100);
  gSignf_pp14p0_DoubleError->GetXaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleError->GetXaxis()->SetTitleOffset(1);
  gSignf_pp14p0_DoubleError->GetXaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleError->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
  gSignf_pp14p0_DoubleError->GetYaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleError->GetYaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleError->SetMarkerColor(4);
  gSignf_pp14p0_DoubleError->SetMarkerSize(1.3);

  gSignf_pp14p0_DoubleError->Draw("a p s ; ; 5 s=0.5");
  Canvas_76->cd();
  Canvas_76->Modified();
  Canvas_76->SetSelected(Canvas_76);

  double signfpereventfactorpp = 1 / sqrt(NEvents);
  TH1F* histosignf__13 = new TH1F("histosignf__13", "Significance per event Lb in pp 14TeV, Nevt=1.26E15", 12, xAxis1);
  histosignf__13->SetBinContent(3, 0.960121204 * signfpereventfactorpp);
  histosignf__13->SetBinContent(4, 7.300882464 * signfpereventfactorpp);
  histosignf__13->SetBinContent(5, 21.40347928 * signfpereventfactorpp);
  histosignf__13->SetBinContent(6, 53.04167744 * signfpereventfactorpp);
  histosignf__13->SetBinContent(7, 122.6176088 * signfpereventfactorpp);
  histosignf__13->SetBinContent(8, 161.7100383 * signfpereventfactorpp);
  histosignf__13->SetBinContent(9, 122.1781281 * signfpereventfactorpp);
  histosignf__13->SetBinContent(10, 46.42496492 * signfpereventfactorpp);
  histosignf__13->SetBinContent(11, 23.86596022 * signfpereventfactorpp);
  histosignf__13->SetBinContent(12, 9.027774988 * signfpereventfactorpp);

  TH1F* histosignf__14 = new TH1F("histosignf__14", "Significance per event Lb in pp 14TeV, Nevt=1.26E15 after BDT cut", 12, xAxis1);
  histosignf__14->SetBinContent(3, 3.157 * signfpereventfactorpp);
  histosignf__14->SetBinContent(4, 24.436 * signfpereventfactorpp);
  histosignf__14->SetBinContent(5, 46.676 * signfpereventfactorpp);
  histosignf__14->SetBinContent(6, 91.851 * signfpereventfactorpp);
  histosignf__14->SetBinContent(7, 173.468 * signfpereventfactorpp);
  histosignf__14->SetBinContent(8, 217.392 * signfpereventfactorpp);
  histosignf__14->SetBinContent(9, 152.307 * signfpereventfactorpp);
  histosignf__14->SetBinContent(10, 63.696 * signfpereventfactorpp);
  histosignf__14->SetBinContent(11, 36.772 * signfpereventfactorpp);
  histosignf__14->SetBinContent(12, 15.964 * signfpereventfactorpp);

  /// <summary>
  /// PbPb histograms
  /// </summary>
  /// 
  // Lb PbPb 5.02TeV with 270E9 events, 55E9 in 30-50%


  // Lb PbPb 5.02TeV 30-50% with 55E9 events and variable Raa
  TCanvas* Canvas_7 = new TCanvas("Canvas_7", "Canvas_7", 1143, 281, 798, 757);
  Canvas_7->Range(-3, -17.34724, 27, 156.1252);
  Canvas_7->SetFillColor(0);
  Canvas_7->SetBorderMode(0);
  Canvas_7->SetBorderSize(2);
  Canvas_7->SetFrameBorderMode(0);
  Canvas_7->SetFrameBorderMode(0);

  TH1F* histosignf__7 = new TH1F("histosignf__7", "#Lambda_{b}^{0} significance Pb-Pb #sqrt{s}=5.02TeV, centr. 30-50%, Nevt=55E9", 12, xAxis1);
    histosignf__7->SetBinContent(3, 1.052497731); 
    histosignf__7->SetBinContent(4, 14.31192447);
    histosignf__7->SetBinContent(5, 34.75113157);
    histosignf__7->SetBinContent(6, 52.64245352);
    histosignf__7->SetBinContent(7, 94.61181487);
    histosignf__7->SetBinContent(8, 116.7758725);
    histosignf__7->SetBinContent(9, 68.14692431);
    histosignf__7->SetBinContent(10, 33.15097017);
    histosignf__7->SetBinContent(11, 18.10340957);
    histosignf__7->SetBinContent(12, 6.387377534);
           
    histosignf__7->SetBinError(3, 1.982622278);
    histosignf__7->SetBinError(4, 9.931590026);
    histosignf__7->SetBinError(5, 19.47172447);
    histosignf__7->SetBinError(6, 26.30293284);
    histosignf__7->SetBinError(7, 37.3740752);
    histosignf__7->SetBinError(8, 42.32361324);
    histosignf__7->SetBinError(9, 27.40184512);
    histosignf__7->SetBinError(10, 15.07235721);
    histosignf__7->SetBinError(11, 8.79846947);
    histosignf__7->SetBinError(12, 3.607303771);

  TH1F* histosignf__8 = new TH1F("histosignf__8", "Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9", 12, xAxis1);
  histosignf__8->SetBinContent(3, 14.6981/1.2); // after BDT
  histosignf__8->SetBinContent(4, 60.4933/1.2);
  histosignf__8->SetBinContent(5, 99.1656/1.2);
  histosignf__8->SetBinContent(6, 122.633/1.2);
  histosignf__8->SetBinContent(7, 181.512/1.2);
  histosignf__8->SetBinContent(8, 207.957/1.2);
  histosignf__8->SetBinContent(9, 146.071/1.2);
  histosignf__8->SetBinContent(10, 93.3654/1.2);
  histosignf__8->SetBinContent(11, 64.3722/1.2);
  histosignf__8->SetBinContent(12, 31.6456/1.2);

  //histosignf__8->SetBinError(3, 1.933428366); // after BDT
  //histosignf__8->SetBinError(4, 8.065706427); // errors not updates to scale
  //histosignf__8->SetBinError(5, 14.07779787);
  //histosignf__8->SetBinError(6, 17.63314224);
  //histosignf__8->SetBinError(7, 18.02152923);
  //histosignf__8->SetBinError(8, 16.17749439);
  //histosignf__8->SetBinError(9, 11.76424342);
  //histosignf__8->SetBinError(10, 7.753200141);
  //histosignf__8->SetBinError(11, 5.023994727);
  //histosignf__8->SetBinError(12, 2.549194909);

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
  histosignf__7->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  histosignf__7->GetXaxis()->SetRange(1, 100);
  histosignf__7->GetXaxis()->SetLabelFont(42);
  histosignf__7->GetXaxis()->SetTitleOffset(1);
  histosignf__7->GetXaxis()->SetTitleFont(42);
  histosignf__7->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  histosignf__7->GetYaxis()->SetLabelFont(42);
  histosignf__7->GetYaxis()->SetTitleFont(42);
  histosignf__7->SetMarkerColor(2);
  histosignf__7->SetMarkerStyle(5);
  histosignf__7->SetMarkerSize(1.3);

  histosignf__7->SetStats(0);
  histosignf__8->SetStats(0);
  histosignf__8->Draw("");
  histosignf__7->Draw("same");

  auto legend7 = new TLegend(0.1, 0.7, 0.48, 0.9);
  TLegendEntry* entry = legend7->AddEntry(histosignf__7, "pre-cuts", "lep");
  entry->SetMarkerStyle(5);
  entry = legend7->AddEntry(histosignf__8, "+BDT cut", "lep");
  entry->SetMarkerStyle(4);
  legend7->Draw("");

  Canvas_7->cd();
  Canvas_7->Modified();
  Canvas_7->SetSelected(Canvas_7);

  //systematic error
  TCanvas* Canvas_77 = new TCanvas("Canvas_77", "Double error Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9 ", 1143, 281, 798, 757);

  double ax[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double ay[12] = {.0, .0, 14.6981, 60.4933, 99.1656, 122.633, 181.512, 207.957, 146.071, 93.3654, 64.3722, 31.6456};
  double aexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double aexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* aeylstat = new double[12]{0.0, 0.0, 0.585029314, 2.293493624, 3.752825752, 4.611779143, 6.803044679, 7.814932757, 5.593404862, 3.838024886, 2.853968576, 1.642247677};
  double* aeyhstat = new double[12]{0.0, 0.0, 0.585029314, 2.293493624, 3.752825752, 4.611779143, 6.803044679, 7.814932757, 5.593404862, 3.838024886, 2.853968576, 1.642247677};

  double* aeylsys = new double[12]{0.0, 0.0, 2.078123679, 8.650038275, 15.0736845, 18.97480161, 21.21489495, 21.95943601, 17.27759805, 12.78552218, 10.18449421, 6.524007873};
  double* aeyhsys = new double[12]{0.0, 0.0, 2.078123679, 8.650038275, 15.0736845, 18.97480161, 21.21489495, 21.95943601, 17.27759805, 12.78552218, 10.18449421, 6.524007873};

  TGraphMultiErrors* gSignf_PbPb5p02_DoubleError = new TGraphMultiErrors("gSignf_PbPb5p02_DoubleError", "Double error Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9 ", 12, ax, ay, aexl, aexh, aeylstat, aeyhstat);
  gSignf_PbPb5p02_DoubleError->AddYError(12, aeylsys, aeyhsys);
  gSignf_PbPb5p02_DoubleError->SetMarkerStyle(4);
  gSignf_PbPb5p02_DoubleError->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleError->GetAttLine(0)->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleError->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_PbPb5p02_DoubleError->GetAttFill(1)->SetFillStyle(0);
  gSignf_PbPb5p02_DoubleError->GetXaxis()->SetTitle("p_{T} (GeV)");
  gSignf_PbPb5p02_DoubleError->GetXaxis()->SetRange(1, 100);
  gSignf_PbPb5p02_DoubleError->GetXaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleError->GetXaxis()->SetTitleOffset(1);
  gSignf_PbPb5p02_DoubleError->GetXaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleError->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
  gSignf_PbPb5p02_DoubleError->GetYaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleError->GetYaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleError->SetMarkerColor(4);
  gSignf_PbPb5p02_DoubleError->SetMarkerSize(1.3);

  gSignf_PbPb5p02_DoubleError->Draw("a p s ; ; 5 s=0.5");
  Canvas_77->cd();
  Canvas_77->Modified();
  Canvas_77->SetSelected(Canvas_77);

  double sigpereventfactor = 1 / sqrt(NEventsPbPb);
  TH1F* histosignf__11 = new TH1F("histosignf__11", "Significance/event Lb in PbPb 5.02TeV, centr. 30-50%", 12, xAxis1);
  histosignf__11->SetBinContent(3, 1.476411422 * sigpereventfactor);
  histosignf__11->SetBinContent(4, 19.83811666 * sigpereventfactor);
  histosignf__11->SetBinContent(5, 47.37049454 * sigpereventfactor);
  histosignf__11->SetBinContent(6, 70.70376854 * sigpereventfactor);
  histosignf__11->SetBinContent(7, 124.3875541 * sigpereventfactor);
  histosignf__11->SetBinContent(8, 152.0880488 * sigpereventfactor);
  histosignf__11->SetBinContent(9, 90.89947862 * sigpereventfactor);
  histosignf__11->SetBinContent(10, 45.30123391 * sigpereventfactor);
  histosignf__11->SetBinContent(11, 24.97200691 * sigpereventfactor);
  histosignf__11->SetBinContent(12, 8.835840788 * sigpereventfactor);

  histosignf__11->SetBinError(3, 0.194308477 * sigpereventfactor);
  histosignf__11->SetBinError(4, 2.645205765 * sigpereventfactor);
  histosignf__11->SetBinError(5, 6.724885959 * sigpereventfactor);
  histosignf__11->SetBinError(6, 10.16588564 * sigpereventfactor);
  histosignf__11->SetBinError(7, 12.34927916 * sigpereventfactor);
  histosignf__11->SetBinError(8, 11.83167705 * sigpereventfactor);
  histosignf__11->SetBinError(9, 7.320726785 * sigpereventfactor);
  histosignf__11->SetBinError(10, 3.761962422 * sigpereventfactor);
  histosignf__11->SetBinError(11, 1.948953026 * sigpereventfactor);
  histosignf__11->SetBinError(12, 0.711725044 * sigpereventfactor);

  TH1F* histosignf__12 = new TH1F("histosignf__12", "Significance/event Lb in PbPb 5.02TeV, centr. 30-50%, after BDT cut", 12, xAxis1);
  histosignf__12->SetBinContent(3, 14.6981 * sigpereventfactor); // after BDT
  histosignf__12->SetBinContent(4, 60.4933 * sigpereventfactor);
  histosignf__12->SetBinContent(5, 99.1656 * sigpereventfactor);
  histosignf__12->SetBinContent(6, 122.633 * sigpereventfactor);
  histosignf__12->SetBinContent(7, 181.512 * sigpereventfactor);
  histosignf__12->SetBinContent(8, 207.957 * sigpereventfactor);
  histosignf__12->SetBinContent(9, 146.071 * sigpereventfactor);
  histosignf__12->SetBinContent(10, 93.3654 * sigpereventfactor);
  histosignf__12->SetBinContent(11, 64.3722 * sigpereventfactor);
  histosignf__12->SetBinContent(12, 31.6456 * sigpereventfactor);

  histosignf__12->SetBinError(3, 1.933428366 * sigpereventfactor); // after BDT
  histosignf__12->SetBinError(4, 8.065706427 * sigpereventfactor);
  histosignf__12->SetBinError(5, 14.07779787 * sigpereventfactor);
  histosignf__12->SetBinError(6, 17.63314224 * sigpereventfactor);
  histosignf__12->SetBinError(7, 18.02152923 * sigpereventfactor);
  histosignf__12->SetBinError(8, 16.17749439 * sigpereventfactor);
  histosignf__12->SetBinError(9, 11.76424342 * sigpereventfactor);
  histosignf__12->SetBinError(10, 7.753200141 * sigpereventfactor);
  histosignf__12->SetBinError(11, 5.023994727 * sigpereventfactor);
  histosignf__12->SetBinError(12, 2.549194909 * sigpereventfactor);

  TH1D* hBkgPerEvent__3 = new TH1D("hBkgPerEvent__3", "#Lambda_{b}^{0} background yield Pb-Pb #sqrt{s}=5.02TeV 30-50%", 12, xAxis1);
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
  hBkgPerEvent__3->GetXaxis()->SetTitle("p_{T}(#Lambda_{b}^{0}) (GeV/c)");
  hBkgPerEvent__3->GetXaxis()->SetLabelFont(42);
  hBkgPerEvent__3->GetXaxis()->SetLabelOffset(0.015);
  hBkgPerEvent__3->GetXaxis()->SetTitleSize(0.045);
  hBkgPerEvent__3->GetXaxis()->SetTitleOffset(1);
  hBkgPerEvent__3->GetXaxis()->SetTitleFont(42);
  hBkgPerEvent__3->GetYaxis()->SetTitle("#Lambda_{b}^{0} background events per collision");
  hBkgPerEvent__3->GetYaxis()->CenterTitle(true);
  hBkgPerEvent__3->GetYaxis()->SetLabelFont(42);
  hBkgPerEvent__3->GetYaxis()->SetLabelOffset(0.01);
  hBkgPerEvent__3->GetYaxis()->SetTitleSize(0.045);
  hBkgPerEvent__3->GetYaxis()->SetTitleOffset(0.8);
  hBkgPerEvent__3->GetYaxis()->SetTitleFont(42);
  hBkgPerEvent__3->GetZaxis()->SetLabelFont(42);
  hBkgPerEvent__3->GetZaxis()->SetTitleOffset(1);
  hBkgPerEvent__3->GetZaxis()->SetTitleFont(42);

  TH1F* histosignal__3 = new TH1F("histosignal__3", "#Lambda_{b}^{0} signal yield Pb-Pb #sqrt{s}=5.02TeV 30-50%", 12, xAxis1);
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

  histosignal__3->SetBinError(3, histosignal__3->GetBinContent(3) * sqrt(0.1717));
  histosignal__3->SetBinError(4, histosignal__3->GetBinContent(4) * sqrt(0.1737));
  histosignal__3->SetBinError(5, histosignal__3->GetBinContent(5) * sqrt(0.1755));
  histosignal__3->SetBinError(6, histosignal__3->GetBinContent(6) * sqrt(0.1771));
  histosignal__3->SetBinError(7, histosignal__3->GetBinContent(7) * sqrt(0.1785));
  histosignal__3->SetBinError(8, histosignal__3->GetBinContent(8) * sqrt(0.1807));
  histosignal__3->SetBinError(9, histosignal__3->GetBinContent(9) * sqrt(0.1826));
  histosignal__3->SetBinError(10, histosignal__3->GetBinContent(10) * sqrt(0.1827));
  histosignal__3->SetBinError(11, histosignal__3->GetBinContent(11) * sqrt(0.1811));
  histosignal__3->SetBinError(12, histosignal__3->GetBinContent(12) * sqrt(0.1761));

  TH1F* histosignal__4 = new TH1F("histosignal__4", "Lb signal per event PbPb 5.02Tev 30-50% after BDT cut", 12, xAxis1);
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

  histosignal__3->SetLineColor(kBlue);
  histosignal__3->SetLineWidth(3);
  histosignal__3->GetXaxis()->SetTitle("p_{T}(#Lambda_{b}^{0}) (GeV/c)");
  histosignal__3->GetXaxis()->SetRange(1, 100);
  histosignal__3->GetXaxis()->SetLabelFont(42);
  histosignal__3->GetXaxis()->SetTitleOffset(1);
  histosignal__3->GetXaxis()->SetTitleFont(42);
  histosignal__3->GetYaxis()->SetTitle("#Lambda_{b}^{0} signal events per collision");
  histosignal__3->GetYaxis()->SetLabelFont(42);
  histosignal__3->GetYaxis()->SetTitleFont(42);
  histosignal__3->GetZaxis()->SetLabelFont(42);
  histosignal__3->GetZaxis()->SetTitleOffset(1);
  histosignal__3->GetZaxis()->SetTitleFont(42);


      // systematic error
  TCanvas* Canvas_767 = new TCanvas("Canvas_767", "Double error Significance Lb in pp 14TeV, Nevt=1.26E15 Pythia+FONLL", 1143, 281, 798, 757);

  double qx[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double qy[12] = {.0, .0, 2.247977833, 17.38240744, 33.16832892, 65.22914526, 123.1248754, 154.1877467, 108.0468962, 45.25064117, 26.21948484, 11.47582911};
  double qexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double qexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* qeylstat = new double[12]{0.0, 0.0, 0.165132548, 1.276135814, 2.43460628, 4.784354651, 9.02687913, 11.30159835, 7.919930435, 3.321583994, 1.925398048, 0.842908737};
  double* qeyhstat = new double[12]{0.0, 0.0, 0.165132548, 1.276135814, 2.43460628, 4.784354651, 9.02687913, 11.30159835, 7.919930435, 3.321583994, 1.925398048, 0.842908737};

  double* qeylsys = new double[12]{0.0, 0.0, 0.931432007, 7.239611145, 13.88274367, 27.40537246, 51.91121175, 65.39543215, 46.06540126, 19.32675688, 11.15306163, 4.815361434};
  double* qeyhsys = new double[12]{0.0, 0.0, 0.931432007, 7.239611145, 13.88274367, 27.40537246, 51.91121175, 65.39543215, 46.06540126, 19.32675688, 11.15306163, 4.815361434};

  TGraphMultiErrors* gSignf_pp14p0_DoubleErrorPF = new TGraphMultiErrors("gSignf_pp14p0_DoubleErrorPF", "", 12, qx, qy, qexl, qexh, qeylstat, qeyhstat);
  gSignf_pp14p0_DoubleErrorPF->AddYError(12, qeylsys, qeyhsys);
  gSignf_pp14p0_DoubleErrorPF->SetMarkerStyle(4);
  gSignf_pp14p0_DoubleErrorPF->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF->GetAttLine(0)->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_pp14p0_DoubleErrorPF->GetAttFill(1)->SetFillStyle(0);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetRange(1, 100);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetTitleOffset(1);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  gSignf_pp14p0_DoubleErrorPF->GetYaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF->GetYaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF->SetMarkerColor(4);
  gSignf_pp14p0_DoubleErrorPF->SetMarkerSize(1.3);

  gSignf_pp14p0_DoubleErrorPF->Draw("a p s ; ; 5 s=0.5");
  histosignf__9->Draw("hist same");

  auto legend100 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend100->AddEntry(histosignf__9, "pre-cuts", "f");
  legend100->AddEntry(gSignf_pp14p0_DoubleErrorPF, "+BDT cut", "lep");
  legend100->Draw("");

    auto t_b = TLatex();
  t_b.SetNDC();
  t_b.SetTextFont(42);
  t_b.SetTextColor(1);
  t_b.SetTextSize(0.035);
  t_b.SetTextAlign(12);
  t_b.DrawLatex(0.4, 0.75, "#splitline{p-p #sqrt{s}=14.0TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
    auto t_bs = TLatex();
  t_bs.SetNDC();
  t_bs.SetTextFont(42);
  t_bs.SetTextColor(1);
  t_bs.SetTextSize(0.035);
  t_bs.SetTextAlign(12);
  t_bs.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=1.26E15 centr. 30-50%}{}");


  Canvas_767->cd();
  Canvas_767->Modified();
  Canvas_767->SetSelected(Canvas_767);

    // systematic error
  TCanvas* Canvas_777 = new TCanvas("Canvas_777", "Double error Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9 Pythia+FONLL", 1143, 281, 798, 757);

  double rx[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double ry[12] = {.0, .0, 10.53138848, 47.59785125, 78.2755259, 98.04878522, 146.1235665, 166.3721578, 112.393948, 63.16209067, 38.87973579, 15.79879017};
  double rexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double rexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* reylstat = new double[12]{0.0, 0.0, 0.517950512, 2.023541317, 3.304875507, 4.036405911, 5.930019533, 6.82956974, 4.954829091, 3.32312327, 2.276792053, 1.042507524};
  double* reyhstat = new double[12]{0.0, 0.0, 0.517950512, 2.023541317, 3.304875507, 4.036405911, 5.930019533, 6.82956974, 4.954829091, 3.32312327, 2.276792053, 1.042507524};

  double* reylsys = new double[12]{0.0, 0.0, 3.508106335, 14.04812827, 23.55185961, 29.11258076, 38.62781437, 42.76967847, 31.17703499, 20.86527346, 14.13594724, 6.488719761};
  double* reyhsys = new double[12]{0.0, 0.0, 3.508106335, 14.04812827, 23.55185961, 29.11258076, 38.62781437, 42.76967847, 31.17703499, 20.86527346, 14.13594724, 6.488719761};

  TGraphMultiErrors* gSignf_PbPb5p02_DoubleErrorPF = new TGraphMultiErrors("gSignf_PbPb5p02_DoubleErrorPF", "", 12, rx, ry, rexl, rexh, reylstat, reyhstat);
  gSignf_PbPb5p02_DoubleErrorPF->AddYError(12, reylsys, reyhsys);
  gSignf_PbPb5p02_DoubleErrorPF->SetMarkerStyle(4);
  gSignf_PbPb5p02_DoubleErrorPF->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF->GetAttLine(0)->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_PbPb5p02_DoubleErrorPF->GetAttFill(1)->SetFillStyle(0);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetRange(1, 100);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetTitleOffset(1);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  gSignf_PbPb5p02_DoubleErrorPF->GetYaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->GetYaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->SetMarkerColor(4);
  gSignf_PbPb5p02_DoubleErrorPF->SetMarkerSize(1.3);

  gSignf_PbPb5p02_DoubleErrorPF->Draw("a p s ; ; 5 s=0.5");
  histosignf__7->Draw("hist same");

    auto legend101 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend101->AddEntry(histosignf__7, "pre-cuts", "f");
  legend101->AddEntry(gSignf_PbPb5p02_DoubleErrorPF, "+BDT cut", "lep");
  legend101->Draw("");

  auto t_c = TLatex();
  t_c.SetNDC();
  t_c.SetTextFont(42);
  t_c.SetTextColor(1);
  t_c.SetTextSize(0.035);
  t_c.SetTextAlign(12);
  t_c.DrawLatex(0.2, 0.75, "#splitline{Pb-Pb #sqrt{s}=5.02TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
  auto t_cs = TLatex();
  t_cs.SetNDC();
  t_cs.SetTextFont(42);
  t_cs.SetTextColor(1);
  t_cs.SetTextSize(0.035);
  t_cs.SetTextAlign(12);
  t_cs.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=55E9 L_{int}=35nb^{-1} centr. 30-50%}{}");


  Canvas_777->cd();
  Canvas_777->Modified();
  Canvas_777->SetSelected(Canvas_777);

  // NO RICH version
  // systematic error
  TCanvas* Canvas_7676 = new TCanvas("Canvas_7676", "pp no rich", 1143, 281, 798, 757);
   //Double error Significance Lb in pp 14TeV, Nevt=1.26E15 Pythia+FONLL        

  double wx[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double wy[12] = {.0, .0, 4.333333333, 41.66666667, 96.33333333, 230.2106667, 441.2543333, 549.9155, 344.417, 140.3333333, 81.66666667, 24.13333333};
  double wexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double wexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* weylstat = new double[12]{0.0, 0.0, 0.293370286, 2.617414374, 7.146264695, 16.24392548, 24.72272803, 27.96945512, 18.05670748, 5.619723259, 4.906274088, 1.362669749};
  double* weyhstat = new double[12]{0.0, 0.0, 0.293370286, 2.617414374, 7.146264695, 16.24392548, 24.72272803, 27.96945512, 18.05670748, 5.619723259, 4.906274088, 1.362669749};

  double* weylsys = new double[12]{0.0, 0.0, 1.654758418, 14.84878182, 40.74981723, 93.04720498, 163.4720416, 161.8421172, 105.0248461, 32.69856351, 28.42008557, 7.784647461};
  double* weyhsys = new double[12]{0.0, 0.0, 1.654758418, 14.84878182, 40.74981723, 93.04720498, 163.4720416, 161.8421172, 105.0248461, 32.69856351, 28.42008557, 7.784647461};

  TGraphMultiErrors* gSignf_pp14p0_DoubleErrorPF_noRICH = new TGraphMultiErrors("gSignf_pp14p0_DoubleErrorPF_noRICH", "", 12, wx, wy, wexl, wexh, weylstat, weyhstat);
  gSignf_pp14p0_DoubleErrorPF_noRICH->AddYError(12, weylsys, weyhsys);
  gSignf_pp14p0_DoubleErrorPF_noRICH->SetMarkerStyle(4);
  gSignf_pp14p0_DoubleErrorPF_noRICH->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetAttLine(0)->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetAttFill(1)->SetFillStyle(0);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetXaxis()->SetRange(1, 100);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetXaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetXaxis()->SetTitleOffset(1);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetXaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetYaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF_noRICH->GetYaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF_noRICH->SetMarkerColor(4);
  gSignf_pp14p0_DoubleErrorPF_noRICH->SetMarkerSize(1.3);

  gSignf_pp14p0_DoubleErrorPF_noRICH->Draw("a p s ; ; 5 s=0.5");
  histosignf__9->Draw("hist same");

  auto legend160 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend160->AddEntry(histosignf__9, "pre-cuts", "f");
  legend160->AddEntry(gSignf_pp14p0_DoubleErrorPF_noRICH, "+BDT without RICH cut", "lep");
  legend160->Draw("");

  auto t_bb = TLatex();
  t_bb.SetNDC();
  t_bb.SetTextFont(42);
  t_bb.SetTextColor(1);
  t_bb.SetTextSize(0.035);
  t_bb.SetTextAlign(12);
  t_bb.DrawLatex(0.4, 0.75, "#splitline{p-p #sqrt{s}=14.0TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
  auto t_bsb = TLatex();
  t_bsb.SetNDC();
  t_bsb.SetTextFont(42);
  t_bsb.SetTextColor(1);
  t_bsb.SetTextSize(0.035);
  t_bsb.SetTextAlign(12);
  t_bsb.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=1.26E15}{}");

  Canvas_7676->cd();
  Canvas_7676->Modified();
  Canvas_7676->SetSelected(Canvas_7676);
            
  // systematic error
  TCanvas* Canvas_7777 = new TCanvas("Canvas_7777", "pbpb no rich", 1143, 281, 798, 757);

  double ex[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double ey[12] = {.0, .0, 6.217593333, 45.5884, 77.2791, 98.38476667, 145.1447, 168.2886667, 110.707, 67.54046667, 41.98943333, 18.5022};
  double eexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double eexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* eeylstat = new double[12]{0.0, 0.0, 0.346297799, 1.991136995, 3.271036865, 3.988571017, 5.858828941, 6.606106908, 4.743372726, 3.186871604, 2.175365016, 1.084337696};
  double* eeyhstat = new double[12]{0.0, 0.0, 0.346297799, 1.991136995, 3.271036865, 3.988571017, 5.858828941, 6.606106908, 4.743372726, 3.186871604, 2.175365016, 1.084337696};
          
  double* eeylsys = new double[12]{0.0, 0.0, 2.75108602, 13.8977264, 23.39715662, 28.89461937, 38.26549817, 42.07688767, 30.0395425, 20.13006082, 13.58736982, 6.709551841};
  double* eeyhsys = new double[12]{0.0, 0.0, 2.75108602, 13.8977264, 23.39715662, 28.89461937, 38.26549817, 42.07688767, 30.0395425, 20.13006082, 13.58736982, 6.709551841};

  TGraphMultiErrors* gSignf_PbPb5p02_DoubleErrorPF_noRICH = new TGraphMultiErrors("gSignf_PbPb5p02_DoubleErrorPF_noRICH", "", 12, ex, ey, eexl, eexh, eeylstat, eeyhstat);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->AddYError(12, eeylsys, eeyhsys);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->SetMarkerStyle(4);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetAttLine(0)->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetAttFill(1)->SetFillStyle(0);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetXaxis()->SetRange(1, 100);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetXaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetXaxis()->SetTitleOffset(1);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetXaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetYaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->GetYaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->SetMarkerColor(4);
  gSignf_PbPb5p02_DoubleErrorPF_noRICH->SetMarkerSize(1.3);

  gSignf_PbPb5p02_DoubleErrorPF_noRICH->Draw("a p s ; ; 5 s=0.5");
  histosignf__7->Draw("hist same");

  auto legend161 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend161->AddEntry(histosignf__7, "pre-cuts", "f");
  legend161->AddEntry(gSignf_PbPb5p02_DoubleErrorPF_noRICH, "+BDT without RICH cut", "lep");
  legend161->Draw("");

  auto t_cg = TLatex();
  t_cg.SetNDC();
  t_cg.SetTextFont(42);
  t_cg.SetTextColor(1);
  t_cg.SetTextSize(0.035);
  t_cg.SetTextAlign(12);
  t_cg.DrawLatex(0.2, 0.75, "#splitline{Pb-Pb #sqrt{s}=5.02TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
  auto t_csg = TLatex();
  t_csg.SetNDC();
  t_csg.SetTextFont(42);
  t_csg.SetTextColor(1);
  t_csg.SetTextSize(0.035);
  t_csg.SetTextAlign(12);
  t_csg.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=55E9 L_{int}=35nb^{-1} centr. 30-50%}{}");

  Canvas_7777->cd();
  Canvas_7777->Modified();
  Canvas_7777->SetSelected(Canvas_777);

  /// with RICH version
  // systematic error
  TCanvas* Canvas_7679 = new TCanvas("Canvas_7679", "pp with rich", 1143, 281, 798, 757);

  



  double qrx[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double qry[12] = {.0, .0, 3.2, 42, 92.5, 227, 474, 593.5, 402, 155, 74, 26};
  double qrexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double qrexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* qreylstat = new double[12]{0.0, 0.0, 0.293370286, 2.617414374, 7.146264695, 16.24392548, 24.72272803, 27.96945512, 18.05670748, 5.619723259, 4.906274088, 1.362669749};
  double* qreyhstat = new double[12]{0.0, 0.0, 0.293370286, 2.617414374, 7.146264695, 16.24392548, 24.72272803, 27.96945512, 18.05670748, 5.619723259, 4.906274088, 1.362669749};

  double* qreylsys = new double[12]{0.0, 0.0, 1.654758418, 14.84878182, 40.74981723, 93.0472049, 163.4720416, 161.8421172, 105.0248461, 32.69856351, 28.42008557, 7.784647461};
  double* qreyhsys = new double[12]{0.0, 0.0, 1.654758418, 14.84878182, 40.74981723, 93.0472049, 163.4720416, 161.8421172, 105.0248461, 32.69856351, 28.42008557, 7.784647461};

  TGraphMultiErrors* gSignf_pp14p0_DoubleErrorPF_withRICH = new TGraphMultiErrors("gSignf_pp14p0_DoubleErrorPF_withRICH", "", 12, qrx, qry, qrexl, qrexh, qreylstat, qreyhstat);
  gSignf_pp14p0_DoubleErrorPF_withRICH->AddYError(12, qreylsys, qreyhsys);
  gSignf_pp14p0_DoubleErrorPF_withRICH->SetMarkerStyle(4);
  gSignf_pp14p0_DoubleErrorPF_withRICH->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetAttLine(0)->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetAttFill(1)->SetFillStyle(0);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetXaxis()->SetRange(1, 100);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetXaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetXaxis()->SetTitleOffset(1);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetXaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetYaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF_withRICH->GetYaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF_withRICH->SetMarkerColor(4);
  gSignf_pp14p0_DoubleErrorPF_withRICH->SetMarkerSize(1.3);

  gSignf_pp14p0_DoubleErrorPF_withRICH->Draw("a p s ; ; 5 s=0.5");
  histosignf__9->Draw("hist same");

  auto legend1008 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend1008->AddEntry(histosignf__9, "pre-cuts", "f");
  legend1008->AddEntry(gSignf_pp14p0_DoubleErrorPF_withRICH, "+BDT with RICH cut", "lep");
  legend1008->Draw("");

  auto t_bk = TLatex();
  t_bk.SetNDC();
  t_bk.SetTextFont(42);
  t_bk.SetTextColor(1);
  t_bk.SetTextSize(0.035);
  t_bk.SetTextAlign(12);
  t_bk.DrawLatex(0.4, 0.75, "#splitline{p-p #sqrt{s}=14.0TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
  auto t_bsk = TLatex();
  t_bsk.SetNDC();
  t_bsk.SetTextFont(42);
  t_bsk.SetTextColor(1);
  t_bsk.SetTextSize(0.035);
  t_bsk.SetTextAlign(12);
  t_bsk.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=1.26E15}{}");

  Canvas_7679->cd();
  Canvas_7679->Modified();
  Canvas_7679->SetSelected(Canvas_767);

  // systematic error
  TCanvas* Canvas_7771 = new TCanvas("Canvas_7771", "pbpb with rich", 1143, 281, 798, 757);

  double rtx[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double rty[12] = {.0, .0, 7.596816171, 47.88286971, 80.41398629, 100.8179246, 150.059601, 172.8457813, 117.8572564, 73.65353296, 48.42827298, 21.78019873};
  double rtexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double rtexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* rteylstat = new double[12]{0.0, 0.0, 0.434636135, 1.951335715, 3.215254369, 3.943453091, 5.793981898, 6.663121978, 4.724234699, 3.1090431, 2.231894747, 1.211287077};
  double* rteyhstat = new double[12]{0.0, 0.0, 0.434636135, 1.951335715, 3.215254369, 3.943453091, 5.793981898, 6.663121978, 4.724234699, 3.1090431, 2.231894747, 1.211287077};

  double* rteylsys = new double[12]{0.0, 0.0, 3.907607552, 15.78515386, 23.143399, 28.68992776, 37.93631478, 41.87803419, 29.93696269, 19.71215446, 13.89271176, 7.386845551};
  double* rteyhsys = new double[12]{0.0, 0.0, 3.907607552, 15.78515386, 23.143399, 28.68992776, 37.93631478, 41.87803419, 29.93696269, 19.71215446, 13.89271176, 7.386845551};

  TGraphMultiErrors* gSignf_PbPb5p02_DoubleErrorPF_withRICH = new TGraphMultiErrors("gSignf_PbPb5p02_DoubleErrorPF_withRICH", "", 12, rtx, rty, rtexl, rtexh, rteylstat, rteyhstat);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->AddYError(12, rteylsys, rteyhsys);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->SetMarkerStyle(4);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetAttLine(0)->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetAttFill(1)->SetFillStyle(0);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetXaxis()->SetRange(1, 100);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetXaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetXaxis()->SetTitleOffset(1);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetXaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetYaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->GetYaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->SetMarkerColor(4);
  gSignf_PbPb5p02_DoubleErrorPF_withRICH->SetMarkerSize(1.3);

  gSignf_PbPb5p02_DoubleErrorPF_withRICH->Draw("a p s ; ; 5 s=0.5");
  histosignf__7->Draw("hist same");

  auto legend1015 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend1015->AddEntry(histosignf__7, "pre-cuts", "f");
  legend1015->AddEntry(gSignf_PbPb5p02_DoubleErrorPF_withRICH, "+BDT with RICH cut", "lep");
  legend1015->Draw("");

  auto t_ch = TLatex();
  t_ch.SetNDC();
  t_ch.SetTextFont(42);
  t_ch.SetTextColor(1);
  t_ch.SetTextSize(0.035);
  t_ch.SetTextAlign(12);
  t_ch.DrawLatex(0.2, 0.75, "#splitline{Pb-Pb #sqrt{s}=5.02TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
  auto t_csh = TLatex();
  t_csh.SetNDC();
  t_csh.SetTextFont(42);
  t_csh.SetTextColor(1);
  t_csh.SetTextSize(0.035);
  t_csh.SetTextAlign(12);
  t_csh.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=55E9 L_{int}=35nb^{-1} centr. 30-50%}{}");

  Canvas_7771->cd();
  Canvas_7771->Modified();
  Canvas_7771->SetSelected(Canvas_777);


  // histo without error, just for comparison
  TH1F* histosignf__1099 = new TH1F("histosignf__1099", "Significance pp precut", 12, xAxis1);
  TH1F* histosignf__1098 = new TH1F("histosignf__1098", "Significance pp simple", 12, xAxis1);
  TH1F* histosignf__1097 = new TH1F("histosignf__1097", "Significance pp noRICH", 12, xAxis1);
  TH1F* histosignf__1096 = new TH1F("histosignf__1096", "", 12, xAxis1);//Significance pp withRICH
  histosignf__1096->SetStats(0);
  TH1F* histosignf__2099 = new TH1F("histosignf__2099", "Significance pbpb precut", 12, xAxis1);
  TH1F* histosignf__2098 = new TH1F("histosignf__2098", "Significance pbpb simple", 12, xAxis1);
  TH1F* histosignf__2097 = new TH1F("histosignf__2097", "Significance pbpb noRICH", 12, xAxis1);
  TH1F* histosignf__2096 = new TH1F("histosignf__2096", "", 12, xAxis1);//Significance pbpb withRICH
  histosignf__2096->SetStats(0);
  for (int i = 0; i < 12; i++) {
    histosignf__1099->SetBinContent(i, histosignf__9->GetBinContent(i+1));
      histosignf__1098->SetBinContent(i,  qy[i]);
      histosignf__1097->SetBinContent(i, wy[i]);
      histosignf__1096->SetBinContent(i, qry[i]);
      histosignf__2099->SetBinContent(i, histosignf__9->GetBinContent(i+1));
      histosignf__2098->SetBinContent(i, ry[i]);
      histosignf__2097->SetBinContent(i, ey[i]);
      histosignf__2096->SetBinContent(i, rty[i]);
  }

  TCanvas* Canvas_957 = new TCanvas("Canvas_957", "pp comparison", 1143, 281, 798, 757);
  

  histosignf__1096->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  histosignf__1096->GetXaxis()->SetRange(0, 25);
  histosignf__1096->GetXaxis()->SetLabelFont(42);
  histosignf__1096->GetXaxis()->SetTitleOffset(1);
  histosignf__1096->GetXaxis()->SetTitleFont(42);
  histosignf__1096->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  histosignf__1096->GetYaxis()->SetLabelFont(42);
  histosignf__1096->GetYaxis()->SetTitleFont(42);
  histosignf__1096->SetLineColor(kGreen-2);
  histosignf__1096->SetLineWidth(2);
  histosignf__1096->Draw("hist");
  histosignf__1098->SetLineColor(kViolet-5);
  histosignf__1098->SetLineWidth(2);
  histosignf__1098->Draw("hist same");
  histosignf__1097->SetLineColor(kBlue);
  histosignf__1097->SetLineWidth(2);
  histosignf__1097->Draw("hist same");
  histosignf__1099->SetLineColor(kRed);
  histosignf__1099->SetLineWidth(2);
  histosignf__1099->Draw("hist same");
  auto legend10152 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend10152->AddEntry(histosignf__1096, "+RICH", "f");
  legend10152->AddEntry(histosignf__1097, "+TOF & #Lambda_{c}^{+}", "f");
  legend10152->AddEntry(histosignf__1098, "+BDT cut", "f");
  legend10152->AddEntry(histosignf__1099, "pre-cuts", "f");
  legend10152->Draw("");
  auto t_bkx = TLatex();
  t_bkx.SetNDC();
  t_bkx.SetTextFont(42);
  t_bkx.SetTextColor(1);
  t_bkx.SetTextSize(0.035);
  t_bkx.SetTextAlign(12);
  t_bkx.DrawLatex(0.4, 0.75, "#splitline{p-p #sqrt{s}=14.0TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
  auto t_bskx = TLatex();
  t_bskx.SetNDC();
  t_bskx.SetTextFont(42);
  t_bskx.SetTextColor(1);
  t_bskx.SetTextSize(0.035);
  t_bskx.SetTextAlign(12);
  t_bskx.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=1.26E15}{}");


  TCanvas* Canvas_956 = new TCanvas("Canvas_956", "pbpb comparison", 1143, 281, 798, 757);

  histosignf__2096->GetXaxis()->SetTitle("p_{T} (#Lambda_{b}^{0}) (GeV)");
  histosignf__2096->GetXaxis()->SetRange(0, 25);
  histosignf__2096->GetXaxis()->SetLabelFont(42);
  histosignf__2096->GetXaxis()->SetTitleOffset(1);
  histosignf__2096->GetXaxis()->SetTitleFont(42);
  histosignf__2096->GetYaxis()->SetTitle("#Lambda_{b}^{0} significance (3#sigma)");
  histosignf__2096->GetYaxis()->SetLabelFont(42);
  histosignf__2096->GetYaxis()->SetTitleFont(42);
  histosignf__2096->SetLineColor(kGreen-2);
  histosignf__2096->SetLineWidth(2);
  histosignf__2096->Draw("hist");
  histosignf__2098->SetLineColor(kViolet-5);
  histosignf__2098->SetLineWidth(2);
  histosignf__2098->Draw("hist same");
  histosignf__2097->SetLineColor(kBlue);
  histosignf__2097->SetLineWidth(2);
  histosignf__2097->Draw("hist same");
  histosignf__2099->SetLineColor(kRed);
  histosignf__2099->SetLineWidth(2);
  histosignf__2099->Draw("hist same");
  auto legend10153 = new TLegend(0.1, 0.7, 0.48, 0.9);
  legend10153->AddEntry(histosignf__2096, "+RICH", "f");
  legend10153->AddEntry(histosignf__2097, "+TOF & #Lambda_{c}^{+}", "f");
  legend10153->AddEntry(histosignf__2098, "+BDT cut", "f");
  legend10153->AddEntry(histosignf__2099, "pre-cuts", "f");
  legend10153->Draw("");
  auto t_chx = TLatex();
  t_chx.SetNDC();
  t_chx.SetTextFont(42);
  t_chx.SetTextColor(1);
  t_chx.SetTextSize(0.035);
  t_chx.SetTextAlign(12);
  t_chx.DrawLatex(0.2, 0.75, "#splitline{Pb-Pb #sqrt{s}=5.02TeV, |y| <1.44}{#Lambda_{b}^{0} #rightarrow p + K^{-} + #pi^{+} + #pi^{-}}");
  auto t_cshx = TLatex();
  t_cshx.SetNDC();
  t_cshx.SetTextFont(42);
  t_cshx.SetTextColor(1);
  t_cshx.SetTextSize(0.035);
  t_cshx.SetTextAlign(12);
  t_cshx.DrawLatex(0.4, 0.55, "#splitline{ N_{evt}=55E9 L_{int}=35nb^{-1} centr. 30-50%}{}");

  Canvas_956->cd();
  Canvas_956->Modified();
  Canvas_956->SetSelected(Canvas_956);

  /// <summary>
  /// Write to file
  /// </summary>
  TFile TMPFile("Lb_histograms.root", "RECREATE");
  TMPFile.WriteObject(eff__1, "Lb_reconeff");
  TMPFile.WriteObject(eff__2, "Lb_reconeffBDT_PbPb");
  TMPFile.WriteObject(histosignf__9, "Lb_pp_sign");
  TMPFile.WriteObject(histosignf__10, "Lb_pp_signBDT");
  TMPFile.WriteObject(histosignf__13, "Lb_pp_signperevent");
  TMPFile.WriteObject(histosignf__14, "Lb_pp_signpereventBDT");
  TMPFile.WriteObject(histosignal__1, "Lb_pp_sigperevent");
  TMPFile.WriteObject(histosignal__2, "Lb_pp_sigpereventBDT");
  TMPFile.WriteObject(hBkgPerEvent__1, "Lb_pp_bkgperevent");
  TMPFile.WriteObject(hBkgPerEvent__2, "Lb_pp_bkgpereventBDT");
  TMPFile.WriteObject(histosignf__7, "Lb_PbPb_sign");
  TMPFile.WriteObject(histosignf__8, "Lb_PbPb_signBDT");
  TMPFile.WriteObject(histosignf__11, "Lb_PbPb_signperevent");
  TMPFile.WriteObject(histosignf__12, "Lb_PbPb_signpereventBDT");
  TMPFile.WriteObject(histosignal__3, "Lb_PbPb_sigperevent");
  TMPFile.WriteObject(histosignal__4, "Lb_PbPb_sigpereventBDT");
  TMPFile.WriteObject(hBkgPerEvent__3, "Lb_PbPb_bkgperevent");
  TMPFile.WriteObject(hBkgPerEvent__4, "Lb_PbPb_bkgpereventBDT");
  TMPFile.WriteObject(gSignf_PbPb5p02_DoubleError, "Lb_PbPb5p02_signfDoubleError"); //only PYTHIA
  TMPFile.WriteObject(gSignf_pp14p0_DoubleErrorPF, "Lb_Signf_pp14p0_DoubleErrorPF"); //both PYTHIA and FONLL
  TMPFile.WriteObject(gSignf_PbPb5p02_DoubleErrorPF, "Lb_Signf_PbPb5p02_DoubleErrorPF");//both PYTHIA and FONLL
  TMPFile.WriteObject(gSignf_pp14p0_DoubleErrorPF_noRICH, "Lb_Signf_pp14p0_DoubleErrorPF_noRICH"); // both PYTHIA and FONLL
  TMPFile.WriteObject(gSignf_PbPb5p02_DoubleErrorPF_noRICH, "Lb_Signf_PbPb5p02_DoubleErrorPF_noRICH"); // both PYTHIA and FONLL
  TMPFile.WriteObject(gSignf_pp14p0_DoubleErrorPF_withRICH, "Lb_Signf_pp14p0_DoubleErrorPF_withRICH");            // both PYTHIA and FONLL
  TMPFile.WriteObject(gSignf_PbPb5p02_DoubleErrorPF_withRICH, "Lb_Signf_PbPb5p02_DoubleErrorPF_withRICH");      // both PYTHIA and FONLL
}