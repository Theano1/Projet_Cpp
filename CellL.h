
//CellL.h


#ifndef CELLL_H
#define CELLL_H
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
    CellL(float a, float b, float c);
    
    //==============================
    //    DESTRUCTOR
    //==============================
    virtual ~CellL();
    
    //==============================
    //    GETTERS
    //==============================
    virtual float GetA_int();
    virtual float GetB_int();
    virtual float GetC_int();
    virtual char Gettype();
    static int nb_L();
    //virtual float& Getw();
    
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
<<<<<<< HEAD
    //virtual int Death();
    virtual Cell* Division();
    //virtual int Mute();

=======
    virtual int Death();
    //virtual Cell* Division();
    virtual int Mute();
    static int nb_L();
>>>>>>> f517e84561de77002c3fcb7ef03550f7ccc428b3
    virtual float absorb(float c, float h);
    
    
    
protected:
    //==============================
    //    PROTECTED METHODS
    //==============================
    
    //==============================
    //    ATTRIBUTES
    //==============================
    float Raa;//  absorption rate
    float Rab;// conversion rate
    //float& w=B_int;//fitness
    static int count_L;////nb of CellL
    
    
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

#endif // CELLL_H

