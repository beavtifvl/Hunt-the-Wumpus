/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Sarah Satchell
** Date: 11/29/2023
** Description: Defines the Wumpus functions
** Input: none
** Output: none
*********************************************************************/
#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

void Wumpus::print(){
    cout << 'W';
}

char Wumpus::eventType(){
    return 'W';
}

void Wumpus::percept(){
    cout << endl << "You smell a terrible stench.";
}

void Wumpus::encounter(){
    cout << "You've encounter the Wumpus, rip. ";
}