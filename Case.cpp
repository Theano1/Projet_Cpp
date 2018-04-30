
// ===========================================================================================
//                                        INCLUDES
// ===========================================================================================

#include <cstdio>
#include "Case.h"
#include "Environnement.h"


// ===========================================================================================
//                                       CONSTRUCTORS
// ===========================================================================================

Case::Case(int x, int y, float A){
  x_ = x;
  y_ = y;
  empty_ = false;
  Aout_ = A;
  Bout_ = 0.;
}

// ===========================================================================================
//                                       DESTRUCTORS
// ===========================================================================================




// ===========================================================================================
//                                         GETTERS
// ===========================================================================================

float Case::Aout(){
  return Aout_;
}


float Case::Bout(){
  return Bout_;
}



int Case::x(){
  return x_;
}


int Case::y(){
  return y_;
}



bool Case::empty(){
  return empty_;
}





// ===========================================================================================
//                                         SETTERS
// ===========================================================================================
