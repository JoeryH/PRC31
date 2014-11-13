#include "Wheel.h"

#include <string>
using std::string;

Wheel::Wheel(int d, const string &mat) :diameter(d), materiaal(mat){

}

string Wheel::getMateriaal() {
	return materiaal;
}

void Wheel::setMateriaal(const string &mat) {
	materiaal = mat;
}

int Wheel::getDiameter() {
	return diameter;
}
