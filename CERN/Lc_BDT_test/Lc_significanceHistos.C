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

//Makes histograms of the significance for Lc test
void Lc_significanceHistos(){

  const Int_t nbins = 7;
  Double_t edges[nbins + 1] = {0.0, 1.0, 2.0, 4.0, 6.0, 8.0, 12.0, 30.0};
  Int_t Nbackground3S[nbins] = {0};
  TCanvas* c1 = new TCanvas("c1", "A Simple Graph Example", 200, 10, 7000, 5000);
  c1->Divide(4, 2);
  TString oldfileDir = "~/Desktop/SharedFol/CERN/Lc_BDT_test/output/";

  for (Int_t nPtBin = 0; nPtBin < nbins; nPtBin++) {
    TString filename = oldfileDir + Form("Pt%.0f/TMVA.root", edges[nPtBin]);
    TFile* oldFile = new TFile(filename);
    TH1D* oldhist = (TH1D*)oldFile->Get("dataset/Method_BDT/BDT/MVA_BDT_effBvsS");

    TTree* testtree;
    TString objectstring = "dataset/TestTree";
    oldFile->GetObject(objectstring, testtree);
    Long64_t nentriesTest = testtree->GetEntries();
    TTree* traintree;
    TString objectstring2 = "dataset/TrainTree";
    oldFile->GetObject(objectstring2, traintree);
    Long64_t nentriesTrain = traintree->GetEntries();

    Int_t classIDtest;
    testtree->SetBranchAddress("classID", &classIDtest);
    Int_t classIDtrain;
    traintree->SetBranchAddress("classID", &classIDtrain);
    Float_t fMassTest, fMassTrain;
    testtree->SetBranchAddress("fM", &fMassTest);
    traintree->SetBranchAddress("fM", &fMassTrain);

    //get distribution of invariant mass of signal
    TH1D* hSigMass = new TH1D("hSigMass", "hSigMass", 100, 1.9, 2.6);
    for (Int_t i = 0; i < nentriesTest; i++) {
      testtree->GetEntry(i);
      if (classIDtest == 0) hSigMass->Fill(fMassTest);
    }
    for (Int_t i = 0; i < nentriesTrain; i++) {
      traintree->GetEntry(i);
      if (classIDtrain == 0) hSigMass->Fill(fMassTrain);
    }
    Float_t SigMean = hSigMass->GetMean();
    Float_t SigRMS = hSigMass->GetRMS();

    for (Int_t i = 0; i < nentriesTest; i++) {
      testtree->GetEntry(i);
      if (classIDtest == 1)
        if (fMassTest >= SigMean - 3 * SigRMS && fMassTest < SigMean + 3 * SigRMS)
          Nbackground3S[nPtBin]++;
    }
    for (Int_t i = 0; i < nentriesTrain; i++) {
      traintree->GetEntry(i);
      if (classIDtrain == 1)
        if (fMassTrain >= SigMean - 3 * SigRMS && fMassTrain < SigMean + 3 * SigRMS)
          Nbackground3S[nPtBin]++;
    }
    c1->cd(nPtBin+1);
    hSigMass->Draw();
  }

  TH1D* NbackgroundEvents = new TH1D("NbackgroundEvents", "NbackgroundEvents", nbins, edges);
  for (Int_t i = 0; i < nbins; i++) {
    NbackgroundEvents->Fill(edges[i] + 0.001, Nbackground3S[i]);
  }
  c1->cd(8);
  NbackgroundEvents->Draw("hist");
}