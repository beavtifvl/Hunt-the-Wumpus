/*********************************************************************
** Program Filename: bats.cpp
** Author: Sarah Satchell
** Date: 11/29/2023
** Description: Defines bat functions
** Input: none
** Output: none
*********************************************************************/
#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation

void Bats::print(){
    cout << 'B';
}
char Bats::eventType(){
    return 'B';
}

void Bats::percept(){
    cout << endl << "You hear wings flapping.";
}

void Bats::encounter(){
    cout << "You've encountered bats, they have confused you!";
}