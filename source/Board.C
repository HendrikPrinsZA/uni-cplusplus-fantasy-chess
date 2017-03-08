#include "Board.h"

const int MAXPIECES = 18;
const int ROWS = 9;
const int COLS = 9;	

void Board::clean(Piece *cleanP)
{
	bool _clean;
	_clean = true;
	if (cleanP!=0)
	{
		for (int a=0; a<9; a++)
		{
			for (int b=0; b<9; b++)
			{
				if (dmGrid[a][b]==cleanP)
				{
					_clean = false;
					break;
				}
				else if (Backup[a][b]==cleanP)
				{
					_clean = false;
					break;
				}
				else if (Redo[a][b]==cleanP)
				{
					_clean = false;
					break;
				}
			}
			if (_clean==false)
				break;
		}
		
		if ((grave->count)>0)
		{
			for (int a=0; a<(grave->count) ; a++)
			{
				if (grave->graveyard[a]==cleanP)
				{
					_clean = false;
					cleanP = 0;
					break;
				}
			}
		}

		if (_clean==true)
		{
			delete cleanP;	
			cleanP = 0;
		}
	}
}



bool Board::buyPiece(int _player, char _piece, int _r, int _c)
{
	if (_player == 1)
	{
		if (_r > 3)
		{
			cout << "==Error: Not allowed to use that half of the board==" << endl;
			return false;
		}
		else if ((_r<0)||(_c<0)||(_c>8))
		{
			cout << "==Error: Requested placement out of range==" << endl;
			return false;
		}	
		else if (dmGrid[_r][_c]->getChar()!=' ')
		{
			cout << "==Already a piece on that placement==" << endl;
			return false;
		}	
	}	
	else if (_player == 2)
	{
		if (_r < 4)
		{
			cout << "==Error: Not allowed to use that half of the board==" << endl;
			return false;
		}
		else if ((_r>8)||(_c<0)||(_c>8))
		{
			cout << "==Error: Requested placement out of range==" << endl;
			return false;
		}	
		else if (dmGrid[_r][_c]->getChar()!=' ')
		{
			cout << "==Already a piece on that placement==" << endl;
			return false;
		}	
	}	

	switch (_piece)
	{
		case '1':	
			delete dmGrid[_r][_c];
			dmGrid[_r][_c] = new FootSoldier(_player,_r,_c);
			break;
;
		case '2':
			delete dmGrid[_r][_c];
			dmGrid[_r][_c] = new Knight(_player,_r,_c);
			break;

		case '3':
			delete dmGrid[_r][_c];
			dmGrid[_r][_c] = new Phantom(_player,_r,_c);
			break;

		case '4':
			delete dmGrid[_r][_c];
			dmGrid[_r][_c] = new Dragon(_player,_r,_c);
			break;
			
		case '5':
			delete dmGrid[_r][_c];
			dmGrid[_r][_c] = new Healer(_player,_r,_c);
			break;
	
		case '6':
			delete dmGrid[_r][_c];
			dmGrid[_r][_c] = new Necromancer(_player,_r,_c);
			break;

		case '7':
			delete dmGrid[_r][_c];
			dmGrid[_r][_c] = new Custom(_player,_r,_c);
			break;
	

		default:
			cout << "No piece selected" << endl;
			break;
	}
	return true;
}


Board::Board(int i)
{
	//Creating custom layout
	option = 2;
	_graveShowHide = 0;
	difficulty = 3;
	bool check;
	check = false;
	int balance, temp;
	int p,_r,_c;
	char option;

	p = 1;
	balance = 100;

	for (int i=0; i<COLS; i++)
	{
		dmGrid[1][i] = new Empty(0,i);
		dmGrid[7][i] = new Empty(0,i);
		dmGrid[0][i] = new Empty(0,i);
		dmGrid[2][i] = new Empty(2,i);
		dmGrid[3][i] = new Empty(3,i);
		dmGrid[4][i] = new Empty(4,i);
		dmGrid[5][i] = new Empty(5,i);
		dmGrid[6][i] = new Empty(6,i);
		dmGrid[8][i] = new Empty(8,i);	
	}	
	//Kings
	delete dmGrid[0][4];
	delete dmGrid[8][4];
	dmGrid[0][4] = new King(1,0,4);
	dmGrid[8][4] = new King(2,8,4);	

	//Player 1 buying
	while (balance >= 5)
	{
		temp = 0;
		for (int a=0; a < 40; a++)
			cout << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "$				The Shop						   $" << endl;
		cout << "$ ITEMS:										   $" << endl;
		cout << "$ 1.FootSoldier			R6.00							   $" << endl;
		cout << "$ 2.Knight			R10.00							   $" << endl;
		cout << "$ 3.Phantom			R5.00							   $" << endl;
		cout << "$ 4.Dragon			R18.00							   $" << endl;
		cout << "$ 5.Healer			R6.00							   $" << endl;
		cout << "$ 6.Necromancer			R6.00							   $" << endl;
		cout << "$ 7.Custom			R<Have to input>					   $" << endl;
		cout << "$------------------------------------------------------------------------------------------$" << endl;
		cout << "$ Player " << p << " shopping cart 					[Balance: " << balance << "]		   $" << endl;
		cout << "$											   $" << endl;
		cout << "$ Name:		Coordinates:	Life:           || Name:	Coordinates:	Life:	   $" << endl;
		for (int a = 0; a < 9; a++)
			for (int b = 0; b < 9; b++)
			{
				if (dmGrid[a][b]->getPlayer()==p)
				{
					temp++;
					if (temp == 2)
					{
						temp = 0;
						cout << " " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "	   $";
						if (check==true)
							cout << endl;
					}
					else if (temp == 1)
					{		
						cout << "$ " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "		||";
					}	
					check = true;
				}
			}
		if (check == false)
			cout << "$			<===No pieces yet===>						   $";// << endl;
		cout << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "Player 1" << endl;
		cout << "Buy piece: ";
		cin >> option;

		string str;
		char nmr;
		cout << "Please enter the (row,col) of where you want to place the piece: ";
		cin >> str;
		while (str.length()!=3)
		{
			while (isdigit(str[0]==false) || (str[1]!=',') || (isalpha(str[2]==false || (((str[2]-49)>8) || ((str[2]-49)<0)))))
			{
				cin >> str;
				cout << "===ERROR: The input is incorrect.===" << endl << "       Enter the row, comma then the collumn." << endl << "       Like: 1,a" << endl;
				break;
			}
			break;
		}
		_r = static_cast<int>((str[0]-48));
		nmr = str[2];
		nmr = nmr - 49;
		_c = static_cast<int>(nmr-48);
		if (buyPiece(p,option,_r,_c)==true)
			balance = balance - dmGrid[_r][_c]->getLife();
	}
	balance = 100;
	check = false;
	p = 2;
	//Player 2 buying
	while (balance >= 5)
	{
		temp = 0;
		for (int a=0; a < 40; a++)
			cout << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "$				The Shop						   $" << endl;
		cout << "$ ITEMS:										   $" << endl;
		cout << "$ 1.FootSoldier			R6.00							   $" << endl;
		cout << "$ 2.Knight			R10.00							   $" << endl;
		cout << "$ 3.Phantom			R5.00							   $" << endl;
		cout << "$ 4.Dragon			R18.00							   $" << endl;
		cout << "$ 5.Healer			R6.00							   $" << endl;
		cout << "$ 6.Necromancer			R6.00							   $" << endl;
		cout << "$ 7.Custom			R<Have to input>					   $" << endl;
		cout << "$------------------------------------------------------------------------------------------$" << endl;
		cout << "$ Player " << p << " shopping cart 					[Balance: " << balance << "]		   $" << endl;
		cout << "$											   $" << endl;
		cout << "$ Name:		Coordinates:	Life:           || Name:	Coordinates:	Life:	   $" << endl;
		for (int a = 0; a < 9; a++)
			for (int b = 0; b < 9; b++)
			{
				if (dmGrid[a][b]->getPlayer()==p)
				{
					temp++;
					if (temp == 2)
					{
						temp = 0;
						cout << " " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "	   $";
						if (check==true)
							cout << endl;
					}
					else if (temp == 1)
					{		
						cout << "$ " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "		||";
					}	
					check = true;
				}
			}
		if (check == false)
			cout << "$			<===No pieces yet===>						   $";// << endl;
		cout << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "Player 2" << endl;
		cout << "Buy piece: ";
		cin >> option;

		string str;
		char nmr;
		cout << "Please enter the (row,col) of where you want to place the piece: ";
		cin >> str;
		while (str.length()!=3)
		{
			while (isdigit(str[0]==false) || (str[1]!=',') || (isalpha(str[2]==false || (((str[2]-49)>8) || ((str[2]-49)<0)))))
			{
				cin >> str;
				cout << "===ERROR: The input is incorrect.===" << endl << "       Enter the row, comma then the collumn." << endl << "       Like: 1,a" << endl;
				break;
			}
			break;
		}
		_r = static_cast<int>((str[0]-48));
		nmr = str[2];
		nmr = nmr - 49;
		_c = static_cast<int>(nmr-48);
		if (buyPiece(p,option,_r,_c)==true)
			balance = balance - dmGrid[_r][_c]->getLife();
	}

	//GraveYard holds the dead pieces
	grave = new GraveYard;
	moves = new unsigned*[4];
	for (int i=0; i<4; i++)
	{
		moves[i] = new unsigned[1];
	}
	for (int a = 0; a<9; a++)
	{
		for (int b = 0; b<9 ; b++)
		{
			Backup[a][b] = 0;
			Redo[a][b] = 0;
		}
	}
	saveBoard();
	DisplayBoard();
}




		//==CONSTRUCTOR for board==//
Board::Board()
{
	//Creating default layout
	moves = new unsigned*[4];
	for (int i=0; i<4; i++)
	{
		moves[i] = new unsigned[1];
	}
	option = 2;
	_graveShowHide = 0;
	difficulty = 3;
	for (int i=0; i<COLS; i++)
	{
		dmGrid[1][i] = new FootSoldier(1,1,i);
		dmGrid[7][i] = new FootSoldier(2,7,i);
		dmGrid[2][i] = new Empty(2,i);
		dmGrid[3][i] = new Empty(3,i);
		dmGrid[4][i] = new Empty(4,i);
		dmGrid[5][i] = new Empty(5,i);
		dmGrid[6][i] = new Empty(6,i);
	}
	//Knights
	dmGrid[0][1] = new Knight(1,0,1);
	dmGrid[0][7] = new Knight(1,0,7);
	dmGrid[8][1] = new Knight(2,8,1);
	dmGrid[8][7] = new Knight(2,8,7);
	//Kings
	dmGrid[0][4] = new King(1,0,4);
	dmGrid[8][4] = new King(2,8,4);	
	//Phantoms
	dmGrid[0][2] = new Phantom(1,0,2);
	dmGrid[0][6] = new Phantom(1,0,6);
	dmGrid[8][2] = new Phantom(2,8,2);
	dmGrid[8][6] = new Phantom(2,8,6);
	//Healers
	dmGrid[0][5] = new Healer(1,0,5);
	dmGrid[8][5] = new Healer(2,8,5);
	//Dragons
	dmGrid[0][8] = new Dragon(1,0,8);
	dmGrid[0][0] = new Dragon(1,0,0);
	dmGrid[8][8] = new Dragon(2,8,8);
	dmGrid[8][0] = new Dragon(2,8,0);
	//Necromancers
	dmGrid[0][3] = new Necromancer(1,0,3);
	dmGrid[8][3] = new Necromancer(2,8,3);
	//GraveYard holds the dead pieces
	grave = new GraveYard;
	
	for (int a = 0; a<9; a++)
	{
		for (int b = 0; b<9 ; b++)
		{
			Backup[a][b] = 0;
			Redo[a][b] = 0;
		}
	}
	saveBoard();
	DisplayBoard();
}
		//!=END of constructor=!//

		//==DESTRUCTOR for board==//
Board::~Board()
{
	int tel = 0;
	clean(cleanFrom);
	clean(cleanTo);
	grave->setPointerNull(cleanFrom);
	grave->setPointerNull(cleanTo);	
	for (int r=0; r<9; r++)
	{
		for (int c=0; c<9; c++)
		{
			if (dmGrid[r][c]!=0)
			{
				for (int _r=0; _r<9; _r++)
				{
					for (int _c=0; _c<9; _c++)
					{
						if (Backup[_r][_c] == dmGrid[r][c])
							Backup[_r][_c] = 0;
						if (Redo[_r][_c] == dmGrid[r][c])
							Redo[_r][_c] = 0;			
					}
				}
				if (cleanTo==dmGrid[r][c])
					cleanTo = 0;
				if (cleanFrom==dmGrid[r][c])
					cleanFrom = 0;
				delete dmGrid[r][c];
				dmGrid[r][c] = 0;
				tel++;	
			}
			if (Backup[r][c]!=0)
			{
				if (cleanTo==Backup[r][c])
					cleanTo = 0;
				if (cleanFrom==Backup[r][c])
					cleanFrom = 0;
				delete Backup[r][c];
				Backup[r][c] = 0;
				tel++;
			}	
			if (Redo[r][c]!=0)
			{
				if (cleanTo==Redo[r][c])
					cleanTo = 0;
				if (cleanFrom==Redo[r][c])
					cleanFrom = 0;
				delete Redo[r][c];
				Redo[r][c] = 0;
				tel++;
			}
		}
	}

	if (cleanFrom != 0)
	{
		delete cleanFrom;
		cleanFrom = 0;
		tel++;
	}
	
	if (cleanTo != 0)
	{
		delete cleanTo;
		cleanTo = 0;
		tel++;
	}


	for (int i=0; i<4; i++)
	{
		delete [] moves[i];
		moves[i] = 0;
	}
	delete [] moves;
	moves = 0;


	//cout <<"pieces deleted= " << tel << endl;
	delete grave;
/*
////////////////////////////////////////////////////MEM check
	cout << "			dmGrid" << endl;
	for (int a = 0; a<9; a++)
	{
		for (int b = 0; b<9 ; b++)
		{
			cout << "(" << a << "," << b << ")" << dmGrid[a][b] << "      ";
		}
		cout << endl;
	}

	cout << endl << "			Backup" << endl;
	for (int a = 0; a<9; a++)
	{
		for (int b = 0; b<9 ; b++)
		{
			cout << "(" << a << "," << b << ")" << Backup[a][b] << "      ";
		}
		cout << endl;
	}
	cout << endl << "			Redo" << endl;
	for (int a = 0; a<9; a++)
	{
		for (int b = 0; b<9 ; b++)
		{
			cout << "(" << a << "," << b << ")" << Redo[a][b] << "      ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "		cleanFrom: " << (cleanFrom) << endl;
	cout << "		cleanTo: " << (cleanTo) << endl;
////////////////////////////////////////////////////MEM check
*/
}
		//!=END of destructor=!//


		//==Saves the board's state==//
void Board::saveBoard()
{
	for (int i=0; i<ROWS; i++)
	{
		for (int j=0;j<COLS;j++)
		{
			Backup[i][j] = dmGrid[i][j];
		}
	}	
}
		//!=END of saving=!//

		//==Undo==//
void Board::undo()
{
	clean(cleanTo);
	clean(cleanFrom);
	for (int i=0; i<ROWS; i++)
	{
		for (int j=0;j<COLS;j++)
		{
			Redo[i][j] = dmGrid[i][j];
		}
	}	
	for (int i=0; i<ROWS; i++)
	{
		for (int j=0;j<COLS;j++)
		{
			dmGrid[i][j] = Backup[i][j];
		}
	}	

	DisplayBoard();
}
		//!=END of undo=!//

		//==Redo==//
void Board::redo()
{
	clean(cleanTo);
	clean(cleanFrom);
	for (int i=0; i<ROWS; i++)
	{
		for (int j=0;j<COLS;j++)
		{
			dmGrid[i][j] = Redo[i][j];
		}
	}	

	DisplayBoard();
}
		//!=END of redo=!//

//==Moving a piece==//
bool Board::move(int _player, int _rFrom, int _cFrom, int _rTo, int _cTo)
{
	int p;
	if (_rFrom>8 ||_rFrom<0 ||_cFrom>8 ||_cFrom<0)
	{
		DisplayBoard();
		cout << "===ERROR: The piece you have requested is out of bounds===" << endl;
		return false;
	}
	else if (_rTo>8 ||_rTo<0 ||_cTo>8 ||_cTo<0)
	{
		DisplayBoard();
		cout << "===ERROR: The placement you have requested is out of bounds===" << endl;
		return false;
	}
	else
	{
		if (dmGrid[_rFrom][_cFrom]->getPlayer()==_player)
		{
			if (dmGrid[_rTo][_cTo]->getPlayer()==_player)
			{
				//If player attacks own piece
				DisplayBoard();
				cout << "===ERROR: Not allowed to move to your own piece===" << endl;
				return false;
			}
			else if (dmGrid[_rTo][_cTo]->getPlayer()==0)				
			{
				//Moves to open spot
				return moveToOpen(_player,_rFrom,_cFrom,_rTo,_cTo);
			}
			else
			{
				//Piece fights
				dmGrid[_rFrom][_cFrom]->attack();
				grave->appendGrave(*dmGrid[_rTo][_cTo]);
				if (dmGrid[_rTo][_cTo]->isKing()==true)
				{
					//Takes opponents king
					//clean(cleanTo);
					p = dmGrid[_rFrom][_cFrom]->getPlayer();
					moveToOpen(_player,_rFrom,_cFrom,_rTo,_cTo);
					//cleanTo = dmGrid[_rTo][_cTo];
					//dmGrid[_rTo][_cTo] = new Empty(_rTo,_cTo);
					gameOver(p);
				}

				else if (dmGrid[_rFrom][_cFrom]->getLife()<=0)
				{
					//Piece dies because of attacking with low life
					if (dmGrid[_rFrom][_cFrom]->isKing()==true) 
					{
						//Attacking player loses because his king attacked with low life
						clean(cleanTo);
						clean(cleanFrom);
						p = dmGrid[_rFrom][_cFrom]->getPlayer();
						cleanFrom = dmGrid[_rFrom][_cFrom];
						dmGrid[_rFrom][_cFrom] = new Empty(_rTo,_cTo);
						cleanTo = dmGrid[_rTo][_cTo];	
						dmGrid[_rTo][_cTo] = new Empty(_rTo,_cTo);
						if (p==1)
							p = 2;
						else p = 1;	
						gameOver(p);
					}
					else
					{
						//Attacking player loses a piece because of attacking with low health
						moveToOpen(_player,_rFrom,_cFrom,_rTo,_cTo);
						clean(cleanTo);
						clean(cleanFrom);
						cleanTo = dmGrid[_rTo][_cTo];
						dmGrid[_rTo][_cTo] = new Empty(_rTo,_cTo);
						cleanFrom = dmGrid[_rFrom][_cFrom];
						dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
						DisplayBoard();
					}
				}
				else 
				{
					moveToOpen(_player,_rFrom,_cFrom,_rTo,_cTo);
				}
				return true;
			}
		}	
		else 
		{
			DisplayBoard();
			cout << "===ERROR: Not allowed to move that piece because you don't have control over it===" << endl;
			return false;
		}
	}
	return false;
}
		//!=END of move=!//

////////////////////========================================================================================================================================================================
		//==Moves a piece to an open destination==//
bool Board::moveToOpen(int _player, int _rFrom, int _cFrom, int _rTo, int _cTo)
{	
	//clean(cleanTo);
	//clean(cleanFrom);
	
	
	char a = dmGrid[_rFrom][_cFrom]->getChar();
	if (a=='F')
	{
		//moves footSoldier
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];
			dmGrid[_rTo][_cTo] = new FootSoldier(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: Footsoldiers may only move up to 2 squares in any direction===" << endl;
		return false;
	}
	else if (a=='K')
	{
		//moves Knight
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];
			dmGrid[_rTo][_cTo] = new Knight(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: Knights may only move in a L path consisting of 3 squares===" << endl;
		return false;
	}
	else if (a=='X')
	{
		//moves King
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];
			dmGrid[_rTo][_cTo] = new King(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: The king may only move 3 squares in any direction===" << endl;
		return false;
	}
	else if (a=='P')
	{
		//moves Phantom
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];
			dmGrid[_rTo][_cTo] = new Phantom(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: Phantoms may only move 2 squares in any direction===" << endl;
		return false;
	}
	else if (a=='H')
	{
		//moves Healer
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];;
			dmGrid[_rTo][_cTo] = new Healer(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: Healers may only move on diagonals for a max of 5 squares===" << endl;
		return false;
	}
	else if (a=='D')
	{
		//moves Dragon
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];
			dmGrid[_rTo][_cTo] = new Dragon(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: Dragons may only move horizontally or vertically to a max of 3 squares===" << endl;
		return false;
	}
	else if (a=='N')
	{
		//moves Necromancer
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];
			dmGrid[_rTo][_cTo] = new Necromancer(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: Necromancers may only move one square in any direction===" << endl;
		return false;
	}
	else if (a=='*')
	{
		//moves Custom
		if (dmGrid[_rFrom][_cFrom]->checkMove(_rTo,_cTo))
		{
			clean(cleanTo);
			clean(cleanFrom);
			if (dmGrid[_rTo][_cTo]->isKing()) 
				gameOver((dmGrid[_rFrom][_cFrom]->getPlayer()));
			cleanTo = dmGrid[_rTo][_cTo];
			dmGrid[_rTo][_cTo] = new Custom(_player,_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
			cleanFrom = dmGrid[_rFrom][_cFrom];
			dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
			DisplayBoard();
			return true;
		}
		DisplayBoard();
		cout << "===ERROR: Custom pieces have their own rules=== " << endl;
		return false;
	}
	return false;
}
		//!=End of move to open=!//	

		//==Cast a spell with a Piece==//
void Board::Spell()
{
	string str;
	char nmr;
	int _rFrom,_cFrom, _rTo, _cTo;
	cout << "       Please enter the (row,col) of the spellcaster you want to use:" << endl << "       ";
	cin >> str;
	while (str.length()!=3)
	{
		while (isdigit(str[0]==false) || (str[1]!=',') || (isalpha(str[2]==false || (((str[2]-49)>8) || ((str[2]-49)<0)))))
		{
			cin >> str;
			cout << "       ===ERROR: The input is incorrect.===" << endl << "       Enter the row, comma then the collumn." << endl << "       Like: 1,a" << endl;
		}
		cout << "       ===ERROR: The input is incorrect.===" << endl << "       Must contain 3 characters." << endl << "       Like 1,a" << endl;
	}
	_rFrom = static_cast<int>((str[0]-48));
	nmr = str[2];
	nmr = nmr - 49;
	_cFrom = static_cast<int>(nmr-48);
	if (dmGrid[_rFrom][_cFrom]->isSpellCaster()==true)
	{
		cout << "       Please enter the (row,col) of the piece you want to cast the " << dmGrid[_rFrom][_cFrom]->SpellType() << " spell on:" << endl << "       ";
		cin >> str;
		while (str.length()!=3)
		{
			while (isdigit(str[0]==false) || (str[1]!=',') || (isalpha(str[2]==false || (((str[2]-49)>8) || ((str[2]-49)<0)))))
			{
				cin >> str;
				cout << "       ===ERROR: The input is incorrect.===" << endl << "       Enter the row, comma then the collumn." << endl << "       Like: 1,a" << endl;
			}
			cout << "       ===ERROR: The input is incorrect.===" << endl << "       Must contain 3 characters." << endl << "       Like 1,a" << endl;
		}
		_rTo = static_cast<int>(str[0]-48);
		nmr = str[2];
		nmr = nmr - 49;
		_cTo = static_cast<int>(nmr-48);
		if ((dmGrid[_rFrom][_cFrom]->getChar())=='H')
		{
			//Cast spell with HEALER
			if ((dmGrid[_rFrom][_cFrom]->getPlayer())==(dmGrid[_rTo][_cTo]->getPlayer())||((dmGrid[_rTo][_cTo]->getChar())!=' '))
			{
				if ((dmGrid[_rFrom][_cFrom]->CastSpell(*dmGrid[_rTo][_cTo]))==true)
				{
					DisplayBoard();
					cout << "       ===Successfully healed===" << endl;
				}
				else
				{
					DisplayBoard();
					cout << "       ===The piece is not in range===" << endl;
				}
			}
			else 
			{
				DisplayBoard();
				cout << "       ===Can only heal friendly units===" << endl;
			}
		}
		else if ((dmGrid[_rFrom][_cFrom]->getChar())=='D')
		{
			//Cast spell with Dragon
			if ((dmGrid[_rFrom][_cFrom]->getPlayer())!=(dmGrid[_rTo][_cTo]->getPlayer())||((dmGrid[_rTo][_cTo]->getChar())!=' '))
			{
				if ((dmGrid[_rFrom][_cFrom]->CastSpell(*dmGrid[_rTo][_cTo]))==true)
				{
					DisplayBoard();
					cout << "       ===Successfully spat with fire===" << endl;
					if (dmGrid[_rTo][_cTo]->getLife()<=0)
					{
						if (dmGrid[_rTo][_cTo]->isKing()) 
							gameOver(dmGrid[_rFrom][_cFrom]->getPlayer());
						else
						{
							clean(cleanTo);
							cleanTo = dmGrid[_rTo][_cTo];
							dmGrid[_rTo][_cTo] = new Empty(_rTo,_cTo);
							DisplayBoard();
							cout << "       ===Successfully spat with fire===" << endl;
						}
					}
				}
				else
				{
					DisplayBoard();
					cout << "       ===The piece is not in range===" << endl;
				}
			}
			else 
			{
				DisplayBoard();
				cout << "       ===Can only attack enemy units===" << endl;
			}
		}

		else if ((dmGrid[_rFrom][_cFrom]->getChar())=='P')
		{
			//Cast spell with Phantom
			if (dmGrid[_rTo][_cTo]->getChar()==' ')
			{
				if ((dmGrid[_rFrom][_cFrom]->CastSpell(*dmGrid[_rTo][_cTo]))==true)
				{
					clean(cleanFrom);
					clean(cleanTo);
					cleanTo = dmGrid[_rTo][_cTo];
					dmGrid[_rTo][_cTo] = new Phantom(dmGrid[_rFrom][_cFrom]->getPlayer(),_rTo,_cTo, dmGrid[_rFrom][_cFrom]->getLife());
					clean(cleanFrom);
					dmGrid[_rFrom][_cFrom] = new Empty(_rFrom,_cFrom);
					DisplayBoard();
					cout << "       ===Successfully teleported===" << endl;
					if (dmGrid[_rTo][_cTo]->getLife()<=0)
					{
						clean(cleanTo);
						cleanTo = dmGrid[_rTo][_cTo];
						dmGrid[_rTo][_cTo] = new Empty(_rTo,_cTo);
						DisplayBoard();
						cout << "       ===Teleported too far===" << endl;
					}
				}
				else
				{
					DisplayBoard();
					cout << "       ===The destination is not in range===" << endl;
				}
			}
			else 
			{
				DisplayBoard();
				cout << "       ===Can only teleport to open block's===" << endl;
			}
		}	


		else if ((dmGrid[_rFrom][_cFrom]->getChar())=='N')
		{
			//Cast spell with Necromancer
			if (dmGrid[_rTo][_cTo]->getChar()!=' ')
			{
				if ((dmGrid[_rFrom][_cFrom]->CastSpell(*dmGrid[_rTo][_cTo]))==true)
				{
					Piece *temp;
					temp = (grave->getReplacement(dmGrid[_rTo][_cTo],(dmGrid[_rFrom][_cFrom]->getPlayer())));
					clean(cleanTo);
					cleanTo = dmGrid[_rTo][_cTo]; 
					dmGrid[_rTo][_cTo] = temp;
					clean(temp);
					DisplayBoard();
					cout << "       ===Successfully resurrected===" << endl;
				}
				else
				{
					DisplayBoard();
					cout << "       ===Requested piece is out of range===" << endl;
				}
			}
			else 
			{
				DisplayBoard();
				cout << "       ===Only allowed to use resurrect on a piece on the board===" << endl;
			}
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if ((dmGrid[_rFrom][_cFrom]->getChar())=='*')
		{
			//Cast spell with CUSTOM
			//HEALER
			if (dmGrid[_rFrom][_cFrom]->getSpellChar()=='2')
			{
				if ((dmGrid[_rFrom][_cFrom]->getPlayer())==(dmGrid[_rTo][_cTo]->getPlayer())||((dmGrid[_rTo][_cTo]->getChar())!=' '))
				{
					if ((dmGrid[_rFrom][_cFrom]->CastSpell(*dmGrid[_rTo][_cTo]))==true)
					{
						DisplayBoard();
						cout << "       ===Successfully healed===" << endl;
					}
					else
					{
						DisplayBoard();
						cout << "       ===The piece is not in range===" << endl;
					}
				}
				else 
				{
					DisplayBoard();
					cout << "       ===Can only heal friendly units===" << endl;
				}
			}
			//Fire
			else if (dmGrid[_rFrom][_cFrom]->getSpellChar()=='1')
			{
				if ((dmGrid[_rFrom][_cFrom]->getPlayer())!=(dmGrid[_rTo][_cTo]->getPlayer())||((dmGrid[_rTo][_cTo]->getChar())!=' '))
				{
					if ((dmGrid[_rFrom][_cFrom]->CastSpell(*dmGrid[_rTo][_cTo]))==true)
					{
						DisplayBoard();
						cout << "       ===Successfully spat with fire===" << endl;
						if (dmGrid[_rTo][_cTo]->getLife()<=0)
						{
							if (dmGrid[_rTo][_cTo]->isKing()) 
								gameOver(dmGrid[_rFrom][_cFrom]->getPlayer());
							else
							{
								clean(cleanTo);
								cleanTo = dmGrid[_rTo][_cTo]; 
								dmGrid[_rTo][_cTo] = new Empty(_rTo,_cTo);
								DisplayBoard();
								cout << "       ===Successfully spat with fire===" << endl;
							}
						}
					}
				else
				{
					DisplayBoard();
					cout << "       ===The piece is not in range===" << endl;
				}
			}
			else 
			{
				DisplayBoard();
				cout << "       ===Can only attack enemy units===" << endl;
			}
			}
		}


	}
	else 
	{
		DisplayBoard();
		cout << "       ===That is not a spellcaster===" << endl;
	}
}
		//==End of cast==//

void Board::DisplayBoard()
{
	int temp;
	temp = 4;

	if (option==1)
	{
		//Displays the grid and stats.
		for (int i=0; i<40 ;i++)
			cout << endl;
		cout << "********************************************************************************************" << endl;
		cout << "*      				---Player ONE stats---                                     *" << endl;
		cout << "* Name:		Coordinates:	Life:           || Name:	Coordinates:	Life:	   *" << endl;
		for (int a = 0; a < 9; a++)
			for (int b = 0; b < 9; b++)
			{
				if (dmGrid[a][b]->getPlayer()==1)
				{
					temp++;
					if ((temp % 2) == 1)
					{
						if (temp>5)
							cout << endl;
						cout << "* " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "		||";
					}
					else if ((temp % 2) == 0)
					{	
						cout << " " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "	   *";

					}	
				}
			}
		if ( temp % 2 == 1 )
			cout << "					   *";
		cout << endl << "********************************************************************************************" << endl;
		cout << "*		     a    b    c    d    e    f    g    h    i				   *" << endl;
		cout << "*		   ..............................................			   *" << endl;
		int rows = 9;
		for (int countR = 0; countR < rows;countR++)
		{
			cout << "*		 " << countR << " |";
			for (int countC = 0; countC < 9 ; countC++)
			{
				if (dmGrid[countR][countC])
				{
					cout << " " << dmGrid[countR][countC]->getPieceID() << " |";
				}
			}
			cout << "			   *";
			cout << endl << "* 		   ----------------------------------------------			   *" << endl;
		}
		cout << "********************************************************************************************" << endl;
		cout << "*      				---Player TWO stats---                                     *" << endl;
		cout << "* Name:		Coordinates:	Life:           || Name:	Coordinates:	Life:	   *" << endl;
		temp = 4;
		for (int a = 0; a < 9; a++)
			for (int b = 0; b < 9; b++)
			{
				if (dmGrid[a][b]->getPlayer()==2)
				{
					temp++;
					if ((temp % 2) == 1)
					{
						if (temp>5)
							cout << endl;
						cout << "* " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "		||";
					}
					else if ((temp % 2) == 0)
					{	
						cout << " " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "	   *";
					}	
				}
			}
		if ( temp % 2 == 1 )
			cout << "					   *";
		cout << endl << "********************************************************************************************" << endl;
		if (_graveShowHide==1)
			cout << grave;
		//End of option 1
	}
	else if (option==2)
	{
		//Displays only the grid.
		for (int i=0; i<40 ;i++)
			cout << endl;
		cout << endl << "********************************************************************************************" << endl;
		cout << "*	 	     a    b    c    d    e    f    g    h    i				   *" << endl;
		cout << "*		   ..............................................			   *" << endl;
		int rows = 9;
		for (int countR = 0; countR < rows;countR++)
		{
			cout << "*		 " << countR << " |";
			for (int countC = 0; countC < 9 ; countC++)
			{
				if (dmGrid[countR][countC])
				{
					cout << " " << dmGrid[countR][countC]->getPieceID() << " |";
				}
			}
			cout << "			   *";
			cout << endl << "* 		   ----------------------------------------------			   *" << endl;
		}
		cout << "***********************************************************************************************" << endl;
		if (_graveShowHide==1)
			cout << grave;
		
	}
	else if (option==3)
	{
		//Displays only the stats.
		for (int i=0; i<40 ;i++)
			cout << endl;
		cout << "********************************************************************************************" << endl;
		cout << "*      				---Player ONE stats---                                     *" << endl;
		cout << "* Name:		Coordinates:	Life:           || Name:	Coordinates:	Life:	   *" << endl;
		for (int a = 0; a < 9; a++)
			for (int b = 0; b < 9; b++)
			{
				if (dmGrid[a][b]->getPlayer()==1)
				{
					temp++;
					if ((temp % 2) == 1)
					{
						if (temp>5)
							cout << endl;
						cout << "* " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "		||";
					}
					else if ((temp % 2) == 0)
					{	
						cout << " " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "	   *";
					}	
				}
			}
		if ( temp % 2 == 1 )
			cout << "					   *";
		cout << endl << "********************************************************************************************" << endl;
		cout << "*      				---Player TWO stats---                                     *" << endl;
		cout << "* Name:		Coordinates:	Life:           || Name:	Coordinates:	Life:	   *" << endl;
		temp = 4;
		for (int a = 0; a < 9; a++)
			for (int b = 0; b < 9; b++)
			{
				if (dmGrid[a][b]->getPlayer()==2)
				{
					temp++;
					if ((temp % 2) == 1)
					{
						if (temp>5)
							cout << endl;
						cout << "* " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "		||";
					}
					else if ((temp % 2) == 0)
					{	
						cout << " " << dmGrid[a][b]->getName() << "	";
						cout << a << "," << static_cast<char>(b+97) << "		";
						cout << dmGrid[a][b]->getLife() << "	   *";
					}	
				}
			}
		if ( temp % 2 == 1 )
			cout << "					   *";
		cout << endl << "********************************************************************************************" << endl;
		if (_graveShowHide==1)
			cout << grave;
	}
}


		//==Game-Over msg==//
void Board::gameOver(int _p)
{
	for (int i=0; i<40 ;i++)
		cout << endl;

	cout << "                 GAME OVER"                   << endl;
	cout << "                               |` \/ \/ \,', "<< endl;
	cout << "                              ;          ` \/\,. "<< endl;
	cout << "                             :               ` \,/ "<< endl;
	cout << "       PLAYER "<<_p<<"              |                  / "<< endl;
	cout << "            WON            ;                 : "<< endl;
	cout << "                            :                  ; "<< endl;
	cout << "                            |      ,---.      / "<< endl;
	cout << "                           :     ,'     `,-._ \ "<< endl;
	cout << "                           ;    (   o    \   `' "<< endl;
	cout << "                         _:      .      ,'  o ; "<< endl;
	cout << "                        /,.`      `.__,'`-.__, "<< endl;
	cout << "                        \_  _               \ "<< endl;
	cout << "                       ,'  / `,          `.,' "<< endl;
	cout << "                 ___,'`-._ \_/ `,._        ; "<< endl;
	cout << "              __;_,'      `-.`-'./ `--.____) "<< endl;
	cout << "           ,-'           _,--\^-' "<< endl;
	cout << "         ,:_____      ,-'     \ "<< endl;
	cout << "        (,'     `--.  \;-._    ; "<< endl;
	cout << "        :    Y      `-/    `,  : "<< endl;
	cout << "        :    :       :     /_;' "<< endl;
	cout << "        :    :       |    : "<< endl;
	cout << "         \    \      :    : "<< endl;
	cout << "          `-._ `-.__, \    `. "<< endl;
	cout << "             \   \  `. \     `. "<< endl;
	cout << "           ,-;    \---)_\ ,','/ "<< endl;
	cout << "           \_ `---'--''' ,'^-;' "<< endl;
	cout << "           (_`     ---''' ,-') "<< endl;
	cout << "           / `--.__,. ,-'    \ "<< endl;
	cout << "           )-.__,-- ||___,--' `-. "<< endl;
	cout << "          /._______,|__________,'\ "<< endl;
	cout << "          `--.____,'|_________,-' " << endl;
}
		//!=END of game-over=!//














