//This is the implementation file Cell.cpp of the class Cell.

//==============================
//    INCLUDES
//==============================

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Cell.h"
#include "CellS.h"
#include "CellL.h"


//==============================
//  DEFINITION STATIC ATTRIBUTES : Those variables are shared by all the objects of class Cell.
// static variables are indicated by the qualifying keyword static at the start of their declaration. All the static variables are initialized as follows: int Server::turn = 0;
// Every static variable must be initialized outside the class definition. Also, a static variable cannot be initialized more than once


//==============================
//    CONSTRUCTORS
//==============================

Cell::Cell(){
    type_ = '0'; 
    org_int_.push_back(.0);
    org_int_.push_back(.0);
    org_int_.push_back(.0);
}

/*
Cell::Cell(char c, vector <float> org){
    if (c == 'L'){
      new CellL(org);
    }
    else if (c == 'S'){
      new CellS(org);
    }
}



Cell::Cell(char c){
    if (c == 'L'){
      new CellL();
    }
    else if (c == 'S'){
      new CellS();
    }
}
*/
//==============================
//    DESTUCTORS
//==============================

Cell::~Cell() = default;


//==============================
//    PUBLIC METHODS
//==============================

vector <float> Cell::division_org(){
  //cout << "je suis dans division_org" << endl;
  org_int_[0] =org_int_[0]/2;
  org_int_[1] =org_int_[1]/2;
  org_int_[2] =org_int_[2]/2;
  return org_int_;
}

/*
float Cell::absorb(float out){
  return 0.0;
}
*/

//==============================
//    GETTERS
//==============================

char Cell::Gettype(){
    return type_;
}


vector <float> Cell::getorg_int(){
  return org_int_;
}

//==============================
//    PROTECTED METHODS
//==============================
