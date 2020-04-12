#include "PuzzleBoard.h"

void PuzzleBoard::reset()
{
	srand(time(NULL));
		
	for (int i=0; i <NUM_GRIDS; ++i) { m_grids[i] = i; }

	m_indexEmptyTile = 0;
	
	// random initialization
	int nMoves = rand() % 100;
	
	for (int i=0; i <nMoves; ++i) {
		int action = rand() % ACTION_SIZE;
		shift(Action(action));
	}
	
	m_hands = 0;
	
	return;
}

void PuzzleBoard::showBoard()
{
	cout << "#Moves: " << m_hands << endl;
	cout << "-------" << endl;
	for (int i=0; i<N_ROWS; i++) {
		for (int j=0; j<N_COLUMNS; j++) {
			if (j == 0) cout << "|" ;
			
			if (m_grids[getIndex(i,j)] == 0) { cout << " |"; }
			else {			
				cout << m_grids[getIndex(i,j)] ;
				cout << "|";
			}
		}	
		cout << std::endl;
		cout << "-------" << endl;
	}
	
	return;
}

bool PuzzleBoard::shift(Action action)
{	
	bool bValid = false;

	int i = m_indexEmptyTile / N_COLUMNS;
	int j = m_indexEmptyTile % N_COLUMNS;
	switch (action) {
		case ACTION_UP:
			// shift in column
			if (i+1 < N_ROWS) {
				int swapIndex = getIndex(i+1,j);
				swap(m_indexEmptyTile, swapIndex);
				m_indexEmptyTile = swapIndex;
				bValid = true;
			}
			break;
		case ACTION_DOWN: 
			// shift in column
			if (i-1 >= 0) {
				int swapIndex = getIndex(i-1,j);
				swap(m_indexEmptyTile, swapIndex);
				m_indexEmptyTile = swapIndex;
				bValid = true;
			}
			break;
		case ACTION_LEFT: 
			if (j+1 < N_COLUMNS) {
				int swapIndex = getIndex(i,j+1);
				swap(m_indexEmptyTile, swapIndex);
				m_indexEmptyTile = swapIndex;
				bValid = true;
			}
			break;
		case ACTION_RIGHT: 
			if (j-1 >= 0) {
				int swapIndex = getIndex(i,j-1);
				swap(m_indexEmptyTile, swapIndex);
				m_indexEmptyTile = swapIndex;
				bValid = true;
			}
			break;
		default: 
			break;
	}
	
	if (bValid) { ++m_hands; }
	
	return bValid;
}


bool PuzzleBoard::isEndGame()
{
	for (int i=0; i <NUM_GRIDS; ++i) { 
		if (m_grids[i] != i) { return false; }
	}		
	
	return true;
}