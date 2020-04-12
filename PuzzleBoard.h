#ifndef PUZZLE_BOARD_H
#define PUZZLE_BOARD_H

#include <iostream>
#include <time.h>
using namespace std;

class PuzzleBoard 
{

public: 

  enum Action {
	  ACTION_UP,
	  ACTION_DOWN,
	  ACTION_LEFT,
	  ACTION_RIGHT,
	  
	  ACTION_SIZE
  };
	
  static const int N_ROWS = 3;
  static const int N_COLUMNS = 3;
  static const int NUM_GRIDS = N_ROWS * N_COLUMNS;

  PuzzleBoard() { reset(); }	
	
  void reset();
  void showBoard();
  bool shift(Action action);
  
  inline int getIndex(int i, int j) const { return N_COLUMNS*i+j; }
  inline void swap(int index1, int index2) { 
	int tmp = m_grids[index1];
	m_grids[index1] = m_grids[index2];
	m_grids[index2] = tmp;
  }
  
  bool isEndGame();
	
private:
	int m_indexEmptyTile;
	int m_grids[NUM_GRIDS];	
	int m_hands;
};

#endif