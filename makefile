# makefile for project 2

build: *.h *.cpp 
	g++ -std=c++0x -o output_file *.h *.cpp
run: output_file 
	./output_file
