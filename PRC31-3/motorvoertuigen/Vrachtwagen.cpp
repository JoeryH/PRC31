#include "Vrachtwagen.h"

Vrachtwagen::Vrachtwagen(const string &type, const string &matSoort, int diam, int aantalWielen, int vermogen)
: Wagen(type, matSoort, diam, aantalWielen)
{
	this->vermogen = new int(vermogen);
}

Vrachtwagen::~Vrachtwagen() {
	delete vermogen;
}

int Vrachtwagen::getVermogen() {
	return *vermogen;
}

Vrachtwagen::Vrachtwagen(const Vrachtwagen &mijnVrachtwagen) : Wagen(mijnVrachtwagen) {
	vermogen = new int(*mijnVrachtwagen.vermogen);
}

Vrachtwagen& Vrachtwagen::operator=(const Vrachtwagen &mijnVrachtwagen) {
	if (&mijnVrachtwagen == this) return *this;
	Wagen::operator=(mijnVrachtwagen);
	delete vermogen;
	vermogen = new int(*mijnVrachtwagen.vermogen);
	return *this;
}
