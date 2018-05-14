main: main.o Environnement.o Case.o
	g++ -o main main.o Environnement.o Case.o Cell.o CellS.o CellL.o -std=gnu++11
	
	
Case.o:Case.cpp
	g++ -o Case.o -c Case.cpp -std=gnu++11

Environnement.o:Environnement.cpp
	g++ -o Environnement.o -c Environnement.cpp -std=gnu++11
	

Cell.o:Cell.cpp Cell.h
	g++ -o Cell.o -c Cell.cpp -std=gnu++11

CellS.o:CellS.cpp CellS.h Cell.
	g++ -o CellS.o -c Cell.cpp

CellL.o:CellL.cpp CellL.h Cell.
	g++ -o CellL.o -c Cell.cpp

