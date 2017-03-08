#ifndef DRAGON_H
#define DRAGON_H

#include "SpellCaster.h"

class Dragon: public SpellCaster
{
	public:
		Dragon(int,int,int);
		Dragon(int,int,int,int);
		~Dragon();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return false;};
		string getName() const {return "Dragon     ";};
		void setLifeFull() {life = 18;};


		bool isSpellCaster() {return true;};
		string SpellType() {return "spit fireball";};
		void Spit(Piece&);
		bool CastSpell(Piece &);

	private:
		char PieceID[2];
		int player;
		int life;
};

#endif
