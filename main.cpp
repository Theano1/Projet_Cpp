#include "Environnement.h"
#include <iostream>
#include <cstdio>
#include "Cell.h"
#include "CellS.h"
#include "CellL.h"
#include "Case.h"
#include "Environnement.h"
using namespace std;


int main() {

  //--------------------TEST Environnemernt------------------------

  Environnement* env = new Environnement(4,4,0.1,50);
  cout<< env->run(3,10)<<endl;
  
  
  return 0;
}

