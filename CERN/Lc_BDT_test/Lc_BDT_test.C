/// \file
 /// \ingroup tutorial_tmva
 /// \notebook -nodraw
 /// This macro provides examples for the training and testing of the
 /// TMVA classifiers.
 ///
 /// As input data is used a toy-MC sample consisting of four Gaussian-distributed
 /// and linearly correlated input variables.
 /// The methods to be used can be switched on and off by means of booleans, or
 /// via the prompt command, for example:
 ///
 ///     root -l ./TMVAClassification.CUndefined control sequence \"
 ///
 /// (note that the backslashes are mandatory)
 /// If no method given, a default set of classifiers is used.
 /// The output file "TMVA.root" can be analysed with the use of dedicated
 /// macros (simply say: root -l <macro.C>), which can be conveniently
 /// invoked through a GUI that will appear at the end of the run of this macro.
 /// Launch the GUI via the command:
 ///
 ///     root -l ./TMVAGui.C
 ///
 /// You can also compile and run the example with the following commands
 ///
 ///     make
 ///     ./TMVAClassification <Methods>
 ///
 /// where: `<Methods> = "method1 method2"` are the TMVA classifier names
 /// example:
 ///
 ///     ./TMVAClassification Fisher LikelihoodPCA BDT
 ///
 /// If no method given, a default set is of classifiers is used
 ///
 /// - Project   : TMVA - a ROOT-integrated toolkit for multivariate data analysis
 /// - Package   : TMVA
 /// - Root Macro: TMVAClassification
 ///
 /// \macro_output
 /// \macro_code
 /// \author Andreas Hoecker


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
 //#include "/home/mjongerh/alice/sw/ubuntu2004_x86-64/ROOT/v6-20-08-alice1-local2/test/Event.h"

 #include "TMVA/Factory.h"
 #include "TMVA/DataLoader.h"
 #include "TMVA/Tools.h"
 #include "TMVA/TMVAGui.h"

 int Lc_BDT_test( TString myMethodList = "" )
 {
    // The explicit loading of the shared libTMVA is done in TMVAlogon.C, defined in .rootrc
    // if you use your private .rootrc, or run from a different directory, please copy the
    // corresponding lines from .rootrc

    // Methods to be processed can be given as an argument; use format:
    //
    //     mylinux~> root -l TMVAClassification.CUndefined control sequence \"

    //---------------------------------------------------------------
    // This loads the library
    TMVA::Tools::Instance();

    // Default MVA methods to be trained + tested
    std::map<std::string,int> Use;

    // Boosted Decision Trees
    Use["BDT"]             = 1; // uses Adaptive Boost
    Use["BDTG"]            = 0; // uses Gradient Boost
    Use["BDTB"]            = 0; // uses Bagging
    Use["BDTD"]            = 0; // decorrelation + Adaptive Boost
    Use["BDTF"]            = 0; // allow usage of fisher discriminant for node splitting
    //
    // Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
    Use["RuleFit"]         = 0;
    // ---------------------------------------------------------------

    std::cout << std::endl;
    std::cout << "==> Start TMVAClassification" << std::endl;

    // Select methods (don't look at this code - not of interest)
    if (myMethodList != "") {
       for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

       std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
       for (UInt_t i=0; i<mlist.size(); i++) {
          std::string regMethod(mlist[i]);

          if (Use.find(regMethod) == Use.end()) {
             std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
             for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
             std::cout << std::endl;
             return 1;
          }
          Use[regMethod] = 1;
       }
    }

    // --------------------------------------------------------------------------------------------------

    // Here the preparation phase begins

    // Read training and test data
    // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
    TFile *inputSignal(0);
    TString fnamesig = "/home/mjongerh/alice/SharedFol/CERN/Lc_BDT_test/PtBinTest/Lc_binTest_signal_Pt2.root"; //"/home/mjongerh/alice/LcBDTtest/input/Lc_signal_nocuts_50files.root";
    if (!gSystem->AccessPathName( fnamesig )) {
       inputSignal = TFile::Open( fnamesig ); // check if file in local directory exists
    }
    if (!inputSignal) {
       std::cout << "ERROR: could not open data file" << std::endl;
       exit(1);
    }
    std::cout << "--- TMVAClassification       : Using input file: " << inputSignal->GetName() << std::endl;

    TFile *inputBackground(0);
    TString fnamebkg = "/home/mjongerh/alice/SharedFol/CERN/Lc_BDT_test/PtBinTest/Lc_binTest_background_Pt2.root"; //"/home/mjongerh/alice/LcBDTtest/input/Lc_background_nocuts_50files.root";
    if (!gSystem->AccessPathName(fnamebkg)) {
      inputBackground = TFile::Open(fnamebkg); // check if file in local directory exists
    }
    if (!inputBackground) {
      std::cout << "ERROR: could not open data file" << std::endl;
      exit(1);
    }
    std::cout << "--- TMVAClassification       : Using input file: " << inputBackground->GetName() << std::endl;

    // Register the training and test trees
    TTree* signalTree = (TTree*)inputSignal->Get("O2hfcandp3full"); //Get("DF_0/O2hfcandp3full")
    TTree* backgroundTree = (TTree*)inputBackground->Get("O2hfcandp3full");

    signalTree->Print();
    backgroundTree->Print();
    signalTree->AutoSave();
    backgroundTree->AutoSave();

    // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
    TString outfileName( "TMVA.root" );
    TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

    // Create the factory object. Later you can choose the methods
    // whose performance you'd like to investigate. The factory is
    // the only TMVA object you have to interact with
    //
    // The first argument is the base of the name of all the
    // weightfiles in the directory weight/
    //
    // The second argument is the output file for the training results
    // All TMVA output can be suppressed by removing the "!" (not) in
    // front of the "Silent" argument in the option string
    TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,
                                                "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );

    TMVA::DataLoader *dataloader=new TMVA::DataLoader("dataset");
    // If you wish to modify default settings
    // (please check "src/Config.h" to see all available global options)
    //
    //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
    //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

    // Define the input variables that shall be used for the MVA training
    // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
    // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
    dataloader->AddVariable("fCPA", "fCPA", "units", 'F' );
    dataloader->AddVariable("fDecayLength", "fDecayLength", "units", 'F');
    dataloader->AddVariable("fImpactParameter0", "fImpactParameter0", "units", 'F');
    dataloader->AddVariable("fImpactParameter1", "fImpactParameter1", "units", 'F');
    dataloader->AddVariable("fImpactParameter2", "fImpactParameter2", "units", 'F');
    dataloader->AddVariable("fCPAXY", "fCPAXY", "units", 'F');


    //dataloader->AddVariable("fNSigTOFPi0", "fNSigTOFPi0", "units", 'F');
    //dataloader->AddVariable("fNSigTOFPi1", "fNSigTOFPi1", "units", 'F');
    dataloader->AddVariable("fNSigTOFPi2", "fNSigTOFPi2", "units", 'F');
    //dataloader->AddVariable("fNSigTOFKa0", "fNSigTOFKa0", "units", 'F');
    dataloader->AddVariable("fNSigTOFKa1", "fNSigTOFKa1", "units", 'F');
    //dataloader->AddVariable("fNSigTOFKa2", "fNSigTOFKa2", "units", 'F');
    dataloader->AddVariable("fNSigTOFPr0", "fNSigTOFPr0", "units", 'F');
    //dataloader->AddVariable("fNSigTOFPr1", "fNSigTOFPr1", "units", 'F');
    //dataloader->AddVariable("fNSigTOFPr2", "fNSigTOFPr2", "units", 'F');

    // You can add so-called "Spectator variables", which are not used in the MVA training,
    // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
    // input variables, the response values of all trained MVAs, and the spectator variables

    //dataloader->AddSpectator( "spec1 := var1*2",  "Spectator 1", "units", 'F' );
    //dataloader->AddSpectator( "spec2 := var1*3",  "Spectator 2", "units", 'F' );
    dataloader->AddSpectator("fM", "fM", "units", 'F');
    dataloader->AddSpectator("fPt", "fPt", "Gev", 'F');


    // global event weights per tree (see below for setting event-wise weights)
    Double_t signalWeight     = 1.0;
    Double_t backgroundWeight = 1.0;

    // You can add an arbitrary number of signal or background trees
    dataloader->AddSignalTree    ( signalTree,     signalWeight );
    dataloader->AddBackgroundTree( backgroundTree, backgroundWeight );

    // To give different trees for training and testing, do as follows:
    //
    //     dataloader->AddSignalTree( signalTrainingTree, signalTrainWeight, "Training" );
    //     dataloader->AddSignalTree( signalTestTree,     signalTestWeight,  "Test" );

    // Use the following code instead of the above two or four lines to add signal and background
    // training and test events "by hand"
    // NOTE that in this case one should not give expressions (such as "var1+var2") in the input
    //      variable definition, but simply compute the expression before adding the event
    // ```cpp
    // // --- begin ----------------------------------------------------------
    // std::vector<Double_t> vars( 4 ); // vector has size of number of input variables
    // Float_t  treevars[4], weight;
    //
    // // Signal
    // for (UInt_t ivar=0; ivar<4; ivar++) signalTree->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
    // for (UInt_t i=0; i<signalTree->GetEntries(); i++) {
    //    signalTree->GetEntry(i);
    //    for (UInt_t ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
    //    // add training and test events; here: first half is training, second is testing
    //    // note that the weight can also be event-wise
    //    if (i < signalTree->GetEntries()/2.0) dataloader->AddSignalTrainingEvent( vars, signalWeight );
    //    else                              dataloader->AddSignalTestEvent    ( vars, signalWeight );
    // }
    //
    // // Background (has event weights)
    // background->SetBranchAddress( "weight", &weight );
    // for (UInt_t ivar=0; ivar<4; ivar++) background->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
    // for (UInt_t i=0; i<background->GetEntries(); i++) {
    //    background->GetEntry(i);
    //    for (UInt_t ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
    //    // add training and test events; here: first half is training, second is testing
    //    // note that the weight can also be event-wise
    //    if (i < background->GetEntries()/2) dataloader->AddBackgroundTrainingEvent( vars, backgroundWeight*weight );
    //    else                                dataloader->AddBackgroundTestEvent    ( vars, backgroundWeight*weight );
    // }
    // // --- end ------------------------------------------------------------
    // ```
    // End of tree registration

    // Set individual event weights (the variables must exist in the original TTree)
    // -  for signal    : `dataloader->SetSignalWeightExpression    ("weight1*weight2");`
    // -  for background: `dataloader->SetBackgroundWeightExpression("weight1*weight2");`
    
    //dataloader->SetBackgroundWeightExpression( "weight" );

    // Apply additional cuts on the signal and background samples (can be different)
    TCut mycuts = ""; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
    TCut mycutb = ""; // for example: TCut mycutb = "abs(var1)<0.5";

    // Tell the dataloader how to use the training and testing events
    //
    // If no numbers of events are given, half of the events in the tree are used
    // for training, and the other half for testing:
    //
    //    dataloader->PrepareTrainingAndTestTree( mycut, "SplitMode=random:!V" );
    //
    // To also specify the number of testing events, use:
    //
    //    dataloader->PrepareTrainingAndTestTree( mycut,
    //         "NSigTrain=3000:NBkgTrain=3000:NSigTest=3000:NBkgTest=3000:SplitMode=Random:!V" );
    int NsigTrain = signalTree->GetEntries() / 2;
    long long Nmaxbkg = 300000;
    int NbkgTrain = min(Nmaxbkg, backgroundTree->GetEntries()/2);
    int NsigTest = signalTree->GetEntries() / 2;
    int NbkgTest = min(Nmaxbkg, backgroundTree->GetEntries()/2);
    dataloader->PrepareTrainingAndTestTree(mycuts, NsigTrain, NbkgTrain, NsigTest, NbkgTest, "SplitMode=Random:NormMode=NumEvents:!V");

    // ### Book MVA methods
    //
    // Please lookup the various method configuration options in the corresponding cxx files, eg:
    // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
    // it is possible to preset ranges in the option string in which the cut optimisation should be done:
    // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

    // Boosted Decision Trees
    if (Use["BDTG"]) // Gradient Boost
       factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTG",
                            "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );

    if (Use["BDT"])  // Adaptive Boost
       factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT",
                            "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );

    if (Use["BDTB"]) // Bagging
       factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTB",
                            "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20" );

    if (Use["BDTD"]) // Decorrelation + Adaptive Boost
       factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTD",
                            "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate" );

    if (Use["BDTF"])  // Allow Using Fisher discriminant in node splitting for (strong) linearly correlated variables
       factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTF",
                            "!H:!V:NTrees=50:MinNodeSize=2.5%:UseFisherCuts:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20" );

    // RuleFit -- TMVA implementation of Friedman's method
    if (Use["RuleFit"])
       factory->BookMethod( dataloader, TMVA::Types::kRuleFit, "RuleFit",
                            "H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02" );

    // For an example of the category classifier usage, see: TMVAClassificationCategory
    //
    // --------------------------------------------------------------------------------------------------
    //  Now you can optimize the setting (configuration) of the MVAs using the set of training events
    // STILL EXPERIMENTAL and only implemented for BDT's !
    //
    //     factory->OptimizeAllMethods("SigEffAt001","Scan");
    //     factory->OptimizeAllMethods("ROCIntegral","FitGA");
    //
    // --------------------------------------------------------------------------------------------------

    // Now you can tell the factory to train, test, and evaluate the MVAs
    //
    // Train MVAs using the set of training events
    factory->TrainAllMethods();

    // Evaluate all MVAs using the set of test events
    factory->TestAllMethods();

    // Evaluate and compare performance of all configured MVAs
    factory->EvaluateAllMethods();

    // --------------------------------------------------------------

    // Save the output
    outputFile->Close();

    std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
    std::cout << "==> TMVAClassification is done!" << std::endl;

    delete factory;
    delete dataloader;
    // Launch the GUI for the root macros
    if (!gROOT->IsBatch()) TMVA::TMVAGui( outfileName );

    return 0;
 }

 int main( int argc, char** argv )
 {
    // Select methods (don't look at this code - not of interest)
    TString methodList;
    for (int i=1; i<argc; i++) {
       TString regMethod(argv[i]);
       if(regMethod=="-b" || regMethod=="--batch") continue;
       if (!methodList.IsNull()) methodList += TString(",");
       methodList += regMethod;
    }
    return Lc_BDT_test(methodList);
 }
