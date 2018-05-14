//
//  CellS.cpp
//  
//
//
//

#include "CellS.h"
#include <iostream>
using std::cout;
using std::endl;

//==============================
//  STATIC ATTRIBUTES DEFINITION
//==============================
int CellS::count_S = 0; //On initialise notre count à 0

//==============================
//    CONSTRUCTORS
//==============================

CellS::CellS(){
    
    count_S++;
    
    type='S';
    
    Rbb=0.1;
    Rbc=0.1;
    
}
CellS::CellS(float a, float b, float c){
    
    count_S++;
    
    type='S';
    
    A_int=a;
    B_int=b;
    C_int=c;
    //w=C_int;
    
    Rbb=0.1;
    Rbc=0.1;
    
}

//==============================
//    DESTRUCTOR
//==============================

CellS::~CellS(){
    count_S--;
}

//==============================
//    PUBLIC METHODS
//==============================

Cell* CellS::Division(){
    
    A_int = A_int/2.0; //les individus fils héritent de la moitié des concentrations internes du parent
    B_int = B_int/2.0;
    C_int = C_int/2.0;
    
    CellS* newcell = new CellS(A_int, B_int, C_int); //nouvelle bactérie de type B qui récupère les nouveaux attributs
    return newcell;
    
}

void CellS::Describe(){
    cout<< "Cette bactérie de type " <<type<<" présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl<<" ainsi qu'une fitness de "<<w<<endl;
    
}

int CellS::Death(){ return Cell::Death();}

char CellS::Gettype(){return Cell::Gettype();}

int CellS::Mute(){return Cell::Mute();}

float CellS::GetA_int(){return A_int;}

float CellS::GetB_int(){return B_int;}

float CellS::GetC_int(){return C_int;}

//float& CellS::Getw(){return w;}

int CellS::nb_S()
{
    return count_S;
}

float CellS::absorb(float c, float h){ //système qui régit le réseau métabolique des individus de type Gb
    
    float newb=c;
    float newbint=B_int;
    float newcint=C_int;
    
    newb+=h*(-Rbb*c);
    newbint+=h*(Rbb*c-Rbc*B_int);
    newcint+=h*(Rbc*B_int);
    
    B_int=newbint;
    C_int=newcint;
    
    return newb;
    
}


