#include "Meetserie.h"
#include <iostream>
using namespace std;

Meetserie::Meetserie(string nm)
: naam(nm), count(0)
{
}

string Meetserie::getNaam()
{
	return naam;
}

void Meetserie::setNaam(string nm)
{
	Meetserie *ptr = this;
	ptr->naam = nm;
}

bool Meetserie::isVol() {
    return count == MaxAantalMeetwaarden;
}

void Meetserie::voegToe(int meetw)
{
	Meetserie *ptr = this;
	if (!ptr->isVol()) {
        meetwaarden[count] = meetw;
        count++;
	}
}

bool Meetserie::meetwaardeKomtVoor(int meetw) {
    for(int i = 0; i < count; i++) {
        if (meetwaarden[i] == meetw) {
            return true;
        }
    }
    return false;
}

int Meetserie::getMeetwaarde(int i)
{
	return meetwaarden[i];
}

void Meetserie::bepAantalMeetwaarden(int &aantal) {
    aantal = count;
}
