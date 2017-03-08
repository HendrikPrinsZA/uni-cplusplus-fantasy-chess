#ifndef CUSTOM_H
#define CUSTOM_H

#include "SpellCaster.h"

class Custom: public SpellCaster
{
	public:
		Custom(int,int,int);
		Custom(int,int,int,int);
		~Custom();
		int getPlayer() const;
		string getPieceID() const;
		char getChar() const;
		bool checkMove(int, int);
		void attack();
		int getLife() const {return life;};
		bool isKing() const {return false;};
		string getName() const {return name;};
		void setLifeFull() {life = maxLife;};

		void setName();
		void setTheLife();
		void setSpellType();
		void setMoveRadius();
		char getSpellChar() {return _spelltype;};


		bool isSpellCaster() {return true;};
		string SpellType() {return spellName;};
		void Spit(Piece&);
		void Heal(Piece&);
		bool CastSpell(Piece &);

	private:
		char PieceID[2];
		int player;
		int life, maxLife, moveRadius;
		string name,spellName;
		char _spelltype;
};

#endif
