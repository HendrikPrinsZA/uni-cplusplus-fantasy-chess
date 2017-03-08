#include "Empty.h"

Empty::Empty(int _r, int _c) : Piece(_r , _c)
{
	player = 0;
	strcpy(PieceID,"  ");
}

Empty::~Empty()
{

}

int Empty::getPlayer() const
{
	return player;
}

string Empty::getPieceID() const
{
	return PieceID;
}

char Empty::getChar() const
{
	return PieceID[0];
}
