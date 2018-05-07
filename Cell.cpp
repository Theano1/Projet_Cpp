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
float Cell::p_death =0.02; // death probability (=0.02)
float Cell::p_mutation=0; // mutation probability (0)
float Cell::W_min=0.001; // minimum fitness (=0.001)

//==============================
//    CONSTRUCTORS
//==============================

Cell::Cell(){
    A_int=0;
    B_int=0;
    C_int=0;
}

//==============================
//    DESTRUCTOR
//==============================

Cell::~Cell(){}

//==============================
//    PUBLIC METHODS
//==============================

//==============================
//    GETTERS
//==============================

char Cell::Gettype(){
    return type;
}

float Cell::GetA_int() {
    return A_int;
}

float Cell::GetB_int() {
    return B_int;
}

float Cell::GetC_int() {
    return C_int;
}

//==============================
//    PROTECTED METHODS
//==============================
