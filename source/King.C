#include "King.h"


void King::attack()
{
	life = life-2;
}

King::King(int iPlayer, int _r, int _c) : Piece(_r , _c)
{
	life = 30;
	player = iPlayer;
	strcpy(PieceID,"X");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}

King::King(int iPlayer, int _r, int _c, int _l) : Piece(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"X");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool King::checkMove(int r,int c)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-r));
	moveC = abs(static_cast<double>(getC()-c));
	
	if (getR()==r && moveC<=3)
		return true;
	else if (getC()==c && moveR<=3)
		return true;
	else if ((moveR==moveC) && (moveR+moveC)<=6)
		return true;
	return false;
	
}	

King::~King()
{
}

int King::getPlayer() const
{
	return player;
}

string King::getPieceID() const
{
	return PieceID;
}
char King::getChar() const
{
	return PieceID[0];
}
