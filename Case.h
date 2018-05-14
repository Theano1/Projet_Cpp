#ifndef CASE_H
#define CASE_H

// ===========================================================================================
//                                           INCLUDES
// ===========================================================================================

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Cell.h"


using namespace std;

class Case{

  public:
  
    // =========================================================================================
    //                                       CONSTRUCTORS
    // =========================================================================================

    Case(vector <float> org, char c);
    Case(float a, char c);
    Case();
  
    // =========================================================================================
    //                                        DESTRUCTORS
    // =========================================================================================
  
    ~Case();
  
  
    // =========================================================================================
    //                                          GETTERS
    // =========================================================================================
  
    vector <float> org_out();
    Cell* cell();
    float Pmut();

    
  
    // =========================================================================================
    //                                          SETTERS
    // =========================================================================================
    

    void set_cell(char c);
    void set_org_out(vector <float> org);
    
    
    
    // =========================================================================================
    //                                          METHODS
    // =========================================================================================
    
    
    void reset_case(float Ainit);
    float fitness();
    bool IsEmpty();
    char IsA();
    
    
  protected:
  
    // =========================================================================================
    //                                          ATTRIBUTS
    // =========================================================================================
    
    vector <float> org_out_;
    Cell* cell_;
    static float Wmin_;
    static float Pmut_;
};


#endif
