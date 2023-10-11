#include "Bus.h"
#include "Base.h"
#include <iostream>
using namespace std;
Bus::Bus(int people, int max_people, double petrol, double max_petrol) :Vehicle(petrol, max_petrol)
{
	this->people = people;
	this->max_people = max_people;
}
unsigned Bus:: getPeopleCount()
{
	return people;
}
unsigned Bus:: getMaxPeople()
{
	return max_people;
}
void Bus::arrive()
{
	Base::people_on_base += people + driver;//1 - is a driver
	people = driver = 0;
	Base::vehicle_on_base++;
}
bool Bus::leave()
{
	Vehicle::leave();
	if (Base::people_on_base >= max_people)
	{
		people = max_people;
		Base::people_on_base -= max_people;
		return true;
	}
	else if(Base::people_on_base==0)
	{
		cout << "There is no people left on base" << endl;
		return false;
	}
	else
	{
		people = Base::people_on_base;
		Base::people_on_base = 0;
		return true;
	}
}