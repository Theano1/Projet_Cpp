//
//  CellS.cpp
//  
//
//
//

#include "CellS.h"
#include <iostream>
using namespace std;



//==============================
//    CONSTRUCTORS
//==============================

CellS::CellS(){
   type_ = 'S';
   Rbb=0.1;
   Rbc=0.1;
}



CellS::CellS(vector <float> org_int){
  type_='S';
  org_int_={org_int[0],org_int[1],org_int[2]};
  Rbb=0.1;
  Rbc=0.1;
    
}


//==============================
//    PUBLIC METHODS
//==============================

vector <float> CellS::getorg_int(){
  return org_int_;
}



float CellS::absorb(float out){ // système qui régit le réseau métabolique des individus de type Ga
  float Bout = out;
  float Bin = org_int_[1];
  
  out = -Bout*Rbb_;
  org_int_[1] = Bout*Rbb_ - org_int_[1]*Rbc_;
  org_int_[2] = Bin*Rbc_;
  return out;
}


