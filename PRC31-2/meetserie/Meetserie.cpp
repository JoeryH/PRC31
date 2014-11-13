#include "Meetserie.h"
#include <iostream>
#include <fstream>
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
	naam = nm;
}

bool Meetserie::isVol() {
    return count == MaxAantalMeetwaarden;
}

void Meetserie::voegToe(int meetw)
{
	if (!isVol()) {
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

int Meetserie::getMeetwaarde(int i) const
{
	return meetwaarden[i];
}

void Meetserie::bepAantalMeetwaarden(int &aantal) const {
    aantal = count;
}

void Meetserie::save() {
	ofstream outfile;
	outfile.open("meetserie.txt");
	outfile << count << endl;
	for (int i = 0; i < count; i++) {
		outfile << meetwaarden[i] << endl;
	}
	outfile << naam << endl;
	outfile.close();
}

Meetserie Meetserie::load() {
    ifstream infile;
    infile.open("meetserie.txt");
    Meetserie m("");
    infile >> m.count;
    for (int i = 0; i < m.count; i++) {
		infile >> m.meetwaarden[i];
	}
    infile >> m.naam;
    infile.close();
    return m;
}


