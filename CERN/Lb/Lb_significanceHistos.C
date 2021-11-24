#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <math.h>

#include "TClass.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TLatex.h"

//Makes histograms of the significance for Lb test
void Lb_significanceHistos() {
  const Int_t nbins = 11;
  Double_t edges[nbins + 1] = {0., 1., 2., 3., 4., 5., 7., 10., 13., 16., 20., 24.};
  Double_t BDTSignf[nbins] = {0.0, 0.0, 0.0, 0.828, 6.532, 15.0891, 54.7563, 67.9376, 45.325, 31.4128, 30.2179};

  long Nevent = 210000000000000;
  TH1F* SignfAfterBDT = new TH1F("SignfAfterBDT", "Significance after BDT cut. NO traditional cuts", nbins, edges);
  for (Int_t i = 0; i < nbins; i++) {
    SignfAfterBDT->SetBinContent(i+1, BDTSignf[i]);
  }
  TCanvas* c1 = new TCanvas("c1", "significance", 200, 10, 1000, 1000);
  SignfAfterBDT->GetYaxis()->SetTitleOffset(1.28);
  SignfAfterBDT->GetYaxis()->SetTitle("significance S/sqrt(S+B)");
  gPad->SetLogy();
  SignfAfterBDT->SetLineColor(kBlue);
  SignfAfterBDT->SetTitle("Significance after BDT cut");
  SignfAfterBDT->Draw();

  auto t_b = TLatex();
  t_b.SetNDC();
  t_b.SetTextFont(42);
  t_b.SetTextColor(1);
  t_b.SetTextSize(0.04);
  t_b.SetTextAlign(12);
  t_b.DrawLatex(0.3, 0.53, "#Lambda_{b}^{0} #rightarrow #Lambda_{c}^{+} #pi^{-} #rightarrow p K^{-} #pi^{+} #pi^{-}");

  auto t_a = TLatex();
  t_a.SetNDC();
  t_a.SetTextFont(42);
  t_a.SetTextColor(1);
  t_a.SetTextSize(0.03);
  t_a.SetTextAlign(12);
  t_a.DrawLatex(0.24, 0.44, "N_{ev} = 210 * 10^{12}, PP #sqrt{s}=14.0TeV, |y| <1.44, BR=0.03%");
  
  auto t_c = TLatex();
  t_c.SetNDC();
  t_c.SetTextFont(42);
  t_c.SetTextColor(1);
  t_c.SetTextSize(0.03);
  t_c.SetTextAlign(12);
  t_c.DrawLatex(0.24, 0.44, "No cuts on any parameter other than BDT response");
}
