
//CellL.h


#ifndef CELLL_H
#define CELLL_H
//==============================
//    INCLUDES
//==============================

#include "Cell.h"
#include <vector>
#include "CellS.h"
using namespace std;

class CellL: public Cell{
    
  public:
    //==============================
    //    CONSTRUCTORS
    //==============================
    CellL();
    CellL(vector <float> org_int);
    
    
    //==============================
    //    DESTRUCTORS
    //==============================
    virtual ~CellL();
    
    
    //==============================
    //    GETTERS
    //==============================
    vector <float> getorg_int();

    //==============================
    //    SETTERS
    //==============================
    
    //==============================
    //    OPERATORS
    //==============================
    
    //==============================
    //    PUBLIC METHODS
    //==============================
    
    virtual float absorb(float out);
    
    
    
  protected:
    //==============================
    //    PROTECTED METHODS
    //==============================
    
    //==============================
    //    ATTRIBUTES
    //==============================
    float Raa_;//  absorption rate
    float Rab_;// conversion rate
    
    
    //==============================
    //    GETTER DEFINITION
    //==============================
    
    
    //==============================
    //    SETTER DEFINITION
    //==============================
    
    //==============================
    //    OPERATOR DEFINITION
    //==============================
};

#endif // CellL

