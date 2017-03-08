#ifndef GRAVEYARD_H
#define GRAVEYARD_H
#include <vector>

#include "Board.h"
#include "Necromancer.h"


using namespace std;
class GraveYard
{
	public:
		GraveYard();
		~GraveYard();
		void appendGrave(Piece &);
		Piece* getReplacement(Piece *, int);
		void setPointerNull(Piece *);
		int getCount() const;
		friend ostream &operator << (ostream &, const GraveYard *);
		friend class Board;

	private:
		static const int size = 34;
		int count;
		vector<Piece*> graveyard;	
		
};

#endif
