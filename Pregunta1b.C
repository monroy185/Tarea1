#include "TH1.h"
#include "TTree.h"

void Pregunta1b(){

TTree *T1 = new TTree("T1","data");
Long64_t n1 = T1->ReadFile("NuAstro_4yr_IceCube_Data.txt","ID:DepEnergy:Errmin:Errmax:Time:Declination:RAdeg:MedAngResdeg:Topology");

T1->SetMarkerStyle(6);
T1->SetMarkerSize(6);

T1->Draw("RAdeg:ID");

}
