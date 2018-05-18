#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

//=====================================================================================================
//                                                    INCLUDES
//=====================================================================================================


#include "Case.h"
#include <string>
#include <vector>
#include "CellL.h"
#include "CellS.h"

using namespace std;
class Environnement{

  public:
  
//=====================================================================================================
//                                                    CONSCTRUCTORS
//=====================================================================================================

    Environnement(int W, int H, float D, int T, float Ainit, float Tfinal);
  
//=====================================================================================================
//                                                    DESTRUCTOR
//=====================================================================================================

    ~Environnement();
  
//=====================================================================================================
//                                                    GETTERS
//=====================================================================================================
    int nb_S_init();
    int nb_L_init();
    int W();
    int H();
    int T();
    float Ainit();
    float Tfinal();
    
  
//=====================================================================================================
//                                                    SETTERS
//=====================================================================================================


//=====================================================================================================
//                                                    METHODS
//==================================================================================================== 
  
    void diffusion();
    void competition();
    void filling_gride(Case* gride);
    void reset_grid();
    string state();
    void division(Case* c1, Case* c2);


  protected:

//=====================================================================================================
//                                                    ATTRIBUTS
//=====================================================================================================
  
    int nb_S_;
    int nb_L_;
    int W_;
    int H_;
    int T_;
    float D_;
    float Ainit_;
    float Tfinal_;
    Case** gride_;
    

};





#endif
