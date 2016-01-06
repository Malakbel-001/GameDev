#include "Vehicle.h"


Vehicle::Vehicle()
{	
}


Vehicle::~Vehicle()
{
}

void Vehicle::SetPassenger(Object* _passenger)
{
	passenger = _passenger;
}

Object* Vehicle::GetPassenger()
{
	return passenger;
}