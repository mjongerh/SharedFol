// Class: ReadRuleFit
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : RuleFit::RuleFit
TMVA Release   : 4.2.1         [262657]
ROOT Release   : 6.24/06       [399366]
Creator        : mjongerh
Date           : Wed Feb 23 15:18:55 2022
Host           : Linux alicecerno2 5.4.0-90-generic #101-Ubuntu SMP Fri Oct 15 20:00:55 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /home/mjongerh/alice/SharedFol/CERN/Lb
Training events: 13426
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
H: "True" [Print method-specific help message]
GDTau: "-1.000000e+00" [Gradient-directed (GD) path: default fit cut-off]
GDTauPrec: "1.000000e-02" [GD path: precision of tau]
GDStep: "1.000000e-02" [GD path: step size]
GDNSteps: "10000" [GD path: number of steps]
GDErrScale: "1.020000e+00" [Stop scan when error > scale*errmin]
fEventsMin: "1.000000e-02" [Minimum fraction of events in a splittable node]
fEventsMax: "5.000000e-01" [Maximum fraction of events in a splittable node]
nTrees: "20" [Number of trees in forest.]
RuleMinDist: "1.000000e-03" [Minimum distance between rules]
MinImp: "1.000000e-03" [Minimum rule importance accepted]
Model: "modrulelinear" [Model to be used]
RuleFitModule: "rftmva" [Which RuleFit module to use]
# Default:
VerbosityLevel: "Default" [Verbosity level]
VarTransform: "None" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
LinQuantile: "2.500000e-02" [Quantile of linear terms (removes outliers)]
GDPathEveFrac: "5.000000e-01" [Fraction of events used for the path search]
GDValidEveFrac: "5.000000e-01" [Fraction of events used for the validation]
ForestType: "adaboost" [Method to use for forest generation (AdaBoost or RandomForest)]
RFWorkDir: "./rulefit" [Friedman's RuleFit module (RFF): working dir]
RFNrules: "2000" [RFF: Mximum number of rules]
RFNendnodes: "4" [RFF: Average number of end nodes]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 7
fCPA                          fCPA                          fCPA                          fCPA                          units                             'F'    [0.950004994869,1]
fCPAXY                        fCPAXY                        fCPAXY                        fCPAXY                        units                             'F'    [0.738317668438,1]
fChi2PCA                      fChi2PCA                      fChi2PCA                      fChi2PCA                      units                             'F'    [2.42053495138e-17,9.95931550278e-05]
fDecayLength                  fDecayLength                  fDecayLength                  fDecayLength                  units                             'F'    [0.00510575436056,2.57999682426]
fDecayLengthXY                fDecayLengthXY                fDecayLengthXY                fDecayLengthXY                units                             'F'    [0.00504088168964,2.08321642876]
fImpactParameter0             fImpactParameter0             fImpactParameter0             fImpactParameter0             units                             'F'    [-0.306884557009,0.242023587227]
fImpactParameter1             fImpactParameter1             fImpactParameter1             fImpactParameter1             units                             'F'    [-1.7921795845,1.96139729023]
NSpec 4
fPtProng0                     fPtProng0                     fPtProng0                     fPtProng0                     units                             'F'    [1.09606301785,16.3366107941]
fPtProng1                     fPtProng1                     fPtProng1                     fPtProng1                     units                             'F'    [0.500221073627,14.2106075287]
fM                            fM                            fM                            fM                            units                             'F'    [4.62080574036,6.62003660202]
fPt                           fPt                           fPt                           fPt                           Gev                               'F'    [13.0003318787,15.9998140335]


============================================================================ */

#include <array>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadRuleFit : public IClassifierReader {

 public:

   // constructor
   ReadRuleFit( std::vector<std::string>& theInputVars )
      : IClassifierReader(),
        fClassName( "ReadRuleFit" ),
        fNvars( 7 )
   {
      // the training input variables
      const char* inputVars[] = { "fCPA", "fCPAXY", "fChi2PCA", "fDecayLength", "fDecayLengthXY", "fImpactParameter0", "fImpactParameter1" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = 0;
      fVmax[0] = 0;
      fVmin[1] = 0;
      fVmax[1] = 0;
      fVmin[2] = 0;
      fVmax[2] = 0;
      fVmin[3] = 0;
      fVmax[3] = 0;
      fVmin[4] = 0;
      fVmax[4] = 0;
      fVmin[5] = 0;
      fVmax[5] = 0;
      fVmin[6] = 0;
      fVmax[6] = 0;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';
      fType[4] = 'F';
      fType[5] = 'F';
      fType[6] = 'F';

      // initialize constants
      Initialize();

   }

   // destructor
   virtual ~ReadRuleFit() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const override;

 private:

   // method-specific destructor
   void Clear();

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   double fVmin[7];
   double fVmax[7];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[7];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)
   // not implemented for class: "ReadRuleFit"
};
void   ReadRuleFit::Initialize(){}
void   ReadRuleFit::Clear(){}
double ReadRuleFit::GetMvaValue__( const std::vector<double>& inputValues ) const {
   double rval=0.2425850817;
   //
   // here follows all rules ordered in importance (most important first)
   // at the end of each line, the relative importance of the rule is given
   //
   if ((inputValues[3]<0.2514971793)&&(inputValues[4]<0.3019230962)&&(-0.02313378826<inputValues[5])) rval+=-0.02447354805;   // importance = 0.808
   if ((inputValues[4]<0.2029623687)&&(-0.04540393502<inputValues[6])) rval+=-0.0246141638;   // importance = 0.805
   if ((inputValues[3]<0.250333488)) rval+=-0.02625374295;   // importance = 0.791
   if ((inputValues[4]<0.2029623687)) rval+=-0.02696542983;   // importance = 0.782
   if ((inputValues[4]<0.2029623687)&&(-0.009382195771<inputValues[5])) rval+=-0.02138491188;   // importance = 0.773
   if ((0.02856740728<inputValues[3])&&(inputValues[3]<0.2514971793)&&(inputValues[4]<0.3019230962)) rval+=-0.021333793;   // importance = 0.765
   if ((inputValues[3]<0.3729473352)&&(0.03975900263<inputValues[4])) rval+=-0.02019775047;   // importance = 0.737
   if ((-0.004762025084<inputValues[6])) rval+=-0.01986979203;   // importance = 0.735
   if ((inputValues[5]<0.03291572258)) rval+=-0.03005645635;   // importance = 0.632
   if ((-0.0433838889<inputValues[5])&&(inputValues[5]<0.0005389272701)) rval+=-0.015397243;   // importance = 0.580
   if ((0.0634758994<inputValues[3])&&(inputValues[3]<0.250333488)) rval+=-0.0151038236;   // importance = 0.569
   if ((-0.01713395864<inputValues[5])&&(-0.004762025084<inputValues[6])) rval+=-0.01451687829;   // importance = 0.543
   if ((0.1276836693<inputValues[3])) rval+=-0.0141528976;   // importance = 0.529
   if ((inputValues[5]<0.006777239498)&&(0.003479679348<inputValues[6])) rval+=-0.01403226571;   // importance = 0.525
   if ((inputValues[6]<-0.004762025084)) rval+=-0.01301565412;   // importance = 0.481
   if ((inputValues[3]<0.1277196109)&&(-0.004762025084<inputValues[6])) rval+=-0.01243690509;   // importance = 0.455
   if ((0.1276836693<inputValues[3])&&(0.1211130992<inputValues[4])) rval+=-0.01163175279;   // importance = 0.419
   if ((0.1277196109<inputValues[3])&&(-0.01936124265<inputValues[5])) rval+=-0.01001586686;   // importance = 0.347
   if ((inputValues[3]<0.3729473352)&&(inputValues[4]<0.03975900263)) rval+=-0.009378992081;   // importance = 0.316
   if ((inputValues[5]<0.006777239498)&&(inputValues[6]<0.003479679348)) rval+=-0.009275717585;   // importance = 0.313
   if ((0.008045311086<inputValues[5])&&(inputValues[6]<-0.004762025084)) rval+=-0.008431222459;   // importance = 0.279
   if ((0.01399277989<inputValues[4])&&(inputValues[4]<0.2029623687)&&(inputValues[6]<-0.008894753642)) rval+=-0.00846419485;   // importance = 0.278
   if ((inputValues[4]<0.1040191874)&&(0.0005389272701<inputValues[5])&&(inputValues[5]<0.02057173848)) rval+=-0.008402889653;   // importance = 0.277
   if ((inputValues[3]<0.128816396)&&(inputValues[5]<0.006777239498)&&(inputValues[6]<0.003479679348)) rval+=-0.008147482549;   // importance = 0.262
   if ((0.1277196109<inputValues[3])&&(-0.004762025084<inputValues[6])) rval+=-0.007432886944;   // importance = 0.235
   if ((inputValues[4]<0.1040016189)&&(inputValues[6]<-0.004762025084)) rval+=-0.006575285233;   // importance = 0.200
   if ((0.05287220329<inputValues[3])&&(inputValues[4]<0.2029623687)&&(0.005784037057<inputValues[5])&&(inputValues[6]<0.02192511037)) rval+=-0.006524307486;   // importance = 0.197
   if ((0.1040016189<inputValues[4])&&(inputValues[6]<-0.004762025084)) rval+=-0.006440368887;   // importance = 0.193
   if ((inputValues[3]<0.1277196109)&&(inputValues[6]<-0.004762025084)) rval+=-0.00630107214;   // importance = 0.189
   if ((inputValues[3]<0.1277196109)&&(inputValues[4]<0.03414906189)&&(-0.004762025084<inputValues[6])) rval+=-0.006371915692;   // importance = 0.186
   if ((inputValues[3]<0.1277196109)&&(0.03414906189<inputValues[4])&&(-0.004762025084<inputValues[6])) rval+=-0.006064989393;   // importance = 0.181
   if ((0.2029623687<inputValues[4])) rval+=-0.005920016322;   // importance = 0.172
   if ((inputValues[4]<0.2029623687)&&(inputValues[5]<-0.009382195771)) rval+=-0.005580517948;   // importance = 0.160
   if ((0.02388767526<inputValues[4])&&(inputValues[4]<0.2029623687)&&(inputValues[5]<-0.009382195771)) rval+=-0.005537088514;   // importance = 0.159
   if ((0.008045311086<inputValues[5])&&(inputValues[5]<0.03033493832)&&(inputValues[6]<-0.004762025084)) rval+=-0.005388264951;   // importance = 0.151
   if ((0.08088345081<inputValues[3])&&(inputValues[3]<0.2514971793)&&(inputValues[4]<0.3019230962)&&(-0.02313378826<inputValues[5])&&(inputValues[5]<-0.0008329481934)) rval+=-0.004385690167;   // importance = 0.112
   if ((0.1277196109<inputValues[3])&&(inputValues[5]<-0.01936124265)) rval+=-0.004131602065;   // importance = 0.104
   if ((0.250333488<inputValues[3])&&(inputValues[6]<0.03778849915)) rval+=-0.004154647322;   // importance = 0.102
   if ((inputValues[3]<0.2514971793)&&(0.1219809577<inputValues[4])&&(inputValues[4]<0.3019230962)&&(-0.02313378826<inputValues[5])) rval+=-0.003928621302;   // importance = 0.096
   if ((0.1277196109<inputValues[3])&&(inputValues[3]<0.2446001917)&&(-0.004762025084<inputValues[6])) rval+=-0.003881352915;   // importance = 0.094
   if ((-0.0433838889<inputValues[5])&&(inputValues[5]<0.0005389272701)&&(0.04204556718<inputValues[6])) rval+=-0.003328557868;   // importance = 0.077
   if ((0.1484051049<inputValues[3])&&(inputValues[4]<0.2029623687)&&(0.0003110108373<inputValues[5])) rval+=-0.003261294084;   // importance = 0.074
   if ((0.1484051049<inputValues[3])&&(0.052572079<inputValues[4])&&(inputValues[4]<0.2029623687)&&(0.0003110108373<inputValues[5])) rval+=-0.003255865404;   // importance = 0.073
   if ((0.1484051049<inputValues[3])&&(inputValues[4]<0.2029623687)&&(inputValues[5]<0.0003110108373)) rval+=-0.003231901461;   // importance = 0.073
   if ((0.02497562394<inputValues[3])&&(0.0521742627<inputValues[4])&&(inputValues[4]<0.1040191874)&&(0.0005389272701<inputValues[5])&&(inputValues[5]<0.02057173848)) rval+=-0.003201178297;   // importance = 0.073
   if ((0.0521742627<inputValues[4])&&(inputValues[4]<0.1040191874)&&(0.0005389272701<inputValues[5])&&(inputValues[5]<0.02057173848)) rval+=-0.003201178297;   // importance = 0.073
   if ((inputValues[3]<0.3729473352)&&(0.1497097164<inputValues[4])&&(inputValues[4]<0.2020845562)) rval+=-0.003200389203;   // importance = 0.071
   if ((0.2029623687<inputValues[4])&&(inputValues[4]<0.2925061882)) rval+=-0.003035939103;   // importance = 0.067
   if ((0.03291572258<inputValues[5])) rval+=-0.002828989795;   // importance = 0.059
   if ((0.1040191874<inputValues[4])&&(0.0005389272701<inputValues[5])&&(inputValues[5]<0.02057173848)) rval+=-0.002560605697;   // importance = 0.052
   if ((0.1276836693<inputValues[3])&&(inputValues[4]<0.1211130992)) rval+=-0.00252114481;   // importance = 0.051
   if ((0.2514971793<inputValues[3])&&(inputValues[4]<0.3019230962)&&(inputValues[6]<0.01568512619)) rval+=-0.002169081298;   // importance = 0.040
   if ((0.2514971793<inputValues[3])&&(inputValues[4]<0.3019230962)&&(0.01568512619<inputValues[6])) rval+=-0.001779935718;   // importance = 0.031
   if ((0.1571474075<inputValues[3])&&(inputValues[3]<0.3729473352)&&(inputValues[4]<0.1497097164)&&(-0.005226526409<inputValues[6])) rval+=-0.001396089225;   // importance = 0.021
   if ((0.1277196109<inputValues[3])&&(inputValues[3]<0.2212251425)&&(inputValues[5]<-0.01936124265)) rval+=-0.00132392667;   // importance = 0.020
   if ((0.1571474075<inputValues[3])&&(inputValues[3]<0.3729473352)&&(inputValues[4]<0.1497097164)&&(inputValues[6]<-0.005226526409)) rval+=-0.001115387636;   // importance = 0.016
   if ((0.128816396<inputValues[3])&&(inputValues[5]<0.006777239498)&&(inputValues[6]<0.003479679348)) rval+=-0.001128235036;   // importance = 0.016
   if ((0.250333488<inputValues[3])&&(inputValues[5]<0.0200958997)&&(-0.01321679354<inputValues[6])&&(inputValues[6]<0.03778849915)) rval+=-0.001009863913;   // importance = 0.013
   if ((0.250333488<inputValues[3])&&(0.07545150071<inputValues[4])&&(-0.003491665237<inputValues[6])&&(inputValues[6]<0.03778849915)) rval+=-0.0008904329716;   // importance = 0.010
   if ((0.250333488<inputValues[3])&&(-0.003491665237<inputValues[6])&&(inputValues[6]<0.03778849915)) rval+=-0.0008904329716;   // importance = 0.010
   if ((inputValues[3]<0.06595552713)&&(inputValues[4]<0.2029623687)&&(inputValues[5]<-0.009382195771)) rval+=-0.0007443885434;   // importance = 0.008
   if ((0.1484051049<inputValues[3])&&(inputValues[4]<0.2029623687)&&(-0.005293515511<inputValues[5])&&(inputValues[5]<0.0003110108373)) rval+=-0.0003360481981;   // importance = 0.003
   //
   // here follows all linear terms
   // at the end of each line, the relative importance of the term is given
   //
   rval+=-5.307951851*std::min( double(0.9999999404), std::max( double(inputValues[0]), double(0.9868728518)));   // importance = 1.000
   rval+=-7.216873345*std::min( double(1), std::max( double(inputValues[1]), double(0.989949882)));   // importance = 1.000
   rval+=-0.01396326325*std::min( double(0.6202951074), std::max( double(inputValues[3]), double(0.01041585486)));   // importance = 0.156
   rval+=-0.01437809687*std::min( double(0.445571661), std::max( double(inputValues[4]), double(0.007975517772)));   // importance = 0.117
   return rval;
}
inline double ReadRuleFit::GetMvaValue( const std::vector<double>& inputValues ) const
{
   // classifier response value
   double retval = 0;

   // classifier response, sanity check first
   if (!IsStatusClean()) {
      std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                << " because status is dirty" << std::endl;
   }
   else {
         retval = GetMvaValue__( inputValues );
   }

   return retval;
}
