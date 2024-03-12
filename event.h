#ifndef EVENT_H
#define EVENT_H 
using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
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
virtual void print() = 0;
/*********************************************************************
** Function:eventType
** Description:returns event type
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
virtual char eventType() = 0;
/*********************************************************************
** Function:percept
** Description: prints message for percept of event
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
virtual void percept() = 0;
/*********************************************************************
** Function:encounter
** Description:prints message for encounter
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/
virtual void encounter() = 0;

	
};
#endif