#ifndef CASE_H
#define CASE_H

// ===========================================================================================
//                                           INCLUDES
// ===========================================================================================

#include <cstdio>
#include <cstdlib>


class Case{

  public:
  
    // =========================================================================================
    //                                       CONSTRUCTORS
    // =========================================================================================
    Case(int x, int y, float A);
  
    // =========================================================================================
    //                                        DESTRUCTORS
    // =========================================================================================
  
    ~Case();
  
  
    // =========================================================================================
    //                                          GETTERS
    // =========================================================================================
  
    float Aout();
    float Bout();
    int x();
    int y();
    bool empty();
    
  
    // =========================================================================================
    //                                          SETTERS
    // =========================================================================================
    
    void set_empty(bool empt);
    void set_Aout(float c);
    void set_Bout(float c);
    
    
    
  protected:
  
    // =========================================================================================
    //                                          ATTRIBUTS
    // =========================================================================================
    
    float Aout_;
    float Bout_;
    int x_;
    int y_;
    bool empty_;
  
};


#endif
