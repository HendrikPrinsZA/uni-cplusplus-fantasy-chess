#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"

class Necromancer: public SpellCaster
{
	public:
		Necromancer(int,int,int);
		Necromancer(int,int,int,int);
		~Necromancer();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return false;};
		string getName() const {return "Necromancer";};
		void setLifeFull() {life = 6;};

		bool isSpellCaster() {return true;};
		string SpellType() {return "resurrect";};
		void Resurrect(Piece&);
		bool CastSpell(Piece &);

	private:
		char PieceID[2];
		int player;
		int life;
};

#endif
