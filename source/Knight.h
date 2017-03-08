#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight: public Piece
{
	public:
		Knight(int,int,int);
		Knight(int,int,int,int);
		~Knight();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return false;};
		string getName() const {return "Knight     ";};
		void setLifeFull() {life = 10;};

	private:
		char PieceID[2];
		int player;
		int life;
};

#endif
