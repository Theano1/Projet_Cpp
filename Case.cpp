
// ===========================================================================================
//                                        INCLUDES
// ===========================================================================================

#include <cstdio>
#include "Case.h"
#include <vector>
#include "Environnement.h"
#include "Cell.h"


// ===========================================================================================
//                             Definition of static attributes
// ===========================================================================================

float Case::Wmin_ = 0.001;
float Case::Pmut_ = 0.0;
// ===========================================================================================
//                                       CONSTRUCTORS
// ===========================================================================================

//constructeur qui prend en paramètres les organites externes et le type de la cellule

Case::Case(vector <float> org, char c){
  org_out_ = {org[0],org[1],org[2]};
  cell_ = new Cell(c);
  
}

//constructeur qui prend en parametre la quantité initiale de glucose et le type de la cellule

Case::Case(float a, char c){
  org_out_ = {a,.0,.0};
  cell_ = new Cell(c);
  
}

Case::Case(){
  org_org_ = {.0, .0, .0};
  cell_ = nullptr;
}


// ===========================================================================================
//                                       DESTRUCTORS
// ===========================================================================================


Case::~Case(){
  delete[] cell_;  
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


void Case::set_cell(char c){
  delete[] cell_;  
  cell_ = new Cell(c); 
}


void Case::set_org_out(vector <float> org){
  org_out_ = {org[0], org[1], org[2]};
}


// =========================================================================================
//                                          METHODS
// =========================================================================================
    
// remet a 0 les molécules externes
void Case::reset_case(float Ainit){
  vector <float> org_out = {Ainit, .0, .0};
  org_out_ = org_out;
}


   
//fonction qui permet de déterminer la fitness d'une cellule
float Case::fitness(){
  float w;
  if (this -> cell() -> type() == 'L'){
    w = org_out_[1];
  }
  else if (this -> cell() -> type() == 'S'){
    w = org_out_[2];
  }
  if (w < Wmin_){
    w = 0;
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
  if (this -> cell() -> type() == 'L'){
    return 'L';
  else if (this -> cell() -> type() == 'S'){
    return 'S';
}


//fonction de divison: la case c recoit la cellule fille de la case sur laquelle on applique le méthode
void Case::divison(Case* c){
  char t;
  //first we determine the mother's type
  if (this -> gettype() == 'L'){
    t = 'L';
  }
  
  if (this -> gettype() == 'S'){
    t = 'S';
  }
  
  
  
  //this is for the cell in the box
  double rand1 = (double) rand()/RAND_MAX;
  if ( rand1 <= Pmut_){
    delete[] cell_;  
    if (t == 'L'){
      cell_ = new Cell(S);
    }
    else {
      cell_ = new Cell(L);
    } 
  }
  
  //this is for the new cell that is going in the empty box
  double rand2 = (double) rand()/RAND_MAX;
  if ( rand2 <= c -> Pmut()){
    if (t == 'L'){
      c -> cell_ = new Cell(S);
    }
    else {
      c -> cell_ = new Cell(L);
    } 
  }
  
  //distribution of the molecules to the dauthers
  org_out_ = {org_out_[0]/2, org_out_[1]/2, org_out_[2]/2};
  c -> org_out() = {org_out_[0]/2, org_out_[1]/2, org_out_[2]/2};  

}



