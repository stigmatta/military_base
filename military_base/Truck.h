#pragma once
#include "Vehicle.h"
class Truck :public Vehicle
{
private:
	double load, max_load;
public:
	Truck(double load,double max_load, double petrol, double max_petrol);
	double getLoad();
	double getMaxLoad();
	virtual void arrive();
	virtual bool leave();
};

