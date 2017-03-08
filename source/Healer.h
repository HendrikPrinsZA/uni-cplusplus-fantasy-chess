#ifndef HEALER_H
#define HEALER_H
#include "SpellCaster.h"

class Healer: public SpellCaster
{
	public:
		Healer(int,int,int);
		Healer(int,int,int,int);
		~Healer();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return false;};
		string getName() const {return "Healer     ";};
		
		bool isSpellCaster() {return true;};
		string SpellType() {return "healing";};
		void Heal(Piece&);
		bool CastSpell(Piece &);

	private:
		char PieceID[2];
		int player;
		int life;
};

#endif
