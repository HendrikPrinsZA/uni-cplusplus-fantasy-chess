#ifndef SPELLCASTER_H
#define SPELLCASTER_H
#include "Piece.h"


class SpellCaster: public Piece
{
	public:
		SpellCaster(int _r, int _c);
		void getPiece() const;
		virtual bool CastSpell();
		virtual bool CastSpell(Piece &);
		virtual string SpellType() {return "";};

	protected:
		bool limit;
};

#endif
