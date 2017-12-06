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


  TCanvas *c2 = new TCanvas("charge","Residual");
  TH1F *eHist = new TH1F("[PIXEL]","(e) buck0",100,-6,14);
  TH1F *fHist = new TH1F("[PIXEL]","(f) buck1-3",100,-6,14);
  TH1F *gHist = new TH1F("[PIXEL]","(g) buck0",100,0,10);
  TH1F *hHist = new TH1F("[PIXEL]","(h) buck1-3",100,0,10);
  
  //FILE *fin,*fout; void cosmicRead () {            
  FILE *fout;  

  TLine *t3= new TLine(0, 0, 2500, 0);

  TProfile *aPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
  TProfile *bPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
  TProfile *cPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
  TProfile *dPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
  TLine *t1= new TLine(0, 0, 500, 0);
  TLine *t2= new TLine(0, 0, 500, 0);
  /*
// For Run data of four KPiX_C (used 11/2014)
TH1F *aHist = new TH1F("[fC]","(a) Slope C0010",100,-1,24);
TH1F *bHist = new TH1F("[fC]","(b) Slope C0012",100,-1,24);
TH1F *cHist = new TH1F("[fC]","(c) Slope C0014",100,-1,24);
TH1F *dHist = new TH1F("[fC]","(d) Slope C0016",100,-1,24);
//TH1F *eHist = new TH1F("[PIXEL]","(e) C0010",1024,0,1024);
//TH1F *fHist = new TH1F("[PIXEL]","(f) C0012",1024,0,1024);
//TH1F *gHist = new TH1F("[PIXEL]","(g) C0014",1024,0,1024);
//TH1F *hHist = new TH1F("[PIXEL]","(h) C0016",1024,0,1024);
TH1F *iHist = new TH1F("[TIME]","(i) C0010",1100,700,1000);
TH1F *jHist = new TH1F("[TIME]","(j) C0012",1100,700,1000);
TH1F *kHist = new TH1F("[TIME]","(k) C0014",1100,700,1000);
TH1F *lHist = new TH1F("[TIME]","(l) C0016",1100,700,1000);
//TH1F *mHist = new TH1F("delta [fC]","(m) C0010",100,-5,5);
//TH1F *nHist = new TH1F("delta [fC]","(n) C0012",100,-5,5);
//TH1F *oHist = new TH1F("delta [fC]","(o) C0014",100,-5,5);
//TH1F *pHist = new TH1F("delta [fC]","(p) C0016",100,-5,5);
TH1F *mHist = new TH1F("delta [fC]","(m) C0010",100,0.1,1.1);
TH1F *nHist = new TH1F("delta [fC]","(n) C0012",100,0.1,1.1);
TH1F *oHist = new TH1F("delta [fC]","(o) C0014",100,0.1,1.1);
TH1F *pHist = new TH1F("delta [fC]","(p) C0016",100,0.1,1.1);
TH1F *qHist = new TH1F("[ped-RMS fC]","(q) C0010",100,0,0.5);
TH1F *rHist = new TH1F("[ped-RMS fC]","(r) C0012",100,0,0.5);
TH1F *sHist = new TH1F("[ped-RMS fC]","(s) C0014",100,0,0.5);
TH1F *tHist = new TH1F("[ped-RMS fC]","(t) C0016",100,0,0.5);
//TH1F *qHist = new TH1F("[ped-RMS fC]","(q) C0010",100,-10,10);
//TH1F *rHist = new TH1F("[ped-RMS fC]","(r) C0012",100,-10,10);
//TH1F *sHist = new TH1F("[ped-RMS fC]","(s) C0014",100,-10,10);
//TH1F *tHist = new TH1F("[ped-RMS fC]","(t) C0016",100,-10,10);
//TH1F *uHist = new TH1F("[ped fC]","(u) C0010",100,-1,1);
//TH1F *vHist = new TH1F("[ped fC]","(v) C0010",100,-1,1);
//TH1F *wHist = new TH1F("[ped fC]","(w) C0010",100,-1,1);
//TH1F *xHist = new TH1F("[ped fC]","(x) C0010",100,-1,1);
TH1F *uHist = new TH1F("[ped fC]","(u) C0010",100,590,610);
TH1F *vHist = new TH1F("[ped fC]","(v) C0012",100,595,615);
TH1F *wHist = new TH1F("[ped fC]","(w) C0014",100,630,650);
TH1F *xHist = new TH1F("[ped fC]","(x) C0016",100,585,605);

// For Pedestal Tests
//TH1F *aHist = new TH1F("[fC]","(a) Residuals First  Sensor",100,-5,5);
//TH1F *bHist = new TH1F("[fC]","(b) Residuals Second Sensor",100,-5,5);
//TH1F *cHist = new TH1F("[fC]","(c) Residuals Third  Sensor",100,-5,5);
//TH1F *dHist = new TH1F("[fC]","(d) Residuals Fourth Sensor",100,-5,5);
//TH1F *eHist = new TH1F("[ADC]","(e) Pedestals First  Sensor",100,0,400);
//TH1F *fHist = new TH1F("[ADC]","(f) Pedestals Second Sensor",100,0,400);
//TH1F *gHist = new TH1F("[ADC]","(g) Pedestals Third  Sensor",100,0,400);
//TH1F *hHist = new TH1F("[ADC]","(h) Pedestals Fourth Sensor",100,0,400);
////TH1F *eHist = new TH1F("[ADC]","(e) (Pedestals-old) First  Sensor",40,-20,20);
////TH1F *fHist = new TH1F("[ADC]","(f) (Pedestals-old) Second Sensor",40,-20,20);
////TH1F *gHist = new TH1F("[ADC]","(g) (Pedestals-old) Third  Sensor",40,-20,20);
////TH1F *hHist = new TH1F("[ADC]","(h) (Pedestals-old) Fourth Sensor",40,-20,20);
//TH1F *iHist = new TH1F("[fC]","(i) RMS First  Sensor",100,0,2);
//TH1F *jHist = new TH1F("[fC]","(j) RMS Second Sensor",100,0,2);
//TH1F *kHist = new TH1F("[fC]","(k) RMS Third  Sensor",100,0,2);
//TH1F *lHist = new TH1F("[fC]","(l) RMS Fourth Sensor",100,0,2);
////TH1F *aHist = new TH1F("[fC]","(a) Residuals First  Bucket",100,-1,1);
////TH1F *bHist = new TH1F("[fC]","(b) Residuals Second Bucket",100,-1,1);
////TH1F *cHist = new TH1F("[fC]","(c) Residuals Third  Bucket",100,-1,1);
////TH1F *dHist = new TH1F("[fC]","(d) Residuals Fourth Bucket",100,-1,1);
////TH1F *eHist = new TH1F("[ADC]","(e) Pedestals First  Bucket",100,0,400);
////TH1F *fHist = new TH1F("[ADC]","(f) Pedestals Second Bucket",100,0,400);
////TH1F *gHist = new TH1F("[ADC]","(g) Pedestals Third  Bucket",100,0,400);
////TH1F *hHist = new TH1F("[ADC]","(h) Pedestals Fourth Bucket",100,0,400);
////TH1F *iHist = new TH1F("[Bunch]","(i) Time First  Bucket",200,720,920);
////TH1F *jHist = new TH1F("[Bunch]","(j) Time Second Bucket",200,720,920);
////TH1F *kHist = new TH1F("[Bunch]","(k) Time Third  Bucket",200,720,920);
////TH1F *lHist = new TH1F("[Bunch]","(l) Time Fourth Bucket",200,720,920);
////TH1F *eHist = new TH1F("[fC]","(e) Fifth   Sensor",200,-10,10);
////TH1F *fHist = new TH1F("[fC]","(f) Sixth   Sensor",200,-10,10);
////TH1F *gHist = new TH1F("[fC]","(g) Seventh Sensor",200,-10,10);
////TH1F *hHist = new TH1F("[fC]","(h) Eighth  Sensor",200,-10,10);
////TH1F *iHist = new TH1F("[fC]","(i) Last    Sensor",200,-10,10);
*/ 
 int jk=0, idm=0, mnd=0, mxd=0, inc=0, llx=0, i=0, count=0, jst=0, gn=0, jnt=0, j=0, k=0, ida=0, n=0, l=0 ;
 unsigned int jtn=0, jtx=0, jtr=0, jtst=0, itrn=0;
 
 double x=0., y=0., z=0., rms=0.;
 double dac[256], dec[256]; 
 double dped[1024][4][3][30]; 
 double pdq[1024][4][3][30];
 int npq[1024][4][3][30]; 
 
 bool stat=false;
 
 char head[25][50];
 
 for (int a=0; a<256; a++ ) {
   dac[a]=0.;
   dec[a]=0.;
 }

 for (int a=0; a<1024; a++ ) {
   for (int b=0; b<4; b++ ) {
     for (int c=0; c<3; c++ ) {
       for (int d=0; d<30; d++ ) {
	 dped[a][b][c][d]=0.;
	 pdq[a][b][c][d]=0.;
	 npq[a][b][c][d]=0;
       }
     }
   }
 }


 gStyle->SetOptStat(111110);
 gStyle->SetOptFit(0011);
 gStyle->SetStatW(0.30);
 gStyle->SetStatH(0.15);
 aPlot->SetMarkerStyle(6);
 bPlot->SetMarkerStyle(6);
 cPlot->SetMarkerStyle(6);
 dPlot->SetMarkerStyle(6);
 fout=fopen("survey.txt","w");
 


//Calibration for DESY  set-up  

//times 5,000, 13,000, 14,000, 15,000, 500. def.ana=0.1V ramp=2.2
 
// strcpy(head[0],"/home/dtsionou/kpix/kpix_2016_04_18/data/2016_04_19_01_05_28.bin");
 strcpy(head[0],argv[2]);
 jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;
 
 
 // Nominal Calibration DAC charge.
 for(i=0;i<246;i++){
   dac[i]=500-2*i;
 } 
 for(i=246;i<256;i++){
   dac[i]=255-i;
 }
 
 for(jtr=0;jtr<jtx;jtr++){
   
   //Process base pedestals.
   DataRead *r=new DataRead;
   stat = r->open(head[jtr]);
   if(! stat){
     printf("pedestal file not found\n"); 
     fprintf(fout,"pedestal file not found\n");
   }
   printf("file = %d\n",jtr); 
   fprintf(fout,"file = %d\n",jtr);

   // Skip Events.
   jtst=0; 
   KpixEvent e; 
   KpixSample *s; 
   for(i=0;i<2;i++){
     r->next(&e);
   }

   while(r->next(&e)&&jtst<50) { //why for 100 events?
     count=e.count(); 
     itrn=e.eventNumber(); 
     jtst++;
     
     // Each trigger:
     i=0; 
     while(i<count){
       s=e.sample(i); 
       jst=s->getSampleType(); 
       gn=s->getSampleRange();
       jnt=s->getTrigType();    
       j=s->getKpixChannel(); 
       k=s->getKpixBucket();
       ida=s->getKpixAddress(); 
       x=s->getSampleValue(); 
       z=s->getSampleTime();
       
       //       printf(      "j=%5d k=%5d ida=%5d gn%3d x=%5.2f\n",j,k,ida,gn,x);
       //       fprintf(fout,"j=%5d k=%5d ida=%5d gn%3d x=%5.2f\n",j,k,ida,gn,x);
       
       // Produce Averages (dped) and variances (pdq) for each pixel, bucket, sensor.
       if(jst==0){
	 if(jtst==1){
	   dped[j][k][gn][ida]=0; 
	   npq[j][k][gn][ida]=0;
	 }
	 //here he averages out the pedestal and computes the rms for every new event added
	 y=x-dped[j][k][gn][ida]; 
	 n=npq[j][k][gn][ida]; 
	 dped[j][k][gn][ida]+=y/(n+1);
	 pdq[j][k][gn][ida]+=n*y*y/(n+1); 
	 npq[j][k][gn][ida]++;
	 rms = sqrt(pdq[j][k][gn][ida]);
       } 
       i++; 

       printf(      " itrn= %d j= %d x=%4.0f Pedestal=%4.0f RMS=%f\n",itrn,j,x,dped[j][k][gn][ida],rms);
       fprintf(fout," itrn= %d j= %d x=%4.0f Pedestal=%4.0f RMS=%f\n",itrn,j,x,dped[j][k][gn][ida],rms);
       //       printf(      " itrn= %d j= %d x=%4.0f Pedestal=%4.0f RMS=%f\n",itrn,j,x,dped[j][k][gn][ida],pdq[j][k][gn][ida]);
       //       fprintf(fout," itrn= %d j= %d x=%4.0f Pedestal=%4.0f RMS=%f\n",itrn,j,x,dped[j][k][gn][ida],pdq[j][k][gn][ida]);

     } // while(i<cout), end of block 
   } // while r, end of file 

   //   printf(      " itrn= %d count= %d Pedestal=%4.0f\n",itrn,count,dped[0][0][0][1]);
   //   fprintf(fout," itrn= %d count= %d Pedestal=%4.0f\n",itrn,count,dped[0][0][0][1]);
   //End base pedestals.
 
   /*   
   if(inc==1){
     llx=32; 
     for(l=0;l<9;l++){
       dec[l]=l;
     } 
     for(l=9;l<32;l++){
       dec[l]=4*l-26;
     }
   }

   if(inc==5){
     llx=27;
     dec[0]=0; 
     dec[1]=5; 
     for(l=2;l<9;l++){
       dec[l]=10*(l-1);
     }
     for(l=7;l<15;l++){
       dec[l]=20*(l-7)+60;
     }
     dec[15]=240; 
     dec[16]=280; 
     dec[17]=320; 
     dec[18]=360; 
     dec[19]=400;
     dec[20]=420; 
     dec[21]=440; 
     dec[22]=450; 
     dec[23]=470; 
     dec[24]=480; 
     dec[25]=490; 
     dec[26]=500;
   } // inc 
   
   if(inc==32){
     llx=9; 
     dec[0]=0; 
     for(l=1;l<llx;l++){
       dec[l]=64*l-12;
       printf(      "l=%2d dec=%4.0f\n",l,dec[l]);
       fprintf(fout,"l=%2d dec=%4.0f\n",l,dec[l]);
     }
   }
   */   
   
   delete r;
 }
 
 
 
 fclose(fout); 
 //c1->SaveAs("file.png"); 
 // c2->SaveAs("plot.png");

}

