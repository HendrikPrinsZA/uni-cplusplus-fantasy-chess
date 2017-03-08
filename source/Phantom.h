#ifndef PHANTOM_H
#define PHANTOM_H

#include "SpellCaster.h"

class Phantom: public SpellCaster
{
	public:
		Phantom(int,int,int);
		Phantom(int,int,int,int);
		~Phantom();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return false;};
		string getName() const {return "Phantom    ";};
		void setLifeFull() {};


		bool isSpellCaster() {return true;};
		string SpellType() {return "teleport";};
		void Teleport();
		bool CastSpell(Piece &);

	private:
		char PieceID[2];
		int player;
		int life;
};

#endif
