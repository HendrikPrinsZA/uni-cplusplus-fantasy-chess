#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <cstring>
#include <iostream>
#include <cctype>

using namespace std;

class Game
{
	public:
		Game();
		Game(int);
		~Game();
		void TurnOver(); //Determines when a turn is over
		void getCoordinates();
		void menu();
		void Casting();
		void setDifficulty();		
		
		friend class SpellCaster;
      
	
	private:
		int turn;
		int rFrom,cFrom,rTo,cTo;	
	protected:
		Board *TheBoard; //The board that we can refer to when playing
};
#endif
