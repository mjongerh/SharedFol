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

void Test() {
    TCanvas* c = new TCanvas("c", "Graph2D example", 0, 0, 600, 400);
    Double_t x, y, z;
    Int_t np = 100;
    TGraph2D* dt = new TGraph2D();
    dt->SetTitle("Graph title; X axis title; Y axis title; Z axis title");
    for (Int_t N = 0; N < np; N++) {
      x = N % 10 ;
      y = (int)(N / 10);
      z = 2*x;
      dt->SetPoint(N, x, y, z);
    }
    
    
    TGraph2D* dt2 = new TGraph2D();
    dt2->SetTitle("Graph title; X axis title; Y axis title; Z axis title");
    for (Int_t N = 0; N < np; N++) {
      x = N % 10 ;
      y = (int)(N / 10);
      z = -2*x+10;
      dt2->SetPoint(N, x, y, z);
    }


    gStyle->SetPalette(1);
    dt->Draw("surf1");
    dt2->Draw("surf2");
    return c;
}