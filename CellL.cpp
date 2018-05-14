//==============================
//    INCLUDES
//==============================
#include "CellL.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
int CellL::count_L = 0;  //initialization of count to 0

//==============================
//    CONSTRUCTORS
//==============================

CellL::CellL(){
  
  count_L++;

  type='L';

  Raa=0.1;
  Rab=0.1;

}

CellL::CellL(float a, float b, float c){

  count_L++;
  
  type='L';

  A_int=a;
  B_int=b;
  C_int=c;

  //w=B_int;

  Raa=0.1;
  Rab=0.1;

}

//==============================
//    DESTRUCTOR
//==============================

CellL::~CellL(){
  count_L--;
}
//==============================
//    PUBLIC METHODS
//==============================

void CellL::Describe(){
	cout<< "Cette bactérie de type "<<type<<" présente une concentration interne en A: "<<A_int<<", en B: "<<B_int<<" et en C: "<<C_int<<endl;
}

/*Cell* CellL::Division(){

	A_int = A_int/2.0; //child get the half of their parents' concentration
	B_int = B_int/2.0;
	C_int = C_int/2.0;
  
	CellL* newcell = new CellL(A_int,B_int,C_int); //new L bacterie with new concentrations intra after division 
	return newcell;
}
*/


int CellL::Death(){return Cell::Death();}

char CellL::Gettype(){return Cell::Gettype();}

int CellL::Mute(){return Cell::Mute();}

float CellL::GetA_int(){return A_int;}

float CellL::GetB_int(){return B_int;}

float CellL::GetC_int(){return C_int;}

//float& CellL::Getw(){return w;}

int CellL::nb_L()
{
    return count_L;   // renvoie la valeur du count
}


float CellL::absorb(float c, float h){ // système qui régit le réseau métabolique des individus de type Ga

  float newa=c;
  float newbint=B_int;
  float newaint=A_int;

  newa+=h*(-Raa*c);
  newaint+=h*(Raa*c-Rab*A_int);
  newbint+=h*(Rab*A_int);

  B_int=newbint;
  A_int=newaint;
  
  return newa;
}
