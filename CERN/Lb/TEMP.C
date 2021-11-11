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

void TEMP() {
  TFile oldFile("./Trees/Trees/Lb_binned_bkg_Pt5.00.root");
  TTree* oldtree;
  TString objectstring = Form("O2hfcandlbfull", i);
  oldFile.GetObject(objectstring, oldtree);
  int entries = oldtree.GetEntries();
  float chi2PCAEntry;
  oldtree->SetBranchAddress("fChi2PCA", &chi2PCAEntry);

  TCanvas* c1 = new TCanvas("c1", "Histogram Drawing Options", 200, 10, 700, 900);
  auto Histo = new TH1D("Histo", "Chi2PCA",100, 0.0, 0.0000012);
  for (int i = 0; i < entries; i++) {
    oldtree->GetEntry(i);
    Histo.Fill(chi2PCAEntry);
  }
  Histo.Draw();
  
  c1->Modified();
  c1->Update();
}