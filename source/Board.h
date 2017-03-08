#ifndef BOARD_H
#define BOARD_H

//#include "Piece.h"
#include "FootSoldier.h" //Includes subclass
#include "Empty.h"
#include "Knight.h"
#include "King.h"
#include "Phantom.h"
#include "Healer.h"
#include "Dragon.h"
#include "Necromancer.h"
#include "GraveYard.h"
#include "Custom.h"

#include <cmath>

#include <iostream>
#include <cstring>

class GraveYard;

using namespace std;

class Board
{
	public:
		Board();
		Board(int);
		~Board();
		void DisplayBoard();
		bool move(int _player, int _xFrom, int _yFrom, int _xTo, int _yTo);
		void undo();
		void redo();
		void saveBoard();
		void gameOver(int);
		void setOption(int i){option = i;};
		void Spell();
		void setGraveShowHide() { if (_graveShowHide == 0) _graveShowHide=1; else _graveShowHide=0;};
		bool buyPiece(int _player, char _piece, int _r, int _c);
		
		int getDiff() {return difficulty;};
		void setDiff(int _d) {difficulty = _d;};

		void startAI(int _p, int diff);
		bool defend(int, int, int);
		bool checkMoves(int, int);
		void displayAImsg();
		void clean(Piece*);
		void stalling();
	
	private:
		bool moveToOpen(int _player, int _xFrom, int _yFrom, int _xTo, int _yTo);
		static const int ROWS = 9;
		static const int COLS = 9;
		
	protected:
		Piece *dmGrid[ROWS][COLS];
		Piece *Backup[ROWS][COLS];
		Piece *Redo[ROWS][COLS];
		GraveYard *grave;
		Piece *cleanTo,*cleanFrom;
		
		int option,_graveShowHide,difficulty,countMoves;
		unsigned **moves;
};

#endif
