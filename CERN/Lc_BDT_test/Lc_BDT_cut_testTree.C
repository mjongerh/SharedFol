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
#include "TClass.h"

void Lc_BDT_cut_testTree()
{
  TString oldfileDir = "/home/mjongerh/Lc_data/output/";

  THStack* hs = new THStack("hs", "Stacked 1D histograms");
  //create two 1-d histograms
  TH1F* hSig = new TH1F("hSig", "Signal events", 100, 1.8, 3.);
  hSig->SetFillColor(kRed);
  hSig->SetMarkerStyle(21);
  hSig->SetMarkerColor(kRed);
  TH1F* hBkg = new TH1F("hBkg", "Bkg events", 100, 1.8, 3.);
  hBkg->SetFillColor(kBlue);
  hBkg->SetMarkerStyle(21);
  hBkg->SetMarkerColor(kBlue);

  // PtBins - settings
  const Int_t nPtBins = 7;
  Float_t ptBins[nPtBins + 1] = {0., 1., 2., 4., 6., 8., 12., 100.};
  
  for (int i = 0; i < nPtBins; i++) {
    Float_t PtLow = ptBins[i];
    Float_t PtHigh = ptBins[i + 1];

    TString oldfileName = oldfileDir + Form("Pt%.0f/TMVA.root", PtLow);
    TFile oldFile(oldfileName);
    TTree* oldtree;

    TString objectstring = "dataset/TestTree";
    oldFile.GetObject(objectstring, oldtree);
    if (oldtree == nullptr) printf("tree not found");

    Long64_t nentries = oldtree->GetEntries();
    Int_t classID;
    float fM;
    oldtree->SetBranchAddress("classID", &classID);
    oldtree->SetBranchAddress("fM", &fM);

    for (Long64_t i = 0; i < nentries; i++) {
      oldtree->GetEntry(i);
      if (classID == 0)
        hSig->Fill(fM);
      else if (classID == 1)
        hBkg->Fill(fM);
      else
        printf("error, event is not signal o r background\n");
    }
  }

  hs->Add(hSig);
  hs->Add(hBkg);
  TCanvas* cst = new TCanvas("cst", "stacked hists", 10, 10, 700, 700);
  hs->Draw();
}