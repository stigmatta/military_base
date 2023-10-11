#include "Vehicle.h"
#include "Base.h"
#include <iostream>
using namespace std;
Vehicle::Vehicle()
{
	petrol_amount = 20;
	tank_volume = 100;
	this_index = ++index;
}
Vehicle::Vehicle(double petrol_amount, double tank_volume)
{
	this->petrol_amount = petrol_amount;
	this->tank_volume = tank_volume;
	this_index = ++index;
}
Vehicle& Vehicle:: operator[](int index)
{
	try
	{
		if (index >= 0 && index < Base::vehicle_on_base)
		{
			return Base::getVehicleArray()[index];
		}
		else
			throw 1;
	}
	catch (int a)
	{
		cout << "Index is out of bounds for an array" << endl;
	}
}
Vehicle* Base::getVehicleArray()
{
	return vehicles;
}
double Vehicle:: getTankVolume()
{
	return tank_volume;
}
double Vehicle::getPetrolAmount()
{
	return petrol_amount;
}
unsigned Vehicle:: getThisIndex()
{
	return this_index;
}
int Vehicle::getIndex()
{
	return index;
}
void Vehicle::setIndex(int ind)
{
	Vehicle::index = ind;
}
void Vehicle::arrive()
{
	Base::people_on_base++;
	Base::vehicle_on_base++;
	driver = 0;
}
bool Vehicle::leave()
{
	if (petrol_amount != tank_volume)
	{
		if (Base::petrol_on_base >= tank_volume - petrol_amount)
		{
			if (Base::people_on_base > 0)
			{
				petrol_amount += tank_volume - petrol_amount;
				Base::petrol_on_base -= tank_volume - petrol_amount;
				Base::people_on_base--;
				Base::vehicle_on_base--;
				driver = 1;
				return true;
			}
			else
			{
				cout << "No driver for this vehicle left" << endl;
				return false;
			}
		}
		else
		{
			cout << "No petrol for this vehicle left" << endl;
			return false;
		}
	}
	else
	{
		if (Base::people_on_base > 0)
		{
			Base::people_on_base--;
			Base::vehicle_on_base--;
			driver = 1;
			return true;
		}
		else
		{
			cout << "No driver for this vehicle left" << endl;
			return false;
		}
	}
}
