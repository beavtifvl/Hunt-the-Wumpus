/*********************************************************************
** Program Filename: game.cpp
** Author: Sarah Satchell
** Date: 11/29/2023
** Description: Implementation of the game functions
** Input: User input, game setup parameters
** Output: Game board, game state messages
*********************************************************************/
#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "event.h"

#include <iostream>

using namespace std;

// Game Implementation

Game::Game() {
    // Game constructor
    // Initialize game variables and set default values
    roomArr.clear();
    col = 0;
    row = 0;
    num_arrows = 0;
    debug_view = false;

    // Counters for various events
    wumpusCounter = 0;
    batsCounter = 0;
    stalCounter = 0;
    goldCounter = 0;
    batRounds = 0;

    // Flags for game state
    wumpWarp = true;
    hasWon = false;
    hasLost = false;
    hasGold = false;
    hasBats = false;

    advPos = nullptr;
    startPos = nullptr;
    wumpusPos = nullptr;

    sameSettingBool = false;
}

Game::~Game() {
    // Game destructor
    // Deallocate memory and clear game data
    if (advPos != nullptr) {
        delete advPos;
        cout << "game destroyed" << endl;
    }

    if (startPos != nullptr) {
        delete startPos;
        cout << "start position destroyed" << endl;
    }

    if (wumpusPos != nullptr) {
        delete wumpusPos;
        cout << "wumpus destroyed" << endl;
    }

    advPos = nullptr;
    startPos = nullptr;
    wumpusPos = nullptr;

    for (int i = 0; i < roomArr.size(); i++) {
        roomArr[i].clear();
    }
    roomArr.clear();
}

void Game::set_up(int l, int w) {
    // Set up the game with specified dimensions
    col = l;
    row = w;
    num_arrows = 3; // Start with 3 arrows

    // Create a 2D vector to represent the game rooms
    for (int i = 0; i < row; i++) {
        vector<Room> row_vec;
        for (int j = 0; j < col; j++) {
            row_vec.push_back(Room(i, j));
        }
        roomArr.push_back(row_vec);
    }

    // Place events in the game
    placeEvents(new Wumpus);
    placeEvents(new Bats);
    placeEvents(new Bats);
    placeEvents(new Stalactites);
    placeEvents(new Stalactites);
    placeEvents(new Gold);
    placePlayer();
}

void Game::placeEvents(Event* e) {
    // Place events in random rooms
    int temprow = 0;
    int tempcol = 0;
    do {
        temprow = rand() % row;
        tempcol = rand() % col;
    } while (roomArr.at(temprow).at(tempcol).getEventptr() != nullptr);

    roomArr.at(temprow).at(tempcol).setEvent(e);
    // Update the position of the Wumpus if placed
    if (roomArr.at(temprow).at(tempcol).getEventptr()->eventType() == 'W') {
        delete wumpusPos;
        wumpusPos = nullptr;
        wumpusPos = new Room(temprow, tempcol);
    }
}

void Game::placePlayer() {
    // Place the player in a random room
    int temprow = 0;
    int tempcol = 0;
    do {
        temprow = rand() % row;
        tempcol = rand() % col;
    } while (roomArr.at(temprow).at(tempcol).getEventptr() != nullptr);

    roomArr.at(temprow).at(tempcol).set_hasPlayer(true);
    roomArr.at(temprow).at(tempcol).set_StartRoom(true);
    advPos = new Room(temprow, tempcol);
    startPos = new Room(temprow, tempcol);
}

void Game::set_advPos(Room* advPosi) {
    // Set the player's position
    if (wumpusPos != nullptr) {
        delete wumpusPos;
    }
    advPos = advPosi;
}

void Game::set_startPos(Room* startPosi) {
    // Set the starting position
    if (startPos != nullptr) {
        delete startPos;
    }
    startPos = startPosi;
}

void Game::set_wumpPos(Room* wump) {
    // Set the Wumpus's position
    if (wumpusPos != nullptr) {
        delete wumpusPos;
    }
    wumpusPos = wump;
}

// Display the game board
void Game::display_game() const {
    cout << endl << endl;
    string line = "";
    for (int i = 0; i < col; ++i) {
        line += "------";
    }
    for (int i = 0; i < row; ++i) {
        cout << line << endl;
        cout << "||";
        for (int j = 0; j < col; ++j) {
            // Display the player, events, and other elements on the game board
            if (roomArr.at(i).at(j).get_hasPlayer()) {
                cout << " ";
                roomArr.at(i).at(j).printPlayer();
            } else if (roomArr.at(i).at(j).getEventptr() != nullptr && debug_view) {
                cout << " ";
                roomArr[i][j].getEventptr()->print();
            } else if ((i == startPos->get_row()) && (j == startPos->get_col()) &&
                       !roomArr.at(i).at(j).get_hasPlayer() && debug_view) {
                cout << " ~";
            } else if (roomArr.at(i).at(j).getEventptr() == nullptr ||
                       (roomArr.at(i).at(j).getEventptr() != nullptr && !debug_view)) {
                cout << "  ";
            }
            cout << " ||";
        }
        cout << endl;
    }
    cout << line << endl;
    cout << "Arrows remaining: " << num_arrows << endl;
}

bool Game::check_win() const {
    return hasWon;
}

void Game::set_Win(bool e) {
    hasWon = e;
}

void Game::move_up() {
    // Move player up
    if (advPos->get_row() != 0) {
        int r = advPos->get_row() - 1;
        int l = advPos->get_col();
        roomArr.at(r + 1).at(l).set_hasPlayer(false);
        roomArr.at(r).at(l).set_hasPlayer(true);
        delete advPos;
        advPos = nullptr;
        advPos = new Room(r, l);
    } else {
        cout << "Out of bounds" << endl;
    }
}

void Game::move_down() {
    // Move player down
    if (advPos->get_row() != row - 1) {
        int r = advPos->get_row() + 1;
        int l = advPos->get_col();
        roomArr.at(r - 1).at(l).set_hasPlayer(false);
        roomArr.at(r).at(l).set_hasPlayer(true);
        delete advPos;
        advPos = nullptr;
        advPos = new Room(r, l);
    } else {
        cout << "Out of bounds" << endl;
    }
}

void Game::move_left() {
    // Move player left
    if (advPos->get_col() != 0) {
        int r = advPos->get_row();
        int l = advPos->get_col() - 1;
        roomArr.at(r).at(l + 1).set_hasPlayer(false);
        roomArr.at(r).at(l).set_hasPlayer(true);
        delete advPos;
        advPos = nullptr;
        advPos = new Room(r, l);
    } else {
        cout << "Out of bounds" << endl;
    }
}

void Game::move_right() {
    // Move player right
    if (advPos->get_col() != col - 1) {
        int r = advPos->get_row();
        int l = advPos->get_col() + 1;
        roomArr.at(r).at(l - 1).set_hasPlayer(false);
        roomArr.at(r).at(l).set_hasPlayer(true);
        delete advPos;
        advPos = nullptr;
        advPos = new Room(r, l);
    } else {
        cout << "Out of bounds" << endl;
    }
}

char Game::get_dir() {
    // Get direction of arrow
    char dir;
    // Note: error checking is needed!!
    bool x = true;
    while (x) {
        cout << "Fired an arrow...." << endl;
        cout << "W-up" << endl;
        cout << "A-left" << endl;
        cout << "S-down" << endl;
        cout << "D-right" << endl;

        cout << "Enter direction: " << endl;
        cin >> dir;
        cin.ignore(256, '\n');
        if (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd') {
            cout << endl << "Invalid input, try again!";
        } else {
            x = false;
        }
    }
    return dir;
}

void Game::check_AdjRooms() {
    // Check and display percepts around the player's location
    int advRow = advPos->get_row();
    int advCol = advPos->get_col();

    // Check above
    if (advRow - 1 >= 0) {
        if (roomArr.at(advRow - 1).at(advCol).getEventptr() != nullptr) {
            roomArr.at(advRow - 1).at(advCol).getEventptr()->percept();
        }
    }

    // Check below
    if (advRow + 1 < row) {
        if (roomArr.at(advRow + 1).at(advCol).getEventptr() != nullptr) {
            roomArr.at(advRow + 1).at(advCol).getEventptr()->percept();
        }
    }

    // Check left
    if (advCol - 1 >= 0) {
        if (roomArr.at(advRow).at(advCol - 1).getEventptr() != nullptr) {
            roomArr.at(advRow).at(advCol - 1).getEventptr()->percept();
        }
    }

    // Check right
    if (advCol + 1 < col) {
        if (roomArr.at(advRow).at(advCol + 1).getEventptr() != nullptr) {
            roomArr.at(advRow).at(advCol + 1).getEventptr()->percept();
        }
    }
}

void Game::wumpus_move() {
    // Move the Wumpus after a missed arrow (75% chance)
    int chance = rand() % 4;
    if (chance != 3) {
        while (wumpWarp) {
            roomArr.at(wumpusPos->get_row()).at(wumpusPos->get_col()).setEvent(nullptr);
            cout << "The arrow makes a sound. The Wumpus has moved..." << endl;

            int temprow = 0;
            int tempcol = 0;

            do {
                temprow = rand() % row;
                tempcol = rand() % col;
            } while (roomArr.at(temprow).at(tempcol).getEventptr() != nullptr &&
                     !roomArr.at(temprow).at(tempcol).get_StartRoom());

            Room* wumpus = new Room(temprow, tempcol);
            set_wumpPos(wumpus);
            roomArr.at(temprow).at(tempcol).setEvent(new Wumpus);
            wumpWarp = false;
        }
    }
}

void Game::fire_arrow() {
    // Fire an arrow in the specified direction and check for Wumpus within 3 blocks
    char dir = get_dir();

    // Shoot up and check if Wumpus is within 3 blocks
    if (dir == 'w') {
        if ((wumpusPos->get_col() == advPos->get_col()) &&
            (advPos->get_row() - 3 <= wumpusPos->get_row() && wumpusPos->get_row() < advPos->get_row())) {
            cout << "You've shot the Wumpus!" << endl;
            set_Win(true);
        } else {
            wumpus_move();
        }
    }

    // Shoot down and check if Wumpus is within 3 blocks
    if (dir == 's') {
        if ((wumpusPos->get_col() == advPos->get_col()) &&
            (advPos->get_row() + 3 >= wumpusPos->get_row() && wumpusPos->get_row() > advPos->get_row())) {
            cout << "You've shot the Wumpus!" << endl;
            set_Win(true);
        } else {
            wumpus_move();
        }
    }

    // Shoot left and check if Wumpus is within 3 blocks
	if(dir == 'a'){
		if((wumpusPos->get_row() == advPos->get_row()) &&												
		((advPos->get_col()-3 <= wumpusPos->get_col() && wumpusPos->get_col() < advPos->get_col()))){	
			cout << "You've shot the Wumpus!" << endl;
			set_Win(true);
		} else {
			wumpus_move();
		}
	} 
	//shoot down and check if Wumpus is within 3 blocks
	if(dir == 'd'){
		if((wumpusPos->get_row() == advPos->get_row()) &&												
		//checks if wumpus is in same row as player
		((advPos->get_col()+3 >= wumpusPos->get_col() && wumpusPos->get_col() > advPos->get_col()))){	
			cout << "You've shot the Wumpus!" << endl;
			set_Win(true);
		} else {
			wumpus_move();
		}
	}
	return;

}


void Game::check_encounter(){											
	if(roomArr.at(advPos->get_row()).at(advPos->get_col()).getEventptr() != nullptr){					
		//checks if player is in a room with a event
		char event = roomArr.at(advPos->get_row()).at(advPos->get_col()).getEventptr()->eventType();
		switch (event)
		{
		case 'W':
			roomArr.at(advPos->get_row()).at(advPos->get_col()).getEventptr()->encounter();
			hasLost = true;
			break;
		case 'S':
			roomArr.at(advPos->get_row()).at(advPos->get_col()).getEventptr()->encounter();
			stalEncounter();
			break;
		case 'B':
			roomArr.at(advPos->get_row()).at(advPos->get_col()).getEventptr()->encounter();
			batsEncounter();
			break;
		case 'G':
			roomArr.at(advPos->get_row()).at(advPos->get_col()).getEventptr()->encounter();
			goldEncounter();
			break;
		default:
			break;
		}
	}
}

// 50 perfect chance of stalctite falling and killing player
void Game::stalEncounter(){
	int chance = rand() % 2;
	if(chance != 0){
		cout << endl <<  "Ouch, a stalactite has fallen and killed you." << endl;
		hasLost = true;
	}
}

void Game::batsEncounter(){
	hasBats = true;

}

void Game::goldEncounter(){
	hasGold = true;
	roomArr.at(advPos->get_row()).at(advPos->get_col()).setEvent(nullptr);	//delete gold event
}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f' && num_arrows > 0){
		num_arrows--;
		Game::fire_arrow();
		return;
	} else if(num_arrows == 0){
		cout << endl << "Yikes, you are out of arrows!" ;
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}
//Over 15 lines because lots of cout statements
char Game::get_input(){
	//Note: error checking is needed!!
	//Your code here:
	char c;
	bool x  = true;
	while(x){
		cout << endl << endl << "Player move..." << endl << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;
		cout << "f-fire an arrow" << endl;

		cout << "Enter input: ";
		cin >> c;
		cin.ignore(256, '\n');
		if(c!='w'&&c!='a'&&c!='s'&&c!='d'&&c!='f'){
			cout << endl<< "Invalid input, try again!";
		} else{
			if(hasBats == true){
				reverseMoves(c);
				batRounds++;
				if(batRounds == 5){
					batRounds = 0;
					hasBats = false;
				}
			}
			x= false;
		}
	} 
	return c;
}

void Game::reverseMoves(char &v){
	if (v == 'a'){
		v = 'd';
	}else if (v == 'd'){
		v = 'a';
	}else if (v == 'w'){
		v = 's';
	} else if (v == 's'){
		v = 'w';
	}
}

void Game::check_Escape(){
	if(hasGold == true){
		if((advPos->get_row() == startPos->get_row()) 					
		//check] player for gold and if they are in starting room
		&& (advPos->get_col() == startPos->get_col()))
		{
			hasWon = true;
		}
	}
}

bool Game::get_sameSettingBool()const{									
	return sameSettingBool;
}

void Game::sameSetting(){
	bool b = false;
	bool x = true;
	while(x){
		cout << "Would you like to play with the SAME settings? 0 - No 1 - Yes: ";
		cin >> b;
		if(b == true){
			sameSettingBool = true;
			x=false;
		} else if(b==false){
			sameSettingBool = false;
			x=false;
		}else {
			cout << "Invalid input. Try again.";
		}
	}

}

void Game::askAgain(){														
	//same as main
	int width = 0, lenth = 0;
	bool debug = false;
	string dbg;
	bool x = true;
	bool y = true;
	while(x){ 							  
		while(y){			
			//error handle			
			cout << "Enter width (4-50): " ; 
			cin >> width;
			cout << "Enter length (4-50): " ;
			cin >> lenth;
			if(width <= 50 && lenth <= 50&& width >= 4 && lenth >= 4 ){
				y =false;
			} else{
				cout << "Invalid. Try again." << endl;
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
			cout << "Try again." << endl;
		}
		Game g;
		g.play_game(width, lenth, debug);
	}
}


void Game::reset(){														
	roomArr.clear();
	this->wumpusCounter = 0;
	this->batsCounter = 0;
    this->stalCounter = 0;
    this->goldCounter = 0;
	this->batRounds = 0;
	
	this->wumpWarp = true;
	this->hasWon=false;
	this->hasLost = false;
	this->hasGold =false;
	this->hasBats = false;

	this->sameSettingBool = false;

	delete this->advPos;
	delete this->startPos;
	delete this->wumpusPos;
	this->advPos = nullptr;
	this->startPos = nullptr;
	this->wumpusPos = nullptr;
}
void Game::play_again(){
	bool b = false;
	bool x = true;
	while(x){
		cout << endl << "Would you like to play again? 0 - No 1 - Yes: ";
		cin >> b;
		if(b == true){
			x=false;
			sameSetting();
			if(!sameSettingBool){
				askAgain();
			}else if(sameSettingBool){
				reset();
				play_game(col,row,debug_view);
			}
		} else if(b==false){
			cout << endl << "Bye." <<endl;
			x=false;
		}else {
			cout << "Invalid input. Try again.";
		}
	}

}


//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){
	Game::set_up(w, l);
	this->debug_view = d;

	char input, arrow_input;
	
	while (Game::check_win() == false && hasLost == false){

		check_AdjRooms();

		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);
		check_Escape();

		//3. may or may not encounter events
		//Your code here:
		check_encounter();
	}	

	if(hasWon == true){
		cout << endl << "Congrats! You have won!" <<endl;
	}
	if(hasLost == true){
		cout << endl <<  "You lost!"<< endl;
	}
	// extra credit 
	play_again();

	return;

}