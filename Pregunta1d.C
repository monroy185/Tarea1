#include "TTree.h"

void Pregunta1d(){

TTree *T1 = new TTree("T1","data");
Long64_t n1 = T1->ReadFile("NuAstro_4yr_IceCube_Data.txt","ID:DepEnergy:Errmin:Errmax:Time:Declination:RAdeg:MedAngResdeg:Topology");
T1->SetMarkerStyle(6);
T1->SetMarkerSize(4);
T1->Scan("DepEnergy:ID","Topology==1");
T3->Add(T1);

TTree *T2 = new TTree("T1","data");
Long64_t n2 = T2->ReadFile("NuAstro_4yr_IceCube_Data.txt","ID:DepEnergy:Errmin:Errmax:Time:Declination:RAdeg:MedAngResdeg:Topology");
T2->SetMarkerStyle(5);
T2->SetMarkerSize(3);
T2->Scan("DepEnergy:ID","Topology==2");
T3->Add(T2);

T3->Draw();
.
}
