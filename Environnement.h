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

    Environnement(int W, int H, float D, float Tfinal);
  
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
    float Tfinal();
    Case** gride();
  
//=====================================================================================================
//                                                    SETTERS
//=====================================================================================================


//=====================================================================================================
//                                                    METHODS
//==================================================================================================== 
  
    void diffusion();
    void competition();
    void filling_gride(float A);
    void reset_grid(float A);
    int state();
    void division(Case* c1, Case* c2);
    void death();
    int run(float Ainit, int t);
    void metabolism();

  protected:

//=====================================================================================================
//                                                    ATTRIBUTS
//=====================================================================================================
  
    int nb_S_;
    int nb_L_;
    int W_;
    int H_;
    float D_;
    float Tfinal_;
    static float Pdeath_;
    Case** gride_;
    

};





#endif
