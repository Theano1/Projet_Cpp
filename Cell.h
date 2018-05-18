//This is the header file Cell.h.


#ifndef CELL_H
#define CELL_H


#include <vector>
using namespace std;

class Cell{

    public:
    //==============================
    //    CONSTRUCTORS
    //==============================

    Cell();
    Cell(char c, vector <float> org);
    Cell(char c);

    //==============================
    //    DESTRUCTORS
    //==============================
    virtual ~Cell();

    
    //==============================
    //    GETTERS
    //==============================
    //They are virtual functions because they may, in a sense, be used before they are defined.
    
    char Gettype();
    
    
    //==============================
    //    SETTERS
    //==============================
    
    //==============================
    //    PUBLIC METHODS
    //==============================
    //
    
    vector <float> division_org();
    vector <float> getorg_int();

    
    
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

