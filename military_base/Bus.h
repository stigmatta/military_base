#pragma once
#include "Vehicle.h"
class Bus:public Vehicle
{
private:
	unsigned people, max_people;
public:
	Bus(int people, int max_people, double petrol, double max_petrol);
	unsigned getPeopleCount(); 
	unsigned getMaxPeople(); 
	virtual void arrive();
	virtual bool leave();
};

