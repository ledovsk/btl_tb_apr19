//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 16 13:04:02 2019 by ROOT version 6.14/06
// from TTree pulse/Digitized waveforms
// found on file: ../data/DataVMETiming_Run1287.root
//////////////////////////////////////////////////////////

#ifndef pulse_h
#define pulse_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>

// Header file for the classes stored in the TTree if any.

class pulse {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          i_evt;
   Float_t         channel[36][1024];
   Float_t         time[4][1024];
   Float_t         baseline[36];
   Float_t         baseline_RMS[36];
   Float_t         noise[36];
   Float_t         amp[36];
   Float_t         t_peak[36];
   Float_t         integral[36];
   Float_t         intfull[36];
   Float_t         risetime[36];
   Float_t         decaytime[36];
   Float_t         IL_10[36];
   Float_t         IL_20[36];
   Float_t         IL_30[36];
   Float_t         IL_50[36];
   Float_t         IL_10mV[36];
   Float_t         IL_20mV[36];
   Float_t         IL_30mV[36];
   Float_t         IL_50mV[36];
   Float_t         IL_70mV[36];
   Float_t         IL_90mV[36];
   Float_t         IL_100mV[36];
   Float_t         IL_120mV[36];
   Float_t         IL_140mV[36];
   Float_t         IL_160mV[36];
   Float_t         IL_180mV[36];
   Float_t         IL_200mV[36];
   Float_t         LP1_10[36];
   Float_t         LP1_20[36];
   Float_t         LP1_30[36];
   Float_t         LP1_50[36];
   Float_t         LP1_10mV[36];
   Float_t         LP1_20mV[36];
   Float_t         LP1_30mV[36];
   Float_t         LP1_50mV[36];
   Float_t         LP1_70mV[36];
   Float_t         LP1_90mV[36];
   Float_t         LP1_100mV[36];
   Float_t         LP1_120mV[36];
   Float_t         LP1_140mV[36];
   Float_t         LP1_160mV[36];
   Float_t         LP1_180mV[36];
   Float_t         LP1_200mV[36];
   Float_t         LP2_10[36];
   Float_t         LP2_20[36];
   Float_t         LP2_30[36];
   Float_t         LP2_50[36];
   Float_t         LP2_10mV[36];
   Float_t         LP2_20mV[36];
   Float_t         LP2_30mV[36];
   Float_t         LP2_50mV[36];
   Float_t         LP2_70mV[36];
   Float_t         LP2_90mV[36];
   Float_t         LP2_100mV[36];
   Float_t         LP2_120mV[36];
   Float_t         LP2_140mV[36];
   Float_t         LP2_160mV[36];
   Float_t         LP2_180mV[36];
   Float_t         LP2_200mV[36];
   Float_t         gaus_mean[36];
   Float_t         gaus_sigma[36];
   Float_t         gaus_chi2[36];
   Int_t           triggerNumber;
   UShort_t        corruption;
   Float_t         xIntercept;
   Float_t         yIntercept;
   Float_t         xSlope;
   Float_t         ySlope;
   Float_t         x_dut[4];
   Float_t         y_dut[4];
   Float_t         chi2;
   Int_t           ntracks;

   // List of branches
   TBranch        *b_i_evt;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_time;   //!
   TBranch        *b_baseline;   //!
   TBranch        *b_baseline_RMS;   //!
   TBranch        *b_noise;   //!
   TBranch        *b_amp;   //!
   TBranch        *b_t_peak;   //!
   TBranch        *b_integral;   //!
   TBranch        *b_intfull;   //!
   TBranch        *b_risetime;   //!
   TBranch        *b_decaytime;   //!
   TBranch        *b_IL_10;   //!
   TBranch        *b_IL_20;   //!
   TBranch        *b_IL_30;   //!
   TBranch        *b_IL_50;   //!
   TBranch        *b_IL_10mV;   //!
   TBranch        *b_IL_20mV;   //!
   TBranch        *b_IL_30mV;   //!
   TBranch        *b_IL_50mV;   //!
   TBranch        *b_IL_70mV;   //!
   TBranch        *b_IL_90mV;   //!
   TBranch        *b_IL_100mV;   //!
   TBranch        *b_IL_120mV;   //!
   TBranch        *b_IL_140mV;   //!
   TBranch        *b_IL_160mV;   //!
   TBranch        *b_IL_180mV;   //!
   TBranch        *b_IL_200mV;   //!
   TBranch        *b_LP1_10;   //!
   TBranch        *b_LP1_20;   //!
   TBranch        *b_LP1_30;   //!
   TBranch        *b_LP1_50;   //!
   TBranch        *b_LP1_10mV;   //!
   TBranch        *b_LP1_20mV;   //!
   TBranch        *b_LP1_30mV;   //!
   TBranch        *b_LP1_50mV;   //!
   TBranch        *b_LP1_70mV;   //!
   TBranch        *b_LP1_90mV;   //!
   TBranch        *b_LP1_100mV;   //!
   TBranch        *b_LP1_120mV;   //!
   TBranch        *b_LP1_140mV;   //!
   TBranch        *b_LP1_160mV;   //!
   TBranch        *b_LP1_180mV;   //!
   TBranch        *b_LP1_200mV;   //!
   TBranch        *b_LP2_10;   //!
   TBranch        *b_LP2_20;   //!
   TBranch        *b_LP2_30;   //!
   TBranch        *b_LP2_50;   //!
   TBranch        *b_LP2_10mV;   //!
   TBranch        *b_LP2_20mV;   //!
   TBranch        *b_LP2_30mV;   //!
   TBranch        *b_LP2_50mV;   //!
   TBranch        *b_LP2_70mV;   //!
   TBranch        *b_LP2_90mV;   //!
   TBranch        *b_LP2_100mV;   //!
   TBranch        *b_LP2_120mV;   //!
   TBranch        *b_LP2_140mV;   //!
   TBranch        *b_LP2_160mV;   //!
   TBranch        *b_LP2_180mV;   //!
   TBranch        *b_LP2_200mV;   //!
   TBranch        *b_gaus_mean;   //!
   TBranch        *b_gaus_sigma;   //!
   TBranch        *b_gaus_chi2;   //!
   TBranch        *b_triggerNumber;   //!
   TBranch        *b_corruption;   //!
   TBranch        *b_xIntercept;   //!
   TBranch        *b_yIntercept;   //!
   TBranch        *b_xSlope;   //!
   TBranch        *b_ySlope;   //!
   TBranch        *b_x_dut;   //!
   TBranch        *b_y_dut;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_ntracks;   //!

   pulse(TTree *tree=0);
   virtual ~pulse();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   void Analysis();
   void General(TString);
   void MCP(int, TString);
   void Bar(int, int, int, int, double, double, TString);
};

#endif

#ifdef pulse_cxx
pulse::pulse(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../data/DataVMETiming_Run1287.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../data/DataVMETiming_Run1287.root");
      }
      f->GetObject("pulse",tree);

   }
   Init(tree);
}

pulse::~pulse()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t pulse::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t pulse::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void pulse::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("i_evt", &i_evt, &b_i_evt);
   fChain->SetBranchAddress("channel", channel, &b_channel);
   fChain->SetBranchAddress("time", time, &b_time);
   fChain->SetBranchAddress("baseline", baseline, &b_baseline);
   fChain->SetBranchAddress("baseline_RMS", baseline_RMS, &b_baseline_RMS);
   fChain->SetBranchAddress("noise", noise, &b_noise);
   fChain->SetBranchAddress("amp", amp, &b_amp);
   fChain->SetBranchAddress("t_peak", t_peak, &b_t_peak);
   fChain->SetBranchAddress("integral", integral, &b_integral);
   fChain->SetBranchAddress("intfull", intfull, &b_intfull);
   fChain->SetBranchAddress("risetime", risetime, &b_risetime);
   fChain->SetBranchAddress("decaytime", decaytime, &b_decaytime);
   fChain->SetBranchAddress("IL_10", IL_10, &b_IL_10);
   fChain->SetBranchAddress("IL_20", IL_20, &b_IL_20);
   fChain->SetBranchAddress("IL_30", IL_30, &b_IL_30);
   fChain->SetBranchAddress("IL_50", IL_50, &b_IL_50);
   fChain->SetBranchAddress("IL_10mV", IL_10mV, &b_IL_10mV);
   fChain->SetBranchAddress("IL_20mV", IL_20mV, &b_IL_20mV);
   fChain->SetBranchAddress("IL_30mV", IL_30mV, &b_IL_30mV);
   fChain->SetBranchAddress("IL_50mV", IL_50mV, &b_IL_50mV);
   fChain->SetBranchAddress("IL_70mV", IL_70mV, &b_IL_70mV);
   fChain->SetBranchAddress("IL_90mV", IL_90mV, &b_IL_90mV);
   fChain->SetBranchAddress("IL_100mV", IL_100mV, &b_IL_100mV);
   fChain->SetBranchAddress("IL_120mV", IL_120mV, &b_IL_120mV);
   fChain->SetBranchAddress("IL_140mV", IL_140mV, &b_IL_140mV);
   fChain->SetBranchAddress("IL_160mV", IL_160mV, &b_IL_160mV);
   fChain->SetBranchAddress("IL_180mV", IL_180mV, &b_IL_180mV);
   fChain->SetBranchAddress("IL_200mV", IL_200mV, &b_IL_200mV);
   fChain->SetBranchAddress("LP1_10", LP1_10, &b_LP1_10);
   fChain->SetBranchAddress("LP1_20", LP1_20, &b_LP1_20);
   fChain->SetBranchAddress("LP1_30", LP1_30, &b_LP1_30);
   fChain->SetBranchAddress("LP1_50", LP1_50, &b_LP1_50);
   fChain->SetBranchAddress("LP1_10mV", LP1_10mV, &b_LP1_10mV);
   fChain->SetBranchAddress("LP1_20mV", LP1_20mV, &b_LP1_20mV);
   fChain->SetBranchAddress("LP1_30mV", LP1_30mV, &b_LP1_30mV);
   fChain->SetBranchAddress("LP1_50mV", LP1_50mV, &b_LP1_50mV);
   fChain->SetBranchAddress("LP1_70mV", LP1_70mV, &b_LP1_70mV);
   fChain->SetBranchAddress("LP1_90mV", LP1_90mV, &b_LP1_90mV);
   fChain->SetBranchAddress("LP1_100mV", LP1_100mV, &b_LP1_100mV);
   fChain->SetBranchAddress("LP1_120mV", LP1_120mV, &b_LP1_120mV);
   fChain->SetBranchAddress("LP1_140mV", LP1_140mV, &b_LP1_140mV);
   fChain->SetBranchAddress("LP1_160mV", LP1_160mV, &b_LP1_160mV);
   fChain->SetBranchAddress("LP1_180mV", LP1_180mV, &b_LP1_180mV);
   fChain->SetBranchAddress("LP1_200mV", LP1_200mV, &b_LP1_200mV);
   fChain->SetBranchAddress("LP2_10", LP2_10, &b_LP2_10);
   fChain->SetBranchAddress("LP2_20", LP2_20, &b_LP2_20);
   fChain->SetBranchAddress("LP2_30", LP2_30, &b_LP2_30);
   fChain->SetBranchAddress("LP2_50", LP2_50, &b_LP2_50);
   fChain->SetBranchAddress("LP2_10mV", LP2_10mV, &b_LP2_10mV);
   fChain->SetBranchAddress("LP2_20mV", LP2_20mV, &b_LP2_20mV);
   fChain->SetBranchAddress("LP2_30mV", LP2_30mV, &b_LP2_30mV);
   fChain->SetBranchAddress("LP2_50mV", LP2_50mV, &b_LP2_50mV);
   fChain->SetBranchAddress("LP2_70mV", LP2_70mV, &b_LP2_70mV);
   fChain->SetBranchAddress("LP2_90mV", LP2_90mV, &b_LP2_90mV);
   fChain->SetBranchAddress("LP2_100mV", LP2_100mV, &b_LP2_100mV);
   fChain->SetBranchAddress("LP2_120mV", LP2_120mV, &b_LP2_120mV);
   fChain->SetBranchAddress("LP2_140mV", LP2_140mV, &b_LP2_140mV);
   fChain->SetBranchAddress("LP2_160mV", LP2_160mV, &b_LP2_160mV);
   fChain->SetBranchAddress("LP2_180mV", LP2_180mV, &b_LP2_180mV);
   fChain->SetBranchAddress("LP2_200mV", LP2_200mV, &b_LP2_200mV);
   fChain->SetBranchAddress("gaus_mean", gaus_mean, &b_gaus_mean);
   fChain->SetBranchAddress("gaus_sigma", gaus_sigma, &b_gaus_sigma);
   fChain->SetBranchAddress("gaus_chi2", gaus_chi2, &b_gaus_chi2);
   fChain->SetBranchAddress("triggerNumber", &triggerNumber, &b_triggerNumber);
   fChain->SetBranchAddress("corruption", &corruption, &b_corruption);
   fChain->SetBranchAddress("xIntercept", &xIntercept, &b_xIntercept);
   fChain->SetBranchAddress("yIntercept", &yIntercept, &b_yIntercept);
   fChain->SetBranchAddress("xSlope", &xSlope, &b_xSlope);
   fChain->SetBranchAddress("ySlope", &ySlope, &b_ySlope);
   fChain->SetBranchAddress("x_dut", x_dut, &b_x_dut);
   fChain->SetBranchAddress("y_dut", y_dut, &b_y_dut);
   fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
   fChain->SetBranchAddress("ntracks", &ntracks, &b_ntracks);
   Notify();
}

Bool_t pulse::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void pulse::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t pulse::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef pulse_cxx
