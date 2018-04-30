main: main.o Environnement.o Case.o
	g++ -o main main.o Environnement.o Case.o
	
main.o:main.cpp
	g++ -o main.o -c main.cpp
	
Case.o:Case.cpp
	g++ -o Case.o -c Case.cpp

Environnement.o:Environnement.cpp
	g++ -o Environnement.o -c Environnement.cpp
