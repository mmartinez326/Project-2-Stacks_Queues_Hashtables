# makefile for project 2

build: *.h *.cpp 
	g++ -std=c++0x -fpermissive *.h *.cpp
run: output_file 
	./a.out
