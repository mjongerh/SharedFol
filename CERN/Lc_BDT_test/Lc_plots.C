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
  Canvas_1->SetLogy();

  TH1D* hBkgPerEvent__2 = new TH1D("hBkgPerEvent__2", "#Lambda_{c}^{+} background per event", 10, xAxis2);
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

  auto t_b = TLatex();
  t_b.SetNDC();
  t_b.SetTextFont(42);
  t_b.SetTextColor(1);
  t_b.SetTextSize(0.035);
  t_b.SetTextAlign(12);
  t_b.DrawLatex(0.2, 0.75, "#splitline{PbPb #sqrt{s}=5.02TeV, |y| <1}{#Lambda_{c}^{+} #rightarrow p + K^{-} + #pi^{+}, centr. 30-50%}");


  TCanvas* Canvas_2 = new TCanvas("Canvas_2", "Canvas_1", 367, 161, 1295, 807);
  Canvas_2->SetLogy();
  TH1F* histosignal__1 = new TH1F("histosignal__1", "#Lambda_{c}^{+} signal per event ", 10, xAxis2);
  histosignal__1->SetBinContent(1, 4.92914e+08/3.8e10);
  histosignal__1->SetBinContent(2, 2.21432e+09/3.8e10);
  histosignal__1->SetBinContent(3, 3.10382e+09/3.8e10);
  histosignal__1->SetBinContent(4, 2.82725e+09/3.8e10);
  histosignal__1->SetBinContent(5, 2.23624e+09/3.8e10);
  histosignal__1->SetBinContent(6, 1.35756e+09/3.8e10);
  histosignal__1->SetBinContent(7, 1.48177e+09/3.8e10);
  histosignal__1->SetBinContent(8, 7.71874e+08/3.8e10);
  histosignal__1->SetBinContent(9, 1.46573e+08/3.8e10);
  histosignal__1->SetBinContent(10, 1.36606e+07/3.8e10);
  //histosignal__1->SetBinError(1, 25476.9/3.8e10);
  //histosignal__1->SetBinError(2, 25476.9/3.8e10);
  //histosignal__1->SetBinError(3, 14678.1/3.8e10);
  //histosignal__1->SetBinError(4, 9457.04/3.8e10);
  //histosignal__1->SetBinError(5, 7514.49/3.8e10);
  //histosignal__1->SetBinError(6, 8792.39/3.8e10);
  //histosignal__1->SetBinError(7, 6455.13/3.8e10);
  //histosignal__1->SetBinError(8, 9924.99/3.8e10);
  //histosignal__1->SetBinError(9, 33541.4/3.8e10);
  //histosignal__1->SetBinError(10, 177081/3.8e10);

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

  auto t_s = TLatex();
  t_s.SetNDC();
  t_s.SetTextFont(42);
  t_s.SetTextColor(1);
  t_s.SetTextSize(0.035);
  t_s.SetTextAlign(12);
  t_s.DrawLatex(0.2, 0.75, "#splitline{PbPb #sqrt{s}=5.02TeV, |y| <1}{#Lambda_{c}^{+} #rightarrow p + K^{-} + #pi^{+}, centr. 30-50%}");



  /// Paramdistributions
  TString oldfileDir = "~/Desktop/SharedFol/TMP/TMVA_Lc_paramdist.root";
  TFile* oldFile = new TFile(oldfileDir);

  TTree* oldtree;
  TString objectstring = "dataset/TrainTree";
  oldFile->GetObject(objectstring, oldtree);
  if (oldtree == nullptr) {
    printf("tree not found");
  }
  Long64_t nentries = oldtree->GetEntries();
  float PtEntry, fM, BDT, fDecayLength, fDecayLengthXY, fImpactParameter0, fImpactParameter1, fCPA, fCPAXY, fChi2PCA;
  Int_t classID;
  oldtree->SetBranchAddress("fPt", &PtEntry);
  oldtree->SetBranchAddress("fM", &fM);
  oldtree->SetBranchAddress("fDecayLength", &fDecayLength);
  oldtree->SetBranchAddress("fImpactParameter0", &fImpactParameter0);
  oldtree->SetBranchAddress("fCPA", &fCPA);
  oldtree->SetBranchAddress("classID", &classID);

  Float_t weight;
  weight = 1.0; // Nbkg/Nsig;

  TH1F* hMS = new TH1F("hMS", "SIGNAL M", 50, 1.0, 3.0);
  TH1F* hMB = new TH1F("hMB", "BACKGROUND M", 50, 1.0, 3.0);
  TH1F* hDecayLengthS = new TH1F("hDecayLengthS", "SIGNAL Decay length", 50, 0.0, 0.4);
  TH1F* hDecayLengthB = new TH1F("hDecayLengthB", "BACKGROUND Decay", 50, 0.0, 0.4);
  TH1F* hImpactParameter0S = new TH1F("hImpactParameter0S", "SIGNAL Impact param0", 50, -0.1, 0.1);
  TH1F* hImpactParameter0B = new TH1F("hImpactParameter0B", "BACKGROUND Impact param0", 50, -0.1, 0.1);
  TH1F* hCPAS = new TH1F("hCPAS", "SIGNAL CPA", 100, 0.95, 1.05);
  TH1F* hCPAB = new TH1F("hCPAB", "BACKGROUND CPA", 100, 0.95, 1.05);


  for (Int_t i = 0; i < nentries; i++) {
    oldtree->GetEntry(i);
    if (classID == 0) {
      hMS->Fill(fM, weight);
      hDecayLengthS->Fill(fDecayLength, weight);
      hImpactParameter0S->Fill(fImpactParameter0, weight);
      hCPAS->Fill(fCPA, weight);
    } else {
      hMB->Fill(fM, weight);
      hDecayLengthB->Fill(fDecayLength), weight;
      hImpactParameter0B->Fill(fImpactParameter0, weight);
      hCPAB->Fill(fCPA, weight);
    }
  }
  hMS->Scale(1 / hMS->GetEntries());
  hMB->Scale(1 / hMB->GetEntries());
  hDecayLengthS->Scale(1 / hDecayLengthS->GetEntries());
  hDecayLengthB->Scale(1 / hDecayLengthB->GetEntries());
  hImpactParameter0S->Scale(1 / hImpactParameter0S->GetEntries());
  hImpactParameter0B->Scale(1 / hImpactParameter0B->GetEntries());
  hCPAS->Scale(1 / hCPAS->GetEntries());
  hCPAB->Scale(1 / hCPAB->GetEntries());


  /////
  TCanvas* canvas3 = new TCanvas("canvas3", "Input variables (training sample)", 167, 165, 800, 440);
  gStyle->SetOptStat(0);
  canvas3->Range(0, 0, 1, 1);

  TColor* color; // for color definition with alpha
  ci = TColor::GetColor("#f0f0f0");
  canvas3->SetFillColor(ci);
  canvas3->SetBorderMode(0);
  canvas3->SetBorderSize(2);
  canvas3->SetTickx(1);
  canvas3->SetTicky(1);
  canvas3->SetLeftMargin(0.12);
  canvas3->SetRightMargin(0.05);

  ci = TColor::GetColor("#fffffd");
  canvas3->SetFrameFillColor(ci);
  canvas3->SetFrameBorderMode(0);

  // ------------>Primitives in pad: canvas3_1
  TPad* canvas3_1 = new TPad("canvas3_1", "canvas3_1", 0.01, 0.51, 0.3233333, 0.99);
  canvas3_1->Draw();
  canvas3_1->cd();
  canvas3_1->Range(0.7547625, -30.03394, 1.020972, 178.5351);

  ci = TColor::GetColor("#f0f0f0");
  canvas3_1->SetFillColor(ci);
  canvas3_1->SetBorderMode(0);
  canvas3_1->SetBorderSize(2);
  canvas3_1->SetTickx(1);
  canvas3_1->SetTicky(1);
  canvas3_1->SetLeftMargin(0.17);
  canvas3_1->SetRightMargin(0.06);
  canvas3_1->SetBottomMargin(0.144);

  ci = TColor::GetColor("#fffffd");
  canvas3_1->SetFrameFillColor(ci);
  canvas3_1->SetFrameBorderMode(0);

  ci = TColor::GetColor("#fffffd");
  canvas3_1->SetFrameFillColor(ci);
  canvas3_1->SetFrameBorderMode(0);

  
  hCPAS->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  hCPAS->SetLineColor(ci);
  hCPAS->SetLineWidth(2);
  hCPAS->GetXaxis()->SetTitle("fCPA  [units]");
  hCPAS->GetXaxis()->SetLabelFont(42);
  hCPAS->GetXaxis()->SetLabelOffset(0.012);
  hCPAS->GetXaxis()->SetLabelSize(0.048);
  hCPAS->GetXaxis()->SetTitleSize(0.054);
  hCPAS->GetXaxis()->SetTitleOffset(1.25);
  hCPAS->GetXaxis()->SetTitleFont(42);
  hCPAS->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.00512 units");
  hCPAS->GetYaxis()->SetLabelFont(42);
  hCPAS->GetYaxis()->SetLabelOffset(0.012);
  hCPAS->GetYaxis()->SetLabelSize(0.048);
  hCPAS->GetYaxis()->SetTitleSize(0.054);
  hCPAS->GetYaxis()->SetTitleOffset(1.7);
  hCPAS->GetYaxis()->SetTitleFont(42);
  hCPAS->GetZaxis()->SetLabelFont(42);
  hCPAS->GetZaxis()->SetTitleOffset(1);
  hCPAS->GetZaxis()->SetTitleFont(42);
  hCPAS->Draw("hist");

  
  hCPAB->SetFillColor(2);
  hCPAB->SetFillStyle(3554);
  hCPAB->SetLineColor(2);
  hCPAB->SetLineWidth(2);
  hCPAB->GetXaxis()->SetTitle("fCPA  [units]");
  hCPAB->GetXaxis()->SetRange(20, 41);
  hCPAB->GetXaxis()->SetLabelFont(42);
  hCPAB->GetXaxis()->SetTitleOffset(1);
  hCPAB->GetXaxis()->SetTitleFont(42);
  hCPAB->GetYaxis()->SetTitle("dN_{ }/^{ }0.00512 units");
  hCPAB->GetYaxis()->SetLabelFont(42);
  hCPAB->GetYaxis()->SetTitleFont(42);
  hCPAB->GetZaxis()->SetLabelFont(42);
  hCPAB->GetZaxis()->SetTitleOffset(1);
  hCPAB->GetZaxis()->SetTitleFont(42);
  hCPAB->Draw("histsame");

  TLegend* leg = new TLegend(0.17, 0.75, 0.57, 0.9, NULL, "brNDC");
  leg->SetBorderSize(1);
  leg->SetTextFont(62);

  ci = TColor::GetColor("#7d8b9d");
  leg->SetLineColor(ci);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1);
  TLegendEntry* entry = leg->AddEntry("fCPA__Signal_Id", "Signal", "F");
  entry->SetFillColor(38);
  entry->SetFillStyle(1001);

  ci = TColor::GetColor("#0000ee");
  entry->SetLineColor(ci);
  entry->SetLineStyle(1);
  entry->SetLineWidth(2);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(62);
  entry = leg->AddEntry("fCPA__Background_Id", "Background", "F");
  entry->SetFillColor(2);
  entry->SetFillStyle(3554);
  entry->SetLineColor(2);
  entry->SetLineStyle(1);
  entry->SetLineWidth(2);
  entry->SetMarkerColor(1);
  entry->SetMarkerStyle(21);
  entry->SetMarkerSize(1);
  entry->SetTextFont(62);
  leg->Draw();


  TText* text = new TText(0.98, 0.14, "U/O-flow (S,B): (0.0, 0.0)% / (0.0, 0.0)%");
  text->SetNDC();
  text->SetTextSize(0.04);
  text->SetTextAngle(90);
  text->Draw();

  TPaveText* pt = new TPaveText(0.01, 0.9288942, 0.4139386, 0.995, "blNDC");
  pt->SetName("title");
  pt->SetBorderSize(1);

  ci = TColor::GetColor("#5d6b7d");
  pt->SetFillColor(ci);

  ci = TColor::GetColor("#7d8b9d");
  pt->SetLineColor(ci);
  pt->SetTextColor(0);
  TText* pt_LaTex = pt->AddText("Input variable: fCPA");
  pt->Draw();
  canvas3_1->Modified();
  canvas3->cd();

  // ------------>Primitives in pad: canvas3_2
  TPad* canvas3_2 = new TPad("canvas3_2", "canvas3_2", 0.3433333, 0.51, 0.6566667, 0.99);
  canvas3_2->Draw();
  canvas3_2->cd();
  canvas3_2->Range(-0.9530699, -1.921443, 4.676763, 11.42191);

  ci = TColor::GetColor("#f0f0f0");
  canvas3_2->SetFillColor(ci);
  canvas3_2->SetBorderMode(0);
  canvas3_2->SetBorderSize(2);
  canvas3_2->SetTickx(1);
  canvas3_2->SetTicky(1);
  canvas3_2->SetLeftMargin(0.17);
  canvas3_2->SetRightMargin(0.06);
  canvas3_2->SetBottomMargin(0.144);

  ci = TColor::GetColor("#fffffd");
  canvas3_2->SetFrameFillColor(ci);
  canvas3_2->SetFrameBorderMode(0);

  ci = TColor::GetColor("#fffffd");
  canvas3_2->SetFrameFillColor(ci);
  canvas3_2->SetFrameBorderMode(0);


  hDecayLengthS->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  hDecayLengthS->SetLineColor(ci);
  hDecayLengthS->SetLineWidth(2);
  hDecayLengthS->GetXaxis()->SetTitle("fDecayLength  [units]");
  hDecayLengthS->GetXaxis()->SetLabelFont(42);
  hDecayLengthS->GetXaxis()->SetLabelOffset(0.012);
  hDecayLengthS->GetXaxis()->SetLabelSize(0.048);
  hDecayLengthS->GetXaxis()->SetTitleSize(0.054);
  hDecayLengthS->GetXaxis()->SetTitleOffset(1.25);
  hDecayLengthS->GetXaxis()->SetTitleFont(42);
  hDecayLengthS->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.108 units");
  hDecayLengthS->GetYaxis()->SetLabelFont(42);
  hDecayLengthS->GetYaxis()->SetLabelOffset(0.012);
  hDecayLengthS->GetYaxis()->SetLabelSize(0.048);
  hDecayLengthS->GetYaxis()->SetTitleSize(0.054);
  hDecayLengthS->GetYaxis()->SetTitleOffset(1.7);
  hDecayLengthS->GetYaxis()->SetTitleFont(42);
  hDecayLengthS->GetZaxis()->SetLabelFont(42);
  hDecayLengthS->GetZaxis()->SetTitleOffset(1);
  hDecayLengthS->GetZaxis()->SetTitleFont(42);
  hDecayLengthS->Draw("hist");

 
  hDecayLengthB->SetFillColor(2);
  hDecayLengthB->SetFillStyle(3554);
  hDecayLengthB->SetLineColor(2);
  hDecayLengthB->SetLineWidth(2);
  hDecayLengthB->GetXaxis()->SetTitle("fDecayLength  [units]");
  hDecayLengthB->GetXaxis()->SetRange(1, 40);
  hDecayLengthB->GetXaxis()->SetLabelFont(42);
  hDecayLengthB->GetXaxis()->SetTitleOffset(1);
  hDecayLengthB->GetXaxis()->SetTitleFont(42);
  hDecayLengthB->GetYaxis()->SetTitle("dN_{ }/^{ }0.108 units");
  hDecayLengthB->GetYaxis()->SetLabelFont(42);
  hDecayLengthB->GetYaxis()->SetTitleFont(42);
  hDecayLengthB->GetZaxis()->SetLabelFont(42);
  hDecayLengthB->GetZaxis()->SetTitleOffset(1);
  hDecayLengthB->GetZaxis()->SetTitleFont(42);
  hDecayLengthB->Draw("histsame");

  

  pt = new TPaveText(0.01, 0.9288942, 0.5779123, 0.995, "blNDC");
  pt->SetName("title");
  pt->SetBorderSize(1);

  ci = TColor::GetColor("#5d6b7d");
  pt->SetFillColor(ci);

  ci = TColor::GetColor("#7d8b9d");
  pt->SetLineColor(ci);
  pt->SetTextColor(0);
  pt_LaTex = pt->AddText("Input variable: fDecayLength");
  pt->Draw();
  canvas3_2->Modified();
  canvas3->cd();

  // ------------>Primitives in pad: canvas3_3
  TPad* canvas3_3 = new TPad("canvas3_3", "canvas3_3", 0.6766667, 0.51, 0.99, 0.99);
  canvas3_3->Draw();
  canvas3_3->cd();
  canvas3_3->Range(-0.2386221, -16.87589, 0.1989076, 100.3178);

  ci = TColor::GetColor("#f0f0f0");
  canvas3_3->SetFillColor(ci);
  canvas3_3->SetBorderMode(0);
  canvas3_3->SetBorderSize(2);
  canvas3_3->SetTickx(1);
  canvas3_3->SetTicky(1);
  canvas3_3->SetLeftMargin(0.17);
  canvas3_3->SetRightMargin(0.06);
  canvas3_3->SetBottomMargin(0.144);

  ci = TColor::GetColor("#fffffd");
  canvas3_3->SetFrameFillColor(ci);
  canvas3_3->SetFrameBorderMode(0);

  ci = TColor::GetColor("#fffffd");
  canvas3_3->SetFrameFillColor(ci);
  canvas3_3->SetFrameBorderMode(0);

  hImpactParameter0S->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  hImpactParameter0S->SetLineColor(ci);
  hImpactParameter0S->SetLineWidth(2);
  hImpactParameter0S->GetXaxis()->SetTitle("fImpactParameter0  [units]");
  hImpactParameter0S->GetXaxis()->SetLabelFont(42);
  hImpactParameter0S->GetXaxis()->SetLabelOffset(0.012);
  hImpactParameter0S->GetXaxis()->SetLabelSize(0.048);
  hImpactParameter0S->GetXaxis()->SetTitleSize(0.054);
  hImpactParameter0S->GetXaxis()->SetTitleOffset(1.25);
  hImpactParameter0S->GetXaxis()->SetTitleFont(42);
  hImpactParameter0S->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.00842 units");
  hImpactParameter0S->GetYaxis()->SetLabelFont(42);
  hImpactParameter0S->GetYaxis()->SetLabelOffset(0.012);
  hImpactParameter0S->GetYaxis()->SetLabelSize(0.048);
  hImpactParameter0S->GetYaxis()->SetTitleSize(0.054);
  hImpactParameter0S->GetYaxis()->SetTitleOffset(1.7);
  hImpactParameter0S->GetYaxis()->SetTitleFont(42);
  hImpactParameter0S->GetZaxis()->SetLabelFont(42);
  hImpactParameter0S->GetZaxis()->SetTitleOffset(1);
  hImpactParameter0S->GetZaxis()->SetTitleFont(42);
  hImpactParameter0S->Draw("hist");

  hImpactParameter0B->SetFillColor(2);
  hImpactParameter0B->SetFillStyle(3554);
  hImpactParameter0B->SetLineColor(2);
  hImpactParameter0B->SetLineWidth(2);
  hImpactParameter0B->GetXaxis()->SetTitle("fImpactParameter0  [units]");
  hImpactParameter0B->GetXaxis()->SetRange(8, 32);
  hImpactParameter0B->GetXaxis()->SetLabelFont(42);
  hImpactParameter0B->GetXaxis()->SetTitleOffset(1);
  hImpactParameter0B->GetXaxis()->SetTitleFont(42);
  hImpactParameter0B->GetYaxis()->SetTitle("dN_{ }/^{ }0.00842 units");
  hImpactParameter0B->GetYaxis()->SetLabelFont(42);
  hImpactParameter0B->GetYaxis()->SetTitleFont(42);
  hImpactParameter0B->GetZaxis()->SetLabelFont(42);
  hImpactParameter0B->GetZaxis()->SetTitleOffset(1);
  hImpactParameter0B->GetZaxis()->SetTitleFont(42);
  hImpactParameter0B->Draw("histsame");

  TH1F* fImpactParameter0__Signal_Id__9 = new TH1F("fImpactParameter0__Signal_Id__9", "Input variable: fImpactParameter0", 40, -0.1642421, 0.1726558);
  fImpactParameter0__Signal_Id__9->SetBinContent(14, 0.02475612);
  fImpactParameter0__Signal_Id__9->SetBinContent(15, 0.06189029);
  fImpactParameter0__Signal_Id__9->SetBinContent(16, 0.07426835);
  fImpactParameter0__Signal_Id__9->SetBinContent(17, 0.5198784);
  fImpactParameter0__Signal_Id__9->SetBinContent(18, 1.930977);
  fImpactParameter0__Signal_Id__9->SetBinContent(19, 16.57422);
  fImpactParameter0__Signal_Id__9->SetBinContent(20, 80.54402);
  fImpactParameter0__Signal_Id__9->SetBinContent(21, 16.43806);
  fImpactParameter0__Signal_Id__9->SetBinContent(22, 1.906221);
  fImpactParameter0__Signal_Id__9->SetBinContent(23, 0.420854);
  fImpactParameter0__Signal_Id__9->SetBinContent(24, 0.1361586);
  fImpactParameter0__Signal_Id__9->SetBinContent(25, 0.02475612);
  fImpactParameter0__Signal_Id__9->SetBinContent(26, 0.02475612);
  fImpactParameter0__Signal_Id__9->SetBinContent(27, 0.01237806);
  fImpactParameter0__Signal_Id__9->SetBinContent(29, 0.01237806);
  fImpactParameter0__Signal_Id__9->SetBinContent(31, 0.02475612);
  fImpactParameter0__Signal_Id__9->SetBinError(14, 0.01750522);
  fImpactParameter0__Signal_Id__9->SetBinError(15, 0.02767818);
  fImpactParameter0__Signal_Id__9->SetBinError(16, 0.03031993);
  fImpactParameter0__Signal_Id__9->SetBinError(17, 0.08021899);
  fImpactParameter0__Signal_Id__9->SetBinError(18, 0.1546019);
  fImpactParameter0__Signal_Id__9->SetBinError(19, 0.4529422);
  fImpactParameter0__Signal_Id__9->SetBinError(20, 0.9984882);
  fImpactParameter0__Signal_Id__9->SetBinError(21, 0.4510779);
  fImpactParameter0__Signal_Id__9->SetBinError(22, 0.1536077);
  fImpactParameter0__Signal_Id__9->SetBinError(23, 0.07217586);
  fImpactParameter0__Signal_Id__9->SetBinError(24, 0.04105338);
  fImpactParameter0__Signal_Id__9->SetBinError(25, 0.01750522);
  fImpactParameter0__Signal_Id__9->SetBinError(26, 0.01750522);
  fImpactParameter0__Signal_Id__9->SetBinError(27, 0.01237806);
  fImpactParameter0__Signal_Id__9->SetBinError(29, 0.01237806);
  fImpactParameter0__Signal_Id__9->SetBinError(31, 0.01750522);
  fImpactParameter0__Signal_Id__9->SetMaximum(88.59843);
  fImpactParameter0__Signal_Id__9->SetEntries(9592);
  fImpactParameter0__Signal_Id__9->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  fImpactParameter0__Signal_Id__9->SetLineColor(ci);
  fImpactParameter0__Signal_Id__9->SetLineWidth(2);
  fImpactParameter0__Signal_Id__9->GetXaxis()->SetTitle("fImpactParameter0  [units]");
  fImpactParameter0__Signal_Id__9->GetXaxis()->SetLabelFont(42);
  fImpactParameter0__Signal_Id__9->GetXaxis()->SetLabelOffset(0.012);
  fImpactParameter0__Signal_Id__9->GetXaxis()->SetLabelSize(0.048);
  fImpactParameter0__Signal_Id__9->GetXaxis()->SetTitleSize(0.054);
  fImpactParameter0__Signal_Id__9->GetXaxis()->SetTitleOffset(1.25);
  fImpactParameter0__Signal_Id__9->GetXaxis()->SetTitleFont(42);
  fImpactParameter0__Signal_Id__9->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.00842 units");
  fImpactParameter0__Signal_Id__9->GetYaxis()->SetLabelFont(42);
  fImpactParameter0__Signal_Id__9->GetYaxis()->SetLabelOffset(0.012);
  fImpactParameter0__Signal_Id__9->GetYaxis()->SetLabelSize(0.048);
  fImpactParameter0__Signal_Id__9->GetYaxis()->SetTitleSize(0.054);
  fImpactParameter0__Signal_Id__9->GetYaxis()->SetTitleOffset(1.7);
  fImpactParameter0__Signal_Id__9->GetYaxis()->SetTitleFont(42);
  fImpactParameter0__Signal_Id__9->GetZaxis()->SetLabelFont(42);
  fImpactParameter0__Signal_Id__9->GetZaxis()->SetTitleOffset(1);
  fImpactParameter0__Signal_Id__9->GetZaxis()->SetTitleFont(42);
  fImpactParameter0__Signal_Id__9->Draw("sameaxis");
  text = new TText(0.98, 0.14, "U/O-flow (S,B): (0.0, 0.1)% / (0.0, 0.1)%");
  text->SetNDC();
  text->SetTextSize(0.04);
  text->SetTextAngle(90);
  text->Draw();

  pt = new TPaveText(0.01, 0.9288942, 0.673897, 0.995, "blNDC");
  pt->SetName("title");
  pt->SetBorderSize(1);

  ci = TColor::GetColor("#5d6b7d");
  pt->SetFillColor(ci);

  ci = TColor::GetColor("#7d8b9d");
  pt->SetLineColor(ci);
  pt->SetTextColor(0);
  pt_LaTex = pt->AddText("Input variable: fImpactParameter0");
  pt->Draw();
  canvas3_3->Modified();
  canvas3->cd();

  // ------------>Primitives in pad: canvas3_4
  TPad* canvas3_4 = new TPad("canvas3_4", "canvas3_4", 0.01, 0.01, 0.3233333, 0.49);
  canvas3_4->Draw();
  canvas3_4->cd();
  canvas3_4->Range(-0.2238581, -16.18861, 0.1866853, 96.2323);

  ci = TColor::GetColor("#f0f0f0");
  canvas3_4->SetFillColor(ci);
  canvas3_4->SetBorderMode(0);
  canvas3_4->SetBorderSize(2);
  canvas3_4->SetTickx(1);
  canvas3_4->SetTicky(1);
  canvas3_4->SetLeftMargin(0.17);
  canvas3_4->SetRightMargin(0.06);
  canvas3_4->SetBottomMargin(0.144);

  ci = TColor::GetColor("#fffffd");
  canvas3_4->SetFrameFillColor(ci);
  canvas3_4->SetFrameBorderMode(0);

  ci = TColor::GetColor("#fffffd");
  canvas3_4->SetFrameFillColor(ci);
  canvas3_4->SetFrameBorderMode(0);

  TH1F* fImpactParameter1__Signal_Id__10 = new TH1F("fImpactParameter1__Signal_Id__10", "Input variable: fImpactParameter1", 40, -0.1540657, 0.1620527);
  fImpactParameter1__Signal_Id__10->SetBinContent(14, 0.03957512);
  fImpactParameter1__Signal_Id__10->SetBinContent(15, 0.05276683);
  fImpactParameter1__Signal_Id__10->SetBinContent(16, 0.1714922);
  fImpactParameter1__Signal_Id__10->SetBinContent(17, 0.6727771);
  fImpactParameter1__Signal_Id__10->SetBinContent(18, 2.8626);
  fImpactParameter1__Signal_Id__10->SetBinContent(19, 21.3178);
  fImpactParameter1__Signal_Id__10->SetBinContent(20, 77.26382);
  fImpactParameter1__Signal_Id__10->SetBinContent(21, 20.31523);
  fImpactParameter1__Signal_Id__10->SetBinContent(22, 2.730683);
  fImpactParameter1__Signal_Id__10->SetBinContent(23, 0.7255439);
  fImpactParameter1__Signal_Id__10->SetBinContent(24, 0.1055337);
  fImpactParameter1__Signal_Id__10->SetBinContent(25, 0.2110673);
  fImpactParameter1__Signal_Id__10->SetBinContent(26, 0.03957512);
  fImpactParameter1__Signal_Id__10->SetBinContent(32, 0.02638341);
  fImpactParameter1__Signal_Id__10->SetBinError(14, 0.02284871);
  fImpactParameter1__Signal_Id__10->SetBinError(15, 0.02638341);
  fImpactParameter1__Signal_Id__10->SetBinError(16, 0.04756337);
  fImpactParameter1__Signal_Id__10->SetBinError(17, 0.09420763);
  fImpactParameter1__Signal_Id__10->SetBinError(18, 0.194326);
  fImpactParameter1__Signal_Id__10->SetBinError(19, 0.5303);
  fImpactParameter1__Signal_Id__10->SetBinError(20, 1.009575);
  fImpactParameter1__Signal_Id__10->SetBinError(21, 0.5176799);
  fImpactParameter1__Signal_Id__10->SetBinError(22, 0.1897956);
  fImpactParameter1__Signal_Id__10->SetBinError(23, 0.09783231);
  fImpactParameter1__Signal_Id__10->SetBinError(24, 0.03731178);
  fImpactParameter1__Signal_Id__10->SetBinError(25, 0.05276683);
  fImpactParameter1__Signal_Id__10->SetBinError(26, 0.02284871);
  fImpactParameter1__Signal_Id__10->SetBinError(32, 0.01865589);
  fImpactParameter1__Signal_Id__10->SetMaximum(84.99021);
  fImpactParameter1__Signal_Id__10->SetEntries(9592);
  fImpactParameter1__Signal_Id__10->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  fImpactParameter1__Signal_Id__10->SetLineColor(ci);
  fImpactParameter1__Signal_Id__10->SetLineWidth(2);
  fImpactParameter1__Signal_Id__10->GetXaxis()->SetTitle("fImpactParameter1  [units]");
  fImpactParameter1__Signal_Id__10->GetXaxis()->SetLabelFont(42);
  fImpactParameter1__Signal_Id__10->GetXaxis()->SetLabelOffset(0.012);
  fImpactParameter1__Signal_Id__10->GetXaxis()->SetLabelSize(0.048);
  fImpactParameter1__Signal_Id__10->GetXaxis()->SetTitleSize(0.054);
  fImpactParameter1__Signal_Id__10->GetXaxis()->SetTitleOffset(1.25);
  fImpactParameter1__Signal_Id__10->GetXaxis()->SetTitleFont(42);
  fImpactParameter1__Signal_Id__10->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.0079 units");
  fImpactParameter1__Signal_Id__10->GetYaxis()->SetLabelFont(42);
  fImpactParameter1__Signal_Id__10->GetYaxis()->SetLabelOffset(0.012);
  fImpactParameter1__Signal_Id__10->GetYaxis()->SetLabelSize(0.048);
  fImpactParameter1__Signal_Id__10->GetYaxis()->SetTitleSize(0.054);
  fImpactParameter1__Signal_Id__10->GetYaxis()->SetTitleOffset(1.7);
  fImpactParameter1__Signal_Id__10->GetYaxis()->SetTitleFont(42);
  fImpactParameter1__Signal_Id__10->GetZaxis()->SetLabelFont(42);
  fImpactParameter1__Signal_Id__10->GetZaxis()->SetTitleOffset(1);
  fImpactParameter1__Signal_Id__10->GetZaxis()->SetTitleFont(42);
  fImpactParameter1__Signal_Id__10->Draw("hist");

  TH1F* fImpactParameter1__Background_Id__11 = new TH1F("fImpactParameter1__Background_Id__11", "fImpactParameter1", 40, -0.1540657, 0.1620527);
  fImpactParameter1__Background_Id__11->SetBinContent(0, 0.09228191);
  fImpactParameter1__Background_Id__11->SetBinContent(1, 0.01051313);
  fImpactParameter1__Background_Id__11->SetBinContent(2, 0.009345003);
  fImpactParameter1__Background_Id__11->SetBinContent(3, 0.02569876);
  fImpactParameter1__Background_Id__11->SetBinContent(4, 0.02336251);
  fImpactParameter1__Background_Id__11->SetBinContent(5, 0.03971626);
  fImpactParameter1__Background_Id__11->SetBinContent(6, 0.04555689);
  fImpactParameter1__Background_Id__11->SetBinContent(7, 0.0642469);
  fImpactParameter1__Background_Id__11->SetBinContent(8, 0.05256564);
  fImpactParameter1__Background_Id__11->SetBinContent(9, 0.1051313);
  fImpactParameter1__Background_Id__11->SetBinContent(10, 0.1203169);
  fImpactParameter1__Background_Id__11->SetBinContent(11, 0.1355025);
  fImpactParameter1__Background_Id__11->SetBinContent(12, 0.2581557);
  fImpactParameter1__Background_Id__11->SetBinContent(13, 0.288527);
  fImpactParameter1__Background_Id__11->SetBinContent(14, 0.4602414);
  fImpactParameter1__Background_Id__11->SetBinContent(15, 0.7335827);
  fImpactParameter1__Background_Id__11->SetBinContent(16, 1.371379);
  fImpactParameter1__Background_Id__11->SetBinContent(17, 2.630618);
  fImpactParameter1__Background_Id__11->SetBinContent(18, 6.493609);
  fImpactParameter1__Background_Id__11->SetBinContent(19, 20.75876);
  fImpactParameter1__Background_Id__11->SetBinContent(20, 59.53701);
  fImpactParameter1__Background_Id__11->SetBinContent(21, 20.5041);
  fImpactParameter1__Background_Id__11->SetBinContent(22, 6.652474);
  fImpactParameter1__Background_Id__11->SetBinContent(23, 2.545345);
  fImpactParameter1__Background_Id__11->SetBinContent(24, 1.254567);
  fImpactParameter1__Background_Id__11->SetBinContent(25, 0.7908209);
  fImpactParameter1__Background_Id__11->SetBinContent(26, 0.4403833);
  fImpactParameter1__Background_Id__11->SetBinContent(27, 0.2581557);
  fImpactParameter1__Background_Id__11->SetBinContent(28, 0.232457);
  fImpactParameter1__Background_Id__11->SetBinContent(29, 0.1541926);
  fImpactParameter1__Background_Id__11->SetBinContent(30, 0.1086357);
  fImpactParameter1__Background_Id__11->SetBinContent(31, 0.09929066);
  fImpactParameter1__Background_Id__11->SetBinContent(32, 0.05723815);
  fImpactParameter1__Background_Id__11->SetBinContent(33, 0.06191065);
  fImpactParameter1__Background_Id__11->SetBinContent(34, 0.07008752);
  fImpactParameter1__Background_Id__11->SetBinContent(35, 0.02453063);
  fImpactParameter1__Background_Id__11->SetBinContent(36, 0.02686688);
  fImpactParameter1__Background_Id__11->SetBinContent(37, 0.03854814);
  fImpactParameter1__Background_Id__11->SetBinContent(38, 0.03153938);
  fImpactParameter1__Background_Id__11->SetBinContent(39, 0.01168125);
  fImpactParameter1__Background_Id__11->SetBinContent(40, 0.008176878);
  fImpactParameter1__Background_Id__11->SetBinContent(41, 0.13083);
  fImpactParameter1__Background_Id__11->SetBinError(0, 0.01038253);
  fImpactParameter1__Background_Id__11->SetBinError(1, 0.003504376);
  fImpactParameter1__Background_Id__11->SetBinError(2, 0.003303958);
  fImpactParameter1__Background_Id__11->SetBinError(3, 0.005478994);
  fImpactParameter1__Background_Id__11->SetBinError(4, 0.005224016);
  fImpactParameter1__Background_Id__11->SetBinError(5, 0.006811283);
  fImpactParameter1__Background_Id__11->SetBinError(6, 0.007294941);
  fImpactParameter1__Background_Id__11->SetBinError(7, 0.00866305);
  fImpactParameter1__Background_Id__11->SetBinError(8, 0.007836024);
  fImpactParameter1__Background_Id__11->SetBinError(9, 0.01108181);
  fImpactParameter1__Background_Id__11->SetBinError(10, 0.01185518);
  fImpactParameter1__Background_Id__11->SetBinError(11, 0.0125811);
  fImpactParameter1__Background_Id__11->SetBinError(12, 0.01736543);
  fImpactParameter1__Background_Id__11->SetBinError(13, 0.01835853);
  fImpactParameter1__Background_Id__11->SetBinError(14, 0.02318663);
  fImpactParameter1__Background_Id__11->SetBinError(15, 0.02927314);
  fImpactParameter1__Background_Id__11->SetBinError(16, 0.04002428);
  fImpactParameter1__Background_Id__11->SetBinError(17, 0.05543367);
  fImpactParameter1__Background_Id__11->SetBinError(18, 0.08709392);
  fImpactParameter1__Background_Id__11->SetBinError(19, 0.1557204);
  fImpactParameter1__Background_Id__11->SetBinError(20, 0.2637171);
  fImpactParameter1__Background_Id__11->SetBinError(21, 0.1547623);
  fImpactParameter1__Background_Id__11->SetBinError(22, 0.08815285);
  fImpactParameter1__Background_Id__11->SetBinError(23, 0.05452781);
  fImpactParameter1__Background_Id__11->SetBinError(24, 0.03828174);
  fImpactParameter1__Background_Id__11->SetBinError(25, 0.03039372);
  fImpactParameter1__Background_Id__11->SetBinError(26, 0.02268089);
  fImpactParameter1__Background_Id__11->SetBinError(27, 0.01736543);
  fImpactParameter1__Background_Id__11->SetBinError(28, 0.01647844);
  fImpactParameter1__Background_Id__11->SetBinError(29, 0.01342074);
  fImpactParameter1__Background_Id__11->SetBinError(30, 0.01126499);
  fImpactParameter1__Background_Id__11->SetBinError(31, 0.01076958);
  fImpactParameter1__Background_Id__11->SetBinError(32, 0.008176878);
  fImpactParameter1__Background_Id__11->SetBinError(33, 0.008504081);
  fImpactParameter1__Background_Id__11->SetBinError(34, 0.009048261);
  fImpactParameter1__Background_Id__11->SetBinError(35, 0.005353023);
  fImpactParameter1__Background_Id__11->SetBinError(36, 0.005602133);
  fImpactParameter1__Background_Id__11->SetBinError(37, 0.00671037);
  fImpactParameter1__Background_Id__11->SetBinError(38, 0.006069758);
  fImpactParameter1__Background_Id__11->SetBinError(39, 0.003693937);
  fImpactParameter1__Background_Id__11->SetBinError(40, 0.003090569);
  fImpactParameter1__Background_Id__11->SetBinError(41, 0.01236228);
  fImpactParameter1__Background_Id__11->SetEntries(108514);
  fImpactParameter1__Background_Id__11->SetFillColor(2);
  fImpactParameter1__Background_Id__11->SetFillStyle(3554);
  fImpactParameter1__Background_Id__11->SetLineColor(2);
  fImpactParameter1__Background_Id__11->SetLineWidth(2);
  fImpactParameter1__Background_Id__11->GetXaxis()->SetTitle("fImpactParameter1  [units]");
  fImpactParameter1__Background_Id__11->GetXaxis()->SetRange(8, 33);
  fImpactParameter1__Background_Id__11->GetXaxis()->SetLabelFont(42);
  fImpactParameter1__Background_Id__11->GetXaxis()->SetTitleOffset(1);
  fImpactParameter1__Background_Id__11->GetXaxis()->SetTitleFont(42);
  fImpactParameter1__Background_Id__11->GetYaxis()->SetTitle("dN_{ }/^{ }0.0079 units");
  fImpactParameter1__Background_Id__11->GetYaxis()->SetLabelFont(42);
  fImpactParameter1__Background_Id__11->GetYaxis()->SetTitleFont(42);
  fImpactParameter1__Background_Id__11->GetZaxis()->SetLabelFont(42);
  fImpactParameter1__Background_Id__11->GetZaxis()->SetTitleOffset(1);
  fImpactParameter1__Background_Id__11->GetZaxis()->SetTitleFont(42);
  fImpactParameter1__Background_Id__11->Draw("histsame");

  TH1F* fImpactParameter1__Signal_Id__12 = new TH1F("fImpactParameter1__Signal_Id__12", "Input variable: fImpactParameter1", 40, -0.1540657, 0.1620527);
  fImpactParameter1__Signal_Id__12->SetBinContent(14, 0.03957512);
  fImpactParameter1__Signal_Id__12->SetBinContent(15, 0.05276683);
  fImpactParameter1__Signal_Id__12->SetBinContent(16, 0.1714922);
  fImpactParameter1__Signal_Id__12->SetBinContent(17, 0.6727771);
  fImpactParameter1__Signal_Id__12->SetBinContent(18, 2.8626);
  fImpactParameter1__Signal_Id__12->SetBinContent(19, 21.3178);
  fImpactParameter1__Signal_Id__12->SetBinContent(20, 77.26382);
  fImpactParameter1__Signal_Id__12->SetBinContent(21, 20.31523);
  fImpactParameter1__Signal_Id__12->SetBinContent(22, 2.730683);
  fImpactParameter1__Signal_Id__12->SetBinContent(23, 0.7255439);
  fImpactParameter1__Signal_Id__12->SetBinContent(24, 0.1055337);
  fImpactParameter1__Signal_Id__12->SetBinContent(25, 0.2110673);
  fImpactParameter1__Signal_Id__12->SetBinContent(26, 0.03957512);
  fImpactParameter1__Signal_Id__12->SetBinContent(32, 0.02638341);
  fImpactParameter1__Signal_Id__12->SetBinError(14, 0.02284871);
  fImpactParameter1__Signal_Id__12->SetBinError(15, 0.02638341);
  fImpactParameter1__Signal_Id__12->SetBinError(16, 0.04756337);
  fImpactParameter1__Signal_Id__12->SetBinError(17, 0.09420763);
  fImpactParameter1__Signal_Id__12->SetBinError(18, 0.194326);
  fImpactParameter1__Signal_Id__12->SetBinError(19, 0.5303);
  fImpactParameter1__Signal_Id__12->SetBinError(20, 1.009575);
  fImpactParameter1__Signal_Id__12->SetBinError(21, 0.5176799);
  fImpactParameter1__Signal_Id__12->SetBinError(22, 0.1897956);
  fImpactParameter1__Signal_Id__12->SetBinError(23, 0.09783231);
  fImpactParameter1__Signal_Id__12->SetBinError(24, 0.03731178);
  fImpactParameter1__Signal_Id__12->SetBinError(25, 0.05276683);
  fImpactParameter1__Signal_Id__12->SetBinError(26, 0.02284871);
  fImpactParameter1__Signal_Id__12->SetBinError(32, 0.01865589);
  fImpactParameter1__Signal_Id__12->SetMaximum(84.99021);
  fImpactParameter1__Signal_Id__12->SetEntries(9592);
  fImpactParameter1__Signal_Id__12->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  fImpactParameter1__Signal_Id__12->SetLineColor(ci);
  fImpactParameter1__Signal_Id__12->SetLineWidth(2);
  fImpactParameter1__Signal_Id__12->GetXaxis()->SetTitle("fImpactParameter1  [units]");
  fImpactParameter1__Signal_Id__12->GetXaxis()->SetLabelFont(42);
  fImpactParameter1__Signal_Id__12->GetXaxis()->SetLabelOffset(0.012);
  fImpactParameter1__Signal_Id__12->GetXaxis()->SetLabelSize(0.048);
  fImpactParameter1__Signal_Id__12->GetXaxis()->SetTitleSize(0.054);
  fImpactParameter1__Signal_Id__12->GetXaxis()->SetTitleOffset(1.25);
  fImpactParameter1__Signal_Id__12->GetXaxis()->SetTitleFont(42);
  fImpactParameter1__Signal_Id__12->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.0079 units");
  fImpactParameter1__Signal_Id__12->GetYaxis()->SetLabelFont(42);
  fImpactParameter1__Signal_Id__12->GetYaxis()->SetLabelOffset(0.012);
  fImpactParameter1__Signal_Id__12->GetYaxis()->SetLabelSize(0.048);
  fImpactParameter1__Signal_Id__12->GetYaxis()->SetTitleSize(0.054);
  fImpactParameter1__Signal_Id__12->GetYaxis()->SetTitleOffset(1.7);
  fImpactParameter1__Signal_Id__12->GetYaxis()->SetTitleFont(42);
  fImpactParameter1__Signal_Id__12->GetZaxis()->SetLabelFont(42);
  fImpactParameter1__Signal_Id__12->GetZaxis()->SetTitleOffset(1);
  fImpactParameter1__Signal_Id__12->GetZaxis()->SetTitleFont(42);
  fImpactParameter1__Signal_Id__12->Draw("sameaxis");
  text = new TText(0.98, 0.14, "U/O-flow (S,B): (0.0, 0.1)% / (0.0, 0.1)%");
  text->SetNDC();
  text->SetTextSize(0.04);
  text->SetTextAngle(90);
  text->Draw();

  pt = new TPaveText(0.01, 0.9288942, 0.6698976, 0.995, "blNDC");
  pt->SetName("title");
  pt->SetBorderSize(1);

  ci = TColor::GetColor("#5d6b7d");
  pt->SetFillColor(ci);

  ci = TColor::GetColor("#7d8b9d");
  pt->SetLineColor(ci);
  pt->SetTextColor(0);
  pt_LaTex = pt->AddText("Input variable: fImpactParameter1");
  pt->Draw();
  canvas3_4->Modified();
  canvas3->cd();

  // ------------>Primitives in pad: canvas3_5
  TPad* canvas3_5 = new TPad("canvas3_5", "canvas3_5", 0.3433333, 0.01, 0.6566667, 0.49);
  canvas3_5->Draw();
  canvas3_5->cd();
  canvas3_5->Range(-0.2404849, -16.57239, 0.2002648, 98.51362);

  ci = TColor::GetColor("#f0f0f0");
  canvas3_5->SetFillColor(ci);
  canvas3_5->SetBorderMode(0);
  canvas3_5->SetBorderSize(2);
  canvas3_5->SetTickx(1);
  canvas3_5->SetTicky(1);
  canvas3_5->SetLeftMargin(0.17);
  canvas3_5->SetRightMargin(0.06);
  canvas3_5->SetBottomMargin(0.144);

  ci = TColor::GetColor("#fffffd");
  canvas3_5->SetFrameFillColor(ci);
  canvas3_5->SetFrameBorderMode(0);

  ci = TColor::GetColor("#fffffd");
  canvas3_5->SetFrameFillColor(ci);
  canvas3_5->SetFrameBorderMode(0);

  TH1F* fImpactParameter2__Signal_Id__13 = new TH1F("fImpactParameter2__Signal_Id__13", "Input variable: fImpactParameter2", 40, -0.1655574, 0.1738198);
  fImpactParameter2__Signal_Id__13->SetBinContent(14, 0.02457526);
  fImpactParameter2__Signal_Id__13->SetBinContent(16, 0.1597392);
  fImpactParameter2__Signal_Id__13->SetBinContent(17, 0.4669299);
  fImpactParameter2__Signal_Id__13->SetBinContent(18, 2.285499);
  fImpactParameter2__Signal_Id__13->SetBinContent(19, 16.07222);
  fImpactParameter2__Signal_Id__13->SetBinContent(20, 79.09547);
  fImpactParameter2__Signal_Id__13->SetBinContent(21, 17.01837);
  fImpactParameter2__Signal_Id__13->SetBinContent(22, 2.138048);
  fImpactParameter2__Signal_Id__13->SetBinContent(23, 0.3563413);
  fImpactParameter2__Signal_Id__13->SetBinContent(24, 0.1720268);
  fImpactParameter2__Signal_Id__13->SetBinContent(26, 0.03686289);
  fImpactParameter2__Signal_Id__13->SetBinContent(27, 0.01228763);
  fImpactParameter2__Signal_Id__13->SetBinContent(28, 0.01228763);
  fImpactParameter2__Signal_Id__13->SetBinContent(29, 0.01228763);
  fImpactParameter2__Signal_Id__13->SetBinError(14, 0.01737733);
  fImpactParameter2__Signal_Id__13->SetBinError(16, 0.04430368);
  fImpactParameter2__Signal_Id__13->SetBinError(17, 0.07574604);
  fImpactParameter2__Signal_Id__13->SetBinError(18, 0.1675809);
  fImpactParameter2__Signal_Id__13->SetBinError(19, 0.4443979);
  fImpactParameter2__Signal_Id__13->SetBinError(20, 0.9858478);
  fImpactParameter2__Signal_Id__13->SetBinError(21, 0.4572914);
  fImpactParameter2__Signal_Id__13->SetBinError(22, 0.162085);
  fImpactParameter2__Signal_Id__13->SetBinError(23, 0.06617091);
  fImpactParameter2__Signal_Id__13->SetBinError(24, 0.0459761);
  fImpactParameter2__Signal_Id__13->SetBinError(26, 0.0212828);
  fImpactParameter2__Signal_Id__13->SetBinError(27, 0.01228763);
  fImpactParameter2__Signal_Id__13->SetBinError(28, 0.01228763);
  fImpactParameter2__Signal_Id__13->SetBinError(29, 0.01228763);
  fImpactParameter2__Signal_Id__13->SetMaximum(87.00502);
  fImpactParameter2__Signal_Id__13->SetEntries(9592);
  fImpactParameter2__Signal_Id__13->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  fImpactParameter2__Signal_Id__13->SetLineColor(ci);
  fImpactParameter2__Signal_Id__13->SetLineWidth(2);
  fImpactParameter2__Signal_Id__13->GetXaxis()->SetTitle("fImpactParameter2  [units]");
  fImpactParameter2__Signal_Id__13->GetXaxis()->SetLabelFont(42);
  fImpactParameter2__Signal_Id__13->GetXaxis()->SetLabelOffset(0.012);
  fImpactParameter2__Signal_Id__13->GetXaxis()->SetLabelSize(0.048);
  fImpactParameter2__Signal_Id__13->GetXaxis()->SetTitleSize(0.054);
  fImpactParameter2__Signal_Id__13->GetXaxis()->SetTitleOffset(1.25);
  fImpactParameter2__Signal_Id__13->GetXaxis()->SetTitleFont(42);
  fImpactParameter2__Signal_Id__13->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.00848 units");
  fImpactParameter2__Signal_Id__13->GetYaxis()->SetLabelFont(42);
  fImpactParameter2__Signal_Id__13->GetYaxis()->SetLabelOffset(0.012);
  fImpactParameter2__Signal_Id__13->GetYaxis()->SetLabelSize(0.048);
  fImpactParameter2__Signal_Id__13->GetYaxis()->SetTitleSize(0.054);
  fImpactParameter2__Signal_Id__13->GetYaxis()->SetTitleOffset(1.7);
  fImpactParameter2__Signal_Id__13->GetYaxis()->SetTitleFont(42);
  fImpactParameter2__Signal_Id__13->GetZaxis()->SetLabelFont(42);
  fImpactParameter2__Signal_Id__13->GetZaxis()->SetTitleOffset(1);
  fImpactParameter2__Signal_Id__13->GetZaxis()->SetTitleFont(42);
  fImpactParameter2__Signal_Id__13->Draw("hist");

  TH1F* fImpactParameter2__Background_Id__14 = new TH1F("fImpactParameter2__Background_Id__14", "fImpactParameter2", 40, -0.1655574, 0.1738198);
  fImpactParameter2__Background_Id__14->SetBinContent(0, 0.09791993);
  fImpactParameter2__Background_Id__14->SetBinContent(1, 0.01305599);
  fImpactParameter2__Background_Id__14->SetBinContent(2, 0.01849599);
  fImpactParameter2__Background_Id__14->SetBinContent(3, 0.02067198);
  fImpactParameter2__Background_Id__14->SetBinContent(4, 0.03263997);
  fImpactParameter2__Background_Id__14->SetBinContent(5, 0.02937598);
  fImpactParameter2__Background_Id__14->SetBinContent(6, 0.05548796);
  fImpactParameter2__Background_Id__14->SetBinContent(7, 0.07724794);
  fImpactParameter2__Background_Id__14->SetBinContent(8, 0.07833594);
  fImpactParameter2__Background_Id__14->SetBinContent(9, 0.09356793);
  fImpactParameter2__Background_Id__14->SetBinContent(10, 0.1359999);
  fImpactParameter2__Background_Id__14->SetBinContent(11, 0.1425279);
  fImpactParameter2__Background_Id__14->SetBinContent(12, 0.2719998);
  fImpactParameter2__Background_Id__14->SetBinContent(13, 0.3546877);
  fImpactParameter2__Background_Id__14->SetBinContent(14, 0.5516156);
  fImpactParameter2__Background_Id__14->SetBinContent(15, 0.7615994);
  fImpactParameter2__Background_Id__14->SetBinContent(16, 1.354559);
  fImpactParameter2__Background_Id__14->SetBinContent(17, 2.503486);
  fImpactParameter2__Background_Id__14->SetBinContent(18, 5.521595);
  fImpactParameter2__Background_Id__14->SetBinContent(19, 16.56696);
  fImpactParameter2__Background_Id__14->SetBinContent(20, 60.30671);
  fImpactParameter2__Background_Id__14->SetBinContent(21, 17.03807);
  fImpactParameter2__Background_Id__14->SetBinContent(22, 5.498748);
  fImpactParameter2__Background_Id__14->SetBinContent(23, 2.41971);
  fImpactParameter2__Background_Id__14->SetBinContent(24, 1.336063);
  fImpactParameter2__Background_Id__14->SetBinContent(25, 0.7713914);
  fImpactParameter2__Background_Id__14->SetBinContent(26, 0.4993916);
  fImpactParameter2__Background_Id__14->SetBinContent(27, 0.3481597);
  fImpactParameter2__Background_Id__14->SetBinContent(28, 0.3035518);
  fImpactParameter2__Background_Id__14->SetBinContent(29, 0.1621119);
  fImpactParameter2__Background_Id__14->SetBinContent(30, 0.1479679);
  fImpactParameter2__Background_Id__14->SetBinContent(31, 0.1229439);
  fImpactParameter2__Background_Id__14->SetBinContent(32, 0.06745595);
  fImpactParameter2__Background_Id__14->SetBinContent(33, 0.05875196);
  fImpactParameter2__Background_Id__14->SetBinContent(34, 0.06310395);
  fImpactParameter2__Background_Id__14->SetBinContent(35, 0.03699197);
  fImpactParameter2__Background_Id__14->SetBinContent(36, 0.03155198);
  fImpactParameter2__Background_Id__14->SetBinContent(37, 0.01305599);
  fImpactParameter2__Background_Id__14->SetBinContent(38, 0.02175998);
  fImpactParameter2__Background_Id__14->SetBinContent(39, 0.01958399);
  fImpactParameter2__Background_Id__14->SetBinContent(40, 0.01196799);
  fImpactParameter2__Background_Id__14->SetBinContent(41, 0.1022719);
  fImpactParameter2__Background_Id__14->SetBinError(0, 0.01032167);
  fImpactParameter2__Background_Id__14->SetBinError(1, 0.00376894);
  fImpactParameter2__Background_Id__14->SetBinError(2, 0.004485935);
  fImpactParameter2__Background_Id__14->SetBinError(3, 0.004742478);
  fImpactParameter2__Background_Id__14->SetBinError(4, 0.005959217);
  fImpactParameter2__Background_Id__14->SetBinError(5, 0.005653409);
  fImpactParameter2__Background_Id__14->SetBinError(6, 0.007769868);
  fImpactParameter2__Background_Id__14->SetBinError(7, 0.009167644);
  fImpactParameter2__Background_Id__14->SetBinError(8, 0.009231979);
  fImpactParameter2__Background_Id__14->SetBinError(9, 0.01008969);
  fImpactParameter2__Background_Id__14->SetBinError(10, 0.0121642);
  fImpactParameter2__Background_Id__14->SetBinError(11, 0.01245272);
  fImpactParameter2__Background_Id__14->SetBinError(12, 0.01720278);
  fImpactParameter2__Background_Id__14->SetBinError(13, 0.01964434);
  fImpactParameter2__Background_Id__14->SetBinError(14, 0.02449811);
  fImpactParameter2__Background_Id__14->SetBinError(15, 0.02878575);
  fImpactParameter2__Background_Id__14->SetBinError(16, 0.03838957);
  fImpactParameter2__Background_Id__14->SetBinError(17, 0.05218995);
  fImpactParameter2__Background_Id__14->SetBinError(18, 0.07750801);
  fImpactParameter2__Background_Id__14->SetBinError(19, 0.1342566);
  fImpactParameter2__Background_Id__14->SetBinError(20, 0.2561516);
  fImpactParameter2__Background_Id__14->SetBinError(21, 0.1361521);
  fImpactParameter2__Background_Id__14->SetBinError(22, 0.07734748);
  fImpactParameter2__Background_Id__14->SetBinError(23, 0.05130928);
  fImpactParameter2__Background_Id__14->SetBinError(24, 0.03812657);
  fImpactParameter2__Background_Id__14->SetBinError(25, 0.02897021);
  fImpactParameter2__Background_Id__14->SetBinError(26, 0.0233096);
  fImpactParameter2__Background_Id__14->SetBinError(27, 0.01946272);
  fImpactParameter2__Background_Id__14->SetBinError(28, 0.01817317);
  fImpactParameter2__Background_Id__14->SetBinError(29, 0.01328072);
  fImpactParameter2__Background_Id__14->SetBinError(30, 0.01268814);
  fImpactParameter2__Background_Id__14->SetBinError(31, 0.01156559);
  fImpactParameter2__Background_Id__14->SetBinError(32, 0.008566914);
  fImpactParameter2__Background_Id__14->SetBinError(33, 0.007995128);
  fImpactParameter2__Background_Id__14->SetBinError(34, 0.008285955);
  fImpactParameter2__Background_Id__14->SetBinError(35, 0.006344071);
  fImpactParameter2__Background_Id__14->SetBinError(36, 0.005859055);
  fImpactParameter2__Background_Id__14->SetBinError(37, 0.00376894);
  fImpactParameter2__Background_Id__14->SetBinError(38, 0.00486568);
  fImpactParameter2__Background_Id__14->SetBinError(39, 0.004615989);
  fImpactParameter2__Background_Id__14->SetBinError(40, 0.003608485);
  fImpactParameter2__Background_Id__14->SetBinError(41, 0.01054854);
  fImpactParameter2__Background_Id__14->SetEntries(108514);
  fImpactParameter2__Background_Id__14->SetFillColor(2);
  fImpactParameter2__Background_Id__14->SetFillStyle(3554);
  fImpactParameter2__Background_Id__14->SetLineColor(2);
  fImpactParameter2__Background_Id__14->SetLineWidth(2);
  fImpactParameter2__Background_Id__14->GetXaxis()->SetTitle("fImpactParameter2  [units]");
  fImpactParameter2__Background_Id__14->GetXaxis()->SetRange(8, 32);
  fImpactParameter2__Background_Id__14->GetXaxis()->SetLabelFont(42);
  fImpactParameter2__Background_Id__14->GetXaxis()->SetTitleOffset(1);
  fImpactParameter2__Background_Id__14->GetXaxis()->SetTitleFont(42);
  fImpactParameter2__Background_Id__14->GetYaxis()->SetTitle("dN_{ }/^{ }0.00848 units");
  fImpactParameter2__Background_Id__14->GetYaxis()->SetLabelFont(42);
  fImpactParameter2__Background_Id__14->GetYaxis()->SetTitleFont(42);
  fImpactParameter2__Background_Id__14->GetZaxis()->SetLabelFont(42);
  fImpactParameter2__Background_Id__14->GetZaxis()->SetTitleOffset(1);
  fImpactParameter2__Background_Id__14->GetZaxis()->SetTitleFont(42);
  fImpactParameter2__Background_Id__14->Draw("histsame");

  TH1F* fImpactParameter2__Signal_Id__15 = new TH1F("fImpactParameter2__Signal_Id__15", "Input variable: fImpactParameter2", 40, -0.1655574, 0.1738198);
  fImpactParameter2__Signal_Id__15->SetBinContent(14, 0.02457526);
  fImpactParameter2__Signal_Id__15->SetBinContent(16, 0.1597392);
  fImpactParameter2__Signal_Id__15->SetBinContent(17, 0.4669299);
  fImpactParameter2__Signal_Id__15->SetBinContent(18, 2.285499);
  fImpactParameter2__Signal_Id__15->SetBinContent(19, 16.07222);
  fImpactParameter2__Signal_Id__15->SetBinContent(20, 79.09547);
  fImpactParameter2__Signal_Id__15->SetBinContent(21, 17.01837);
  fImpactParameter2__Signal_Id__15->SetBinContent(22, 2.138048);
  fImpactParameter2__Signal_Id__15->SetBinContent(23, 0.3563413);
  fImpactParameter2__Signal_Id__15->SetBinContent(24, 0.1720268);
  fImpactParameter2__Signal_Id__15->SetBinContent(26, 0.03686289);
  fImpactParameter2__Signal_Id__15->SetBinContent(27, 0.01228763);
  fImpactParameter2__Signal_Id__15->SetBinContent(28, 0.01228763);
  fImpactParameter2__Signal_Id__15->SetBinContent(29, 0.01228763);
  fImpactParameter2__Signal_Id__15->SetBinError(14, 0.01737733);
  fImpactParameter2__Signal_Id__15->SetBinError(16, 0.04430368);
  fImpactParameter2__Signal_Id__15->SetBinError(17, 0.07574604);
  fImpactParameter2__Signal_Id__15->SetBinError(18, 0.1675809);
  fImpactParameter2__Signal_Id__15->SetBinError(19, 0.4443979);
  fImpactParameter2__Signal_Id__15->SetBinError(20, 0.9858478);
  fImpactParameter2__Signal_Id__15->SetBinError(21, 0.4572914);
  fImpactParameter2__Signal_Id__15->SetBinError(22, 0.162085);
  fImpactParameter2__Signal_Id__15->SetBinError(23, 0.06617091);
  fImpactParameter2__Signal_Id__15->SetBinError(24, 0.0459761);
  fImpactParameter2__Signal_Id__15->SetBinError(26, 0.0212828);
  fImpactParameter2__Signal_Id__15->SetBinError(27, 0.01228763);
  fImpactParameter2__Signal_Id__15->SetBinError(28, 0.01228763);
  fImpactParameter2__Signal_Id__15->SetBinError(29, 0.01228763);
  fImpactParameter2__Signal_Id__15->SetMaximum(87.00502);
  fImpactParameter2__Signal_Id__15->SetEntries(9592);
  fImpactParameter2__Signal_Id__15->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  fImpactParameter2__Signal_Id__15->SetLineColor(ci);
  fImpactParameter2__Signal_Id__15->SetLineWidth(2);
  fImpactParameter2__Signal_Id__15->GetXaxis()->SetTitle("fImpactParameter2  [units]");
  fImpactParameter2__Signal_Id__15->GetXaxis()->SetLabelFont(42);
  fImpactParameter2__Signal_Id__15->GetXaxis()->SetLabelOffset(0.012);
  fImpactParameter2__Signal_Id__15->GetXaxis()->SetLabelSize(0.048);
  fImpactParameter2__Signal_Id__15->GetXaxis()->SetTitleSize(0.054);
  fImpactParameter2__Signal_Id__15->GetXaxis()->SetTitleOffset(1.25);
  fImpactParameter2__Signal_Id__15->GetXaxis()->SetTitleFont(42);
  fImpactParameter2__Signal_Id__15->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.00848 units");
  fImpactParameter2__Signal_Id__15->GetYaxis()->SetLabelFont(42);
  fImpactParameter2__Signal_Id__15->GetYaxis()->SetLabelOffset(0.012);
  fImpactParameter2__Signal_Id__15->GetYaxis()->SetLabelSize(0.048);
  fImpactParameter2__Signal_Id__15->GetYaxis()->SetTitleSize(0.054);
  fImpactParameter2__Signal_Id__15->GetYaxis()->SetTitleOffset(1.7);
  fImpactParameter2__Signal_Id__15->GetYaxis()->SetTitleFont(42);
  fImpactParameter2__Signal_Id__15->GetZaxis()->SetLabelFont(42);
  fImpactParameter2__Signal_Id__15->GetZaxis()->SetTitleOffset(1);
  fImpactParameter2__Signal_Id__15->GetZaxis()->SetTitleFont(42);
  fImpactParameter2__Signal_Id__15->Draw("sameaxis");
  text = new TText(0.98, 0.14, "U/O-flow (S,B): (0.0, 0.1)% / (0.0, 0.1)%");
  text->SetNDC();
  text->SetTextSize(0.04);
  text->SetTextAngle(90);
  text->Draw();

  pt = new TPaveText(0.01, 0.9288942, 0.673897, 0.995, "blNDC");
  pt->SetName("title");
  pt->SetBorderSize(1);

  ci = TColor::GetColor("#5d6b7d");
  pt->SetFillColor(ci);

  ci = TColor::GetColor("#7d8b9d");
  pt->SetLineColor(ci);
  pt->SetTextColor(0);
  pt_LaTex = pt->AddText("Input variable: fImpactParameter2");
  pt->Draw();
  canvas3_5->Modified();
  canvas3->cd();

  // ------------>Primitives in pad: canvas3_6
  TPad* canvas3_6 = new TPad("canvas3_6", "canvas3_6", 0.6766667, 0.01, 0.99, 0.49);
  canvas3_6->Draw();
  canvas3_6->cd();
  canvas3_6->Range(-0.5268054, -6.058476, 1.130569, 36.01427);

  ci = TColor::GetColor("#f0f0f0");
  canvas3_6->SetFillColor(ci);
  canvas3_6->SetBorderMode(0);
  canvas3_6->SetBorderSize(2);
  canvas3_6->SetTickx(1);
  canvas3_6->SetTicky(1);
  canvas3_6->SetLeftMargin(0.17);
  canvas3_6->SetRightMargin(0.06);
  canvas3_6->SetBottomMargin(0.144);

  ci = TColor::GetColor("#fffffd");
  canvas3_6->SetFrameFillColor(ci);
  canvas3_6->SetFrameBorderMode(0);

  ci = TColor::GetColor("#fffffd");
  canvas3_6->SetFrameFillColor(ci);
  canvas3_6->SetFrameBorderMode(0);

  TH1F* fCPAXY__Signal_Id__16 = new TH1F("fCPAXY__Signal_Id__16", "Input variable: fCPAXY", 40, -0.2450518, 1.031126);
  fCPAXY__Signal_Id__16->SetBinContent(0, 0.003268021);
  fCPAXY__Signal_Id__16->SetBinContent(23, 0.006536042);
  fCPAXY__Signal_Id__16->SetBinContent(25, 0.006536042);
  fCPAXY__Signal_Id__16->SetBinContent(37, 0.006536042);
  fCPAXY__Signal_Id__16->SetBinContent(38, 0.02941219);
  fCPAXY__Signal_Id__16->SetBinContent(39, 2.379119);
  fCPAXY__Signal_Id__16->SetBinContent(40, 28.91545);
  fCPAXY__Signal_Id__16->SetBinError(0, 0.003268021);
  fCPAXY__Signal_Id__16->SetBinError(23, 0.004621679);
  fCPAXY__Signal_Id__16->SetBinError(25, 0.004621679);
  fCPAXY__Signal_Id__16->SetBinError(37, 0.004621679);
  fCPAXY__Signal_Id__16->SetBinError(38, 0.009804063);
  fCPAXY__Signal_Id__16->SetBinError(39, 0.08817602);
  fCPAXY__Signal_Id__16->SetBinError(40, 0.3074025);
  fCPAXY__Signal_Id__16->SetMaximum(31.80699);
  fCPAXY__Signal_Id__16->SetEntries(9592);
  fCPAXY__Signal_Id__16->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  fCPAXY__Signal_Id__16->SetLineColor(ci);
  fCPAXY__Signal_Id__16->SetLineWidth(2);
  fCPAXY__Signal_Id__16->GetXaxis()->SetTitle("fCPAXY  [units]");
  fCPAXY__Signal_Id__16->GetXaxis()->SetLabelFont(42);
  fCPAXY__Signal_Id__16->GetXaxis()->SetLabelOffset(0.012);
  fCPAXY__Signal_Id__16->GetXaxis()->SetLabelSize(0.048);
  fCPAXY__Signal_Id__16->GetXaxis()->SetTitleSize(0.054);
  fCPAXY__Signal_Id__16->GetXaxis()->SetTitleOffset(1.25);
  fCPAXY__Signal_Id__16->GetXaxis()->SetTitleFont(42);
  fCPAXY__Signal_Id__16->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.0319 units");
  fCPAXY__Signal_Id__16->GetYaxis()->SetLabelFont(42);
  fCPAXY__Signal_Id__16->GetYaxis()->SetLabelOffset(0.012);
  fCPAXY__Signal_Id__16->GetYaxis()->SetLabelSize(0.048);
  fCPAXY__Signal_Id__16->GetYaxis()->SetTitleSize(0.054);
  fCPAXY__Signal_Id__16->GetYaxis()->SetTitleOffset(1.7);
  fCPAXY__Signal_Id__16->GetYaxis()->SetTitleFont(42);
  fCPAXY__Signal_Id__16->GetZaxis()->SetLabelFont(42);
  fCPAXY__Signal_Id__16->GetZaxis()->SetTitleOffset(1);
  fCPAXY__Signal_Id__16->GetZaxis()->SetTitleFont(42);
  fCPAXY__Signal_Id__16->Draw("hist");

  TH1F* fCPAXY__Background_Id__17 = new TH1F("fCPAXY__Background_Id__17", "fCPAXY", 40, -0.2450518, 1.031126);
  fCPAXY__Background_Id__17->SetBinContent(0, 0.2067224);
  fCPAXY__Background_Id__17->SetBinContent(1, 0.004361231);
  fCPAXY__Background_Id__17->SetBinContent(2, 0.005524226);
  fCPAXY__Background_Id__17->SetBinContent(3, 0.006396473);
  fCPAXY__Background_Id__17->SetBinContent(4, 0.004942729);
  fCPAXY__Background_Id__17->SetBinContent(5, 0.00697797);
  fCPAXY__Background_Id__17->SetBinContent(6, 0.008140965);
  fCPAXY__Background_Id__17->SetBinContent(7, 0.004361231);
  fCPAXY__Background_Id__17->SetBinContent(8, 0.008722463);
  fCPAXY__Background_Id__17->SetBinContent(9, 0.009013211);
  fCPAXY__Background_Id__17->SetBinContent(10, 0.0113392);
  fCPAXY__Background_Id__17->SetBinContent(11, 0.005814975);
  fCPAXY__Background_Id__17->SetBinContent(12, 0.007559468);
  fCPAXY__Background_Id__17->SetBinContent(13, 0.007268719);
  fCPAXY__Background_Id__17->SetBinContent(14, 0.008722463);
  fCPAXY__Background_Id__17->SetBinContent(15, 0.007850217);
  fCPAXY__Background_Id__17->SetBinContent(16, 0.009885457);
  fCPAXY__Background_Id__17->SetBinContent(17, 0.01046696);
  fCPAXY__Background_Id__17->SetBinContent(18, 0.007268719);
  fCPAXY__Background_Id__17->SetBinContent(19, 0.008140965);
  fCPAXY__Background_Id__17->SetBinContent(20, 0.0119207);
  fCPAXY__Background_Id__17->SetBinContent(21, 0.01162995);
  fCPAXY__Background_Id__17->SetBinContent(22, 0.008722463);
  fCPAXY__Background_Id__17->SetBinContent(23, 0.01104845);
  fCPAXY__Background_Id__17->SetBinContent(24, 0.01744493);
  fCPAXY__Background_Id__17->SetBinContent(25, 0.0125022);
  fCPAXY__Background_Id__17->SetBinContent(26, 0.02587664);
  fCPAXY__Background_Id__17->SetBinContent(27, 0.02849338);
  fCPAXY__Background_Id__17->SetBinContent(28, 0.03140087);
  fCPAXY__Background_Id__17->SetBinContent(29, 0.03692509);
  fCPAXY__Background_Id__17->SetBinContent(30, 0.05349777);
  fCPAXY__Background_Id__17->SetBinContent(31, 0.06919821);
  fCPAXY__Background_Id__17->SetBinContent(32, 0.08780613);
  fCPAXY__Background_Id__17->SetBinContent(33, 0.1189162);
  fCPAXY__Background_Id__17->SetBinContent(34, 0.1965462);
  fCPAXY__Background_Id__17->SetBinContent(35, 0.2523699);
  fCPAXY__Background_Id__17->SetBinContent(36, 0.3709954);
  fCPAXY__Background_Id__17->SetBinContent(37, 0.6190041);
  fCPAXY__Background_Id__17->SetBinContent(38, 1.360413);
  fCPAXY__Background_Id__17->SetBinContent(39, 11.16882);
  fCPAXY__Background_Id__17->SetBinContent(40, 16.7073);
  fCPAXY__Background_Id__17->SetBinError(0, 0.007752694);
  fCPAXY__Background_Id__17->SetBinError(1, 0.001126065);
  fCPAXY__Background_Id__17->SetBinError(2, 0.001267344);
  fCPAXY__Background_Id__17->SetBinError(3, 0.001363733);
  fCPAXY__Background_Id__17->SetBinError(4, 0.001198788);
  fCPAXY__Background_Id__17->SetBinError(5, 0.001424372);
  fCPAXY__Background_Id__17->SetBinError(6, 0.001538498);
  fCPAXY__Background_Id__17->SetBinError(7, 0.001126065);
  fCPAXY__Background_Id__17->SetBinError(8, 0.001592496);
  fCPAXY__Background_Id__17->SetBinError(9, 0.001618821);
  fCPAXY__Background_Id__17->SetBinError(10, 0.001815725);
  fCPAXY__Background_Id__17->SetBinError(11, 0.001300268);
  fCPAXY__Background_Id__17->SetBinError(12, 0.001482534);
  fCPAXY__Background_Id__17->SetBinError(13, 0.001453744);
  fCPAXY__Background_Id__17->SetBinError(14, 0.001592496);
  fCPAXY__Background_Id__17->SetBinError(15, 0.001510775);
  fCPAXY__Background_Id__17->SetBinError(16, 0.001695342);
  fCPAXY__Background_Id__17->SetBinError(17, 0.001744493);
  fCPAXY__Background_Id__17->SetBinError(18, 0.001453744);
  fCPAXY__Background_Id__17->SetBinError(19, 0.001538498);
  fCPAXY__Background_Id__17->SetBinError(20, 0.0018617);
  fCPAXY__Background_Id__17->SetBinError(21, 0.001838857);
  fCPAXY__Background_Id__17->SetBinError(22, 0.001592496);
  fCPAXY__Background_Id__17->SetBinError(23, 0.001792296);
  fCPAXY__Background_Id__17->SetBinError(24, 0.00225213);
  fCPAXY__Background_Id__17->SetBinError(25, 0.001906567);
  fCPAXY__Background_Id__17->SetBinError(26, 0.002742918);
  fCPAXY__Background_Id__17->SetBinError(27, 0.002878266);
  fCPAXY__Background_Id__17->SetBinError(28, 0.00302155);
  fCPAXY__Background_Id__17->SetBinError(29, 0.003276572);
  fCPAXY__Background_Id__17->SetBinError(30, 0.003943908);
  fCPAXY__Background_Id__17->SetBinError(31, 0.004485453);
  fCPAXY__Background_Id__17->SetBinError(32, 0.005052675);
  fCPAXY__Background_Id__17->SetBinError(33, 0.00588003);
  fCPAXY__Background_Id__17->SetBinError(34, 0.007559468);
  fCPAXY__Background_Id__17->SetBinError(35, 0.008565993);
  fCPAXY__Background_Id__17->SetBinError(36, 0.01038588);
  fCPAXY__Background_Id__17->SetBinError(37, 0.01341546);
  fCPAXY__Background_Id__17->SetBinError(38, 0.01988815);
  fCPAXY__Background_Id__17->SetBinError(39, 0.05698527);
  fCPAXY__Background_Id__17->SetBinError(40, 0.06969667);
  fCPAXY__Background_Id__17->SetEntries(108514);
  fCPAXY__Background_Id__17->SetFillColor(2);
  fCPAXY__Background_Id__17->SetFillStyle(3554);
  fCPAXY__Background_Id__17->SetLineColor(2);
  fCPAXY__Background_Id__17->SetLineWidth(2);
  fCPAXY__Background_Id__17->GetXaxis()->SetTitle("fCPAXY  [units]");
  fCPAXY__Background_Id__17->GetXaxis()->SetRange(27, 41);
  fCPAXY__Background_Id__17->GetXaxis()->SetLabelFont(42);
  fCPAXY__Background_Id__17->GetXaxis()->SetTitleOffset(1);
  fCPAXY__Background_Id__17->GetXaxis()->SetTitleFont(42);
  fCPAXY__Background_Id__17->GetYaxis()->SetTitle("dN_{ }/^{ }0.0319 units");
  fCPAXY__Background_Id__17->GetYaxis()->SetLabelFont(42);
  fCPAXY__Background_Id__17->GetYaxis()->SetTitleFont(42);
  fCPAXY__Background_Id__17->GetZaxis()->SetLabelFont(42);
  fCPAXY__Background_Id__17->GetZaxis()->SetTitleOffset(1);
  fCPAXY__Background_Id__17->GetZaxis()->SetTitleFont(42);
  fCPAXY__Background_Id__17->Draw("histsame");

  TH1F* fCPAXY__Signal_Id__18 = new TH1F("fCPAXY__Signal_Id__18", "Input variable: fCPAXY", 40, -0.2450518, 1.031126);
  fCPAXY__Signal_Id__18->SetBinContent(0, 0.003268021);
  fCPAXY__Signal_Id__18->SetBinContent(23, 0.006536042);
  fCPAXY__Signal_Id__18->SetBinContent(25, 0.006536042);
  fCPAXY__Signal_Id__18->SetBinContent(37, 0.006536042);
  fCPAXY__Signal_Id__18->SetBinContent(38, 0.02941219);
  fCPAXY__Signal_Id__18->SetBinContent(39, 2.379119);
  fCPAXY__Signal_Id__18->SetBinContent(40, 28.91545);
  fCPAXY__Signal_Id__18->SetBinError(0, 0.003268021);
  fCPAXY__Signal_Id__18->SetBinError(23, 0.004621679);
  fCPAXY__Signal_Id__18->SetBinError(25, 0.004621679);
  fCPAXY__Signal_Id__18->SetBinError(37, 0.004621679);
  fCPAXY__Signal_Id__18->SetBinError(38, 0.009804063);
  fCPAXY__Signal_Id__18->SetBinError(39, 0.08817602);
  fCPAXY__Signal_Id__18->SetBinError(40, 0.3074025);
  fCPAXY__Signal_Id__18->SetMaximum(31.80699);
  fCPAXY__Signal_Id__18->SetEntries(9592);
  fCPAXY__Signal_Id__18->SetFillColor(38);

  ci = TColor::GetColor("#0000ee");
  fCPAXY__Signal_Id__18->SetLineColor(ci);
  fCPAXY__Signal_Id__18->SetLineWidth(2);
  fCPAXY__Signal_Id__18->GetXaxis()->SetTitle("fCPAXY  [units]");
  fCPAXY__Signal_Id__18->GetXaxis()->SetLabelFont(42);
  fCPAXY__Signal_Id__18->GetXaxis()->SetLabelOffset(0.012);
  fCPAXY__Signal_Id__18->GetXaxis()->SetLabelSize(0.048);
  fCPAXY__Signal_Id__18->GetXaxis()->SetTitleSize(0.054);
  fCPAXY__Signal_Id__18->GetXaxis()->SetTitleOffset(1.25);
  fCPAXY__Signal_Id__18->GetXaxis()->SetTitleFont(42);
  fCPAXY__Signal_Id__18->GetYaxis()->SetTitle("(1/N) dN_{ }/^{ }0.0319 units");
  fCPAXY__Signal_Id__18->GetYaxis()->SetLabelFont(42);
  fCPAXY__Signal_Id__18->GetYaxis()->SetLabelOffset(0.012);
  fCPAXY__Signal_Id__18->GetYaxis()->SetLabelSize(0.048);
  fCPAXY__Signal_Id__18->GetYaxis()->SetTitleSize(0.054);
  fCPAXY__Signal_Id__18->GetYaxis()->SetTitleOffset(1.7);
  fCPAXY__Signal_Id__18->GetYaxis()->SetTitleFont(42);
  fCPAXY__Signal_Id__18->GetZaxis()->SetLabelFont(42);
  fCPAXY__Signal_Id__18->GetZaxis()->SetTitleOffset(1);
  fCPAXY__Signal_Id__18->GetZaxis()->SetTitleFont(42);
  fCPAXY__Signal_Id__18->Draw("sameaxis");
  text = new TText(0.98, 0.14, "U/O-flow (S,B): (0.0, 0.7)% / (0.0, 0.0)%");
  text->SetNDC();
  text->SetTextSize(0.04);
  text->SetTextAngle(90);
  text->Draw();

  pt = new TPaveText(0.01, 0.9288942, 0.4659303, 0.995, "blNDC");
  pt->SetName("title");
  pt->SetBorderSize(1);

  ci = TColor::GetColor("#5d6b7d");
  pt->SetFillColor(ci);

  ci = TColor::GetColor("#7d8b9d");
  pt->SetLineColor(ci);
  pt->SetTextColor(0);
  pt_LaTex = pt->AddText("Input variable: fCPAXY");
  pt->Draw();
  canvas3_6->Modified();
  canvas3->cd();
  canvas3->Modified();
  canvas3->cd();
  canvas3->SetSelected(canvas3);
}