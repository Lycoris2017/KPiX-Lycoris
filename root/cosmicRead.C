FILE *fin,*fout; void cosmicRead () {                                   /*07/25/12*/
// kinit
// cd kpix_new
// source setup_env.csh
// root_kpix
// .X cosmicRead.C
// ps2pdf file.ps

// For Scatter Plots.
//TH2F *aPlot = new TH2F("[fC]","[fC]",110,0,110,160,0,160);
//TH2F *bPlot = new TH2F("[fC]","[fC]",110,0,110,120,-1,12);
//TH2F *cPlot = new TH2F("[fC]","[fC]",110,0,110,150,-1.5,1.5);
//TH2F *dPlot = new TH2F("[fC]","[fC]",110,0,110,150,-0.2,0.4);
//TLine *t1= new TLine(0, 0, 110, 110);
//TLine *t2= new TLine(0, 0, 110, 0);
//TH2F *aPlot = new TH2F("[fC]","[fC]",100,0,500,100,0,700);
//TH2F *bPlot = new TH2F("[fC]","[fC]",100,0,500,100,-10,50);
//TH2F *cPlot = new TH2F("[fC]","[fC]",100,0,500,150,-5,5);
//TH2F *dPlot = new TH2F("[fC]","[fC]",100,0,500,100,-0.2,0.4);

TCanvas *c2 = new TCanvas("charge","Residual");
TH1F *eHist = new TH1F("[PIXEL]","(e) buck0",100,-6,14);
TH1F *fHist = new TH1F("[PIXEL]","(f) buck1-3",100,-6,14);
TH1F *gHist = new TH1F("[PIXEL]","(g) buck0",100,0,10);
TH1F *hHist = new TH1F("[PIXEL]","(h) buck1-3",100,0,10);

// For Scatter Plots.
//TH2F *aPlot = new TH2F("[fC]","[fC]",160,0,160,100,-2,2);
//TH2F *bPlot = new TH2F("[fC]","[fC]",160,0,160,100,-2,2);
//TH2F *cPlot = new TH2F("[fC]","[fC]",160,0,160,100,-2,2);
//TH2F *dPlot = new TH2F("[fC]","[fC]",160,0,160,100,-2,2);
//TLine *t1= new TLine(0, 0, 100, 0);
//TLine *t2= new TLine(0, 0, 100, 0);

//TH2F *aPlot = new TH2F("[fC]","[fC]",100,0,800,100,-10,10);
//TH2F *bPlot = new TH2F("[fC]","[fC]",100,0,800,100,-10,10);
//TH2F *cPlot = new TH2F("[fC]","[fC]",100,0,800,100,-10,10);
//TH2F *dPlot = new TH2F("[fC]","[fC]",100,0,800,100,-10,10);
//TLine *t1= new TLine(0, 0, 500, 0);
//TLine *t2= new TLine(0, 0, 500, 0);

//TProfile *aPlot = new TProfile("[fC]","Data [fC]",100,0,200,0,200);
//TProfile *bPlot = new TProfile("[fC]","Residuals [fC]",100,0,200,-50,0);
//TProfile *cPlot = new TProfile("[fC]","Exponential component in Wilkinson [fC]",100,0,200,-5,5);
//TProfile *dPlot = new TProfile("[fC]","Fractional Deviation of Wilkinson current",100,0,2500,-0.2,0.4);
//TLine *t1= new TLine(0, 0, 150, 150);
//TLine *t2= new TLine(0, 0, 150, 0);
 
TLine *t3= new TLine(0, 0, 2500, 0);

TProfile *aPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
TProfile *bPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
TProfile *cPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
TProfile *dPlot = new TProfile("[fC]","Residuals [fC]",100,0,800,-50,50);
TLine *t1= new TLine(0, 0, 500, 0);
TLine *t2= new TLine(0, 0, 500, 0);

//TProfile *aPlot = new TProfile("[fC]","Residuals [fC]",160,0,160,-50,50);
//TProfile *bPlot = new TProfile("[fC]","Residuals [fC]",160,0,160,-50,50);
//TProfile *cPlot = new TProfile("[fC]","Residuals [fC]",160,0,160,-50,50);
//TProfile *dPlot = new TProfile("[fC]","Residuals [fC]",160,0,160,-50,50);
//TLine *t1= new TLine(0, 0, 100, 0);
//TLine *t2= new TLine(0, 0, 100, 0);

//TProfile *aPlot = new TProfile("[fC]","Data [fC]",100,0,600,0,700);
//TProfile *bPlot = new TProfile("[fC]","Residuals [fC]",100,0,600,-50,50);
//TProfile *cPlot = new TProfile("[fC]","Exponential component in Wilkinson [fC]",100,0,600,-5,5);
//TProfile *dPlot = new TProfile("[fC]","Fractional Deviation of Wilkinson current",100,0,2500,-0.2,0.4);
//TLine *t1= new TLine(0, 0, 500, 500);
//TLine *t1= new TLine(0, 0, 500, 0);
//TLine *t2= new TLine(0, 0, 500, 0);

// For Cosmics
//TH1F *aHist = new TH1F("[n]","(a) Multiplicity Sensor_0",100,700,800);
//TH1F *bHist = new TH1F("[n]","(b) Multiplicity Sensor_1",100,700,800);
//TH1F *cHist = new TH1F("[n]","(c) Multiplicity Sensor_2",100,700,800);
//TH1F *dHist = new TH1F("[n]","(d) Multiplicity Sensor_3",100,700,800);
//TH1F *eHist = new TH1F("[n]","(e) Multiplicity Sensor_4",100,700,800);
//TH1F *fHist = new TH1F("[n]","(f) Multiplicity Sensor_5",100,700,800);
//TH1F *gHist = new TH1F("[n]","(g) Multiplicity Sensor_6",100,700,800);
//TH1F *hHist = new TH1F("[n]","(h) Multiplicity Sensor_7",100,700,800);
//TH1F *iHist = new TH1F("[n]","(i) Multiplicity Sensor_8",100,700,800);

//TH1F *aHist = new TH1F("[n]","(a) Multiplicity Sensor_0",20,0,20);
//TH1F *bHist = new TH1F("[n]","(b) Multiplicity Sensor_1",20,0,20);
//TH1F *cHist = new TH1F("[n]","(c) Multiplicity Sensor_2",20,0,20);
//TH1F *dHist = new TH1F("[n]","(d) Multiplicity Sensor_3",20,0,20);
//TH1F *eHist = new TH1F("[n]","(e) Multiplicity Sensor_4",100,0,100);
//TH1F *fHist = new TH1F("[n]","(f) Multiplicity Sensor_5",100,0,100);
//TH1F *gHist = new TH1F("[n]","(g) Multiplicity Sensor_6",100,0,100);
//TH1F *hHist = new TH1F("[n]","(h) Multiplicity Sensor_7",100,0,100);
//TH1F *iHist = new TH1F("[n]","(i) Multiplicity Sensor_8",100,0,100);

// For analysis of four KPiX_C:
//TH1F *aHist = new TH1F("[ADC]","(a) C0012 buck. 0",100,0,5);
//TH1F *bHist = new TH1F("[ADC]","(b) C0012 buck. 1",100,0,5);
//TH1F *cHist = new TH1F("[ADC]","(c) C0012 buck. 2",100,0,5);
//TH1F *dHist = new TH1F("[ADC]","(d) C0012 buck. 3",100,0,5);
//TH1F *eHist = new TH1F("[ADC]","(e) C0014 buck. 0",100,0,5);
//TH1F *fHist = new TH1F("[ADC]","(f) C0014 buck. 1",100,0,5);
//TH1F *gHist = new TH1F("[ADC]","(g) C0014 buck. 2",100,0,5);
//TH1F *hHist = new TH1F("[ADC]","(h) C0014 buck. 3",100,0,5);
//TH1F *iHist = new TH1F("[ADC]","(i) C0013 buck. 0",100,0,5);
//TH1F *jHist = new TH1F("[ADC]","(j) C0013 buck. 1",100,0,5);
//TH1F *kHist = new TH1F("[ADC]","(k) C0013 buck. 2",100,0,5);
//TH1F *lHist = new TH1F("[ADC]","(l) C0013 buck. 3",100,0,5);
//TH1F *mHist = new TH1F("[ADC]","(m) C0011 buck. 0",100,0,5);
//TH1F *nHist = new TH1F("[ADC]","(n) C0011 buck. 1",100,0,5);
//TH1F *oHist = new TH1F("[ADC]","(o) C0011 buck. 2",100,0,5);
//TH1F *pHist = new TH1F("[ADC]","(p) C0011 buck. 3",100,0,5);

// For Calibration stack of thirteen. (last use 8/2014)
////TH1F *aHist = new TH1F("[ADC]","(a) Pedestals low G. A1015",100,-100,900);
//TH1F *aHist = new TH1F("[ADC]","(a) Pedestals low G. A1015",100,0,50);
//TH1F *bHist = new TH1F("[ADC]","(b) Pedestals low G. A1012",100,-100,900);
//TH1F *cHist = new TH1F("[ADC]","(c) Pedestals low G. A1013",100,-100,900);
//TH1F *dHist = new TH1F("[ADC]","(d) Pedestals low G. A1011",100,-100,900);
//TH1F *eHist = new TH1F("[ADC]","(e) Pedestals norm. G. A1015",100,-100,1900);
//TH1F *fHist = new TH1F("[ADC]","(f) Pedestals norm. G. A1012",100,-100,1900);
//TH1F *gHist = new TH1F("[ADC]","(g) Pedestals norm. G. A1013",100,-100,1900);
//TH1F *hHist = new TH1F("[ADC]","(h) Pedestals norm. G. A1011",100,-100,1900);
////TH1F *eHist = new TH1F("[ADC]","(e) Pedestals norm. G. A1015",100,0,10);
////TH1F *fHist = new TH1F("[ADC]","(f) Pedestals norm. G. A1012",100,0,10);
////TH1F *gHist = new TH1F("[ADC]","(g) Pedestals norm. G. A1013",100,0,10);
////TH1F *hHist = new TH1F("[ADC]","(h) Pedestals norm. G. A1011",100,0,10);
//TH1F *iHist = new TH1F("[ADC/fC]","(i) Slope low G. A1015",100,0,1);
//TH1F *jHist = new TH1F("[ADC/fC]","(j) Slope low G. A1012",100,0,1);
//TH1F *kHist = new TH1F("[ADC/fC]","(k) Slope low G. A1013",100,0,1);
//TH1F *lHist = new TH1F("[ADC/fC]","(l) Slope low G. A1011",100,0,1);
//TH1F *mHist = new TH1F("[ADC/fC]","(m) Slope norm. G. A1015",110,0,22);
//TH1F *nHist = new TH1F("[ADC/fC]","(n) Slope norm. G. A1012",110,0,22);
//TH1F *oHist = new TH1F("[ADC/fC]","(o) Slope norm. G. A1013",110,0,22);
//TH1F *pHist = new TH1F("[ADC/fC]","(p) Slope norm. G. A1011",110,0,22);
//TH1F *qHist = new TH1F("[norm/low G]","(q) Ratio Slopes A1015",100,-100,900);
//TH1F *rHist = new TH1F("[norm/low G]","(r) Ratio Slopes A1012",100,-100,900);
//TH1F *sHist = new TH1F("[norm/low G]","(s) Ratio Slopes A1013",100,-100,900);
//TH1F *tHist = new TH1F("[norm/low G]","(t) Ratio Slopes A1011",100,-100,900);
//TH1F *uHist = new TH1F("[norm/low G]","(u) Ratio Slopes A1015",100,-100,100);
//TH1F *vHist = new TH1F("[norm/low G]","(v) Ratio Slopes A1012",100,-100,100);
//TH1F *wHist = new TH1F("[norm/low G]","(w) Ratio Slopes A1013",100,-100,100);

// For Calibration stack of four KPiX_C (used 11/2014)
////TH1F *aHist = new TH1F("[ADC/fC]","(a) Slope C0010",100,0,25);
////TH1F *bHist = new TH1F("[ADC/fC]","(b) Slope C0012",100,0,25);
////TH1F *cHist = new TH1F("[ADC/fC]","(c) Slope C0014",100,0,25);
////TH1F *dHist = new TH1F("[ADC/fC]","(d) Slope C0016",100,0,25);
//TH1F *aHist = new TH1F("[ADC/fC]","(a) Slope C0010",100,0,5);
//TH1F *bHist = new TH1F("[ADC/fC]","(b) Slope C0012",100,0,5);
//TH1F *cHist = new TH1F("[ADC/fC]","(c) Slope C0014",100,0,5);
//TH1F *dHist = new TH1F("[ADC/fC]","(d) Slope C0016",100,0,5);
//TH1F *eHist = new TH1F("[Curv.%]","(e) C0010",100,-5,5);
//TH1F *fHist = new TH1F("[Curv.%]","(f) C0012",100,-5,5);
//TH1F *gHist = new TH1F("[Curv.%]","(g) C0014",100,-5,5);
//TH1F *hHist = new TH1F("[Curv.%]","(h) C0016",100,-5,5);
//TH1F *iHist = new TH1F("[RMS fC]","(i) C0010",100,0,1.0);
//TH1F *jHist = new TH1F("[RMS fC]","(j) C0012",100,0,1.0);
//TH1F *kHist = new TH1F("[RMS fC]","(k) C0014",100,0,1.0);
//TH1F *lHist = new TH1F("[RMS fC]","(l) C0016",100,0,1.0);
//TH1F *mHist = new TH1F("delta [fC]","(m) C0010",100,-1,4);
//TH1F *nHist = new TH1F("delta [fC]","(n) C0012",100,-1,4);
//TH1F *oHist = new TH1F("delta [fC]","(o) C0014",100,-1,4);
//TH1F *pHist = new TH1F("delta [fC]","(p) C0016",100,-1,4);
//TH1F *qHist = new TH1F("[ped-RMS fC]","(q) C0010",100,0,.5);
//TH1F *rHist = new TH1F("[ped-RMS fC]","(r) C0010",100,0,.5);
//TH1F *sHist = new TH1F("[ped-RMS fC]","(s) C0010",100,0,.5);
//TH1F *tHist = new TH1F("[ped-RMS fC]","(t) C0010",100,0,.5);
////TH1F *qHist = new TH1F("[ped-RMS fC]","(q) C0010",100,-10,10);
////TH1F *rHist = new TH1F("[ped-RMS fC]","(r) C0010",100,-10,10);
////TH1F *sHist = new TH1F("[ped-RMS fC]","(s) C0010",100,-10,10);
////TH1F *tHist = new TH1F("[ped-RMS fC]","(t) C0010",100,-10,10);
////TH1F *uHist = new TH1F("[ped fC]","(u) C0010",100,-1,1);
////TH1F *vHist = new TH1F("[ped fC]","(v) C0010",100,-1,1);
////TH1F *wHist = new TH1F("[ped fC]","(w) C0010",100,-1,1);
////TH1F *xHist = new TH1F("[ped fC]","(x) C0010",100,-1,1);
//TH1F *uHist = new TH1F("[ped fC]","(u) C0010",100,590,610);
//TH1F *vHist = new TH1F("[ped fC]","(v) C0010",100,595,615);
//TH1F *wHist = new TH1F("[ped fC]","(w) C0010",100,630,650);
//TH1F *xHist = new TH1F("[ped fC]","(x) C0010",100,585,605);

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

//TH1F *aHist = new TH1F("[ADC]","(a) Pedestals low G. C0012",100,-500,500);
//TH1F *bHist = new TH1F("[ADC]","(b) Pedestals low G. C0014",100,-500,500);
//TH1F *cHist = new TH1F("[ADC]","(c) Pedestals low G. C0013",100,-500,500);
//TH1F *dHist = new TH1F("[ADC]","(d) Pedestals low G. C0011",100,-500,500);
//TH1F *eHist = new TH1F("[ADC]","(e) Pedestals norm. G. C0012",100,-500,500);
//TH1F *fHist = new TH1F("[ADC]","(f) Pedestals norm. G. C0014",100,-500,500);
//TH1F *gHist = new TH1F("[ADC]","(g) Pedestals norm. G. C0013",100,-500,500);
//TH1F *hHist = new TH1F("[ADC]","(h) Pedestals norm. G. C0011",100,-500,500);
//TH1F *iHist = new TH1F("[ADC/fC]","(i) Slope low G. C0012",100,0,1);
//TH1F *jHist = new TH1F("[ADC/fC]","(j) Slope low G. C0014",100,0,1);
//TH1F *kHist = new TH1F("[ADC/fC]","(k) Slope low G. C0013",100,0,1);
//TH1F *lHist = new TH1F("[ADC/fC]","(l) Slope low G. C0011",100,0,1);
//TH1F *mHist = new TH1F("[ADC/fC]","(m) Slope norm. G. C0012",110,0,22);
//TH1F *nHist = new TH1F("[ADC/fC]","(n) Slope norm. G. C0014",110,0,22);
//TH1F *oHist = new TH1F("[ADC/fC]","(o) Slope norm. G. C0013",110,0,22);
//TH1F *pHist = new TH1F("[ADC/fC]","(p) Slope norm. G. C0011",110,0,22);
//TH1F *qHist = new TH1F("[norm/low G]","(q) Ratio Slopes C0012",100,21,23);
//TH1F *rHist = new TH1F("[norm/low G]","(r) Ratio Slopes C0014",100,21,23);
//TH1F *sHist = new TH1F("[norm/low G]","(s) Ratio Slopes C0013",100,21,23);
//TH1F *tHist = new TH1F("[norm/low G]","(t) Ratio Slopes C0011",100,21,23);

// For RMS in Calibration stack of nine.
//TH1F *aHist = new TH1F("[fC]","(a) First   Sensor",100,0,0.5);
//TH1F *bHist = new TH1F("[fC]","(b) Second  Sensor",100,0,0.5);
//TH1F *cHist = new TH1F("[fC]","(c) Third   Sensor",100,0,0.5);
//TH1F *dHist = new TH1F("[fC]","(d) Fourth  Sensor",100,0,0.5);
//TH1F *eHist = new TH1F("[fC]","(e) Fifth   Sensor",100,0,0.5);
//TH1F *fHist = new TH1F("[fC]","(f) Sixth   Sensor",100,0,0.5);
//TH1F *gHist = new TH1F("[fC]","(g) Seventh Sensor",100,0,0.5);
//TH1F *hHist = new TH1F("[fC]","(h) Eighth  Sensor",100,0,0.5);
//TH1F *iHist = new TH1F("[fC]","(i) Last    Sensor",100,0,0.5);

//TH1F *mHist = new TH1F("[fC]","(m) First   Sensor",100,0,.5);
//TH1F *nHist = new TH1F("[fC]","(n) Second  Sensor",100,0,.5);
//TH1F *oHist = new TH1F("[fC]","(o) Third   Sensor",100,0,.5);
//TH1F *pHist = new TH1F("[fC]","(p) Fourth  Sensor",100,0,.5);
//TH1F *qHist = new TH1F("[fC]","(q) Fifth   Sensor",100,0,.5);
//TH1F *rHist = new TH1F("[fC]","(r) Sixth   Sensor",100,0,.5);
//TH1F *sHist = new TH1F("[fC]","(s) Seventh Sensor",100,0,.5);
//TH1F *tHist = new TH1F("[fC]","(t) Eighth  Sensor",100,0,.5);
//TH1F *lHist = new TH1F("[fC]","(l) Last    Sensor",100,0,.5);

// For run with 4.4 pC excitation.
//TH1F *aHist = new TH1F("[fC]","(a) First  Sensor all pix.",150,3500,5000);
//TH1F *bHist = new TH1F("[fC]","(b) Second Sensor all pix.",150,3500,5000);
//TH1F *cHist = new TH1F("[fC]","(c) Third  Sensor all pix.",150,3500,5000);
//TH1F *dHist = new TH1F("[fC]","(d) Fourth Sensor all pix.",150,3500,5000);
////TH1F *eHist = new TH1F("[fC]","(e) First   Sensor pix_0",200,4000,5000);
////TH1F *fHist = new TH1F("[fC]","(f) Second  Sensor pix_0",200,4000,5000);
////TH1F *gHist = new TH1F("[fC]","(g) Third   Sensor pix_0",200,4000,5000);
////TH1F *hHist = new TH1F("[fC]","(h) Fourth  Sensor pix_0",200,4000,5000);
//TH1F *eHist = new TH1F("[fC]","(e) RMS First  Sensor all pix.",100,0,100);
//TH1F *fHist = new TH1F("[fC]","(f) RMS Second Sensor all pix.",100,0,100);
//TH1F *gHist = new TH1F("[fC]","(g) RMS Third  Sensor all pix.",100,0,100);
//TH1F *hHist = new TH1F("[fC]","(h) RMS Fourth Sensor all pix.",100,0,100);
////TH1F *eHist = new TH1F("[n]","(e) Fifth   Sensor",100,3100,3900);
////TH1F *fHist = new TH1F("[n]","(f) Sixth   Sensor",100,3100,3900);
////TH1F *gHist = new TH1F("[n]","(g) Seventh Sensor",100,3100,3900);
////TH1F *hHist = new TH1F("[n]","(h) Eighth  Sensor",100,3100,3900);
////TH1F *iHist = new TH1F("[n]","(i) Last    Sensor",100,3100,3900);
//TH1F *mHist = new TH1F("[fC]","(m) RMS First  Sensor all pix.",100,0,100);
//TH1F *nHist = new TH1F("[fC]","(n) RMS Second Sensor all pix.",100,0,100);
//TH1F *oHist = new TH1F("[fC]","(o) RMS Third  Sensor all pix.",100,0,100);
//TH1F *pHist = new TH1F("[fC]","(p) RMS Fourth Sensor all pix.",100,0,100);
//TH1F *qHist = new TH1F("[fC]","(q) RMS First  Sensor all pix.",100,0,100);
//TH1F *rHist = new TH1F("[fC]","(r) RMS Second Sensor all pix.",100,0,100);
//TH1F *sHist = new TH1F("[fC]","(s) RMS Third  Sensor all pix.",100,0,100);
//TH1F *tHist = new TH1F("[fC]","(t) RMS Fourth Sensor all pix.",100,0,100);

//TH1F *jHist = new TH1F("[KPiX Address","(j) In-time Pixels",128,0,1024);
//TH1F *kHist = new TH1F("[units=bunch clk]","(k) Event Time bucket_0",100,700,900);
//TH1F *lHist = new TH1F("[units=bunch clk]","(l) Pixels first Satellite",128,0,1024);
//TH1F *mHist = new TH1F("[n]","(m) Multiplicity first Sensor",40,0,40);
//TH1F *nHist = new TH1F("[fC]","(n) Late Signals 700-800",100,-20,80);
//TH1F *oHist = new TH1F("[fC]","(o) Hama Hits First Sensor",1024,0,1024);
//TH1F *pHist = new TH1F("[units=bunch clk]","(p) Pixels second Satellite",128,0,1024);
//TH1F *qHist = new TH1F("[units=bunch clk]","(q) Event Time all",150,500,2000);
//TH1F *rHist = new TH1F("[n]","(r) All Hits",200,0,20000);
//TH1F *sHist = new TH1F("[n]","(s) Hits <500",100,0,500);
//TH1F *tHist = new TH1F("[n]","(t) Pixels second Satellite ",128,0,1024);

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

// For Testbeam Data
//TH1F *aHist = new TH1F("[fC]","(a) First   Sensor",100,0,200);
//TH1F *bHist = new TH1F("[fC]","(b) Second  Sensor",100,0,200);
//TH1F *cHist = new TH1F("[fC]","(c) Third   Sensor",100,0,200);
//TH1F *dHist = new TH1F("[fC]","(d) Fourth  Sensor",100,0,200);
//TH1F *eHist = new TH1F("[fC]","(e) Fifth   Sensor",100,0,200);
//TH1F *fHist = new TH1F("[fC]","(f) Sixth   Sensor",100,0,200);
//TH1F *gHist = new TH1F("[fC]","(g) Seventh Sensor",100,0,200);
//TH1F *hHist = new TH1F("[fC]","(h) Eighth  Sensor",100,0,4000);
//TH1F *iHist = new TH1F("[fC]","(i) Last    Sensor",100,0,200);
//TH1F *jHist = new TH1F("[fC]","(j) Prompt Signal",128,0,1024);
//TH1F *kHist = new TH1F("[units=bunch clk]","(k) Event Time all",100,740,840);
//TH1F *lHist = new TH1F("[fC]","(l) First Satellite",128,0,1024);
//TH1F *mHist = new TH1F("[fC]","(m) First   Sensor",100,0,200);
//TH1F *nHist = new TH1F("[fC]","(n) Second  Sensor",100,0,200);
//TH1F *oHist = new TH1F("[fC]","(o) Third   Sensor",100,0,200);
//TH1F *pHist = new TH1F("[fC]","(p) Fourth  Sensor",100,0,200);
//TH1F *qHist = new TH1F("[units=bunch clk]","(q) Event Time all",150,500,2000);
//TH1F *rHist = new TH1F("[fC]","(r) Late Signals 760-803",100,-20,80);
//TH1F *sHist = new TH1F("[n]","(s) Second Satellite",128,0,1024);
//TH1F *tHist = new TH1F("[n]","(t) Third Satellite",128,0,1024);

//TH1F *aHist = new TH1F("[fC]","(a) First   Sensor",80,-10,70);
//TH1F *bHist = new TH1F("[fC]","(b) Second  Sensor",80,-10,70);
//TH1F *cHist = new TH1F("[fC]","(c) Third   Sensor",250,-50,200);
//TH1F *dHist = new TH1F("[fC]","(d) Fourth  Sensor",320,-100,1500);
//TH1F *eHist = new TH1F("[fC]","(e) Fifth   Sensor",320,-100,1500);
//TH1F *fHist = new TH1F("[fC]","(f) Sixth   Sensor",320,-100,1500);
//TH1F *gHist = new TH1F("[fC]","(g) Seventh Sensor",320,-100,1500);
//TH1F *hHist = new TH1F("[fC]","(h) Eighth  Sensor",320,-100,1500);
//TH1F *iHist = new TH1F("[fC]","(i) Last    Sensor",320,-100,1500);

//TH1F *aHist = new TH1F("[fC]","(a) First   Sensor",80,-10,70);
//TH1F *bHist = new TH1F("[fC]","(b) Second  Sensor",80,-10,70);
//TH1F *cHist = new TH1F("[fC]","(c) Third   Sensor",250,-50,200);
//TH1F *dHist = new TH1F("[fC]","(d) Fourth  Sensor",250,-50,200);
//TH1F *eHist = new TH1F("[fC]","(e) Fifth   Sensor",350,-50,200);
//TH1F *fHist = new TH1F("[fC]","(f) Sixth   Sensor",350,-50,200);
//TH1F *gHist = new TH1F("[fC]","(g) Seventh Sensor",350,-50,200);
//TH1F *hHist = new TH1F("[fC]","(h) Eighth  Sensor",350,-50,200);
//TH1F *iHist = new TH1F("[fC]","(i) Last    Sensor",350,-50,200);

//TH1F *jHist = new TH1F("[fC]","(j) Summed Signal",120,0,24000);
//TH1F *jHist = new TH1F("[fC]","(j) Prompt Signal",128,0,1024);
////TH1F *jHist = new TH1F("[fC]","(j) Multiplicity Synchronous Signals",100,0,100);
//TH1F *kHist = new TH1F("[units=bunch clk]","(k) Event Time all",100,740,840);
//TH1F *lHist = new TH1F("[fC]","(l) First Satellite",128,0,1024);
//TH1F *mHist = new TH1F("[fC]","(m) Average for 9 Hits",100,0,10);
//TH1F *mHist = new TH1F("[fC]","(m) Average for 9 Hits",80,-5,35);
//TH1F *mHist = new TH1F("[fC]","(m) Multiplicity in_time Signals",50,0,50);
//TH1F *mHist = new TH1F("[Hama]","(m) single Sensor Hits",1100,0,1100);
//TH1F *mHist = new TH1F("[n]","(m) Multiplicity first Sensor",40,0,40);
////TH1F *mHist = new TH1F("[fC]","(m) neg. Hama Hits Last Sensor",1024,0,1024);
////TH1F *nHist = new TH1F("[fC]","(n) Multiplicity in_time Signals",1024,0,1024);
//TH1F *nHist = new TH1F("[fC]","(n) Late Signals 700-800",100,-20,80);
////TH1F *oHist = new TH1F("[fC]","(o) Average Synchronous Signal",80,-5,35);
//TH1F *oHist = new TH1F("[fC]","(o) Hama Hits First Sensor",1024,0,1024);
////TH1F *pHist = new TH1F("[n]","(p) In-tinme Hits",100,0,100);
//TH1F *pHist = new TH1F("[n]","(p) Second Satellite",128,0,1024);
//TH1F *qHist = new TH1F("[units=bunch clk]","(q) Event Time all",150,500,2000);
//TH1F *rHist = new TH1F("[n]","(r) All Hits",50,0,50);
//TH1F *sHist = new TH1F("[fC]","(s) Summed Signal",100,-1000,9000);
//TH1F *sHist = new TH1F("[units=bunch clk]","(s) Time Sensor_7",100,1000,1100);
//TH1F *tHist = new TH1F("[C]","(t) Sensors with late Signals",12,0,12);
//TH1F *tHist = new TH1F("[n]","(t) Third Satellite",128,0,1024);

// For External Triggers
//TH1F *aHist = new TH1F("[ADC]","(a) All Pixels and Bucket_0",100,0,500);
//TH1F *eHist = new TH1F("[ADC]","(e) All Pixels and Bucket_1",100,0,200);
//TH1F *iHist = new TH1F("[ADC]","(i) All Pixels and Bucket_2",100,-50,50);
//TH1F *mHist = new TH1F("[ADC]","(m) All Pixels and Bucket_3",100,-50,50);
//TH1F *bHist = new TH1F("[ADC]","(b) RMS all Pixels and Bucket-0",100,0,2);
//TH1F *fHist = new TH1F("[ADC]","(f) RMS all Pixels and Bucket-1",100,0,2);
//TH1F *jHist = new TH1F("[ADC]","(j) RMS all Pixels and Bucket-2",100,0,2);
//TH1F *nHist = new TH1F("[ADC]","(n) RMS all Pixels and Bucket-3",100,0,2);
//TH1F *cHist = new TH1F("[fC]","(c) Residuals Bucket_0",100,-10,10);
//TH1F *gHist = new TH1F("[fC]","(g) Residuals Bucket_1",100,-10,10);
//TH1F *kHist = new TH1F("[fC]","(k) Residuals Bucket_2",100,-10,10);
//TH1F *oHist = new TH1F("[fC]","(o) Residuals Bucket_3",100,-10,10);
//TH1F *dHist = new TH1F("[ADC/fC]","(d) Slope bucket_0",100,0,10);
//TH1F *hHist = new TH1F("[ADC/fC]","(h) Slope bucket_1",100,0,10);
//TH1F *lHist = new TH1F("[ADC/fC]","(l) Slope bucket_2",100,0,10);
//TH1F *hHist = new TH1F("[%]","(h) Slope bucket(1-0)",100,0,10);
//TH1F *lHist = new TH1F("[%]","(l) Slope bucket(2-1)",100,-0.5,1.5);

// Other.
//TH1F *bHist = new TH1F("[fC]","(b) 114 Dead Pixels",100,-2,2);
//TH1F *cHist = new TH1F("[fC]","(c) Pedestal diff. (10/27-11/01)",100,-2.5,2.5);
//TH1F *cHist = new TH1F("[fC]","(c) Diff. to Pedestals",100,-5,5);
//TH1F *eHist = new TH1F("%","(e) Error on Slope",100,0,1);
//TH1F *eHist = new TH1F("[fC]","(b) Residuals with Sensor",100,-5,5);
//TH1F *eHist = new TH1F("Residuals [fC]","(e) not sorted",80,-5,35);
//TH1F *fHist = new TH1F("[fC]","(f) Pixel #77",80,-15,20);
//TH1F *fHist = new TH1F("Leakage [pA]","(f) Pixels",100,0,200);
//TH1F *hHist = new TH1F("[fC]","(h) Mean/Shot",100,-2,2);
//TH1F *jHist = new TH1F("[fC]","(j) rms/Shot",100,0,1);
//TH1F *jHist = new TH1F("[fC]","(j) Pixel #118",80,-15,20);
//TH1F *jHist = new TH1F("[fC]","(j) intercept Oct. 18 c.f. PED 17e",100,-150,350);
//TH1F *kHist = new TH1F("[ADC]","(k) Temperature",100,0,200);
//TH1F *lHist = new TH1F("[#]","(l) Multiplicity",50,0,50);
//TH1F *lHist = new TH1F("%","(l) Error on Slope Old",100,0,1);
//TH1F *mHist = new TH1F("[fC]","(m) rms/Pixel",50,0,5),
//TH1F *mHist = new TH1F("[%]","(m) Diff. in Slopes",100,-10,40);

  double a[1024][30],aa[1024][30],slp[1024][4][3][30],xlp[1024][4][3][30],xds[1024][30],
         sig,slpn,slpo,ofs[1024][4][3][30],rms,rsq[1024][4][30],ybb[1024][4][3][30][50],
         u,v,w,x,y,z,uu,uv,uw,vv,ww,xx,zz,sxy,sx2,m0,m1,m2,o0,o1,o2,s0,s1,s2,ss1,ss2,ss3,tt1,tt2,tt3,
         sy1[1024][30],ssx2[1024][30],bbb,cc0,cc1,yy0,yy1,
         xs,ztm,tav,tmp,xdc[1024][4],vtp[200],amx=1.0,
         dif,an,sn,fer,xsm,wsm,wsms,wsx,wsq,wsqs,wqx,zsm,slc[4],xof[4],xtm,ytm[10],ymx,ymn,
         do[4],dm[4],aon=0,son=0,ank[4],snk[4][3],yyv[1024][4][30],
         zmx[4][30],qmz[4][30],qav[4][25],qsq[4][25],pav[4][25],psq[4][25],
         slx[1024][4][30],sly[1024][4][30],ped[1024][4][3][30][25],cped[1024][4][3][30],dped[1024][4][3][30],
         pdq[1024][4][3][30][25],xyv[1024][4][30],xxv[1024][4][30],x2v[1024][4][30],peq[1024][4],
         q[2048][4][30],qq[1024][4],xav[1024][4],yav[200],rep[1024][4][30],x1y1[1024][30],
         xsq[1024][4],itm[1024][4],ktm[1024][4][30][25],xmx[30],ysm[30],yyy[30],tomp[1024],
         dac[256],dec[256],umx[256][4],dll[25];

  int ida,gn=0,i,j,k,l,m,n,i0,i1,i2,i3,i13,ii,iskp,jj,count,jb,jc,jh,jn=1024,jk=4,isv,
      jfl,kfl,jsp,jsv,idr,ids,jdr,jds,ksv,llx,lsv,msv, nlo,ndd,nhi,nq,nr,nsn,nsv,nsw,
      mmv[1024][30],nnv[1024][4][30],gmn,gmx,mn,ct,cv,jm,ks,idm,ite,ipt,kpt,npt,nsm,irh,jrh,
      ibt[30],jbt[30],kbt[30],lbt[30],l0,l1,l2,l3,l4,l5,l6,l7,l8,lj,ivv[30],jv[30],kv[30],mv[30],ntc[30],
      mer=0,ib[1024],ic[1024],iee[1024][4][3][30],ih[1024][4],iz[1024][30],
      o[1024][30],oo[1024][30],jav[1024][4],kda[30],lda[30],mda[30],nda[30],kav[200],mar[200][10],
      ncl[30],jcl[100][30],nn[1024],nav[4][25],nsq[4][25],nmz[4][30],ny[30],nz[30],
      ct0,ct1,ct3,ct4,ct5,ktrn=-1,jnt,jst,jtm,wrg,jmx,jdatp=1,jpix,jbu=0,jx,ctsh,
      nix,lix[500],tnp,jdead[1024],lmx[4096],ntr,ntt,ntu,ntw,nl,mnd,mxd,inc,
      tbp[1024][30],tbc[1024][30],tbd[1024][30],npq[1024][4][3][30][25],nmx[256][4];

  unsigned int ibad,jbad,adc,adv[1024][4],ia[1026][66],irp[1024][4][30],ibl=0,krp,
      cwg=0,wct=0,jtr,jtn,jtx,jft,ktn,ktx,
      sm=0,itrn,itrfst,itxe,itxsv,cnt,zct,jal,jsh,jne,jeq,jgo,jtst,nm,irw=0,wqt=0;

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

for(i=0;i<10;i++){nn[i]=0;}
for (k=0;k<200;k++){ib[k]=0; vtp[k]=0; yav[k]=0; kav[k]=0; for(i=0;i<10;i++){mar[k][i]=0;}}
for(i=0;i<1026;i++){for(k=0;k<66;k++){ia[i][k]=0;}}
for(j=0;j<jn;j++){for(l=0;l<30;l++){xds[j][l]=0;}}
for(j=0;j<jn;j++){ib[j]=0; ic[j]=1; jdead[j]=-1; tomp[j]=0;
for(k=0;k<jk;k++){xav[j][k]=0; xsq[j][k]=0; peq[j][k]=0; jav[j][k]=0; /*tbp[j][k+3]=-1;*/
for(l=0;l<30;l++){irp[j][k][l]=0; rep[j][k][l]=0; nnv[j][k][l]=0;
yyv[j][k][l]=0; xyv[j][k][l]=0; xxv[j][k][l]=0; x2v[j][k][l]=0;}}}

for(l=0;l<30;l++){lda[l]=-1;}
for(l=1;l<5;l++){lda[l]=l;} i0=1; i1=2; i2=3; i3=4; /* seensors 1-4 only */
//lda[10]=10; lda[12]=12; lda[14]=14; lda[16]=16; i0=10; i1=12; i2=14; i3=16;
//i0=11; i1=13; i2=15; i3=17; /* old slot assignment */

//     Read  Dead  Pixels in Stack.
//fin=fopen("dead_pix_stack.txt","r");
//m=fscanf(fin,"%d",&l);
//for(i=0;i<l;i++){m=fscanf(fin,"%d %d %d",&j,&ida,&n);
//printf(      "j= %d ida= %d %d\n",j,ida,n);
//fprintf(fout,"j= %d ida= %d %d\n",j,ida,n);
//x=n; x=.01*x; xds[j][ida]=x;} fclose(fin);

// for(ida=0;ida<9;ida++){for(j=0;j<jn;j++){if(xds[j][ida]>0){
//  printf(     "j= %d ida= %d %5.2f\n",j,ida,xds[j][ida]);
// fprintf(fout,"j= %d ida= %d %5.2f\n",j,ida,xds[j][ida]);}}}



//fin=fopen("gui_sort.txt","r"); for(j=0;j<jn;j++){for(k=0;k<30;k++){
//m=fscanf(fin," %d ",&tbp[j][k]);}
//fprintf(fout," %d ",tbp[j][k]);} fprintf(fout," \n ");
//} fclose(fin);

// fin=fopen("tbp.txt","r"); for(j=0;j<jn;j++){
// m=fscanf(fin," %d %d %d %d %d %d %d\n",&tbp[j][0],&tbp[j][1],&tbp[j][2],&tbp[j][3],&tbp[j][4],&tbp[j][5],&tbp[j][6]);
// fprintf(fout," %d %d %d %d %d %d %d\n",tbp[j][0],tbp[j][1],tbp[j][2],tbp[j][3],tbp[j][4],tbp[j][5],tbp[j][6]);
// } fclose(fin);

// Test on how often a pixel is a neighbor. Should be <6.
// for(j=0;j<jn;j++){for(k=1;k<7;k++){if(tbp[j][k]>-1)tomp[j]++;}}
// for(j=0;j<jn;j++){if(tomp[j]>6){fprintf(fout,"j= %d tomp= %d\n",j,tomp[j]);}}
// for(j=0;j<jn;j++){if(tomp[j]<6){fprintf(fout,"j= %d tomp= %d\n",j,tomp[j]);}}

// Read and transform pixel lists.
// fin=fopen("gui_hama.txt","r"); for(j=0;j<jn;j++){for(k=0;k<15;k++){
// m=fscanf(fin," %d ",&tbc[j][k]);} for(k=0;k<15;k++){
// fprintf(fout," %d ",tbc[j][k]);} fprintf(fout," \n ");}
// for(j=0;j<jn;j++){jj=tbc[j][1]; for(k=0;k<15;k++){
// if(k<2)tbd[jj][k]=tbc[j][k]; if(k>1&&k<9)tbd[jj][k+21]=tbc[j][k];
// for(j=0;j<jn;j++){for(k=0;k<30;k++){if(k>7&&k<23)tbd[j][k]=-1;
// fprintf(fout," %d ",tbd[j][k]);} fprintf(fout," \n ");}

//Process Calibration File gn=0 (normal), 1 (low), 2 (high gain). skip ite=-1.
 jk=1; gmn=0; gmx=1; ite=-1; if(ite<=1){
strcpy(srl[0],"1015"); strcpy(srl[1],"1012"); strcpy(srl[2],"1013");
strcpy(srl[3],"1011"); strcpy(srl[4],"1016"); strcpy(srl[5],"1017"); 
strcpy(srl[6],"1018"); strcpy(srl[7],"1019"); strcpy(srl[8],"1022"); 
strcpy(srl[9],"-1"); strcpy(srl[10],"C0012"); strcpy(srl[11],"C0012");
strcpy(srl[12],"C0014"); strcpy(srl[13],"C0014"); strcpy(srl[14],"C0013"); 
strcpy(srl[15],"C0013"); strcpy(srl[16],"C0011"); strcpy(srl[17],"C0011"); 
// special plots for survey: jsp=2.
 jsp=0;

// strcpy(srl[0],"1011");  strcpy(srl[1],"1013"); 
// strcpy(srl[2],"1012");  strcpy(srl[3],"1015"); 
// strcpy(srl[0],"1002");

 KpixSample *s; KpixCalibRead *c=new KpixCalibRead; irh=0;
// irh=1 for Ryans's calibration.
// c->parse("/u1/w_si/samples/2013_03_05_14_49_01.bin.xml"); idm=4;
// c->parse("/u1/w_si/samples/2013_04_01_21_51_02.bin.xml"); idm=7;
// c->parse("/u1/w_si/samples/2013_04_04_18_07_56.bin.xml"); idm=9;
// c->parse("/u1/kpix/data/2013_04_04_18_07_56.bin.xml"); idm=9;
// This version used extensively up to Sep 2013    
//strcpy(head[0],"/u1/kpix/data/2013_07_26_01_30_53.bin.xml"); idm=9; irh=1;
// Proposed for low gain Sep  2013   
// strcpy(head[1],"/u1/kpix/data/2013_07_25_23_37_09.bin.xml"); gmx=2; idm=9; irh=1;
// c->parse("/u1/w_si/samples/2013_05_15_22_50_36.bin.xml"); idm=1; jk=4;
// PC87444. The chip is C0000, but the file lists mistakenly 1002.
// c->parse("/u1/w_si/samples/2013_05_29_15_47_44.bin.xml"); irh=1; idm=1; jk=1; strcpy(srl[0],"1002");
// c->parse("/u1/w_si/samples/2013_06_18_15_04_00.bin.xml"); idm=1; jk=4;
// c->parse("/u1/w_si/samples/2013_06_20_14_41_22.bin.xml"); idm=1; jk=4;
// c->parse("/u1/w_si/samples/2013_06_21_11_04_10.bin.xml"); idm=1; jk=4;
// c->parse("/u1/w_si/samples/2013_06_21_13_16_27.bin.xml"); idm=1; jk=4; strcpy(srl[0],"C0002");
// c->parse("/u1/w_si/samples/2013_06_25_15_40_19.bin.xml"); idm=1; jk=4; strcpy(srl[0],"1002");
// strcpy(srl[0],"C0000"); strcpy(srl[1],"C0002"); strcpy(srl[2],"1002"); strcpy(srl[3],"1099");
// c->parse("/u1/w_si/samples/2013_10_25_15_25_15.bin.xml"); irh=1; idm=4; jk=1;
// c->parse("/u1/w_si/samples/2013_10_25_18_58_32.bin.xml"); irh=1; idm=4; jk=1;
// c->parse("/u1/w_si/samples/2013_10_28_12_57_03.bin.xml"); irh=1; idm=4; jk=1;
// PC87444
// c->parse("/u1/w_si/samples/2013_10_02_09_30_33.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_03_16_15_06.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_03_21_44_29.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_03_23_25_52.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_05_22_47_36.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_07_11_28_01.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_07_16_26_52.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_07_17_20_12.bin.xml"); irh=1; idm=3; jk=1;
// c->parse("/u1/w_si/samples/2013_10_07_18_14_34.bin.xml"); irh=1; idm=3; jk=1;
// PC87444
// c->parse("/u1/w_si/samples/2013_10_10_21_23_26.bin.xml"); irh=1; idm=1; jk=1; strcpy(srl[0],"C0000");
// PC86131
// strcpy(head[0],"/u1/kpix/data/2014_01_17_20_03_23.bin.xml"); idm=18; irh=1;
// strcpy(head[0],"/u1/kpix/data/2014_01_17_22_09_54.bin.xml"); idm=18; irh=1;
// strcpy(head[0],"/u1/kpix/data/2014_01_18_17_19_26.bin.xml"); idm=18; irh=1;
// strcpy(head[0],"/u1/kpix/data/2014_01_19_12_45_39.bin.xml"); idm=18; irh=1;
// strcpy(head[0],"/u1/kpix/data/2014_01_19_17_24_05.bin.xml"); idm=18; irh=1;
//strcpy(head[0],"/u1/kpix/data/2014_01_19_23_08_39.bin.xml"); idm=18; irh=1;
// strcpy(head[0],"/u1/kpix/data/2014_01_21_08_46_21.bin.xml"); idm=18; irh=1; jn=512;
// strcpy(head[0],"/u1/kpix/data/2014_01_21_12_27_30.bin.xml"); idm=18; irh=1; /*jn=512;*/
//strcpy(head[0],"/u1/kpix/data/2014_02_03_17_58_49.bin.xml"); idm=18; irh=1;
//strcpy(head[1],"/u1/kpix/data/2014_02_03_21_47_02.bin.xml"); idm=18; irh=1; gmx=2;
// CALDAC 0-255, step 5, range thr. 100, norm gain, high-cal cap, only pos. 0-3, 11-17
//strcpy(head[1],"/u1/kpix/data/2014_02_05_16_28_25.bin.xml"); idm=18; irh=1; gmx=2;
// CALDAC 0-255, step 5, range thr. 100, low gain, offs. 6000 thr. lock 8000
//strcpy(head[1],"/u1/kpix/data/2014_02_14_12_16_52.bin.xml"); idm=18; irh=1; gmx=2;
// CALDAC 0-255, step 5, range thr. 100, low gain, offs. 2000 thr. lock 6000(?)
//strcpy(head[1],"/u1/kpix/data/2014_02_14_17_34_39.bin.xml"); idm=18; irh=1; gmx=2;
// CALDAC 0-255, step 5, range thr. 100, low gain, offs. 2000 thr. lock 6000 clk=320
//strcpy(head[1],"/u1/kpix/data/2014_02_14_19_48_54.bin.xml"); idm=18; irh=1; gmx=2;
// CALDAC 0-255, step 5, range thr. 100, low gain, offs. 2000 thr. lock 6000 clk=320
//strcpy(head[1],"/u1/kpix/data/2014_02_16_12_27_21.bin.xml"); idm=18; irh=1; gmx=2;
// CALDAC 0-255, step 5, range thr. 60, parameters of 4.4 pC runb.
//strcpy(head[1],"/u1/kpix/data/2014_02_18_14_19_49.bin.xml"); idm=18; irh=1; gmx=2;
// CALDAC 0-200, step 5, range thr. 60, parameters of 4.4 pC runb.
//strcpy(head[1],"/u1/kpix/data/2014_02_19_15_02_39.bin.xml"); idm=18; irh=1; gmx=2;
// cal12 CALDAC 0-200, step 5, forced low gain, times 1000, 10000, 11000.
//strcpy(head[1],"/u1/kpix/data/2014_06_14_13_07_25.bin.xml"); idm=17; irh=1; gmx=2;
// cal12 CALDAC 0-200, step 5, forced low gain, times 1000, 10000, 11000.fixed KPiX_C
//strcpy(head[1],"/u1/kpix/data/2014_06_18_08_07_53.bin.xml"); idm=17; irh=1; gmx=2;
//cal12,no frc. l.g.,cal h. range thr 0, caldac 255. no cal source.
//strcpy(head[0],"/u1/kpix/data/2014_06_18_19_36_01.bin.xml"); idm=17; irh=1;
// chris CALDAC 0-200, step 5, forced low gain, times 6000, 8000, 10000.fixed KPiX_C
//strcpy(head[1],"/u1/kpix/data/2014_06_19_23_34_08.bin.xml"); idm=17; irh=1; gmx=2;
// chris CALDAC 0-200, step 5, forced low gain, times 4000, 8000, 10000.fixed KPiX_C
//strcpy(head[1],"/u1/kpix/data/2014_06_21_11_27_42.bin.xml"); idm=17; irh=1; gmx=2;
// chris CALDAC 0-200, step 5, not low gain, times 4000, 8000, 10000.fixed KPiX_C
//strcpy(head[0],"/u1/kpix/data/2014_06_21_13_48_00.bin.xml"); idm=17; irh=1;
// chris CALDAC 50-255,step 5, low gain,ghcal false, offs. 4000, range thr 0 bad file, no senbsor 4
//strcpy(head[1],"/u1/kpix/data/2014_06_23_17_46_42.bin.xml"); idm=17; irh=1; gmx=2;
// chris CALDAC 50-255,step 5, not low gain,ghcal false, offs. 4000, range thr 0
//strcpy(head[0],"/u1/kpix/data/2014_06_23_20_53_13.bin.xml"); idm=17; irh=1;
// chris CALDAC 50-255,step 5, not low gain,ghcal false, offs. 4000, range thr 0
//strcpy(head[1],"/u1/kpix/data/2014_06_23_22_53_46.bin.xml"); idm=17; irh=1; gmx=2;
//  cal12 CALDAC 50-255,step 5, low gain, hcal true, 3000, range thr 0
//strcpy(head[1],"/u1/kpix/data/2014_06_24_21_17_34.bin.xml"); idm=17; irh=1; gmx=2;
//  cal12 CALDAC 50-255,step 5, norm. gain, hcal false, 3000, range thr 0
//strcpy(head[0],"/u1/kpix/data/2014_06_25_22_37_21.bin.xml"); idm=17; irh=1;
//  cal12 CALDAC 50-255,step 5, norm. gain, norm. cal, thr.off. 9000
//strcpy(head[0],"/u1/kpix/data/2014_06_27_19_17_12.bin.xml"); idm=17; irh=1;
//  cal12 CALDAC 50-255,step 5, low gain, hcal true, 3000, range thr 0
//strcpy(head[1],"/u1/kpix/data/2014_06_27_21_20_02.bin.xml"); idm=17; irh=1; gmx=2;
//  cal13 CALDAC 200-255,step 1, high gain.
//strcpy(head[2],"/u1/kpix/data/2014_10_29_12_31_54.bin.xml"); idm=17; irh=1; gmn=0; gmx=1;
gmx=0; /* skip xml-calibration files. */

// Process calibration data ++++++
for(gn=gmn;gn<gmx;gn++){c->parse(head[gn]); ibad=0;

for(ida=0;ida<idm;ida++){if(lda[ida]==-1)continue; jbad=0;
//printf(      "ida=%2d lda=%2d\n",ida,lda[ida]);
//fprintf(fout,"ida=%2d lda=%2d\n",ida,lda[ida]);

xs=1; if(gn==1)xs=2; if(gn==2)xs=.05;
for(k=0;k<jk;k++){snk[k][gn]=0; n=0; for(j=0;j<jn;j++){

// x   = c->baseFitMean(srl[ida],j,k,gn);
// sig = c->baseFitSigma(srl[ida],j,k,gn);
u= c->      baseMean(srl[ida],j,k,gn);
w= c->calibIntercept(srl[ida],j,k,gn);
rms= c->     baseRms(srl[ida],j,k,gn);
y= c->     calibGain(srl[ida],j,k,gn);
fer= c->calibGainErr(srl[ida],j,k,gn);
if(irh==1){jrh=c->badChannel(srl[ida],j);}

if(y!=0){y=y/1e15;} slp[j][k][gn][ida]=y; xlp[j][k][gn][ida]=y;
dped[j][k][gn][ida]=u; cped[j][k][gn][ida]=w;
if(y!=0){
printf(      "j=%5d k=%5d ida=%5d gn%3d y=%5.2f\n",j,k,ida,gn,y);
fprintf(fout,"j=%5d k=%5d ida=%5d gn%3d y=%5.2f\n",j,k,ida,gn,y);}
//if(gn==0){
//printf(      "K=%5d H=%5d ida=%5d flag=%3d y=%5.2f\n",j,tbp[j][0],ida,jrh,y);
//fprintf(fout,"K=%5d H=%5d ida=%5d flag=%3d y=%5.2f\n",j,tbp[j][0],ida,jrh,y);}

 if(y>0){fer=(fer*1e-13)/y;} else{fer=.395;}

// x=slp[j][0][gn][ida]; if(k>0&&x>0){x=100*(y-slp[j][k-1][gn][ida])/x;}
// if(k==1){if(x<0.1)x=0.1; if(x>9.9)x=9.9;} if(k>1){if(x<-.9)x=-.9; if(x>.9)x=.9;}
// if(k==0){bHist->Fill(fer); aHist->Fill(y);} if(k==1){fHist->Fill(fer); eHist->Fill(x);}
// if(k==2){jHist->Fill(fer); iHist->Fill(x);} if(k==3){nHist->Fill(fer); mHist->Fill(x);}

 if((irh==0&&(fer<0.001||y<0.1))||(irh==1&&(jrh!=0||y<=0))){iee[j][k][gn][ida]=0;}
else{iee[j][k][gn][ida]=1;} for(l=1;l<4;l++){iee[j][l][gn][ida]=iee[j][0][gn][ida];}
if(iee[j][k][gn][ida]==0){ibad++; jbad++;}


//if(gn==0&&iee[j][k][0][ida]==0&&ida==2){
//if(gn==1){l=iee[j][k][gn][ida];
//printf(      "K=%5d H=%5d ida=%5d flag=%3d v=%5.2f l=%d\n",j,tbp[j][0],ida,jrh,v,l);
//fprintf(fout,"K=%5d H=%5d ida=%5d flag=%3d v=%5.2f l=%d\n",j,tbp[j][0],ida,jrh,v,l);}

// calibration four KPiX_A and four bare KPiX_C.
//if(gn==1&&y>0.16){
////i0=1; i1=2; i2=3; i3=4;
////i0=11; i1=13; i2=15; i3=17;
//x=u-ped[j][k][0][ida][0];
//v=u-w;
//if(y>.95)y=.95; if(w>499)w=499; z=slp[j][k][0][ida]; if(z>24)z=24;
////if(y>0){u=slp[j][k][0][ida]/y; if(u<21.05)u=21.05; if(u>23.95)u=23.95;}
//if(ida==i0){aHist->Fill(w); eHist->Fill(u); iHist->Fill(y); mHist->Fill(z); qHist->Fill(x); uHist->Fill(v);}
//if(ida==i1){bHist->Fill(w); fHist->Fill(u); jHist->Fill(y); nHist->Fill(z); rHist->Fill(x); vHist->Fill(v);}
//if(ida==i2){cHist->Fill(w); gHist->Fill(u); kHist->Fill(y); oHist->Fill(z); sHist->Fill(x); wHist->Fill(v);}
//if(ida==i3){dHist->Fill(w); hHist->Fill(u); lHist->Fill(y); pHist->Fill(z); tHist->Fill(x); xHist->Fill(v);}
//} /* gn==1 */

// calibration Stack of nine.
// if(gn==0&&iee[j][k][gn][ida]>0){x=rms/y; if(x<0)x=0; if(x>.49)x=.49;
// if(ida==0){aHist->Fill(x);} if(ida==1){bHist->Fill(x);} if(ida==2){cHist->Fill(x);}
// if(ida==3){dHist->Fill(x);} if(ida==4){eHist->Fill(x);} if(ida==5){fHist->Fill(x);}
// if(ida==6){gHist->Fill(x);} if(ida==7){hHist->Fill(x);} if(ida==8){iHist->Fill(x);}}

// if(gn==1&&iee[j][k][gn][ida]>0){x=rms/y; if(x<0)x=0; if(x>9.9)x=9.9;
// if(ida==0){mHist->Fill(x);} if(ida==1){nHist->Fill(x);} if(ida==2){oHist->Fill(x);}
// if(ida==3){pHist->Fill(x);} if(ida==4){qHist->Fill(x);} if(ida==5){rHist->Fill(x);}
// if(ida==6){sHist->Fill(x);} if(ida==7){tHist->Fill(x);} if(ida==8){lHist->Fill(x);}}

//if(k==0&&iee[j][k][gn][ida]==0)ibad++;
//if(ite==1){
//if(fer<1)hHist->Fill(fer); jHist->Fill(fer); if(iee[j][k][0][ida]==0){mHist->Fill(fer);}
//if(y<0)y=0; if(y>9.9)y=9.9; if(iee[j][0][0][ida]==1){gHist->Fill(y);} /*else{kHist->Fill(y);}*/
//lHist->Fill(fer); if(fer>0.1&&fer<10.4){kHist->Fill(y);}} /* ite */
 cnt++;} /* j */

printf(" ida=%2d jbad=%5d\n",ida,jbad); fprintf(fout," ida=%2d jbad=%5d\n",ida,jbad);

 if(n>0){snk[k][gn]/=n; printf(" k=%3d n=%5d snk=%8.3f\n",k,n,snk[k][gn]);
 fprintf(fout," k=%3d n=%5d snk=%8.3f\n",k,n,snk[k][gn]);}

 } /* k */
 } /* ida */
 printf(" ibad_gn_%d=%5d\n\n",gn,ibad); fprintf(fout," ibad_gn_%d=%5d\n\n",gn,ibad);
 }/* gn */ delete c;

//     Read  Bad  Pixels
//// fin=fopen("bad_pix.txt","r");
//// fin=fopen("bad_pix_ctr.txt","r");
// fin=fopen("bad_pix_mult.txt","r");
// m=fscanf(fin,"%d",&l);
//// l=35; /* Eliminate only 35 catastrophic pixels */
//// l=137; /* Eliminate only 35 catastrophic pixels and 88 half-pixels*/
// for(i=0;i<l;i++){m=fscanf(fin,"%d %d %d %d",&j,&jj,&ida,&n);
//// if(i<35)jj=tbp[j][0];
//// if(i>=35){for(m=0;m<jn;m++){jj=j; if(j==tbp[m][0]){j=m; m=jn;}}}
////  printf(     "j= %d H= %5d ida= %d %d\n",j,jj,ida,n);
//// fprintf(fout,"j= %d H= %5d ida= %d %d\n",j,jj,ida,n);
// for(k=0;k<jk;k++){if(ida<0){for(m=0;m<30;m++){iee[j][k][0][m]=0;}}
// else{iee[j][k][0][ida]=0;}}
// } fclose(fin);

 }/* end ite */

// Determine variances of slopes, means and calibration offsets:
// for(j=0;j<jn;j++){y=0; for(k=0;k<jk;k++){y+=0.25*x;}
// for(k=0;k<jk;k++){y=snk[k][gn]; x=1.15*(mean[j][k][gn][0]-y)
// x=mean[j][k][gn][1]-mean[j][k][gn][0];
// o0=ofs[j][k][0][0]; o1=ofs[j][k][1][0]; o2=ofs[j][k][2][0]; s0=slp[j][k][0][0]; s1=slp[j][k][1][0];
// s2=slp[j][k][2][0]; m0=mean[j][k][0][0]; m1=mean[j][k][1][0]; m2=mean[j][k][2][0]
// x=(m0-o0)/s0; x=(o1-o2)/(s2-s1); x=(o1*s2-o2*s1)/(s2-s1)-mean[j][k][2][0];}}
// END Calibration data.


// Process simulation data, skip if jtx=0.
jtx=0; if(jtx>0){
dac[0]=0; dac[1]=5; dac[2]=10; dac[3]=15; dac[4]=25; dac[5]=50; dac[6]=100; dac[7]=150;
dac[8]=200; dac[9]=250; dac[10]=300; dac[11]=350; dac[12]=400; dac[13]=450; dac[14]=500;
dac[15]=550; dac[16]=600; dac[17]=650; dac[18]=680; dac[19]=700;

ybb[0][0][0][0][0]=   0;    ybb[0][0][0][1][0]=     0;  ybb[1][0][0][0][0]=     0;  ybb[1][0][0][1][0]=     0;
ybb[0][0][0][0][1]=  11.3;  ybb[0][0][0][1][1]=  12.4;  ybb[1][0][0][0][1]=  11.5;  ybb[1][0][0][1][1]=  12.6;
ybb[0][0][0][0][2]=  23.2;  ybb[0][0][0][1][2]=  24.4;  ybb[1][0][0][0][2]=  23.4;  ybb[1][0][0][1][2]=  24.6;
ybb[0][0][0][0][3]=  35.1;  ybb[0][0][0][1][3]=  36.6;  ybb[1][0][0][0][3]=  35.3;  ybb[1][0][0][1][3]=  36.8;
ybb[0][0][0][0][4]=  58.9;  ybb[0][0][0][1][4]=  60.8;  ybb[1][0][0][0][4]=  59.1;  ybb[1][0][0][1][4]=  61.0;
ybb[0][0][0][0][5]= 118.7;  ybb[0][0][0][1][5]= 121.6;  ybb[1][0][0][0][5]= 118.6;  ybb[1][0][0][1][5]= 121.8;
ybb[0][0][0][0][6]= 238.4;  ybb[0][0][0][1][6]= 244.1;  ybb[1][0][0][0][6]= 238.5;  ybb[1][0][0][1][6]= 244.0;
ybb[0][0][0][0][7]= 356.4;  ybb[0][0][0][1][7]= 366.9;  ybb[1][0][0][0][7]= 356.0;  ybb[1][0][0][1][7]= 366.8;
ybb[0][0][0][0][8]= 469.2;  ybb[0][0][0][1][8]= 490.2;  ybb[1][0][0][0][8]= 469.9;  ybb[1][0][0][1][8]= 490.4;
ybb[0][0][0][0][9]= 586.3;  ybb[0][0][0][1][9]= 613.6;  ybb[1][0][0][0][9]= 586.0;  ybb[1][0][0][1][9]= 613.4;
ybb[0][0][0][0][10]= 708.5; ybb[0][0][0][1][10]= 736.8; ybb[1][0][0][0][10]= 708.8; ybb[1][0][0][1][10]= 736.9;
ybb[0][0][0][0][11]= 832.2; ybb[0][0][0][1][11]= 860.1; ybb[1][0][0][0][11]= 832.3; ybb[1][0][0][1][11]= 860.4;
ybb[0][0][0][0][12]= 955.7; ybb[0][0][0][1][12]= 984.4; ybb[1][0][0][0][12]= 955.2; ybb[1][0][0][1][12]= 983.9;
ybb[0][0][0][0][13]=1078.7; ybb[0][0][0][1][13]=1107.3; ybb[1][0][0][0][13]=1079.3; ybb[1][0][0][1][13]=1107.5;
ybb[0][0][0][0][14]=1202.8; ybb[0][0][0][1][14]=1230.8; ybb[1][0][0][0][14]=1203.1; ybb[1][0][0][1][14]=1231.9;
ybb[0][0][0][0][15]=1326.3; ybb[0][0][0][1][15]=1355.6; ybb[1][0][0][0][15]=1326.2; ybb[1][0][0][1][15]=1355.2;
ybb[0][0][0][0][16]=1449.7; ybb[0][0][0][1][16]=1478.5; ybb[1][0][0][0][16]=1449.2; ybb[1][0][0][1][16]=1478.4;
ybb[0][0][0][0][17]=1572.3; ybb[0][0][0][1][17]=1595.6; ybb[1][0][0][0][17]=1572.5; ybb[1][0][0][1][17]=1595.8;
ybb[0][0][0][0][18]=1620.4; ybb[0][0][0][1][18]=1630.4; ybb[1][0][0][0][18]=1620.4; ybb[1][0][0][1][18]=1630.5;
ybb[0][0][0][0][19]=1642.4; ybb[0][0][0][1][19]=1652.2; ybb[1][0][0][0][19]=1642.5; ybb[1][0][0][1][19]=1652.2;
;

for(ida=0;ida<2;ida++){m=ida; x1y1[0][m]=0; ssx2[0][m]=0;
for(l=0;l<17;l++){x=dac[l]-dac[0]; for(j=0;j<2;j++){
y=ybb[j][0][0][m][l]-ybb[j][0][0][m][0];
x1y1[0][m]+=y*x; ssx2[0][m]+=x*x;
printf(      " ida=%d l=%5d x1y1=%5.1f ssx2=%5.1f y=%5.1f x=%5.1f\n",m,l,x1y1[0][m],ssx2[0][m],ybb[j][0][0][m][l],x);
fprintf(fout," ida=%d l=%5d x1y1=%5.1f ssx2=%5.1f y=%5.1f x=%5.1f\n",m,l,x1y1[0][m],ssx2[0][m],ybb[j][0][0][m][l],x);
} /* j */ } /* l */

bbb=x1y1[0][m]/ssx2[0][m];
printf(      "bbb=%5.2f\n",bbb);
fprintf(fout,"bbb=%5.2f\n",bbb);

for(l=0;l<20;l++){x=dac[l]-dac[0]; for(j=0;j<2;j++){
y=ybb[j][0][0][m][l]-ybb[j][0][0][m][0];
w=y/bbb; y=w-x;
printf("      %5.2f",y); fprintf(fout,"%5.2f",y);
if(ida==0){aPlot->Fill(x,w); cPlot->Fill(x,y);}
if(ida==1){bPlot->Fill(x,w); dPlot->Fill(x,y);}
} /* j */ } /* l */
fprintf(fout,"\n"); printf("\n");
} /* ida */ } /* jtx , end process simulation data */



// Process Raw Calibration file. =========
jtn=0; jtx=0; jft=0; gmx=1; iskp=400; /*  default, skip section for jtx=0 */

// This version used extensively up to Sep 2013    
//strcpy(head[0],"/u1/w_si/samples/2013_07_26_01_30_53.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=32; iskp=1000;

//Calibration file high gain (cal13, orig. timing).
//strcpy(head[0],"/u1/w_si/samples/2014_11_02_10_18_11.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=200; mxd=255; inc=1;

//Calibration file normal gain.
//strcpy(head[0],"/u1/w_si/samples/2014_11_02_17_30_27.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=50; mxd=255; inc=5;

//Calibration file high gain, times 5000, 5300, 5600, 7200, 500.
//strcpy(head[0],"/u1/w_si/samples/2014_11_14_14_29_32.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=200; mxd=255; inc=1;

//Calibration file high gain, times 5000, 6300, 6600, 7200, 500.
//strcpy(head[0],"/u1/w_si/samples/2014_11_15_13_15_10.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=200; mxd=255; inc=1;

//Calibration (cal13) high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2014_11_17_13_12_18.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=200; mxd=255; inc=1; ndd=100;

//Calibration (cal13) normal gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2014_12_15_12_19_27.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=50; mxd=255; inc=5; ndd=100;

//Calibration (cal13) normal gain, precharge  6000, 2 buckets 
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2015_01_18_15_58_33.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=50; mxd=255; inc=5; ndd=100;

//Calibration (cal13) normal gain, precharge 40950, 2 buckets
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[1],"/u1/w_si/samples/2015_01_22_15_06_44.bin");
//jk=1; jtn=1; jtx=2; idm=17; mnd=50; mxd=255; inc=5; ndd=100;

//Calibration (cal13) normal gain, precharge   320, 2 buckets
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2015_02_06_11_35_47.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=50; mxd=255; inc=5; ndd=100;

//Calibration (cal13) normal gain, precharge 20000, 2 buckets
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[1],"/u1/w_si/samples/2015_03_17_11_47_40.bin");
//jk=1; jtn=1; jtx=2; idm=17; mnd=50; mxd=255; inc=5; ndd=100;

//Calibration (cal15 K1-4) normal gain, precharge  6000, 2 buckets 
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2015_03_20_08_06_31.bin");
//jk=1; jtn=1; jtx=1; idm=17; mnd=50; mxd=255; inc=5; ndd=100;

//Calibration (cal15 K1-4) normal gain, precharge 40950, 2 buckets
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[1],"/u1/w_si/samples/2015_03_20_08_51_44.bin");
//jk=1; jtn=1; jtx=2; jft=8; idm=17; mnd=50; mxd=255; inc=5; ndd=100;

//Calibration (cal15 K1-4) normal gain, precharge  6000, 2 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2015_03_21_16_53_58.bin");
//jk=2; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  40950, 2 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[1],"/u1/w_si/samples/2015_03_22_12_28_27.bin");
//jk=2; jtn=1; jtx=2; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  6000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2015_03_23_18_39_18.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  40950, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[1],"/u1/w_si/samples/2015_03_23_21_12_34.bin");
//jk=4; jtn=1; jtx=2; idm=17; mnd=0; mxd=255; inc=5; llx=27;
//strcpy(head[0],"/u1/w_si/samples/2015_03_23_21_12_34.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge   6000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. DC Power.
//strcpy(head[0],"/u1/w_si/samples/2015_03_31_21_08_33.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  40950, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. DC Power.
//strcpy(head[1],"/u1/w_si/samples/2015_03_31_11_41_48.bin");
//jk=4; jtn=1; jtx=2; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge   1000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. pulsed Power.
//strcpy(head[0],"/u1/w_si/samples/2015_04_07_20_53_03.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge   1000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. pulsed Power. Default Ana 2.5 V.
//strcpy(head[0],"/u1/w_si/samples/2015_04_07_21_36_04.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge   6000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. pulsed Power. Default Ana 1.3V.
//strcpy(head[0],"/u1/w_si/samples/2015_04_09_17_09_27.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge   6000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. pulsed Power. Del.0 750->950.
//strcpy(head[0],"/u1/w_si/samples/2015_04_10_15_54_27.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15) high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//times 5,000, 13,000, 14,000, 15,000, 500. pulsed Power. Del.0 750->950.
//strcpy(head[0],"/u1/w_si/samples/2015_04_10_17_54_24.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=200; mxd=255; inc=1;

//Calibration (cal15) high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//times 5,000, 13,000, 14,000, 15,000, 500. pulsed Power. Del.0 750->950.
//strcpy(head[0],"/u1/w_si/samples/2015_04_11_08_51_31.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=200; mxd=255; inc=1;

//Calibration (cal15 K1-4) normal gain, precharge  6000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. Ramp Thr=2.2V (from 2.4)
//strcpy(head[0],"/u1/w_si/samples/2015_04_13_18_36_02.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  6000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. Ramp Thr=2.3V (from 2.4)
//strcpy(head[0],"/u1/w_si/samples/2015_04_13_20_56_36.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  6000, 4 buckets, 500 fC 
//times 10,000, 12,000, 10,000, 12,000, 500. Ramp Thr=2.2V Def.Ana=1.3
//strcpy(head[0],"/u1/w_si/samples/2015_04_19_13_49_15.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  40,000, 4 buckets, 500 fC 
//times 10,000, 12,000, 10,000, 12,000, 500. Ramp Thr=2.2V Def.Ana=1.89
//strcpy(head[0],"/u1/w_si/samples/2015_04_28_13_29_36.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  40,000, 4 buckets, 500 fC 
//times 10,000, 12,000, 10,000, 12,000, 500. Ramp Thr=2.2V Def.Ana=1.89
//strcpy(head[0],"/u1/w_si/samples/2015_05_06_09_22_35.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  6,000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. def.ana=0.1V
//strcpy(head[0],"/u1/w_si/samples/2015_05_09_17_04_52.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  6,000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. def.ana=0.1V ramp=2.2
//strcpy(head[0],"/u1/u2/kpix/samples/2015_05_12_09_15_02.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration (cal15 K1-4) normal gain, precharge  40,000, 4 buckets, 500 fC 
//times 5,000, 13,000, 14,000, 15,000, 500. def.ana=1.3V ramp=2.2
//strcpy(head[0],"/u1/w_si/samples/2015_05_17_15_56_54.bin");
//jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;

//Calibration for DESY  set-up  
//times 5,000, 13,000, 14,000, 15,000, 500. def.ana=0.1V ramp=2.2
strcpy(head[0],"/u2/kpix/samples/2016_02_18_12_21_58.bin");
jk=4; jtn=1; jtx=1; idm=17; mnd=0; mxd=255; inc=5; llx=27;


// Nominal Calibration DAC charge.
for(i=0;i<246;i++){dac[i]=500-2*i;} for(i=246;i<256;i++){dac[i]=255-i;}




for(jtr=0;jtr<jtx;jtr++){

//Process base pedestals.
DataRead *r=new DataRead; stat = r->open(head[jtr]);
if(! stat){printf("pedestal file not found\n"); fprintf(fout,"pedestal file not found\n");}
printf("file = %d\n",jtr); fprintf(fout,"file = %d\n",jtr);

// Skip Events.
jtst=0; KpixEvent e; for(i=0;i<2;i++){r->next(&e);}

while(r->next(&e)&&jtst<100) {count=e.count(); itrn=e.eventNumber(); jtst++;

// Each trigger:
i=0; while(i<count){s=e.sample(i); jst=s->getSampleType(); gn=s->getSampleRange();
jnt=s->getTrigType();    j=s->getKpixChannel(); k=s->getKpixBucket();
ida=s->getKpixAddress(); x=s->getSampleValue(); z=s->getSampleTime();

printf(      "j=%5d k=%5d ida=%5d gn%3d x=%5.2f\n",j,k,ida,gn,x);
fprintf(fout,"j=%5d k=%5d ida=%5d gn%3d x=%5.2f\n",j,k,ida,gn,x);

// Produce Averages (dped) and variances (pdq) for each pixel, bucket, sensor.
if(jst==0){if(jtst==1){dped[j][k][gn][ida]=0; npq[j][k][gn][ida][jtr]=0;}
y=x-dped[j][k][gn][ida]; n=npq[j][k][gn][ida][jtr]; dped[j][k][gn][ida]+=y/(n+1);
pdq[j][k][gn][ida][jtr]+=n*y*y/(n+1); npq[j][k][gn][ida][jtr]++;
} i++; } /* while(i<cout), end of block */ } /* while r, end of file */
//printf(      " itrn= %d count= %d Pedestal=%4.0f\n",itrn,count,dped[0][0][0][1]);
//fprintf(fout," itrn= %d count= %d Pedestal=%4.0f\n",itrn,count,dped[0][0][0][1]);
//End base pedestals.






if(inc==1){llx=32; for(l=0;l<9;l++){dec[l]=l;} for(l=9;l<32;l++){dec[l]=4*l-26;}}

if(inc==5){llx=27;
dec[0]=0; dec[1]=5; for(l=2;l<9;l++){dec[l]=10*(l-1);}
for(l=7;l<15;l++){dec[l]=20*(l-7)+60;}
dec[15]=240; dec[16]=280; dec[17]=320; dec[18]=360; dec[19]=400;
dec[20]=420; dec[21]=440; dec[22]=450; dec[23]=470; dec[24]=480; dec[25]=490; dec[26]=500;
//for(l=0;l<llx;l++){
//printf(      "%2d dec=%4.0f\n",l,dec[l]);
//fprintf(fout,"%2d dec=%4.0f\n",l,dec[l]);}
} /* inc */

if(inc==32){llx=9; dec[0]=0; for(l=1;l<llx;l++){dec[l]=64*l-12;
printf(      "l=%2d dec=%4.0f\n",l,dec[l]);
fprintf(fout,"l=%2d dec=%4.0f\n",l,dec[l]);
}}

// Read file for corrections.
//fin=fopen("cor400.txt","r"); for(l=1;l<llx;l++){
fin=fopen("corall.txt","r"); for(l=1;l<llx;l++){
m=fscanf(fin,"%d %d %d %d",&i0,&i1,&i2,&i3);
umx[l][0]=.01*i0; umx[l][1]=.01*i1; umx[l][2]=.01*i2; umx[l][3]=.01*i3;
for(k=0;k<4;k++){x=umx[l][k]; printf(" %5.2f",x); fprintf(fout," %5.2f",x);}
printf("\n"); fprintf(fout,"\n");}

//tav=0; ipt=0; kpt=0; npt=100; ct0=0;  /*  for temperature monitor. */
//for(l=0;l<256;l++){for(k=0;k<4;k++){umx[l][k]=0; nmx[l][k]=0;}}
DataRead *r=new DataRead; stat = r->open(head[jtr]);
if(! stat){printf("pedestal file not found\n"); fprintf(fout,"pedestal file not found\n");}
printf("file = %d\n",jtr); fprintf(fout,"file = %d\n",jtr);

//Skip Pedestal Data.
KpixEvent e ; for(i=0;i<iskp/*+16000*/;i++){r->next(&e);}

jtst=0; /*jdr=0; jds=mnd;*/ i0=0; /* jdr=current pixel, jds current cal-DAC. */
for(k=0;k<jk;k++){for(ida=0;ida<30;ida++){nmz[k][ida]=0; zmx[k][ida]=0;}}
while(r->next(&e)) {count=e.count(); itrn=e.eventNumber();
//while(r->next(&e)&&jtst<400) {count=e.count(); itrn=e.eventNumber(); jtst++;
//printf(      " itrn= %d jtst= %d count= %d jdr=%d jds=%d\n",itrn,jtst,count,jdr,jds);
//fprintffout," itrn= %d jtst= %d count= %d jdr=%d jds=%d\n",itrn,jtst,count,jdr,jds);

// Each trigger:
i0++; if(i0==4||inc!=32){i0=0;} /* for old calibration skip first 3 readings */
i=0; while(i<count){s=e.sample(i); jst=s->getSampleType(); if(jst==0&&i0==0){
j=s->getKpixChannel(); jdr=r->getStatusInt("CalChannel"); if(j==jdr){ 
gn=s->getSampleRange(); jnt=s->getTrigType();    k=s->getKpixBucket();
ida=s->getKpixAddress(); x=s->getSampleValue(); z=s->getSampleTime();

jds=r->getStatusInt("CalDac"); i1=-1;
for(l=0;l<llx;l++){if(dec[l]==dac[jds]){ybb[j][k][jtr][ida][l]=x; i1=l;}}
if(inc==32){ybb[j][k][jtr][ida][0]=dped[j][k][0][ida];}
} /* j==jdr */ } /* jst==0 */

//if(j==jdr+1||j==jdr-1){if(jst==0&&jds==mxd){
//k=s->getKpixBucket(); ida=s->getKpixAddress(); x=s->getSampleValue();
//if(x>200){nmz[k][ida]++; zmx[k][ida]+=x;}
//}}
i++; } /* while(i<cout) */
} /* while(r->next(&e)) */ delete r;


//for(j=0;j<10;j++){for(l=0;l<llx;l++){
//printf(      " itrn= %d count= %d ybb=%4.0f\n",itrn,count,ybb[j][0][jtr][1][l]);
//fprintf(fout," itrn= %d count= %d ybb=%4.0f\n",itrn,count,ybb[j][0][jtr][1][l]);}}



// All moments relative to DAC values (jds) have been determined for this driven pixel (jdr)
// and all stations (ida). The highest accepted DAC value is ny and the number accepted is nz.
// Determine slope and offset for each pixel and bucketin each sensor and file.
// For x=b*y+a use moments: b=(<x*y>-<x>*<y>)/(<y**2>-<y>**2); a=<x>-b*<y>; (min-chisq for equal weigt)


//yy0=350; cc0=0.185; yy1=30; cc1=0.06;
//yy0=100; cc0=-15;
yy0=100; cc0=0;

for(k=0;k<jk;k++){nr=0; uw=0; vv=0; xx=0; for(ida=0;ida<idm;ida++){if(lda[ida]==-1)continue;
nq=0; bbb=0; uu=0; uv=0; ww=0; xsm=0; for(j=0;j<jdr;j++){zz=ybb[j][k][jtr][ida][0];
if(k==0){zz+=cc0;}
if(k==0&&zz<230)continue;

sxy=0; sx2=0; for(l=1;l<llx;l++){y=ybb[j][k][jtr][ida][l]-zz; x=dec[l]-dec[0];
//y=y+cc0*yy0*(1-exp(-y/yy0))+cc1*yy1*(1-exp(-y/yy1));
//if(k==0){y+=cc0*exp(-x/yy0);}
u=1;if(l>10&&sxy>0){u=(y*sx2)/sxy-x;}
if(l>10&&k==0&&j>308&&j<314){v=sxy/sx2;
printf(      "j=%d l=%d ida=%d u=%5.2f v=%5.2f\n",j,l,ida,u,v);
fprintf(fout,"j=%d l=%d ida=%d u=%5.2f v=%5.2f\n",j,l,ida,u,v);
}
if(u<-10)continue;
sxy+=y*x; sx2+=x*x;} y=0; if(sx2!=0){y=sxy/sx2;} slp[j][k][jtr][ida]=y;

if(y>2.5){wsm=0; for(l=0;l<llx;l++){x=dec[l]-dec[0]; u=ybb[j][k][jtr][ida][l]-zz;
u/=y; u-=(dec[l]-dec[0]);
if(u<-10)continue;
u-=0.01*x*umx[l][k];
wsm+=u*u;
if(k==0&&y>2.5&&j>308&&j<314){
printf(      "j=%d l=%d ida=%d slp=%5.2f u=%5.2f wsm=%4.0f\n",j,l,ida,y,u,wsm);
fprintf(fout,"j=%d l=%d ida=%d slp=%5.2f u=%5.2f wsm=%4.0f\n",j,l,ida,y,u,wsm);}
} /* l */ wsm=sqrt(wsm/llx);} /* y */

// m=1: use slope_1, m=0: use individual slopes.
m=0; if(y>2.5&&wsm<3){nq++; bbb+=zz; uu+=y; ww+=zz;
uv+=ybb[j][k][jtr][ida][llx-1]; z=slp[j][1][jtr][ida];

wsm=0; for(l=1;l<llx;l++){if(jtr==jtx-1){x=dec[l]-dec[0];
v=ybb[j][k][jtr][ida][l]-zz;
//if(k==0){v+=cc0*exp(-x/yy0);}
u=v/y-x; if(u<-10)continue;
//u=(100*u)/x;
u-=0.01*x*umx[l][k];
//umx[l][k]+=u; nmx[l][k]++;
xsm+=u*u;
wsm+=u*u;
if(k>0)fHist->Fill(u);
if(k==1)bPlot->Fill(x,u,1); if(k==2)cPlot->Fill(x,u,1); if(k==3)dPlot->Fill(x,u,1);

if(m==0&&k==0){aPlot->Fill(x,u,1); eHist->Fill(u);}

if(m==1&&z>0){u=v/z-x;}
if(m==1&&k==1&&z>0&&ybb[j][0][jtr][ida][0]>230){
u=(ybb[j][0][jtr][ida][l]-ybb[j][0][jtr][ida][0])/z-x; aPlot->Fill(x,u,1);
eHist->Fill(u);
}
} /* jtr=jtx-1 */ } /* l */
wsm=sqrt(wsm/llx); if(k==0){gHist->Fill(wsm);} else{hHist->Fill(wsm);}

} /* wsm */ } /* j */


nr+=nq; y=0; if(nq>0){bbb/=nq; uv/=nq; y=uu/nq; ww/=nq; xsm=sqrt(xsm/(nq*llx));}
uw+=uv/4; vv+=y/4; xx+=bbb/4;
//n=nmz[k][ida]; if(n>0)zz=ww-zmx[k][ida]/n;
//printf(      "k=%d ida=%d nq=%4d ped=%5.0f mx=%5.0f slp=%5.2f n=%d diff=%3.0f xsm=%5.2f\n",k,ida,nq,ww,uv,y,n,zz,xsm);
//fprintf(fout,"k=%d ida=%d nq=%4d ped=%5.0f mx=%5.0f slp=%5.2f n=%d diff=%3.0f xsm=%5.2f\n",k,ida,nq,ww,uv,y,n,zz,xsm);
} /* ida */
printf(      "pixels=%d ped=%5.0f max=%5.0f dif=%5.0f slope=%5.2f\n",nr,xx,uw,uw-xx,vv);
fprintf(fout,"pixels=%d ped=%5.0f max=%5.0f dif=%5.0f slope=%5.2f\n",nr,xx,uw,uw-xx,vv);
} /* k */ } /* jtr */


//Generate table of corrections.
//for(l=1;l<llx;l++){
//for(k=0;k<4;k++){x=umx[l][k]/nmx[l][k]; printf(" %5.2f",x); fprintf(fout," %5.2f",x);}
//printf("\n"); fprintf(fout,"\n");}

// Read file for forced calibration.
//fin=fopen("calibr_2014_11_17_13_12_18.txt","r"); for(l=0;l<4096;l++){
//m=fscanf(fin,"%d %d %d %d %d %d",&j,&ida,&i0,&i1,&i2,&i3);
////printf(      " %4d %3d %6d %4d %5d %6d\n",j,ida,i0,i1,i2,i3);
////fprintf(fout," %4d %3d %6d %4d %5d %6d\n",j,ida,i0,i1,i2,i3);
//x=i0; dped[j][0][0][ida]=0.1*x; u=i1; pdq[j][0][0][ida][0]=0.1*u;
//z=i2; slp[j][0][0][ida]=0.1*z; x=i3; wsm=0.001*x; if(z>0)y=u/z;
//if(ida==10){qHist->Fill(y);} if(ida==12){rHist->Fill(y);}
////if(ida==14){sHist->Fill(y);} if(ida==16){tHist->Fill(y);}
//
//if(ida==10){mHist->Fill(wsm);} if(ida==12){nHist->Fill(wsm);}
//if(ida==14){oHist->Fill(wsm);} if(ida==16){pHist->Fill(wsm);}
//} fclose(fin);

// End process Raw Calibration file. =========




// Process Pedestal files. ===
nlo=752; nhi=758; jtn=0; jtx=0; jft=0; gmx=1; /*  default, skip section for jtx=0 */
for(jtr=jtn;jtr<25;jtr++){dac[jtr]=jtr; dll[jtr]=0;}

// special analysis plotting Pedestals: jsp=3.
 jsp=0; gn=0; tav=0; ipt=0; kpt=0; npt=10; ct0=0;

// 21 Pedestal files for stack of nine 05/08/13.
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1000
// strcpy(head[0],"/u1/w_si/samples/2013_05_08_10_54_40.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1100
// strcpy(head[1],"/u1/w_si/samples/2013_05_08_10_56_08.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1200
// strcpy(head[2],"/u1/w_si/samples/2013_05_08_10_57_05.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1300
// strcpy(head[3],"/u1/w_si/samples/2013_05_08_10_58_06.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1400
// strcpy(head[4],"/u1/w_si/samples/2013_05_08_11_17_42.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1500
// strcpy(head[5],"/u1/w_si/samples/2013_05_08_11_18_48.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1600
// strcpy(head[6],"/u1/w_si/samples/2013_05_08_11_19_52.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1700
// strcpy(head[7],"/u1/w_si/samples/2013_05_08_11_20_49.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1800
// strcpy(head[8],"/u1/w_si/samples/2013_05_08_11_21_47.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1900
// strcpy(head[9],"/u1/w_si/samples/2013_05_08_11_22_48.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2000
// strcpy(head[10],"/u1/w_si/samples/2013_05_08_11_23_51.bin");
// ext2, 1,010 cyc. del. 1-3=300    int. forced trig,=2000
//// strcpy(head[10],"/u1/w_si/samples/2013_05_08_17_11_44.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2100
// strcpy(head[11],"/u1/w_si/samples/2013_05_08_11_24_53.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2200
// strcpy(head[12],"/u1/w_si/samples/2013_05_08_11_25_52.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2300
// strcpy(head[13],"/u1/w_si/samples/2013_05_08_11_26_50.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2400
// strcpy(head[14],"/u1/w_si/samples/2013_05_08_11_27_48.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2500
// strcpy(head[15],"/u1/w_si/samples/2013_05_08_11_28_45.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2600
// strcpy(head[16],"/u1/w_si/samples/2013_05_08_11_29_45.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2700
// strcpy(head[17],"/u1/w_si/samples/2013_05_08_11_30_50.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2800
// strcpy(head[18],"/u1/w_si/samples/2013_05_08_11_31_54.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2900
// strcpy(head[19],"/u1/w_si/samples/2013_05_08_11_32_57.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=3000
// strcpy(head[20],"/u1/w_si/samples/2013_05_08_11_34_05.bin");
// jx=3; jk=4; jtx=21; jc4=(jtx-1)/2; nsn=9;

// Three Pedestal files drf for KPiX_1002, 10,000/50,000
// frc7, 1,010 cycles, clock 50 ns  int. forced trig,=1000
// strcpy(head[0],"/u1/w_si/samples/2013_05_14_21_43_50.bin");
// frc7, 1,010 cycles, clock 50 ns  int. forced trig,=2000
// strcpy(head[1],"/u1/w_si/samples/2013_05_14_21_44_48.bin");
// frc7, 1,010 cycles, clock 50 ns  int. forced trig,=3000
// strcpy(head[2],"/u1/w_si/samples/2013_05_14_21_45_55.bin");

// Three simult. calibration files for C0000, 15,000/50,000
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.5V        [fC]
// strcpy(head[0],"/u1/w_si/samples/2013_06_02_15_37_41.bin"); dac[0]=0;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.4V
// strcpy(head[1],"/u1/w_si/samples/2013_06_02_15_39_18.bin"); dac[1]=20;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.3V
// strcpy(head[2],"/u1/w_si/samples/2013_06_02_15_40_34.bin"); dac[2]=40;

// Three simult. calibration files for C0000, 100/50,000
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.5V        [fC]
// strcpy(head[0],"/u1/w_si/samples/2013_06_02_15_53_12.bin"); dac[0]=0;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.4V
// strcpy(head[1],"/u1/w_si/samples/2013_06_02_15_54_33.bin"); dac[1]=20;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.3V
// strcpy(head[2],"/u1/w_si/samples/2013_06_02_15_56_17.bin"); dac[2]=40;
// jx=3; jk=4; jtx=11; jc4=(jtx-1)/2; nsn=1;
// jx=3; jk=4; jtx=3; jc4=(jtx-1)/2; nsn=1;

// Nine simult. calibration files for C0000, 10,000/50,000
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.5V        [fC]
// strcpy(head[0],"/u1/w_si/samples/2013_06_04_22_08_31.bin"); dac[0]=0;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.45V
// strcpy(head[1],"/u1/w_si/samples/2013_06_04_22_09_33.bin"); dac[1]=10;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.40V
// strcpy(head[2],"/u1/w_si/samples/2013_06_04_22_10_33.bin"); dac[2]=20;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.3V
// strcpy(head[3],"/u1/w_si/samples/2013_06_04_22_11_37.bin"); dac[3]=40;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.2V
// strcpy(head[4],"/u1/w_si/samples/2013_06_04_22_12_41.bin"); dac[4]=60;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.0V
// strcpy(head[5],"/u1/w_si/samples/2013_06_04_22_13_48.bin"); dac[5]=100;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.8V
// strcpy(head[6],"/u1/w_si/samples/2013_06_04_22_14_54.bin"); dac[6]=140;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.5V
// strcpy(head[7],"/u1/w_si/samples/2013_06_04_22_16_09.bin"); dac[7]=200;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.2V
// strcpy(head[8],"/u1/w_si/samples/2013_06_04_22_18_47.bin"); dac[8]=260;
// jx=3; jk=4; jtx=9; jc4=(jtx-1)/2; nsn=1; idm=1;
// jx=3; jk=4; jtx=3; jc4=(jtx-1)/2; nsn=1; idm=1;

// Eleven simult. calibration files for A1002, 10,000/50,000
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.5V        [fC]
// strcpy(head[0],"/u1/w_si/samples/2013_06_07_11_43_50.bin"); dac[0]=0;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.45V
// strcpy(head[1],"/u1/w_si/samples/2013_06_07_11_44_56.bin"); dac[1]=10;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.40V
// strcpy(head[2],"/u1/w_si/samples/2013_06_07_11_45_55.bin"); dac[2]=20;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.3V
// strcpy(head[3],"/u1/w_si/samples/2013_06_07_11_46_59.bin"); dac[3]=40;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.2V
// strcpy(head[4],"/u1/w_si/samples/2013_06_07_11_48_02.bin"); dac[4]=60;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.0V
// strcpy(head[5],"/u1/w_si/samples/2013_06_07_11_49_03.bin"); dac[5]=100;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.8V
// strcpy(head[6],"/u1/w_si/samples/2013_06_07_11_50_05.bin"); dac[6]=140;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.5V
// strcpy(head[7],"/u1/w_si/samples/2013_06_07_11_51_08.bin"); dac[7]=200;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.2V
// strcpy(head[8],"/u1/w_si/samples/2013_06_07_11_53_46.bin"); dac[8]=260;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=0.9V
// strcpy(head[9],"/u1/w_si/samples/2013_06_07_11_54_48.bin"); dac[9]=320;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=0.5V
// strcpy(head[10],"/u1/w_si/samples/2013_06_07_11_55_48.bin"); dac[10]=400;
// jx=3; jk=4; jtx=11; jc4=(jtx-1)/2; nsn=1; idm=1;

// Nine simult. calibration files for C0000, 10,000/50,000 ext. power.
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.5V        [fC]
// strcpy(head[0],"/u1/w_si/samples/2013_06_10_21_41_31.bin"); dac[0]=0;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.45V
// strcpy(head[1],"/u1/w_si/samples/2013_06_10_21_42_33.bin"); dac[1]=10;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.40V
// strcpy(head[2],"/u1/w_si/samples/2013_06_10_21_43_38.bin"); dac[2]=20;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.3V
// strcpy(head[3],"/u1/w_si/samples/2013_06_10_21_44_50.bin"); dac[3]=40;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.2V
// strcpy(head[4],"/u1/w_si/samples/2013_06_10_21_45_52.bin"); dac[4]=60;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.0V
// strcpy(head[5],"/u1/w_si/samples/2013_06_10_21_47_03.bin"); dac[5]=100;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.8V
// strcpy(head[6],"/u1/w_si/samples/2013_06_10_21_48_17.bin"); dac[6]=140;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.5V
// strcpy(head[7],"/u1/w_si/samples/2013_06_10_21_49_35.bin"); dac[7]=200;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.2V
// strcpy(head[8],"/u1/w_si/samples/2013_06_10_21_50_43.bin"); dac[8]=260;
// jx=3; jk=4; jtx=9; jc4=(jtx-1)/2; nsn=1; idm=1;

// Eleven simult. calibration files for C0002, 10,000/50,000 Ryan's lab
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.5V        [fC]
// strcpy(head[0],"/u1/w_si/samples/2013_06_13_11_37_17.bin"); dac[0]=0;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.45V
// strcpy(head[1],"/u1/w_si/samples/2013_06_13_11_39_08.bin"); dac[1]=10;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.40V
// strcpy(head[2],"/u1/w_si/samples/2013_06_13_11_40_13.bin"); dac[2]=20;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.3V
// strcpy(head[3],"/u1/w_si/samples/2013_06_13_11_41_16.bin"); dac[3]=40;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.2V
// strcpy(head[4],"/u1/w_si/samples/2013_06_13_11_43_57.bin"); dac[4]=60;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.0V
// strcpy(head[5],"/u1/w_si/samples/2013_06_13_11_45_09.bin"); dac[5]=100;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.8V
// strcpy(head[6],"/u1/w_si/samples/2013_06_13_11_46_14.bin"); dac[6]=140;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.5V
// strcpy(head[7],"/u1/w_si/samples/2013_06_13_11_47_13.bin"); dac[7]=200;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.2V
// strcpy(head[8],"/u1/w_si/samples/2013_06_13_11_48_12.bin"); dac[8]=260;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=0.9V
// strcpy(head[9],"/u1/w_si/samples/2013_06_13_11_49_31.bin"); dac[9]=320;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=0.5V
// strcpy(head[10],"/u1/w_si/samples/2013_06_13_11_50_36.bin"); dac[10]=400;
// jx=3; jk=4; jtx=11; jc4=(jtx-1)/2; nsn=1; idm=1;

// Eleven simult. calibration files for C0003, 10,000/50,000
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.5V        [fC]
// strcpy(head[0],"/u1/w_si/samples/2013_06_13_12_57_25.bin"); dac[0]=0;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.45V
// strcpy(head[1],"/u1/w_si/samples/2013_06_13_12_58_28.bin"); dac[1]=10;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.40V
// strcpy(head[2],"/u1/w_si/samples/2013_06_13_12_59_28.bin"); dac[2]=20;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.3V
// strcpy(head[3],"/u1/w_si/samples/2013_06_13_13_00_32.bin"); dac[3]=40;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.2V
// strcpy(head[4],"/u1/w_si/samples/2013_06_13_13_01_39.bin"); dac[4]=60;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=2.0V
// strcpy(head[5],"/u1/w_si/samples/2013_06_13_13_02_49.bin"); dac[5]=100;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.8V
// strcpy(head[6],"/u1/w_si/samples/2013_06_13_13_03_55.bin"); dac[6]=140;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.5V
// strcpy(head[7],"/u1/w_si/samples/2013_06_13_13_07_32.bin"); dac[7]=200;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=1.2V
// strcpy(head[8],"/u1/w_si/samples/2013_06_13_13_08_32.bin"); dac[8]=260;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=0.9V
// strcpy(head[9],"/u1/w_si/samples/2013_06_13_13_09_35.bin"); dac[9]=320;
// frc9, 1,010 cycles, clock 50 ns  trig,=1000 DAC=0.5V
// strcpy(head[10],"/u1/w_si/samples/2013_06_13_13_10_38.bin"); dac[10]=400;
// jx=3; jk=4; jtx=11; jc4=(jtx-1)/2; nsn=1; idm=1;

// Eleven simult. calibration files for C0004, 10,000/50,000
// strcpy(head[0],"/u1/w_si/samples/2013_06_13_13_33_29.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_13_13_34_55.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_13_13_35_54.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_13_13_36_58.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_13_13_37_54.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_13_13_38_50.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_13_13_40_43.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_13_13_41_46.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_13_13_43_12.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_13_13_44_10.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_13_13_45_11.bin"); dac[10]=400;
// jx=3; jk=4; jtx=11; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0000, 10,000/50,000 KPiX-lab
// strcpy(head[0],"/u1/w_si/samples/2013_06_18_11_17_36.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_18_11_18_35.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_18_11_19_46.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_18_11_20_49.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_18_11_21_49.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_18_11_22_52.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_18_11_23_49.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_18_11_24_52.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_18_11_25_56.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_18_11_26_56.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_18_11_27_55.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_18_11_28_55.bin"); dac[11]=500;
// jx=3; jk=4; jtx=11; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0002, 10,000/50,000 KPiX-lab
// strcpy(head[0],"/u1/w_si/samples/2013_06_18_17_46_20.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_18_17_47_19.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_18_17_48_21.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_18_17_49_21.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_18_17_50_16.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_18_17_51_12.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_18_17_52_06.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_18_17_53_02.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_18_17_53_56.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_18_17_54_55.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_18_17_55_53.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_18_17_56_49.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0002, 10,000/30,000 KPiX-lab
// strcpy(head[0],"/u1/w_si/samples/2013_06_20_14_02_36.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_20_14_03_52.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_20_14_09_25.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_20_14_10_27.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_20_14_11_25.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_20_14_12_59.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_20_14_14_02.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_20_14_15_05.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_20_14_22_06.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_20_14_17_22.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_20_14_18_45.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_20_14_20_02.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0002, 10,000/16,000 KPiX-lab
// strcpy(head[0],"/u1/w_si/samples/2013_06_21_10_41_41.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_21_10_42_52.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_21_10_43_50.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_21_10_44_43.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_21_10_45_40.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_21_10_46_38.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_21_10_47_33.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_21_10_48_31.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_21_10_49_31.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_21_10_50_39.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_21_10_51_47.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_21_10_53_02.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0002, 10,000/16,000 KPiX-lab
// strcpy(head[0],"/u1/w_si/samples/2013_06_21_14_46_06.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_21_14_47_05.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_21_14_48_00.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_21_14_48_55.bin"); dac[3]=40;
//// strcpy(head[4],"/u1/w_si/samples/2013_06_21_14_49_49.bin"); dac[4]=60;
//// strcpy(head[5],"/u1/w_si/samples/2013_06_21_14_50_43.bin"); dac[5]=100;
//// strcpy(head[6],"/u1/w_si/samples/2013_06_21_14_51_38.bin"); dac[6]=140;
//// strcpy(head[7],"/u1/w_si/samples/2013_06_21_14_52_32.bin"); dac[7]=200;
//// strcpy(head[8],"/u1/w_si/samples/2013_06_21_14_53_26.bin"); dac[8]=260;
//// strcpy(head[9],"/u1/w_si/samples/2013_06_21_14_54_18.bin"); dac[9]=320;
//// strcpy(head[10],"/u1/w_si/samples/2013_06_21_14_55_14.bin"); dac[10]=400;
//// strcpy(head[11],"/u1/w_si/samples/2013_06_21_14_56_04.bin"); dac[11]=500;
// jx=3; jk=4; jtx=5; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0000, 10,000/16,000 box=AVDD
// strcpy(head[0],"/u1/w_si/samples/2013_06_25_15_24_48.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_25_15_25_50.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_25_15_26_47.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_25_15_27_46.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_25_15_28_38.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_25_15_29_30.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_25_15_30_26.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_25_15_31_17.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_25_15_32_09.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_25_15_33_03.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_25_15_33_59.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_25_15_34_56.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0000, 10,000/16,000 box=AGND
// strcpy(head[0],"/u1/w_si/samples/2013_06_26_15_09_39.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_26_15_10_37.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_26_15_11_30.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_26_15_12_26.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_26_15_13_21.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_26_15_14_16.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_26_15_15_08.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_26_15_16_00.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_26_15_16_58.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_26_15_18_19.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_26_15_19_14.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_26_15_20_09.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0000, 10,000/10,000 box=AGND
// strcpy(head[0],"/u1/w_si/samples/2013_06_27_07_08_55.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_27_07_10_05.bin"); dac[1]=10;
///// strcpy(head[2],"/u1/w_si/samples/2013_06_27_07_11_25.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_27_07_12_46.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_27_07_13_46.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_27_07_14_42.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_27_07_15_39.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_27_07_16_34.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_27_07_17_32.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_27_07_18_26.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_27_07_19_48.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_27_07_20_50.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for C0000, 10,000/10,000 box=AGND
// strcpy(head[0],"/u1/w_si/samples/2013_06_27_07_38_54.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_27_07_40_32.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_27_07_41_52.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_27_07_42_46.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_27_07_43_40.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_27_07_44_36.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_27_07_45_34.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_27_07_46_35.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_27_07_47_38.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_27_07_48_36.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_27_07_49_33.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_27_07_50_42.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=1;

// Twelve simult. calibration files for stack 10,000/320
// strcpy(head[0],"/u1/w_si/samples/2013_06_28_11_54_35.bin"); dac[0]=0;
// strcpy(head[1],"/u1/w_si/samples/2013_06_28_11_55_32.bin"); dac[1]=10;
// strcpy(head[2],"/u1/w_si/samples/2013_06_28_11_56_40.bin"); dac[2]=20;
// strcpy(head[3],"/u1/w_si/samples/2013_06_28_11_57_33.bin"); dac[3]=40;
// strcpy(head[4],"/u1/w_si/samples/2013_06_28_11_58_31.bin"); dac[4]=60;
// strcpy(head[5],"/u1/w_si/samples/2013_06_28_11_59_29.bin"); dac[5]=100;
// strcpy(head[6],"/u1/w_si/samples/2013_06_28_12_00_27.bin"); dac[6]=140;
// strcpy(head[7],"/u1/w_si/samples/2013_06_28_12_01_23.bin"); dac[7]=200;
// strcpy(head[8],"/u1/w_si/samples/2013_06_28_12_02_23.bin"); dac[8]=260;
// strcpy(head[9],"/u1/w_si/samples/2013_06_28_12_03_16.bin"); dac[9]=320;
// strcpy(head[10],"/u1/w_si/samples/2013_06_28_12_04_17.bin"); dac[10]=400;
// strcpy(head[11],"/u1/w_si/samples/2013_06_28_13_12_45.bin"); dac[11]=500;
// jx=3; jk=4; jtx=10; jc4=(jtx-1)/2; nsn=1; idm=9;

// Override for missing slopes.
// if(jtx<=11&&jtx>1){for(j=0;j<jn;j++){for(ida=0;ida<9;ida++){slp[j][0][0][ida]=5; iee[j][0][0][ida]=1;}}}

// ext1, 1,000,010 cycles, cosmic forced triggers. idm=9
// strcpy(head[0],"/u1/w_si/samples/2013_04_18_21_47_36.bin"); jx=1; jk=1; idm=9; jtx=1;
// strcpy(head[0],"/u1/kpix/data/2013_04_18_21_47_36.bin"); jx=1; jk=1; idm=9; jtx=1;
// ext2, 1,010 cycles, clock 50 ns  Pulse Gen. ~100 Hz (8191 b-clk)
//  ("/u1/w_si/samples/2013_04_25_13_45_33.bin"); jx=1; jk=1;
// ext2, 1,010 cycles, clock 50 ns  Pulse Gen. ~100 Hz (4500 b-clk)
//  ("/u1/w_si/samples/2013_04_25_13_53_15.bin"); jx=1; jk=1;

// ext1, 1,000,010 cycles, cosmic forced triggers. idm=9
// strcpy(head[0],"/u1/w_si/samples/2013_04_18_21_47_36.bin"); jx=1; jk=1; idm=9; jtx=1;
// ext2, 1,010 cycles, clock 50 ns  Pulse Gen. ~100 Hz (8191 b-clk)
//  ("/u1/w_si/samples/2013_04_25_13_45_33.bin"); jx=1; jk=1;
// ext2, 1,010 cycles, clock 50 ns  Pulse Gen. ~100 Hz (4500 b-clk)
//  ("/u1/w_si/samples/2013_04_25_13_53_15.bin"); jx=1; jk=1;
// ext2, frcd. trig. src: Internal, run mode: Calibrate, trg. src: None
//  ("/u1/w_si/samples/2013_04_25_16_53_41.bin"); jx=1; jk=1;
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1000  (8191 b-clk)
//  ("/u1/w_si/samples/2013_04_25_18_11_21.bin"); jx=1; jk=1;
// calint2 Stack in Lab. thrB=2.45V calDAC=251 (4fC)
// strcpy(head[0],"/u1/w_si/samples/2013_09_13_16_30_03.bin"); idm=9; jtx=1; jx=3; jk=1;
// calint2 Stack in Lab. thrB=0V calDAC=251 (4fC)
// strcpy(head[0],"/u1/w_si/samples/2013_09_13_21_53_53.bin"); idm=9; jtx=1; jx=3; jk=1;
// frc10 Stack in Lab. (CalSource=tru, Cal DAC =0, 500 fC, causes noise ~0.6 fC)
// strcpy(head[0],"/u1/w_si/samples/2013_09_21_14_06_37.bin"); idm=9; jx=3; jk=4; jtx=1;
// frc10 Stack in Lab. (CalSource->Disable, noise =0.4 fC)
// strcpy(head[0],"/u1/w_si/samples/2013_09_22_12_24_29.bin"); idm=9; jx=3; jk=4; jtx=1;

// Stack of nine
// frc11, 1,010 cycles, clock 70 ns
// strcpy(head[0],"/u1/w_si/samples/2013_10_12_16_39_48.bin"); dac[0]=0;
// ped6, several runs first 4 sensors in stack9.
// jx=3; jk=4; jtx=9; jc4=(jtx-1)/2; nsn=1; idm=9;
// strcpy(head[0],"/u1/w_si/samples/2013_12_04_16_30_36.bin"); dac[0]=0;
// jx=3; jk=4; jtx=4; jc4=(jtx-1)/2; nsn=1; idm=9;
// strcpy(head[0],"/u1/w_si/samples/2013_12_04_16_32_15.bin"); jx=3; jk=1; jtx=1; idm=4;
// strcpy(head[0],"/u1/w_si/samples/2013_12_05_11_28_17.bin"); dac[0]=0;
// jx=3; jk=4; jtx=4; jc4=(jtx-1)/2; nsn=1; idm=9;
// strcpy(head[0],"/u1/w_si/samples/2013_12_05_12_00_33.bin"); dac[0]=0;
// jx=3; jk=4; jtx=4; jc4=(jtx-1)/2; nsn=1; idm=9;
// strcpy(head[0],"/u1/w_si/samples/2013_12_05_12_06_33.bin"); dac[0]=0;
// jx=3; jk=4; jtx=4; jc4=(jtx-1)/2; nsn=1; idm=4;
// ped6, disab. DC rst, enab. per. rst
// strcpy(head[0],"/u1/w_si/samples/2013_12_05_17_49_12.bin"); jx=3; jk=1; jtx=1; idm=4;
// ped6, 4 calstr. 750, 10, 10, 10 (DC rst)
// strcpy(head[0],"/u1/w_si/samples/2013_12_10_12_32_35.bin"); jx=3; jk=4; jtx=1; idm=4;
// ped6, 4 calstr. 750, 20, 40, 60 (DC rst)
// strcpy(head[0],"/u1/w_si/samples/2013_12_10_14_04_58.bin"); jx=3; jk=4; jtx=1; idm=4;
// ped6, 4 calstr. 750, 20, 40, 60 (DC rst)
// strcpy(head[0],"/u1/w_si/samples/2013_12_10_15_01_33.bin"); jx=3; jk=4; jtx=1; idm=4;
// ped6_mod1 ST17
// strcpy(head[0],"/u1/w_si/samples/2014_01_18_12_11_50.bin"); jx=3; jk=1; jtx=1; idm=18;
// calint9 12 KPiX excluding 0, prech. 6000
//strcpy(head[0],"/u1/w_si/samples/2014_05_19_12_30_28.bin"); jx=3; jk=4; jtx=1; idm=17;
// calint9 12 KPiX excluding 0, prech. 100
//strcpy(head[0],"/u1/w_si/samples/2014_05_19_21_13_17.bin"); jx=3; jk=4; jtx=1; idm=17;
// calint9 12 KPiX excluding 0, prech. 20,000
//strcpy(head[0],"/u1/w_si/samples/2014_05_21_09_19_20.bin"); jx=3; jk=4; jtx=1; idm=17;
// calint9 12 KPiX excluding 0, prech. 40,000
//strcpy(head[0],"/u1/w_si/samples/2014_05_21_10_08_50.bin"); jx=3; jk=4; jtx=1; idm=17;
// calint9 12 KPiX excluding 0, prech. 100 run after power down, no prev. write to memory.
//strcpy(head[0],"/u1/w_si/samples/2014_05_27_12_17_54.bin"); jx=3; jk=4; jtx=1; idm=17;
//cal12 1000, 10000, 11000 data run 400 evts.
//strcpy(head[0],"/u1/w_si/samples/2014_06_16_22_21_04.bin"); jx=3; jk=1; jtx=1; idm=17;
//chris, offs. null 6000 to 5000
//strcpy(head[0],"/u1/w_si/samples/2014_06_21_11_14_01.bin"); jx=3; jk=1; jtx=1; idm=17;
//chris, offs. null 6000 to 5000, low gain
//strcpy(head[0],"/u1/w_si/samples/2014_06_21_11_23_14.bin"); jx=3; jk=1; jtx=1; idm=17;
//chris, offs. null 6000          normal gain
//strcpy(head[0],"/u1/w_si/samples/2014_06_21_17_55_27.bin"); jx=3; jk=1; jtx=1; idm=17;
//chris, offs. null 4000          normal gain
//strcpy(head[0],"/u1/w_si/samples/2014_06_21_18_16_08.bin"); jx=3; jk=1; jtx=1; idm=17;
//chris, offs. null 3000          normal gain
//strcpy(head[0],"/u1/w_si/samples/2014_06_21_18_21_04.bin"); jx=3; jk=1; jtx=1; idm=17;
//chris, offs. null 4000 RST=3000 normal gain
//strcpy(head[0],"/u1/w_si/samples/2014_06_22_12_24_13.bin"); jx=3; jk=1; jtx=1; idm=17;
//cal12, offs. null 3000 RST=3000 thr 7000 b.clk 10200 low gain
//strcpy(head[0],"/u1/w_si/samples/2014_06_24_18_38_51.bin"); jx=3; jk=1; jtx=1; idm=17;
//cal12, offs. null 3000 RST=3000 thr 7000 b.clk 10200 low gain
//strcpy(head[0],"/u1/w_si/samples/2014_06_26_10_02_33.bin"); jx=3; jk=1; jtx=1; idm=17;
//Five calibration files for kpix_1-16 channels 16, normal gain.
//strcpy(head[0],"/u1/w_si/samples/2014_06_26_20_43_06.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_26_20_43_58.bin"); dac[1]=100;
//strcpy(head[2],"/u1/w_si/samples/2014_06_26_20_44_40.bin"); dac[2]=200;
//strcpy(head[3],"/u1/w_si/samples/2014_06_26_20_45_22.bin"); dac[3]=300;
//strcpy(head[4],"/u1/w_si/samples/2014_06_26_20_46_02.bin"); dac[4]=400;
//jx=3; jk=1; jtx=5;
//Five calibration files for kpix_1-16 channels 16, low gain.
//strcpy(head[0],"/u1/w_si/samples/2014_06_26_20_48_18.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_26_20_49_10.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_26_20_49_46.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_26_20_50_24.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_26_20_51_01.bin"); dac[4]=8800;
//gmx=2; jx=3; jk=1; jtx=5;
//Five calibration files for kpix_1-16 channels 16, low gain, disab. pwr. cycle
//strcpy(head[0],"/u1/w_si/samples/2014_06_27_16_29_34.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_27_16_30_25.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_27_16_31_03.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_27_16_31_38.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_27_16_32_34.bin"); dac[4]=8800;
//gmx=2; jx=3; jk=1; jtx=5;
//Five calibration files for kpix_1-16 channels 16, low gain, b.cl, 40,000
//strcpy(head[0],"/u1/w_si/samples/2014_06_27_16_50_15.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_27_16_51_27.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_27_16_52_07.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_27_16_52_38.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_27_16_53_11.bin"); dac[4]=8800;
//gmx=2; jx=3; jk=1; jtx=5;
//Five calibration files for kpix_1-16 channels 16, low gain, thr.off 12,000
//strcpy(head[0],"/u1/w_si/samples/2014_06_27_17_00_58.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_27_17_01_55.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_27_17_02_32.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_27_17_03_08.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_27_17_03_47.bin"); dac[4]=8800;
//gmx=2; jx=3; jk=1; jtx=5;
//Five calibration files for kpix_1-16 channels 16, from cal12, b.cl. 10000
//strcpy(head[0],"/u1/w_si/samples/2014_06_27_18_14_11.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_27_18_15_01.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_27_18_15_44.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_27_18_16_16.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_27_18_16_54.bin"); dac[4]=8800;
//gmx=2; jx=3; jk=1; jtx=5;
//Six calibration files for kpix_1-16 channels 16, from cal12, thr.off=20,000
//strcpy(head[0],"/u1/w_si/samples/2014_06_29_11_51_22.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_29_11_52_20.bin"); dac[1]=100;
//strcpy(head[2],"/u1/w_si/samples/2014_06_29_11_53_16.bin"); dac[2]=200;
//strcpy(head[3],"/u1/w_si/samples/2014_06_29_11_53_49.bin"); dac[3]=300;
//strcpy(head[4],"/u1/w_si/samples/2014_06_29_11_54_40.bin"); dac[4]=400;
//strcpy(head[5],"/u1/w_si/samples/2014_06_29_11_55_13.bin"); dac[5]=500;
//gmx=1; jx=3; jk=1; jtx=6;
//Six calibration files for kpix_1-16 channels 16, from cal12, thr.off=20,000
//strcpy(head[0],"/u1/w_si/samples/2014_06_29_12_16_17.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_29_12_17_23.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_29_12_17_58.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_29_12_18_34.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_29_12_19_09.bin"); dac[4]=8800;
//strcpy(head[5],"/u1/w_si/samples/2014_06_29_12_19_45.bin"); dac[5]=11000;
//gmx=2; jx=3; jk=1; jtx=6;
//Six calibration files for kpix_1-16 channels 16, from cal12, thr.off=28,000
//strcpy(head[0],"/u1/w_si/samples/2014_06_29_15_24_12.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_29_15_25_09.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_29_15_25_43.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_29_15_26_17.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_29_15_26_51.bin"); dac[4]=8800;
//strcpy(head[5],"/u1/w_si/samples/2014_06_29_15_27_22.bin"); dac[5]=11000;
//gmx=2; jx=3; jk=1; jtx=6;
//Six calibration files for kpix_1-16 drive 16 pix from cal12, thr.off=30,000
//strcpy(head[0],"/u1/w_si/samples/2014_06_30_16_53_13.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_30_16_56_10.bin"); dac[1]=1890;
//strcpy(head[2],"/u1/w_si/samples/2014_06_30_16_57_13.bin"); dac[2]=4000;
//strcpy(head[3],"/u1/w_si/samples/2014_06_30_16_57_58.bin"); dac[3]=6270;
//strcpy(head[4],"/u1/w_si/samples/2014_06_30_16_58_36.bin"); dac[4]=8600;
//strcpy(head[5],"/u1/w_si/samples/2014_06_30_16_59_12.bin"); dac[5]=11000;
//gmx=2; jx=3; jk=1; jtx=6;
//Six calibration files for kpix_1-16 drive 16 pix from cal12, thr.off=30,000
//strcpy(head[0],"/u1/w_si/samples/2014_06_30_16_53_13.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_06_30_16_56_10.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_06_30_16_57_13.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_06_30_16_57_58.bin"); dac[3]=6600;
//strcpy(head[4],"/u1/w_si/samples/2014_06_30_16_58_36.bin"); dac[4]=8800;
//strcpy(head[5],"/u1/w_si/samples/2014_06_30_16_59_12.bin"); dac[5]=11000;
//gmx=2; jx=3; jk=1; jtx=6;
//Ten calibration files 2014_07_01_08_08_17, from cal12, thr.off=9,000
//strcpy(head[0],"/u1/w_si/samples/2014_07_01_08_08_17.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_01_08_09_42.bin"); dac[1]=2200;
//strcpy(head[2],"/u1/w_si/samples/2014_07_01_08_10_32.bin"); dac[2]=4400;
//strcpy(head[3],"/u1/w_si/samples/2014_07_01_08_11_23.bin"); dac[3]=5324;
//strcpy(head[4],"/u1/w_si/samples/2014_07_01_08_12_02.bin"); dac[4]=5368;
//strcpy(head[5],"/u1/w_si/samples/2014_07_01_08_12_42.bin"); dac[5]=5412;
//strcpy(head[6],"/u1/w_si/samples/2014_07_01_08_13_29.bin"); dac[6]=5456;
//strcpy(head[7],"/u1/w_si/samples/2014_07_01_08_14_06.bin"); dac[7]=6600;
//strcpy(head[8],"/u1/w_si/samples/2014_07_01_08_14_44.bin"); dac[8]=8800;
//strcpy(head[9],"/u1/w_si/samples/2014_07_01_08_15_27.bin"); dac[9]=11000;
//gmx=2; jx=3; jk=1; jtx=10;
//Ten calibration files 2014_07_01_08_08_17, from cal12, thr.off=9,000 corr. KPiX_A
//strcpy(head[0],"/u1/w_si/samples/2014_07_01_08_08_17.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_01_08_09_42.bin"); dac[1]=2030;
//strcpy(head[2],"/u1/w_si/samples/2014_07_01_08_10_32.bin"); dac[2]=4200;
//strcpy(head[3],"/u1/w_si/samples/2014_07_01_08_11_23.bin"); dac[3]=5130;
//strcpy(head[4],"/u1/w_si/samples/2014_07_01_08_12_02.bin"); dac[4]=5170;
//strcpy(head[5],"/u1/w_si/samples/2014_07_01_08_12_42.bin"); dac[5]=5210;
//strcpy(head[6],"/u1/w_si/samples/2014_07_01_08_13_29.bin"); dac[6]=5250;
//strcpy(head[7],"/u1/w_si/samples/2014_07_01_08_14_06.bin"); dac[7]=6470;
//strcpy(head[8],"/u1/w_si/samples/2014_07_01_08_14_44.bin"); dac[8]=8720;
//strcpy(head[9],"/u1/w_si/samples/2014_07_01_08_15_27.bin"); dac[9]=11000;
//gmx=2; jx=3; jk=1; jtx=10;
//Ten calibration files 2014_07_01_08_08_17, from cal12, thr.off=9,000 corr. KPiX_C
//strcpy(head[0],"/u1/w_si/samples/2014_07_01_08_08_17.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_01_08_09_42.bin"); dac[1]=1890;
//strcpy(head[2],"/u1/w_si/samples/2014_07_01_08_10_32.bin"); dac[2]=4000;
//strcpy(head[3],"/u1/w_si/samples/2014_07_01_08_11_23.bin"); dac[3]=4924;
//strcpy(head[4],"/u1/w_si/samples/2014_07_01_08_12_02.bin"); dac[4]=4968;
//strcpy(head[5],"/u1/w_si/samples/2014_07_01_08_12_42.bin"); dac[5]=5012;
//strcpy(head[6],"/u1/w_si/samples/2014_07_01_08_13_29.bin"); dac[6]=5056;
//strcpy(head[7],"/u1/w_si/samples/2014_07_01_08_14_06.bin"); dac[7]=6270;
//strcpy(head[8],"/u1/w_si/samples/2014_07_01_08_14_44.bin"); dac[8]=8600;
//strcpy(head[9],"/u1/w_si/samples/2014_07_01_08_15_27.bin"); dac[9]=11000;
//gmx=2; jx=3; jk=1; jtx=10;
//Eleven cal-files kpix_1-16 cal12,cal-h=false, frc. lg.=false cal hg=true
//Raw data show gn=0.
//strcpy(head[0],"/u1/w_si/samples/2014_07_07_11_04_35.bin"); dac[0]=0;   dll[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_07_11_05_32.bin"); dac[1]=10;  dll[1]=0.9;
//strcpy(head[2],"/u1/w_si/samples/2014_07_07_11_06_17.bin"); dac[2]=30;  dll[2]=2.1;
//strcpy(head[3],"/u1/w_si/samples/2014_07_07_11_06_53.bin"); dac[3]=50;  dll[3]=2.5;
//strcpy(head[4],"/u1/w_si/samples/2014_07_07_11_07_26.bin"); dac[4]=70;  dll[4]=2.5;
//strcpy(head[5],"/u1/w_si/samples/2014_07_07_11_08_04.bin"); dac[5]=90;  dll[5]=2.2;
//strcpy(head[6],"/u1/w_si/samples/2014_07_07_11_08_42.bin"); dac[6]=110; dll[6]=1.2;
//strcpy(head[7],"/u1/w_si/samples/2014_07_07_11_09_23.bin"); dac[7]=130; dll[7]=0;
////strcpy(head[8],"/u1/w_si/samples/2014_07_07_11_10_48.bin"); dac[8]=150;
////strcpy(head[9],"/u1/w_si/samples/2014_07_07_11_11_39.bin"); dac[9]=170;
////strcpy(head[10],"/u1/w_si/samples/2014_07_07_11_13_01.bin"); dac[10]=190;
//gmx=1; jx=3; jk=1; jtx=8;
//Nine cal-files kpix_1-16 cal12,cal-h=false, frc. lg.=false
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin"); dac[0]=0;   dll[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_07_18_11_23.bin"); dac[1]=0;   dll[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_07_07_18_12_07.bin"); dac[2]=10;  dll[2]=0.9;
//strcpy(head[3],"/u1/w_si/samples/2014_07_07_18_12_51.bin"); dac[3]=30;  dll[3]=2.1;
//strcpy(head[4],"/u1/w_si/samples/2014_07_07_18_13_24.bin"); dac[4]=50;  dll[4]=2.5;
//strcpy(head[5],"/u1/w_si/samples/2014_07_07_18_13_58.bin"); dac[5]=70;  dll[5]=2.5;
//strcpy(head[6],"/u1/w_si/samples/2014_07_07_18_14_37.bin"); dac[6]=90;  dll[6]=2.2;
//strcpy(head[7],"/u1/w_si/samples/2014_07_07_18_16_53.bin"); dac[7]=110; dll[7]=1.2;
//strcpy(head[8],"/u1/w_si/samples/2014_07_07_18_15_55.bin"); dac[8]=130; dll[8]=0;
//gmx=1; jx=3; jk=1; jtn=1; jtx=9;
//Eleven calibration files 2014_07_01_08_08_17, from cal12, thr.off=28,000
//strcpy(head[0],"/u1/w_si/samples/2014_07_12_15_44_09.bin"); dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_12_15_45_57.bin"); dac[1]=440;
//strcpy(head[2],"/u1/w_si/samples/2014_07_12_15_47_30.bin"); dac82]=2200;
//strcpy(head[3],"/u1/w_si/samples/2014_07_12_15_48_06.bin"); dac[3]=4400;
//strcpy(head[4],"/u1/w_si/samples/2014_07_12_15_48_40.bin"); dac[4]=5324;
//strcpy(head[5],"/u1/w_si/samples/2014_07_12_15_49_15.bin"); dac[5]=5368;
//strcpy(head[6],"/u1/w_si/samples/2014_07_12_15_49_43.bin"); dac[6]=5412;
//strcpy(head[7],"/u1/w_si/samples/2014_07_12_15_50_20.bin"); dac[7]=5456;
//strcpy(head[8],"/u1/w_si/samples/2014_07_12_15_50_54.bin"); dac[8]=6600;
//strcpy(head[9],"/u1/w_si/samples/2014_07_12_15_51_33.bin"); dac[9]=8800;
//strcpy(head[10],"/u1/w_si/samples/2014_07_12_15_52_04.bin"); dac[10]=11000;
//gmx=2; jx=3; jk=1; jtx=11;
//Twelve calibration files 2014_07_01_08_08_17, from cal12, thr.off=28,000
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_14_19.bin"); dac[0]=0; dll[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_12_15_44_09.bin"); dac[1]=0; dll[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_07_12_15_45_57.bin"); dac[2]=440; dll[2]=95;
//strcpy(head[3],"/u1/w_si/samples/2014_07_12_15_47_30.bin"); dac[3]=2200; dll[3]=304;
//strcpy(head[4],"/u1/w_si/samples/2014_07_12_15_48_06.bin"); dac[4]=4400; dll[4]=366;
//strcpy(head[5],"/u1/w_si/samples/2014_07_12_15_48_40.bin"); dac[5]=5324; dll[5]=346;
//strcpy(head[6],"/u1/w_si/samples/2014_07_12_15_49_15.bin"); dac[6]=5368; dll[6]=345;
//strcpy(head[7],"/u1/w_si/samples/2014_07_12_15_49_43.bin"); dac[7]=5412; dll[7]=340;
//strcpy(head[8],"/u1/w_si/samples/2014_07_12_15_50_20.bin"); dac[8]=5456; dll[8]=338;
//strcpy(head[9],"/u1/w_si/samples/2014_07_12_15_50_54.bin"); dac[9]=6600; dll[9]=298;
//strcpy(head[10],"/u1/w_si/samples/2014_07_12_15_51_33.bin"); dac[10]=8800; dll[10]=177;
//strcpy(head[11],"/u1/w_si/samples/2014_07_12_15_52_04.bin"); dac[11]=11000; dll[11]=0;
//gmx=2; jx=3; jk=1; jtx=12;
//Twelve calibration files 2014_07_01_08_08_17, from cal12, thr.off=28,000
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_14_19.bin"); dac[0]=0; dll[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_17_10_31_18.bin"); dac[1]=0; dll[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_07_17_10_33_37.bin"); dac[2]=440; dll[2]=95;
//strcpy(head[3],"/u1/w_si/samples/2014_07_17_10_34_22.bin"); dac[3]=1896; dll[3]=304;
//strcpy(head[4],"/u1/w_si/samples/2014_07_17_10_34_55.bin"); dac[4]=4400; dll[4]=366;
//strcpy(head[5],"/u1/w_si/samples/2014_07_17_10_35_31.bin"); dac[5]=5324; dll[5]=346;
//strcpy(head[6],"/u1/w_si/samples/2014_07_17_10_36_09.bin"); dac[6]=5368; dll[6]=345;
//strcpy(head[7],"/u1/w_si/samples/2014_07_17_10_36_45.bin"); dac[7]=5412; dll[7]=340;
//strcpy(head[8],"/u1/w_si/samples/2014_07_17_10_37_21.bin"); dac[8]=5456; dll[8]=338;
//strcpy(head[9],"/u1/w_si/samples/2014_07_17_10_38_07.bin"); dac[9]=6600; dll[9]=298;
//strcpy(head[10],"/u1/w_si/samples/2014_07_17_11_25_32.bin"); dac[10]=8800; dll[10]=177;
//strcpy(head[11],"/u1/w_si/samples/2014_07_17_11_22_58.bin"); dac[11]=10560; dll[11]=177;
//strcpy(head[12],"/u1/w_si/samples/2014_07_17_10_39_22.bin"); dac[12]=11000; dll[12]=0;
//gmx=2; jx=3; jk=1; jtx=13;
//Eleven calibration files 2014_07_13_11_18_27, from cal12, thr.off=28,000
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin"); dac[0]=0;     /*dll[0]=0;    */dll[0]=  0; 
//strcpy(head[1],"/u1/w_si/samples/2014_07_13_11_18_27.bin"); dac[1]=0;     /*dll[1]=0;    */dll[1]=  0; 
//strcpy(head[2],"/u1/w_si/samples/2014_07_13_11_19_13.bin"); dac[2]=100;   /*dll[2]=11.5; */dll[2]=  0; 
//strcpy(head[3],"/u1/w_si/samples/2014_07_13_11_20_13.bin"); dac[3]=200;   /*dll[3]=13.5; */dll[3]= -9.5; 
//strcpy(head[4],"/u1/w_si/samples/2014_07_13_11_21_20.bin"); dac[4]=242;   /*dll[4]=12.5; */dll[4]= -15.3; 
//strcpy(head[5],"/u1/w_si/samples/2014_07_13_11_21_54.bin"); dac[5]=244;   /*dll[5]=12.5; */dll[5]= -15.5;
//strcpy(head[6],"/u1/w_si/samples/2014_07_13_11_22_29.bin"); dac[6]=246;   /*dll[6]=12.5; */dll[6]= -15.8; 
//strcpy(head[7],"/u1/w_si/samples/2014_07_13_11_23_14.bin"); dac[7]=248;   /*dll[7]=12.5; */dll[7]= -16.0; 
//strcpy(head[8],"/u1/w_si/samples/2014_07_13_11_23_50.bin"); dac[8]=300;   /*dll[8]=11;   */dll[8]= -23.5; 
//strcpy(head[9],"/u1/w_si/samples/2014_07_13_11_24_29.bin"); dac[9]=400;   /*dll[9]=7;    */dll[9]= -39.0; 
//strcpy(head[10],"/u1/w_si/samples/2014_07_13_11_25_10.bin"); dac[10]=500; /*dll[10]=0;   */dll[10]=-57.5;
//gmx=1; jx=3; jk=1; jtn=1; jtx=11;
//Thirteen files all cal. 2014_07_13_11_18_27, from cal12, thr.off=28,000 all pix cal.
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin");  dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_17_11_27_57.bin");  dac[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_07_17_11_28_50.bin");  dac[2]=20;   /*dll[2]=2.7;  dll[2]=5;    */dll[2]=0.0;
//strcpy(head[3],"/u1/w_si/samples/2014_07_17_11_29_25.bin");  dac[3]=100;  /*dll[3]=6.3;  dll[3]=11.5; */dll[3]=1.6;
//strcpy(head[4],"/u1/w_si/samples/2014_07_17_11_29_59.bin");  dac[4]=200;  /*dll[4]=4.7;  dll[4]=13.5; */dll[4]=4.8; 
//strcpy(head[5],"/u1/w_si/samples/2014_07_17_11_43_50.bin");  dac[5]=242;  /*dll[5]=3.0;  dll[5]=12.5; */dll[5]=6.9; 
//strcpy(head[6],"/u1/w_si/samples/2014_07_17_11_44_21.bin");  dac[6]=244;  /*dll[6]=2.7;  dll[6]=12.5; */dll[6]=7.0;  
//strcpy(head[7],"/u1/w_si/samples/2014_07_17_11_44_57.bin");  dac[7]=246;  /*dll[7]=-1.0; dll[7]=12.5; */dll[7]=7.0;  
//strcpy(head[8],"/u1/w_si/samples/2014_07_17_11_45_33.bin");  dac[8]=248;  /*dll[8]=-1.0; dll[8]=12.5; */dll[8]=7.1;  
//strcpy(head[9],"/u1/w_si/samples/2014_07_17_12_23_27.bin");  dac[9]=300;  /*dll[9]=-4.0; dll[9]=11;   */dll[9]=9.7;
//strcpy(head[10],"/u1/w_si/samples/2014_07_17_11_46_34.bin"); dac[10]=400; /*dll[10]=-1.5;dll[10]=7;   */dll[10]=16.0;
//strcpy(head[11],"/u1/w_si/samples/2014_07_17_12_24_04.bin"); dac[11]=480; /*dll[11]=0;   dll[11]=2;   */dll[11]=21.4;
//strcpy(head[12],"/u1/w_si/samples/2014_07_17_11_47_38.bin"); dac[12]=500; /*dll[12]=0;   dll[12]=0;   */dll[12]=23.3; 
//gmx=1; jx=3; jk=1; jtn=1; jtx=11; jft=5;
//Thirteen files all cal. 2014_07_13_11_18_27, from cal12, thr.off=28,000 cal 0-127.
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin");  dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_29_17_14_53.bin");  dac[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_07_29_17_15_59.bin");  dac[2]=20;   dll[2]=0;    //dll[2]=5;    dll[2]=0.1;
//strcpy(head[3],"/u1/w_si/samples/2014_07_29_17_16_38.bin");  dac[3]=100;  dll[3]=-3;   //dll[3]=11.5; dll[3]=2.5;
//strcpy(head[4],"/u1/w_si/samples/2014_07_29_17_17_12.bin");  dac[4]=200;  dll[4]=-13;  //dll[4]=13.5; dll[4]=4.3; 
//strcpy(head[5],"/u1/w_si/samples/2014_07_29_17_17_49.bin");  dac[5]=242;  dll[5]=-20;  //dll[5]=12.5; dll[5]=7.1; 
//strcpy(head[6],"/u1/w_si/samples/2014_07_29_17_18_25.bin");  dac[6]=244;  dll[6]=-20;  //dll[6]=12.5; dll[6]=7.6;  
//strcpy(head[7],"/u1/w_si/samples/2014_07_29_17_19_06.bin");  dac[7]=246;  dll[7]=-16;  //dll[7]=12.5; dll[7]=7.6;  
//strcpy(head[8],"/u1/w_si/samples/2014_07_29_17_19_48.bin");  dac[8]=248;  dll[8]=-16.0;//dll[8]=12.5; dll[8]=7.3;  
//strcpy(head[9],"/u1/w_si/samples/2014_07_29_17_20_35.bin");  dac[9]=300;  dll[9]=-19.; //dll[9]=11;   dll[9]=9.1;
//strcpy(head[10],"/u1/w_si/samples/2014_07_29_17_22_07.bin"); dac[10]=400; dll[10]=-19; //dll[10]=7;   dll[10]=19;  
//strcpy(head[11],"/u1/w_si/samples/2014_07_29_17_22_51.bin"); dac[11]=480; dll[11]=0;   //dll[11]=2;   dll[11]=21.5;
//strcpy(head[12],"/u1/w_si/samples/2014_07_29_17_23_24.bin"); dac[12]=500; dll[12]=0;   //dll[12]=0;   dll[12]=25.5; 
//gmx=1; jx=3; jk=1; jtn=1; jtx=13; jft=13;
//Sixteen files all cal. 2014_07_13_11_18_27, from cal12, thr.off=28,000 cal 0-63.
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin");  dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_30_11_39_15.bin");  dac[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_07_30_11_40_18.bin");  dac[2]=20;   dll[2]=0.9;   //dll[2]=5;    dll[2]=0;  
//strcpy(head[3],"/u1/w_si/samples/2014_07_30_11_40_55.bin");  dac[3]=40;   dll[3]=0.7;   //dll[3]=11.5; dll[3]=0;
//strcpy(head[4],"/u1/w_si/samples/2014_07_30_11_41_26.bin");  dac[4]=60;   dll[4]=0;     //dll[4]=13.5; dll[4]=-9.5; 
//strcpy(head[5],"/u1/w_si/samples/2014_07_30_11_41_59.bin");  dac[5]=80;   dll[5]=-0.7;  //dll[5]=12.5; dll[5]=-15.3; 
//strcpy(head[6],"/u1/w_si/samples/2014_07_30_11_42_39.bin");  dac[6]=100;  dll[6]=-2.1;  //dll[6]=12.5; dll[6]=-15.5;  
//strcpy(head[7],"/u1/w_si/samples/2014_07_30_11_43_19.bin");  dac[7]=200;  dll[7]=-11.7; //dll[7]=12.5; dll[7]=-15.8;  
//strcpy(head[8],"/u1/w_si/samples/2014_07_30_11_44_02.bin");  dac[8]=242;  dll[8]=-18.2; //dll[8]=12.5; dll[8]=-16.0;  
//strcpy(head[9],"/u1/w_si/samples/2014_07_30_11_44_36.bin");  dac[9]=244;  dll[9]=-18.5; //dll[9]=11;   dll[9]=-23.5;
//strcpy(head[10],"/u1/w_si/samples/2014_07_30_11_45_11.bin"); dac[10]=246; dll[10]=-15.2;//dll[10]=7;   dll[10]=-39;  
//strcpy(head[11],"/u1/w_si/samples/2014_07_30_11_45_48.bin"); dac[11]=248; dll[11]=-15.0;//dll[11]=2;   dll[11]=-55.5;
//strcpy(head[12],"/u1/w_si/samples/2014_07_30_11_46_25.bin"); dac[12]=300; dll[12]=-17.5;//dll[12]=0;   dll[12]=-57.5; 
//strcpy(head[13],"/u1/w_si/samples/2014_07_30_11_47_01.bin"); dac[13]=400; dll[13]=-27.4;//dll[13]=7;   dll[13]=-39;  
//strcpy(head[14],"/u1/w_si/samples/2014_07_30_11_47_36.bin"); dac[14]=460; dll[14]=-39.1;//dll[14]=2;   dll[14]=-55.5;
//strcpy(head[15],"/u1/w_si/samples/2014_07_30_11_48_26.bin"); dac[15]=500; dll[15]=-38.2;//dll[15]=0;   dll[15]=-57.5; 
//gmx=1; jx=3; jk=1; jtn=1; jtx=16; jft=8;
//Sixteen files all cal. 2014_07_13_11_18_27, from cal12, thr.off=28,000 cal 960-1023.
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin");  dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_07_30_17_46_22.bin");  dac[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_07_30_17_47_09.bin");  dac[2]=20;   /*dll[2]=0.9;   */dll[2]=0.9;  //dll[2]=0;  
//strcpy(head[3],"/u1/w_si/samples/2014_07_30_17_47_45.bin");  dac[3]=40;   /*dll[3]=0.7;   */dll[3]=0.7;  //dll[3]=0;
//strcpy(head[4],"/u1/w_si/samples/2014_07_30_17_48_18.bin");  dac[4]=60;   /*dll[4]=0;     */dll[4]=0.0;  //dll[4]=-9.5; 
//strcpy(head[5],"/u1/w_si/samples/2014_07_30_17_48_49.bin");  dac[5]=80;   /*dll[5]=-0.7;  */dll[5]=-0.7; //dll[5]=-15.3; 
//strcpy(head[6],"/u1/w_si/samples/2014_07_30_17_49_18.bin");  dac[6]=100;  /*dll[6]=-2.1;  */dll[6]=-2.1; //dll[6]=-15.5;  
//strcpy(head[7],"/u1/w_si/samples/2014_07_30_17_49_51.bin");  dac[7]=200;  /*dll[7]=-11.7; */dll[7]=-11.7;//dll[7]=-15.8;  
//strcpy(head[8],"/u1/w_si/samples/2014_07_30_17_50_27.bin");  dac[8]=242;  /*dll[8]=-18.2; */dll[8]=-18.2;//dll[8]=-16.0;  
//strcpy(head[9],"/u1/w_si/samples/2014_07_30_17_50_57.bin");  dac[9]=244;  /*dll[9]=-18.5; */dll[9]=-18.5;//dll[9]=-23.5;
//strcpy(head[10],"/u1/w_si/samples/2014_07_30_17_51_33.bin"); dac[10]=246; /*dll[10]=-15.2;*/dll[10]=-18; //dll[10]=-39;  
//strcpy(head[11],"/u1/w_si/samples/2014_07_30_17_52_08.bin"); dac[11]=248; /*dll[11]=-15.0;*/dll[11]=-18; //dll[11]=-55.5;
//strcpy(head[12],"/u1/w_si/samples/2014_07_30_17_52_41.bin"); dac[12]=300; /*dll[12]=-17.5;*/dll[12]=-24; //dll[12]=-57.5; 
//strcpy(head[13],"/u1/w_si/samples/2014_07_30_17_53_18.bin"); dac[13]=400; /*dll[13]=-27.4;*/dll[13]=-61; //dll[13]=-39;  
//strcpy(head[14],"/u1/w_si/samples/2014_07_30_17_53_54.bin"); dac[14]=460; /*dll[14]=-39.1;*/dll[14]=-95; //dll[14]=-55.5;
//strcpy(head[15],"/u1/w_si/samples/2014_07_30_17_54_29.bin"); dac[15]=500; /*dll[15]=-38.2;*/dll[15]=-102;//dll[15]=-57.5; 
//gmx=1; jx=3; jk=1; jtn=1; jtx=16; jft=8;
//Sixteen files 2014_08_01_18_59_29, from cal12, thr.off=28,000 cal pix14 only.
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin");  dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_08_01_18_59_29.bin");  dac[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_08_01_19_00_36.bin");  dac[2]=20;   /*dll[2]=-0.8;  dll[2]=5;    */dll[2]=2.2;
//strcpy(head[3],"/u1/w_si/samples/2014_08_01_19_01_14.bin");  dac[3]=40;   /*dll[3]=-0.6;  dll[3]=11.5; */dll[3]=0.7;
//strcpy(head[4],"/u1/w_si/samples/2014_08_01_19_01_44.bin");  dac[4]=60;   /*dll[4]=-0.2;  dll[4]=13.5; */dll[4]=0.3; 
//strcpy(head[5],"/u1/w_si/samples/2014_08_01_19_02_21.bin");  dac[5]=80;   /*dll[5]=0.5;   dll[5]=12.5; */dll[5]=1.1;
//strcpy(head[6],"/u1/w_si/samples/2014_08_01_19_03_07.bin");  dac[6]=100;  /*dll[6]=1.7;   dll[6]=12.5; */dll[6]=1.9;  
//strcpy(head[7],"/u1/w_si/samples/2014_08_01_19_05_26.bin");  dac[7]=200;  /*dll[7]=10.0;  dll[7]=12.5; */dll[7]=8.8;  
//strcpy(head[8],"/u1/w_si/samples/2014_08_01_19_06_03.bin");  dac[8]=242;  /*dll[8]=15.0;  dll[8]=12.5; */dll[8]=13.2;  
//strcpy(head[9],"/u1/w_si/samples/2014_08_01_19_06_35.bin");  dac[9]=244;  /*dll[9]=15.0;  dll[9]=11;   */dll[9]=13.6;
//strcpy(head[10],"/u1/w_si/samples/2014_08_01_19_07_08.bin"); dac[10]=246; /*dll[10]=15.5; dll[10]=7;   */dll[10]=13.4;
//strcpy(head[11],"/u1/w_si/samples/2014_08_01_19_07_40.bin"); dac[11]=248; /*dll[11]=15.7; dll[11]=2;   */dll[11]=13.3;
//strcpy(head[12],"/u1/w_si/samples/2014_08_01_19_08_18.bin"); dac[12]=300; /*dll[12]=21.6; dll[12]=0;   */dll[12]=18.5; 
//strcpy(head[13],"/u1/w_si/samples/2014_08_01_19_08_52.bin"); dac[13]=400; /*dll[13]=34.5; dll[13]=7;   */dll[13]=29.6;
//strcpy(head[14],"/u1/w_si/samples/2014_08_01_19_09_31.bin"); dac[14]=460; /*dll[14]=43.0; dll[14]=2;   */dll[14]=36.2;
//strcpy(head[15],"/u1/w_si/samples/2014_08_01_19_10_03.bin"); dac[15]=500; /*dll[15]=49.0; dll[15]=0;   */dll[15]=41; 
//gmx=1; jx=3; jk=1; jtn=1; jtx=16; jft=8;
//Sixteen files all cal. 2014_08_02_16_18_05, from cal12, thr.off=28,000 cal pix14, 46....964.
//strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin");  dac[0]=0;
//strcpy(head[1],"/u1/w_si/samples/2014_08_02_16_18_05.bin");  dac[1]=0;
//strcpy(head[2],"/u1/w_si/samples/2014_08_02_16_18_57.bin");  dac[2]=20;   /*dll[2]=-1.4;  dll[2]=5;   */ dll[2]=0.3;  
//strcpy(head[3],"/u1/w_si/samples/2014_08_02_16_19_35.bin");  dac[3]=40;   /*dll[3]=-1.6;  dll[3]=11.5;*/ dll[3]=1.0;
//strcpy(head[4],"/u1/w_si/samples/2014_08_02_16_20_09.bin");  dac[4]=60;   /*dll[4]=-1.3;  dll[4]=13.5;*/ dll[4]=1.5; 
//strcpy(head[5],"/u1/w_si/samples/2014_08_02_16_20_52.bin");  dac[5]=80;   /*dll[5]=-0.6;  dll[5]=12.5;*/ dll[5]=3.1; 
//strcpy(head[6],"/u1/w_si/samples/2014_08_02_16_21_24.bin");  dac[6]=100;  /*dll[6]=0.6;   dll[6]=12.5;*/ dll[6]=4.5;  
//strcpy(head[7],"/u1/w_si/samples/2014_08_02_16_21_56.bin");  dac[7]=200;  /*dll[7]=11.7;  dll[7]=12.5;*/ dll[7]=13.3;  
//strcpy(head[8],"/u1/w_si/samples/2014_08_02_16_22_30.bin");  dac[8]=242;  /*dll[8]=18.3;  dll[8]=12.5;*/ dll[8]=18.8;  
//strcpy(head[9],"/u1/w_si/samples/2014_08_02_16_23_01.bin");  dac[9]=244;  /*dll[9]=18.6;  dll[9]=11;  */ dll[9]=18.9;
//strcpy(head[10],"/u1/w_si/samples/2014_08_02_16_23_31.bin"); dac[10]=246; /*dll[10]=19.0; dll[10]=7;  */ dll[10]=19.2;
//strcpy(head[11],"/u1/w_si/samples/2014_08_02_16_24_05.bin"); dac[11]=248; /*dll[11]=19.2; dll[11]=2;  */ dll[11]=19.2;
//strcpy(head[12],"/u1/w_si/samples/2014_08_02_16_24_37.bin"); dac[12]=300; /*dll[12]=27.3; dll[12]=0;  */ dll[12]=25.2; 
//strcpy(head[13],"/u1/w_si/samples/2014_08_02_16_25_06.bin"); dac[13]=400; /*dll[13]=45.6; dll[13]=7;  */ dll[13]=38;  
//strcpy(head[14],"/u1/w_si/samples/2014_08_02_16_25_37.bin"); dac[14]=460; /*dll[14]=59.0; dll[14]=2;  */ dll[14]=46.0;
//strcpy(head[15],"/u1/w_si/samples/2014_08_02_16_26_06.bin"); dac[15]=500; /*dll[15]=66.6; dll[15]=0;  */ dll[15]=50.4; 
//gmx=1; jx=3; jk=1; jtn=1; jtx=16; jft=8;
////Calibraion file normal gain.
////strcpy(head[0],"/u1/w_si/samples/2014_07_15_09_15_58.bin");
//strcpy(head[0],"/u1/w_si/samples/2014_10_29_12_31_54.bin");
//for(i=0;i<45;i++){dac[i]=100-2*i;} for(i=45;i<56;i++){dac[i]=55-i;}
////for(i=0;i<56;i++){printf("dac=%5.0f\n",dac[i]); fprintf(fout,"dac=%5.0f\n",dac[i]);}
//gmx=1; jx=3; jk=1; jtn=1; jtx=1; jft=8;

//Run file int10 high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2014_11_22_16_54_54.bin");
//jk=1; jtn=1; jtx=1; jft=8; idm=17;

////Run file int12, DAC=255, 0 fC; high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head.[0],"/u1/w_si/samples/2014_11_26_11_07_06.bin"); dac[0]=0.2;
////Run file int12, DAC=253, 2.2 fC, high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[1],"/u1/w_si/samples/2014_12_10_16_00_14.bin"); dac[1]=2.2;
////Run file int12, DAC=251, 4.2 fC, high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[2],"/u1/w_si/samples/2014_11_26_11_09_14.bin"); dac[2]=4.2;
////Run file int12, DAC=245, 10.4 fC, high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[3],"/u1/w_si/samples/2014_12_10_16_02_00.bin"); dac[3]=10.4;
////Run file int12, DAC=240, 21 fC, high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[4],"/u1/w_si/samples/2014_12_10_16_13_07.bin"); dac[4]=21;
////Run file int12, DAC=240, 42 fC, high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[5],"/u1/w_si/samples/2014_12_10_16_35_25.bin"); dac[5]=42;
////jk=1; jtn=1; jtx=6; jft=8; idm=17; mnd=200; mxd=255; inc=1;
////Run file int12, DAC=240, 108 fC, high gain, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[6],"/u1/w_si/samples/2014_12_10_16_37_05.bin"); dac[6]=108;
//jk=1; jtn=1; jtx=7; jft=8; idm=17; mnd=200; mxd=255; inc=1;

//Run file int13 high gain, DAC=251, 4 fC, times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[0],"/u1/w_si/samples/2014_12_01_12_08_25.bin");
//jk=1; jtn=1; jtx=1; jft=8; idm=17; mnd=200; mxd=255; inc=1;

////                                               offset thresh.  rst    clock  inhib.
////Run file int13 high gain, DAC=255, 0 fC, times 5,000, 13,000, 14,000, 15,000, 710.
////strcpy(head[0],"/u1/w_si/samples/2014_12_11_14_05_07.bin"); dac[0]=0.2;
////Run file int13 high gain, DAC=253, 2.2 fC, times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[0],"/u1/w_si/samples/2014_12_11_14_06_02.bin"); dac[0]=2.2;
////Run file int13 high gain, DAC=251, 4.2 fC, times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[1],"/u1/w_si/samples/2014_12_11_14_07_25.bin"); dac[1]=4.2;
////Run file int13 high gain, DAC=245, 10.4 fC, times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[2],"/u1/w_si/samples/2014_12_11_14_09_33.bin"); dac[2]=10.4;
////Run file int13 high gain, DAC=240, 21 fC, times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[3],"/u1/w_si/samples/2014_12_11_14_10_46.bin"); dac[3]=21;
////Run file int13 high gain, DAC=240, 42 fC, times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[4],"/u1/w_si/samples/2014_12_11_14_11_52.bin"); dac[4]=42;
////jk=1; jtn=1; jtx=6; jft=8; idm=17; mnd=200; mxd=255; inc=1;
////Run file int13 high gain, DAC=240, 108 fC, times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[5],"/u1/w_si/samples/2014_12_11_14_12_54.bin"); dac[5]=108;
//jk=1; jtn=1; jtx=6; jft=8; idm=17; mnd=200; mxd=255; inc=1;

//Run file int13 high gain, DAC=251, 4 fC, times 5,000, 13,000, 14,000, 15,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2014_12_04_09_25_12.bin");
//jk=1; jtn=1; jtx=1; jft=8; idm=17; mnd=200; mxd=255; inc=1;

//Run file int13 high gain, DAC=251, 4 fC, times 5,000, 13,000, 18,000, 20,000, 710.
//strcpy(head[0],"/u1/w_si/samples/2014_12_12_20_18_52.bin");
//jk=1; jtn=1; jtx=1; jft=8; idm=17; mnd=200; mxd=255; inc=1;

//                                                 offset thresh.  rst    clock  inhib.
//Run file int13 high gain, DAC=252, 3.2 fC, times 8,000, 20,000, 5,000, 20,000, 500.
//strcpy(head[0],"/u1/w_si/samples/2014_12_13_13_01_16.bin"); dac[0]=3.2;
////Run file int13 high gain, DAC=251, 4.2 fC,
//strcpy(head[1],"/u1/w_si/samples/2014_12_13_13_02_14.bin"); dac[1]=4.2;
////Run file int13 high gain, DAC=245, 10.4 fC,
//strcpy(head[2],"/u1/w_si/samples/2014_12_13_13_03_22.bin"); dac[2]=10.4;
////Run file int13 high gain, DAC=240, 21 fC,
//strcpy(head[3],"/u1/w_si/samples/2014_12_13_13_04_34.bin"); dac[3]=21;
////Run file int13 high gain, DAC=240, 42 fC,
//strcpy(head[4],"/u1/w_si/samples/2014_12_13_13_05_25.bin"); dac[4]=42;
////jk=1; jtn=1; jtx=6; jft=8; idm=17; mnd=200; mxd=255; inc=1;
////Run file int13 high gain, DAC=240, 108 fC,
//strcpy(head[5],"/u1/w_si/samples/2014_12_13_13_06_22.bin"); dac[5]=108;
//jk=1; jtn=1; jtx=6; jft=8; idm=17; mnd=200; mxd=255; inc=1;

//Run file int14 high gain, DAC=251, 4 fC, times 5,000, 13,000, 18,000, 20,000, 710.
//strcpy(head[0],"/u1/w_si/samples/2014_12_17_16_55_37.bin");
//jk=1; jtn=1; jtx=1; jft=8; idm=17; mnd=200; mxd=255; inc=1;

//                                 offset thresh.  rst    clock  inhib.
//Run file int14 high gain,  times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[0],"/u1/w_si/samples/2014_12_18_11_27_13.bin"); dac[0]=0.2;
//strcpy(head[1],"/u1/w_si/samples/2014_12_18_11_28_34.bin"); dac[1]=1.2;
//strcpy(head[2],"/u1/w_si/samples/2014_12_18_11_29_17.bin"); dac[2]=2.2;
//strcpy(head[3],"/u1/w_si/samples/2014_12_18_11_29_57.bin"); dac[3]=3.2;
//strcpy(head[4],"/u1/w_si/samples/2014_12_18_11_30_37.bin"); dac[4]=4.2;
//strcpy(head[5],"/u1/w_si/samples/2014_12_18_11_31_35.bin"); dac[5]=5.2;
//strcpy(head[6],"/u1/w_si/samples/2014_12_18_12_46_03.bin"); dac[6]=6.2;
//strcpy(head[7],"/u1/w_si/samples/2014_12_18_11_33_22.bin"); dac[7]=8.2;
//strcpy(head[8],"/u1/w_si/samples/2014_12_18_11_34_23.bin"); dac[8]=10.2;
//strcpy(head[9],"/u1/w_si/samples/2014_12_18_11_35_07.bin"); dac[9]=14.2;
//strcpy(head[10],"/u1/w_si/samples/2014_12_18_11_35_47.bin"); dac[10]=20.2;
//strcpy(head[11],"/u1/w_si/samples/2014_12_18_11_36_39.bin"); dac[11]=30.2;
//strcpy(head[12],"/u1/w_si/samples/2014_12_18_12_25_05.bin"); dac[12]=40.2;
//strcpy(head[13],"/u1/w_si/samples/2014_12_18_12_26_39.bin"); dac[13]=50.2;
//strcpy(head[14],"/u1/w_si/samples/2014_12_18_11_38_48.bin"); dac[14]=60.2;
//strcpy(head[15],"/u1/w_si/samples/2014_12_18_11_39_36.bin"); dac[15]=80.2;
//strcpy(head[16],"/u1/w_si/samples/2014_12_18_12_27_27.bin"); dac[16]=100.2;
//jk=1; jtn=1; jtx=15; jft=8; idm=17; mnd=200; mxd=255; inc=1;

//                                 offset thresh.  rst    clock  inhib.
//Run file int14 high gain,  times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[0],"/u1/w_si/samples/2014_12_18_14_49_20.bin"); dac[0]=1.2;
//strcpy(head[1],"/u1/w_si/samples/2014_12_18_14_50_33.bin"); dac[1]=2.2;
//strcpy(head[2],"/u1/w_si/samples/2014_12_18_14_51_38.bin"); dac[2]=3.2;
//strcpy(head[3],"/u1/w_si/samples/2014_12_18_14_52_11.bin"); dac[3]=4.2;
//strcpy(head[4],"/u1/w_si/samples/2014_12_18_14_52_49.bin"); dac[4]=5.2;
//strcpy(head[5],"/u1/w_si/samples/2014_12_18_14_56_09.bin"); dac[5]=6.2;
//strcpy(head[6],"/u1/w_si/samples/2014_12_18_14_57_00.bin"); dac[6]=7.2;
//strcpy(head[7],"/u1/w_si/samples/2014_12_18_14_57_55.bin"); dac[7]=8.2;
//strcpy(head[8],"/u1/w_si/samples/2014_12_18_14_58_46.bin"); dac[8]=10.2;
//strcpy(head[9],"/u1/w_si/samples/2014_12_18_14_59_46.bin"); dac[9]=14.2;
//strcpy(head[10],"/u1/w_si/samples/2014_12_18_15_19_26.bin"); dac[10]=20.2;
//strcpy(head[11],"/u1/w_si/samples/2014_12_18_15_01_29.bin"); dac[11]=30.2;
//strcpy(head[12],"/u1/w_si/samples/2014_12_18_15_02_10.bin"); dac[12]=40.2;
//strcpy(head[13],"/u1/w_si/samples/2014_12_18_15_03_03.bin"); dac[13]=50.2;
//strcpy(head[14],"/u1/w_si/samples/2014_12_18_15_03_50.bin"); dac[14]=60.2;
//strcpy(head[15],"/u1/w_si/samples/2014_12_18_15_04_55.bin"); dac[15]=80.2;
//strcpy(head[16],"/u1/w_si/samples/2014_12_18_15_05_35.bin"); dac[16]=100.2;
//jk=1; jtn=1; jtx=17; jft=8; idm=17; mnd=200; mxd=255; inc=1; ndd=128;

//                                 offset thresh.  rst    clock  inhib.
//Run file int14 high gain,  times 5,000, 13,000, 14,000, 15,000, 710.
//strcpy(head[0],"/u1/w_si/samples/2014_12_19_10_43_59.bin"); dac[0]=1;
//strcpy(head[1],"/u1/w_si/samples/2014_12_19_10_47_05.bin"); dac[1]=2;
//strcpy(head[2],"/u1/w_si/samples/2014_12_19_10_47_55.bin"); dac[2]=3;
//strcpy(head[3],"/u1/w_si/samples/2014_12_19_10_48_27.bin"); dac[3]=4;
//strcpy(head[4],"/u1/w_si/samples/2014_12_19_10_49_06.bin"); dac[4]=5;
//strcpy(head[5],"/u1/w_si/samples/2014_12_19_10_49_44.bin"); dac[5]=6;
//strcpy(head[6],"/u1/w_si/samples/2014_12_19_10_50_14.bin"); dac[6]=7;
//strcpy(head[7],"/u1/w_si/samples/2014_12_19_11_37_04.bin"); dac[7]=8;
//strcpy(head[8],"/u1/w_si/samples/2014_12_19_10_51_59.bin"); dac[8]=10;
//strcpy(head[9],"/u1/w_si/samples/2014_12_19_10_52_44.bin"); dac[9]=14;
//strcpy(head[10],"/u1/w_si/samples/2014_12_19_10_53_42.bin"); dac[10]=20;
//strcpy(head[11],"/u1/w_si/samples/2014_12_19_10_54_36.bin"); dac[11]=30;
//strcpy(head[12],"/u1/w_si/samples/2014_12_19_10_55_10.bin"); dac[12]=40;
//strcpy(head[13],"/u1/w_si/samples/2014_12_19_10_55_46.bin"); dac[13]=50;
//strcpy(head[14],"/u1/w_si/samples/2014_12_19_10_56_21.bin"); dac[14]=60;
//strcpy(head[15],"/u1/w_si/samples/2014_12_19_10_56_54.bin"); dac[15]=70;
//strcpy(head[16],"/u1/w_si/samples/2014_12_19_10_57_31.bin"); dac[16]=80;
//strcpy(head[17],"/u1/w_si/samples/2014_12_19_10_58_05.bin"); dac[17]=90;
//strcpy(head[18],"/u1/w_si/samples/2014_12_19_10_58_36.bin"); dac[18]=100;
//jk=1; jtn=1; jtx=19; jft=8; idm=17; mnd=200; mxd=255; inc=1; ndd=100;
jtx=0;


for(l=0;l<19;l++){dec[l]=dac[l];}
for(i=0;i<9;i++){dac[i]+=0.0013*(i+1)*(i+1);}
dac[8]=10.26; dac[9]=14.37; dac[10]=20.59; dac[11]=31.04;
dac[12]=41.62; dac[13]=52.34; dac[14]=63.19; dac[15]=74.16; dac[16]=85.27; dac[17]=96.50; dac[18]=107.86;



//=========000000000
//tav=0; ipt=0; kpt=0; npt=10; ct0=0; /* for temperature monitor */
for(l=9;l<30;l++){for(j=0;j<jn;j++){x1y1[j][l]=0; sy1[j][l]=0; ssx2[j][l]=0;}}
nsn=0; slpn=0; slpo=0; jds=3; for(jtr=0;jtr<jtx;jtr++){ysm[jtr]=0;
for(k=0;k<jk;k++){
nsq[k][jtr]=0; pav[k][jtr]=0; psq[k][jtr]=0; for(l=0;l<30;l++){
/*dsl[k][l][jtr]=0;*/ for(j=0;j<jn;j++){for(i=0;i<2;i++){
ped[j][k][i][l][jtr]=0; pdq[j][k][i][l][jtr]=0; npq[j][k][i][l][jtr]=0;}}}}
yyy[10]=3; yyy[12]=2.4; yyy[14]=2; yyy[16]=3;

DataRead *r=new DataRead; stat = r->open(head[jtr]);
if(! stat){printf("pedestal file not found\n"); fprintf(fout,"pedestal file not found\n");}
printf("file = %d\n",jtr); fprintf(fout,"file = %d\n",jtr);

// Skip Events.
jtst=0; KpixEvent e ; for(i=0;i<0;i++){r->next(&e);}
while(r->next(&e)) {count=e.count(); itrn=e.eventNumber();
//while(r->next(&e)&&jtst<100) {count=e.count(); itrn=e.eventNumber(); jtst++;
//printf(      " itrn= %d jtst= %d count= %d\n",itrn,jtst,count);
//fprintf(fout," itrn= %d jtst= %d count= %d\n",itrn,jtst,count);

// Each trigger:
i=0; while(i<count){s=e.sample(i); jst=s->getSampleType(); gn=s->getSampleRange();
jnt=s->getTrigType();    j=s->getKpixChannel(); k=s->getKpixBucket();
// Calculate running average of temperature.
// tmp is temperature, tnp the raw output of the sensor and l the count mod. 32
//if(jst==1){tmp=0.598*(255-x)-62; l=z/256; tnp=z-256*l;}
//if(kpt==0){ct0++; tav+=(tmp-tav)/ct0;} else{tav+=(tmp-vtp[ipt])/npt;}
//vtp[ipt]=tmp; ipt++; if(ipt>=npt){ipt=0; kpt=1;
//printf(      "itrn= %d tmp= %4.1f tav=%4.1f ct0=%d\n",itrn,tmp,tav,ct0);
//fprintf(fout,"itrn= %d tmp= %4.1f tav=%4.1f ct0=%d\n",itrn,tmp,tav,ct0);}

 if(jst==2){xtm=z+x*0.125; ytm[jtm]=xtm; if(jtm<9)jtm++; ct0++;}

 if(jst==1){tmp=0.598*(255-x)-62; l=z/256; tnp=z-256*l;}

 if(jst==0){ktm[j][k][ida][jtr]=z;

if(k==0/*&&j==6&&(z<755||ida==14)*/){y=x-dped[j][k][gn][ida];
u=slp[j][k][gn][ida]; if(u>0)y/=u;
y+=yyy[ida]; /*x=y;*/
if(z<750)z=750; if(z>1799)z=1799;
/*if(u>0)*/{
if(ida==10){aHist->Fill(y);} if(ida==12){bHist->Fill(y);}
if(ida==14){cHist->Fill(y);} if(ida==16){dHist->Fill(y);}}
if(ida==10){eHist->Fill(j);} if(ida==12){fHist->Fill(j);}
//printf("       itrn= %d j=%4d ida=%d  gn=%d  slp=%4.1f ped=%4.0f y=%5.1f z=%4.0f\n",itrn,j,ida, gn,u,dped[j][k][gn][ida],y,z);
//fprintf(fout," itrn= %d j=%4d ida=%d  gn=%d  slp=%4.1f ped=%4.0f y=%5.1f z=%4.0f\n",itrn,j,ida, gn,u,dped[j][k][gn][ida],y,z);}

// Produce Averages (ped) and variances (pdq) for each pixel, bucket, sensor.
/*if(jx==3)*/{y=x-ped[j][k][gn][ida][jtr]; n=npq[j][k][gn][ida][jtr];
pdq[j][k][gn][ida][jtr]+=n*y*y/(n+1);
n++; ped[j][k][gn][ida][jtr]+=y/n; npq[j][k][gn][ida][jtr]=n;} /* jx==3 */

// Produce moments of Pedestals (x) with respect to time (z).
//if(jx>0&&jx<3){zz=x-yyv[j][k][ida]; nnv[j][k][ida]++; n=nnv[j][k][ida];
//yyv[j][k][ida]+=zz/n; xyv[j][k][ida]+=(x*z-xyv[j][k][ida])/n;
//xxv[j][k][ida]+=(z-xxv[j][k][ida])/n; x2v[j][k][ida]+=(z*z-x2v[j][k][ida])/n;} /* jx */

}
} /* jst==0 */

// Test on correct trigger type, jnt=0 for forced, jnt=1 for internal trigger.
// if(jx==jnt&&k==0){wrg=1;
//       printf(" itrnwrg= %d j= %d k= %d t_type= %d wrg= %d %d %5.1f\n",itrn,j,k,jnt,wrg,o[0],a[0]);
// fprintf(fout," itrnwrg= %d j= %d k= %d t_type= %d wrg= %d %d %5.1f\n",itrn,j,k,jnt,wrg,o[0],a[0]);}

i++; } /* while(i<cout) */ } /* while(r->next(&e)) */ delete r;



printf(      "ida  q   n   j=  6     n   j=106     n  j=206      n   j=306     n  j=406      n   j=506\n");
fprintf(fout,"ida  q   n   j=  6     n   j=106     n  j=206      n   j=306     n  j=406      n   j=506\n");
gn=gmx-1; k=0; for(ida=0;ida<idm;ida++){if(lda[ida]==-1)continue;
y=dac[jtr]-dac[jds];
printf("      %d %4.0f",ida,dac[jtr]);
fprintf(fout,"%d %4.0f",ida,dac[jtr]);
for(j=6;j<512;j+=ndd){n=npq[j][k][gn][ida][jtr]; bbb=slp[j][0][0][ida];
if(n>1){x1y1[j][ida]+=y*ped[j][k][gn][ida][jtr];
y=dac[jtr]-dac[jds]; sy1[j][ida]+=y; ssx2[j][ida]+=y*y;}
x=0; if(n>0&&bbb>0){x=yyy[ida]+(ped[j][k][gn][ida][jtr]-dped[j][k][gn][ida])/bbb-dac[jtr];}
z=0; if(n>1&&bbb>0){z=sqrt(pdq[j][k][gn][ida][jtr]/(n-1))/bbb;}
printf("       %3d %4.1f(%3.1f)",n,x,z);
fprintf(fout," %3d %4.1f(%3.1f)",n,x,z);} /* j */
//x=x1y1[j][ida]; z=ped[j][k][gn][ida][jtr];
//printf("       %3d %5.0f(%5.0f)",n,x,z);
//fprintf(fout," %3d %5.0f(%5.0f)",n,x,z);} /* j */
printf("\n"); fprintf(fout,"\n");
} /* ida */ 

} /* jtr */

//for(ida=0;ida<idm;ida++){if(lda[ida]==-1)continue;
//for(j=6;j<512;j+=ndd){if(ssx2[j][ida]>0){
//bbb=(x1y1[j][ida]- ped[j][0][0][ida][jds]*sy1[j][ida])/ssx2[j][ida];
////if(ida==10&&j==6){bbb+=.01;}
//printf("       slp1=%5.1f",slp[j][0][0][ida]);
//fprintf(fout," slp1=%5.1f",slp[j][0][0][ida]);
//printf("       slp=%5.1f",bbb);
//fprintf(fout," slp=%5.1f",bbb);
//xsm=0; n=0; for(jtr=0;jtr<jtx;jtr++){x=-9.9; if(npq[j][k][gn][ida][jtr]>1){n++;
////x=ped[j][0][0][ida][jtr]-ped[j][0][0][ida][jds]-bbb*(dac[jtr]-dac[jds]); xsm+=x*x;} /* npq */
//x=ped[j][0][0][ida][jtr]-ped[j][0][0][ida][jds]-bbb*(dec[jtr]-dec[jds]); xsm+=x*x;} /* npq */
//if(x!=-9.9)x/=bbb;
//printf("      %5.1f",x);
//fprintf(fout,"%5.1f",x);} /* jtr */
//if(n>2){xsm=sqrt(xsm/((n-2)*bbb*bbb));} else{xsm=-1;}
//printf(" xsm=%5.2f\n",xsm); fprintf(fout," xsm=%5.2f\n",xsm);
//} /* ssx2 */ } /* j */
//printf("\n"); fprintf(fout,"\n");} /* ida */


 if(jx==3&&jtx>1){
// For max-min analysis function of time in each pixel
//for(k=0;k<jk;k++){for(ida=0;ida<idm;ida++){for(j=0;j<jn;j++){
//for(jtr=jtn;jtr<jtx;jtr++){ n=npq[j][k][0][ida][jtr];
//z=0; if(n>1){z=sqrt(pdq[j][k][gn][ida][jtr]/(n-1));} pdq[j][k][gn][ida][jtr]=z;} /* jtr */
//z=pdq[j][k][gn][ida][0]; /*if(z<0.1)z=0.1; if(z>1.9)z=1.9;*/ x=ped[j][k][gn][ida][0]; if(x<20)x=20; if(x>480)x=480;
//// if(z<.1||z>1.9){iee[j][k][0][ida]=0; if(k==0){
////  printf(     "Bad Pixel j=%5d k=%2d ida=%3d z=%5.2f\n",j,k,ida,z);
//// fprintf(fout,"Bad Pixel j=%5d k=%2d ida=%3d z=%5.2f\n",j,k,ida,z);}}
//else{
////if(k==0){bHist->Fill(z); aHist->Fill(x);}
////if(k>0)){x-=ped[j][k-1][gn][ida][0]; if(x>199)x=199;}
////if(k==1){fHist->Fill(z); eHist->Fill(x);} if(x>49)x=49;
////if(k==2){jHist->Fill(z); iHist->Fill(x);} if(k==3){nHist->Fill(z); mHist->Fill(x);}
//} /* z */ } /* j */ } /* ida */ } /* k */

//for(k=0;k<jk;k++){for(ida=0;ida<idm;ida++){ibad=0; for(j=0;j<jn;j++){
//if(iee[j][k][0][ida]==0){if(k==0)ibad++; if(k>0&&iee[j][0][0][ida]==1)ibad++;}} /* j */
//printf(      " k=%2d ida=%3d ibad= %5d\n",k,ida,ibad);
//fprintf(fout," k=%2d ida=%3d ibad= %5d\n",k,ida,ibad);}}

// Determine slope and offset for each pixel and bucketin each sensor and file.
// For y=b*x+a use moments: b=(<x*y>-<x>*<y>)/(<x**2>-<x>**2); a=<y>-b*<x>; (min-chisq for equal weigt)
// For 1-parameter fit:a = (<xy>-b<x>)/<x*x> 
printf("\n Nominal charge [fC] and corrections");
fprintf(fout,"\n Nominal charge [fC] and corrections");
for(jtr=0;jtr<jtx;jtr++){y=dac[jtr]; printf("%5.0f",y); fprintf(fout,"%5.0f",y);}
printf("\n KPIX HPIX UNIT slp-new slp_old icpt");
fprintf(fout,"\n KPIX HPIX UNIT slp-new slp_old icpt");
for(jtr=0;jtr<jtx;jtr++){y=dll[jtr]; printf("%5.1f",y); fprintf(fout,"%5.1f",y);}
printf("\n"); fprintf(fout,"\n");

gn=gmx-1; for(k=0;k<jk;k++){for(jtr=0;jtr<jtx;jtr++){nav[k][jtr]=0; qav[k][jtr]=0; qsq[k][jtr]=0;}
xsm=0; for(j=0;j<jn;j++){

for(ida=0;ida<idm;ida++){if(lda[ida]==-1)continue; jtr=0;
//In cal: dped=base-pedestal, cped = intercept.
u=dped[j][k][1][ida]; w=cped[j][k][1][ida]; y=xlp[j][k][1][ida]; z=xlp[j][k][0][ida];
x=ped[j][k][gn][ida][0]; v=dped[j][k][1][ida]-cped[j][k][1][ida];
if((i0>4||(y>0.14&&z>2.5))/*&&u>100*/){
if(ida==i0){/*aHist->Fill(w); eHist->Fill(u);*/ iHist->Fill(y); mHist->Fill(z); qHist->Fill(x); uHist->Fill(v);}
if(ida==i1){bHist->Fill(w); /*fHist->Fill(u);*/ jHist->Fill(y); nHist->Fill(z); rHist->Fill(x); vHist->Fill(v);}
if(ida==i2){cHist->Fill(w); /*gHist->Fill(u);*/ kHist->Fill(y); oHist->Fill(z); sHist->Fill(x); wHist->Fill(v);}
if(ida==i3){dHist->Fill(w); /*hHist->Fill(u);*/ lHist->Fill(y); pHist->Fill(z); tHist->Fill(x); xHist->Fill(v);}}
} /* ida */ 

//m=j/64; if((j-64*m)!=14)continue;
//if(j!=14)continue;
//if(j>127)continue;
//if(j>63)continue;
//if(j<960)continue;
for(ida=0;ida<idm;ida++){y=xlp[j][k][1][ida]; z=xlp[j][k][0][ida]; w=ped[j][k][gn][ida][jtn];
//if(w<100||(gn==0&&ida==16&&j==654)||(gn==1&&ida==10&&j==846)||((y<0.14||z<2.5)&&ida<10)||lda[ida]==-1)continue;
if(lda[ida]==-1||z<2||z>6)continue;
//if((j==910&&ida==3)||(j==718&&ida==2)||(j==974&&ida<=2))continue;
if((j==14&&ida==4)||(j==206&&ida==4)||(j==974&&ida<=2))continue;

v=0; u=0; z=0; vv=0; for(jtr=jtn;jtr<jtx;jtr++){
n=npq[j][k][gn][ida][jtr]; if(n>1)x=sqrt(pdq[j][k][gn][ida][jtr]/(n-1));
if(x<=0){ printf(      "ERROR j=%4d ida=%d jtr=%4d x=%6.1f\n",j,ida,jtr,x);
          fprintf(fout,"ERROR j=%4d ida=%d jtr=%4d x=%6.1f\n",j,ida,jtr,x); x=1;}
else{pdq[j][k][gn][ida][jtr]=x/sqrt(n);}
//if(jtr==1)eHist->Fill(x); if(jtr==jtx-3)fHist->Fill(x); if(jtr==jtx-2)gHist->Fill(x); if(jtr==jtx-1)hHist->Fill(x);
if(jtr>=jft)continue;
x=dac[jtr]+dll[jtr]; y=ped[j][k][gn][ida][jtr]; v+=x; vv+=x*x; z+=x*y;
// Two-parameter fit to slope.
//nav[k][jtr]++; qav[k][jtr]+=y; qsq[k][jtr]+=(y*y); u+=y;
//printf(      " j=%4d ida=%d v=%6.1f u=%6.1f vv=%6.1f z=%6.1f\n",j,ida,v,u,vv,z);
//fprintf(fout," j=%4d ida=%d v=%6.1f u=%6.1f vv=%6.1f z=%6.1f\n",j,ida,v,u,vv,z);
} /* jtr */

// Two-parameter fit to slope.
//x=vv-(v*v)/jtx; if(x>0){x=(z-(u*v)/jtx)/x;} w=(u-v*x)/jtx; n=2;
// One-parameter fit to slope.
x=(z-w*v)/vv; n=1;

if(x>0){zz=0; for(jtr=0;jtr<jtx;jtr++){
y=(ped[j][k][gn][ida][jtr]-x*(dac[jtr]+dll[jtr])-w)/x; if(jtr>=jtn)zz+=y*y; yyy[jtr]=y;} /* jtr */

if(jtx>n+jtn){zz=sqrt(zz/(jtx-n-jtn));} if(zz<20){
slp[j][k][gn][ida]=x; ofs[j][k][gn][ida]=w; y=xlp[j][k][gn][ida]; slpn+=x; slpo+=y;
printf(      " %4d %4d %4d %7.3f %7.3f %4.0f",j,tbp[j][0],ida,x,y,w);
fprintf(fout," %4d %4d %4d %7.3f %7.3f %4.0f",j,tbp[j][0],ida,x,y,w);


nsn++; for(jtr=0;jtr<jtx;jtr++){y=(ped[j][k][gn][ida][jtr]-x*(dac[jtr]+dll[jtr])-w)/x; y=yyy[jtr]; ysm[jtr]+=y;
/*y/=pdq[j][k][gn][ida][jtr];*/ if(jtr>=jtn){u+=y;} printf(      "%5.0f",y); fprintf(fout,"%5.0f",y);
x=pdq[j][k][gn][ida][jtr];
if(jtr==1)eHist->Fill(x); if(jtr==jtx-3)fHist->Fill(x); if(jtr==jtx-2)gHist->Fill(x); if(jtr==jtx-1)hHist->Fill(x);
} /* jtr */

printf(" q_rms=%3.0f mean=%3.0f\n",zz,u); fprintf(fout," q_rms=%3.0f mean=%3.0f\n",zz,u);
aHist->Fill(zz); xsm+=zz;
} /* x>0 */ } /* zz */} /* ida */ } /* j */ } /* k */

if(nsn>0){slpn/=nsn; slpo/=nsn;}
printf(      "\n  nsn=%3d        %5.3f   %5.3f AVG,",nsn,slpn,slpo);
fprintf(fout,"\n  nsn=%3d        %5.3f   %5.3f AVG,",nsn,slpn,slpo);
if(nsn>0){for(jtr=0;jtr<jtx;jtr++){y=ysm[jtr]/nsn; printf(      "%5.1f",y); fprintf(fout,"%5.1f",y);}
printf(" rms_av=%5.2f\n",xsm/nsn); fprintf(fout," rms_av=%5.2f\n",xsm/nsn);}

// Histograms of slopes.
//for(j=0;j<jn;j++){ for(ida=0;ida<idm;ida++){
//// if(slp[j][0][gn][ida]<2||slp[j][1][gn][ida]<2||slp[j][2][gn][ida]<2||slp[j][3][gn][ida]<2){
////  printf(     "Bad Pixel j=%5d slc= %5.2f %5.2f %5.2f %5.2f\n",j,slp[j][0][gn][ida],slp[j][1][gn][ida],slp[j][2][gn][ida],slp[j][3][gn][ida]);
//// fprintf(fout,"Bad Pixel j=%5d slc= %5.2f %5.2f %5.2f %5.2f\n",j,slp[j][0][gn][ida],slp[j][1][gn][ida],slp[j][2][gn][ida],slp[j][3][gn][ida]);}
//for(k=0;k<jk;k++){v=slp[j][k][gn][ida];
//// if(k==0){
//// if(slp[j][1][gn][ida]<2/*||w<2*/){
////  printf(     "Bad Pixel j=%5d slc= %5.2f %5.2f %5.2f %5.2f\n",j,v,slp[j][1][gn][ida],slp[j][2][gn][ida],slp[j][3][gn][ida]);
//// fprintf(fout,"Bad Pixel j=%5d slc= %5.2f %5.2f %5.2f %5.2f\n",j,v,slp[j][1][gn][ida],slp[j][2][gn][ida],slp[j][3][gn][ida]);
//// for(l=jtn;l<jtx;l++){x=ped[j][0][gn][ida][l];
////  printf(     "Pedestals j=%5d slc= %5.2f %5.2f %5.2f %5.2f\n",j,x,ped[j][1][ida][l],ped[j][2][ida][l],ped[j][3][ida][l]);
//// fprintf(fout,"Pedestals j=%5d slc= %5.2f %5.2f %5.2f %5.2f\n",j,x,ped[j][1][ida][l],ped[j][2][ida][l],ped[j][3][ida][l]);}
//// } /* slp */
//// } /* k==0 */
//// if(k>0){w=slp[j][k-1][gn][ida]; if(w>1){v=100*((v/w)-1); if(k==1){if(v<0.1.)v=0.1; if(v>9.5)v=9.5;}
//// if(k==2){if(v<-0.9)v=-0.9; if(v>0.9)v=0.9;}
//// if(k==3){if(v<-1.4)v=-1.4; if(v>0.5)v=0.5;}
//// w=v;
//// } /* w */
//// } /* k>0 */
//if(iee[j][k][0][ida]>0){
//w=v; if(w<0.1)w=0.1; if(w>9.9)w=9.9;
//// w=xlp[j][k][gn][ida]; if(w>0){w=100*(v-w)/w;} if(w<-8.9)w=-8.9; if(w>39)w=39;
//// if(k==0/*&&(slp[j][1][gn][ida]<2||j==1023)*/){dHist->Fill(w);}
//if(k==1){hHist->Fill(w);} if(k==2){lHist->Fill(w);} if(k==3){pHist->Fill(w);}
//} /* iee */ } /* k */ } /* ida */ } /* j */

// For each pixel applying slope and offset corrections as function of file parameter jtr.
//for(j=0;j<jn;j++){for(k=0;k<jk;k++){for(ida=0;ida<idm;ida++){for(jtr=jtn;jtr<jtx;jtr++){
//y=ped[j][k][gn][ida][jtr]-(slp[j][k][gn][ida]*dac[jtr]+ofs[j][k][gn][ida]);
//// dsl[k][ida][jtr]+=y;
//z=y-dsl[k][ida][jtr]; dsl[k][ida][jtr]+=(z/(j+1)); ped[j][k][gn][ida][jtr]=y;
//// z=pdq[j][k][gn][ida][jtr]; if(z>0){y/=z;} rsq[j][k][ida]+=(y*y);
//// if(z>39)z=39;
//// if(k==0)qHist->Fill(z); if(k==1)rHist->Fill(z); if(k==2)sHist->Fill(z); if(st->Fill(z);
////  printf(     " ERR j=%4d k=%2d file=%2d y=%4.0f Ped= %5.1f Pdq= %4.1f Rsq=%4.0f\n",j,k,jtr,y,ped[j][k][ida][jtr],z,rsq[j][k][ida]);
//// fprintf(fout," ERR j=%4d k=%2d file=%2d y=%4.0f Ped= %5.1f Pdq= %4.1f Rsq=%4.0f\n",j,k,jtr,y,ped[j][k][ida][jtr],z,rsq[j][k][ida]);}
//// if((j<5||j>1018)&&k==0){
////  printf(     "TEST j=%4d k=%2d file=%2d y=%4.0f Ped= %5.1f Pdq= %4.1f Rsq=%4.0f\n",j,k,jtr,y,ped[j][k][ida][jtr],z,rsq[j][k][ida]);
//// fprintf(fout,"TEST j=%4d k=%2d file=%2d y=%4.0f Ped= %5.1f Pdq= %4.1f Rsq=%4.0f\n",j,k,jtr,y,ped[j][k][ida][jtr],z,rsq[j][k][ida]);}
//} /* jtr */
//// if(jtx>1){w=sqrt(rsq[j][k][ida]/(jtx-1)); v=w; if(v>39)v=39; if(k==0)qHist->Fill(v);
//// if(k==1)rHist->Fill(v); if(k==2)sHist->Fill(v); if(k==3)tHist->Fill(v);}
//// if(k==0&&jtx>1){
//// if(w>30){
////  printf(     " large error j=%5d slc= %5.2f xof= %5.2f err=%4.0f\n",j,v,ofs[j][k][gn][ida],w);
//// fprintf(fout," large error j=%5d slc= %5.2f xof= %5.2f err=%4.0f\n",j,v,ofs[j][k][gn][ida],w);}
//// v=slp[j][k][gn][ida]; if(v<2){
////  printf(     " low slope j=%5d slc= %5.2f xof= %5.2f err=%4.0f\n",j,v,ofs[j][k][gn][ida],w);
//// fprintf(fout," low slope j=%5d slc= %5.2f xof= %5.2f err=%4.0f\n",j,v,ofs[j][k][gn][ida],w);}
//// } /* jtx */
//} /* ida */ } /* k */ } /* j */

// Determine slope and offset common to all pixels and sensors, but seperately for each bucket.
 //for(k=0;k<jk;k++){x=0; y=0; z=0; zz=0;

////for(j=0;j<jn;j++){for(ida=0;ida<1;ida++){rsq[j][k][ida]=0;
////for(jtr=jtn;jtr<jtx;jtr++){y=ped[j][k][gn][ida][jtr]-dsl[k][ida][jtr];
////z=pdq[j][k][gn][ida][jtr]; if(z>0){y/=z;} rsq[j][k][ida]+=(y*y);} /* jtr */
////if(jtx>1){w=sqrt(rsq[j][k][ida]/(jtx-1)); v=w; if(v>49.9)v=49.9; if(k==0)qHist->Fill(v);
////if(v>9.9)v=9.9;
////if(k==1)rHist->Fill(v); if(k==2)sHist->Fill(v); if(k==3)tHist->Fill(v);} /* jtx */ } /* ida */ } /* j */

//for(jtr=jtn;jtr<jtx;jtr++){u=qav[k][jtr]; n=nav[k][jtr]; w=qsq[k][jtr]-(u*u)/n; u/=n;
//qav[k][jtr]=u; qsq[k][jtr]=w;
//printf(     " bucket= %4d file=%2d Qav= %7.3f Qsq= %5.1f Nav= %d\n",k,jtr,u,w,nav[k][jtr]);
//fprintf(fout," bucket= %4d file=%2d Qav= %7.3f Qsq= %5.1f Nav= %d\n",k,jtr,u,w,nav[k][jtr]);
//v=dac[jtr]; x+=v; zz+=v*v; y+=u; z+=u*v;} /* jtr */
//slc[k]=zz-(x*x)/jtx; if(slc[k]!=0){slc[k]=(z-(y*x)/jtx)/slc[k];} else{slc[k]=0;} xof[k]=(y-slc[k]*x)/jtx;
//printf(     " xav= %4.1f yav= %4.1f xyav= %4.1f x2av= %4.1f slc= %5.2f xof= %5.2f\n",x,y,z,zz,slc[k],xof[k]);
//fprintf(fout," xav= %4.1f yav= %4.1f xyav= %4.1f x2av= %4.1f slc= %5.2f xof= %5.2f\n",x,y,z,zz,slc[k],xof[k]);
//// Apply slope and offset correction.    
//for(jtr=jtn;jtr<jtx;jtr++){qav[k][jtr]-=(slc[k]*dac[jtr]+xof[k]);
//// x=dsl[k][0][jtr]/jn;
//x=dsl[k][0][jtr];
//printf(     "New k=%2d file=%2d Qav= %7.3f Qsq= %5.1f Nav= %d Dsl=%4.1f\n",k,jtr,qav[k][jtr],qsq[k][jtr],nav[k][jtr],x);
//fprintf(fout,"New k=%2d file=%2d Qav= %7.3f Qsq= %5.1f Nav= %d Dsl=%4.1f\n",k,jtr,qav[k][jtr],qsq[k][jtr],nav[k][jtr],x);
//} /* jtr */ } /* k */

//for(j=0;j<jn;j++){for(k=0;k<jk;k++){for(ida=0;ida<idm;ida++){ymn=10000; ymx=0;
//if(iee[j][0][0][ida]>0){for(jtr=jtn;jtr<jtx;jtr++){x=ped[j][k][gn][ida][jtr]/slp[j][0][gn][ida];

//if(x>-1&&x<1){
//y=x-pav[k][jtr]; psq[k][jtr]+=nsq[k][jtr]*y*y/(nsq[k][jtr]+1); nsq[k][jtr]++; pav[k][jtr]+=y/nsq[k][jtr];}

//if(x<-1.9)x=-3.9; if(x>1.9)x=3.9;}
////  if(jtr==0)aHist->Fill(x);  if(jtr==1)bHist->Fill(x);  if(jtr==2)cHist->Fill(x);  if(jtr==3)dHist->Fill(x);
//// if(jtr==jtx-4)fHist->Fill(x);
//// if(jtr==jtx-3)gHist->Fill(x); if(jtr==jtx-2)hHist->Fill(x); if(jtr==jtx-1)iHist->Fill(x);
//} /* jtr */ x=ymx-ymn; if(x>4.9)x=4.9; /*mHist->Fill(x);*/
//if(ymx-ymn>5){
////  printf(     " pixel= %4d sensor= %4d  %4d  %4d ymn= %5.1f ymx= %5.1f\n",j,ida,ktn,ktx,ymn,ymx);
//// fprintf(fout," pixel= %4d sensor= %4d  %4d  %4d ymn= %5.1f ymx= %5.1f\n",j,ida,ktn,ktx,ymn,ymx);
//}
//} /* iee */ } /* ida */ } /* k */ } /* j */

// for(k=0;k<jk;k++){
//  printf(     " bucket= %4d \n",k);
// fprintf(fout," bucket= %4d \n",k);
// for(jtr=jtn;jtr<jtx;jtr++){y=pav[k][jtr]; n=nsq[k][jtr]; z=0; if(n>1){z=sqrt(psq[k][jtr]/(n-1));}
//  printf(     " bucket= %4d file=%2d pav= %9.5f psq= %9.5f nav= %d\n",k,jtr,y,z,n);
// fprintf(fout," bucket= %4d file=%2d pav= %9.5f psq= %9.5f nav= %d\n",k,jtr,y,z,n);}}

 } /* jx End max-min analysis function of time in each pixel.*/







// Print moments.
// if(jx!=3/*&&jtst<400*/){k=0; for(j=0;j<jn;j++){for(l=0;l<idm;l++){if(iee[j][k][0][l]>0){x=0; n=nnv[j][k][l]; y=x2v[j][k][l]-xxv[j][k][l]*xxv[j][k][l];
////       printf(" jx= %d j= %d l= %d ida= %d n= %d %5.1f\n",jx,j,l,ida,n,x);
//// fprintf(fout," jx= %d j= %d l= %d ida= %d n= %d %5.1f\n",jx,j,l,ida,n,x);
// if(y!=0){x=(xyv[j][k][l]-xxv[j][k][l]*yyv[j][k][l])/y;} slx[j][k][l]=x; sly[j][k][l]=yyv[j][k][l]-x*xxv[j][k][l];
//// if(j<10){y=sly[j][k][l];
////  printf("ped[%d][0]= %d %d  %d %5.0f  %5.0f %5.3f %5.3f %8.7f %5.1f\n",j,k,l,n,xxv[j][k][l],x2v[j][k][l],yyv[j][k][l],xyv[j][k][l],x,y);
//// fprintf(fout," %5d %5d %5d  %d %5.0f  %5.0f %5.3f %5.3f %8.7f %5.1f\n",j,k,l,n,xxv[j][k][l],x2v[j][k][l],yyv[j][k][l],xyv[j][k][l],x,y);}
// }}}}


 ite=0; idm=9; jtn=0; jtx=0; /* Defaults:jtx=0 causes skip of this section */
 /*if(jx==3)ite=1;*/ if(ite==0){jx=0; jk=1; gn=0;
// for(l=0;l<30;l++){lda[l]=8-l;} /* Stack normal orientation. */
 for(l=0;l<30;l++){lda[l]=l;} /* Stack reverse orientation. */
 lda[9]=11; lda[10]=13; lda[11]=15; lda[12]=17;

// int4, diff 1/2 1,000,010 cycles, idm=9 jx=0; jk=1;
// strcpy(head[0],"/u1/w_si/samples/2013_04_05_14_36_37.bin"); jx=0; jk=4;
// strcpy(head[0],"/u1/kpix/data/2013_04_05_14_36_37.bin"); jx=0; jk=4;
// ext1, diff 1/2 1,000,010 cycles, idm=9
// strcpy(head[0],"/u1/w_si/samples/2013_04_18_21_47_36.bin"); jx=1;
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2000
// strcpy(head[0],"/u1/w_si/samples/2013_04_25_16_53_41.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1000
// strcpy(head[1],"/u1/w_si/samples/2013_04_25_18_11_21.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=3000
// strcpy(head[2],"/u1/w_si/samples/2013_04_25_18_35_09.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=4000
// strcpy(head[3],"/u1/w_si/samples/2013_04_25_18_43_05.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=520
// strcpy(head[11],"/u1/w_si/samples/2013_04_25_20_21_32.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2000
// strcpy(head[10],"/u1/w_si/samples/2013_04_25_20_39_11.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=1500
// strcpy(head[4],"/u1/w_si/samples/2013_04_25_21_19_48.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=2500
// strcpy(head[5],"/u1/w_si/samples/2013_04_25_21_28_11.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=3500
// strcpy(head[6],"/u1/w_si/samples/2013_04_25_21_29_59.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=3000
// strcpy(head[9],"/u1/w_si/samples/2013_04_25_21_56_43.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=600
// strcpy(head[7],"/u1/w_si/samples/2013_04_25_22_04_35.bin");
// ext2, 1,010 cycles, clock 50 ns  int. forced trig,=700
// strcpy(head[8],"/u1/w_si/samples/2013_04_25_22_09_05.bin");
// int4, diff 1/2 1010 cycles, idm=9 jx=0; jk=1;
// strcpy(head[0],"/u1/w_si/samples/2013_06_27_15_57_25.bin"); jx=0; jtx=1;
// int5, 1010 cycles, idm=9 jx=0;
// strcpy(head[0],"/u1/w_si/samples/2013_07_08_21_17_41.bin"); jx=0; jk=4; jtx=1;
// int6, 1010 cycles, idm=9 jx=0; & more D in iad=0.
// strcpy(head[0],"/u1/w_si/samples/2013_07_09_17_06_31.bin"); jx=0; jk=4; jtx=1;
// int6, 100,010 cycles, idm=9 jx=0; & more D in iad=0.
// strcpy(head[0],"/u1/w_si/samples/2013_07_09_17_14_25.bin"); jx=0; jk=4; jtx=1;
// int6, 1,000,010 cycles, idm=9 jx=0; & more D in iad=0, iad=7,
// strcpy(head[0],"/u1/w_si/samples/2013_07_09_22_41_42.bin"); jx=0; jk=4; jtx=1;
// strcpy(head[0],"/u1/kpix/data/2013_07_09_22_41_42.bin"); jx=0; jk=4; jtx=1;
// int7, 100,010 cycles, idm=9 jx=0; & more D in iad=0, iad=7,
// strcpy(head[0],"/u1/w_si/samples/2013_07_15_17_47_48.bin"); jx=0; jk=4; jtx=1;
// int7, 1,000,010 cycles, idm=9 jx=0; & more D in iad=0, iad=7,
// strcpy(head[0],"/u1/w_si/samples/2013_07_15_20_56_59.bin"); jx=0; jk=4; jtx=1;
// int7, 10,010 cycles, idm=9 jx=0; & clk ct=8191, tr. inh.=500
// strcpy(head[0],"/u1/w_si/samples/2013_07_19_11_29_39.bin"); jx=0; jk=4; jtx=1;
// int7, 1,000,010 cycles, idm=9 jx=0; clk ct=8191, tr. inh.=500,
// strcpy(head[0],"/u1/w_si/samples/2013_07_19_21_30_29.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam (background).
// strcpy(head[0],"/u1/w_si/samples/2013_07_24_14_15_54.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam (background).
// strcpy(head[0],"/u1/w_si/samples/2013_07_24_20_21_34.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam.(tungsten in beam)
// strcpy(head[0],"/u1/kpix/data/2013_07_25_18_18_53.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam.
// strcpy(head[0],"/u1/kpix/data/2013_07_26_10_05_12.bin"); jx=0; jk=4; jtx=1;
// int8 Test ll <Bill McCann)
// strcpy(head[0],"/u1/kpix/data/2013_07_26_10_41_28.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam, standard parameters, standard orientation.
// strcpy(head[0],"/u1/kpix/data/2013_07_26_12_16_13.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam, standard parameters, standard orientation. Low beam.
// strcpy(head[0],"/u1/kpix/data/2013_07_26_14_13_43.bin"); jx=0; jk=4; jtx=1;
// strcpy(head[0],"/u1/kpix/data/2013_07_26_16_55_13.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam. Marty's file.               
// strcpy(head[0],"/u1/kpix/data/2013_07_28_19_25_54.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam. Dylan's file.               
// strcpy(head[0],"/u1/kpix/data/2013_07_28_20_33_31.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam, Range DAC=0   standard orientation. 5/pulse.
// strcpy(head[0],"/u1/kpix/data/2013_07_28_18_16_40.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam, Range DAC=0.9 standard orientation. 5/pulse.
// strcpy(head[0],"/u1/kpix/data/2013_07_28_18_40_29.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam, Range DAC=0.7 standard orientation. 5/pulse.
// strcpy(head[0],"/u1/kpix/data/2013_07_28_19_25_54.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam, Range DAC=0.3 standard orientation. 5/pulse.
// strcpy(head[0],"/u1/kpix/data/2013_07_28_20_02_40.bin"); jx=0; jk=4; jtx=1;
// int8 Test Beam. Stack in reverse order.
// strcpy(head[0],"/u1/kpix/data/2013_07_29_11_14_58.bin"); jx=0; jk=4; jtx=1;
// Marty 4.4 pC 
//strcpy(head[0],"/u1/kpix/data/2013_09_07_09_41_33.bin"); jx=-1; jk=4; jtx=1;
//calint2 Stack in Lab. thrA=2.4 thrB=0 cal252=3fC range 0.3V
//strcpy(head[0],"/u1/w_si/samples/2013_09_13_11_07_06.bin"); jx=0; jk=4; jtx=1;
//calint2 Stack in Lab. thrB=2.3V thrB=0 cal252=3fC range 0.3V 
//strcpy(head[0],"/u1/w_si/samples/2013_09_13_13_02_40.bin"); jx=0; jk=4; jtx=1;
//calint2 Stack in Lab. thrB=2.45V thrB=0 cal252=3fC range 0.3V 
//strcpy(head[0],"/u1/w_si/samples/2013_09_13_16_21_00.bin"); jx=0; jk=4; jtx=1;
//calint2 Stack in Lab. thrB=2.45V calDAC=251 (4fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_13_16_30_03.bin"); jx=0; jk=4; jtx=1;
//calint2 Stack in Lab. thrB=2.45V (5fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_15_14_52_32.bin"); jx=0; jk=4; jtx=1;
//calint3 Stack in Lab. thrB=0V (20fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_11_54_19.bin"); jx=0; jk=4; jtx=1;
//calint3 Stack in Lab. thrB=0V (5fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_15_17_05.bin"); jx=0; jk=4; jtx=1;
//calint3 Stack in Lab. thrB=0V (10fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_15_21_27.bin"); jx=0; jk=4; jtx=1;
//calint3 Stack in Lab. thrB=0V (14fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_15_28_30.bin"); jx=0; jk=4; jtx=1;
//calint3 Stack in Lab. thrB=0V (16fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_16_51_55.bin"); jx=0; jk=4; jtx=1;
//calint3 Stack in Lab. thrB=0V (18fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_17_16_27.bin"); jx=0; jk=4; jtx=1;
//calint3 Stack in Lab. thrB=0V (5fC)
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_20_34_15.bin"); jx=0; jk=4; jtx=1;
//int8 Stack in Lab.
//strcpy(head[0],"/u1/w_si/samples/2013_09_16_20_55_19.bin"); jx=0; jk=4; jtx=1;
//frc10 Stack in Lab.
//strcpy(head[0],"/u1/w_si/samples/2013_09_21_14_06_37.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. C=col_1 32-63 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_08_13_04_47.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. C=32-63 0 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_08_13_14_04.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. C=32-95 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_08_13_19_49.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. row_1 = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_10_10_39_14.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. col_2 = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_19_16_40_20.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. col_3 (96-127) = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_19_18_40_39.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. col_0 = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_19_18_44_29.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. col_4 (128-159) = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_19_18_48_11.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. col_31 (992-1023) = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_20_11_28_25.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. col_15 (480-511) = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_20_11_54_07.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. col_16 (512-543) = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_20_11_57_43.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. row_15 32 pix = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_21_14_54_56.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. row_16 32 pix = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_21_14_58_33.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. row_15 32 pix = 10 fC
//strcpy(head[0],"/u1/w_si/samples/2013_10_21_15_20_08.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. row_1 32 pix = 10 fC, thr.DAC210
// strcpy(head[0],"/u1/w_si/samples/2013_10_22_10_46_35.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. row_1 32 pix = 10 fC, thr.DAC200
//strcpy(head[0],"/u1/w_si/samples/2013_10_22_11_12_36.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. row_1 16 pix = 10 fC, thr.DAC240
//strcpy(head[0],"/u1/w_si/samples/2013_10_22_11_55_39.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. C=col_1 32-63 7 fC, just below onset monsters
//strcpy(head[0],"/u1/w_si/samples/2013_10_22_21_02_08.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. C=col_1 32-63 10 fC, disab 170 sens_7
//strcpy(head[0],"/u1/w_si/samples/2013_10_24_11_53_10.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. C=col_1 32-63 10 fC, disab 170 sens_7
//strcpy(head[0],"/u1/w_si/samples/2013_10_24_15_00_30.bin"); jx=0; jk=4; jtx=1;
//calint6 Stack in Lab. C=col_1 32-63 10 fC, disab 170 sens_7
//strcpy(head[0],"/u1/w_si/samples/2013_10_24_15_25_58.bin"); jx=0; jk=4; jtx=1;
//calint6_mod4 Stack in Lab. col 0-96
//strcpy(head[0],"/u1/w_si/samples/2014_01_22_12_45_06.bin"); jx=0; jk=4; jtx=1;
//calint6_mod6 Stack in Lab. 112 pixels.
//strcpy(head[0],"/u1/w_si/samples/2014_01_31_16_04_35.bin"); jx=0; jk=4; jtx=1; idm=13;
//calint8 Stack in Lab. KPiX_B
//strcpy(head[0],"/u1/w_si/samples/2014_03_11_16_49_00.bin"); jx=0; jk=4; jtx=1; idm=27;

 for(jtr=jtn;jtr<jtx;jtr++){

 for(k=0;k<jk;k++){nav[k][jtr]=0; qav[k][jtr]=0; qsq[k][jtr]=0;}
 for(l=0;l<30;l++){ibt[l]=0; jbt[l]=0; kbt[l]=0; lbt[l]=0; for(j=0;j<jn;j++){nnv[j][0][l]=0;}}

// New Data Format: cd kpix_new, setup_env.csh, bin/kpixGui xml/int3.xml&, onlineGui&
 DataRead *r=new DataRead; stat = r->open(head[jtr]);

 if(! stat){printf("data file not found\n"); fprintf(fout,"data file not found\n");}
 printf("file = %d\n",jtr); fprintf(fout,"file = %d\n",jtr);

// Process run data
 jdatp=1; jpix=0; ct0=0; ct1=0; ct3=0; ct4=0; ct5=0; jtst=0;
 for(l=0;l<30;l++){ntc[l]=0; kv[l]=0;for(j=0;j<jn;j++){mmv[j][l]=0;}}
 for(l=0;l<jn;l++){jdead[l]=0;}

// New Data Format. Skip Events.
KpixEvent e ; for(i=0;i<0;i++){r->next(&e);}
//while(r->next(&e)) {count=e.count(); itrn=e.eventNumber();
//while(r->next(&e)&&jtst<33500) {count=e.count(); itrn=e.eventNumber();
while(r->next(&e)&&jtst<5) {count=e.count(); itrn=e.eventNumber();
//printf(      " itrn=%d count=%4d jx=%d\n",itrn,count,jx);
//fprintf(fout," itrn=%d count=%4d jx=%d\n",itrn,count,jx);

// For run with 4.4 pC (jx=-1) jsv is KPiX address of driven pixel.
 jsv=jtst/100;

 jtst++; /*if(count<=idm){ct3++;} else*/{ct4++;
 if(jx>=0){rHist->Fill(count);}
//if(count>300){ct5++;} /*else*/{
//if(count>300){ct5++;} if(count<500&&jtst==(100*jsv+99)){
//if(count>300){ct5++;} if(/*jsv==13&&count<500&&*/jtst==(100*jsv+99)){
if(count>300){ct5++;} if(jx>=0||(jtst>(100*jsv+90)&&jtst<=(100*jsv+100))){
//{
 if(jx<0){if(count<=500){sHist->Fill(count); jdead[jsv]++;} rHist->Fill(count);}

// Each trigger:
 nix=0; ntr=0; ntt=0; ntu=0; ntw=0; wsm=0; wsq=0; cv=0;
 nm=0; krp=0; n=0; mn=0; wrg=0; cv=0; xtm=0; jtm=0; ct=0; itxsv=0, xsm=0;
 for(j=0;j<30;j++){xmx[j]=-1000; ivv[j]=0; lmx[j]=-1; mda[j]=0; nda[j]=0; ncl[j]=0;
 for(k=0;k<jk;k++){nmz[k][j]=0; zmx[k][j]=0; qmz[k][j]=0;}}

 i=0; while(i<count){s=e.sample(i); jst=s->getSampleType();

 jnt=s->getTrigType();    j=s->getKpixChannel(); k=s->getKpixBucket();
 ida=s->getKpixAddress(); x=s->getSampleValue(); z=s->getSampleTime(); gn=s->getSampleRange();
//printf(      " itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f jst=%d\n",itrn,j,k,ida,x,z,jst);
//fprintf(fout," itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f jst=%d\n",itrn,j,k,ida,x,z,jst);

// if(jst==2){xtm=z+x*0.125; ytm[jtm]=xtm; if(jtm<9)jtm++; ct0++;
//  if(jtst<2||l!=0){ ct0++;
//  printf(     "itrn= %d jtm= %d l=%d\n",itrn,jtm,l);
// fprintf(fout,"itrn= %d jtm= %d l=%d\n",itrn,jtm,l);}
// }

//if(jst==0){if(k==0)ct0++; if(k>0)ct1++; nnv[j][k][ida]++; ia[j][ida]++;
if(jst==0&&ida<idm){if(k==0)ct0++; if(k>0)ct1++; nnv[j][k][ida]++; ia[j][ida]++;
/* if(z>nlo&&z<nhi)if(k==0)*/if(iee[jsv][0][0][ida]>0){ivv[ida]++; mmv[jsv][ida]++;}
 adv[j][k]=x; itm[j][k]=z; ktm[j][k][ida][jtr]=z; ih[j][k]=jnt; zz=z; if(zz>1190)zz=1190;

//y=slp[j][k][gn][ida];
//printf(      " itrn=%d j= %4d y= %5.2f ida= %4d x= %6.0f z= %6.0f jst=%d\n",itrn,j,y,ida,x,z,jst);
//fprintf(fout," itrn=%d j= %4d y= %5.2f ida= %4d x= %6.0f z= %6.0f jst=%d\n",itrn,j,y,ida,x,z,jst);

// if(jtst<2&&jtx==9&&k==0&&jtr==4){
// if(j!=99&&j!=103&&ida&&4){
//  printf(     " itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f tbp=%d\n",itrn,j,k,ida,x,z,tbp[j][0]);
// fprintf(fout," itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f tbp=%d\n",itrn,j,k,ida,x,z,tbp[j][0]);}
// if(jsp==0&&k==0&&iee[j][k][0][ida]>0){kHist->Fill(zz);}
// if(jsp==3&&k==0){if(ida==0)aHist->Fill(zz); if(ida==1)dHist->Fill(zz);
//                  if(ida==2)gHist->Fill(zz); if(ida==3)kHist->Fill(zz);}

// Test for repeated numbers, legal for low noise, error otherwise.
// if(x==rep[j][k][ida]){irp[j][k][ida]++; krp++;} else{if(irp[j][k][ida]>5)
// {  printf(     " irp= %d j= %d k= %d rep=%5.0f\n",irp[j][k][ida],j,k,rep[j][k][ida]);
//   fprintf(fout," irp= %d j= %d k= %d rep=%5.0f\n",irp[j][k][ida],j,k,rep[j][k][ida]);}
// rep[j][k][ida]=x; irp[j][k][ida]=0;}

y=slp[j][k][gn][ida]; if(y>0&&k==0)ct++; /*if(y<=0.1){y=5;}*/
//x=(x-sly[j][k][ida]-slx[j][k][ida]*itm[j][k])/y; qq[j][k]=x; q[j][k][ida]=x;
iee[j][k][gn][ida]=1;
if(y>0){x=(x-ped[j][k][gn][ida][0])/y; qq[j][k]=x; q[j][k][ida]=x;} else{iee[j][k][gn][ida]=0;}

//l=iee[j][k][gn][ida]; if(l>0&&gn==1/*jtst<3*/){
//printf(      " itrn=%d l=%d j=%4d k=%d ida=%4d x=%6.0f y=%5.2f z=%6.0f gn=%d jst=%d\n",itrn,l,j,k,ida,x,y,z,gn,jst);
//fprintf(fout," itrn=%d l=%d j=%4d k=%d ida=%4d x=%6.0f y=%5.2f z=%6.0f gn=%d jst=%d\n",itrn,l,j,k,ida,x,y,z,gn,jst);}


// if(iee[jsv][0][0][ida]>0){
//// if((k==0&&/*j!=jsv&&*/z>752&&z<756)||(k==0&&z>760&&z<764)){
//if(x>40&&z>752&&z<758){
//printf(      " itrn=%d H=%4d j= %4d ida= %4d x= %6.0f z= %6.0f tbp=%d\n",itrn,tbp[jsv][0],j,ida,x,z,tbp[j][0]);
//fprintf(fout," itrn=%d H=%4d j= %4d ida= %4d x= %6.0f z= %6.0f tbp=%d\n",itrn,tbp[jsv][0],j,ida,x,z,tbp[j][0]);}

// if(jst==0&&jtst>1200&&z>nlo&&z<nhi){l=iee[j][0][gn][ida]; if(l>0){
//  printf(     " itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f iee=%d jst=%d\n",itrn,j,k,ida,x,z,l,jtst);
// fprintf(fout," itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f iee=%d jst=%d\n",itrn,j,k,ida,x,z,l,jtst);}}

// Pedestals zmx from run with external triggers. 
// if(jx>0&&jx!=3&&k==0&&iee[j][k][0][ida]>0){
// y=x-zmx[k][ida]; qmz[k][ida]=qmz[k][ida]+(nmz[k][ida]*y*y)/(nmz[k][ida]+1);
// nmz[k][ida]++; zmx[k][ida]+=y/nmz[k][ida];
// lHist->Fill(x);kHist->Fill(z/*-xtm*/);
// if(x>4&&k==0){ntt++; xsm+=((x-xsm)/ntt);}
// } /* jx */

 } /* jst */

// tmp is temperature, tnp the raw output of the sensor and l the count mod. 32
 if(jst==1){tmp=0.598*(255-x)-62; l=z/256; tnp=z-256*l;}
// if(jst==1){tmp=0.598*(255-x)-62; l=z; l=(l>>8); tnp=z&0xff;}


// if(kpt==0){ct0++; tav+=(tmp-tav)/ct0;} else{tav+=(tmp-vtp[ipt])/npt;}
// vtp[ipt]=tmp; ipt++; if(ipt>=npt){ipt=0; kpt=1;}
//  printf(     "itrn= %d tmp= %4.1f tav=%4.1f ct0=%d\n",itrn,tmp,tav,ct0);
// fprintf(fout,"itrn= %d tmp= %4.1f tav=%4.1f ct0=%d\n",itrn,tmp,tav,ct0);}


// if(jst==2){xtm=z+x*0.125; ytm[jtm]=xtm; if(jtm<9)jtm++; ct0++;}

// if(jtm>1){
//  printf(     "itrn= %d jtm= %d ytm0= %4.1f ytm1= %4.1f\n",itrn,jtm,ytm[0],ytm[1]);
// fprintf(fout,"itrn= %d jtm= %d ytm0= %4.1f ytm1= %4.1f\n",itrn,jtm,ytm[0],ytm[1]);
// if(jst>0){if(jst==1){if(x>199)x=199; kHist->Fill(x);}
// if(jst==1){
//  printf(     "itrn= %d tmp= %4.1f tnp=%d l=%d\n",itrn,tmp,tnp,l);
// fprintf(fout,"itrn= %d tmp= %4.1f tnp=%d l=%d\n",itrn,tmp,tnp,l);}
// if(gn==1){y=slp[j][k][gn][ida]; if(z<5000){x+=y*(z-5000)/1000;}}

 if(jst==0){{
// if(k==0){
//  printf(     "itrn= %d j= %d k= %d jnt= %d jst= %d x= %4.1f z= %4.1f xtm= %4.1f\n",itrn,j,k,jnt,jst,x,z,xtm);
// fprintf(fout,"itrn= %d j= %d k= %d jnt= %d jst= %d x= %4.1f z= %4.1f xtm= %4.1f\n",itrn,j,k,jnt,jst,x,z,xtm);}

// Sort.(o[0]=-1 if no max. in range found) need x>-5 for int. trigg. events)
 if(k==0&&iee[j][k][gn][ida]>0/*&&gn==0*/){n=nda[ida]; aa[n][ida]=x; oo[n][ida]=j; if(n>0){for(m=0;m<n;m++){
 if(x>aa[m][ida]){for(l=n;l>m;--l){aa[l][ida]=aa[l-1][ida]; oo[l][ida]=oo[l-1][ida];} aa[m][ida]=x; oo[m][ida]=j; m=n;
 }/* x>am */ } /* m */ } /* n>0 */ n++; nda[ida]=n;} /* k */
// End sort.


// Determine wsm = average and x<-1||x>1wsq = mean square of offsets in this event:
 if(jx>0&&j<jn&&k==0&&iee[j][k][0][ida]>0&&ih[j][k]>=0&&j!=o[0]){
 x=qq[j][k]-wsm; wsq+=cv*x*x/(cv+1); cv++; wsm+=x/cv;
// peq[j][k]+=ic[j]*x*x/(ic[j]+1); ic[j]++;}
 l=(itm[j][k]/100)-1; if(l<0)l=0; if(l>199)l=199; x=qq[j][k]; yav[l]+=x; kav[l]++;}
// End Determine wsm = average 

 } /* end jst==0 */

//  printf(     " itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f ct4=%d ntt=%d\n",itrn,j,k,ida,x,z,ct4,ntt);
// fprintf(fout," itrn=%d j= %4d k= %d ida= %4d x= %6.0f z= %6.0f ct4=%d ntt=%d\n",itrn,j,k,ida,x,z,ct4,ntt);

// Make histograms for cross-talk analysis.
// if(y>0&&k</*jk*/1){z=x; if(z<-50)z=-50; if(z>49)z=49;
// if(j!=8&&j!=149&&j!=238&&j!=254){eHist->Fill(z);
// if(z>0.7||z<-0.7){
//  printf(     "itrn= %d j= %d k=%d z= %5.1f Ped= %5.0f\n",itrn,j,k,z,ped[j][k][0]);
// fprintf(fout,"itrn= %d j= %d k=%d z= %5.1f Ped= %5.0f\n",itrn,j,k,z,ped[j][k][0]);}}
// else{
//  printf(     "itrn= %d j= %d k=%d z= %5.1f Ped= %5.0f\n",itrn,j,k,z,ped[j][k][0]);
// fprintf(fout,"itrn= %d j= %d k=%d z= %5.1f Ped= %5.0f\n",itrn,j,k,z,ped[j][k][0]);
// cHist->Fill(x);} /* else */ } /* y>0 */
// End  histograms for cross-talk analysis.

/* Test on correct trigger type, jnt=0 for forced, jnt=1 for internal trigger. */
 if((jx>0&&jnt==0)||(jx==0&&jnt==0)){if(k==0){wrg=1;
/*       printf(" itrnwrg= %d j= %d k= %d t_type= %d wrg= %d %d %5.1f\n",itrn,j,k,jnt,wrg,o[0],a[0]);*/
/* fprintf(fout," itrnwrg= %d j= %d k= %d t_type= %d wrg= %d %d %5.1f\n",itrn,j,k,jnt,wrg,o[0],a[0]);*/}}

 if(itrn!=itrfst){if(k==0){itxe=itm[j][k]; if(itxsv==0)itxsv=itxe;}}

 }/*  end test j<jn, itrn!=itrfst */ i++;} /* end while(i)              */




// End of train. Process all pixels for this trigger.

// For 4.4 pC run (jx=-1):
 if(jx<0){ nsn=0; for(l=0;l<idm;l++){ysm[l]=0; nsn+=nda[l];

if(ivv[l]>1500){printf(     " itrn=%6d ida=%d ivv=%d\n",itrn,l,ivv[l]);
              fprintf(fout," itrn=%6d ida=%d ivv=%d\n",itrn,l,ivv[l]);}

//m=l; x=ivv[l]; if(x>0.1){if(x>99)x=99; if(y>99)y=99;
//if(m==lda[0]){aHist->Fill(x);} if(m==lda[1]){bHist->Fill(x);} if(m==lda[2]){cHist->Fill(x);}
//if(m==lda[3]){dHist->Fill(x);} if(m==lda[4]){eHist->Fill(x);} if(m==lda[5]){fHist->Fill(x);}
//if(m==lda[6]){gHist->Fill(x);} if(m==lda[7]){hHist->Fill(x);} if(m==lda[8]){iHist->Fill(x);}}

 m=lda[l]; for(i=0;i<nda[m];i++){j=oo[i][m]; n=ktm[j][0][m][0]; qHist->Fill(n);
 x=aa[i][m];
//printf(      " itrn=%d j= %4d jsv=%d ida= %4d x= %6.0f z= %6.0f jst=%d\n",itrn,j,jsv,l,x,z,jst);
//fprintf(fout," itrn=%d j= %4d jsv=%d ida= %4d x= %6.0f z= %6.0f jst=%d\n",itrn,j,jsv,l,x,z,jst);
 if(x<3520)x=3520; if(x>6990)x=4960;
if(j==jsv){

// Produce Averages (ped) and variances (pdq) for each pixel, bucket, sensor.
j=oo[i][m]; y=x-ped[j][0][gn][m][0]; n=npq[j][0][gn][m][0]; pdq[j][0][gn][m][0]+=n*y*y/(n+1);
n++; ped[j][0][gn][m][0]+=y/n; npq[j][0][gn][m][0]=n;
if(n==10){z=sqrt(pdq[j][0][gn][m][0]/(n-1)); if(z>99)z=99;
if(m==lda[0]){mHist->Fill(z);} if(m==lda[1]){nHist->Fill(z);} if(m==lda[2]){oHist->Fill(z);}
if(m==lda[3]){pHist->Fill(z);} if(m==lda[4]){qHist->Fill(z);} if(m==lda[5]){rHist->Fill(z);}
if(m==lda[6]){sHist->Fill(z);} if(m==lda[7]){tHist->Fill(z);} if(m==lda[8]){jHist->Fill(z);}
/*if(z>20)*/{
printf("ped[%5d][0]= n=%3d ida=%d ped=%5.0f x=%5.0f y=%7.5f z=%5.1f\n",j,n,m,ped[j][k][gn][m][0],x,y,z);
fprintf(fout," %5d   n=%3d ida=%d ped=%5.0f x=%5.0f y=%7.5f z=%5.1f\n",j,n,m,ped[j][k][gn][m][0],x,y,z);}
} /* n==10 */

if(m==lda[0]){aHist->Fill(x);} if(m==lda[1]){bHist->Fill(x);} if(m==lda[2]){cHist->Fill(x);}
if(m==lda[3]){dHist->Fill(x);} if(m==lda[4]){eHist->Fill(x);} if(m==lda[5]){fHist->Fill(x);}
if(m==lda[6]){gHist->Fill(x);} if(m==lda[7]){hHist->Fill(x);} if(m==lda[8]){iHist->Fill(x);}
//if(j==0){if(m==lda[0]){eHist->Fill(x);} if(m==lda[1]){fHist->Fill(x);} if(m==lda[2]){gHist->Fill(x);}
//if(m==lda[3]){hHist->Fill(x);}
//if(m==lda[4]){eHist->Fill(x);} if(m==lda[5]){fHist->Fill(x);}
//if(m==lda[6]){gHist->Fill(x);} if(m==lda[7]){hHist->Fill(x);} if(m==lda[8]){iHist->Fill(x);}
} /* j==jsv */
 if(m==lda[7]){kHist->Fill(n);
 if(iee[jsv][0][0][m]>0&&j!=jsv){
//if(n>752&&n<758){jHist->Fill(j);
//printf(     "itrn=%6d ida=%d jsv= %4d H=%4d j= %4d H=%4d\n",itrn,m,jsv,tbp[jsv][0],j,tbp[j][0]);
//fprintf(fout,"itrn=%6d ida=%d jsv= %4d H=%4d j= %4d H=%4d\n",itrn,m,jsv,tbp[jsv][0],j,tbp[j][0]);}
 if(n>759&&n<769){lHist->Fill(j);}
 if(n>768&&n<773){pHist->Fill(j);}
 if(n>776&&n<783){tHist->Fill(j);}} /* iee */ } /* lda */
 } /* i */
 if(n>=nlo&&n<=nhi&&m==lda[7]){oHist->Fill(tbp[j][0]);}

 } /* l */ } /* jx<0 for 4.4 pC */

// Build clusters jcl[i][l] of ncl[l] elements in each sensor [l].
// nsv>0 for one in_time hit or two neighbors in first sensor.
 l=lda[0]; nsv=0; for(k=0;k<nda[l];k++){j=oo[k][l];
 n=ktm[j][0][l][0]; if(n>=nlo&&n<=nhi){a[nsv][l]=aa[k][l]; o[nsv][l]=j; nsv++;}} /* k */

 if(nsv>2)nsv=0; if(nsv==2){n=1; j=o[0][l]; jj=o[1][l];
 for(i=1;i<8;i++){if(j==tbp[jj][i]){n++;}} /* i */ } /* nsv */ if(n==1)nsv=0;

// if(nsv==2){
//  printf(     " nsv=%d a0=%5.1f a1=%5.1f\n",nsv,a[0][l],a[1][l]);
// fprintf(fout," nsv=%d a0=%5.1f a1=%5.1f\n",nsv,a[0][l],a[1][l]);}
// printf(" j=%d nsv=%d\n",j,nsv); fprintf(fout," j=%d nsv=%d\n",j,nsv);




 ntu=0; ntw=0; ntt=0; i13=8; xsm=0;
 if(jx>=0){for(l=0;l<idm;l++){m=lda[l];
 for(i=0;i<nda[m];i++){j=oo[i][m]; n=ktm[j][0][m][0]; x=aa[i][m];

 if(n>nlo+1&&n<nhi-1){ntu++;} if(n<nlo||n>nhi){ntw++;} else{ntt++;}

 kHist->Fill(n); if(jx>=0||(iee[jsv][0][0][m]>0&&j!=jsv)){

 if(n>nlo+8&&n<nhi+45){y=x; if(y<-20)y=-20; if(y>79)y=79; rHist->Fill(y);}

 if(n>nlo&&n<nhi){jHist->Fill(j);}
 if(n>nlo+7&&n<nhi+11){lHist->Fill(j);}
 if(n>nlo+16&&n<nhi+15){sHist->Fill(j);}
 if(n>nlo+24&&n<nhi+25){tHist->Fill(j);}} /* jx */
 if(n>nlo&&n<nhi){mda[m]++; if(x>0){ysm[m]+=x;}
// for(k=0;k<nix;k++){jsv=lix[k];for(n=1;n<i13;n++){if(j==tbp[jsv][n]){
// ntc[9]++;
// if(m==lda[0]||m==lda[1]){if(x<-10)x=-10; if(x>67)x=67;} else{if(x<-50)x=-50; if(x>197)x=197;}
// if(m==lda[0]||m==lda[1]){if(x<-10)x=-10; if(x>67)x=67;}
// if(xds[j][l]>0){kHist->Fill(n); if(x<1000)pHist->Fill(x);
//  printf(     "j= %d l= %d %5.2f x=%5.0f\n",j,l,xds[j][l],x);
// fprintf(fout,"j= %d l= %d %5.2f x=%5.0f\n",j,l,xds[j][l],x);
 if(m==lda[0]){aHist->Fill(x);} if(m==lda[1]){bHist->Fill(x);} if(m==lda[2]){cHist->Fill(x);}
 if(m==lda[3]){dHist->Fill(x);} if(m==lda[4]){eHist->Fill(x);} if(m==lda[5]){fHist->Fill(x);}
 if(m==lda[6]){gHist->Fill(x);} if(m==lda[7]){hHist->Fill(x);} if(m==lda[8]){iHist->Fill(x);}
 /*if(m==lda[9]){mHist->Fill(x);}*/ if(m==lda[10]){nHist->Fill(x);}
 if(m==lda[11]){oHist->Fill(x);} if(m==lda[12]){pHist->Fill(x);}
// } /* xds */
 if(nix<198){lix[nix]=j; nix++;}
// ncl[m]++; jcl[k][m]=j; n=i13; k=nix;} /* j */ } /* n */ } /* k */ 
// if(jtst<100){
//  printf(     "itrn=%8d n= %d m= %d k=%d j=%d h=%d ysm=%4.1f\n",itrn,ktm[j][0][m][0],m,k,j,tbp[j][0],x);
// fprintf(fout,"itrn=%8d n= %d m= %d k=%d j=%d h=%d ysm=%4.1f\n",itrn,ktm[j][0][m][0],m,k,j,tbp[j][0],x);
// }
 } /* nlo */
 if(nix>1){for(n=0;n<nix-1;n++){if(lix[nix-1]==lix[n]){nix--;}}}
 } /* i */

 if(jtst<0){for(n=0;n<nix;n++){printf(" %d",lix[n]); fprintf(fout," %d",lix[n]);} /* n */
 printf("\n"); fprintf(fout,"\n");
 for(n=0;n<nix;n++){i=lix[n]; i=tbp[i][0]; printf(" %d",i); fprintf(fout," %d",i);} /* n */
 printf("  lix\n"); fprintf(fout,"  lix\n");} /* jtst */
 /*if(ysm[m]!=0)*/{x=ivv[m]; */*x=ysm[m];*/ if(x>99){x=99;} if(m==lda[0]){mHist->Fill(mda[m]);}
// if(m==lda[0]||m==lda[1]){if(x<-10)x=-10; if(x>67)x=67;}
// if(m==lda[0]){aHist->Fill(x);} if(m==lda[1]){bHist->Fill(x);} if(m==lda[2]){cHist->Fill(x);}
// if(m==lda[3]){dHist->Fill(x);} if(m==lda[4]){eHist->Fill(x);} if(m==lda[5]){fHist->Fill(x);}
// if(m==lda[6]){gHist->Fill(x);} if(m==lda[7]){hHist->Fill(x);} if(m==lda[8]){iHist->Fill(x);}
 } /* ysm */  xsm+=ysm[m];
 } /* l */ } /* jx */




// if(nix>99)nix=99; if(nix>0)pHist->Fill(nix);
 if(jtst<10){printf(" itrn=%8d xsm=%5.0f\n",itrn,xsm); fprintf(fout," itrn=%8d xsm=%5.0f\n",itrn,xsm);}

 if(xsm>23700)xsm=23700; if(xsm!=0){if(nix>5){/*jHist->Fill(xsm);*/} else{
 m=0; for(i=0;i<idm;i++){if(mda[i]>0)m++;} if(m>0){jbt[m]++; jbt[29]++;
// if(m>7){
//  printf(     "itrn=%8d n= %d jfl= %d k=%d j=%d h=%d x=%4.1f\n",itrn,ktm[j][0][m][0],jfl,k,j,tbp[j][0],x);
// fprintf(fout,"itrn=%8d n= %d jfl= %d k=%d j=%d h=%d x=%4.1f\n",itrn,ktm[j][0][m][0],jfl,k,j,tbp[j][0],x);}
// if(m>6){if(xsm>99)xsm=99; lHist->Fill(xsm);}
 } /* m */ } /* else */ } /* xsm */


 {irw++; jfl=0;

 l=lda[1]; m=lda[2]; if(mda[l]==0){ntc[6]++; if(mda[m]==0)ntc[8]++;} if(mda[m]==0)ntc[7]++; 

// zmx, qmz, nmz only for external trigggers.
// if(jtm>0){nsw=0; nsv=2; k=0; for(i=0;i<idm;i++){if(nmz[0][i]>1){x=sqrt(qmz[0][i]/(nmz[0][i]-1));
// if(x>2){nsv--; mda[i]=0;} if(x>9.9)x-9.9; mHist->Fill(x);}}}
// if(nsv>=0)nsv=0;

// if(jx>0&&jx!=3&&nsv>=0&&jtm>0){
// k==0; for(j=0;j<jn;j++){for(i=0;i<idm;i++){if(iee[j][k][0][i]>0&&mda[i]>0){
// y=q[j][k][i]; if(y<-4)y=-4; if(y>34)y=34;
////   printf(     " itrn= %d j= %d k= %d jtst=%5.0f\n",itrn,j,k,jtst);
////  fprintf(fout," itrn= %d j= %d k= %d jtst=%5.0f\n",itrn,i,j,jtst);
// if(i==0)aHist->Fill(y); if(i==1)bHist->Fill(y); if(i==2)cHist->Fill(y);
// if(i==3)dHist->Fill(y); if(i==4)eHist->Fill(y); if(i==5)fHist->Fill(y);
// if(i==6)gHist->Fill(y); if(i==7)hHist->Fill(y); if(i==8)iHist->Fill(y);
//// lHist->Fill(x);kHist->Fill(z/*-xtm*/);
// } /* j */ } /* i */ } /* iee */ } /* jx */

// k=lda[0]; l=lda[1]; if(/*mda[k]<2&&*/mda[l]==1&&a[0][l]<10){irw++; ii=ntr;
 if(jtm>0)ct1++;

// Forced triggers jx>0, jnt=0, but not min-max analysis jx=3.
/* if(jx>0&&jx!=3)*/

 {i2=8; i13=7;
// for(i=0;i<idm;i++){if(mda[i]>95){
//  printf(     "itrn=%8d i= %d mda=%d\n",itrn,i,mda[i]);
// fprintf(fout,"itrn=%8d i= %d mda=%d\n",itrn,i,mda[i]); mda[i]=40;}}

 nsv=0; l6=0; l4=1; l5=lda[0]; if(mda[l5]<1){l5=lda[1]; l4=2;}
 for(l0=0;l0<mda[l5];l0++){jv[0]=l0; mv[0]=l5; nsv=1;
//  printf(     "itrn=%8d nsv= %d l0= %d l5=%d mda=%d\n",itrn,nsv,l0,l5,mda[l5]);
// fprintf(fout,"itrn=%8d nsv= %d l0= %d l5=%d mda=%d\n",itrn,nsv,l0,l5,mda[l5]);

 nsv=0;
 if(nsv>0){for(k=l4;k<9;k++){l3=lda[k]; lj=-1; l=jv[nsv-1]; m=mv[nsv-1]; if(m>29)m=29; jsv=o[l][m];
 for(l2=0;l2<mda[l3];l2++){j=o[l2][l3]; jv[nsv]=l2; mv[nsv]=l3;
 for(i=1;i<i13;i++){if(j==tbp[jsv][i]){nsv++; lj=l2; l2=mda[l3];
 } /* j */ } /* i */ } /* l2 */
 } /* k */
 if(mda[l5]>1){if(nsv>l6){l6=nsv; l7=l0;}
//  printf(     "itrn=%8d nsv= %d l0= %d l5=%d mda=%d\n",itrn,nsv,l0,l5,mda[l5]);
// fprintf(fout,"itrn=%8d nsv= %d l0= %d l5=%d mda=%d\n",itrn,nsv,l0,l5,mda[l5]);
 }
 } /* nsv */
 /*l0=mda[l5];*/} /* l0 */

// if(l6>0&&mda[l5]>1){
//  printf(     "itrn=%8d l6= %d l7= %d l5=%d mda=%d\n",itrn,l6,l7,l5,mda[l5]);
// fprintf(fout,"itrn=%8d l6= %d l7= %d l5=%d mda=%d\n",itrn,l6,l7,l5,mda[l5]);}

 if(l6>0){nsw=0; jv[0]=l7; nsv=1;
 for(k=l4;k<9;k++){l3=lda[k]; lj=-1; l=jv[nsv-1]; m=mv[nsv-1]; if(m>29)m=29; jsv=o[l][m];
//  printf(     "itrn=%8d nsv= %d l3= %d jsv=%d\n",itrn,nsv,l3,jsv);
// fprintf(fout,"itrn=%8d nsv= %d l3= %d jsv=%d\n",itrn,nsv,l3,jsv);
 for(l2=0;l2<mda[l3];l2++){j=o[l2][l3]; jv[nsv]=l2; mv[nsv]=l3;
//  printf(     "itrn=%8d nsv= %d l2= %d jsv=%d j=%d\n",itrn,nsv,l2,jsv,j);
// fprintf(fout,"itrn=%8d nsv= %d l2= %d jsv=%d j=%d\n",itrn,nsv,l2,jsv,j);
 for(i=1;i<13;i++){if(j==tbp[jsv][i]){nsv++; if(nsv>6){
//  printf(     "itrn=%8d nsv= %d l2= %d %d %d\n",itrn,nsv,l3,tbp[jsv][0],tbp[j][0]);
// fprintf(fout,"itrn=%8d nsv= %d l2= %d %d %d\n",itrn,nsv,l3,tbp[jsv][0],tbp[j][0]);
 } /* nsv */ lj=l2; l2=mda[l3];
 } /* j */ } /* i */ } /* l2 */
 } /* k */ } /* l6 */

 if(nsv>0){x=0; n=0; for(i=0;i<nsv;i++){j=jv[i]; m=mv[i]; y=a[j][m];
 if(y!=0.0){n++; /*if(y<-4)y=-4; if(y>34)y=34; jHist->Fill(y);*/ if(j>499)j=499; x+=((a[j][m]-x)/(n+1));}
// if(nsv==1){l=0; for(k=0;k<idm;k++){if(mda[k]>0){l++;}}
//  printf(     "itrn=%8d i= %d j= %d m= %d l=%d %4.1f %4.1f   ",itrn,i,j,m,l,a[j][m],x);
// fprintf(fout,"itrn=%8d i= %d j= %d m= %d l=%d %4.1f %4.1f   ",itrn,i,j,m,l,a[j][m],x);
// for(k=0;k<idm;k++){printf(" %d",mda[k]); fprintf(fout," %d",mda[k]);
// } printf("\n"); fprintf(fout,"\n");}
 } /* i */ ibt[nsv]++; ibt[29]++; /*if(nsv>4)mHist->Fill(x);*/ lbt[nsv+nsw]++; lbt[29]++;} /* nsv */

// if(nsv>0){m=0; for(i=0;i<idm;i++){if(mda[i]>0)m++;} if(m>0){jbt[m]++; if(m>0)jbt[29]++;}}

// } /* test mda */
 } /* jx */

 m=0; for(i=0;i<idm;i++){if(mda[i]>0){m++;}} kbt[m]++; /*if(m>0)*/kbt[29]++;

//// if(m>3&&m<9){printf(" itrn= %d",itrn); fprintf(fout," itrn= %d",itrn); for(i=0;i<idm;i++){
// if(mda[0]>0&&mda[8]>0){printf(" itrn= %d",itrn); fprintf(fout," itrn= %d",itrn);
// for(i=0;i<idm;i++){
// if(mda[i]==0){kv[i]++; printf(" s_%d= %d",i,mda[i]); fprintf(fout," s%d= %d",i,mda[i]);}
// if(i==(idm-1)){printf(" \n"); fprintf(fout," \n");}} /* i */
// m=0; for(i=0;i<idm;i++){if(mda[i]==0){m++;}} kbt[m]++; kbt[29]++;} /* test m or mda */

// Pixels with single hits.
// if(jx==0&&m==1){j=o[0][k]; x=a[0][k]; l=tbp[j][0]; mHist->Fill(l);}
// fprintf(fout," itrn= %5d ntt=%d K=%4d H=%4d sensor= %4d x=%4.1f\n",itrn,ntt,j,tbp[j][0],k,x);
//  printf(     " itrn= %5d ntt=%d K=%4d H=%4d sensor= %4d x=%4.1f\n",itrn,ntt,j,tbp[j][0],k,x);}

// ii=0; for(i=0;i<9;i++){l=mda[i]; if(l>0){ii++;
// if(i==0)aHist->Fill(l); if(i==1)bHist->Fill(l); if(i==2)cHist->Fill(l); if(i==3)dHist->Fill(l);
// if(i==4)eHist->Fill(l); if(i==5)fHist->Fill(l); if(i==6)gHist->Fill(l); if(i==7)hHist->Fill(l);
// if(i==8)iHist->Fill(l);
// }} jbt[ii]++; jbt[29]++;

// For forced triggers (jx>0) reject short records, count in (jsh)
 if(jx>0&&ct<jn-ibad){jsh++;
//       printf(" itrnjsh= %d ct= %d ibad= %d wrg= %d\n",itrn,ct,ibad,jsh);
// fprintf(fout," itrnjsh= %d ct= %d ibad= %d wrg= %d\n",itrn,ct,ibad,jsh);
 }

 else{if(itxe-itxsv==1)jne++; if(itxe-itxsv>1)jgo++;
 if(jx==0||itxe==itxsv||jn>512){if(itxe==itxsv){jeq++;} }}  /* end  else: jx==0||ct>=jn-ibad  */

 if((jx==0||itxe==itxsv||jn>512||jn==128)/*&&(ct==jn-ibad)*/)
 {
 if(wrg==1){cwg++;} elseif(jx==0||(ct==jn-ibad))
// {     /*  accept good triggers  */ {
 jal++;



 if(jx>0&&jx!=3){k=0; if(cv>1){wsq=sqrt(wsq/(cv-1)); a[0]-=wsm; a[1]-=wsm;}
 if(wsm!=0&&wsq!=0){z=wsq; if(z>0.9)z=0.9; jHist->Fill(z); /*wsq=0;*/
 if(wsq>wqx){wqt++;} else{z=wsm; if(z<-2)z=-2; if(z>1.9)z=1.9; hHist->Fill(z); /*wsm=0;*/
 if(wsm<-wsx||wsm>wsx){wct++;} else{
 for(j=0;j<jn;j++){if(iee[j][0][0][ida]==0||ih[j][k]<0)continue;
 x=qq[j][k]; x-=wsm; z=itm[j][k]-xtm;
 y=x; if(y<-2)y=-2; if(y>1.9)y=1.9; if(j!=o[0])eHist->Fill(y);
/* if((z>1.4&&z<2.8))*/{/*cHist->Fill(x); mHist->Fill(z);*/}
//  printf(     "itrn= %d j= %d k= %d jnt= %d x= %4.1f z= %4.1f\n",itrn,j,k,jnt,x,z);
// fprintf(fout,"itrn= %d j= %d k= %d jnt= %d x= %4.1f z= %4.1f\n",itrn,j,k,jnt,x,z);
/* if(j!=o[0]&&j!=o[1]&&j!=o[2])*/{/*if((z>1.4&&z<2.8))*/{x-=xav[j][k];
 xsq[j][k]+=jav[j][k]*x*x/(jav[j][k]+1); jav[j][k]++; xav[j][k]+=x/jav[j][k];}
 aHist->Fill(j); /*dHist->Fill(ztm*itm[j][k]);*/} /*j!=o[0]*/
//  printf(     "itrn= %d j= %d k=%d wsm4= %4.1f qq= %5.1f Ped= %5.0f\n",itrn,j,k,wsm,qq[j][k],ped[j][k][0]);
// fprintf(fout,"itrn= %d j= %d k=%d wsm4= %4.1f qq= %5.1f Ped= %5.0f\n",itrn,j,k,wsm,qq[j][k],ped[j][k][0]);}
 if(j==o[0]){fHist->Fill(a[0]);

/* Make list of raw data                                                       */
 /*if(jdatp>0&&itm[j][0]>xtm&&itm[j][0]<xtm+5)*/{ m=-1; z=0; if(n>1){m=o[1]; z=a[1];}
  printf(     " %8d %5d %5.1f j= %5d %5.0f wsm= %5.2f wsq= %6.2f a= %6.2f\n",itrn,m,z,j,itm[j][0],wsm,wsq,a[0]);
 fprintf(fout," %8d %5d %5.1f j= %5d %5.0f wsm= %5.2f wsq= %6.2f a= %6.2f\n",itrn,m,z,j,itm[j][0],wsm,wsq,a[0]);}
/* End  list of raw data                                                       */

/* if((a[0]>2.4&&a[0]<30&&n>0))*/{
// aHist->Fill(j); /*dHist->Fill(ztm*itm[j][k]); gHist->Fill(a[0]);*/
// if(n>1)bHist->Fill(a[1]);
// if(n>3){ j=o[0]; m=o[1]; l=o[2];
//  printf(     "itrn= %d j= %d m=%d l= %d a0= %4.1f a1= %5.1f a2= %5.1f %4.1f\n",itrn,j,m,l,a[0],a[1],a[2],a[3]);
// fprintf(fout,"itrn= %d j= %d m=%d l= %d a0= %4.1f a1= %5.1f a2= %5.1f %4.1f\n",itrn,j,m,l,a[0],a[1],a[2],a[3]);}
// if(n>2)cHist->Fill(a[2]);
 } /* test a0 */ } /* j==o[0] */ } /* end j */ } /* test wsm */ } /* test wsq */ } /*jx */

// make table:
// if(abs(wsm)<wsx){if(wsq<wqx){
// x=a[0]; jm=o[0]; m=x; if(m<0)m=0; else m+=1; ia[jm][0]=jm;
//  printf(     " %d m= %d jm= %d a0= %5.1f qq= %5.1f\n",itrn,m,jm,a[0],adv[jmx][0]);
// fprintf(fout," %d m= %d jm= %d a0= %5.1f qq= %5.1f\n",itrn,m,jm,a[0],adv[jmx][0]);
// if(m>14)m=14; ia[jm][m+1]++; ia[jn][m+1]++; ia[jn+1][m+1]++; sm++;
// } /* wsq */ } /* wsm */

// } /*  end full record (?) end abs(wsm)<70  */
// } /*  end skip wrong trigger   */
 } /*  end train (?) end jne true   */
 } /*  end reject large average rms */
 } /*  end reject large average rms */
 } /*  end count < 150              */
 } /*  end count u=idm              */
 } /* end while(r->next(&e))        */

 delete r;
 } /* jtr */

// Print xav
// k=0; for(j=0;j<jn;j++){if(iee[j][k][0][0]==0)continue; l=jav[j][k];
// if(l>0){z=xav[j][k]; if(z<-5)z=-5; if(z>14.9)z=14.9; gHist->Fill(z);
// if(iee[j][k][0][0]>0){/*cHist->Fill(xav[j][k]);*/
// {y=slp[j][k][gn][0]; if(l>0){
// if(l>1){x=sqrt(xsq[j][k]/(l-1));}
// z=(xav[j][k]-0.0)*y;} ped[j][k][0]+=z; if(x>4.99)x=4.99; /*if(jx>0)mHist->Fill(x); bHist->Fill(ped[j][k][0]/y);*/
//                                                                                    aHist->Fill(ped[j][k][0]/y);
// if(z>1.4||z<-1.4){
////  printf(      "xav[%d][0]= %5.1f %d sl= %5.1f %4.1f %4.0f ped= %4.1f\n",j,xav[j][k],l,y,x,z,ped[j][k]);
//// fprintf(fout," xav[%d][0]= %5.1f %d sl= %5.1f %4.1f %4.0f ped= %4.1f\n",j,xav[j][k],l,y,x,z,ped[j][k]);
// }}}}
// else {if(/*iee[j][k][0][0]>0||slp[j][k][gn][0]>0*/ xav[j][k]<1&&jav[j][k]>0){
////  printf(      "xav[%d][0]= %5.1f %d %5.1f %4.0f %4.0f %4.1f\n",j,xav[j][k],jav[j][k],y,x,z,ped[j][k]);
//// fprintf(fout," xav[%d][0]= %5.1f %d %5.1f %4.0f %4.0f %4.1f\n",j,xav[j][k],jav[j][k],y,x,z,ped[j][k]);
// fprintf(fout," %d %5.1f\n",j,xav[j][k]);
// }}}
////  printf(      "xav[%d][0]= %5.1f %d %d\n",j,xav[j][k],jav[j][k],iee[j][k][0][0]);
//// fprintf(fout,"         %5d %5.1f %d %d\n",j,xav[j][k],jav[j][k],iee[j][k][0][0]);}}
////  printf(      "ped[%d][0]= %d %d %4.0f\n",j,k,k,ped[j][k]);
//// fprintf(fout,"         %5d %d %d %4.0f\n",j,k,k,ped[j][k]);}
// End   xav

 } /* ite */

// Print jdead
// nsm=0; for(j=0;j<jn;j++){nsm+=jdead[j]; if(jdead[j]>0&&jdead[j]<100){
//  printf(     "j=%5d jdead=%4d\n",j,jdead[j]);
// fprintf(fout,"j=%5d jdead=%4d\n",j,jdead[j]);}}
//  printf(     " nsm=%4d\n",nsm); fprintf(fout," nsm=%4d\n",nsm);

// Print yav
// for(j=0;j<200;j++){if(kav[j]>0)yav[j]/=kav[j];
//  printf(     "yav[%d]= %5.1f %d\n",j,yav[j],kav[j]);
// fprintf(fout,"yav[%d]= %5.1f %d\n",j,yav[j],kav[j]);}
// End   yav

// Print mmv
// for(l=0;l<idm;l++){for(j=0;j<jn;j++){m=tbp[j][0];
// if(mmv[j][l]>500&&iee[j][0][0][l]>0){printf(     " jsv=%6d HAMA=%5d ida=%d mmv=%d\n",j,m,l,mmv[j][l]);
//                  fprintf(fout," jsv=%6d HAMA=%5d ida=%d mmv=%d\n",j,m,l,mmv[j][l]);}}}
// printf("\n"); fprintf(fout,"\n");
// for(j=0;j<jn;j++){m=tbp[j][0]; for(l=0;l<idm;l++){
// if(mmv[j][l]>500&&iee[j][0][0][l]>0){printf(     " jsv=%6d HAMA=%5d ida=%d mmv=%d\n",j,m,l,mmv[j][l]);
//                  fprintf(fout," jsv=%6d HAMA=%5d ida=%d mmv=%d\n",j,m,l,mmv[j][l]);}}}

// Print nnv
 jk=4; nsn=0; printf("\n\n"); fprintf(fout,"\n\n");
 for(k=0;k<jk;k++){
 for(l=0;l<9;l++){
 for(j=0;j<jn;j++){
// if((k>0&&nnv[j][k][l]>500)||nnv[j][k][l]>5000){
 if(k==0&&iee[j][k][0][l]==1&&nnv[j][k][l]<2){
//  printf(     "pixel=%5d bucket=%d sensor=%d nnv=%5d\n",j,k,l,nnv[j][k][l]);
// fprintf(fout,"pixel=%5d bucket=%d sensor=%d nnv=%5d\n",j,k,l,nnv[j][k][l]);
 if(j>0){nnv[0][k][l]+=nnv[j][k][l];}}} /* j */ } /* l */ } /* k */
 printf("\n\n"); fprintf(fout,"\n\n");

 for(k=0;k<jk;k++){
 for(l=0;l<9;l++){
 if(nnv[0][k][l]>0){
  printf(     "bucket=%d sensor=%d nnv=%5d\n",k,l,nnv[0][k][l]);
 fprintf(fout,"bucket=%d sensor=%d nnv=%5d\n",k,l,nnv[0][k][l]);
 nsn+=nnv[0][k][l];}} /* l */ } /* k */

//  printf(     "\nSum of Pixel Hits=%5d\n\n",nsn);
// fprintf(fout,"\nSum of Pixel Hits=%5d\n\n",nsn);

// Print kv
// for(l=0;l<9;l++){
//  printf(     " sensor=%d kv=%5d\n",l,kv[l]);
// fprintf(fout," sensor=%d kv=%5d\n",l,kv[l]);}

// Print mar
// fprintf(fout,"\n Bad Pixels in up to Five Assemblies:\n");
// fprintf(fout,"\n    1    2    3   4a   4b  1-2  1-3  1-4  2-3 4a-4b\n");
// for(j=0;j<200;j++){if(mar[j][2]!=0){nn[2]++;} if(mar[j][4]!=0){nn[4]++;}}
// for(j=0;j<200;j++){if(mar[j][0]!=0){nn[0]++;
// for(n=0;n<200;n++){if(mar[j][0]==mar[n][1]){k=nn[5]; mar[k][5]=mar[j][0]; nn[5]++;}}}}
// for(j=0;j<200;j++){if(mar[j][0]!=0){
// for(n=0;n<200;n++){if(mar[j][0]==mar[n][2]){k=nn[6]; mar[k][6]=mar[j][0]; nn[6]++;}}}}
// for(j=0;j<200;j++){if(mar[j][0]!=0){
// for(n=0;n<200;n++){if(mar[j][0]==mar[n][3]){k=nn[7]; mar[k][7]=mar[j][0]; nn[7]++;}}}}
// for(j=0;j<200;j++){if(mar[j][1]!=0){nn[1]++;
// for(n=0;n<200;n++){if(mar[j][1]==mar[n][2]){k=nn[8]; mar[k][8]=mar[j][1]; nn[8]++;}}}}
// for(j=0;j<200;j++){if(mar[j][3]!=0){nn[3]++;
// for(n=0;n<200;n++){if(mar[j][3]==mar[n][4]){k=nn[9]; mar[k][9]=mar[j][3]; nn[9]++;}}}}
// for(i=0;i<10;i++){printf("%5d",nn[i]); fprintf(fout,"%5d",nn[i]);}
// printf("\n\n"); fprintf(fout,"\n\n");
// for(j=0;j<200;j++){if((mar[j][0]+mar[j][1]+mar[j][2]+mar[j][3]+mar[j][4])>0){
// for(i=0;i<10;i++){printf("%5d",mar[j][i]); fprintf(fout,"%5d",mar[j][i]);}
// printf("\n"); fprintf(fout,"\n");}}
// End   mar

  printf(     "count= %d itrfst= %d itrn= %d ntu=%d ntw=%d ntt=%d\n",count,itrfst,itrn,ntu,ntw,ntt);
 fprintf(fout,"count= %d itrfst= %d itrn= %d ntu=%d ntw=%d ntt=%d\n",count,itrfst,itrn,ntu,ntw,ntt);

// Print table of individual channels.
 for(i=0;i<jn;i++){for(j=0;j<idm;j++){if(ia[i][j]>10000){if(iee[i][0][0][j])>0){
 fprintf(fout,"        %4d %5d         %d %6d\n",i,tbp[i][0],j,ia[i][j]);
  printf(     " pixel= %4d %5d sensor= %d %6d\n",i,tbp[i][0],j,ia[i][j]);}}}}

// for(i=0;i<jn+2;i++){{fprintf(fout," pixel= %4d %6d",ia[i][0],ia[i][1]);
// printf(" pixel= %4d %6d",ia[i][0],ia[i][1]); for(k=2;k<15;k++){printf("%4d",ia[i][k]);
// fprintf(fout,"%4d",ia[i][k]);} printf(" over= %6d\n",ia[i][15]);
// fprintf(fout," over= %6d\n",ia[i][15]);}
// } /* end mer>0 */

/* Print some diagnostics.                                                     */
 fprintf(fout," Number of Cycles            (jtst) = %d\n",jtst);
  printf(     " Number of Cycles            (jtst) = %d\n",jtst);
if(ite==0){
// fprintf(fout," New blocks= %d\n",ibl);
//  printf(     " New blocks= %d\n",ibl);
 fprintf(fout," Cycles with data (irw)= %d\n",irw);
  printf(     " Cycles with data (irw)= %d\n",irw); irw-=jsh;
// fprintf(fout," Short records= %d (%d)\n",jsh,irw);
//  printf(     " Short records= %d (%d)\n",jsh,irw); irw-=jne;
// fprintf(fout," Delta-t=1-records= %d (%d)\n",jne,irw);
//  printf(     " Delta-t=1-records= %d (%d)\n",jne,irw); irw-=jgo;
// fprintf(fout," Delta-t>1-records= %d (%d)\n",jgo,irw);
//  printf(     " Delta-t>1-records= %d (%d)\n",jgo,irw);
// fprintf(fout," Delta-t=0-records= %d\n",jeq);
//  printf(     " Delta-t=0-records= %d\n",jeq); jeq-=cwg;
 fprintf(fout," Wrong trigger type %d \n",cwg);
  printf(     " Wrong trigger type %d \n",cwg);
 fprintf(fout," Accepted Records (jal)= %d\n",jal);
  printf(     " Accepted Records (jal)= %d\n",jal); jal-=wct;
// fprintf(fout," Rejects av. resid.= %d (%d)\n",wct,jal);
//  printf(     " Rejects av. resid.= %d (%d)\n",wct,jal); jal-=wqt;
// fprintf(fout," Rejects av. sq   .= %d (%d)\n",wqt,jal);
//  printf(     " Rejects av. sq   .= %d (%d)\n",wqt,jal);
 fprintf(fout," Bucket_0 Hits                (ct0) = %d\n",ct0);
  printf(     " Bucket_0 Hits                (ct0) = %d\n",ct0);
 fprintf(fout," Bucket_1-3 Hits              (ct1) = %d\n",ct1);
  printf(     " Bucket_1-3 Hits              (ct1) = %d\n",ct1);
 fprintf(fout," Cycles with count=9          (ct3) = %d\n",ct3);
  printf(     " Cycles with count=9          (ct3) = %d\n",ct3);
 fprintf(fout," cycles with >=1 pixels       (ct4) = %d\n",ct4);
  printf(     " cycles with >=1 pixels       (ct4) = %d\n",ct4);
 fprintf(fout," cycles with count>500        (ct5) = %d\n",ct5);
  printf(     " cycles with count>500        (ct5) = %d\n",ct5);
 fprintf(fout," Losses in second sensor     (ntc6) = %d\n",ntc[6]);
  printf(     " Losses in second sensor     (ntc6) = %d\n",ntc[6]);
 fprintf(fout," Losses in third sensors     (ntc7) = %d\n",ntc[7]);
  printf(     " Losses in third sensors     (ntc7) = %d\n",ntc[7]);
 fprintf(fout," Losses in both Sensors      (ntc8) = %d\n",ntc[8]);
  printf(     " Losses in both Sensors      (ntc8) = %d\n",ntc[8]);
 fprintf(fout," Matches first and second    (ntc9) = %d\n",ntc[9]);
  printf(     " Matches first and second    (ntc9) = %d\n",ntc[9]);
for(i=0;i<=9;i++){
 fprintf(fout," Raw %9d Sensor/Track Hits (%d)= %6d    %6d  %6d\n",kbt[i],i,jbt[i],ibt[i],lbt[i]);
  printf(     " Raw %9d Sensor/Track Hits (%d)= %6d    %6d  %6d\n",kbt[i],i,jbt[i],ibt[i],lbt[i]);}
 fprintf(fout,"\n Raw %9d Sum Sensors/Tracks     %6d    %6d  %6d\n",kbt[29],jbt[29],ibt[29],lbt[29]);
  printf(     "\n Raw %9d Sum Sensors/Tracks     %6d    %6d  %6d\n",kbt[29],jbt[29],ibt[29],lbt[29]);
 } /* ite */

// fprintf(fout," triggers= %d; amx= %5.1f (0,1,2,3,4 or more)>amx= %d %d %d %d %d\n",
// sm,amx,cc[0],cc[1],cc[2],cc[3],cc[4]);
// fprintf(fout,     " %d %d %d %d %d %d %d %d %d %d zct= %d zsm= %8.0f\n",
// w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7],w[8],w[9],zct,zsm);
//  printf(     " triggers= %d; amx= %5.1f (0,1,2,3,4 or more)>amx= %d %d %d %d %d\n",
// sm,amx,cc[0],cc[1],cc[2],cc[3],cc[4]);
//  printf(          " %d %d %d %d %d %d %d %d %d %d zct= %d zsm= %8.0f\n",
// w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7],w[8],w[9],zct,zsm);

//TCanvas *c1 = new TCanvas("charge","090518");

c2->Divide(2,4,.007,.007);
c2->cd(1); aPlot->Draw(); t1->Draw("same");
c2->cd(2); bPlot->Draw(); t1->Draw("same");
c2->cd(3); cPlot->Draw(); t2->Draw("same");
c2->cd(4); dPlot->Draw(); t2->Draw("same");
c2->cd(5); /*gPad->SetLogx(); gPad->SetLogy();*/ eHist->Draw(); eHist->Fit("gaus","q","",-1.5,1.5);  
c2->cd(6); /*gPad->SetLogx(); gPad->SetLogy();*/ fHist->Draw(); fHist->Fit("gaus","q","",-1.5,1.5);  
c2->cd(7); /*gPad->SetLogx(); gPad->SetLogy();*/ gHist->Draw();
c2->cd(8); /*gPad->SetLogx(); gPad->SetLogy();*/ hHist->Draw();


// For Survey
// c1->Divide(3,6,.007,.007);
// c1->cd(1)/*->SetLogy()*/; aHist->Draw(); aHist->Fit("gaus","q");
// c1->cd(2)/*->SetLogy()*/; bHist->Draw(); bHist->Fit("gaus","q");
// c1->cd(3)/*->SetLogy()*/; cHist->Draw(); cHist->Fit("gaus","q");
// c1->cd(4)/*->SetLogy()*/; dHist->Draw(); dHist->Fit("gaus","q");
// c1->cd(5)/*->SetLogy()*/; eHist->Draw(); eHist->Fit("gaus","q");
// c1->cd(6)/*->SetLogy()*/; fHist->Draw(); fHist->Fit("gaus","q");
// c1->cd(7)/*->SetLogy()*/; gHist->Draw(); gHist->Fit("gaus","q"); 
// c1->cd(8)/*->SetLogy()*/; hHist->Draw(); hHist->Fit("gaus","q");
// c1->cd(9)/*->SetLogy()*/; iHist->Draw(); iHist->Fit("gaus","q");
// c1->cd(10)/*->SetLogy()*/; jHist->Draw(); jHist->Fit("gaus","q");
// c1->cd(11)/*->SetLogy()*/; kHist->Draw(); kHist->Fit("gaus","q");
// c1->cd(12)/*->SetLogy()*/; lHist->Draw(); lHist->Fit("gaus","q");
// c1->cd(13)/*->SetLogy()*/; mHist->Draw(); mHist->Fit("gaus","q"); 
// c1->cd(14)/*->SetLogy()*/; nHist->Draw(); nHist->Fit("gaus","q"); 
// c1->cd(15)/*->SetLogy()*/; oHist->Draw(); oHist->Fit("gaus","q"); 
// c1->cd(16)/*->SetLogy()*/; pHist->Draw(); pHist->Fit("gaus","q"); 
// c1->cd(17)/*->SetLogy()*/; qHist->Draw(); qHist->Fit("gaus","q"); 
// c1->cd(18)/*->SetLogy()*/; rHist->Draw(); rHist->Fit("gaus","q"); 

// c1->Divide(1,4,.007,.007);
// c1->cd(1)->SetLogy(); aHist->Draw(); /*aHist->Fit("gaus","q");*/
// c1->cd(2)->SetLogy(); bHist->Draw(); bHist->Fit("gaus","q");
// c1->cd(3)->SetLogy(); cHist->Draw(); cHist->Fit("gaus","q");
// c1->cd(4)/*->SetLogy()*/; dHist->Draw(); dHist->Fit("gaus","q");

//// For Cosmics
//c1->Divide(4,5,.001,.001);
////c1->Divide(4,6,.003,.003);
////c1->Divide(4,2,.007,.007);
////c1->Divide(4,4,.007,.007);
////c1->cd(1)/*->SetLogy()*/; aHist->Draw(); /*aHist->Fit("gaus","q","",4000,4600);*/
////c1->cd(2)/*->SetLogy()*/; bHist->Draw(); bHist->Fit("gaus","q","",4000,4600);
////c1->cd(3)/*->SetLogy()*/; cHist->Draw(); cHist->Fit("gaus","q","",4000,4600);
////c1->cd(4)/*->SetLogy()*/; dHist->Draw(); dHist->Fit("gaus","q","",4000,4600);
////c1->cd(5)/*->SetLogy()*/; eHist->Draw(); /*eHist->Fit("gaus","q","",3500,5000);*/
////c1->cd(6)/*->SetLogy()*/; fHist->Draw(); /*fHist->Fit("gaus","q","",3500,5000);*/
////c1->cd(7)/*->SetLogy()*/; gHist->Draw(); /*gHist->Fit("gaus","q","",3500,5000);*/
////c1->cd(8)/*->SetLogy()*/; hHist->Draw(); /*hHist->Fit("gaus","q","",3500,5000);*/
//c1->cd(1)/*->SetLogy()*/; aHist->Draw(); /*aHist->Fit("landau","q","",0.5,60);*/
////TF1 *landau = aHist->GetFunction("landau"); 
//c1->cd(2)/*->SetLogy()*/; bHist->Draw(); /*bHist->Fit("gaus","q");*/
//c1->cd(3)/*->SetLogy()*/; cHist->Draw(); /*cHist->Fit("gaus","q");*/
//c1->cd(4)/*->SetLogy()*/; dHist->Draw(); /*dHist->Fit("landau","q","",0.5,60);*/
//c1->cd(5)/*->SetLogy()*/; eHist->Draw(); /*eHist->Fit("gaus","q","",100,600);*/
//c1->cd(6)/*->SetLogy()*/; fHist->Draw(); /*fHist->Fit("gaus","q","",50,300);*/
//c1->cd(7)/*->SetLogy()*/; gHist->Draw(); /*gHist->Fit("gaus","q","",100,400);*/
//c1->cd(8)/*->SetLogy()*/; hHist->Draw(); /*hHist->Fit("gaus","q","",-2,2);*/
//c1->cd(9)/*->SetLogy()*/;  iHist->Draw(); /*iHist->Fit("gaus","q","",0.1,0.5);*/
//c1->cd(10)/*->SetLogy()*/; jHist->Draw(); /*jHist->Fit("gaus","q","",0.1,0.5);*/
//c1->cd(11)/*->SetLogy()*/; kHist->Draw(); /*kHist->Fit("gaus","q","",0.1,0.5);*/
//c1->cd(12)/*->SetLogy()*/; lHist->Draw(); /*lHist->Fit("gaus","q","",0.1,0.5);*/
//c1->cd(13)/*->SetLogy()*/; mHist->Draw(); mHist->Fit("gaus","q","",0.1,.6); 
//c1->cd(14)/*->SetLogy()*/; nHist->Draw(); nHist->Fit("gaus","q","",0.1,.6); 
//c1->cd(15)/*->SetLogy()*/; oHist->Draw(); oHist->Fit("gaus","q","",0.1,.6); 
//c1->cd(16)/*->SetLogy()*/; pHist->Draw(); pHist->Fit("gaus","q","",0.1,.6); 
//c1->cd(17)/*->SetLogy()*/; qHist->Draw(); qHist->Fit("gaus","q","",0,0.2);
//c1->cd(18)/*->SetLogy()*/; rHist->Draw(); rHist->Fit("gaus","q","",0,0.2);
//c1->cd(19)/*->SetLogy()*/; sHist->Draw(); sHist->Fit("gaus","q","",0,0.2);
//c1->cd(20)/*->SetLogy()*/; tHist->Draw(); tHist->Fit("gaus","q","",0,0.2);
////c1->cd(21)/*->SetLogy()*/; uHist->Draw(); /*uHist->Fit("gaus","q","",50,150);*/
////c1->cd(22)/*->SetLogy()*/; vHist->Draw(); /*vHist->Fit("gaus","q","",50,150);*/
////c1->cd(23)/*->SetLogy()*/; wHist->Draw(); /*wHist->Fit("gaus","q","",50,150);*/
////c1->cd(24)/*->SetLogy()*/; xHist->Draw(); /*xHist->Fit("gaus","q","",50,150);*/
////x = landau->Integral(0,30.0);
////printf("landau= %8.3f\n",x); fprintf(fout,"landau= %8.3f\n",x);

// For Cosmics with External Triggers
// c1->Divide(3,5,.007,.007);
// c1->cd(1)->SetLogy(); aHist->Draw(); aHist->Fit("gaus","q");
// c1->cd(2)->SetLogy(); bHist->Draw(); bHist->Fit("gaus","q");
// c1->cd(3)->SetLogy(); cHist->Draw(); cHist->Fit("gaus","q");
// c1->cd(4)->SetLogy(); dHist->Draw(); dHist->Fit("gaus","q");
// c1->cd(5)->SetLogy(); eHist->Draw(); eHist->Fit("gaus","q","",0.1,0.2);
// c1->cd(6)->SetLogy(); fHist->Draw(); fHist->Fit("gaus","q","",0.1,0.2);
// c1->cd(7)->SetLogy(); gHist->Draw(); gHist->Fit("gaus","q","",0.1,0.2);
// c1->cd(8)->SetLogy(); hHist->Draw(); hHist->Fit("gaus","q","",0.1,0.2);
// c1->cd(9)->SetLogy(); iHist->Draw(); iHist->Fit("gaus","q");
// c1->cd(10)->SetLogy(); jHist->Draw(); jHist->Fit("landau","q","",0.5,30);
// TF1 *landau = jHist->GetFunction("landau");
// c1->cd(11)->SetLogy(); kHist->Draw();
// c1->cd(12)/*->SetLogy()*/; lHist->Draw(); lHist->Fit("gaus","q");
// c1->cd(13)/*->SetLogy()*/; mHist->Draw(); /*mHist->Fit("gaus","q");*/
// c1->cd(14)->SetLogy(); nHist->Draw(); /*nHist->Fit("gaus","q"); */
// c1->cd(15)->SetLogy(); oHist->Draw(); /*oHist->Fit("gaus","q"); */

// For Pedestal Evaluation.
////c1->Divide(4,5,.007,.007);
//c1->Divide(4,4,.007,.007);
////c1->Divide(4,3,.007,.007);
//c1->cd(1)->SetLogy(); aHist->Draw(); aHist->Fit("gaus","q","",35,70);
//c1->cd(2)->SetLogy(); bHist->Draw(); bHist->Fit("gaus","q","",35,70);
//c1->cd(3)->SetLogy(); cHist->Draw(); cHist->Fit("gaus","q","",35,70);
//c1->cd(4)->SetLogy(); dHist->Draw(); dHist->Fit("gaus","q","",35,70);
//c1->cd(5)->SetLogy(); eHist->Draw(); eHist->Fit("gaus","q","",0.09,0.22);
//c1->cd(6)->SetLogy(); fHist->Draw(); fHist->Fit("gaus","q","",0.09,0.22);
//c1->cd(7)->SetLogy(); gHist->Draw(); gHist->Fit("gaus","q","",0.09,0.22);
//c1->cd(8)->SetLogy(); hHist->Draw(); hHist->Fit("gaus","q","",0.09,0.22);
//c1->cd(9)->SetLogy(); iHist->Draw(); iHist->Fit("gaus","q","",2,8);
//c1->cd(10)->SetLogy(); jHist->Draw(); jHist->Fit("gaus","q","",2,8);
//c1->cd(11)->SetLogy(); kHist->Draw(); kHist->Fit("gaus","q","",2,8);
//c1->cd(12)->SetLogy(); lHist->Draw(); lHist->Fit("gaus","q","",2,8);
//c1->cd(13)->SetLogy(); mHist->Draw(); mHist->Fit("gaus","q","",2,8);
//c1->cd(14)->SetLogy(); nHist->Draw(); nHist->Fit("gaus","q","",2,8);
//c1->cd(15)->SetLogy(); oHist->Draw(); oHist->Fit("gaus","q","",2,8);
//c1->cd(16)->SetLogy(); pHist->Draw(); pHist->Fit("gaus","q","",2,8);
////c1->cd(17)/*->SetLogy()*/; qHist->Draw();
////c1->cd(18)/*->SetLogy()*/; rHist->Draw(); /*rHist->Fit("gaus","q");*/
////c1->cd(19)/*->SetLogy()*/; sHist->Draw(); /*sHist->Fit("gaus","q");*/
////c1->cd(20)/*->SetLogy()*/; tHist->Draw(); /*tHist->Fit("gaus","q");*/

fclose(fout); /*c1->SaveAs("file.png");*/ c2->SaveAs("plot.png");}
