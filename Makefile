main: main.o Environnement.o Case.o
	g++ -o main main.o Environnement.o Case.o Cell.o CellS.o CellL.o 
	
main.o:main.cpp
	g++ -o main.o -c main.cpp
	
Case.o:Case.cpp
	g++ -o Case.o -c Case.cpp

Environnement.o:Environnement.cpp
	g++ -o Environnement.o -c Environnement.cpp

Cell.o:Cell.cpp Cell.h
	g++ -o Cell.o -c Cell.cpp

CellS.o:CellS.cpp CellS.h Cell.
	g++ -o CellS.o -c Cell.cpp

CellL.o:CellL.cpp CellL.h Cell.
	g++ -o CellL.o -c Cell.cpp