#include "FootSoldier.h"

void FootSoldier::attack()
{
	life = life-2;
}

FootSoldier::FootSoldier(int iPlayer, int _r, int _c) : Piece(_r , _c)
{
	life = 6;
	player = iPlayer;
	strcpy(PieceID,"F");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}

FootSoldier::FootSoldier(int iPlayer, int _r, int _c, int _l) : Piece(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"F");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool FootSoldier::checkMove(int r,int c)
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

FootSoldier::~FootSoldier()
{
}

int FootSoldier::getPlayer() const
{
	return player;
}

string FootSoldier::getPieceID() const
{
	return PieceID;
}
char FootSoldier::getChar() const
{
	return PieceID[0];
}
