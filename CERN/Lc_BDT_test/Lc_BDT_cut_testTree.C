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

void Lc_BDT_cut_testTree( Int_t input)
{
  // PtBins - settings
  const Int_t nPtBins = 7;
  Float_t ptBins[nPtBins + 1] = {0., 1., 2., 4., 6., 8., 12., 100.};

  Float_t PtLow = ptBins[input];
  Float_t PtHigh = ptBins[input + 1];

    TString oldfileDir = "~/Desktop/SharedFol/CERN/Lc_BDT_test/output/";
    TString name = Form("Pt %.0f up to %0.f", PtLow, PtHigh); //global name ; x-asix title ; y-axis title
    THStack* hs = new THStack("hs", name);
    TCanvas* cst = new TCanvas("cst", "stacked hists", 1400, 1400);
    //cst->GetXaxis()->SetTitle("Invariant mass [GeV]");
    //create two 1-d histograms
    TH1F* hSig = new TH1F("hSig", "Signal events", 100, 1.9, 2.7);
    hSig->SetFillColor(kRed);
    hSig->SetMarkerStyle(21);
    hSig->SetMarkerColor(kRed);
    TH1F* hBkg = new TH1F("hBkg", "Bkg events", 100, 1.9,2.7);
    hBkg->SetFillColor(kBlue);
    hBkg->SetMarkerStyle(21);
    hBkg->SetMarkerColor(kBlue);



    TString oldfileName = oldfileDir + Form("Pt%d/TMVA.root", input);
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
        printf("error, event is not signal or background\n");
    }
    
    hs->Add(hBkg);
    hs->Add(hSig);
    gPad->SetGrid();
    hs->Draw();
    hs->GetXaxis()->SetTitle("My X Axis Title");
    hs->GetYaxis()->SetTitle("My Y Axis Title");
    hs->GetYaxis()->SetTitleOffset(10);
    TLegend* legend = new TLegend();
    legend->AddEntry(hSig, "Signal", "f");
    legend->AddEntry(hBkg, "Background", "f");
    legend->Draw();
    gPad->Modified();
    gPad->Update(); 

}