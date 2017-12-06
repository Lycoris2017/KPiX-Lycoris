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


 double a[1024][30],aa[1024][30],slp[1024][4][3][30],xlp[1024][4][3][30],xds[1024][30],
   sig,slpn,slpo,ofs[1024][4][3][30],rms,rsq[1024][4][30],ybb[1024][4][3][30][50],
   dox[4],dm[4],aon=0,son=0,ank[4],snk[4][3],yyv[1024][4][30],
   zmx[4][30],qmz[4][30],qav[4][25],qsq[4][25],pav[4][25],psq[4][25],
   slx[1024][4][30],sly[1024][4][30],ped[1024][4][3][30][25],cped[1024][4][3][30],dped[1024][4][3][30],
   pdq[1024][4][3][30][25],xyv[1024][4][30],xxv[1024][4][30],x2v[1024][4][30],peq[1024][4],
   q[2048][4][30],qq[1024][4],xav[1024][4],yav[200],rep[1024][4][30],x1y1[1024][30],
   xsq[1024][4],itm[1024][4],ktm[1024][4][30][25],xmx[30],ysm[30],yyy[30],tomp[1024],
   u,w,x,y,z,
   //         v,x,z,uu,uv,uw,vv,ww,xx,zz,sxy,sx2,m0,m1,m2,o0,o1,o2,s0,s1,s2,ss1,ss2,ss3,tt1,tt2,tt3,
   sy1[1024][30],ssx2[1024][30],bbb,cc0,cc1,yy0,yy1,
   xs,ztm,tav,tmp,xdc[1024][4],vtp[200],amx=1.0,fer,
   dac[256],dec[256],umx[256][4],dll[25];
 

   //         dif,an,sn,xsm,wsm,wsms,wsx,wsq,wsqs,wqx,zsm,slc[4],xof[4],xtm,ytm[10],ymx,ymn,
  int ida,gn=0,i,j,k,l,m,n,i0,i1,i2,i3,i13,ii,iskp,jj,count,jb,jc,jh,jn=1024,jk=4,isv,
    lls,jsp, llx,
    //    jfl,kfl,jsp,jsv,idr,ids,jdr,jds,ksv,lsv,msv, nlo,ndd,nhi,nq,nr,nsn,nsv,nsw,
    mmv[1024][30],nnv[1024][4][30],gmn,gmx,mn,ct,cv,jm,ks,idm,ite,ipt,kpt,npt,nsm,irh,jrh,
    ibt[30],jbt[30],kbt[30],lbt[30],l0,l1,l2,l3,l4,l5,l6,l7,l8,lj,ivv[30],jv[30],kv[30],mv[30],ntc[30],
    mer=0,ib[1024],ic[1024],iee[1024][4][3][30],ih[1024][4],iz[1024][30],
    o[1024][30],oo[1024][30],jav[1024][4],kda[30],lda[30],mda[30],nda[30],kav[200],mar[200][10],
    ncl[30],jcl[100][30],nn[1024],nav[4][25],nsq[4][25],nmz[4][30],ny[30],nz[30],
    ct0,ct1,ct3,ct4,ct5,ktrn=-1,jnt,jst,jtm,wrg,jmx,jdatp=1,jpix,jbu=0,jx,ctsh,
    nix,lix[500],tnp,jdead[1024],//lmx[4096],ntr,ntt,ntu,ntw,nl,
    mnd,mxd,inc,
    tbp[1024][30],tbc[1024][30],tbd[1024][30],npq[1024][4][3][30][25],nmx[256][4];

  unsigned int ibad,jbad,adc,adv[1024][4],ia[1026][66],irp[1024][4][30];//,ibl=0,krp;
  unsigned int cnt, jtn, jtx, jtr,jtst, itrn; 
    //      cwg=0,wct=0,jft,ktn,ktx,
    //  sm=0,itrfst,itxe,itxsv,zct,jal,jsh,jne,jeq,jgo,nm,irw=0,wqt=0;

  bool stat;

  char srl[30][6],head[25][50];

gStyle->SetOptStat(111110);
gStyle->SetOptFit(0011);
gStyle->SetStatW(0.30);
gStyle->SetStatH(0.15);
aPlot->SetMarkerStyle(6);
bPlot->SetMarkerStyle(6);
cPlot->SetMarkerStyle(6);
dPlot->SetMarkerStyle(6);
fout=fopen("survey.txt","w");

 for(i=0;i<10;i++){
   nn[i]=0;
 }

for (k=0;k<200;k++){
  ib[k]=0; 
  vtp[k]=0; 
  yav[k]=0; 
  kav[k]=0; 
  for(i=0;i<10;i++){
    mar[k][i]=0;
  }
 }

for(i=0;i<1026;i++){
  for(k=0;k<66;k++){
    ia[i][k]=0;
  }
 }

for(j=0;j<jn;j++){
  for(l=0;l<30;l++){
    xds[j][l]=0;
  }
 }

for(j=0;j<jn;j++){
  ib[j]=0; 
  ic[j]=1; 
  jdead[j]=-1; 
  tomp[j]=0;
  for(k=0;k<jk;k++){
    xav[j][k]=0; 
    xsq[j][k]=0; 
    peq[j][k]=0; 
    jav[j][k]=0; 
    // tbp[j][k+3]=-1;
    for(l=0;l<30;l++){
      irp[j][k][l]=0; 
      rep[j][k][l]=0; 
      nnv[j][k][l]=0;
      yyv[j][k][l]=0; 
      xyv[j][k][l]=0; 
      xxv[j][k][l]=0; 
      x2v[j][k][l]=0;
    }
  }
 }

for(l=0;l<30;l++){
  lda[l]=-1;
 }
for(l=1;l<5;l++){
  lda[l]=l;
 } 
 
 i0=1; i1=2; i2=3; i3=4; // seensors 1-4 only 
//lda[10]=10; lda[12]=12; lda[14]=14; lda[16]=16; i0=10; i1=12; i2=14; i3=16;
//i0=11; i1=13; i2=15; i3=17; // old slot assignment 


//Process Calibration File gn=0 (normal), 1 (low), 2 (high gain). skip ite=-1.
 jk=1; gmn=0; gmx=1; ite=-1; 
 if(ite<=1){
   strcpy(srl[0],"1015"); 
   strcpy(srl[1],"1012"); 
   strcpy(srl[2],"1013");
   strcpy(srl[3],"1011"); 
   strcpy(srl[4],"1016"); 
   strcpy(srl[5],"1017"); 
   strcpy(srl[6],"1018"); 
   strcpy(srl[7],"1019"); 
   strcpy(srl[8],"1022"); 
   strcpy(srl[9],"-1"); 
   strcpy(srl[10],"C0012"); 
   strcpy(srl[11],"C0012");
   strcpy(srl[12],"C0014"); 
   strcpy(srl[13],"C0014"); 
   strcpy(srl[14],"C0013"); 
   strcpy(srl[15],"C0013"); 
   strcpy(srl[16],"C0011"); 
   strcpy(srl[17],"C0011"); 
   // special plots for survey: jsp=2.
   jsp=0;
   
   // strcpy(srl[0],"1011");  strcpy(srl[1],"1013"); 
   // strcpy(srl[2],"1012");  strcpy(srl[3],"1015"); 
   // strcpy(srl[0],"1002");
   
   //   KpixSample *s; 
   KpixCalibRead *c=new KpixCalibRead; 
   irh=0;
   // irh=1 for Ryans's calibration.

   //  cal13 CALDAC 200-255,step 1, high gain.
   //strcpy(head[2],"/u1/kpix/data/2014_10_29_12_31_54.bin.xml"); idm=17; irh=1; gmn=0; gmx=1;
   gmx=0; // skip xml-calibration files. 
   
   // Process calibration data ++++++
   for(gn=gmn;gn<gmx;gn++){
     c->parse(head[gn]); 
     ibad=0;
     
     for(ida=0;ida<idm;ida++){
       if (lda[ida]==-1) continue; 
       jbad=0;
       //printf(      "ida=%2d lda=%2d\n",ida,lda[ida]);
       //fprintf(fout,"ida=%2d lda=%2d\n",ida,lda[ida]);
       
       xs=1; 
       if (gn==1) xs=2; 
       if (gn==2) xs=.05;
       for(k=0;k<jk;k++){
	 snk[k][gn]=0; 
	 n=0; 
	 for(j=0;j<jn;j++){
	   
	   // x   = c->baseFitMean(srl[ida],j,k,gn);
	   // sig = c->baseFitSigma(srl[ida],j,k,gn);
	   u= c->baseMean(srl[ida],j,k,gn);
	   w= c->calibIntercept(srl[ida],j,k,gn);
	   rms= c->baseRms(srl[ida],j,k,gn);
	   y= c->calibGain(srl[ida],j,k,gn);
	   fer= c->calibGainErr(srl[ida],j,k,gn);
	   if (irh==1) {
	     jrh=c->badChannel(srl[ida],j);
	   }
	   
	   if (y!=0) { 
	     y=y/1e15;
	   } 
	   
	   slp[j][k][gn][ida]=y; 
	   xlp[j][k][gn][ida]=y;
	   dped[j][k][gn][ida]=u; 
	   cped[j][k][gn][ida]=w;

	   if(y!=0){
	     printf(      "j=%5d k=%5d ida=%5d gn%3d y=%5.2f\n",j,k,ida,gn,y);
	     fprintf(fout,"j=%5d k=%5d ida=%5d gn%3d y=%5.2f\n",j,k,ida,gn,y);}
	   
	   if (y>0) {
	     fer=(fer*1e-13)/y;
	   } 
	   else {
	     fer=.395;
	   }

	   
	   if ( (irh==0&&(fer<0.001||y<0.1) ) || ( irh==1&&(jrh!=0||y<=0 ) ) ) {
	     iee[j][k][gn][ida]=0;
	   }
	   else {
	     iee[j][k][gn][ida]=1;
	   } 

	   for(l=1;l<4;l++){
	     iee[j][l][gn][ida]=iee[j][0][gn][ida];
	   }

	   if(iee[j][k][gn][ida]==0){
	     ibad++; 
	     jbad++;
	   }


	   cnt++;
	 } /* j */

	 printf(" ida=%2d jbad=%5d\n",ida,jbad); fprintf(fout," ida=%2d jbad=%5d\n",ida,jbad);
	 
	 if(n>0){
	   snk[k][gn]/=n; 
	   printf(" k=%3d n=%5d snk=%8.3f\n",k,n,snk[k][gn]);
	   fprintf(fout," k=%3d n=%5d snk=%8.3f\n",k,n,snk[k][gn]);
	 }
	 
       } /* k */
     } /* ida */

     printf(" ibad_gn_%d=%5d\n\n",gn,ibad); 
     fprintf(fout," ibad_gn_%d=%5d\n\n",gn,ibad);
   }/* gn */ 

   delete c;
   
 }/* end ite */

// END Calibration data.


//Calibration for DESY  set-up  

//times 5,000, 13,000, 14,000, 15,000, 500. def.ana=0.1V ramp=2.2
 
 strcpy(head[0],"/home/dtsionou/kpix/kpix_2016_04_18/data/2016_02_18_12_21_58.bin");
// strcpy(head[0],argv[1]);
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

   while(r->next(&e)&&jtst<100) {
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
       
       printf(      "j=%5d k=%5d ida=%5d gn%3d x=%5.2f\n",j,k,ida,gn,x);
       fprintf(fout,"j=%5d k=%5d ida=%5d gn%3d x=%5.2f\n",j,k,ida,gn,x);
       
       // Produce Averages (dped) and variances (pdq) for each pixel, bucket, sensor.
       if(jst==0){
	 if(jtst==1){
	   dped[j][k][gn][ida]=0; 
	   npq[j][k][gn][ida][jtr]=0;
	 }
	 y=x-dped[j][k][gn][ida]; 
	 n=npq[j][k][gn][ida][jtr]; 
	 dped[j][k][gn][ida]+=y/(n+1);
	 pdq[j][k][gn][ida][jtr]+=n*y*y/(n+1); 
	 npq[j][k][gn][ida][jtr]++;
       } 
       i++; }  /* while(i<cout), end of block */ 
   } /* while r, end of file */

   //printf(      " itrn= %d count= %d Pedestal=%4.0f\n",itrn,count,dped[0][0][0][1]);
   //fprintf(fout," itrn= %d count= %d Pedestal=%4.0f\n",itrn,count,dped[0][0][0][1]);
   //End base pedestals.

   
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
   } /* inc */
   
   if(inc==32){
     llx=9; 
     dec[0]=0; 
     for(l=1;l<llx;l++){
       dec[l]=64*l-12;
       printf(      "l=%2d dec=%4.0f\n",l,dec[l]);
       fprintf(fout,"l=%2d dec=%4.0f\n",l,dec[l]);
     }
   }
   
   
   delete r;
 }
 
 
 
 fclose(fout); 
 /*c1->SaveAs("file.png");*/ 
 c2->SaveAs("plot.png");
}

