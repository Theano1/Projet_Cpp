//
//  CellS.h
//
//

#ifndef CELLS_H
#define CELLS_H

//==============================
//    INCLUDES
//==============================

#include "Cell.h"
#include <vector>
#include "CellL.h"
using namespace std;

class CellS: public Cell{
  public:
    //==============================
    //    CONSTRUCTORS
    //==============================
    CellS();
    CellS(vector <float> org_int);
    
    //==============================
    //    DESTRUCTORS
    //==============================
    virtual ~CellS();
    
    
    
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
    float Rbb_; //absorption rate
    float Rbc_; //conversion rate
};

#endif /* CellS_h */
