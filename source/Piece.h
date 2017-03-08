#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class Piece
{
	public:
		Piece(int,int);
		virtual ~Piece();
		virtual string getPieceID() const = 0;
		virtual char getChar() const;
		virtual int getPlayer() const = 0;
		virtual bool checkMove(int,int) = 0;
		virtual void attack() = 0;
		virtual int getLife() const = 0;
		virtual bool isKing() const = 0;
		virtual string getName() const = 0;
		virtual bool isSpellCaster() {return false;};
		virtual bool CastSpell() {return false;};
		virtual bool CastSpell(Piece &) {return false;};
		virtual string SpellType() {return "";};
		virtual void setLifeFull() {};
		virtual char getSpellChar() {return 'a';};

		void setR(int);
		void setC(int);
		int getR() const;
		int getC() const;	

	private:
		int r;
		int c;
};

#endif
