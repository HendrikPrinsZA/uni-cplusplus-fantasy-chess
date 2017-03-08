#include "Custom.h"

void Custom::setName()
{
	for (int a = 0; a< 40; a++)
		cout << endl;
	cout << "				CREATING A CUSTOM PIECE" << endl;
	cout << "Please enter your custom piece's name: ";
	cin >> name;
}

void Custom::setTheLife()
{
	int l;
	l = 0;
	cout << "Please enter " << name << "'s maximum life (0<life<21) :";
	cin >> l;
	while ((l<1) || (l > 21))
	{
		cout << "Value was incorrect" << endl;
		cout << "Please enter " << name << "'s maximum life (0<life<21) :";
		cin >> l;
	}
	maxLife = l;
}

void Custom::setMoveRadius()
{
	cout << "Please enter the move radius: ";
	cin >> moveRadius;
}


void Custom::setSpellType()
{
	char option;
	cout << "Please select a spell type from the list" << endl;
	cout << "	1.Spitting Fire"<< endl;
	cout << "	2.Healing"<< endl;
	cout << "Option: ";
	cin >> option;
	while ((option!='1')&&(option!='2'))
	{
		cout << "Must select 1 or 2" << endl;
		cout << "Option: ";
		cin >> option;
	}
	_spelltype = option;
	if (option == '1')
		spellName = "fire spitting";
	else 
		spellName = "healing";
}

Custom::Custom(int iPlayer, int _r, int _c) : SpellCaster(_r , _c)
{
	setName();
	setTheLife();
	setSpellType();
	setMoveRadius();
	life = maxLife;
	player = iPlayer;
	strcpy(PieceID,"*");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


void Custom::Spit(Piece &p)
{
	p.attack();
	p.attack();
	p.attack();
}

void Custom::Heal(Piece &p)
{
	p.setLifeFull();
}


bool Custom::CastSpell(Piece &p)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-p.getR()));
	moveC = abs(static_cast<double>(getC()-p.getC()));
	if (_spelltype=='1')
	{
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
	}
	else
	{
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
	}
	return false;
}



void Custom::attack()
{
	life = life-2;
}

Custom::Custom(int iPlayer, int _r, int _c, int _l) : SpellCaster(_r , _c)
{
	life = _l;
	player = iPlayer;
	strcpy(PieceID,"*");
	if (iPlayer==1)
		strcat(PieceID,"1");
	else 
		strcat(PieceID,"2");
}


bool Custom::checkMove(int r,int c)
{
	double moveR,moveC;
	moveR = abs(static_cast<double>(getR()-r));
	moveC = abs(static_cast<double>(getC()-c));
	if ((moveR==moveC) && (moveR<=moveRadius))
		return true;
	if ((moveR+moveC)>moveRadius)
		return false;
	return true;
	
}	

Custom::~Custom()
{
}

int Custom::getPlayer() const
{
	return player;
}

string Custom::getPieceID() const
{
	return PieceID;
}
char Custom::getChar() const
{
	return PieceID[0];
}
