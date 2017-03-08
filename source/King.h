#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "SpellCaster.h"

class King: public Piece
{
	public:
		King(int,int,int);
		King(int,int,int,int);
		~King();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return true;};
		string getName() const {return "King       ";};
		void setLifeFull() {life = 30;};
		
		//void CastSpell(Piece &);

	private:
		char PieceID[2];
		int player;
		int life;
};

#endif
