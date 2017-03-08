#ifndef FOOTSOLDIER_H
#define FOOTSOLDIER_H

#include "Piece.h"

class FootSoldier: public Piece
{
	public:
		FootSoldier(int,int,int);
		FootSoldier(int,int,int,int);
		~FootSoldier();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return false;};
		
		void setLifeFull() {life = 6;};

		string getName() const {return "Footsoldier";};

	private:
		char PieceID[2];
		int player;
		int life;
};

#endif
