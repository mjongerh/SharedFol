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
void HistoMaker() {
  TString oldfileDir = "~/Desktop/SharedFol/CERN/Lc_BDT_test/output/";
  TString filename = oldfileDir + "Pt2/TMVA.root";
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
  TCanvas* c1 = new TCanvas("c1", "A Simple Graph Example", 200, 10, 7000, 5000);
  c1->Divide(4, 4);
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
  weight = 1.0; //Nbkg/Nsig;

  TH2D* hDecayLengthS = new TH2D("hDecayLengthS", "SIGNAL Decay length vs BDT response", 50, -0.8, 0.5, 50, 0, 0.03);
  TH2D* hDecayLengthB = new TH2D("hDecayLengthB", "BACKGROUND Decay length vs BDT response", 50, -0.8, 0.5, 50, 0, 0.03);
  TH2D* hImpactParameter0S = new TH2D("hImpactParameter0S", "SIGNAL Impact param0 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter0B = new TH2D("hImpactParameter0B", "BACKGROUND Impact param0 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter1S = new TH2D("hImpactParameter1S", "SIGNAL Impact param1 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter1B = new TH2D("hImpactParameter1B", "BACKGROUND Impact para1 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter2S = new TH2D("hImpactParameter2S", "SIGNAL Impact param2 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hImpactParameter2B = new TH2D("hImpactParameter2B", "BACKGROUND Impact param2 vs BDT response", 50, -0.8, 0.5, 50, -0.1, 0.1);
  TH2D* hCPAS = new TH2D("hCPAS", "SIGNAL CPA vs BDT response", 50, -0.8, 0.5, 50, 0.7, 1.05);
  TH2D* hCPAB = new TH2D("hCPAB", "BACKGROUND CPA vs BDT response", 50, -0.8, 0.5, 50, 0.7, 1.05);
  TH2D* hCPAXYS = new TH2D("hCPAXYS", "SIGNAL CPAXY vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.1);
  TH2D* hCPAXYB = new TH2D("hCPAXYB", "BACKGROUND CPAXY vs BDT response", 50, -0.8, 0.5, 50, -1.0, 1.1);
  TH2D* hNSigTOFPi2S = new TH2D("hNSigTOFPi2S", "SIGNAL NSigTOF Pi vs BDT response", 50, -0.8, 0.5, 50, -5.0, 5.0);
  TH2D* hNSigTOFPi2B = new TH2D("hNSigTOFPi2B", "BACKGROUND NSigTOF Pi vs BDT response", 50, -0.8, 0.5, 50, -5.0, 5.0);
  TH2D* hNSigTOFKa1S = new TH2D("hNSigTOFKa1B", "SIGNAL NSigTOF Ka vs BDT response", 50, -0.8, 0.5, 50, -20.0, 5.0);
  TH2D* hNSigTOFKa1B = new TH2D("hNSigTOFKa1B", "BACKGROUND NSigTOF Ka vs BDT response", 50, -0.8, 0.5, 50, -20.0, 5.0);
  TH2D* hNSigTOFPr0S = new TH2D("hNSigTOFPr0S", "SIGNAL NSigTOF Pr vs BDT response", 50, -0.8, 0.5, 50, -80.0, 20.0);
  TH2D* hNSigTOFPr0B = new TH2D("hNSigTOFPr0B", "BACKGROUND NSigTOF Pr vs BDT response", 50, -0.8, 0.5, 50, -80.0, 20.0);

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
    hDecayLengthS->Draw("colz");
    hDecayLengthS->GetXaxis()->SetTitle("BDT response");
    hDecayLengthS->GetYaxis()->SetTitle("decay length");
    c1->cd(3);
    hDecayLengthB->Draw("colz");
    hDecayLengthB->GetXaxis()->SetTitle("BDT response");
    hDecayLengthB->GetYaxis()->SetTitle("decay length");

    c1->cd(4);
    hImpactParameter0S->Draw("colz");
    hImpactParameter0S->GetXaxis()->SetTitle("BDT response");
    hImpactParameter0S->GetYaxis()->SetTitle("Impact param0");
    c1->cd(5);
    hImpactParameter0B->Draw("colz");
    hImpactParameter0B->GetXaxis()->SetTitle("BDT response");
    hImpactParameter0B->GetYaxis()->SetTitle("Impact param0");

    c1->cd(6);
    hImpactParameter1S->Draw("colz");
    hImpactParameter1S->GetXaxis()->SetTitle("BDT response");
    hImpactParameter1S->GetYaxis()->SetTitle("Impact param1");
    c1->cd(7);
    hImpactParameter1B->Draw("colz");
    hImpactParameter1B->GetXaxis()->SetTitle("BDT response");
    hImpactParameter1B->GetYaxis()->SetTitle("Impact param1");

    c1->cd(8);
    hImpactParameter2S->Draw("colz");
    hImpactParameter2S->GetXaxis()->SetTitle("BDT response");
    hImpactParameter2S->GetYaxis()->SetTitle("Impact param2");
    c1->cd(9);
    hImpactParameter2B->Draw("colz");
    hImpactParameter2B->GetXaxis()->SetTitle("BDT response");
    hImpactParameter2B->GetYaxis()->SetTitle("Impact param2");

    c1->cd(11);
    hCPAS->Draw("colz");
    hCPAS->GetXaxis()->SetTitle("BDT response");
    hCPAS->GetYaxis()->SetTitle("CPA");
    c1->cd(12);
    hCPAB->Draw("colz");
    hCPAB->GetXaxis()->SetTitle("BDT response");
    hCPAB->GetYaxis()->SetTitle("CPA");

    c1->cd(13);
    hCPAXYS->Draw("colz");
    hCPAXYS->GetXaxis()->SetTitle("BDT response");
    hCPAXYS->GetYaxis()->SetTitle("CPAXY");
    c1->cd(14);
    hCPAXYB->Draw("colz");
    hCPAXYB->GetXaxis()->SetTitle("BDT response");
    hCPAXYB->GetYaxis()->SetTitle("CPAXY");


    TCanvas* c2 = new TCanvas("c2", "A Simple Graph Example", 200, 10, 7000, 5000);
    c2->Divide(2, 3);
    c2->cd(1);
    hNSigTOFPi2S->Draw("colz");
    hNSigTOFPi2S->GetXaxis()->SetTitle("BDT response");
    hNSigTOFPi2S->GetYaxis()->SetTitle("NSig TOF Pi");
    c2->cd(2);
    hNSigTOFPi2B->Draw("colz");
    hNSigTOFPi2B->GetXaxis()->SetTitle("BDT response");
    hNSigTOFPi2B->GetYaxis()->SetTitle("NSig TOF Pi");

    c2->cd(3);
    hNSigTOFKa1S->Draw("colz");
    hNSigTOFKa1S->GetXaxis()->SetTitle("BDT response");
    hNSigTOFKa1S->GetYaxis()->SetTitle("NSig TOF Ka");
    c2->cd(4);
    hNSigTOFKa1B->Draw("colz");
    hNSigTOFKa1B->GetXaxis()->SetTitle("BDT response");
    hNSigTOFKa1B->GetYaxis()->SetTitle("NSig TOF Ka");

    c2->cd(5);
    hNSigTOFPr0S->Draw("colz");
    hNSigTOFPr0S->GetXaxis()->SetTitle("BDT response");
    hNSigTOFPr0S->GetYaxis()->SetTitle("NSig TOF Pr");
    c2->cd(6);
    hNSigTOFPr0B->Draw("colz");
    hNSigTOFPr0B->GetXaxis()->SetTitle("BDT response");
    hNSigTOFPr0B->GetYaxis()->SetTitle("NSig TOF Pr");
}