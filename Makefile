all : add-nbo

add-nbo: main.o
	g++ -o add-nbo main.o

main.o: main.cpp
	g++ -c main.o main.cpp
