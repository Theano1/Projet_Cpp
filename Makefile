main: main.o Environnement.o Case.o
	g++ -o main main.o Environnement.o Case.o
	
main.o:main.cpp
	g++ -o main.o -c main.cpp -std=gnu++11
	
Case.o:Case.cpp
	g++ -o Case.o -c Case.cpp -std=gnu++11

Environnement.o:Environnement.cpp
	g++ -o Environnement.o -c Environnement.cpp -std=gnu++11
	
Cell.o:Cell.cpp
	g++ -o Cell.o -c Cell.cpp -std=gnu++11
