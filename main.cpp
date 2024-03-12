/*********************************************************************
** Program Filename: main.cpp
** Author: Sarah Satchell
** Date: 11/29/2023
** Description: Gets user input to start the game
** Input: Width of board, length of board and play in cheat mode.
** Output: n/a
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	srand(time(NULL));
	int width = 0, lenth = 0;
	bool debug = false;
	string dbg;
	bool x = true;
	bool y = true;
	Game g;
	// error handling
	while(x){ 							
		while(y){						
			cout << "Enter width (4-50): " ; 
			cin >> width;
			cout << "Enter length (4-50): " ;
			cin >> lenth;
			if(width <= 50 && lenth <= 50&& width >= 4 && lenth >= 4 ){
				y = false;
			} else{
				cout << "Invalid input." << endl;
			}
		}
		cout << "Debug mode? Enter 'true' or 'false': ";
		cin >> dbg;
		if(dbg == "true"){
			debug = true;
			x = false;
		} else if(dbg == "false"){
			debug = false;
			x = false;
		} else {
			cout << "Invalid." << endl;
		}
	}
	g.play_game(width, lenth, debug);
	
		
		
	return 0;
}