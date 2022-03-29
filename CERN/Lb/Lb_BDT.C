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

int Lb_BDT(TString myMethodList = ""){
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested
  std::map<std::string, int> Use;

  // Boosted Decision Trees
  Use["BDT"] = 1;  // uses Adaptive Boost
  Use["BDTG"] = 0; // uses Gradient Boost
  Use["BDTB"] = 0; // uses Bagging
  Use["BDTD"] = 0; // decorrelation + Adaptive Boost
  Use["BDTF"] = 0; // allow usage of fisher discriminant for node splitting
  Use["RuleFit"] = 0; // 
  // --- Neural Networks (all are feed-forward Multilayer Perceptrons)
  Use["MLP"] = 0; // Recommended ANN
  std::cout << std::endl;
  std::cout << "==> Start TMVAClassification" << std::endl;

  // Select methods (don't look at this code - not of interest)
  if (myMethodList != "") {
    for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
      it->second = 0;

    std::vector<TString> mlist = TMVA::gTools().SplitString(myMethodList, ',');
    for (UInt_t i = 0; i < mlist.size(); i++) {
      std::string regMethod(mlist[i]);

      if (Use.find(regMethod) == Use.end()) {
        std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
        for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
          std::cout << it->first << " ";
        std::cout << std::endl;
        return 1;
      }
      Use[regMethod] = 1;
    }
  }
  
  // Here the preparation phase begins
  // PtBins - settings
  const Int_t nPtBins = 12;
  Float_t ptBins[nPtBins + 1] = {0., 0.5, 1., 2., 3., 4., 5., 7., 10., 13., 16., 20., 24.};
  Float_t TrainFraction = 0.7; //fraction of training and testing. 0.7 is 70% training 30% testing

  for (Int_t i = 0; i < 12; i++) { //nPtBins //master loop over all ptbins
    TFile* inputSignal(0);
    TString fnamesig = Form("/home/mjongerh/Lb_data/LbStrictPIDcutSel_data/Trees/Lb_binned_signal_Pt%.1f.root", ptBins[i]); //Signal Input folder      /home/mjongerh/Lb_data/Trees/
    if (!gSystem->AccessPathName(fnamesig)) {
      inputSignal = TFile::Open(fnamesig); // check if file in local directory exists
    }
    if (!inputSignal) {
      std::cout << "ERROR: could not open signal file" << std::endl;
      exit(1);
    }
    std::cout << "--- TMVAClassification       : Using input signal file: " << inputSignal->GetName() << std::endl;

    TFile* inputBackground(0);
    TString fnamebkg = Form("/home/mjongerh/Lb_data/LbStrictPIDcutSel_data/Trees/Lb_binned_bkg_Pt%.1f.root", ptBins[i]); //Background Input folder
    if (!gSystem->AccessPathName(fnamebkg)) {
      inputBackground = TFile::Open(fnamebkg);
    }
    if (!inputBackground) {
      std::cout << "ERROR: could not open bkg file" << std::endl;
      exit(1);
    }
     //Second set of data files
    //TFile* inputSignal2(0);
    //TString fnamesig2 = Form("/home/mjongerh/Lb_data/LbGunPanoscutSel_data/Trees/Lb_binned_signal_Pt%.1f.root", ptBins[i]); //Signal Input folder      /home/mjongerh/Lb_data/Trees/
    //if (!gSystem->AccessPathName(fnamesig2)) {
    //  inputSignal2 = TFile::Open(fnamesig2); // check if file in local directory exists
    //}
    //if (!inputSignal2) {
    //  std::cout << "ERROR: could not open signal file" << std::endl;
    //  exit(1);
    //}
    //std::cout << "--- TMVAClassification       : Using input signal file: " << inputSignal2->GetName() << std::endl;

    //TFile* inputBackground2(0);
    //TString fnamebkg2 = Form("/home/mjongerh/Lb_data/LbGunPanoscutSel_data/Trees/Lb_binned_bkg_Pt%.1f.root", ptBins[i]); //Background Input folder
    //if (!gSystem->AccessPathName(fnamebkg2)) {
    //  inputBackground2 = TFile::Open(fnamebkg2);
    //}
    //if (!inputBackground2) {
    //  std::cout << "ERROR: could not open bkg file" << std::endl;
    //  exit(1);
    //}
    //std::cout << "--- TMVAClassification       : Using input background file: " << inputBackground2->GetName() << std::endl;

    // Register the training and test trees
    TTree* signalTree = (TTree*)inputSignal->Get("O2hfcandlbfull");
    TTree* backgroundTree = (TTree*)inputBackground->Get("O2hfcandlbfull");
    //TTree* signalTree2 = (TTree*)inputSignal2->Get("O2hfcandlbfull");
    //TTree* backgroundTree2 = (TTree*)inputBackground2->Get("O2hfcandlbfull");

    signalTree->Print();
    backgroundTree->Print();
    signalTree->AutoSave();
    backgroundTree->AutoSave();
    //signalTree2->Print();
    //backgroundTree2->Print();
    //signalTree2->AutoSave();
    //backgroundTree2->AutoSave();

    // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
    TString outfileDir = Form("/home/mjongerh/Lb_data/outputPIDTest/Pt%.1f", ptBins[i]);
    TString createdir = "mkdir -p " + outfileDir; //create directory if it doesn't exist yet
    gSystem->Exec(createdir);
    TString outfileName = outfileDir + "/TMVA.root";
    TFile* outputFile = TFile::Open(outfileName, "RECREATE");

    TMVA::Factory* factory = new TMVA::Factory("TMVAClassification", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
    TMVA::DataLoader* dataloader = new TMVA::DataLoader("dataset");

    // Define the input variables that shall be used for the MVA training
    dataloader->AddVariable("fCPA", "fCPA", "units", 'F');
    dataloader->AddVariable("fCPAXY", "fCPAXY", "units", 'F');
    dataloader->AddVariable("fChi2PCA", "fChi2PCA", "units", 'F');
    dataloader->AddVariable("fDecayLength", "fDecayLength", "units", 'F');
    dataloader->AddVariable("fDecayLengthXY", "fDecayLengthXY", "units", 'F');
    dataloader->AddVariable("fImpactParameter0", "fImpactParameter0", "units", 'F');
    dataloader->AddVariable("fImpactParameter1", "fImpactParameter1", "units", 'F');
    // Lc param
    dataloader->AddVariable("fLcM", "fLcM", "units", 'F');
    dataloader->AddVariable("fLcCt", "fLcCt", "units", 'F');
    dataloader->AddVariable("fLcY", "fLcY", "units", 'F');
    dataloader->AddVariable("fLcE", "fLcE", "units", 'F');
    dataloader->AddVariable("fLcEta", "fLcEta", "units", 'F');
    dataloader->AddVariable("fLcCPA", "fLcCPA", "units", 'F');
    dataloader->AddVariable("fLcCPAXY", "fLcCPAXY", "units", 'F');
    dataloader->AddVariable("fLcChi2PCA", "fLcChi2PCA", "units", 'F');
    dataloader->AddVariable("fLcDecayLength", "fLcDecayLength", "units", 'F');
    dataloader->AddVariable("fLcDecayLengthXY", "fLcDecayLengthXY", "units", 'F');

    // PID params
    dataloader->AddVariable("fNSigRICHPi0", "fNSigRICHPi0", "units", 'F'); //direct daughter pion
    dataloader->AddVariable("fNSigTOFPi0", "fNSigTOFPi0", "units", 'F');
    dataloader->AddVariable("fNSigRICHTrk1Pi", "fNSigRICHTrk1Pi", "units", 'F'); //granddaughter pi/p
    dataloader->AddVariable("fNSigRICHTrk1Pr", "fNSigRICHTrk1Pr", "units", 'F');
    dataloader->AddVariable("NSigRICHTrk2Ka", "NSigRICHTrk2Ka", "units", 'F'); //granddaughter Kaon
    dataloader->AddVariable("fNSigRICHTrk3Pi", "fNSigRICHTrk3Pi", "units", 'F'); //granddaughter p/Pi
    dataloader->AddVariable("fNSigRICHTrk3Pr", "fNSigRICHTrk3Pr", "units", 'F');



    //Spectator variables
    dataloader->AddSpectator("fPtProng0", "fPtProng0", "units", 'F');
    dataloader->AddSpectator("fPtProng1", "fPtProng1", "units", 'F');
    dataloader->AddSpectator("fM", "fM", "units", 'F');
    dataloader->AddSpectator("fPt", "fPt", "Gev", 'F');

    // global event weights per tree (see below for setting event-wise weights)
    Double_t signalWeight = 1.0;
    Double_t backgroundWeight = 1.0;

    // You can add an arbitrary number of signal or background trees
    if (signalTree->GetEntries() != 0) dataloader->AddSignalTree(signalTree, signalWeight);
    if (backgroundTree->GetEntries() != 0) dataloader->AddBackgroundTree(backgroundTree, backgroundWeight);
    //if (signalTree2->GetEntries() != 0) dataloader->AddSignalTree(signalTree2, signalWeight);
    //if (backgroundTree2->GetEntries() != 0) dataloader->AddBackgroundTree(backgroundTree2, backgroundWeight);

    // Apply additional cuts on the signal and background samples (can be different)
    TCut mycuts = ""; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
    TCut mycutb = ""; // for example: TCut mycutb = "abs(var1)<0.5";

    //case 1 input file
    int NsigTrain = (signalTree->GetEntries()) * TrainFraction;
    long long Nmaxbkg = 500000;
    int NbkgTrain = min(Nmaxbkg, (long long)(backgroundTree->GetEntries() * TrainFraction));
    int NsigTest = (signalTree->GetEntries()) * (1.0 - TrainFraction);
    int NbkgTest = min(Nmaxbkg, (long long)(backgroundTree->GetEntries() * (1.0 - TrainFraction)));
    
    //case 2 input files
    //int NsigTrain = (signalTree->GetEntries() + signalTree2->GetEntries()) * TrainFraction;
    //long long Nmaxbkg = 500000;
    //int NbkgTrain = min(Nmaxbkg, (long long)((backgroundTree->GetEntries() + backgroundTree2->GetEntries()) * TrainFraction));
    //int NsigTest = (signalTree->GetEntries() + signalTree2->GetEntries()) * (1.0 - TrainFraction);
    //int NbkgTest = min(Nmaxbkg, (long long)((backgroundTree->GetEntries() + backgroundTree2->GetEntries()) * (1.0 - TrainFraction)));
    dataloader->PrepareTrainingAndTestTree(mycuts, NsigTrain, NbkgTrain, NsigTest, NbkgTest, "SplitMode=Random:NormMode=NumEvents:!V");

    // Boosted Decision Trees
    if (Use["BDT"]) // Adaptive Boost
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT",
                          "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");

    if (Use["BDTG"]) // Gradient Boost
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTG",
                          "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=3");

    if (Use["BDTB"]) // Bagging
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTB",
                          "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20");

    if (Use["BDTD"]) // Decorrelation + Adaptive Boost
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTD",
                          "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate");

    if (Use["BDTF"]) // Allow Using Fisher discriminant in node splitting for (strong) linearly correlated variables
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTF",
                          "!H:!V:NTrees=50:MinNodeSize=2.5%:UseFisherCuts:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20");

    // RuleFit -- TMVA implementation of Friedman's method
    if (Use["RuleFit"])
      factory->BookMethod(dataloader, TMVA::Types::kRuleFit, "RuleFit",
                          "H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02");
    // TMVA ANN: MLP (recommended ANN) -- all ANNs in TMVA are Multilayer Perceptrons
    //if (Use["MLP"]) factory->BookMethod(TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator");

    // Now you can tell the factory to train, test, and evaluate the MVAs
    factory->TrainAllMethods();
    factory->TestAllMethods();
    factory->EvaluateAllMethods();
    outputFile->Close();    // Save the output

    std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
    std::cout << "==> TMVAClassification is done!" << std::endl;
    TString mvdataset = "mv dataset " + outfileDir + "/dataset";
    gSystem->Exec(mvdataset);
    delete factory;
    delete dataloader;
    // Launch the GUI for the root macros
    //if (!gROOT->IsBatch())
    //  TMVA::TMVAGui(outfileName);
  }
  return 0;
}

int main(int argc, char** argv)
{
  // Select methods (don't look at this code - not of interest)
  TString methodList;
  for (int i = 1; i < argc; i++) {
    TString regMethod(argv[i]);
    if (regMethod == "-b" || regMethod == "--batch")
      continue;
    if (!methodList.IsNull())
      methodList += TString(",");
    methodList += regMethod;
  }
  return Lb_BDT(methodList);
}