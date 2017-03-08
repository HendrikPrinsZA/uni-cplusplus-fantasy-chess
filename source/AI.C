#include "Board.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>


bool Board::defend(int _p, int _row, int _col)
{
	bool done;
	done = false;
	for (int r=0; r<9; r++)
	{
		if (done==false)
		for (int c=0; c<9; c++)
		{
			if (done == false)
			if (dmGrid[r][c]->getPlayer()==_p)
				if (dmGrid[r][c]->checkMove(_row,_col)==true)
				{
					move(_p,r,c,_row,_col);
					done = true;
					return true;
				}
		}
	}
	return false;
			
}

void Board::stalling()
{
	const int _SIZE = 81;
	const unsigned TIME = 33333333;
	char input[_SIZE];
	ifstream inFile;
	unsigned random;
	random = 0;
	string sLyn;
	sLyn = "|";

	for (unsigned a = 0; a < 50; a++)
	{
		cout << "	      " << " ____________________________________________________" << endl;
		cout << "	      " << "|                        " << setw(3) << right << ((a+1)*2) << "%                        |" << endl;
		cout << "	      |="<< setw(50) << left << sLyn   << "=|" << endl;
		cout << "	      " << "|____________________________________________________|" << endl;
		for (unsigned u = 0; u < 900000; u++)
		{
			random = rand();
		}	
		DisplayBoard();
		sLyn = sLyn +"|";
		
	} 
}


void Board::displayAImsg()
{
	cout << "Computer moved to " << moves[countMoves-1][0] << "," << static_cast<char>(moves[countMoves-1][1]+97);
	cout << " with the " << dmGrid[moves[countMoves-1][0]][moves[countMoves-1][1]]->getName() << endl;
}


bool Board::checkMoves(int _row, int _col)
{
	for (int i=0; i<4; i++)
	{
		if ((moves[i][0]==_row) && (moves[i][1]==_col))
		{
			return false;
		}
	}
	return true;	
}


void Board::startAI(int _p,int diff)
{
	bool moved;
	moved = false;
	int enemy;
	int range,temp;

	if (countMoves == 3)
	{
		countMoves = 0;
	}

	temp = 0;
	if (_p==1)
		enemy = 2;
	else enemy = 1;

	int KingR,KingC;
	for (int row=0; row<9; row++)
	{
	  	for (int col=0; col<9; col++)
	      	{
	         	//If the piece belongs to the player
		 	if (dmGrid[row][col]->getPlayer() == enemy)
		 	{	
				if (dmGrid[row][col]->isKing()==true)
				{			   		
					KingR = row;
					KingC = col;
	}	}	}	}
	//Found the enemy's king

	///////Take king 1st
	if (moved==false)
	for (int row=0; row<9; row++)
	{
	   	if (moved==false)
	   	for (int col=0; col<9; col++)
	      	{
			if (moved==false)
	        	 //If the piece belongs to the player
		 	if (dmGrid[row][col]->getPlayer() == _p)
		 	{
				if (moved==false)
			   	for (int aRow = row - diff; aRow < row + diff; aRow++)
					if (moved==false)
			      		for (int aCol = col - diff; aCol < col + diff; aCol++)
			 		{
						if (aRow>0 && aCol>0 && aRow<9 && aCol <9)
							if (dmGrid[aRow][aCol]->getPlayer() == enemy)
							{
								if (dmGrid[aRow][aCol]->isKing() == true)
								{
									move(_p,row,col,aRow,aCol);
									moved = true;
									moves[countMoves][0] = aRow;
									moves[countMoves][1] = aCol;
									countMoves++;
								}  
							}
					}
			}
	     	}
	}
	////////////END OF taking king


	///King's threatening
	if (moved==false)
	{
		for (int row=0; row<9; row++)
		{
			if (moved==false)
	   		for (int col=0; col<9; col++)
	      		{
				if (moved == false)
	         		//If the piece belongs to the player
				if (dmGrid[row][col]->getPlayer() == _p)
		 		{
		     			//Get the coordinates of the player's king
		     			if (dmGrid[row][col]->isKing())
		     			{
			   			for (int aRow = row - 3; aRow < row + 3; aRow++)
							if (moved==false)
			      				for (int aCol = col - 3; aCol < col + 3; aCol++)
			 				{
								if (aRow>-1 && aCol>-1 && aRow<9 && aCol <9)
									if (dmGrid[aRow][aCol]->getPlayer() == enemy)
									{	
										if (moved==false)
										if (defend(_p,aRow,aCol)==true)
										{
											moves[countMoves][0] = aRow;
											moves[countMoves][1] = aCol;
											countMoves++;
											moved = true;
										}
									}	
							}
					}
				}
			}
		}
	}
	////////////END OF king's threatening

	///If no move has been made to defend the king
	if (moved==false)
	{
		for (int row=0; row<9; row++)
		{
	  		for (int col=0; col<9; col++)
	      		{
				if (checkMoves(row,col))
	         		//If the piece belongs to the player
		 		if (dmGrid[row][col]->getPlayer() == _p)
		 		{
			   		for (int aRow = row - 3; aRow < row + 3; aRow++)
						if (moved == false)
			      			for (int aCol = col - 3; aCol < col + 3; aCol++)
			 			{
							if (moved == false)
							if (aRow>-1 && aCol>-1 && aRow<9 && aCol <9)
								if (dmGrid[aRow][aCol]->getPlayer() == enemy)
								{
									if (moved==false)
									if (defend(_p,aRow,aCol)==true)
									{
										moves[countMoves][0] = aRow;
										moves[countMoves][1] = aCol;
										countMoves++;
										moved = true;
									}
								}
		     				}
		     				
	         		}
	     		}
		}
	}
	////////////End of random defence
	int tempR1,tempC1,tempR2,tempC2;
		tempR1 = 0;
		tempC1 = 0;
		tempR2 = 0;
		tempC2 = 0;
	//Move towards king
	if (moved==false)
	{
		range = 18;
		double moveR,moveC;
		//Get the piece that can come the closest to the king
		for (int row=0; row<9; row++)
		{
	  		for (int col=0; col<9; col++)
	      		{
		 		if (dmGrid[row][col]->getPlayer() == _p)
		 		{	
					if (checkMoves(row,col))
					for (int aRow = row - diff; aRow < row + diff; aRow++)
			      			for (int aCol = col - diff; aCol < col + diff; aCol++)
			 			{
							if (moved == false)
							if (aRow>-1 && aCol>-1 && aRow<9 && aCol <9)
								if (dmGrid[row][col]->isKing()==false)
								if (dmGrid[aRow][aCol]->getPlayer() != _p)
								{
									if (dmGrid[row][col]->checkMove(aRow,aCol)==true)
									{
										moveR = abs(static_cast<double>(aRow-KingR));
										moveC = abs(static_cast<double>(aCol-KingC));
										temp = moveR + moveC;
										if (temp<range)
										{
											range = temp;
											tempR1 = row;
											tempC1 = col;
											tempR2 = aRow;
											tempC2 = aCol;
										}
									}	
								}	   		
		     				}			
	         		}
	    		}
		}
	}
	if (moved==false)
	if (move(_p,tempR1,tempC1,tempR2,tempC2)==true)
	{
		moves[countMoves][0] = tempR2;
		moves[countMoves][1] = tempC2;
		countMoves++;
		moved = true;
	}
}
