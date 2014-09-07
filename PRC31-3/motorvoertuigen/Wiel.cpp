#include "Wiel.h"

#include <string>
using std::string;

Wiel::Wiel(int d, const string &mat) :diameter(d), materiaal(mat){

}

string Wiel::getMateriaal() {
	return materiaal;
}

void Wiel::setMateriaal(const string &mat) {
	materiaal = mat;
}

int Wiel::getDiameter() {
	return diameter;
}
