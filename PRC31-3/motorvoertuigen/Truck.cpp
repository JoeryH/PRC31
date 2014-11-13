#include "Truck.h"

Truck::Truck(const string &type, const string &matSoort, int diam, int aantalWheelen, int vermogen)
: Car(type, matSoort, diam, aantalWheelen)
{
	this->vermogen = new int(vermogen);
}

Truck::~Truck() {
	delete vermogen;
}

int Truck::getVermogen() {
	return *vermogen;
}

Truck::Truck(const Truck &mijnTruck) : Car(mijnTruck) {
	vermogen = new int(*mijnTruck.vermogen);
}

Truck& Truck::operator=(const Truck &mijnTruck) {
	if (&mijnTruck == this) return *this;
	Car::operator=(mijnTruck);
	delete vermogen;
	vermogen = new int(*mijnTruck.vermogen);
	return *this;
}
