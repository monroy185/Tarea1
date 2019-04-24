#include "TH1.h"
#include "TTree.h"

void Pregunta1aShower(){

TTree *T = new TTree("T","data");
Long64_t nlines = T->ReadFile("NuAstro_4yr_IceCube_Data.txt","ID:DepEnergy:Errmin:Errmax:Time:Declination:RAdeg:MedAngResdeg:Topology");
TH1F *h1 = new TH1F("h1","x",1,-100,100);

T->Draw("MedAngResdeg","Topology==1");
}
