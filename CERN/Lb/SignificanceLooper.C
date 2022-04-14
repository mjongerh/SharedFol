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

int SignificanceLooper(TString myMethodList = ""){
  //TMVA::Tools::Instance();
  gSystem->Load("libTMVAGui");
  //Input
  TString dir = "/home/maurice/Desktop/SharedFol/CERN/Lb/outputmidSel/"; //Directory of TMVA output+dataset
  TString plotdir = dir + "Plots/";                                             // Directory of TMVA output+dataset
  gSystem->Exec("mkdir -p " + plotdir);
  TString TypeMVA = "BDT";

  const Int_t nPtBins = 12;
  Float_t ptBins[nPtBins + 1] = {0., 0.5, 1., 2., 3., 4., 5., 7., 10., 13., 16., 20., 24.};
  Float_t Nsigpp[nPtBins] = {0.0, 0.0, 28616.60108, 271787.3595, 756479.2554, 153754.227, 4209037.834, 602752.96, 3168660.553, 1512760.83, 862833.2325, 338699.3472};
  Float_t Nsigpbpb[nPtBins] = {0.0, 0.0, 204.9674613, 2855.105372, 7400.133614, 11264.65547, 24420.58843, 32203.33325, 16053.27729, 7256.754035, 3875.526333, 1396.856919};
  Float_t Nbkgpp[nPtBins] = {0.0, 0.0, 1.75e9, 2.74e9, 2.48e9, 1.67e9, 2.34e9, 2.77e9, 1.34e9, 2.11e9, 2.57e9, 2.72e9};
  Float_t Nbkgpbpb[nPtBins] = {0.0, 0.0, 37720.2, 36941.7, 37946.1, 34524.6, 42202, 43846, 39439.3, 40660.54398, 41953.5, 46428.55};
  

  
  for (size_t i = 2; i < nPtBins; i++) {
    // Use macro to extract BDT results @Nev
    //$ root -l -b -q mymacro.C | tee outputfile.log
    //This cammand saves console output to a file
    TString temporary = dir + Form("Pt%.1f/", ptBins[i]) + "TMVA.root";
    TMVA::mvaeffs("dataset", temporary, Nsigpp[i], Nbkgpp[i], kTRUE, "S/sqrt(S+B)");
    //TString fname = dir + Form("Pt%.1f_pp.pdf", ptBins[i]);
    //canvas1->SaveAs(fname);
    gSystem->Exec("mv ./dataset/plots/mvaeffs.png " + plotdir + Form("mvaeffs_pp_Pt%.1f.png", ptBins[i]));

    TMVA::mvaeffs("dataset", temporary, Nsigpbpb[i], Nbkgpbpb[i], kTRUE, "S/sqrt(S+B)");
    //fname = dir + Form("Pt%.1f_pbpb.pdf", ptBins[i]);
    //canvas1->SaveAs(fname);
    gSystem->Exec("mv ./dataset/plots/mvaeffs.png " + plotdir + Form("mvaeffs_PbPb_Pt%.1f.png", ptBins[i]));

    /* example on how to save as pdf
    root -b 
    root [0] gSystem->Load("libTMVAGui");
    root [1] TMVA::mvas("dataset","TMVA.root");
    root [2] canvas1->SaveAs("canvas1.pdf"); 
    */
  }
  return 0;
}

//int main(int argc, char** argv)
//{
//  TString methodList;
//  for (int i = 1; i < argc; i++) {
//    TString regMethod(argv[i]);
//    if (regMethod == "-b" || regMethod == "--batch")
//      continue;
//    if (!methodList.IsNull())
//      methodList += TString(",");
//    methodList += regMethod;
//  }
//  Test(methodList);
//  return 0;
//}