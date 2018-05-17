//This is the implementation file Cell.cpp of the class Cell.

//==============================
//    INCLUDES
//==============================

#include <iostream>
using namespace std;
#include "Cell.h"

//==============================
//  DEFINITION STATIC ATTRIBUTES : Those variables are shared by all the objects of class Cell.
// static variables are indicated by the qualifying keyword static at the start of their declaration. All the static variables are initialized as follows: int Server::turn = 0;
// Every static variable must be initialized outside the class definition. Also, a static variable cannot be initialized more than once


//==============================
//    CONSTRUCTORS
//==============================

Cell::Cell(){
    org_int_ = {.0, .0, .0};
}


//==============================
//    PUBLIC METHODS
//==============================

vector <float> Cell::divison_org(){
  org_int_={org_int_[0]/2,org_int_[1]/2,org_int_[2]/2};
  return org_int_;
}


//==============================
//    GETTERS
//==============================

char Cell::Gettype(){
    return type_;
}

//==============================
//    PROTECTED METHODS
//==============================
