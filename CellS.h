//
//  CellS.h
//
//

#ifndef CellS_h
#define CellS_h

//==============================
//    INCLUDES
//==============================

#include "Cell.h"

class CellS: public Cell
{
public:
    //==============================
    //    CONSTRUCTORS
    //==============================
    CellS();
    CellS(vector <float> org_int);
    
    
    
    //==============================
    //    GETTERS
    //==============================
    vector <float> getorg_int();
    virtual char Gettype();
    
    
    //==============================
    //    SETTERS
    //==============================
    
    //==============================
    //    OPERATORS
    //==============================
    
    //==============================
    //    PUBLIC METHODS
    //==============================
    
    virtual void Describe();
    virtual float absorb(float out);
    
    
protected:
    //==============================
    //    PROTECTED METHODS
    //==============================
    
    //==============================
    //    ATTRIBUTES
    //==============================
    float Rbb; //absorption rate
    float Rbc; //conversion rate


#endif /* CellS_h */
