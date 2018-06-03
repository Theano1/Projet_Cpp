
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

  Environnement* env = new Environnement(32,32,0.1,5000);
  for (float i=0; i<51; i += 10){
   for (int j=0; j<1501; j +=50){
    cout<< env->run(i,j)<<endl;
    }
  }
  
  
  delete env;
  
  
  return 0;
}
