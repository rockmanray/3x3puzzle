all: PuzzleBoard.cpp main.cpp PuzzleBoard.h
	g++ -c PuzzleBoard.cpp
	g++ main.cpp PuzzleBoard.o -o puzzle
