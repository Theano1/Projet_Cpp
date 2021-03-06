#include "Environnement.h"
#include "Case.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include "Cell.h"
#include "CellL.h"
#include "CellS.h"

//using namespace std;



// ===========================================================================================
//                             Definition of static attributes
// ===========================================================================================

float Environnement::Pdeath_ = 0.02;


//====================================================================================================
//                                                    CONSTRUCTOR
//====================================================================================================

Environnement::Environnement(int W, int H, float D, float Tfinal){ 
  W_=W;
  H_=H;
  D_=D;
  Tfinal_=Tfinal;
  nb_S_= (W_*H_)/2;
  nb_L_= (W_*H_)/2;
  
  
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
    if (gride_[i]!= nullptr){
      delete[] gride_[i];  
    }
  }
  delete[] gride_;
}

//====================================================================================================
//                                                    GETTERS
//====================================================================================================

int Environnement::H(){
  return H_;
}


int Environnement::W(){
  return W_;
}


Case** Environnement::gride(){
  return gride_;
}


//====================================================================================================
//                                                    METHODS
//===================================================================================================
 
void Environnement::diffusion(){
  int x=0;
  int y=0;
  for (int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++j){
      float a=gride_[i][j].org_out()[0];
      float b=gride_[i][j].org_out()[1];
      float c=gride_[i][j].org_out()[2];
      for (int k=-1;k<2; ++k){
        for (int l=-1; l<2; ++l){
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
            
            a=a+D_*gride_[x][y].org_out()[0];
            b=b+D_*gride_[x][y].org_out()[1];
            c=c+D_*gride_[x][y].org_out()[2];      
            
                             
          }       
        }
      }
      
      if (9*D_*gride_[i][j].org_out()[0] > a){
        a = 0;
      }
      else {
        a=a-9*D_*gride_[i][j].org_out()[0];
      }
      
      if (9*D_*gride_[i][j].org_out()[1] > b){
        b = 0;
      }
      else {
        b=b-9*D_*gride_[i][j].org_out()[1];
      }
      
      if (9*D_*gride_[i][j].org_out()[2] > c){
        c = 0;
      }
      else {
        c=c-9*D_*gride_[i][j].org_out()[2];
      }

      
      //update of organites out
      vector<float> vect;
      vect.push_back(a);
      vect.push_back(b);
      vect.push_back(c);
      gride_[x][y].set_org_out(vect);
      
    }
  }
}



//fonction de divison: la case c recoit la cellule fille de la case sur laquelle on applique le méthode
//c1: mother and c2: daugther
void Environnement::division(Case* c1, Case* c2){
  //cout << "testouille divisonouille" << endl;
  //cout << "cell = " << c1->cell() << endl;
  //cout << "division = " << c1->cell()->division_org()[1]  << endl;

  //stock the interior organelles of the cell that is going to divise
  vector<float> org_mother = c1->cell()->division_org();

  
  
  //stock of the cell's type
  char t;
  //cout << "La cellule qui va se diviser est une " << c1->cell()->Gettype()  << endl;
  //first we determine the mother's type
  if (c1->cell()->Gettype() == 'L'){
    t = 'L';
  }
  
  if (c1->cell()->Gettype() == 'S'){
    t = 'S';
  }

  
  
  
  //this is for the cell in the box
  double rand1 = (double) rand()/RAND_MAX;
  if ( rand1 <= c1->Pmut()){
    if (t == 'L'){
      c1->set_cell('S', org_mother);
      nb_L_ -=1;
      nb_S_ +=1;
    }
    else {
      c1->set_cell('L', org_mother);
      nb_S_ -= 1;
      nb_L_ += 1;
    } 
  }
  
  
  else {
    if (t == 'L'){
      c1->set_cell('L', org_mother);
    }
    else {
      //cout << "je vais me diviser en 2 car je suis une maman S" << endl;
      c1->set_cell('S', org_mother);
      //cout << "je me suis divisée en 2 car je suis une maman S" << endl;
    }
  } 
  
  
  //this is for the new cell that is going in the empty box
  double rand2 = (double) rand()/RAND_MAX;
  if ( rand2 <= c2->Pmut()){
    if (t == 'L'){
      c2->set_cell('S', org_mother);
      nb_S_ +=1;
    }
    else {
      c2->set_cell('L', org_mother);
      nb_L_ +=1;
    }
  } 
  
  
  else {
    if (t == 'L'){
      c2->set_cell('L', org_mother);
    }
    else {
      c2->set_cell('S', org_mother);
    } 
  }
  
  //cout << "testouille divisonouille ze end" << endl;
}
  



void Environnement::competition(){
  vector<int> length;
  vector<int> width;
  int cor_x;
  int cor_y;
  for (int k = 0; k < W_; ++k){
    length.push_back(k);
    width.push_back(k);
  }
  
  random_shuffle(length.begin(),length.end());
  random_shuffle(width.begin(),width.end());

  //cout << "je rentre dans compétition" << endl;
  for (vector<int>::iterator i = length.begin() ; i != length.end(); ++i){
    for (vector<int>::iterator j = width.begin() ; j != width.end(); ++j){
      if (gride_[*i][*j].IsEmpty() == true){
        //cout << "je rentre dans isempty() == true" << endl;
        for (int k=-1;k<2; ++k){
          for (int l=-1; l<2; ++l){
            if (k!=0 and l!=0){
              int x=0;

              int y=0;
              
              //Thor formation
              if(*i+k>H_-1){
                x=0;
              }
              else if(*i+k<0){
                x=H_-1;
              }
              else{
                x=*i+k;
              }
              if (*j+l>W_-1){
                y=0;
              }
              else if(*j+l<0){
                y=W_-1;
              }
              else{
                y=*j+l;
              }               
              
              //cout << "est ce que mon voisin est vide? " << gride_[x][y].IsEmpty() << endl;
              
              if (gride_[x][y].IsEmpty()== false){
                //cout << "je rentre dans isempty == false" << endl;
                int fit=gride_[x][y].fitness();
                cor_x = x;
                cor_y = y;
                
                if (fit<gride_[x][y].fitness()){
                  fit = gride_[x][y].fitness();
                  cor_x = x;
                  cor_y = y;
                }
              }
                           
            }
          }
        }
        division(&gride_[cor_x][cor_y], &gride_[*i][*j]);
      }
    }    
  }
}
 
      


//Filling the gride_

void Environnement::filling_gride(float A){
  vector<char> vec((H_*W_)/2, 'L');
  vector<char> vec1((H_*W_)/2,'S');
  vec.insert(vec.end(),vec1.begin(), vec1.end());
  random_shuffle(vec.begin(), vec.end());
  vector<char>::iterator it = vec.begin();
  
  for (int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++j){
        assert(it != vec.end());
        //gride_[i][j] = Case(A, *it);
        //Cell* cell = gride_[i][j].cell();
        gride_[i][j].set_cell(*it);
        //Cell* cell = gride_[i][j].cell();
        ++it;
      }
    }
}
   


//Reset the environment
void Environnement::reset_grid(float A){
  for(int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++j){      
      gride_[i][j].reset_case(A);
    }
  }
}
  

int Environnement::state(){
  if (nb_S_ ==0 and nb_L_ ==0){
    return 0; //"Extinction";
  }
  else if (nb_S_ ==0 and nb_L_ !=0){
    return 1; //"Exclusion";
  }
  else{
    return 2; //"Cohabitation";
  }
}


void Environnement::death(){  

  for(int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++j){ 
      float nb =  (rand()%(1000))/1000.0;  //random number between 0 et 1
      
      
      if (nb < Pdeath_){
        vector<float> org_out=gride_[i][j].org_out();
        vector<float> org_int=gride_[i][j].cell()->getorg_int();
        vector<float> new_org;
        new_org.push_back(org_int[0]+org_out[0]);
        new_org.push_back(org_int[1]+org_out[1]);
        new_org.push_back(org_int[2]+org_out[2]);
        gride_[i][j].set_org_out(new_org);
        
        if (gride_[i][j].IsA() == 'L'){
          nb_L_ -=1;
        }
        else {
          nb_S_ -=1;
        }
        
        
        gride_[i][j].death();

      }
    }
  }
}


void Environnement::metabolism(){
  //cout << "je rentre dans metabolisme" << endl;
  //cout << gride_[0][0].IsA() << endl;
  
  float new_Aout = .0;
  float new_Bout = .0;
    for(int i=0; i< H_; ++i){
      for (int j=0; j<W_; ++j){ 
        if (gride_[i][j].cell()->Gettype() == 'L'){
          //cout << "ma cellule est L" << endl;
        
          float Aout =gride_[i][j].org_out()[0];
          new_Aout =gride_[i][j].cell()->absorb(Aout);
          new_Bout =gride_[i][j].org_out()[1];
        }
        else if (gride_[i][j].cell()->Gettype() == 'S'){
          //cout << "ma cellule est S" << endl;
          float Bout =gride_[i][j].org_out()[1];
          
          assert(gride_[i][j].cell() != NULL);
          
          new_Bout = (gride_[i][j].cell())->absorb(Bout);
          new_Aout = gride_[i][j].org_out()[0];
        }
        
        else {
          cerr << "La cellule n'éxiste pas wsh " << endl;
          exit(EXIT_FAILURE);
       }
        

        vector <float> new_vect_out;
        new_vect_out.push_back(new_Aout);
        new_vect_out.push_back(new_Bout);
        new_vect_out.push_back(gride_[i][j].org_out()[2]);
        gride_[i][j].set_org_out(new_vect_out);
      }
    }
}



int Environnement::run(float Ainit, int t){
  filling_gride(Ainit);
  for (int z=1; z<5001; ++z){
    if (z == t){
      reset_grid(Ainit);
    }
    
    diffusion();
    death();
    competition();
    metabolism(); 
    //cout << "#######CECI EST LA FIN DE LA BOUCLE#######" << endl << endl;
  }

  return this->state();
      
}




   
   
