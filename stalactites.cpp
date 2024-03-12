/*********************************************************************
** Program Filename: stalactites.cpp
** Author: Sarah Satchell
** Date: 11/29/2023
** Description: def for stalactites functions
** Input: n/a
** Output: n/a
*********************************************************************/
#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

void Stalactites::print(){
   cout << 'S';
}

char Stalactites::eventType(){
    return 'S';
}

void Stalactites::percept(){
    cout << endl << "You hear water dripping.";
}

void Stalactites::encounter(){
    cout << "Uh oh, you've entered room with stalactites!";
}
