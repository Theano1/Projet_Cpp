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
// Every static variable must be initialized outside the class definition. Also, a static variable cannot be initialized more than once.

//==============================
static float p_death; // death probability (=0.02)
static float p_mutation; // mutation probability (0)
static float W_min; // minimum fitness (=0.001)

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

Cell::~Cell(){}

//==============================
//    PUBLIC METHODS
//==============================

char Bacterie::Gettype(){
    return type;
}


//==============================
//    PROTECTED METHODS
//==============================
