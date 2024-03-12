#ifndef ROOM_H
#define ROOM_H 

#include "event.h"
#include <iostream>
using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private:  
    int col;
    int row;
    Event* event;
    bool hasPlayer;
    bool startRoom;

public:
/*********************************************************************
** Function:default constructor
** Description: initiates all variables
** Parameters:none
** Pre-Conditions:room object created
** Post-Conditions:none
*********************************************************************/
Room();
/*********************************************************************
** Function:nmon default constructor
** Description: creates room object with int int
** Parameters:int- width, int-length
** Pre-Conditions:room object created
** Post-Conditions:none
*********************************************************************/
Room(int, int);
/*********************************************************************
** Function:destructor
** Description: destroys vars and free mem
** Parameters:none
** Pre-Conditions:program ends, var goes out of scope
** Post-Conditions:memory freed, stuff destroyed
*********************************************************************/
~Room();
/*********************************************************************
** Function:print 
** Description:test some stuff
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
void print() const;
/*********************************************************************
** Function:get_row
** Description:gets row of room object
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
int get_row()const;
/*********************************************************************
** Function:get_col
** Description:gets column of room object
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
int get_col()const;
/*********************************************************************
** Function:setEvent
** Description:sets event at location to passed event
** Parameters:Event* passes what kind of event
** Pre-Conditions:game set up
** Post-Conditions:game is set up
*********************************************************************/
void setEvent(Event*);
/*********************************************************************
** Function:getEventpr
** Description:get event going on at location
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:returns event
*********************************************************************/
Event* getEventptr() const;
/*********************************************************************
** Function:get_hasPlayer
** Description:see if location has player
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:returns boolean
*********************************************************************/
bool get_hasPlayer()const;
/*********************************************************************
** Function:set_hasPlayer
** Description:sets hasPlayer boolean at location
** Parameters:bool - true or false passed
** Pre-Conditions:none
** Post-Conditions:hasBool is set to passed boolean
*********************************************************************/
void set_hasPlayer(bool);
/*********************************************************************
** Function:placePlayer
** Description:place player location
** Parameters:none
** Pre-Conditions:game setup
** Post-Conditions:player has been palced
*********************************************************************/
void placePlayer();
/*********************************************************************
** Function:printPlayer
** Description:prints play symbol
** Parameters:none
** Pre-Conditions:display called
** Post-Conditions:player symbol printed
*********************************************************************/
void printPlayer()const;
/*********************************************************************
** Function:set_startRoom
** Description:gets starting room position
** Parameters: sets room to true if it is where player begins
** Pre-Conditions:player placed
** Post-Conditions:none
*********************************************************************/
void set_StartRoom(bool);
/*********************************************************************
** Function:get start room
** Description:gets starting room position
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
bool get_StartRoom();
/*********************************************************************
** Function:set_row
** Description:sets row
** Parameters:int& passed value
** Pre-Conditions:none
** Post-Conditions:row is set to passed value
*********************************************************************/
void set_row(int&);
/*********************************************************************
** Function:set_col
** Description:sets col
** Parameters:int& passed value
** Pre-Conditions:none
** Post-Conditions:col is set to passed value
*********************************************************************/
void set_col(int&);
/*********************************************************************
** Function:check_escape
** Description:sees if player is at start room with gold
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
void check_Escape();


};

#endif