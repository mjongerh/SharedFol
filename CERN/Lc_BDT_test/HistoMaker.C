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

void HistoMaker() {
  TString oldfileDir = "~/Desktop/SharedFol/CERN/Lc_BDT_test/output/";
  TString filename = oldfileDir + "Pt1/TMVA.root";
  TFile* oldFile = new TFile(filename);
  TH1D* oldhist = (TH1D*)oldFile->Get("dataset/Method_BDT/BDT/MVA_BDT_effBvsS");


  Double_t x[101], y[101]; //x: false positive (background eff), y: True positive (signal eff)
  Int_t n = 100;
  for (Int_t i = 0; i < n; i++) {
    x[i] = oldhist->GetBinContent(i+1);
    y[i] = oldhist->GetBinCenter(i+1);
  }
  x[100] = 1.0;
  y[100] = 1.0;
  TCanvas* c1 = new TCanvas("c1", "A Simple Graph Example", 200, 10, 5000, 3000);
  c1->Divide(5, 3);
  c1->cd(1);
  TGraph* gr = new TGraph(n+1, x, y);
  gr->GetXaxis()->SetTitle("False positive rate (bkg eff.)");
  gr->GetYaxis()->SetTitle("True positive rate (signal eff.)");
  gr->Draw("AL");

  TTree* oldtree;
  TString objectstring = "dataset/TestTree";
  oldFile->GetObject(objectstring, oldtree);
  if (oldtree == nullptr) {
      printf("tree not found");
  }
  Long64_t nentries = oldtree->GetEntries();
  float PtEntry, BDT, fDecayLength, fImpactParameter0, fImpactParameter1, fImpactParameter2, fCPA, fCPAXY, fNSigTOFPi2, fNSigTOFKa1, fNSigTOFPr0;
  Int_t classID;
  oldtree->SetBranchAddress("fPt", &PtEntry);
  oldtree->SetBranchAddress("BDT", &BDT);
  oldtree->SetBranchAddress("fDecayLength", &fDecayLength);
  oldtree->SetBranchAddress("fImpactParameter0", &fImpactParameter0);
  oldtree->SetBranchAddress("fImpactParameter1", &fImpactParameter1);
  oldtree->SetBranchAddress("fImpactParameter2", &fImpactParameter2);
  oldtree->SetBranchAddress("fCPA", &fCPA);
  oldtree->SetBranchAddress("fCPAXY", &fCPAXY);
  oldtree->SetBranchAddress("classID", &classID);
  oldtree->SetBranchAddress("fNSigTOFPi2", &fNSigTOFPi2);
  oldtree->SetBranchAddress("fNSigTOFKa1", &fNSigTOFKa1);
  oldtree->SetBranchAddress("fNSigTOFPr0", &fNSigTOFPr0);
  
  
  Float_t weight;
  Int_t Nsig, Nbkg;
  for (Int_t i = 0; i < nentries; i++) {
    oldtree->GetEntry(i);
    if (classID == 0)
      Nsig++;  
    else Nbkg++;
  }
  weight = Nbkg / Nsig;

  TH2D* hDecayLengthS = new TH2D("hDecayLengthS", "Decay length vs BDT response", 10, 1.0, 0.0, 10, 1.0, 0.0); // 50, -0.8, 0.5, 50, 0, 30);
  TH2D* hDecayLengthB = new TH2D("hDecayLengthB", "Decay length vs BDT response", 50, -0.8, 0.5, 50, 0, 30);
  TH2D* hImpactParameter0S = new TH2D("hImpactParameter0S", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hImpactParameter0B = new TH2D("hImpactParameter0B", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hImpactParameter1S = new TH2D("hImpactParameter1S", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hImpactParameter1B = new TH2D("hImpactParameter1B", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hImpactParameter2S = new TH2D("hImpactParameter2S", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hImpactParameter2B = new TH2D("hImpactParameter2B", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hCPAS = new TH2D("hCPAS", "Decay length vs BDT response", 50, -0.8, 0.5, 50, 0.8, 1.0);
  TH2D* hCPAB = new TH2D("hCPAB", "Decay length vs BDT response", 50, -0.8, 0.5, 50, 0.8, 1.0);
  TH2D* hCPAXYS = new TH2D("hCPAXYS", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hCPAXYB = new TH2D("hCPAXYB", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.0);
  TH2D* hNSigTOFPi2S = new TH2D("hNSigTOFPi2S", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -40.0, 80.0);
  TH2D* hNSigTOFPi2B = new TH2D("hNSigTOFPi2B", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -40.0, 80.0);
  TH2D* hNSigTOFKa1S = new TH2D("hNSigTOFKa1B", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -40.0, 80.0);
  TH2D* hNSigTOFKa1B = new TH2D("hNSigTOFKa1B", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -40.0, 80.0);
  TH2D* hNSigTOFPr0S = new TH2D("hNSigTOFPr0S", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -80.0, 20.0);
  TH2D* hNSigTOFPr0B = new TH2D("hNSigTOFPr0B", "Decay length vs BDT response", 50, -0.8, 0.5, 50, -80.0, 20.0);

    for (Int_t i = 0; i < nentries; i++) {
        oldtree->GetEntry(i);
      if (classID == 0) {
        hDecayLengthS->Fill(BDT, fDecayLength, weight);
        hImpactParameter0S->Fill(BDT, fImpactParameter0, weight);
        hImpactParameter1S->Fill(BDT, fImpactParameter1, weight);
        hImpactParameter2S->Fill(BDT, fImpactParameter2, weight);
        hCPAS->Fill(BDT, fCPA, weight);
        hCPAXYS->Fill(BDT, fCPAXY, weight);
        hNSigTOFPi2S->Fill(BDT, fNSigTOFPi2, weight);
        hNSigTOFKa1S->Fill(BDT, fNSigTOFKa1, weight);
        hNSigTOFPr0S->Fill(BDT, fNSigTOFPr0, weight);
      }
        else {
        hDecayLengthB->Fill(BDT, fDecayLength);
        hImpactParameter0B->Fill(BDT, fImpactParameter0);
        hImpactParameter1B->Fill(BDT, fImpactParameter1);
        hImpactParameter2B->Fill(BDT, fImpactParameter2);
        hCPAB->Fill(BDT, fCPA);
        hCPAXYB->Fill(BDT, fCPAXY);
        hNSigTOFPi2B->Fill(BDT, fNSigTOFPi2);
        hNSigTOFKa1B->Fill(BDT, fNSigTOFKa1);
        hNSigTOFPr0B->Fill(BDT, fNSigTOFPr0);
        }
    }
    c1->cd(2);
    //gStyle->SetPalette(30);
    hDecayLengthS->Draw("colz");
    //gStyle->SetPalette(20);
    //hDecayLengthB->Draw("colSAME");

}