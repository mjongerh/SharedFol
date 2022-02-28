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
  double* aeylstat = new double[12]{0.0, 0.0, 5.949280998, 9.834196424, 15.16048126, 18.50901144, 18.87938863, 17.12796321, 13.04044564, 9.579556961, 7.542965078, 6.176908112};
  double* aeyhstat = new double[12]{0.0, 0.0, 5.949280998, 9.834196424, 15.16048126, 18.50901144, 18.87938863, 17.12796321, 13.04044564, 9.579556961, 7.542965078, 6.176908112};
  double* aeylsys = new double[12]{0.0, 0.0, 1.406217321, 6.05601751, 10.45978246, 13.69091238, 21.94096854, 29.02971369, 24.27686046, 18.16911763, 14.6798901, 8.501549225};
  double* aeyhsys = new double[12]{0.0, 0.0, 1.406217321, 6.05601751, 10.45978246, 13.69091238, 21.94096854, 29.02971369, 24.27686046, 18.16911763, 14.6798901, 8.501549225};

  TGraphMultiErrors* gme = new TGraphMultiErrors("gme", "Double error Significance Lb in PbPb 5.02TeV, centr. 30-50%, Nevt=55E9 ", 5, ax, ay, aexl, aexh, aeylstat, aeyhstat);
  gme->AddYError(12, aeylsys, aeyhsys);
  gme->SetMarkerStyle(4);
  gme->SetLineColor(kRed);
  gme->GetAttLine(0)->SetLineColor(kRed);
  gme->GetAttLine(1)->SetLineColor(kBlue);
  gme->GetAttFill(1)->SetFillStyle(0);
  gme->GetXaxis()->SetTitle("p_{T} (GeV)");
  gme->GetXaxis()->SetRange(1, 100);
  gme->GetXaxis()->SetLabelFont(42);
  gme->GetXaxis()->SetTitleOffset(1);
  gme->GetXaxis()->SetTitleFont(42);
  gme->GetYaxis()->SetTitle("Lb significance S/sqrt(S+B)");
  gme->GetYaxis()->SetLabelFont(42);
  gme->GetYaxis()->SetTitleFont(42);
  gme->SetMarkerColor(4);
  gme->SetMarkerSize(1.3);

  gme->Draw("a p s ; ; 5 s=0.5");
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
}