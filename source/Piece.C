#include "Piece.h"


int Piece::getR() const
{
	return r;
}
int Piece::getC() const
{
	return c;
}
void Piece::setR(int _r)
{
	r = _r;
}
void Piece::setC(int _c)
{
	c = _c;
}


Piece::Piece(int _r, int _c)
{
	r = _r;
	c = _c;
}

Piece::~Piece()
{
}


char Piece::getChar() const
{
	return ' ';
}
