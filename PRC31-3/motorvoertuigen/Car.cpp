#include "Car.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

Car::Car(const string &type, const string &matSoort, int diam, int aantalWheelen) {
	this->type = type;
	for (int i=0; i < aantalWheelen; i++) {
		Wheel *w = new Wheel(diam, matSoort);
		wiel.push_back(w);
	}
}

Car::~Car() {
	for (unsigned int i = 0; i < wiel.size(); i++) {
		delete wiel[i];
	}
}

string Car::getType() {
	return type;
}

void Car::setKenteken(const string &kenteken) {
	this->kenteken = kenteken;
}

string Car::getKenteken() {
	return kenteken;
}

int Car::getAantalWheelen() {
	return wiel.size();
}

Wheel* Car::getWheel(int i) {
	return wiel[i];
}

void Car::verwijderWheel(int i) {
	if (0 <= i && i < wiel.size()) {
		wiel.erase(wiel.begin() + i);
	} else {
		throw out_of_range("verkeerde index");
	}
}

void Car::voegWheelToe(int d, const string &mat) {
    Wheel *w = new Wheel(d, mat);
    wiel.push_back(w);
}

Car::Car(const Car &mijnCar) : kenteken(mijnCar.kenteken), type(mijnCar.type) {
	for (unsigned int i = 0; i < mijnCar.wiel.size(); i++) {
		Wheel *w = new Wheel(*(mijnCar.wiel[i]));
		wiel.push_back(w);
	}
}

Car& Car::operator=(const Car &mijnCar) {
	if (&mijnCar == this) return *this;
	type = mijnCar.type;
	kenteken = mijnCar.kenteken;


	for (unsigned int i = 0; i < wiel.size(); i++) {
		delete wiel[i];
	}
	wiel.clear();
	for (unsigned int i = 0; i < mijnCar.wiel.size(); i++) {
		Wheel *w = new Wheel(*(mijnCar.wiel[i]));
		wiel.push_back(w);
	}
	return *this;
}
