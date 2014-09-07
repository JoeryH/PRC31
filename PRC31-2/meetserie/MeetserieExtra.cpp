#include "MeetserieExtra.h"
#include <fstream>

MeetserieExtra::MeetserieExtra(string nm) :Meetserie(nm),aantalVerschillendeWaarden(0){
}

int MeetserieExtra::getAantalKeer(int meetw) {
	int aantalMeetw = 0;
	for(int i = 0; i < count; i++) {
        if (meetwaarden[i] == meetw) {
			aantalMeetw++;
		}
	}
	return aantalMeetw;
}

void MeetserieExtra::voegToeMeetserie(const Meetserie &meets) {
	int aantal = 0;
	meets.bepAantalMeetwaarden(aantal);
	for (int i = 0; i < aantal; i++) {
		voegToe(meets.getMeetwaarde(i));
	}
}

void MeetserieExtra::voegToe(int meetw) {
	if (!Meetserie::meetwaardeKomtVoor(meetw)) {
		aantalVerschillendeWaarden++;
	}
	Meetserie::voegToe(meetw);
}

int MeetserieExtra::getAantalVerschillendeWaarden() {
	return aantalVerschillendeWaarden;
}


void MeetserieExtra::save() {
	ofstream outfile;
	outfile.open("meetserieextra.txt");
	outfile << count << endl;
	outfile << aantalVerschillendeWaarden << endl;
	for (int i = 0; i < count; i++) {
		outfile << meetwaarden[i] << endl;
	}
	outfile << naam << endl;
	outfile.close();
}

MeetserieExtra MeetserieExtra::load() {
    ifstream infile;
    infile.open("meetserieextra.txt");
    MeetserieExtra m("");
    infile >> m.count;
	infile >> m.aantalVerschillendeWaarden;
    for (int i = 0; i < m.count; i++) {
		infile >> m.meetwaarden[i];
	}
    infile >> m.naam;
    infile.close();
    return m;
}
