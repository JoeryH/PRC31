#include "Meetserie.h"
#include <iostream>

#include <string>    // C++ has a so-called string class that resembles the C# String/string classes.
using namespace std; // These two lines (#include and using) are necessary to be able to use the C++ string class.

void showMenu( void )
{
    cout << ("\n\nMENU");
	cout << ("\n===========================");
	cout << ("\n[1] Tonen alle waarden");
	cout << ("\n[2] Toevoegen van een meetwaarde");
	cout << ("\n[3] Testen of er nog meetwaarden geplaatst kunnen worden");
	cout << ("\n[4] Tonen hoe vaak een bepaalde meetwaarde voorkomt");
	cout << ("\n[5] Tonen van de naam van de meetserie");
	cout << ("\n[6] Aanpassen van de naam van de meetserie");
	cout << ("\n[7] Testen of een meetwaarde voorkomt");
	cout << ("\n[9] STOPPEN");
	cout <<  ("\n\nKeuze : ");
}

int main( void )
{
	string naam;
	bool stoppen;
	char antwoord;
	int meetw;
	int aantal;

	Meetserie mijnMeetserie("");

	stoppen=false;
	while (!stoppen)
	{
		showMenu();
		cin.get(antwoord);
		cin.ignore();

		switch (antwoord)
		{
			case '1' :
                mijnMeetserie.bepAantalMeetwaarden(aantal);
                for (int i = 0; i < aantal; i++) {
                    cout << mijnMeetserie.getMeetwaarde(i) << endl;
                }
				break;
			case '2' :
			    if (mijnMeetserie.isVol()) {
                    cout << "Meetserie is vol." << endl;
			    } else {
                    cout << "Geef meetwaarde op : ";
                    cin >> meetw;
                    cin.ignore();
                    mijnMeetserie.voegToe(meetw);
                    cout << endl;
			    }
				break;
			case '3' :
				if (mijnMeetserie.isVol())
					cout << "Meetserie is vol." << endl;
				else
				{
					cout << "Meetserie is niet vol." << endl;
				}
				break;
			case '4' :
			    cout << "Geef meetwaarde op : ";
                cin >> meetw;
                cin.ignore();
				if (!mijnMeetserie.meetwaardeKomtVoor(meetw)) {
					cout << "Meetwaarde komt 0 keer voor" << endl;
				}
				else {
					int aantalMeetw = 0;
					mijnMeetserie.bepAantalMeetwaarden(aantal);
					for (int i = 0; i < aantal; i++) {
                        if (meetw == mijnMeetserie.getMeetwaarde(i)) {
							aantalMeetw++;
                        }
					}
					cout << "Meetwaarde komt  " << aantalMeetw << " keer voor" << endl;
				}
			    break;
			case '5' :
                cout << "Naam van de meetserie is: " << mijnMeetserie.getNaam() << endl;
                break;
			case '6' :
			    cout << "Geef naam van de meetserie : ";
				getline(cin,naam);
				mijnMeetserie.setNaam(naam);
				break;
            case '7':
                cout << "Geef meetwaarde op : ";
                cin >> meetw;
                cin.ignore();
				if (mijnMeetserie.meetwaardeKomtVoor(meetw))
					cout << "Meetwaarde komt voor" << endl;
				else
					cout << "Meetwaarde komt niet voor" << endl;
			    break;
                break;
			case '9' :
				stoppen = true;
				break;
			default:
				cout << "\n\nVerkeerde keuze";
				break;
		}
	}
	return 0;
}
