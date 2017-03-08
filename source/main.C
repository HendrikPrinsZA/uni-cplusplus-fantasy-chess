#include <iostream>
#include "Game.h"
#include <cctype>
#include <cstring>
//#include <fstream>
//#include <cstdlib>

using namespace std;

int main()
{
	Game *Check;
	Check = 0;
	char menu;
	menu = 'a';
	/*const int SIZE_MAIN = 81;
	const unsigned TIME_MAIN = 33333333;
	char input[SIZE_MAIN];
	ifstream inFile;
	unsigned random;
	random = 0;
	string sLyn;
	sLyn = "|";



	inFile.open("think1.txt");
	if (inFile)
	{
		for (unsigned u = 0; u < 50; u++)
		{
			cout << endl;
		}
		while (!inFile.eof())
		{
			inFile.getline(input,SIZE_MAIN);
			cout << "	" << input << endl;
		}
		cout << "		   Thinking." << endl;
		for (unsigned u = 0; u < TIME_MAIN; u++)
		{
			random = rand();
		}		
	}
	inFile.close();

	inFile.open("think2.txt");
	if (inFile)
	{
		for (unsigned u = 0; u < 50; u++)
		{
			cout << endl;
		}
		while (!inFile.eof())
		{
			inFile.getline(input,SIZE_MAIN);
			cout << "	" << input << endl;

		}
		cout << "		   Thinking.." << endl;
		for (unsigned u = 0; u < TIME_MAIN; u++)
		{
			random = rand();
		}		
	}
	inFile.close();	

	inFile.open("think3.txt");
	if (inFile)
	{
		for (unsigned u = 0; u < 50; u++)
		{
			cout << endl;
		}
		while (!inFile.eof())
		{
			inFile.getline(input,SIZE_MAIN);
			cout << "	" << input << endl;

		}
		cout << "		   Thinking..." << endl;
		for (unsigned u = 0; u < TIME_MAIN; u++)
		{
			random = rand();
		}		
	}
	inFile.close();	*/	

	while (menu!='0')
	{
		for (int a=0;a<40; a++)
			cout << endl;
		cout << "####################################################" << endl;
		cout << "#						   #" << endl;
		cout << "#		   C C C C C 			   #" << endl;
		cout << "#   FANTASY	C	     C			   #" << endl;
		cout << "#	      C		       C		   #" << endl;
		cout << "#	    C					   #" << endl;
		cout << "#	  C					   #" << endl;
		cout << "#	C					   #" << endl;
		cout << "#	C	H    H  EEEE   sSSS   sSSS	   #" << endl;
		cout << "#	C	H    H  E     S    ' S    '	   #" << endl;
		cout << "#	C	HhhhhH  Eee    SSs    SSs	   #" << endl;
		cout << "#	C	H    H  E     .   S  .   S	   #" << endl;
		cout << "#	C	H    H  EEEE   SSS    SSS          #" << endl;
		cout << "#	C					   #" << endl;
		cout << "#	  C					   #" << endl;
		cout << "#	    C		     C			   #" << endl;
		cout << "#	      C		   C	     created by	   #" << endl;
		cout << "#		C C C C C	<Hendrik Prinsloo> #" << endl;
		cout << "#				                   #" << endl;
		cout << "#--------------------------------------------------#" << endl;
		cout << "#                    Gametype                      #" << endl;
		cout << "#	0. Quit				  	   #" << endl;
		cout << "#	1. Quickstart	 			   #" << endl;
		cout << "#	2. Buy pieces and the start		   #" << endl;
		cout << "####################################################" << endl << "	Decision: ";
		cin >> menu;
		
		switch (menu)
		{
			case '0':
				break;
			case '1':
				Check = new Game;
				break;
			case '2': 
				Check = new Game(1);
				break;
			default:
				cout << "NO CHOICE MADE" << endl;
				break;
		}
	}
	if (Check != 0)
	{
		delete Check;
	}
			

	return 0;
}
