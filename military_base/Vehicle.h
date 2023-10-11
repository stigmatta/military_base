#pragma once
class Vehicle
{
protected:
	double petrol_amount, tank_volume;
	unsigned this_index,driver;
	static int index;
public:
	Vehicle();
	Vehicle(double petrol_amount, double tank_volume);
	double getTankVolume();
	double getPetrolAmount(); 
	unsigned getThisIndex();
	static int getIndex();
	static void setIndex(int);
	virtual void arrive(); 
	virtual bool leave();
	Vehicle& operator[](int index);
};

