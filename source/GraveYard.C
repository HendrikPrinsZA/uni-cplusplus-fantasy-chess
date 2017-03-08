#include "GraveYard.h"

void GraveYard::setPointerNull(Piece *p)
{
	if (graveyard.size()>0)
	{
		if (p != 0)
		{
			for (int a=0; a<count ; a++)
			{
				if (graveyard[a]==p)
				{
					graveyard[a]=0;
				}
			}
		}
	}
}

Piece* GraveYard::getReplacement(Piece *p, int _p)
{
	bool found;
	found = false;
	if (graveyard.size()>0)
		while (found==false)
		{
			for (int a = getCount()-1;a>=0; a--)
				if (p->getPlayer()==_p)
				{
					return graveyard[a];
				}
			found = true;
		}
	return p;
}



ostream& operator<<(ostream &strm, const GraveYard *obj)
{
	cout << "*				          Graveyard					   *" << endl;
	cout << "* Player:		Piece:			Position:			       	   *" << endl;
	cout << "*------------------------------------------------------------------------------------------*" << endl;
	
	if (obj->getCount()==0)
		cout << "*	<Graveyard is empty>					                           *" << endl;
	else
	for (int a=0; a<obj->getCount(); a++)
	{
		if (obj->graveyard[a])
		{
			cout << "* " << obj->graveyard[a]->getPlayer() <<"               	" << obj->graveyard[a]->getName()<< "		";
			cout << obj->graveyard[a]->getR() << "," << static_cast<char>(obj->graveyard[a]->getC()+97) << "					   *" << endl;
		}
	}
	cout << "********************************************************************************************" << endl;
	return strm;
};

GraveYard::GraveYard()
{
	count = 0;
}

GraveYard::~GraveYard()
{
	if (graveyard.size()>0)
	{
		for (int i=(count-1); i >=0 ; i--)
		{
			if (graveyard[i]!=0)
			{
				delete graveyard[i];
				graveyard[i] = 0;
				graveyard.pop_back();
			}
		}
	}
}

void GraveYard::appendGrave(Piece &p)
{
	graveyard.push_back(&p);
	cout << "			vector: " << count << " points to " <<  graveyard[count] << " whitch is a " << graveyard[count]->getName() << endl;
	count++;
}

int GraveYard::getCount() const
{
	return count;
}
