
//CellL.h


#ifndef CellL
#define CellL
//==============================
//    INCLUDES
//==============================

#include "Cell.h"

class CellL: public Cell{
    
public:
    //==============================
    //    CONSTRUCTORS
    //==============================
    CellL();
    CellL(vector <float> org_int);
    
    
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

