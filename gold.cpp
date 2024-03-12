/*********************************************************************
** Program Filename: gold.cpp
** Author: Sarah Satchell
** Date: 11/29/2023
** Description: Defines the Gold functions
** Input: none
** Output: none
*********************************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

void Gold::print(){
    cout <<  'G';
}

char Gold::eventType(){
    return 'G';
}

void Gold::percept(){
     cout << endl << "You see a glimmer nearby.";
}

void Gold::encounter(){
    cout << "You've encountered the gold! You grab it and now you are ready to go back.";
}