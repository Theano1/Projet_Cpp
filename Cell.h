//This is the header file Cell.h.


#ifndef CELL_H
#define CELL_H


#include <iostream>
#include <vector>
using namespace std;

class Cell{

    public:
    //==============================
    //    CONSTRUCTORS
    //==============================

    Cell();

    
    //==============================
    //    GETTERS
    //==============================
    //They are virtual functions because they may, in a sense, be used before they are defined.
    
    virtual char Gettype();
    
    
    //fonction virtuelles pures : dans la classe Cell, ces fonction n'existe pas mais dans toutes les classes filles de Cell (Cell S et Cell L), il y a ces fonctions nommées GetA_int(), GetB_int()... qui renvoient un float mais ne prennent aucun argument
    virtual float GetA_int()=0;
    virtual float GetB_int()=0;
    virtual float GetC_int()=0;
    virtual float& Getw()=0;
    
    //==============================
    //    SETTERS
    //==============================
    
    //==============================
    //    PUBLIC METHODS
    //==============================
    //
    
    virtual void Describe()=0; //Describe Cell : cette méthode est virtuelle pure
    vector <float> division_org();
    

    
    
    protected:
    //==============================
    //    PROTECTED METHODS
    //==============================
    

    //==============================
    //    ATTRIBUTES
    //==============================

    // Concentration of metabolites inside the Cell
    vector <float> org_int_;
    char type_; // Cell type (L or S)


    


};

#endif // CELL_H

