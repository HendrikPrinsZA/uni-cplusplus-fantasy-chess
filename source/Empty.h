#ifndef EMPTY_H
#define EMPTY_H

#include "Piece.h"

class Empty: public Piece
{
	public:
		Empty(int,int);
		~Empty();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int){return true;};
		void attack(){};
		int getLife() const {return 0;};
		bool isKing() const {return false;};
		string getName() const {return "";};
	private:
		char PieceID[2];
		int player;

};

#endif
