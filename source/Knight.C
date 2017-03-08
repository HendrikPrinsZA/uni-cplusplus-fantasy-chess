#include "Knight.h"
#include "Knight.h"

void Knight::attack()
{
	life = life-2;
}

Knight::Knight(int iPlayer, int _r, int _c) : Piece(_r , _c)
{
	life = 10;
	player = iPlayer;
	strcpy(PieceID,"K");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}

Knight::Knight(int iPlayer, int _r, int _c, int _l) : Piece(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"K");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool Knight::checkMove(int r,int c)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-r));
	moveC = abs(static_cast<double>(getC()-c));
	if ((moveR+moveC)==3)
		return true;
	if ((moveR+moveC)>2)
		return false;
	return false;
	
}	

Knight::~Knight()
{
}

int Knight::getPlayer() const
{
	return player;
}

string Knight::getPieceID() const
{
	return PieceID;
}
char Knight::getChar() const
{
	return PieceID[0];
}
