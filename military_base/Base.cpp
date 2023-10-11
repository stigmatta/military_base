#include "Base.h"
#include "Vehicle.h"
Base::Base()
{
	vehicles = new Vehicle[vehicle_on_base];
	Vehicle::setIndex(-1);
}
Base::Base(unsigned int people_on_base, unsigned int vehicle_on_base, double petrol_on_base, double goods_on_base)
{
	vehicles = new Vehicle[vehicle_on_base];
	Vehicle::setIndex(0);
}
Vehicle* Base:: addVehicle(Vehicle& vehicle)
{
	vehicles[vehicle.getThisIndex()] = vehicle;
	return vehicles;
}