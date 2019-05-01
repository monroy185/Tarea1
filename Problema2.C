
#include "TH1.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"




Double_t background(Double_t *x, Double_t *par) {
   return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}



Double_t lorentzianPeak(Double_t *x, Double_t *par) {
  return (x[0]*par[0]+par[1]);
}


Double_t fitFunction(Double_t *x, Double_t *par) {
  return background(x,par) + lorentzianPeak(x,&par[3]);
}

void FittingDemo() {


   const int nBins = 50;

   Double_t data[nBins] = { 315, 290,297,304,308,309,283,314,321,229,
                           247,295,285,293,254,258,279,270,255,261,
                           263,243,277,309,326,325,264,224,206,146,
                           161,149,130,145,127,138,124,113,118,94,
                           85,98,60,62,68,61,53,46,35,40};


   TH1F *histo = new TH1F("histo",
      "Lorentzian Peak on Quadratic Background",50,0,5);
   histo->SetMarkerStyle(21);
   histo->SetMarkerSize(1.2);
   histo->SetStats(0);


   for(int i=0; i < nBins;  i++) {
   histo->SetBinContent(i+1,data[i]);
   histo->SetBinError(i+1,TMath::Sqrt(data[i]));
   }


   TF1 *fitFcn = new TF1("fitFcn",fitFunction,0,5,6);
  
  
   fitFcn->SetParameters(330,-46,-4,-120,1200,1);
   histo->Fit("fitFcn","0");

  
   fitFcn->SetParameter(4,0.6);
   fitFcn->SetParameter(5,1);  

   histo->Fit("fitFcn","V+","ep");

  
   TF1 *backFcn = new TF1("backFcn",background,0,5,3);
   backFcn->SetLineColor(kRed);
   TF1 *signalFcn = new TF1("signalFcn",lorentzianPeak,0,5,3);
   signalFcn->SetLineColor(kBlue);
   signalFcn->SetNpx(500);
   Double_t par[6];

  
   fitFcn->GetParameters(par);

  
   signalFcn->SetParameters(&par[3]);
   signalFcn->Draw("same");




   TLegend *legend=new TLegend(0.6,0.65,0.88,0.85);
   legend->SetTextFont(72);
   legend->SetTextSize(0.04);
   legend->AddEntry(histo,"Data","lpe");
   legend->AddEntry(backFcn,"Background fit","l");
   legend->AddEntry(signalFcn,"Signal fit","l");


   legend->Draw();

}


