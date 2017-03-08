#include "Phantom.h"

void Phantom::Teleport()
{
	life--;
}

bool Phantom::CastSpell(Piece &p)
{
	
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-p.getR()));
	moveC = abs(static_cast<double>(getC()-p.getC()));
	if (moveR==moveC)
	{
		for (int a=0; a<(moveR+moveC); a++)
			Teleport();
		return true;
	}
	if ((getR()==p.getR())||(getC()==p.getC()))
	{
		for (int a=0; a<(moveR+moveC); a++)
			Teleport();
		return true;
	}
	return false;
}


void Phantom::attack()
{
	life = life-2;
}

Phantom::Phantom(int iPlayer, int _r, int _c) : SpellCaster(_r , _c)
{
	life = 5;
	player = iPlayer;
	strcpy(PieceID,"P");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}

Phantom::Phantom(int iPlayer, int _r, int _c, int _l) : SpellCaster(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"P");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool Phantom::checkMove(int r,int c)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-r));
	moveC = abs(static_cast<double>(getC()-c));
	
	if (getR()==r && moveC<=2)
		return true;
	else if (getC()==c && moveR<=2)
		return true;
	else if ((moveR==moveC) && (moveR+moveC)<=4)
		return true;
	return false;
	
}	

Phantom::~Phantom()
{
}

int Phantom::getPlayer() const
{
	return player;
}

string Phantom::getPieceID() const
{
	return PieceID;
}
char Phantom::getChar() const
{
	return PieceID[0];
}
