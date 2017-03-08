#include "Game.h"


void Game::Casting()
{
	TheBoard->Spell();
}

void Game::setDifficulty()
{
	char i;
	cout << "		Please select the difficulty of the computer" << endl;
	cout << "		1. Easy" << endl;
	cout << "		2. Medium" << endl;
	cout << "		3. Hard" << endl;
	cout << "		Option: ";
	cin >> i;
	while ((i != '1') && (i != '2') && (i != '3'))
	{
		cout << "		Wrong input. Please select the difficulty of the computer" << endl;
		cout << "		1. Easy" << endl;
		cout << "		2. Medium" << endl;
		cout << "		3. Hard" << endl;
		cout << "		Option: ";
		cin >> i;
	}

	switch (i)
	{
		case '1':
			TheBoard->setDiff(1);
			break;
		case '2':
			TheBoard->setDiff(3);
			break;
		case '3':
			TheBoard->setDiff(5);
			break;
	}	
	
}



void Game::getCoordinates()
{
	string str;
	char nmr;
	cout << "       Please enter the (row,col) of the piece you want to move:" << endl << "       ";
	cin >> str;
	while (str.length()!=3)
	{
		while (isdigit(str[0]==false) || (str[1]!=',') || (isalpha(str[2]==false || (((str[2]-49)>8) || ((str[2]-49)<0)))))
		{
			cin >> str;
			cout << "       ===ERROR: The input is incorrect.===" << endl << "       Enter the row, comma then the collumn." << endl << "       Like: 1,a" << endl;
			break;
		}
		break;
	}
	rFrom = static_cast<int>((str[0]-48));
	nmr = str[2];
	nmr = nmr - 49;
	cFrom = static_cast<int>(nmr-48);
	cout << "       Please enter the (row,col) where you want to move the piece:" << endl << "       ";
	cin >> str;
	while (str.length()!=3)
	{
		while (isdigit(str[0]==false) || (str[1]!=',') || (isalpha(str[2]==false || (((str[2]-49)>8) || ((str[2]-49)<0)))))
		{
			cin >> str;
			cout << "       ===ERROR: The input is incorrect.===" << endl << "       Enter the row, comma then the collumn." << endl << "       Like: 1,a" << endl;
			break;
		}
		break;
	}
	rTo = static_cast<int>(str[0]-48);
	nmr = str[2];
	nmr = nmr - 49;
	cTo = static_cast<int>(nmr-48);	
}

Game::Game()
{
	TheBoard = new Board;
	turn = 1;
	menu();
}

Game::Game(int i)
{
	TheBoard = new Board(i);
	turn = 1;
	menu();
}


Game::~Game()
{
	delete TheBoard;
}

void Game::TurnOver()
{
	if (turn==1) 
		turn = 2;
	else turn = 1;
}

void Game::menu()
{
	char choice,custom;
	bool over;
	string unre;
	unre = "5. Undo";
	choice = 1;

	while (choice!='0')
	{
		cout << "Player " << turn <<" enter your choice:" << endl;

		cout << "1. Move" << endl;
		cout << "2. Simulate AI move" << endl;
		cout << "3. Cast Spell" << endl;
		cout << "4. Customize" << endl;
		cout << "0. Exit" << endl;
		cout << unre << endl;
		cout << "Option: ";
		cin >> choice;		
		switch (choice)
		{
			case '0':
				cout << "Exit" << endl;
				break;

			case '1':
				getCoordinates();
				TheBoard->saveBoard();
				over = TheBoard->move(turn,rFrom,cFrom,rTo,cTo);
				if (over == true) 
				{
					TurnOver();
					unre="5. Undo";
				}
				break;
			case '2':
				TheBoard->saveBoard();
				TheBoard->DisplayBoard();
				TheBoard->stalling();

				TheBoard->startAI(turn,TheBoard->getDiff());
				TheBoard->displayAImsg();
				unre="5. Undo";
				TurnOver();
				break;
			case '3': 
				Casting();
				break;
			case '4': 
				cout << "	1. Default view. (Grid + Stats)" << endl;
				cout << "	2. Grid view only." << endl;
				cout << "	3. Stats view only." << endl;
				cout << "	4. Show/hide graveyard." << endl;
				cout << "	5. Set difficulty." << endl;
				cout << "	";
				cin >> custom;
				if (custom=='1')
					TheBoard->setOption(1);
				else if (custom=='2')
					TheBoard->setOption(2);
				else if (custom=='3')
					TheBoard->setOption(3);
				else if (custom=='4')
					TheBoard->setGraveShowHide();
				else if (custom=='5')
					setDifficulty();
				TheBoard->DisplayBoard();
				break;
			case '5': if (unre=="5. Undo")
				{
					unre = "5. Redo";
					TheBoard->undo();
					TurnOver();
				}				
				else 
				{
					TheBoard->redo();
					unre = "5. Undo";
					TurnOver();
				}
				break;

			default:
				cout << "No option selected" << endl;
		}
	}
}
