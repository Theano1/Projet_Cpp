#include <cstdio>
#include <iostream>
#include "Environnement.h"
#include "Case.h"
#include <vector>
#include <string>

using namespace std;

//====================================================================================================
//                                                    CONSTRUCTOR
//====================================================================================================

Environnement::Environnement(int W, int H, float D, int T, float Ainit, float Tfinal){ 
  W_=W;
  H_=H;
  D_=D;
  T_=T;
  Ainit_=Ainit;
  Tfinal_=Tfinal;
  int nb_S_= (W_*H_)/2;
  int nb_L_= (W_*H_)/2;
  
  
  //gride_ creation
  gride_ = new Case* [H_];
  for (int i=0; i<H_; ++i){
    gride_[i]= new Case [W_];
  }
      
   
}

//====================================================================================================
//                                                    DESTRUCTOR
//====================================================================================================

Environnement::~Environnement(){
  for(int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++j){
      delete[] &gride_[i][j];
    }
  }
}

//====================================================================================================
//                                                    GETTERS
//====================================================================================================



//====================================================================================================
//                                                    METHODS
//===================================================================================================
   
void Environnement::diffusion(){
  int x=0;
  int y=0;
  int k;
  int l;
  for (int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++i){
      float a=gride_[i][j].org_out()[0];
      float b=gride_[i][j].org_out()[1];
      float c=gride_[i][j].org_out()[2];
      for (int k=-1;k<2; ++k){
        for (int l=-1; l<2; ++k){
          if (k!=0 and l!=0){
              
              //Thor formation
            if(i+k>H_-1){
              x=0;
            }
            else if(i+k<0){
              x=H_-1;
            }
            else{
              x=i+k;
            }
            if (j+l>W_-1){
              y=0;
            }
            else if(j+l<0){
              y=W_-1;
            }
            else{
              y=j+l;       
            }  
            
            a=a+D_*gride_[x+k][y+l].org_out()[0];
            b=b+D_*gride_[x+k][y+l].org_out()[1];
            c=c+D_*gride_[x+k][y+l].org_out()[2];      
            
                             
          }       
        }
      }
      a=a-9*D_*gride_[x+k][y+l].org_out()[0];
      b=b-9*D_*gride_[x+k][y+l].org_out()[1];
      c=c-9*D_*gride_[x+k][y+l].org_out()[2];
       
    }
  }
}


/*
void Environnement::competition(){
  vector<int> length;
  vector<int> width;
  for (int k = 0; k < 10; ++k){
    length.push_back(k);
    width.push_back(k);
  }
  
  random_shuffle(length.begin(),longeur.end());
  random_shuffle(width.begin(),largeur.end());


  for (vector<int>::iterator i = length.begin() ; i != length.end(); ++i){
    for (vector<int>::iterator j = witdh.begin() ; j != width.end(); ++j){
      if (gride_[i][j].IsEmpty == false){
        for (int k=-1;k<2, ++k){
          for (int l=-1; l<2, ++k){
            if (k!=0 and l!=0){
              int x=0;
              int y=0;
              
              //Thor formation
              if(i+k>H_-1){
                x=0;
              }
              else if(i+k<0){
                x=H_-1;
              }
              else{
                x=i+k;
              }
              if (j+l>W_-1){
                y=0;
              }
              else if(j+l<0){
                y=W_-1;
              }
              else{
                y=j+l;
              }               
              if (gride_[i][j].IsEmpty== true){
                int fit=gride_[i][j].fitness()
                for (int k=-1;k<2; ++k);{
                  for (int l=-1; l<2; ++k){
                    if (fit<grille[k+i][l+j].fitness()){
                      fit = grille[k+i][l+j].fitness();
                      x=k+i;
                      y=l+j;
                    }
                  }
                }
                gride_[x][y].division(*gride_[i][j]);
                           
              }
            }
          }
        }
      }    
    }
  }
}
 
      

   
//Filling the gride_

void Environnement::filling_gride_(Case* gride_){
  vector<char> vec((H_*W_)/2, 'L');
  vector<char> vec1((H_*W_)/2,'S');
  vec.insert(vec.end(),vec1.begin(), vec1.end());
  random_shuffle(vec.begin(), vec.end());
  int count=0;
  for (int i=0; i<H_; ++i){
    for (int j=0; j<W; ++i){
        gride_[i][j]= Case(A_init, vec[count]) ; 
        count += 1;
      }
    }
  
}
   


//Reset the environment
void Environnement::reset_grid(){
  for(int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++j){      
      gride_[i][j].reset_case(Ainit_);
    }
  }
}
  

string Environnement::state(){
  if (nb_S_ ==0 and nb_L_ ==0){
    return "Extinction";
  }
  else if (nb_S_ ==0 and nb_L_ !=0){
    return "Exclusion";
  }
  else{
    return "Cohabitation";
  }
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
    cell_ = delete;
    if (t == 'L'){
      cell_ = new Cell(S);
      nb_L_ -=1;
      nb_S_ +1;
    }
    else {
      cell_ = new Cell(L);
      nb_S_ -= 1;
      nb_L_ += 1;
    } 
  }
  
  //this is for the new cell that is going in the empty box
  double rand2 = (double) rand()/RAND_MAX;
  if ( rand2 <= c -> Pmut()){
    if (t == 'L'){
      c -> cell_ = new Cell(S);
      nb_S_ +=1;
    }
    else {
      c -> cell_ = new Cell(L);
      nb_L_ +=1;
    } 
  }
  
  //distribution of the molecules to the dauthers
  org_out_ = {org_out_[0]/2, org_out_[1]/2, org_out_[2]/2};
  c -> org_out() = {org_out_[0]/2, org_out_[1]/2, org_out_[2]/2};  

}
  
  */




   
   
