#include <cstdio>
#include "Environnement.h"


//=====================================================================================================
//                                                    CONSTRUCTOR
//=====================================================================================================

Environnement::Environnement(int W, int H, float D, int T, float Ainit, float Tfinal){ 
  W_=W;
  H_=H;
  D_=D;
  T_=T;
  Ainit_=Ainit;
  Tfinal_=Tfinal;  
}

//=====================================================================================================
//                                                    DESTRUCTOR
//=====================================================================================================

Environnement::~Environnement()=default;

//=====================================================================================================
//                                                    GETTERS
//=====================================================================================================

int Environnement::nb_S_init() {
  return nb_S_init_;
}

int Environnement::nb_L_init() {
  return nb_L_init_;
}

int Environnement::W() {
  return W_;
}

int Environnement::H() {
  return H_;
}

int Environnement::T() {
  return T_;
}

float Environnement::Ainit() {
return Ainit_;
}

float Environnement::Tfinal() {
return Tfinal_;
}
  

//=====================================================================================================
//                                                    METHODS
//==================================================================================================== 
  
void Environnement::diffusion(){

}


void Environnement::competition(){

}
   
   
   
   
   
   
   
