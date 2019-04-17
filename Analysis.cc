#include "pulse.hh"
#include "TH1.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TGraph.h"

using namespace std;
TFile *fout_;



void pulse::General(TString dirname="General")
{
  fout_->cd();
  TDirectory *gendir = fout_->mkdir(dirname.Data());
  gendir->cd();
  
  TH2D *hAmpMin = new TH2D("hAmpMin", "Minimum of waveforms", 36, -0.5, 35.5, 600, -1500, 1500); 
  TH2D *hAmpMax = new TH2D("hAmpMax", "Maximum of waveforms", 36, -0.5, 35.5, 600, -1500, 1500);
  TH2D *hTimeMin = new TH2D("hTimeMin", "Time of Minimum of waveforms", 36, -0.5, 35.5, 300, -50, 250); 
  TH2D *hTimeMax = new TH2D("hTimeMax", "Time of Maximum of waveforms", 36, -0.5, 35.5, 300, -50, 250);
  TH2D *hPedMean = new TH2D("hPedMean", "Mean value of pre-samples", 36, -0.5, 35.5, 600, -300, 300); 
  TH2D *hPedRMS = new TH2D("hPedRMS", "RMS  of pre-samples", 36, -0.5, 35.5, 500, 0, 50); 
  TProfile *hPulseAvg[36];
  for(int ich=0; ich<36; ich++){
    char hn[120];
    sprintf(hn,"hPulseAvg_%d",ich);
    hPulseAvg[ich] = new TProfile(hn,"Average pulse shape", 1000, 0, 200);
  }
  TH1D *hNtracks = new TH1D("hNtracks","Number of tracks",10, -0.5, 9.5);
  TH1D *hChi2 = new TH1D("hChi2","Tracks: log10(chi2)", 200, -2, 4);
  TH2D *hTracksXvsY = new TH2D("hTracksXvsY", "Track position X vs Y", 100, -10., 50., 100, -10., 50.);
  
  Long64_t nentries = fChain->GetEntries();
  Long64_t nbytes = 0, nb = 0;

  cout << " Running General" << endl;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    if (jentry % 100 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    hNtracks->Fill(ntracks);
    if(ntracks==1){
      if(chi2>1e-2){
	hChi2->Fill(log10(chi2));
	hTracksXvsY->Fill(xIntercept, yIntercept);
      }
    }
    
    for(int ich=0; ich<36; ich++){
      int group = ich / 9;
      double amin = 1e+9;
      double amax = -1e+9;
      double tmin = 0;
      double tmax = 0;
      for(int it=0; it<1024; it++){
	if(channel[ich][it] <= amin){
	  amin = channel[ich][it];
	  tmin = time[group][it];
	}
	if(channel[ich][it] >= amax){
	  amax = channel[ich][it];
	  tmax = time[group][it];
	}
	hPulseAvg[ich]->Fill(time[group][it], channel[ich][it]);
      }
      hAmpMin->Fill(ich, amin);
      hAmpMax->Fill(ich, amax);
      hTimeMin->Fill(ich, tmin);
      hTimeMax->Fill(ich, tmax);

      double sum0=0;
      double sum1=0;
      double sum2=0;
      for(int it=10; it<30; it++){
	sum0 += 1.;
	sum1 += channel[ich][it];
	sum2 += channel[ich][it] * channel[ich][it];
      }
      double avg = sum1 / sum0;
      double rms = sqrt( sum2 / sum0 - avg * avg );
      hPedMean->Fill(ich, avg);
      hPedRMS->Fill(ich, rms);
    }
  }
  gendir->cd();
  hAmpMin->Write();
  hAmpMax->Write();
  hTimeMin->Write();
  hTimeMax->Write();
  hPedMean->Write();
  hPedRMS->Write();
  for(int ich=0; ich<36; ich++){
    hPulseAvg[ich]->Write();
  }
  hNtracks->Write();
  hChi2->Write();
  hTracksXvsY->Write();
  fout_->cd();
}



void pulse::MCP(int ich, TString dirname="MCP")
{
  fout_->cd();
  TDirectory *mcpdir = fout_->mkdir(dirname.Data());
  mcpdir->cd();

  TH1D *hAmpMCP = new TH1D("hAmpMCP", "MCP amplitude", 1000, 0, 1500.);
  TH1D *hAmpMCP_1trk = new TH1D("hAmpMCP_1trk", "MCP amplitude for good tracks", 1000, 0, 1500.);
  TH1D *hTimeMCP_1trk = new TH1D("hTimeMCP_1trk", "MCP time", 1000, 0, 200.);
  TProfile2D *hAmpXvsY = new TProfile2D("hAmpXvsY", "Map of Average amplitude. Y vs X", 100, -10, 50, 100, -10, 50);
  TProfile2D *hEffXvsY = new TProfile2D("hEffXvsY", "MCP Efficiency. Y vs X", 100, -10, 50, 100, -10, 50);
  TProfile *hPulseMCP = new TProfile("hPulseMCP", "Average pulse shape of MCP", 1000, -50, 150);
  
  Long64_t nentries = fChain->GetEntries();
  Long64_t nbytes = 0, nb = 0;

  cout << "Running MCP" << endl;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    if (jentry % 100 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    int group = ich / 9;
    double amin = 1e+9;
    int imin = 0;
    double t0 = 0;
    for(int it=0; it<1024; it++){
      if(channel[ich][it] <= amin){
	amin = channel[ich][it];
	imin = it;
      }
    }
    amin *= -1.;
    hAmpMCP->Fill(amin);
    if(ntracks==1){
      hAmpMCP_1trk->Fill(amin);
      if(amin > 50.0 && amin < 400 && imin > 10 && imin < 900){
	hAmpXvsY->Fill(xIntercept, yIntercept, amin);
	hEffXvsY->Fill(xIntercept, yIntercept, 1.0);
	hTimeMCP_1trk->Fill(time[group][imin]);
	for(int it=0; it<1024; it++){
	  hPulseMCP->Fill(time[group][it] - time[group][imin], channel[ich][it]);
	}
      }else{
	hEffXvsY->Fill(xIntercept, yIntercept, 0.0);
      }
    }    
  }
  
  mcpdir->cd();
  hAmpMCP->Write();
  hAmpMCP_1trk->Write();
  hTimeMCP_1trk->Write();
  hAmpXvsY->Write();
  hEffXvsY->Write();
  hPulseMCP->Write();
  fout_->cd();
}



void pulse::Bar(int ich1hi, int ich2hi, int ich1lo, int ich2lo, double cut1, double cut2, TString dirname="Bar")
{
  fout_->cd();
  TDirectory *bardir = fout_->mkdir(dirname.Data());
  bardir->cd();

  TH2D *hAmpLo1vs2 = new TH2D("hAmpLo1vs2","Bar amplitude, Low gain, 1 vs 2", 200, 0, 1500, 200, 0, 1500);
  TH2D *hAmpLo1vs2_1trk = new TH2D("hAmpLo1vs2_1trk","Bar amplitude with 1 track, Low gain, 1 vs 2",
				   200, 0, 1500, 200, 0, 1500);
  TH1D *hAmpMCP = new TH1D("hAmpMCP", "MCP amplitude", 1000, 0, 1500.);
  TProfile2D *hAmp1LoXvsY = new TProfile2D("hAmp1LoXvsY", "Map of Average amplitude in 1. Y vs X", 100, -10, 50, 100, -10, 50);
  TProfile2D *hAmp2LoXvsY = new TProfile2D("hAmp2LoXvsY", "Map of Average amplitude in 2. Y vs X", 100, -10, 50, 100, -10, 50);
  TProfile2D *hEffLoXvsY = new TProfile2D("hEffLoXvsY", "Bar Efficiency. Y vs X", 100, -10, 50, 100, -10, 50);
  
  // Waveforms for good events
  const int nWFmax = 17;
  TGraph *grWF[5][nWFmax];
  for(int igr=0; igr<nWFmax; igr++){
    char grName[120];
    grWF[0][igr] = new TGraph();
    sprintf(grName,"grWF_MCP_%d", igr);
    grWF[0][igr]->SetName(grName);

    grWF[1][igr] = new TGraph();
    sprintf(grName,"grWF_ch1hi_%d", igr);
    grWF[1][igr]->SetName(grName);

    grWF[2][igr] = new TGraph();
    sprintf(grName,"grWF_ch2hi_%d", igr);
    grWF[2][igr]->SetName(grName);

    grWF[3][igr] = new TGraph();
    sprintf(grName,"grWF_ch1lo_%d", igr);
    grWF[3][igr]->SetName(grName);

    grWF[4][igr] = new TGraph();
    sprintf(grName,"grWF_ch2lo_%d", igr);
    grWF[4][igr]->SetName(grName);

  }
  int ngr = 0;

  
  Long64_t nentries = fChain->GetEntries();
  Long64_t nbytes = 0, nb = 0;

  cout << "Running Bar" << endl;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    if (jentry % 100 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    double amp1lo = 1e+9;
    for(int it=0; it<1024; it++){
      if(channel[ich1lo][it] <= amp1lo){
	amp1lo = channel[ich1lo][it];
      }
    }
    amp1lo *= -1.;
    
    double amp2lo = 1e+9;
    for(int it=0; it<1024; it++){
      if(channel[ich2lo][it] <= amp2lo){
	amp2lo = channel[ich2lo][it];
      }
    }
    amp2lo *= -1.;

    int ichMCP = (ich1hi / 9) * 9;
    double ampMCP = amp[ichMCP];
    
    hAmpLo1vs2->Fill(amp1lo, amp2lo);
    if(ntracks==1){
      hAmpLo1vs2_1trk->Fill(amp1lo, amp2lo);
      if(amp1lo > cut1 && amp2lo > cut2){
	hAmpMCP->Fill(ampMCP);
	hEffLoXvsY->Fill(xIntercept, yIntercept, 1.0);
	if(amp1lo < 850.){
	  hAmp1LoXvsY->Fill(xIntercept, yIntercept, amp1lo);
	}
	if(amp2lo < 850.){
	  hAmp2LoXvsY->Fill(xIntercept, yIntercept, amp2lo);
	}
	if(ngr<nWFmax){
	  int groupLo = ich1lo / 9;
	  int groupHi = ich1hi / 9;
	  for(int it=0; it<1024; it++){
	    grWF[0][ngr]->SetPoint(it, time[groupHi][it], channel[ichMCP][it]);
	    grWF[1][ngr]->SetPoint(it, time[groupHi][it], channel[ich1hi][it]);
	    grWF[2][ngr]->SetPoint(it, time[groupHi][it], channel[ich2hi][it]);
	    grWF[3][ngr]->SetPoint(it, time[groupLo][it], channel[ich1lo][it]);
	    grWF[4][ngr]->SetPoint(it, time[groupLo][it], channel[ich2lo][it]);
	  }
	  ngr++;
	}
      }else{
	hEffLoXvsY->Fill(xIntercept, yIntercept, 0.0);
      }
    }
  }
  bardir->cd();
  hAmpLo1vs2->Write();
  hAmpLo1vs2_1trk->Write();
  hAmpMCP->Write();
  hAmp1LoXvsY->Write();
  hAmp2LoXvsY->Write();
  hEffLoXvsY->Write();
  for(int igr=0; igr<std::min(nWFmax,ngr); igr++){
    grWF[0][igr]->Write();
    grWF[1][igr]->Write();
    grWF[2][igr]->Write();
    grWF[3][igr]->Write();
    grWF[4][igr]->Write();
  }
  fout_->cd();
}



void pulse::Analysis()
{  
  if (fChain == 0) return;
  fout_ = new TFile("output.root","recreate");

  pulse::General("General");  
  pulse::MCP(9, "MCP_HI");
  pulse::Bar(14, 15, 24, 25, 250., 500., "Bar_1");
  
  fout_->Close();
}










