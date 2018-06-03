
#include "Environnement.h"
#include <iostream>
#include <cstdio>
#include "Cell.h"
#include "CellS.h"
#include "CellL.h"
#include "Case.h"

using namespace std;


int main() {

  //--------------------TEST Environnemernt------------------------

  Environnement* env = new Environnement(6,6,0.1,50);
  for (float i=1; i<51; ++i){
   for (int j=1; j<51; ++j){
    cout<< env->run(i,j)<<endl;
  }
  }
  
  
  delete env;
  
  
  return 0;
}
