//==============================
//    INCLUDES
//==============================
#include "CellL.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



//==============================
//    CONSTRUCTORS
//==============================

CellL::CellL(){
  type_='L';
  Raa_=0.1;
  Rab_=0.1;
}

CellL::CellL(vector <float> org_int){
  type_='L';
  org_int_={org_int[0],org_int[1],org_int[2]};
  Raa=0.1;
  Rab=0.1;
}



//==============================
//    PUBLIC METHODS
//==============================

vector <float> CellL::getorg_int(){
  return org_int_;
}



float CellL::absorb(float out){ // système qui régit le réseau métabolique des individus de type Ga
  float Aout = out;
  float Ain = org_int_[0];
  
  out = -Aout*Raa_;
  org_int_[0] = Aout*Raa_ - org_int_[0]*Rab_;
  org_int_[1] = Ain*Rab_;
  return out;
}



