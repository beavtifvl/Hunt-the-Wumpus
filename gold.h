#ifndef GOLD_H
#define GOLD_H 
#include "event.h"
//Gold Interface
class Gold : public Event
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