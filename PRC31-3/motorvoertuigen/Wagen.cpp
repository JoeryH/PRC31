#include "Wagen.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

Wagen::Wagen(const string &type, const string &matSoort, int diam, int aantalWielen) {
	this->type = type;
	for (int i=0; i < aantalWielen; i++) {
		Wiel *w = new Wiel(diam, matSoort);
		wiel.push_back(w);
	}
}

Wagen::~Wagen() {
	for (unsigned int i = 0; i < wiel.size(); i++) {
		delete wiel[i];
	}
}

string Wagen::getType() {
	return type;
}

void Wagen::setKenteken(const string &kenteken) {
	this->kenteken = kenteken;
}

string Wagen::getKenteken() {
	return kenteken;
}

int Wagen::getAantalWielen() {
	return wiel.size();
}

Wiel* Wagen::getWiel(int i) {
	return wiel[i];
}

void Wagen::verwijderWiel(int i) {
	if (0 <= i && i < wiel.size()) {
		wiel.erase(wiel.begin() + i);
	} else {
		throw out_of_range("verkeerde index");
	}
}

void Wagen::voegWielToe(int d, const string &mat) {
    Wiel *w = new Wiel(d, mat);
    wiel.push_back(w);
}

Wagen::Wagen(const Wagen &mijnWagen) : kenteken(mijnWagen.kenteken), type(mijnWagen.type) {
	for (unsigned int i = 0; i < mijnWagen.wiel.size(); i++) {
		Wiel *w = new Wiel(*(mijnWagen.wiel[i]));
		wiel.push_back(w);
	}
}

Wagen& Wagen::operator=(const Wagen &mijnWagen) {
	if (&mijnWagen == this) return *this;
	type = mijnWagen.type;
	kenteken = mijnWagen.kenteken;


	for (unsigned int i = 0; i < wiel.size(); i++) {
		delete wiel[i];
	}
	wiel.clear();
	for (unsigned int i = 0; i < mijnWagen.wiel.size(); i++) {
		Wiel *w = new Wiel(*(mijnWagen.wiel[i]));
		wiel.push_back(w);
	}
	return *this;
}
