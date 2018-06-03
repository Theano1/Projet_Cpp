all: main

main: main.o Environnement.o Case.o Cell.o CellL.o CellS.o
	g++ -o main main.o Environnement.o Case.o Cell.o CellS.o CellL.o
	
main.o:main.cpp Case.cpp Environnement.cpp Cell.cpp CellL.cpp CellS.cpp
	g++ -g -c -Wall main.cpp -o main.o -std=c++11
	
Case.o:Case.cpp Case.h Cell.h CellL.h CellS.h 
	g++ -g -c -Wall  Case.cpp -o Case.o -std=c++11

Environnement.o:Environnement.cpp Environnement.h
	g++ -g -c -Wall   Environnement.cpp -o Environnement.o -std=c++11

Cell.o:  Cell.cpp Cell.h 
	g++ -g -c -Wall   Cell.cpp -o Cell.o -std=c++11

CellS.o:  CellS.cpp CellS.h Cell.h
	g++ -g -c -Wall   CellS.cpp -o CellS.o -std=c++11

CellL.o:  CellL.cpp CellL.h Cell.h
	g++ -g -c -Wall   CellL.cpp -o CellL.o -std=c++11


clean:
	rm -f *.o

