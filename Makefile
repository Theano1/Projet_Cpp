main: main.o
	g++ -o main main.o
	
main.o:main.cpp
	g++ -o main.o -c main.cpp
