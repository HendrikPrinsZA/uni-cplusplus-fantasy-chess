#include "Dragon.h"

void Dragon::Spit(Piece &p)
{
	p.attack();
	p.attack();
	p.attack();
}

bool Dragon::CastSpell(Piece &p)
{
	
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-p.getR()));
	moveC = abs(static_cast<double>(getC()-p.getC()));
	if ((moveR==moveC) && moveR<=4)
	{
		Spit(p);	
		return true;
	}
	if ((moveR+moveC)<=4)
	{
		Spit(p);
		return true;
	}
	return false;
}



void Dragon::attack()
{
	life = life-2;
}

Dragon::Dragon(int iPlayer, int _r, int _c) : SpellCaster(_r , _c)
{
	life = 18;
	player = iPlayer;
	strcpy(PieceID,"D");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}

Dragon::Dragon(int iPlayer, int _r, int _c, int _l) : SpellCaster(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"D");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool Dragon::checkMove(int r,int c)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-r));
	moveC = abs(static_cast<double>(getC()-c));
	if ((getR()!=r)&&(getC()!=c))
		return false;
	if ((moveR+moveC)>3)
		return false;
	return true;
	
}	

Dragon::~Dragon()
{
}

int Dragon::getPlayer() const
{
	return player;
}

string Dragon::getPieceID() const
{
	return PieceID;
}
char Dragon::getChar() const
{
	return PieceID[0];
}
