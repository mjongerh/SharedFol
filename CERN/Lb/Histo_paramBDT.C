#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TClass.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

//Makes histograms of each parameter with respect to the BDT response of that event
void Histo_paramBDT()
{
  TString oldfileDir = "~/Desktop/SharedFol/CERN/Lb/outputstrictcut/";
  TString filename = oldfileDir + "Pt7.0/TMVA.root";
  TFile* oldFile = new TFile(filename);

  TCanvas* c1 = new TCanvas("c1", "A Simple Graph Example", 200, 10, 3000, 2000);
  c1->Divide(5, 5);
  c1->cd(1);

  TTree* oldtree;
  TString objectstring = "dataset/TestTree";
  oldFile->GetObject(objectstring, oldtree);
  if (oldtree == nullptr) {
    printf("tree not found");
  }
  Long64_t nentries = oldtree->GetEntries();
  float PtEntry, fM, BDT, fDecayLength, fDecayLengthXY, fImpactParameter0, fImpactParameter1, fCPA, fCPAXY, fChi2PCA;
  Int_t classID;
  oldtree->SetBranchAddress("fPt", &PtEntry);
  oldtree->SetBranchAddress("fM", &fM);
  oldtree->SetBranchAddress("BDT", &BDT);
  oldtree->SetBranchAddress("fDecayLength", &fDecayLength);
  oldtree->SetBranchAddress("fDecayLengthXY", &fDecayLengthXY);
  oldtree->SetBranchAddress("fImpactParameter0", &fImpactParameter0);
  oldtree->SetBranchAddress("fImpactParameter1", &fImpactParameter1);
  oldtree->SetBranchAddress("fCPA", &fCPA);
  oldtree->SetBranchAddress("fCPAXY", &fCPAXY);
  oldtree->SetBranchAddress("fChi2PCA", &fChi2PCA);
  oldtree->SetBranchAddress("classID", &classID);

  Float_t weight;
  Int_t Nsig, Nbkg;
  for (Int_t i = 0; i < nentries; i++) {
    oldtree->GetEntry(i);
    if (classID == 0)
      Nsig++;
    else
      Nbkg++;
  }
  weight = 1.0; //Nbkg/Nsig;

  TH2D* hMS = new TH2D("hMS", "SIGNAL M vs BDT response", 50, -0.8, 0.5, 50, 0, 40.0);
  TH2D* hMB = new TH2D("hMB", "BACKGROUND M vs BDT response", 50, -0.8, 0.5, 50, 0, 40.0);
  TH2D* hDecayLengthS = new TH2D("hDecayLengthS", "SIGNAL Decay length vs BDT response", 50, -0.8, 0.5, 50, 0, 0.03);
  TH2D* hDecayLengthB = new TH2D("hDecayLengthB", "BACKGROUND Decay length vs BDT response", 50, -0.8, 0.5, 50, 0, 0.03);
  TH2D* hDecayLengthXYS = new TH2D("hDecayLengthXYS", "SIGNAL Decay lengthXY vs BDT response", 50, -0.8, 0.5, 50, 0, 0.03);
  TH2D* hDecayLengthXYB = new TH2D("hDecayLengthXYB", "BACKGROUND Decay lengthXY vs BDT response", 50, -0.8, 0.5, 50, 0, 0.03);
  TH2D* hImpactParameter0S = new TH2D("hImpactParameter0S", "SIGNAL Impact param0 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter0B = new TH2D("hImpactParameter0B", "BACKGROUND Impact param0 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter1S = new TH2D("hImpactParameter1S", "SIGNAL Impact param1 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter1B = new TH2D("hImpactParameter1B", "BACKGROUND Impact para1 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hCPAS = new TH2D("hCPAS", "SIGNAL CPA vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.05);
  TH2D* hCPAB = new TH2D("hCPAB", "BACKGROUND CPA vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.05);
  TH2D* hCPAXYS = new TH2D("hCPAXYS", "SIGNAL CPAXY vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.1);
  TH2D* hCPAXYB = new TH2D("hCPAXYB", "BACKGROUND CPAXY vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.1);
  
  const Int_t logbins = 100;
  Double_t xmin = 1e-7;
  Double_t xmax = 1e-3;
  Double_t logxmin = TMath::Log10(xmin);
  Double_t logxmax = TMath::Log10(xmax);
  Double_t binwidth = (logxmax - logxmin) / logbins;
  Double_t xlogbins[logbins + 1];
  xlogbins[0] = xmin;
  for (Int_t i = 1; i <= logbins; i++) {
    xlogbins[i] = xmin + TMath::Power(10, logxmin + i * binwidth);
  }

  TH2D* hChi2PCAS = new TH2D("hChi2PCAS", "SIGNAL Chi2PCA vs BDT response", 50, -0.8, 0.5, logbins, xlogbins);
  TH2D* hChi2PCAB = new TH2D("hChi2PCAB", "BACKGROUND Chi2PCA vs BDT response", 50, -0.8, 0.5, logbins, xlogbins);

  for (Int_t i = 0; i < nentries; i++) {
    oldtree->GetEntry(i);
    if (classID == 0) {
      hMS->Fill(BDT, fM, weight);
      hDecayLengthS->Fill(BDT, fDecayLength, weight);
      hDecayLengthXYS->Fill(BDT, fDecayLengthXY, weight);
      hImpactParameter0S->Fill(BDT, fImpactParameter0, weight);
      hImpactParameter1S->Fill(BDT, fImpactParameter1, weight);
      hCPAS->Fill(BDT, fCPA, weight);
      hCPAXYS->Fill(BDT, fCPAXY, weight);
      hChi2PCAS->Fill(BDT, TMath::Sqrt(fChi2PCA), weight);
    } else {
      hMB->Fill(BDT, fM, weight);
      hDecayLengthB->Fill(BDT, fDecayLength);
      hDecayLengthXYB->Fill(BDT, fDecayLengthXY);
      hImpactParameter0B->Fill(BDT, fImpactParameter0);
      hImpactParameter1B->Fill(BDT, fImpactParameter1);
      hCPAB->Fill(BDT, fCPA);
      hCPAXYB->Fill(BDT, fCPAXY);
      hChi2PCAB->Fill(BDT, TMath::Sqrt(fChi2PCA));
    }
  }
  c1->cd(2);
  hDecayLengthS->Draw("colz");
  hDecayLengthS->GetXaxis()->SetTitle("BDT response");
  hDecayLengthS->GetYaxis()->SetTitle("decay length sig");
  c1->cd(3);
  hDecayLengthB->Draw("colz");
  hDecayLengthB->GetXaxis()->SetTitle("BDT response");
  hDecayLengthB->GetYaxis()->SetTitle("decay length bkg");

  c1->cd(4);
  hImpactParameter0S->Draw("colz");
  hImpactParameter0S->GetXaxis()->SetTitle("BDT response");
  hImpactParameter0S->GetYaxis()->SetTitle("Impact param0 sig");
  c1->cd(5);
  hImpactParameter0B->Draw("colz");
  hImpactParameter0B->GetXaxis()->SetTitle("BDT response");
  hImpactParameter0B->GetYaxis()->SetTitle("Impact param0 bkg");

  c1->cd(6);
  hImpactParameter1S->Draw("colz");
  hImpactParameter1S->GetXaxis()->SetTitle("BDT response");
  hImpactParameter1S->GetYaxis()->SetTitle("Impact param1 sig");
  c1->cd(7);
  hImpactParameter1B->Draw("colz");
  hImpactParameter1B->GetXaxis()->SetTitle("BDT response");
  hImpactParameter1B->GetYaxis()->SetTitle("Impact param1 bkg");

  c1->cd(8);
  hChi2PCAS->Draw("colz");
  hChi2PCAS->GetXaxis()->SetTitle("BDT response");
  hChi2PCAS->GetYaxis()->SetTitle("Chi2PCA sig [cm]");
  gPad->SetLogy();

  c1->cd(9);
  hChi2PCAB->Draw("colz");
  hChi2PCAB->GetXaxis()->SetTitle("BDT response");
  hChi2PCAB->GetYaxis()->SetTitle("Chi2PCA bkg [cm]");
  gPad->SetLogy();

  c1->cd(11);
  hCPAS->Draw("colz");
  hCPAS->GetXaxis()->SetTitle("BDT response");
  hCPAS->GetYaxis()->SetTitle("CPA sig");
  c1->cd(12);
  hCPAB->Draw("colz");
  hCPAB->GetXaxis()->SetTitle("BDT response");
  hCPAB->GetYaxis()->SetTitle("CPA bkg");

  c1->cd(13);
  hCPAXYS->Draw("colz");
  hCPAXYS->GetXaxis()->SetTitle("BDT response");
  hCPAXYS->GetYaxis()->SetTitle("CPAXY sig");
  c1->cd(14);
  hCPAXYB->Draw("colz");
  hCPAXYB->GetXaxis()->SetTitle("BDT response");
  hCPAXYB->GetYaxis()->SetTitle("CPAXY bkg");

  c1->cd(16);
  hDecayLengthXYS->Draw("colz");
  hDecayLengthXYS->GetXaxis()->SetTitle("BDT response");
  hDecayLengthXYS->GetYaxis()->SetTitle("decay lengthXY sig");
  c1->cd(17);
  hDecayLengthXYB->Draw("colz");
  hDecayLengthXYB->GetXaxis()->SetTitle("BDT response");
  hDecayLengthXYB->GetYaxis()->SetTitle("decay lengthXY bkg");

  c1->cd(18);
  hMS->Draw("colz");
  hMS->GetXaxis()->SetTitle("BDT response");
  hMS->GetYaxis()->SetTitle("Mass sig");
  c1->cd(19);
  hMB->Draw("colz");
  hMB->GetXaxis()->SetTitle("BDT response");
  hMB->GetYaxis()->SetTitle("Mass bkg");
}