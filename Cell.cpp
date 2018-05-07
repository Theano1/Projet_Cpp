//This is the implementation file Cell.cpp of the class Cell.

//==============================
//    INCLUDES
//==============================

#include <iostream>
using namespace std;
#include "Cell.h"

//==============================
//  DEFINITION STATIC ATTRIBUTES
//==============================
float Cell::rAA_ = 0;
float Cell::rAB_ = 0;
float Cell::rBB_ = 0;
float Cell::rBC_ = 0;
float Cell::min_fit_ = 0;

//==============================
//    CONSTRUCTORS
//==============================

Cell::Cell(){
    p_death=0.02;
    p_mutation=0.00;
    W_min=0.001;
    
    
    A_int=0;
    B_int=0;
    C_int=0;
}

//==============================
//    DESTRUCTOR
//==============================

Cell::Cell(){}

//==============================
//    PUBLIC METHODS
//==============================

//==============================
//    PROTECTED METHODS
//==============================
