#include "Base.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"
#include <iostream>
using namespace std;
Vehicle* Base::vehicles;
unsigned Base::people_on_base = 100;
unsigned int Base:: vehicle_on_base=20;
double Base:: petrol_on_base = 150.4;
double Base::goods_on_base=10.6;
int Vehicle::index = -1;
int main()
{
	Base base;
	cout << Vehicle::getIndex()<<endl;
	Vehicle a1(25, 100);
	base.addVehicle(a1);
	cout << Vehicle::getIndex() << endl;
	Vehicle a2(25, 100);
	cout << Vehicle::getIndex() << endl;
	Bus a3(6, 25, 32.5, 100);
	cout << Vehicle::getIndex() << endl;
	a3.leave();
	cout << Base::people_on_base << endl;
	Truck a4(0,9.4, 25, 100);
	a4.leave();
	cout << Base::goods_on_base << endl;
}