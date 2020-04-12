#include <iostream>
#include <sstream>
#include "PuzzleBoard.h"
using namespace std;

int main()
{
	PuzzleBoard board;
	board.showBoard();
	string line;	
	bool bResult = false;
	while(cin>>line) {
		bool bResult;
		if (line == "U" || line == "u" || line == "8") { 
			cout << "[Action: UP]" << endl;
			bResult = board.shift(PuzzleBoard::ACTION_UP); 
		}
		else if (line == "D" || line == "d" || line == "2") { 
			cout << "[Action: DOWN]" << endl;
			bResult = board.shift(PuzzleBoard::ACTION_DOWN); 
		}
		else if (line == "R" || line == "r" || line == "6") { 
			cout << "[Action: RIGHT]" << endl;
			bResult = board.shift(PuzzleBoard::ACTION_RIGHT); 
		}
		else if (line == "L" || line == "l" || line == "4") { 
			cout << "[Action: LEFT]" << endl;
			bResult = board.shift(PuzzleBoard::ACTION_LEFT); 
		}
		else if (line == "clear_board") {
			cout << "[Clear Board]" << endl;	
			board.reset();
			bResult = true;
		}
		else { 
			cout << "Invalid action: " << line << endl; 
			bResult = false;
		}
		
		if (!bResult) { cout << "Board not changed" << endl; }		
		
		board.showBoard();
		
		if (board.isEndGame()) {
			cout << "You won!" << endl;
			cout << "Game restart." << endl;
			board.reset();	
			board.showBoard();
		}
	}

   return 0;
}

