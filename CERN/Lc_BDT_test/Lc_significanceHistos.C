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

//Makes histograms of the significance for Lc test
void Lc_significanceHistos() {
  const Int_t nbins = 10;
  Double_t edges[nbins + 1] = {0.0, 1.0, 2.0 ,3.0, 4.0 ,5.0 ,6.0, 8.0, 12.0 ,24.0 , 36.0};
  //efficiency multiplier after optimal bdt cut (drawn by hand from TMVAGUI)
  //  S 0.7182  B 0.01984
  Double_t SigeffBDT[nbins] = {0.0, 0.748, 0.7661, 0.7782, 0.7182, 0.7182, 0.7586, 0.8788, 0.8788, 0.8788};
  Double_t BkgeffBDT[nbins] = {0.0, 0.006161, 0.009599, 0.0108, 0.01984, 0.01984, 0.04362, 0.06736, 0.06736, 0.06736};


  Int_t Nevent = 38376000000;
  TFile* input_file = new TFile("./foutputLambda_c.root", "read");
  TH2F* signal = (TH2F*)input_file.Get("histosignal");
  TH2F* bkgperevent = (TH2F*)input_file.Get("hBkgPerEvent");
  TH2F* OldSignificance = (TH2F*)input_file.Get("histosignf");
  TH2F* SignfAfterBDT = OldSignificance.Clone("SignfAfterBDT");

  for (Int_t i = 1; i < nbins; i++) {
    auto Nsig = signal->GetBinContent(i+1);
    auto Nbkg = bkgperevent->GetBinContent(i+1) * Nevent;
    auto NsigBDT = Nsig * SigeffBDT[i];
    auto NbkgBDT = Nbkg * BkgeffBDT[i];
    Float_t BDTSignf = NsigBDT / (sqrt(NsigBDT + NbkgBDT));
    SignfAfterBDT->SetBincontent(i + 1, BDTSignf);
  }
  TCanvas* c1 = new TCanvas("c1", "significance comparison", 200, 10, 7000, 5000);
  OldSignificance.Draw();
  SignfAfterBDT.Draw("same");
}

// OLD half-working version, to be applied on TMVA output
//void Lc_significanceHistos()
//{
//
//  const Int_t nbins = 7;
//  Double_t edges[nbins + 1] = {0.0, 1.0, 2.0, 4.0, 6.0, 8.0, 12.0, 30.0};
//  Float_t Nbackground3S[nbins] = {0.0};
//  TCanvas* c1 = new TCanvas("c1", "A Simple Graph Example", 200, 10, 7000, 5000);
//  c1->Divide(4, 2);
//  TString oldfileDir = "~/Desktop/SharedFol/CERN/Lc_BDT_test/output/";
//
//  for (Int_t nPtBin = 0; nPtBin < nbins; nPtBin++) {
//    TString filename = oldfileDir + Form("Pt%.0f/TMVA.root", edges[nPtBin]);
//    TFile* oldFile = new TFile(filename);
//    TH1D* oldhist = (TH1D*)oldFile->Get("dataset/Method_BDT/BDT/MVA_BDT_effBvsS");
//
//    TTree* testtree;
//    TString objectstring = "dataset/TestTree";
//    oldFile->GetObject(objectstring, testtree);
//    Long64_t nentriesTest = testtree->GetEntries();
//    TTree* traintree;
//    TString objectstring2 = "dataset/TrainTree";
//    oldFile->GetObject(objectstring2, traintree);
//    Long64_t nentriesTrain = traintree->GetEntries();
//
//    Int_t classIDtest;
//    testtree->SetBranchAddress("classID", &classIDtest);
//    Int_t classIDtrain;
//    traintree->SetBranchAddress("classID", &classIDtrain);
//    Float_t fMassTest, fMassTrain;
//    testtree->SetBranchAddress("fM", &fMassTest);
//    traintree->SetBranchAddress("fM", &fMassTrain);
//
//    //get distribution of invariant mass of signal
//    TH1D* hSigMass = new TH1D("hSigMass", "hSigMass", 100, 1.9, 2.6); //TO DO: add BDT cut (maybe eta cut as well?)
//    for (Int_t i = 0; i < nentriesTest; i++) {
//      testtree->GetEntry(i);
//      if (classIDtest == 0)
//        hSigMass->Fill(fMassTest);
//    }
//    for (Int_t i = 0; i < nentriesTrain; i++) {
//      traintree->GetEntry(i);
//      if (classIDtrain == 0)
//        hSigMass->Fill(fMassTrain);
//    }
//    hSigMass->Fit("gaus", "", "", 2.25, 2.31); //Fit and get values
//    TF1* FitFunc = (TF1*)hSigMass->GetListOfFunctions()->FindObject("gaus");
//    Float_t SigMean = FitFunc->GetParameter(1);
//    Float_t SigRMS = FitFunc->GetParameter(2);
//    for (Int_t i = 0; i < nentriesTest; i++) {
//      testtree->GetEntry(i);
//      if (classIDtest == 1) {
//        if ((fMassTest > (SigMean - (3 * SigRMS))) && (fMassTest < (SigMean + (3 * SigRMS)))) {
//          Nbackground3S[nPtBin]++;
//          //printf("mean= %.2f, RMS= %.2f\nMass=%.2f\n", SigMean, SigRMS, fMassTest);
//        }
//      }
//    }
//    for (Int_t i = 0; i < nentriesTrain; i++) {
//      traintree->GetEntry(i);
//      if (classIDtrain == 1) {
//        if ((fMassTrain > (SigMean - (3 * SigRMS))) && (fMassTrain < (SigMean + (3 * SigRMS)))) {
//          Nbackground3S[nPtBin]++;
//        }
//      }
//    }
//    c1->cd(nPtBin + 1);
//    hSigMass->Draw();
//    printf("Nentries=%d+%d\n", nentriesTest, nentriesTrain);
//  }
//  c1->cd(8);
//  gPad->SetLogy();
//  TH1F* NbackgroundEvents = new TH1F("NbackgroundEvents", "NbackgroundEvents", nbins, edges);
//  NbackgroundEvents->SetMinimum(0.0000001);
//  NbackgroundEvents->SetMaximum(0.01);
//  for (Int_t i = 0; i < nbins; i++) {
//    NbackgroundEvents->Fill(edges[i] + 0.001, Nbackground3S[i] / 30000000); //correct for Nevents
//  }
//  //NbackgroundEvents->GetYAxis().SetTitle("bkgevents / Nevents")
//  NbackgroundEvents->Draw("hist");
//
//  //TO DO: calculate signal yield
////Signal = deltaPt * delta y * BR * N expected events * (A * e) * <Taa> * d sigma/dPt ^FONLL * f(c->Hc) * F(c/lambdac) * Raa
//  Float_t SignalYieldPt[nbins] = {0.0};
//  Float_t AcceptEff[nbins] = {0.0};
//  Float_t dSigmadPt[nbins] = {1.9088 * pow(10.0, 8.0), 6.4600 * pow(10.0, 8.0), 5.0024 * pow(10.0, 8.0), 1.7522 * pow(10.0, 8.0), 5.9160 * pow(10.0, 7.0), 1.6154 * pow(10.0, 7.0), 6.9526 * pow(10.0, 5.0)};
//  Float_t fctoHc = 20.4; //+-1.3(stat) +1.6-2.2(syst)
//  Float_t BranchRatio = 0.0628; //
//  Float_t BranchRatio = 0.0628; //
//  Float_t SignalYieldPt[nbins] = {0.0};
//
//}