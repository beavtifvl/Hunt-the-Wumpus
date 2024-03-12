#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "stalactites.h"
#include "event.h"
#include "room.h"

using namespace std;

// Game interface 
class Game
{
private:
	// Declare a 2D vector of Room objects:
	vector<vector<Room>> roomArr;
	// Other member variables:
	int col;             // Length of the board
	int row;             // Width of the board
	int num_arrows;      // Keep track of the number of arrows remaining
	bool debug_view;     // Debug mode or not

	// Feel free to add more variables...
	int wumpusCounter;
	int batsCounter;
	int stalCounter;
	int goldCounter;

	int batRounds;

	Room* advPos;
	Room* startPos;
	Room* wumpusPos;

	bool wumpWarp;
	bool hasWon;
	bool hasLost;
	bool hasGold;
	bool hasBats;

	bool sameSettingBool;

public:
	// Suggested functions:
	/*********************************************************************
	** Function: Game()
	** Description: Default constructor
	** Parameters: None
	** Pre-Conditions: Game object is created
	** Post-Conditions: Game variables are initialized
	*********************************************************************/ 
	Game();

	/*********************************************************************
	** Function: ~Game()
	** Description: Destructor
	** Parameters: None
	** Pre-Conditions: Function ends, or program ends, or object goes out of scope
	** Post-Conditions: Memory managed
	*********************************************************************/ 
	~Game();

	/*********************************************************************
	** Function: set_up
	** Description: Create 2D vector and place events and players randomly
	** Parameters: int - width, int - length
	** Pre-Conditions: Game started
	** Post-Conditions: 2D vector created
	*********************************************************************/ 
	void set_up(int, int);

	/*********************************************************************
	** Function: display_game
	** Description: Prints game to terminal
	** Parameters: None
	** Pre-Conditions: 2D vector created and events are placed
	** Post-Conditions: Printed to terminal
	*********************************************************************/ 
	void display_game() const;

	/*********************************************************************
	** Function: check_win()
	** Description: Checks if player killed wumpus or escaped with gold
	** Parameters: None
	** Pre-Conditions: Game started
	** Post-Conditions: None
	*********************************************************************/ 
	bool check_win() const;

	/*********************************************************************
	** Function: get_dir
	** Description: Gets user input from which direction to fire arrow
	** Parameters: None
	** Pre-Conditions: Fired arrow
	** Post-Conditions: Killed wumpus or misses
	*********************************************************************/ 
	char get_dir();

	/*********************************************************************
	** Function: wumpus_move
	** Description: 75% chance for wumpus to warp to a random room when arrow misses
	** Parameters: None
	** Pre-Conditions: Fired arrow
	** Post-Conditions: Wumpus moves or doesn't move
	*********************************************************************/ 
	void wumpus_move();

	/*********************************************************************
	** Function: fire_arrow
	** Description: Fires arrow
	** Parameters: None
	** Pre-Conditions: Player chooses 'f' to fire arrow
	** Post-Conditions: Fired arrow
	*********************************************************************/ 
	void fire_arrow();

	/*********************************************************************
	** Function: move_up
	** Description: Moves player up
	** Parameters: None
	** Pre-Conditions: Player chose to move
	** Post-Conditions: Player moved
	*********************************************************************/ 
	void move_up();

	/*********************************************************************
	** Function: move_down
	** Description: Moves player down
	** Parameters: None
	** Pre-Conditions: Player chose to move
	** Post-Conditions: Player moved
	*********************************************************************/ 
	void move_down();

	/*********************************************************************
	** Function: move_left
	** Description: Moves player left
	** Parameters: None
	** Pre-Conditions: Player chose to move
	** Post-Conditions: Player moved
	*********************************************************************/ 
	void move_left();

	/*********************************************************************
	** Function: move_right
	** Description: Moves player right
	** Parameters: None
	** Pre-Conditions: Player chose to move
	** Post-Conditions: Player moved
	*********************************************************************/ 
	void move_right();

	/*********************************************************************
	** Function: move
	** Description: Moves character in direction
	** Parameters: None
	** Pre-Conditions: Player chose to move
	** Post-Conditions: Player moved
	*********************************************************************/ 
	void move(char);

	/*********************************************************************
	** Function: get_input
	** Description: See which direction player wants to move
	** Parameters: None
	** Pre-Conditions: Player chose to move
	** Post-Conditions: Player moved
	*********************************************************************/ 
	char get_input();

	/*********************************************************************
	** Function: play_game
	** Description: Initiates game
	** Parameters: int - width, int - length, bool - cheat mode on or off
	** Pre-Conditions: Game has started
	** Post-Conditions: Player is playing
	*********************************************************************/ 
	void play_game(int, int, bool);

	/*********************************************************************
	** Function: placeEvents
	** Description: Places events randomly
	** Parameters: Event* - what event type
	** Pre-Conditions: Game has been initiated
	** Post-Conditions: Events are placed randomly
	*********************************************************************/ 
	void placeEvents(Event*);

	/*********************************************************************
	** Function: get_hasPlayer()
	** Description: Returns hasPlayer boolean
	** Parameters: None
	** Pre-Conditions: N/A
	** Post-Conditions: Boolean returned
	*********************************************************************/ 
	bool get_hasPlayer() const;

	/*********************************************************************
	** Function: set_hasPlayer
	** Description: Sets hasPlayer bool
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: hasPlayer is set
	*********************************************************************/ 
	void set_hasPlayer();

	/*********************************************************************
	** Function: placePlayer
	** Description: Places player at a random room
	** Parameters: None
	** Pre-Conditions: Game setup started
	** Post-Conditions: Player placed
	*********************************************************************/ 
	void placePlayer();

	/*********************************************************************
	** Function: set_advPos
	** Description: Sets player position
	** Parameters: Room* - where the player will be
	** Pre-Conditions: Player moves
	** Post-Conditions: Player moved
	*********************************************************************/ 
	void set_advPos(Room*);

	/*********************************************************************
	** Function: set_startPos
	** Description: Saves starting room location
	** Parameters: Room* - where the starting room is
	** Pre-Conditions: Player is placed
	** Post-Conditions: Starting room location saved
	*********************************************************************/ 
	void set_startPos(Room*);

	/*********************************************************************
	** Function: set_wumpusPos
	** Description: Sets wumpus position
	** Parameters: Room* - where the wumpus will be
	** Pre-Conditions: Wumpus moves
	** Post-Conditions: Wumpus moved
	*********************************************************************/ 
	void set_wumpPos(Room*);

	/*********************************************************************
	** Function: set_Win
	** Description: Set hasWon boolean
	** Parameters: bool - passes if the player has won
	** Pre-Conditions: N/A
	** Post-Conditions: N/A
	*********************************************************************/ 
	void set_Win(bool);

	/*********************************************************************
	** Function: check_adjRooms
	** Description: Checks adjacent rooms to display percepts
	** Parameters: None
	** Pre-Conditions: Player moves
	** Post-Conditions: N/A
	*********************************************************************/ 
	void check_AdjRooms();

	/*********************************************************************
	** Function: check_encounter
	** Description: Checks if the player is in a room with an event
	** Parameters: None
	** Pre-Conditions: Player moved
	** Post-Conditions: Event plays
	*********************************************************************/ 
	void check_encounter();

	/*********************************************************************
	** Function: stalEncounter
	** Description: 50% chance player dies when entering room
	** Parameters: None
	** Pre-Conditions: Player enters stalactite room
	** Post-Conditions: Player dies or lives
	*********************************************************************/ 
	void stalEncounter();

	/*********************************************************************
	** Function: batsEncounter
	** Description: Reverses player movements for 5 rounds
	** Parameters: None
	** Pre-Conditions: Player enters room with bats
	** Post-Conditions: Reverses player movements for 5 rounds
	*********************************************************************/ 
	void batsEncounter();

	/*********************************************************************
	** Function: goldEncounter
	** Description: Picks up gold/deletes gold event
	** Parameters: None
	** Pre-Conditions: Player goes in gold room
	** Post-Conditions: hasGold is set to true
	*********************************************************************/
	void goldEncounter();

	/*********************************************************************
	** Function: reverseMoves
	** Description: Reverses player moves
	** Parameters: char& - changes player's movements
	** Pre-Conditions: Encountered bats
	** Post-Conditions: Player's moves reversed
	*********************************************************************/
	void reverseMoves(char&);

	/*********************************************************************
	** Function: checkEscape
	** Description: Checks to see if the player is at the starting room with gold
	** Parameters: None
	** Pre-Conditions: Player has gold
	** Post-Conditions: Player wins
	*********************************************************************/
	void check_Escape();

	/*********************************************************************
	** Function: get_samesettingbool
	** Description: Gets sameSettingBool boolean
	** Parameters: None
	** Pre-Conditions: Game ends
	** Post-Conditions: Players want new or same settings
	*********************************************************************/
	bool get_sameSettingBool() const;

	/*********************************************************************
	** Function: play_again
	** Description: Play again feature
	** Parameters: None
	** Pre-Conditions: Game ends
	** Post-Conditions: Exits or restarts the game
	*********************************************************************/
	void play_again();

	/*********************************************************************
	** Function: sameSetting
	** Description: Asks the player if they want the same settings
	** Parameters: None
	** Pre-Conditions: Game ends
	** Post-Conditions: N/A
	*********************************************************************/
	void sameSetting();

	/*********************************************************************
	** Function: start_game
	** Description: Starts the game
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions: None
	*********************************************************************/
	void start_game();

	/*********************************************************************
	** Function: askAgain
	** Description: Asks if they want to play again
	** Parameters: None
	** Pre-Conditions: Game end
	** Post-Conditions: None
	*********************************************************************/
	void askAgain();

	/*********************************************************************
	** Function: reset
	** Description: Resets all variables when they want the same settings
	** Parameters: None
	** Pre-Conditions: Game ends
	** Post-Conditions: All variables reset
	*********************************************************************/
	void reset();
};

#endif
