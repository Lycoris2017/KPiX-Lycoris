	//-----------------------------------------------------------------------------
	// File          : analysis.cpp
	// Author        : Uwe Krämer (orig. Ryan Herbst) <uwe.kraemer@desy.de>
	// Created       : 06/28/2017
	// Project       : KPiX Analysis
	//-----------------------------------------------------------------------------
	// Description :
	// General analysis of KPiX data.
	//-----------------------------------------------------------------------------
	// Copyright (c) 2012 by SLAC. All rights reserved.
	// Proprietary and confidential to SLAC.
	//-----------------------------------------------------------------------------
	// Modification history :
	// 05/30/2012: created
	// 06/28/2017: large scale rewrite of original calibrationFitter.cpp
	//-----------------------------------------------------------------------------
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
	#include <TStyle.h>
	#include <TKey.h>
	#include <TClass.h>
	#include <stdarg.h>
	#include <KpixEvent.h>
	#include <KpixSample.h>
	#include <Data.h>
	#include <DataRead.h>
	#include <math.h>
	#include <fstream>
	#include <XmlVariables.h>
	#include <string.h>
	
	using namespace std;
	
	
	
	TH1F *summary1 = new TH1F("Pedestals", "Pedestals [ADC] ; Charge/ADC ; # entries", 9000, 0, 9000);
	TH1F *summary2 = new TH1F("Slope", "Slope [ADC/fC]; Charge/fC; Charge/ADC", 200, -100, 100);
	TH1F *summary3 = new TH1F("Intercept", "Intecept [ADC]", 2000, -1000, 1000);
	TH1F *summary4 = new TH1F("Pedestals", "Pedestals [fC]; Charge/fC; #entries", 1000, -100, 100);
	
	TH1F *summary11 = new TH1F("PedestalsRMS", "Pedestal RMS ; RMS/ADC ; # entries", 200, 0, 20);
	TH1F *summary111= new TH1F("PedestalRMS|AmplitudeCorrected", "Corrected Pedestal RMS ; RMS/ADC", 200, 0, 0.1);
	TH1F *summary12 = new TH1F("SlopeRMS", "Slope RMS ; Slope(ADC/fC)", 1000, 0, 20);
	TH1F *summary13 = new TH1F("InterceptRMS", "Intecept RMS", 1000, 0, 100);
	TH1F *summary14 = new TH1F("PedestalsRMS", "Pedestals RMS [fC]; Charge/fC ;# entries", 1000, 0, 10);
	
	TH1F *channel_entries= new TH1F("Channel entries", "Channel Entries; KPiX_channel_address; # entries", 1024, 0, 1024);
	TH1F *channel_entries_stamped= new TH1F("Channel entries stamped", "Channel Entries stamped; KPiX_channel_address; # entries", 1024, 0, 1024);
	
	TH1F *channel_entries_stamped_400= new TH1F("Channel entries stamped 400", "Channel Entries stamped 400; KPiX_channel_address; # entries", 1024, 0, 1024);
	TH1F *channel_entries_stamped_200= new TH1F("Channel entries stamped 200", "Channel Entries stamped 200; KPiX_channel_address; # entries", 1024, 0, 1024);
	TH1F *channel_entries_stamped_100= new TH1F("Channel entries stamped 100", "Channel Entries stamped 100; KPiX_channel_address; # entries", 1024, 0, 1024);
	TH1F *channel_entries_stamped_50= new TH1F("Channel entries stamped 50", "Channel Entries stamped 50; KPiX_channel_address; # entries", 1024, 0, 1024);
	TH1F *channel_entries_stamped_10= new TH1F("Channel entries stamped 10", "Channel Entries stamped 10; KPiX_channel_address; # entries", 1024, 0, 1024);
	
	TH1F *time_kpix= new TH1F("time kpix", "time kpix; Time/bunchClkCount; #entries", 300, 0, 8200);
	TH1F *time_kpix_selected= new TH1F("time kpix_selected", "time kpix_selected; Time/bunchClkCount; #entries", 300, 0, 8200);
	TH1F *time_external= new TH1F("time external", "time external; Time/bunchClkCount; #entries", 300, 0, 8200);
	
	TH1F *total= new TH1F("Total_response", "total_response; Charge/ADC; #entries", 300, 0, 8200);
	TH1F *total_stamped= new TH1F("Total_response_stamped", "total_response_stamped; Charge/ADC; #entries", 300, 0, 8200);
	
	TH1F *total_selected= new TH1F("Total_response_selected", "total_response_selected; Charge/ADC; #entries", 300, 0, 8200);
	TH1F *total_stamped_selected= new TH1F("Total_response_selected_stamped", "total_response_selected_stamped; Charge/ADC; #entries", 300, 0, 8200);
	
	TH1F *beam_ext_time_diff = new TH1F("beam_ext_time_diff", "beam_ext_time_diff; #Delta T/bunchClkCount; # entries", 17000, -8192, 8192);
	TH1F *beam_ext_time_diff_selected = new TH1F("beam_ext_time_diff_selected", "beam_ext_time_diff_selected; $#Delta$T/bunchClkCount; # entries", 17000, -8192, 8192);
	TH1F *beam_ext_time_diff_865 = new TH1F("beam_ext_time_diff_865", "beam_ext_time_diff_865; $#Delta$T/bunchClkCount; # entries", 17000, -8192, 8192);
	TH1F *beam_ext_time_diff_801 = new TH1F("beam_ext_time_diff_801", "beam_ext_time_diff_801; $#Delta$T/bunchClkCount; # entries", 17000, -8192, 8192);
	
	
	// Function to compute calibration charge
	
	
	void addDoubleToXml ( ofstream *xml, uint indent, string variable, Double_t value ) {
	uint x;
	
	//if ( ! isnan(value) ) {
	if( !(value != value) ){
		for (x=0; x < indent; x++) *xml << " ";
		*xml << "<" << variable << ">";
		*xml << value;
		*xml << "</" << variable << ">";
		*xml << endl;
	}
	}
	
	void addStringToXml ( ofstream *xml, uint indent, string variable, string value ) {
	uint x;
	
	for (x=0; x < indent; x++) *xml << " ";
	*xml << "<" << variable << ">";
	*xml << value;
	*xml << "</" << variable << ">";
	*xml << endl;
	}
	
	
	// Process the data
	int main ( int argc, char **argv ) 
	{
	DataRead               dataRead;
	off_t                  fileSize;
	off_t                  filePos;
	KpixEvent              event;
	KpixSample             *sample;
	
	string                 calState;
	uint                   lastPct;
	uint                   currPct;
	bool                   bucketFound[32][1024][4];
	bool                   chanFound[32][1024];
	bool                   kpixFound[32];
	uint                   minChan;
	uint                   maxChan;
	uint                   x;
	uint                   range;
	uint                   value;
	uint                   kpix;
	uint                   channel;
	uint                   bucket;
	double                  tstamp;
	string                 serial;
	KpixSample::SampleType type;
	TH1F                   	*hist[32][1024][4][2];
	TH1F					*hist_stamped[32][1024][4][2];
	TH1F					*channel_time[32][1024][4][2];
	stringstream           tmp;
	stringstream           tmp_units;
	
	stringstream           tmp2;
	stringstream           tmp2_units;
	
	stringstream           tmp3;
	stringstream           tmp3_units;
	
	ofstream               xml;
	ofstream               csv;
	uint                   eventCount;
	string                 outRoot;
	string                 outXml;
	string                 outCsv;
	TFile                  *rFile;
	TCanvas                *c1;
	stringstream           crossString;
	stringstream           crossStringCsv;
	XmlVariables           config;
	bool                   findBadMeanHist;
	bool                   findBadMeanFit;
	bool                   findBadMeanChisq;
	bool                   findBadGainFit;
	bool                   findBadGainChisq;
	double                 meanMin[2];
	double                 meanMax[2];
	double                 meanChisq;
	double                 gainMin[2];
	double                 gainMax[2];
	double                 chargeError[2];
	double                 gainChisq;
	double                 fitMin[2];
	double                 fitMax[2];
	ofstream               debug;
	ofstream				channel_file_bad;
	ofstream				channel_file_bad_fit;
	ofstream				channel_file_noise;
	ofstream				channel_file_calib;
	ofstream 				channel_file_adc_mean;
	uint                   badTimes;
	uint                   goodTimes;
	uint                   badMeanFitCnt;
	uint                   badMeanHistCnt;
	uint                   badMeanChisqCnt;
	uint                   badGainFitCnt;
	uint                   badGainChisqCnt;
	uint                   failedGainFit;
	uint                   failedMeanFit;
	uint                   badChannelCnt;
	uint					noiseSigmaCnt;
	uint                    errorSigmaCnt;
	double 					calib_slope[1024];
	double					calib_y0[1024];
	
	
	
	// Data file is the first and only arg
	if ( argc != 3 && argc != 4 ) {
		cout << "Usage: calibrationFitter config_file data_file [debug_file]\n";
		return(1);
	}
	
	//if ( argc == 4 ) debug.open(argv[3],ios::out | ios::trunc);
	bool calibration_check = 0;
	if ( argc == 4 ) calibration_check = 1;
	
	// Read configuration
	if ( ! config.parseFile("config",argv[1]) ) {
		cout << "Failed to read configuration from " << argv[1] << endl;
		return(1);
	}
	//Read root calibration file
	//if ( argc == 4 && ! calibration_file.is_open()) {
		//cout << "Failed to read calibration from " << argv[3] << endl;
		//return(1);
	//}
	
	// Extract configuration values
	findBadMeanHist  = config.getInt("FindBadMeanHist");
	findBadMeanFit   = config.getInt("FindBadMeanFit");
	meanMin[0]       = config.getDouble("GoodMeanMinR0");
	meanMax[0]       = config.getDouble("GoodMeanMaxR0");
	meanMin[1]       = config.getDouble("GoodMeanMinR1");
	meanMax[1]       = config.getDouble("GoodMeanMaxR1");
	findBadMeanChisq = config.getInt("FindBadMeanChisq");
	meanChisq        = config.getInt("GoodMeanChisqMax");
	findBadGainFit   = config.getInt("FindBadGainFit");
	gainMin[0]       = config.getDouble("GoodGainMinR0");
	gainMax[0]       = config.getDouble("GoodGainMaxR0");
	gainMin[1]       = config.getDouble("GoodGainMinR1");
	gainMax[1]       = config.getDouble("GoodGainMaxR1");
	findBadGainChisq = config.getInt("FindBadGainChisq");
	gainChisq        = config.getInt("GoodGainChisqMax");
	fitMin[0]        = config.getDouble("GainFitMinR0");
	fitMax[0]        = config.getDouble("GainFitMaxR0");
	fitMin[1]        = config.getDouble("GainFitMinR1");
	fitMax[1]        = config.getDouble("GainFitMaxR1");
	chargeError[0]   = config.getDouble("GainChargeErrorR0");
	chargeError[1]   = config.getDouble("GainChargeErrorR1");
	
	// Open data file
	if ( ! dataRead.open(argv[2])  ) {
		cout << "Error opening data file " << argv[2] << endl;
		return(1);
	}
	
	// Create output names
	tmp.str("");
	tmp << argv[2] << ".root";
	outRoot = tmp.str();
	tmp.str("");
	tmp << argv[2] << ".xml";
	outXml = tmp.str();
	tmp.str("");
	tmp << argv[2] << ".csv";
	outCsv = tmp.str();
	
	
	//Start of change
	if (argc == 4) 
	{
		TFile *calibration_file = TFile::Open(argv[3]);		
		TIter cal_iter(calibration_file->GetListOfKeys());
		TKey *cal_key;
		int count = 0;
		while ((cal_key = (TKey*)cal_iter())) 
		{
			//cout << "Current key1 = " << cal_key->GetClassName() << endl;
			string title = cal_key->GetTitle();
			if ((strcmp(cal_key->GetClassName(), "TGraphErrors") == 0) && (title.find("calib") != std::string::npos ))
			{
				//cout << "test" << endl;
				TGraphErrors *calib_graph = (TGraphErrors*)cal_key->ReadObj();
				calib_graph->Fit("pol1","eq","",fitMin[range],fitMax[range]);
				calib_slope[count] = calib_graph->GetFunction("pol1")->GetParameter(1);
				calib_y0[count] = calib_graph->GetFunction("pol1")->GetParameter(0);
				//cout << "Title: " << cal_key->GetTitle() << " with Slope = " << calib_slope[count] << endl;
				++count;
			}
		}
	}
	//end of change
	
	//////////////////////////////////////////
	// Read Data
	//////////////////////////////////////////
	cout << "Opened data file: " << argv[2] << endl;
	fileSize = dataRead.size();
	filePos  = dataRead.pos();
	
	// Init
	currPct          	= 0;
	lastPct          	= 100;
	eventCount       	= 0;
	minChan          	= 0;
	maxChan          	= 0;
	badTimes         	= 0;
	badMeanFitCnt    	= 0;
	badMeanHistCnt   	= 0;
	badMeanChisqCnt  	= 0;
	badGainFitCnt    	= 0;
	badGainChisqCnt 	= 0;
	failedGainFit   	= 0;
	failedMeanFit   	= 0;
	badChannelCnt   	= 0;
	noiseSigmaCnt		= 0;
	errorSigmaCnt		= 0;
	cout << "\rReading File: 0 %" << flush;
	goodTimes       	= 0;
	
	
	// Initialize all histograms
	//int count = 0;
	//while ( dataRead.next(&event) ) 
	//{
		//if (count < 10) 
		//{
		 //cout << "test" << endl;
		//}
		//count++;
	//}
	//dataRead.close();
	//cout << "DEEEEEEEEEEEEEEEEEBUUUUUUUUUUUUUUUUUUUUUG" << endl;
	//dataRead.open(argv[2]);
	//count = 0;
	//while ( dataRead.next(&event) ) 
	//{
		//if (count < 10) 
		//{
		 //cout << "test" << endl;
		//}
		//count++;
	//}
	
	// Default canvas
	c1 = new TCanvas("c1","c1");
	
	// Open root file
	rFile = new TFile(outRoot.c_str(),"recreate");
	
	while ( dataRead.next(&event) )
	{
		eventCount++;
		for (x=0; x < event.count(); x++) 
		{
	
			//// Get sample
			sample  = event.sample(x);
			kpix    = sample->getKpixAddress();
			channel = sample->getKpixChannel();
			bucket  = sample->getKpixBucket();
			if ( type == KpixSample::Data ) 
			{
				kpixFound[kpix]          = true;
				chanFound[kpix][channel] = true;
				bucketFound[kpix][channel][bucket] = true;
			}
		}
	}
	dataRead.close();
	dataRead.open(argv[2]);
	// initialization of histograms
	range = 0;
	for (kpix = 0; kpix < 32; kpix++)
	{
		//
		//cout << "DEBUG test " << kpixFound[kpix] << endl;
		if (kpixFound[kpix])
		{
			for (channel = 0; channel < 1024; channel++)
			{
				if (chanFound[kpix][channel])
				{
					for (bucket = 0; bucket < 4; bucket++)
					{
						if (bucketFound[kpix][channel][bucket])
						{
							tmp.str("");
							tmp << "hist" << "_c" << dec << setw(4) << setfill('0') << channel;
							tmp << "_b" << dec << bucket;
							tmp << "_k" << dec << kpix;
							
							tmp_units.str("");
							tmp_units << "hist" << "_c" << dec << setw(4) << setfill('0') << channel;
							tmp_units << "_b" << dec << bucket;
							tmp_units << "_k" << dec << kpix;
							tmp_units << "; Charge/ADC; #entries/#events";
						
							tmp2.str("");
							tmp2 << "hist_stamped" << "_c" << dec << setw(4) << setfill('0') << channel;
							tmp2 << "_b" << dec << bucket;
							tmp2 << "_k" << dec << kpix;
							tmp2 << "_time_cut";
								
							tmp2_units.str("");
							tmp2_units << "hist_stamped" << "_c" << dec << setw(4) << setfill('0') << channel;
							tmp2_units << "_b" << dec << bucket;
							tmp2_units << "_k" << dec << kpix;
							tmp2_units << "; Charge/ADC; #entries/#events";
						
							
							tmp3.str("");
							tmp3 << "time" << "_c" << dec << setw(4) << setfill('0') << channel;
							tmp3 << "_b" << dec << bucket;
							tmp3 << "_r" << dec << range;
							tmp3 << "_k" << dec << kpix;
							
							tmp3_units.str("");
							tmp3_units << "time" << "_c" << dec << setw(4) << setfill('0') << channel;
							tmp3_units << "_b" << dec << bucket;
							tmp3_units << "_k" << dec << kpix;
							tmp3_units << "; Time/bunchClkCount; #entries";
						
							
							hist[kpix][channel][bucket][0] = new TH1F(tmp.str().c_str(),tmp_units.str().c_str(),8192,0,8192);
							hist_stamped[kpix][channel][bucket][0] = new TH1F(tmp2.str().c_str(),tmp2_units.str().c_str(),8192,0,8192);
							channel_time[kpix][channel][bucket][0] = new TH1F(tmp3.str().c_str(),tmp3_units.str().c_str(),300,0,8192);
							
							
						}
					}
				}
			}
		}
	}
	
	//// Process each event
	while ( dataRead.next(&event) ) 
	{
		std::vector<double> time_ext;
		//// get each sample
		for (x=0; x < event.count(); x++) 
		{
	
			//// Get sample
			sample  = event.sample(x);
			kpix    = sample->getKpixAddress();
			channel = sample->getKpixChannel();
			bucket  = sample->getKpixBucket();
			value   = sample->getSampleValue();
			type    = sample->getSampleType();
			tstamp  = sample->getSampleTime();
			range   = sample->getSampleRange();
			
			
			
			if (type == 2)
			{
				double time = tstamp + double(value * 0.125);
				time_external->Fill(time);
				time_ext.push_back(time);
				//cout << "DEBUG: channel in timestmap = " << channel << endl;
				//cout << "DEBUG: bucket in timestmap = " << bucket << endl;
				
			}
			//if (type == 1)
			//{
				////cout << "DEBUG: Channel in temp = " << channel << endl;
				////cout << "DEBUG: value in temp = " << value << endl;
			//}
			
			if ( type == KpixSample::Data ) 
			{
				
				////if (channel != 491 && channel != 500 && channel != 501 && channel != 533 && channel != 532  && channel != 490 && channel != 522 && channel != 523)
				////{
					////// Create entry if it does not exist
					time_kpix->Fill(tstamp);
					////cout << "DEBUG: KPIX = " << kpix << endl;
					////cout << "DEBUG: channel = " << channel << endl;
					////cout << "DEBUG: bucket = " << bucket << endl;
					////cout << "[DEBUG1] " << hist[kpix][channel][bucket][0] << endl;
					//////cout << "[DEBUG2]" << hist_stamped[kpix][channel][bucket][range] << endl;
					//////cout << "[DEBUG1]" << eventCount << endl;
					//////cout << "[DEBUG1]" << double(value)/double(eventCount) << endl;
					
					hist[kpix][channel][bucket][0]->Fill(value,1.0/double(eventCount));
					channel_entries->Fill(channel);
					channel_time[kpix][channel][bucket][0]->Fill(tstamp);
					total->Fill(value);
					if (channel == 832 || channel == 801 || channel == 771 || channel == 772 || channel == 773 || channel == 774 || channel == 805 || channel == 837 || channel == 867 || channel == 866 || channel == 897 || channel == 928 || channel == 911 || channel == 879 || channel == 878 || channel == 846 || channel == 847 ||  channel == 833 || channel == 834 || channel == 835 || channel == 802 || channel == 803 || channel == 835 || channel == 865 || channel == 864)
					{
						total_selected->Fill(value);
						time_kpix_selected->Fill(tstamp);
						
					}
					double trig_diff = 8200.0;
					double trig_diff_selected = 8200.0;
					double trig_diff_865 = 8200.0;
					double trig_diff_801 = 8200.0;
					for (int j = 0; j < time_ext.size(); ++j)
					{
						//if(tstamp > time_ext.at(j) - 2 || tstamp < time_ext.at(j)+2)
						if (channel == 832 || channel == 801 || channel == 771 || channel == 772 || channel == 773 || channel == 774 || channel == 805 || channel == 837 || channel == 867 || channel == 866 || channel == 897 || channel == 928 || channel == 911 || channel == 879 || channel == 878 || channel == 846 || channel == 847 ||  channel == 833 || channel == 834 || channel == 835 || channel == 802 || channel == 803 || channel == 835 || channel == 865 || channel == 864)
						{
							if (trig_diff_selected >= fabs(tstamp-time_ext.at(j)))
							{
								trig_diff_selected = tstamp-time_ext.at(j);
								//cout << "[DEBUG] TSTAMP " << tstamp << endl;
								//cout << "[DEBUG] T_EXT " << time_ext.at(j) << endl;
								//cout << "[DEBUG] DIFF " << trig_diff_selected << endl;
							}
							
						}
						if (channel == 865)
						{
							if (trig_diff_865 >= fabs(tstamp-time_ext.at(j)))
							{
								trig_diff_865 = tstamp-time_ext.at(j);
								//cout << "[DEBUG] TSTAMP " << tstamp << endl;
								//cout << "[DEBUG] T_EXT " << time_ext.at(j) << endl;
								//cout << "[DEBUG] DIFF " << trig_diff_selected << endl;
							}
						}
						if (channel == 801)
						{
							if (trig_diff_801 >= fabs(tstamp-time_ext.at(j)))
							{
								trig_diff_801 = tstamp-time_ext.at(j);
								//cout << "[DEBUG] TSTAMP " << tstamp << endl;
								//cout << "[DEBUG] T_EXT " << time_ext.at(j) << endl;
								//cout << "[DEBUG] DIFF " << trig_diff_selected << endl;
							}
						}
						
						if (trig_diff >= fabs(tstamp-time_ext.at(j)))
						{	
								trig_diff = double(tstamp)-time_ext.at(j);
								//cout << "[DEBUG] TSTAMP " << tstamp << endl;
								//cout << "[DEBUG] T_EXT " << time_ext.at(j) << endl;
								//cout << "[DEBUG] DIFF " << trig_diff << endl;
						}
						
					}
					if((trig_diff >= 1 )  && (trig_diff  <= 2.65) ) //1 and 2.625
					{
						hist_stamped[kpix][channel][0][range]->Fill(value,1.0/double(eventCount));
						channel_entries_stamped->Fill(channel);
						total_stamped->Fill(value);
						if (channel == 832 || channel == 801 || channel == 771 || channel == 772 || channel == 773 || channel == 774 || channel == 805 || channel == 837 || channel == 867 || channel == 866 || channel == 897 || channel == 928 || channel == 911 || channel == 879 || channel == 878 || channel == 846 || channel == 847 ||  channel == 833 || channel == 834 || channel == 835 || channel == 802 || channel == 803 || channel == 835 || channel == 865 || channel == 864)
						{
							total_stamped_selected->Fill(value);
							
						}
					}
					if((trig_diff >= -200 )  && (trig_diff  <= 200) ) //1 and 2.625
					{
						channel_entries_stamped_200->Fill(channel);
					}
					if((trig_diff >= -400 )  && (trig_diff  <= 400) ) //1 and 2.625
					{
						channel_entries_stamped_400->Fill(channel);
					}
					if((trig_diff >= -100 )  && (trig_diff  <= 100) ) //1 and 2.625
					{
						channel_entries_stamped_100->Fill(channel);
					}
					if((trig_diff >= -50 )  && (trig_diff  <= 50) ) //1 and 2.625
					{
						channel_entries_stamped_50->Fill(channel);
					}
					if((trig_diff >= -10 )  && (trig_diff  <= 10) ) //1 and 2.625
					{
						channel_entries_stamped_10->Fill(channel);
					}
					
					
					if (channel == 832 || channel == 801 || channel == 771 || channel == 772 || channel == 773 || channel == 774 || channel == 805 || channel == 837 || channel == 867 || channel == 866 || channel == 897 || channel == 928 || channel == 911 || channel == 879 || channel == 878 || channel == 846 || channel == 847 ||  channel == 833 || channel == 834 || channel == 835 || channel == 802 || channel == 803 || channel == 835 || channel == 865 || channel == 864)
					{
						beam_ext_time_diff_selected->Fill(trig_diff_selected);
					}
					if (channel == 865)
					{
						beam_ext_time_diff_865->Fill(trig_diff_865);
					}
					if (channel == 801)
					{
						beam_ext_time_diff_801->Fill(trig_diff_801);
					}
					beam_ext_time_diff->Fill(trig_diff);
				//}
				
			}
		}
	  ////   Show progress
		filePos  = dataRead.pos();
		currPct = (uint)(((double)filePos / (double)fileSize) * 100.0);
		if ( currPct != lastPct ) 
		{
			cout << "\rReading File: " << currPct << " %      " << flush;
			lastPct = currPct;
		}
	}
	////// Writing of histograms
	//double first = (hist_calib->FindFirstBinAbove(0))* (2000.0/8192) -1;
	//double last = hist_calib->FindLastBinAbove(0)* (2000.0/8192) +1;
							
	//hist_calib->GetXaxis()->SetRangeUser(first, last);
	
	channel_entries->Write();
	channel_entries_stamped->Write();
	channel_entries_stamped_400->Write();
	channel_entries_stamped_200->Write();
	channel_entries_stamped_100->Write();
	channel_entries_stamped_50->Write();
	channel_entries_stamped_10->Write();
	
	time_external->Write();
	time_kpix->Write();
	time_kpix_selected->Write();
	total->Write();
	total_selected->Write();
	total_stamped->Write();
	total_stamped_selected->Write();
	beam_ext_time_diff_selected->Write();
	beam_ext_time_diff->Write();
	beam_ext_time_diff_865->Write();
	beam_ext_time_diff_801->Write();
    for (kpix = 0; kpix < 32; kpix++)
    {
		if (kpixFound[kpix])
		{
			for (channel = 0; channel < 1024; channel++)
			{
				if (chanFound[kpix][channel])
				{
					for (bucket = 0; bucket < 4; bucket++)
					{
						if (bucketFound[kpix][channel][bucket])
						{	
								hist[kpix][channel][bucket][0]->Write();
								hist_stamped[kpix][channel][bucket][0]->Write();
								channel_time[kpix][channel][bucket][0]->Write();
							
						}
					}
				}
			}
		}
	}
	cout << endl;
	cout << "Wrote root plots to " << outRoot << endl;
	cout << "Wrote xml data to " << outXml << endl;
	cout << "Wrote csv data to " << outCsv << endl;
	cout << endl;
	
	
	dataRead.close();
	return(0);
	}
