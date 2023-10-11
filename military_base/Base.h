#pragma once
#include "Vehicle.h"
class Base
{
private:
	static Vehicle* vehicles;
public:
	static unsigned int people_on_base;
	static unsigned int vehicle_on_base;
	static double petrol_on_base;
	static double goods_on_base;
	static Vehicle* getVehicleArray();
	Base();
	Vehicle* addVehicle(Vehicle& vehicle);
	Base(unsigned int people_on_base, unsigned int vehicle_on_base, double petrol_on_base, double goods_on_base);
};

