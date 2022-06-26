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

int TEMP(TString myMethodList = "")
{
  TMVA::Tools::Instance();

  // Default MVA methods to be trained + tested
  std::map<std::string, int> Use;

  // Boosted Decision Trees
  Use["BDT"] = 1;     // uses Adaptive Boost
  Use["BDTG"] = 1;    // uses Gradient Boost
  Use["BDTB"] = 0;    // uses Bagging
  Use["BDTD"] = 0;    // decorrelation + Adaptive Boost
  Use["BDTF"] = 1;    // allow usage of fisher discriminant for node splitting
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
  Float_t TrainFraction = 0.7; // fraction of training and testing. 0.7 is 70% training 30% testing

  for (Int_t i = 0; i < 12; i++) { // nPtBins //master loop over all ptbins
    TFile* inputSignal(0);
    TString fnamesig = Form("/home/maurice/Desktop/SharedFol/CERN/Lb/LbTrees_50M/Lb_binned_signal_Pt%.1f.root", ptBins[i]); // Signal Input folder      /home/mjongerh/Lb_data/Trees/
    if (!gSystem->AccessPathName(fnamesig)) {
      inputSignal = TFile::Open(fnamesig); // check if file in local directory exists
    }
    if (!inputSignal) {
      std::cout << "ERROR: could not open signal file" << std::endl;
      exit(1);
    }
    std::cout << "--- TMVAClassification       : Using input signal file: " << inputSignal->GetName() << std::endl;

    TFile* inputBackground(0);
    TString fnamebkg = Form("/home/maurice/Desktop/SharedFol/CERN/Lb/LbTrees_50M/Lb_binned_bkg_Pt%.1f.root", ptBins[i]); // Background Input folder
    if (!gSystem->AccessPathName(fnamebkg)) {
      inputBackground = TFile::Open(fnamebkg);
    }
    if (!inputBackground) {
      std::cout << "ERROR: could not open bkg file" << std::endl;
      exit(1);
    }
    // Second set of data files
    TFile* inputSignal2(0);
    TString fnamesig2 = Form("/home/maurice/Desktop/SharedFol/CERN/Lb/LbStrictCutSelPID_data/LbStrictPIDcutSel_data/Trees/Lb_binned_signal_Pt%.1f.root", ptBins[i]); // Signal Input folder      /home/mjongerh/Lb_data/Trees/
    if (!gSystem->AccessPathName(fnamesig2)) {
      inputSignal2 = TFile::Open(fnamesig2); // check if file in local directory exists
    }
    if (!inputSignal2) {
      std::cout << "ERROR: could not open signal file" << std::endl;
      exit(1);
    }
    std::cout << "--- TMVAClassification       : Using input signal file: " << inputSignal2->GetName() << std::endl;

    TFile* inputBackground2(0);
    TString fnamebkg2 = Form("/home/maurice/Desktop/SharedFol/CERN/Lb/LbStrictCutSelPID_data/LbStrictPIDcutSel_data/Trees/Lb_binned_bkg_Pt%.1f.root", ptBins[i]); // Background Input folder
    if (!gSystem->AccessPathName(fnamebkg2)) {
      inputBackground2 = TFile::Open(fnamebkg2);
    }
    if (!inputBackground2) {
      std::cout << "ERROR: could not open bkg file" << std::endl;
      exit(1);
    }
    std::cout << "--- TMVAClassification       : Using input background file: " << inputBackground2->GetName() << std::endl;

    // Register the training and test trees
    TTree* signalTree = (TTree*)inputSignal->Get("O2hfcandlbfull");
    TTree* backgroundTree = (TTree*)inputBackground->Get("O2hfcandlbfull");
    TTree* signalTree2 = (TTree*)inputSignal2->Get("O2hfcandlbfull");
    TTree* backgroundTree2 = (TTree*)inputBackground2->Get("O2hfcandlbfull");

    signalTree->Print();
    backgroundTree->Print();
    signalTree->AutoSave();
    backgroundTree->AutoSave();
    signalTree2->Print();
    backgroundTree2->Print();
    signalTree2->AutoSave();
    backgroundTree2->AutoSave();

    // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
    TString outfileDir = Form("~/Desktop/SharedFol/CERN/Lb/outputSimpel/Pt%.1f", ptBins[i]);
    TString createdir = "mkdir -p " + outfileDir; // create directory if it doesn't exist yet
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
    //dataloader->AddVariable("fLcM", "fLcM", "units", 'F');
    //// dataloader->AddVariable("fLcCt", "fLcCt", "units", 'F');
    //// dataloader->AddVariable("fLcY", "fLcY", "units", 'F');
    //// dataloader->AddVariable("fLcE", "fLcE", "units", 'F');
    //// dataloader->AddVariable("fLcEta", "fLcEta", "units", 'F');
    //dataloader->AddVariable("fLcCPA", "fLcCPA", "units", 'F');
    //dataloader->AddVariable("fLcCPAXY", "fLcCPAXY", "units", 'F');
    //dataloader->AddVariable("fLcChi2PCA", "fLcChi2PCA", "units", 'F');
    //dataloader->AddVariable("fLcDecayLength", "fLcDecayLength", "units", 'F');
    //dataloader->AddVariable("fLcDecayLengthXY", "fLcDecayLengthXY", "units", 'F');
    //dataloader->AddVariable("fLcImpactParameter0", "fLcImpactParameter0", "units", 'F');
    //dataloader->AddVariable("fLcImpactParameter1", "fLcImpactParameter1", "units", 'F');
    //dataloader->AddVariable("fLcImpactParameter2", "fLcImpactParameter2", "units", 'F');

    // PID params
    // dataloader->AddVariable("fNSigRICHPi0", "fNSigRICHPi0", "units", 'F'); //direct daughter pion
    //dataloader->AddVariable("fNSigTOFPi0", "fNSigTOFPi0", "units", 'F');
    // dataloader->AddVariable("fNSigRICHTrk1Pi", "fNSigRICHTrk1Pi", "units", 'F'); //granddaughter pi/p
    // dataloader->AddVariable("fNSigRICHTrk1Pr", "fNSigRICHTrk1Pr", "units", 'F');
    // dataloader->AddVariable("fNSigRICHTrk2Ka", "fNSigRICHTrk2Ka", "units", 'F'); //granddaughter Kaon
    // dataloader->AddVariable("fNSigRICHTrk3Pi", "fNSigRICHTrk3Pi", "units", 'F'); //granddaughter p/Pi
    // dataloader->AddVariable("fNSigRICHTrk3Pr", "fNSigRICHTrk3Pr", "units", 'F');

    //dataloader->AddVariable("fNSigTOFTrk1Pr", "fNSigTOFTrk1Pr", "units", 'F'); // grandaughters
    //dataloader->AddVariable("fNSigTOFTrk1Pi", "fNSigTOFTrk1Pi", "units", 'F');
    //dataloader->AddVariable("fNSigTOFTrk2Ka", "fNSigTOFTrk2Ka", "units", 'F');
    //dataloader->AddVariable("fNSigTOFTrk3Pi", "fNSigTOFTrk3Pi", "units", 'F');
    //dataloader->AddVariable("fNSigTOFTrk3Pr", "fNSigTOFTrk3Pr", "units", 'F');

    // Spectator variables
    dataloader->AddSpectator("fPtProng0", "fPtProng0", "units", 'F');
    dataloader->AddSpectator("fPtProng1", "fPtProng1", "units", 'F');
    dataloader->AddSpectator("fM", "fM", "units", 'F');
    dataloader->AddSpectator("fPt", "fPt", "Gev", 'F');

    // global event weights per tree (see below for setting event-wise weights)
    Double_t signalWeight = 1.0;
    Double_t backgroundWeight = 1.0;

    // You can add an arbitrary number of signal or background trees
    if (signalTree->GetEntries() != 0)
      dataloader->AddSignalTree(signalTree, signalWeight);
    if (backgroundTree->GetEntries() != 0)
      dataloader->AddBackgroundTree(backgroundTree, backgroundWeight);
    if (signalTree2->GetEntries() != 0)
      dataloader->AddSignalTree(signalTree2, signalWeight);
    if (backgroundTree2->GetEntries() != 0)
      dataloader->AddBackgroundTree(backgroundTree2, backgroundWeight);

    // Apply additional cuts on the signal and background samples (can be different)
    TCut mycuts = ""; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
    TCut mycutb = ""; // for example: TCut mycutb = "abs(var1)<0.5";

    // case 1 input file
     //int NsigTrain = (signalTree->GetEntries()) * TrainFraction;
     //long long Nmaxbkg = 500000;
     //int NbkgTrain = min(Nmaxbkg, (long long)(backgroundTree->GetEntries() * TrainFraction));
     //int NsigTest = (signalTree->GetEntries()) * (1.0 - TrainFraction);
     //int NbkgTest = min(Nmaxbkg, (long long)(backgroundTree->GetEntries() * (1.0 - TrainFraction)));

    // case 2 input files
    int NsigTrain = (signalTree->GetEntries() + signalTree2->GetEntries()) * TrainFraction;
    long long Nmaxbkg = 500000;
    int NbkgTrain = min(Nmaxbkg, (long long)((backgroundTree->GetEntries() + backgroundTree2->GetEntries()) * TrainFraction));
    int NsigTest = (signalTree->GetEntries() + signalTree2->GetEntries()) * (1.0 - TrainFraction);
    int NbkgTest = min(Nmaxbkg, (long long)((backgroundTree->GetEntries() + backgroundTree2->GetEntries()) * (1.0 - TrainFraction)));
    
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
    // if (Use["MLP"]) factory->BookMethod(TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator");

    // Now you can tell the factory to train, test, and evaluate the MVAs
    factory->TrainAllMethods();
    factory->TestAllMethods();
    factory->EvaluateAllMethods();
    outputFile->Close(); // Save the output

    std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
    std::cout << "==> TMVAClassification is done!" << std::endl;
    TString mvdataset = "mv dataset " + outfileDir + "/dataset";
    gSystem->Exec(mvdataset);
    delete factory;
    delete dataloader;
    // Launch the GUI for the root macros
    // if (!gROOT->IsBatch())
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
  return TEMP(methodList);
}


	&	BDT		& & 		BDTG		& &		BDTF	 &	\\
Rank &	Variable	&	        Importance	&	Variable	&	Importance	&	Variable	&	Importance	\\
\hline
\hline
1	&	ImpactParameter0	&	 $2.88\cdot 10^{-1}$	&	ImpactParameter0	&	$3.07\cdot 10^{-1}$	&	CPA	                &	$3.16\cdot 10^{-1}$ \\
2	&	ImpactParameter1	&	 $2.08\cdot 10^{-1}$	&	ImpactParameter1	&	$2.27\cdot 10^{-1}$	&	CPAXY	            &	$2.42\cdot 10^{-1}$ \\
3	&	DecayLength		    &    $1.73\cdot 10^{-1}$	&	DecayLength	        &	$2.03\cdot 10^{-1}$	&	ImpactParameter0	&	$1.43\cdot 10^{-1}$ \\
4	&	DecayLengthXY		&    $1.37\cdot 10^{-1}$	&	DecayLengthXY	    &	$1.55\cdot 10^{-1}$	&	DecayLengthXY	    &	$1.12\cdot 10^{-1}$ \\
5	&	CPA		            &    $1.33\cdot 10^{-1}$	&	CPA	                &	$7.30\cdot 10^{-2}$	&	DecayLength	        &	$1.10\cdot 10^{-1}$ \\
6	&	CPAXY		        &    $5.80\cdot 10^{-2}$	&	CPAXY	            &	$3.02\cdot 10^{-2}$	&	ImpactParameter1	&	$7.68\cdot 10^{-2}$ \\
7	&	Chi2PCA		        &    $3.77\cdot 10^{-3}$	&	Chi2PCA	            &	$4.88\cdot 10^{-3}$	&	Chi2PCA	            &	$0.00\cdot 10^{+0}$ \\



	&	BDT		& & 		BDTG		& &		BDTF	 &	\\
Rank &	Variable	&	        Importance	&	Variable	&	Importance	&	Variable	&	Importance	\\
\hline
\hline
1	&	LcM	                &	$9.22\cdot 10^{-2}$	&	LcM	                &	$1.08\cdot 10^{-1}$ \\
2	&	NSigTOFTrk3Pr	    &	$6.91\cdot 10^{-2}$	&	LcCPA	            &	$5.62\cdot 10^{-2}$ \\
3	&	LcCPA	            &	$6.39\cdot 10^{-2}$	&	NSigTOFTrk3Pr	    &	$5.19\cdot 10^{-2}$ \\
4	&	LcDecayLengthXY	    &	$4.95\cdot 10^{-2}$	&	LcImpactParameter1	&	$4.64\cdot 10^{-2}$ \\
5	&	LcImpactParameter1	&	$4.78\cdot 10^{-2}$	&	LcDecayLength	    &	$4.57\cdot 10^{-2}$ \\
6	&	LcDecayLength	    &	$4.47\cdot 10^{-2}$	&	LcDecayLengthXY	    &	$4.56\cdot 10^{-2}$ \\
7	&	LcImpactParameter0	&	$4.25\cdot 10^{-2}$	&	LcImpactParameter0	&	$4.48\cdot 10^{-2}$ \\
8	&	CPA	                &	$4.23\cdot 10^{-2}$	&	NSigRICHTrk3Pr	    &	$4.30\cdot 10^{-2}$ \\
9	&	ImpactParameter0	&	$4.14\cdot 10^{-2}$	&	NSigRICHTrk3Pi	    &	$4.12\cdot 10^{-2}$ \\
10	&	LcImpactParameter2	&	$3.89\cdot 10^{-2}$	&	NSigTOFTrk1Pr	    &	$4.12\cdot 10^{-2}$ \\
11	&	NSigTOFTrk1Pr	    &	$3.77\cdot 10^{-2}$	&	ImpactParameter0	&	$4.12\cdot 10^{-2}$ \\
12	&	NSigRICHTrk3Pr	    &	$3.74\cdot 10^{-2}$	&	NSigTOFTrk3Pi	    &	$4.06\cdot 10^{-2}$ \\
13	&	NSigRICHTrk3Pi	    &	$3.64\cdot 10^{-2}$	&	LcImpactParameter2	&	$3.89\cdot 10^{-2}$ \\
14	&	LcCPAXY	            &	$3.61\cdot 10^{-2}$	&	NSigRICHPi0	        &	$3.74\cdot 10^{-2}$ \\
15	&	NSigTOFTrk1Pi	    &	$3.38\cdot 10^{-2}$	&	NSigRICHTrk1Pr	    &	$3.69\cdot 10^{-2}$ \\
16	&	ImpactParameter1	&	$3.29\cdot 10^{-2}$	&	NSigRICHTrk1Pi	    &	$3.41\cdot 10^{-2}$ \\
17	&	NSigRICHTrk1Pr	    &	$3.26\cdot 10^{-2}$	&	LcCPAXY	            &	$3.40\cdot 10^{-2}$ \\
18	&	NSigTOFTrk3Pi	    &	$3.24\cdot 10^{-2}$	&	ImpactParameter1	&	$3.06\cdot 10^{-2}$ \\
19	&	NSigRICHTrk1Pi	    &	$3.23\cdot 10^{-2}$	&	NSigRICHTrk2Ka	    &	$2.74\cdot 10^{-2}$ \\
20	&	NSigRICHTrk2Ka	    &	$2.83\cdot 10^{-2}$	&	NSigTOFTrk1Pi	    &	$2.72\cdot 10^{-2}$ \\
21	&	NSigRICHPi0	        &	$2.56\cdot 10^{-2}$	&	DecayLength	        &	$2.52\cdot 10^{-2}$ \\
22	&	CPAXY	            &	$2.09\cdot 10^{-2}$	&	CPA	                &	$2.11\cdot 10^{-2}$ \\
23	&	NSigTOFPi0	        &	$2.02\cdot 10^{-2}$	&	DecayLengthXY	    &	$2.03\cdot 10^{-2}$ \\
24	&	DecayLength	        &	$1.97\cdot 10^{-2}$	&	LcChi2PCA	        &	$1.92\cdot 10^{-2}$ \\
25	&	LcChi2PCA	        &	$1.83\cdot 10^{-2}$	&	NSigTOFPi0	        &	$1.86\cdot 10^{-2}$ \\
26	&	DecayLengthXY	    &	$1.28\cdot 10^{-2}$	&	NSigTOFTrk2Ka	    &	$1.53\cdot 10^{-2}$ \\
27	&	NSigTOFTrk2Ka	    &	$1.05\cdot 10^{-2}$	&	CPAXY	            &	$8.53\cdot 10^{-3}$ \\
28	&	Chi2PCA	            &	$0.00\cdot 10^{+0}$	&	Chi2PCA	            &	$0.00\cdot 10^{+0}$ \\


	&	BDT		& & 		BDTG		& &		BDTF	 &	\\
Rank &	Variable	&	        Importance	&	Variable	&	Importance	&	Variable	&	Importance	\\
\hline
\hline
1	&	LcM	                &	$1.06\cdot 10^{-1}$	&	LcM	                &	$1.40\cdot 10^{-1}$	&	CPA	                &	$1.93\cdot 10^{-1}$ \\
2	&	NSigTOFTrk3Pr	    &	$9.12\cdot 10^{-2}$	&	LcCPA	            &	$7.30\cdot 10^{-2}$	&	LcM	                &	$1.17\cdot 10^{-1}$ \\
3	&	LcCPA	            &	$7.64\cdot 10^{-2}$	&	NSigTOFTrk3Pr	    &	$6.94\cdot 10^{-2}$	&	LcDecayLengthXY	    &	$9.93\cdot 10^{-2}$ \\
4	&	LcDecayLengthXY	    &	$6.24\cdot 10^{-2}$	&	LcDecayLength	    &	$6.34\cdot 10^{-2}$	&	NSigTOFTrk3Pr	    &	$8.89\cdot 10^{-2}$ \\
5	&	LcDecayLength	    &	$5.72\cdot 10^{-2}$	&	LcDecayLengthXY	    &	$6.03\cdot 10^{-2}$	&	DecayLengthXY	    &	$7.36\cdot 10^{-2}$ \\
6	&	LcImpactParameter1	&	$5.69\cdot 10^{-2}$	&	LcImpactParameter1	&	$5.89\cdot 10^{-2}$	&	DecayLength	        &	$6.69\cdot 10^{-2}$ \\
7	&	LcImpactParameter2	&	$5.24\cdot 10^{-2}$	&	NSigTOFTrk1Pr	    &	$5.49\cdot 10^{-2}$	&	LcChi2PCA	        &	$6.18\cdot 10^{-2}$ \\
8	&	ImpactParameter0	&	$5.21\cdot 10^{-2}$	&	LcImpactParameter0	&	$5.46\cdot 10^{-2}$	&	LcDecayLength	    &	$6.13\cdot 10^{-2}$ \\
9	&	LcImpactParameter0	&	$5.16\cdot 10^{-2}$	&	ImpactParameter0	&	$5.06\cdot 10^{-2}$	&	NSigTOFTrk3Pi	    &	$5.19\cdot 10^{-2}$ \\
10	&	NSigTOFTrk1Pr	    &	$5.08\cdot 10^{-2}$	&	LcImpactParameter2	&	$4.90\cdot 10^{-2}$	&	CPAXY	            &	$4.68\cdot 10^{-2}$ \\
11	&	CPA	                &	$4.88\cdot 10^{-2}$	&	NSigTOFTrk3Pi	    &	$4.54\cdot 10^{-2}$	&	NSigTOFTrk1Pr	    &	$2.83\cdot 10^{-2}$ \\
12	&	LcCPAXY	            &	$4.79\cdot 10^{-2}$	&	ImpactParameter1	&	$4.47\cdot 10^{-2}$	&	ImpactParameter0	&	$2.46\cdot 10^{-2}$ \\
13	&	NSigTOFTrk3Pi	    &	$4.63\cdot 10^{-2}$	&	LcCPAXY	            &	$4.47\cdot 10^{-2}$	&	LcCPA	            &	$2.19\cdot 10^{-2}$ \\
14	&	ImpactParameter1	&	$3.72\cdot 10^{-2}$	&	DecayLength	        &	$3.30\cdot 10^{-2}$	&	NSigTOFTrk1Pi	    &	$1.73\cdot 10^{-2}$ \\
15	&	NSigTOFTrk1Pi	    &	$3.25\cdot 10^{-2}$	&	CPA	                &	$2.97\cdot 10^{-2}$	&	LcImpactParameter0	&	$1.62\cdot 10^{-2}$ \\
16	&	DecayLength	        &	$2.78\cdot 10^{-2}$	&	DecayLengthXY	    &	$2.69\cdot 10^{-2}$	&	NSigTOFPi0	        &	$9.84\cdot 10^{-3}$ \\
17	&	NSigTOFPi0	        &	$2.60\cdot 10^{-2}$	&	NSigTOFTrk1Pi	    &	$2.61\cdot 10^{-2}$	&	LcImpactParameter2	&	$8.31\cdot 10^{-3}$ \\
18	&	DecayLengthXY	    &	$2.55\cdot 10^{-2}$	&	LcChi2PCA	        &	$2.39\cdot 10^{-2}$	&	LcImpactParameter1	&	$7.90\cdot 10^{-3}$ \\
19	&	CPAXY	            &	$1.95\cdot 10^{-2}$	&	NSigTOFPi0	        &	$2.26\cdot 10^{-2}$	&	ImpactParameter1	&	$4.50\cdot 10^{-3}$ \\
20	&	LcChi2PCA	        &	$1.95\cdot 10^{-2}$	&	CPAXY	            &	$1.77\cdot 10^{-2}$	&	Chi2PCA	            &	$9.80\cdot 10^{-4}$ \\
21	&	NSigTOFTrk2Ka	    &	$1.16\cdot 10^{-2}$	&	NSigTOFTrk2Ka	    &	$1.18\cdot 10^{-2}$	&	LcCPAXY	            &	$3.87\cdot 10^{-6}$ \\
22	&	Chi2PCA	            &	$0.00\cdot 10^{+0}$	&	Chi2PCA	            &	$0.00\cdot 10^{+0}$	&	NSigTOFTrk2Ka	    &	$5.71\cdot 10^{-11}$\\

// pbpb no RICH
1
--- Classifier   (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg
--- --------------------------------------------------------------------------------------------------
---        BDT:  (204.96747,37720.199)      -0.3390      7.42371  111.8004  115.0006   0.5455 0.003049
---       BDTG:  (204.96747,37720.199)      -0.9810      3.63888  74.53362  345.0018   0.3636 0.009146
---       BDTF:  (204.96747,37720.199)       0.0976      7.59019  93.16703   57.5003   0.4545 0.001524

2
---        BDT:  (2855.1055,36941.699)      -0.1007      45.2411  2489.066  537.8874   0.8718  0.01456
---       BDTG:  (2855.1055,36941.699)      -0.4684      45.9125  2537.872  517.5897   0.8889  0.01401
---       BDTF:  (2855.1055,36941.699)       0.0685      45.6116  2659.885  740.8637   0.9316  0.02005

3
---        BDT:  (7400.1338,37946.102)      -0.0686      77.8955  7123.862  1239.983   0.9627  0.03268
---       BDTG:  (7400.1338,37946.102)      -0.1546      78.5127  7123.862  1108.999   0.9627  0.02923
---       BDTF:  (7400.1338,37946.102)       0.0697      75.4291  6887.058  1449.558   0.9307   0.0382

4
---        BDT:  (11264.655,34524.602)      -0.0542      98.4302  10814.69    1257.1   0.9601  0.03641
---       BDTG:  (11264.655,34524.602)      -0.1108      99.2163  10969.85  1254.759   0.9738  0.03634
---       BDTF:  (11264.655,34524.602)       0.0349      97.5078  10612.98   1233.69   0.9421  0.03573

5
---        BDT:  (24420.588,    42202)      -0.0421      146.929  23578.92  2174.453   0.9655  0.05152
---       BDTG:  (24420.588,    42202)       0.2010      148.091  23505.73  1687.816   0.9625  0.03999
---       BDTF:  (24420.588,    42202)      -0.0003      140.414     23030  3871.076   0.9431  0.09173

7
---        BDT:  (32203.332,    43846)      -0.0444      168.483  31049.39  2912.835   0.9642  0.06643
---       BDTG:  (32203.332,    43846)       0.0333      170.251  31251.63  2443.315   0.9704  0.05572
---       BDTF:  (32203.332,    43846)       0.0095      166.132  30442.68  3135.629   0.9453  0.07151

10
---        BDT:  (16053.277,39439.301)      -0.0402      111.693  14721.48  2650.569    0.917  0.06721
---       BDTG:  (16053.277,39439.301)       0.1751       112.81  14895.64  2539.322   0.9279  0.06439
---       BDTF:  (16053.277,39439.301)       0.0111      107.618  14485.85   3632.44   0.9024   0.0921

13
---        BDT:  (7256.7539,40660.543)      -0.0427      67.9516  6340.938  2366.854   0.8738  0.05821
---       BDTG:  (7256.7539,40660.543)       0.1881      68.4837  6524.101  2551.316    0.899  0.06275
---       BDTF:  (7256.7539,40660.543)       0.0837      66.1861  6262.439   2690.26    0.863  0.06616

16
---        BDT:  (3875.5264,  41953.5)      -0.0360      42.5265  2915.943  1785.577   0.7524  0.04256
---       BDTG:  (3875.5264,  41953.5)       0.2543      43.3743  3272.997  2421.122   0.8445  0.05771
---       BDTF:  (3875.5264,  41953.5)       0.1436      40.0675  2782.048  2039.038   0.7179   0.0486

20
---        BDT:  (1396.8569,46428.551)      -0.0490      18.7284  891.9689  1376.323   0.6386  0.02964
---       BDTG:  (1396.8569,46428.551)       0.6393      18.2652  785.3814  1063.522   0.5622  0.02291
---       BDTF:  (1396.8569,46428.551)       0.2045       18.513  863.9195  1313.763   0.6185   0.0283
