#ifndef BATS_H
#define BATS_H 
#include "event.h"
//Bats Interface
class Bats : public Event
{
    protected:

    public:
/*********************************************************************
** Function:void print
** Description:	prints symbol of event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions:none
*********************************************************************/
void print();
/*********************************************************************
** Function:eventType
** Description:returnss what kind of event
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
char eventType();
/*********************************************************************
** Function:percept
** Description:prints percept of event
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
void percept();
/*********************************************************************
** Function:encounter
** Description:prints encounter message
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
void encounter();

};

#endif