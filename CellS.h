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
    CellS(float a, float b, float c);
    
    
    //==============================
    //    DESTRUCTOR
    //==============================
    virtual ~CellS();
    
    //==============================
    //    GETTERS
    //==============================
    virtual float GetA_int();
    virtual float GetB_int();
    virtual float GetC_int();
    virtual char Gettype();
    virtual float& Getw();
    
    
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
    virtual Cell* Division();
    virtual int Death();
    virtual int Mute();
    static int nombre_S();
    virtual float absorb(float c, float h);
    
    
protected:
    //==============================
    //    PROTECTED METHODS
    //==============================
    
    //==============================
    //    ATTRIBUTES
    //==============================
    float Rbb; //taux d'absorption
    float Rbc; //taux de conversion
    float& w=C_int; //fitness
    static int compteur_S; //nombre de bactérie CellS
    




#endif /* CellS_h */
