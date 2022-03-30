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
  legend3->AddEntry(histosignal__1, "Panos' cuts", "f");
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

  TH1F* histosignf__9 = new TH1F("histosignf__9", "Significance Lb in pp 14TeV, Nevt=1.26E15", 12, xAxis1);
  histosignf__9->SetBinContent(3, 0.960121204);
  histosignf__9->SetBinContent(4, 7.300882464);
  histosignf__9->SetBinContent(5, 21.40347928);
  histosignf__9->SetBinContent(6, 53.04167744);
  histosignf__9->SetBinContent(7, 122.6176088);
  histosignf__9->SetBinContent(8, 161.7100383);
  histosignf__9->SetBinContent(9, 122.1781281);
  histosignf__9->SetBinContent(10, 46.42496492);
  histosignf__9->SetBinContent(11, 23.86596022);
  histosignf__9->SetBinContent(12, 9.027774988);

  TH1F* histosignf__10 = new TH1F("histosignf__10", "Significance Lb in pp 14TeV, Nevt=1.26E15 after BDT cut", 12, xAxis1);
  histosignf__10->SetBinContent(3, 3.157);
  histosignf__10->SetBinContent(4, 24.436);
  histosignf__10->SetBinContent(5, 46.676);
  histosignf__10->SetBinContent(6, 91.851);
  histosignf__10->SetBinContent(7, 173.468);
  histosignf__10->SetBinContent(8, 217.392);
  histosignf__10->SetBinContent(9, 152.307);
  histosignf__10->SetBinContent(10, 63.696);
  histosignf__10->SetBinContent(11, 36.772);
  histosignf__10->SetBinContent(12, 15.964);
  
  histosignf__10->SetLineWidth(2);
  histosignf__10->GetXaxis()->SetTitle("p_{T} (GeV)");
  histosignf__10->GetXaxis()->SetRange(1, 100);
  histosignf__10->GetXaxis()->SetLabelFont(42);
  histosignf__10->GetXaxis()->SetTitleOffset(1);
  histosignf__10->GetXaxis()->SetTitleFont(42);
  histosignf__10->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
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
  histosignf__9->SetMarkerColor(2);
  histosignf__9->SetMarkerStyle(5);
  histosignf__9->SetMarkerSize(1.3);

  histosignf__9->SetStats(0);
  histosignf__10->SetStats(0);
  histosignf__10->Draw("");
  histosignf__9->Draw("same");

  auto legend5 = new TLegend(0.1, 0.7, 0.48, 0.9);
  TLegendEntry* entry1 = legend5->AddEntry(histosignf__9, "Panos' cuts", "lep");
  entry1->SetMarkerStyle(5);
  entry1 = legend5->AddEntry(histosignf__10, "+BDT cut", "lep");
  entry1->SetMarkerStyle(4);
  legend5->Draw("");

  Canvas_5->cd();
  Canvas_5->Modified();
  Canvas_5->SetSelected(Canvas_5);

    // systematic error
  TCanvas* Canvas_76 = new TCanvas("Canvas_76", "Double error Significance Lb in pp 14TeV, Nevt=1.26E15", 1143, 281, 798, 757);

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
  TH1F* histosignf__13 = new TH1F("histosignf__9", "Significance per event Lb in pp 14TeV, Nevt=1.26E15", 12, xAxis1);
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

  TH1F* histosignf__14 = new TH1F("histosignf__10", "Significance per event Lb in pp 14TeV, Nevt=1.26E15 after BDT cut", 12, xAxis1);
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

  TH1F* histosignal__3 = new TH1F("histosignal__3", "Lb signal per event PbPb 5.02Tev 30-50%", 12, xAxis1);
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

  TGraphMultiErrors* gSignf_pp14p0_DoubleErrorPF = new TGraphMultiErrors("gSignf_pp14p0_DoubleErrorPF", "Double error Significance Lb in pp 14TeV, Nevt=1.26E15 Pythia+FONLL", 12, qx, qy, qexl, qexh, qeylstat, qeyhstat);
  gSignf_pp14p0_DoubleErrorPF->AddYError(12, peylsys, peyhsys);
  gSignf_pp14p0_DoubleErrorPF->SetMarkerStyle(4);
  gSignf_pp14p0_DoubleErrorPF->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF->GetAttLine(0)->SetLineColor(kRed);
  gSignf_pp14p0_DoubleErrorPF->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_pp14p0_DoubleErrorPF->GetAttFill(1)->SetFillStyle(0);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetTitle("p_{T} (GeV)");
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetRange(1, 100);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetTitleOffset(1);
  gSignf_pp14p0_DoubleErrorPF->GetXaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
  gSignf_pp14p0_DoubleErrorPF->GetYaxis()->SetLabelFont(42);
  gSignf_pp14p0_DoubleErrorPF->GetYaxis()->SetTitleFont(42);
  gSignf_pp14p0_DoubleErrorPF->SetMarkerColor(4);
  gSignf_pp14p0_DoubleErrorPF->SetMarkerSize(1.3);

  gSignf_pp14p0_DoubleErrorPF->Draw("a p s ; ; 5 s=0.5");
  Canvas_767->cd();
  Canvas_767->Modified();
  Canvas_767->SetSelected(Canvas_767);

    // systematic error
  TCanvas* Canvas_777 = new TCanvas("Canvas_777", "Double error Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9 Pythia+FONLL", 1143, 281, 798, 757);

  double rx[12] = {0.25, 0.75, 1.5, 2.5, 3.5, 4.5, 6, 8.5, 11.5, 14.5, 18, 22};
  double ry[12] = {.0, .0, 12.19458422, 50.68258144, 83.06790941, 102.8136469, 152.228166, 174.2279332, 121.9157496, 76.83452449, 52.21965438, 24.8959652};
  double rexl[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double rexh[12] = {0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 1.0, 1.5, 1.5, 1.5, 2.0, 2.0};
  double* reylstat = new double[12]{0.0, 0.0, 0.498827571, 1.944758912, 3.179678298, 3.901967477, 5.750767295, 6.606106908, 4.741957492, 3.273729683, 2.432208484, 1.366626312};
  double* reyhstat = new double[12]{0.0, 0.0, 0.498827571, 1.944758912, 3.179678298, 3.901967477, 5.750767295, 6.606106908, 4.741957492, 3.273729683, 2.432208484, 1.366626312};

  double* reylsys = new double[12]{0.0, 0.0, 3.418445998, 13.6839039, 22.98240627, 28.50249386, 37.71740403, 41.57336254, 30.03195466, 20.59823968, 14.98242866, 8.227062708};
  double* reyhsys = new double[12]{0.0, 0.0, 3.418445998, 13.6839039, 22.98240627, 28.50249386, 37.71740403, 41.57336254, 30.03195466, 20.59823968, 14.98242866, 8.227062708};

  TGraphMultiErrors* gSignf_PbPb5p02_DoubleErrorPF = new TGraphMultiErrors("gSignf_PbPb5p02_DoubleErrorPF", "Double error Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9 Pythia+FONLL", 12, rx, ry, rexl, rexh, reylstat, reyhstat);
  gSignf_PbPb5p02_DoubleErrorPF->AddYError(12, aeylsys, aeyhsys);
  gSignf_PbPb5p02_DoubleErrorPF->SetMarkerStyle(4);
  gSignf_PbPb5p02_DoubleErrorPF->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF->GetAttLine(0)->SetLineColor(kRed);
  gSignf_PbPb5p02_DoubleErrorPF->GetAttLine(1)->SetLineColor(kBlue);
  gSignf_PbPb5p02_DoubleErrorPF->GetAttFill(1)->SetFillStyle(0);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetTitle("p_{T} (GeV)");
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetRange(1, 100);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetTitleOffset(1);
  gSignf_PbPb5p02_DoubleErrorPF->GetXaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
  gSignf_PbPb5p02_DoubleErrorPF->GetYaxis()->SetLabelFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->GetYaxis()->SetTitleFont(42);
  gSignf_PbPb5p02_DoubleErrorPF->SetMarkerColor(4);
  gSignf_PbPb5p02_DoubleErrorPF->SetMarkerSize(1.3);

  gSignf_PbPb5p02_DoubleErrorPF->Draw("a p s ; ; 5 s=0.5");
  Canvas_777->cd();
  Canvas_777->Modified();
  Canvas_777->SetSelected(Canvas_777);


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
}