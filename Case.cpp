
// ===========================================================================================
//                                        INCLUDES
// ===========================================================================================

#include <cstdio>
#include "Case.h"
#include <vector>
#include "Environnement.h"
#include "Cell.h"
#include "CellL.h"
#include "CellS.h"

// ===========================================================================================
//                             Definition of static attributes
// ===========================================================================================

float Case::Wmin_ = 0.001;
float Case::Pmut_ = 0.0;
// ===========================================================================================
//                                       CONSTRUCTORS
// ===========================================================================================

//constructor that takes the external organelles and the type of the cell in parameters

Case::Case(vector <float> org, char c){
  org_out_.push_back(org[0]);
  org_out_.push_back(org[1]);
  org_out_.push_back(org[2]);
  cell_ = nullptr;
  if (c == 'L'){
    cell_ = new CellL();
  }
  else if (c == 'S'){
    cell_ = new CellS();
  } else {
    cerr << "Error wrong cell type asked: " << c << endl;
    exit(EXIT_FAILURE);
  }
}

//constructeur qui prend en parametre la quantité initiale de glucose et le type de la cellule

Case::Case(float a, char c){
  org_out_.push_back(a);
  org_out_.push_back(.0);
  org_out_.push_back(.0);
  cell_ = nullptr;
  
  if (c == 'L'){
    cell_ = new CellL();
  }
  else if (c == 'S'){
    cell_ = new CellS();
  } else {
    cerr << "Error wrong cell type asked: " << c << endl;
    exit(EXIT_FAILURE);
  }
}

Case::Case(){
  org_out_.push_back(.0);
  org_out_.push_back(.0);
  org_out_.push_back(.0);
  cell_ = nullptr;
}


// ===========================================================================================
//                                       DESTRUCTORS
// ===========================================================================================


Case::~Case(){
  if (cell_ != nullptr){
    delete cell_;
  }
}

// ===========================================================================================
//                                         GETTERS
// ===========================================================================================


vector <float> Case::org_out(){
  return org_out_;
}

Cell* Case::cell(){
  return cell_;
}


float Case::Pmut(){
  return Pmut_;
}


// ===========================================================================================
//                                         SETTERS
// ===========================================================================================


void Case::set_cell(char c, vector <float> org){
  if (cell_ != nullptr){
    delete cell_;
  }
  
  //cout << cell_ << endl;
  if (c == 'L'){
    cell_ = new CellL(org);
  }
  else if (c == 'S'){
    //cout << "je rentre dans set_cell car je suis un S" << endl;
    cell_ = new CellS(org);
  } 
  else {
    cerr << c << " is an inccorect cell type." << endl;
  }
}


void Case::set_cell(char c){
  if (cell_ != nullptr){
    delete cell_;
  }
  
  if (c == 'L'){
    cell_ = new CellL();
  }
  else if (c == 'S'){
    cell_ = new CellS();
  } 
  else {
     cout << "probleme dans set_cell" << endl;
  }
}


void Case::set_org_out(vector <float> org){
  org_out_[0] = org[0];
  org_out_[1] = org[1];
  org_out_[2] = org[2];

}


// =========================================================================================
//                                          METHODS
// =========================================================================================
    
// remet a 0 les molécules externes
void Case::reset_case(float Ainit){
  org_out_[0] = Ainit;
  org_out_[1] = .0;
  org_out_[2] = .0;
}


   
//fonction qui permet de déterminer la fitness d'une cellule
float Case::fitness(){
  float w;
  if (cell_ == nullptr){
    return 99.9;
  }
  
  if (cell_ -> Gettype() == 'L'){
    w = org_out_[1];
  }
  else {
    w = org_out_[2];
  }
  if (w < Wmin_){
    w = 0.;
  }
  return w;
}


//fonction qui determine si une case est vide ou pas
bool Case::IsEmpty(){
  if (cell_ == nullptr){
    return true;
  }
  else{
    return false;
  }
}


//fonction qui renvoit le type de cellule qui est dans la case
char Case::IsA(){
  if (this -> cell() -> Gettype() == 'L'){
    return 'L';
  }
  else if (this -> cell() -> Gettype() == 'S'){
    return 'S';
  }
  else {
    return 'Z';
  }
}

void Case::death(){
  cell_ = nullptr;
  delete cell_;
}




