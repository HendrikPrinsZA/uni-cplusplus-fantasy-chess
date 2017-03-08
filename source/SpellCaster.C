#include "SpellCaster.h"

SpellCaster::SpellCaster(int _r, int _c): Piece(_r,_c)
{
}

void SpellCaster::getPiece() const
{
}

bool SpellCaster::CastSpell()
{
	return false;
}

bool SpellCaster::CastSpell(Piece &)
{
	return false;
}
