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
//float Cell::p_death =0.02; // death probability (=0.02)
//float Cell::p_mutation=0; // mutation probability (0)
//float Cell::W_min=0.001; // minimum fitness (=0.001)

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
/*
int Cell::Death(){
    
    float nb =  (rand()%(1000))/1000.0;  //random number between 0 et 1
    
    if(nb<p_death){ // if nb is less than p_death
        
        return 0; // The cell die
        
    }
    
    else{ //if nb is more than p_death
        
        return 1;// The cell live
        
    }
}

int Cell::Mute(){
    
    
    float nb =  (rand()%(1000))/1000.0; //random number between 0 et 1
    
    if (nb<p_mutation){ // if nb is less than p_mutation
        
        return 0; // The cell mute
    }
    
    else{ // if nb is more than p_mutation
        
        return 1; //The cell doesn't mute
    }
    
}
*/

//==============================
//    GETTERS
//==============================

char Cell::Gettype(){
    return type;
}

//==============================
//    PROTECTED METHODS
//==============================
