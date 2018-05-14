//This is the header file Cell.h.


#ifndef CELL_H
#define CELL_H


#include <iostream>
using namespace std;

class Cell
{
    public:
    //==============================
    //    CONSTRUCTORS
    //==============================

    Cell();
    Cell(float a, float b, float c);
    
    //==============================
    //    DESTRUCTOR
    //==============================
    
    virtual ~Cell();
    
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
    int Death(); // return 1 if the Cell live and 0 if the Cell die with a probability p_death
    int Mute(); // return 1 (cell doesn't mute) or 0 (cell mute) with probability p_mutation
    virtual Cell* Division()=0; // divide concentrations of the cell by 2 ; return a pointer on the same cell

    
    
    protected:
    //==============================
    //    PROTECTED METHODS
    //==============================
    
    //==============================
    // DECLARATION STATIC ATTRIBUTES
    //==============================

    static float p_death; // death probability (=0.02)
    static float p_mutation; // mutation probability (0)
    static float W_min; // minimum fitness (=0.001)
    
    //==============================
    //    ATTRIBUTES
    //==============================

    // Concentration of metabolites inside the Cell
    float A_int;
    float B_int;
    float C_int;
    char type; // Cell type (L or S)


    


};

#endif // CELL_H

