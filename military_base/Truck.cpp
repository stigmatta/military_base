#include "Truck.h"
#include "Vehicle.h"
#include "Base.h"
#include <iostream>
using namespace std;
Truck::Truck(double load, double max_load, double petrol, double max_petrol) :Vehicle(petrol, max_petrol)
{
	this->load = load;
	this->max_load = max_load;
}
double Truck::getLoad()
{
	return load;
}
double Truck::getMaxLoad()
{
	return max_load;
}
void Truck::arrive()
{
	Vehicle::arrive();
	Base::goods_on_base += load;
	load = 0;
}
bool Truck::leave()
{
	Vehicle::leave();
	if (Base::goods_on_base >= max_load)
	{
		load = max_load;
		Base::goods_on_base -= max_load;
		return true;
	}
	else if (Base::people_on_base == 0)
	{
		cout << "There is no goods left on base" << endl;
		return false;
	}
	else
	{
		load = Base::goods_on_base;
		Base::goods_on_base = 0;
		return true;
	}
}