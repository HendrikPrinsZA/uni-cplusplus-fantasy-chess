#include "Necromancer.h"

void Necromancer::Resurrect(Piece &p)
{
}

bool Necromancer::CastSpell(Piece &p)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-p.getR()));
	moveC = abs(static_cast<double>(getC()-p.getC()));
	if ((moveR==moveC) && moveR<=3)
	{
		Resurrect(p);	
		return true;
	}
	if ((moveR+moveC)<=3)
	{
		Resurrect(p);
		return true;
	}
	return false;
}

void Necromancer::attack()
{
	life = life-2;
}

Necromancer::Necromancer(int iPlayer, int _r, int _c) : SpellCaster(_r , _c)
{
	life = 6;
	player = iPlayer;
	strcpy(PieceID,"N");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}

Necromancer::Necromancer(int iPlayer, int _r, int _c, int _l) : SpellCaster(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"N");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool Necromancer::checkMove(int r,int c)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-r));
	moveC = abs(static_cast<double>(getC()-c));
	if ((moveR==moveC) && moveR==1)
		return true;
	if ((moveR+moveC)>1)
		return false;
	return true;
	
}	

Necromancer::~Necromancer()
{
}

int Necromancer::getPlayer() const
{
	return player;
}

string Necromancer::getPieceID() const
{
	return PieceID;
}
char Necromancer::getChar() const
{
	return PieceID[0];
}
