/*********************************************************************
** Program Filename: room.cpp
** Author: Sarah Satchell
** Date: 11/29/2023
** Description: def for the Room functions
** Input: none
** Output: none
*********************************************************************/
#include "room.h"

using namespace std;

//Room Implementation

Room::Room(){
    event = nullptr;
    hasPlayer = false;
    col = 0;
    row = 0;
    this->startRoom = false;
}

Room::Room(int row, int col){
    this-> row = row;
    this-> col = col;
    event = nullptr;
    hasPlayer = false;
}
Room::~Room(){
    delete this->event;
    this->event = nullptr;

}

void Room::print() const{
    cout << "(" << row << ", " << col << ")";
}

void Room::set_StartRoom(bool e){
    this->startRoom = e;
}


bool Room::get_StartRoom(){
    return startRoom;
}
int Room::get_row()const{
    return row;
}

int Room::get_col()const{
    return col;
 }

void Room::set_row(int &i){
    row = i;
}

void Room::set_col(int& i){
    col = i;
}


void Room::setEvent(Event* events){
    if(this-> event != nullptr){
        delete this -> event;
    }
    this-> event = events;
}

Event* Room::getEventptr()const{
    return event;
}

void Room::set_hasPlayer(bool b){
	this->hasPlayer = b;
}

bool Room::get_hasPlayer()const{
	return hasPlayer;
}

void Room::printPlayer()const{
    cout << "*";
}



    