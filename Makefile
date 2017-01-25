CC=g++
FLAGS=-std=c++11

MAIN=main

all:main

main: main.cpp
	    $(CC) $(FLAGS) main.cpp -o bin/main


