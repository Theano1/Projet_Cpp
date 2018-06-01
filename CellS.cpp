//
//  CellS.cpp
//  
//
//
//
#include "Cell.h"
#include "CellS.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;



//==============================
//    CONSTRUCTORS
//==============================

CellS::CellS():Cell(){
   type_ = 'S';
   Rbb_=0.1;
   Rbc_=0.1;
}





CellS::CellS(vector <float> org_int):Cell(){
  type_='S';
  org_int_.push_back(org_int[0]);
  org_int_.push_back(org_int[1]);
  org_int_.push_back(org_int[2]);
  Rbb_=0.1;
  Rbc_=0.1;
    
}


//==============================
//    DESTUCTORS
//==============================

CellS::~CellS() = default;

//==============================
//    PUBLIC METHODS
//==============================

vector <float> CellS::getorg_int(){
  return org_int_;
}



float CellS::absorb(float out){ // système qui régit le réseau métabolique des individus de type Ga
  cout << "using cellS absorb" << endl;
  float Bout = out;
  float Bin = org_int_[1];
  
  out = -Bout*Rbb_;
  org_int_[1] = Bout*Rbb_ - org_int_[1]*Rbc_;
  org_int_[2] = Bin*Rbc_;
  return out;
}


