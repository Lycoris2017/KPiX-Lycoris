#include <iostream>
#include <iomanip>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TMultiGraph.h>
#include <TApplication.h>
#include <TGraphErrors.h>
#include <TGraph.h>
#include <TLine.h>
#include <TProfile.h>
#include <TStyle.h>
#include <stdarg.h>
#include <KpixEvent.h>
#include <KpixSample.h>
#include <KpixCalibRead.h>
#include <Data.h>
#include <DataRead.h>
#include <math.h>
#include <fstream>
#include <XmlVariables.h>
using namespace std;


int main (int argc, char **argv) { 
  
  XmlVariables           config;
  ofstream               debug;
  DataRead               dataRead;
  off_t                  fileSize;
  off_t                  filePos;
  KpixEvent              event;
  KpixSample             *sample;
  KpixSample::SampleType type;
  
  // Data file is the first and only arg
  if ( argc != 3 && argc != 4 ) {
    cout << "Usage: cosmicRead_compiled config_file data_file [debug_file]\n";
    return(1);
  }
  
  if ( argc == 4 ) debug.open(argv[3],ios::out | ios::trunc);
  
  // Read configuration
  if ( ! config.parseFile("config",argv[1]) ) {
    cout << "Failed to read configuration from " << argv[1] << endl;
    return(1);
  }
  
  // Open data file
  if ( ! dataRead.open(argv[2]) ) {
    cout << "Error opening data file " << argv[2] << endl;
    return(1);
  }
  
  /*
    TCanvas *c2 = new TCanvas("charge","Residual");
    TH1F *eHist = new TH1F("[PIXEL]","(e) buck0",100,-6,14);
    TH1F *fHist = new TH1F("[PIXEL]","(f) buck1-3",100,-6,14);
    TH1F *gHist = new TH1F("[PIXEL]","(g) buck0",100,0,10);
    TH1F *hHist = new TH1F("[PIXEL]","(h) buck1-3",100,0,10);
  */
  //FILE *fin,*fout; void cosmicRead () {            
  //  FILE *fout;  
  
  uint kpix=0, channel=0, bucket=0, range=0, x=0, value=0, tstamp=0;
  
  uint chan[32][1024][4][2];

  for (kpix=0; kpix < 32; kpix++) {
    for (channel=0; channel < 1024; channel++) {
      for (bucket=0; bucket < 4; bucket++) {
	chan[kpix][channel][bucket][0] = NULL;
	chan[kpix][channel][bucket][1] = NULL;
      }
    }
  }
  
  //////////////////////////////////////////
  // Read Data
  //////////////////////////////////////////
  cout << "Opened data file: " << argv[2] << endl;
  fileSize = dataRead.size();
  filePos  = dataRead.pos();
  cout << "\rReading File: 0 %" << flush;
  
  // Process each event
  while ( dataRead.next(&event) ) {
    
    // get each sample
    for (x=0; x < event.count(); x++) {
      
      // Get sample
      sample  = event.sample(x);
      kpix    = sample->getKpixAddress();
      channel = sample->getKpixChannel();
      bucket  = sample->getKpixBucket();
      value   = sample->getSampleValue();
      type    = sample->getSampleType();
      tstamp  = sample->getSampleTime();
      range   = sample->getSampleRange();
      
      chan[kpix][channel][bucket][range] = value;
      
      std::cout<<"Event "<<x<<" : kpix "<<kpix<<" channel "<<channel<<" bucket "<<bucket<<" range "<<range<<" . Value = "<<value<<std::endl;

    } // for loop on event count
  } // while for next event
  
}

