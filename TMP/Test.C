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

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

int Test() {
  TMVA::Tools::Instance();
  //Input
  TString dir = "/home/maurice/Desktop/SharedFol/CERN/Lb/outputmidSel/Pt4.0/"; //Directory of TMVA output+dataset
  TString prefix = "dataset/weights/TMVAClassification"; //prefix for weights file
  TString TypeMVA = "BDT";
  TString fname = "/home/maurice/Desktop/SharedFol/CERN/Lb/LbmidcutSel_data/Trees/Lb_binned_bkg_Pt4.0.root"; //filename of test tree
  TString treename = "O2hfcandlbfull"; //name of tree inside the file

  TFile* input(0);
  //TString fpath = dir + fname;
  if (!gSystem->AccessPathName(fname)) {
    input = TFile::Open(fname); // check if file exists
  } else {
    std::cout << "File can not be found" << std::endl;
    exit(1);
  }
  std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;
  TMVA::Reader* reader = new TMVA::Reader("!Color:!Silent");

  //Add all parameters that were used, same name, same data type
  Float_t fCPA, fCPAXY, fChi2PCA, fDecayLength, fDecayLengthXY, fImpactParameter0, fImpactParameter1;
  reader->AddVariable("fCPA", &fCPA);
  reader->AddVariable("fCPAXY", &fCPAXY);
  reader->AddVariable("fChi2PCA", &fChi2PCA);
  reader->AddVariable("fDecayLength", &fDecayLength);
  reader->AddVariable("fDecayLengthXY", &fDecayLengthXY);
  reader->AddVariable("fImpactParameter0", &fImpactParameter0);
  reader->AddVariable("fImpactParameter1", &fImpactParameter1);

  //Same for spectators
  Float_t fPtProng0, fPtProng1, fM, fPt;
  reader->AddSpectator("fPtProng0", &fPtProng0);
  reader->AddSpectator("fPtProng1", &fPtProng0);
  reader->AddSpectator("fM", &fM);
  reader->AddSpectator("fPt", &fPt);

  // Book method in the reader
  TString weightfile = dir + prefix + "_" + TypeMVA + ".weights.xml";
  reader->BookMVA("BDT", weightfile);

  TH1F *histBdt = new TH1F("MVA_BDT", "MVA_BDT", 100, -0.8, 0.8);

  TTree* theTree = (TTree*)input->Get(treename);
  theTree->SetBranchAddress("fCPA", &fCPA);
  theTree->SetBranchAddress("fCPAXY", &fCPAXY);
  theTree->SetBranchAddress("fChi2PCA", &fChi2PCA);
  theTree->SetBranchAddress("fDecayLength", &fDecayLength);
  theTree->SetBranchAddress("fDecayLengthXY", &fDecayLengthXY);
  theTree->SetBranchAddress("fImpactParameter0", &fImpactParameter0);
  theTree->SetBranchAddress("fImpactParameter1", &fImpactParameter1);

  std::vector<Float_t> vecVar(4); // vector for EvaluateMVA tests
  std::cout << "--- Processing: " << theTree->GetEntries() << " events" << std::endl;

  for (Long64_t ievt = 0; ievt < theTree->GetEntries(); ievt++) {
    if (ievt % 10000 == 0)
      std::cout << "--- ... Processing event: " << ievt << std::endl;

    theTree->GetEntry(ievt);
    // Return the MVA outputs and fill into histograms
      histBdt->Fill(reader->EvaluateMVA("BDT"));
  }
  TFile* target = new TFile("TMVAtest.root", "RECREATE");
  histBdt->Write();
  std::cout << "--- Created root file: \"TMVAtest.root\" containing the MVA output histograms" << std::endl;
  delete reader;
  std::cout << "==> TMVAClassificationApplication is done!" << std::endl;
  return 0;
}