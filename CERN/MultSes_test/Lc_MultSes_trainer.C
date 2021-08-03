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

int Lc_MultSes_trainer(TString myMethodList = "")
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

  std::cout << std::endl;
  std::cout << "==> Start TMVAClassification" << std::endl;

  // --------------------------------------------------------------------------------------------------

  // Here the preparation phase begins

  // Read training and test data
  // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
  TFile* inputSignal(0);
  TString fnamesig = "/home/mjongerh/alice/LcBDTtest/input/Lc_signal_nocuts_50files.root";
  TFile* inputBackground(0);
  TString fnamebkg = "/home/mjongerh/alice/LcBDTtest/input/Lc_background_nocuts_50files.root";

  // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
  TString outfileName("TMVA_Lc_BDTfactory.root");
  //TString temporaryfName("TEMPORARYFILE.root")
  //TString cmd = "cp " + outputFile + " " + temporaryfName;
  //std::cout << "cmd exit status = " << gSystem->Exec(cmd) << std::endl;
  TFile* outputFile = TFile::Open(outfileName, "RECREATE");

  if (!gSystem->AccessPathName(fnamesig)) {
    inputSignal = TFile::Open(fnamesig); // check if file in local directory exists
  }
  if (!inputSignal) {
    std::cout << "ERROR: could not open signal data file" << std::endl;
    exit(1);
  }
  std::cout << "--- TMVAClassification       : Using input signal file: " << inputSignal->GetName() << std::endl;

  if (!gSystem->AccessPathName(fnamebkg)) {
    inputBackground = TFile::Open(fnamebkg); // check if file in local directory exists
  }
  if (!inputBackground) {
    std::cout << "ERROR: could not open background data file" << std::endl;
    exit(1);
  }
  std::cout << "--- TMVAClassification       : Using input background file: " << inputBackground->GetName() << std::endl;

  // Register the training and test trees
  TTree* signalTree = (TTree*)inputSignal->Get("DF_0/O2hfcandp3full");
  TTree* backgroundTree = (TTree*)inputBackground->Get("DF_0/O2hfcandp3full");

  signalTree->Print();
  backgroundTree->Print();
  signalTree->AutoSave();
  backgroundTree->AutoSave();

  // Create the factory object. Later you can choose the methods

  TMVA::Factory* factory = new TMVA::Factory("TMVAClassification", outputFile,
                                             "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");

  TMVA::DataLoader* dataloader = new TMVA::DataLoader("dataset");
  // If you wish to modify default settings
  // (please check "src/Config.h" to see all available global options)
  //
  //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
  //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

  // Define the input variables that shall be used for the MVA training
  // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
  // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
  dataloader->AddVariable("fCPA", "fCPA", "units", 'F');
  dataloader->AddVariable("fDecayLength", "fDecayLength", "units", 'F');
  dataloader->AddVariable("fImpactParameter0", "fImpactParameter0", "units", 'F');
  dataloader->AddVariable("fImpactParameter1", "fImpactParameter1", "units", 'F');
  dataloader->AddVariable("fImpactParameter2", "fImpactParameter2", "units", 'F');
  dataloader->AddVariable("fCPAXY", "fCPAXY", "units", 'F');

  // global event weights per tree (see below for setting event-wise weights)
  Double_t signalWeight = 1.0;
  Double_t backgroundWeight = 1.0;

  // You can add an arbitrary number of signal or background trees
  dataloader->AddSignalTree(signalTree, signalWeight);
  dataloader->AddBackgroundTree(backgroundTree, backgroundWeight);

  // End of tree registration

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
  //         "NSigTrain=3000:NBkgTrain=3000:NSigTest=3000:NBkgTest=3000:SplitMode=Random:!V" ); SEEMS OUTDATED, use the following instead:
  // PrepareTrainingAndTestTree(mycuts, NsigTrain, NbkgTrain, NsigTest, NbkgTest, "SplitMode=Random:NormMode=NumEvents:!V")
  int NsigTrain = signalTree->GetEntries();
  long long Nmaxbkg = 30000;
  int NbkgTrain = min(Nmaxbkg, backgroundTree->GetEntries());
  int NsigTest = 0;
  int NbkgTest = 0;
  dataloader->PrepareTrainingAndTestTree(mycuts, NsigTrain, NbkgTrain, NsigTest, NbkgTest, "SplitMode=Random:NormMode=NumEvents:!V");

  // ### Book MVA methods
  //
  // Please lookup the various method configuration options in the corresponding cxx files, eg:
  // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
  // it is possible to preset ranges in the option string in which the cut optimisation should be done:
  // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

  // Boosted Decision Trees
  TString weightfName("dataset/weights/TMVAClassification_BDT.weights.xml");
  factory->BookMethodWeightFile(dataloader, TMVA::Types::kBDT, "BDT", weightfName); //Uses the weightfile/factory from previous sessions

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
  //factory->TestAllMethods();

  // Evaluate and compare performance of all configured MVAs
  //factory->EvaluateAllMethods();

  // --------------------------------------------------------------

  // Save the output
  outputFile->Close();

  std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
  std::cout << "==> TMVAClassification is done!" << std::endl;

  //TString cmdrm = "rm " + temporaryfName;
  //std::cout << "cmd exit status = " << gSystem->Exec(cmd) << std::endl;
  delete factory;
  delete dataloader;
  // Launch the GUI for the root macros
  //if (!gROOT->IsBatch())
  //  TMVA::TMVAGui(outfileName);

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
  return Lc_MultSes_trainer(methodList);
}
