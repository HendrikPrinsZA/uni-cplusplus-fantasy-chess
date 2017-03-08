#include "Healer.h"

void Healer::Heal(Piece &p)
{
	p.setLifeFull();
}

bool Healer::CastSpell(Piece &p)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-p.getR()));
	moveC = abs(static_cast<double>(getC()-p.getC()));
	if ((moveR==moveC) && moveR<=2)
	{
		Heal(p);	
		return true;
	}
	if ((moveR+moveC)<=3)
	{
		Heal(p);
		return true;
	}
	return false;
}

void Healer::attack()
{
	life = life-2;
}

Healer::Healer(int iPlayer, int _r, int _c) : SpellCaster(_r , _c)
{
	life = 6;
	player = iPlayer;
	strcpy(PieceID,"H");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}

Healer::Healer(int iPlayer, int _r, int _c, int _l) : SpellCaster(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"H");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool Healer::checkMove(int r,int c)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-r));
	moveC = abs(static_cast<double>(getC()-c));
	if ((moveR==moveC) && ((moveR+moveC)<=12))
		return true;
	return false;
	
}	

Healer::~Healer()
{
}

int Healer::getPlayer() const
{
	return player;
}

string Healer::getPieceID() const
{
	return PieceID;
}
char Healer::getChar() const
{
	return PieceID[0];
}
