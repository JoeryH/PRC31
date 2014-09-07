#include "MeetserieExtra.h"
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
	cout << ("\n[8] Toevoegen van de meetserie m1 met waarden 8 en 9");
	cout << ("\n[9] Toevoegen van de meetserieExtra mx1 met waarden -2 en -3");
	cout << ("\n[a] Tonen van aantal verschillende waarden");
	cout << ("\n[v] Tonen hoe vaak een bepaalde meetwaarde voorkomt");
	cout << ("\n[s] Opslaan dummy meetserie (test)");
	cout << ("\n[l] Laden dummy meetserie (test)");
	cout << ("\n[d] Opslaan huidige meetserieextra");
	cout << ("\n[k] Laden huidige meetserieextra");
	cout << ("\n[q] STOPPEN");
	cout <<  ("\n\nKeuze : ");
}

int main( void )
{
	string naam;
	bool stoppen;
	char antwoord;
	int meetw;
	int aantal;

	MeetserieExtra mijnMeetserie("");

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
			case '8':
				{
					Meetserie m1("");
					m1.voegToe(8); m1.voegToe(9);
					mijnMeetserie.voegToeMeetserie(m1);
				}

				break;
			case '9':
                {
                	MeetserieExtra mx1("");
					mx1.voegToe(-2); mx1.voegToe(-3);
					mijnMeetserie.voegToeMeetserie(mx1);
                }
				break;
			case 'a':
                cout << "Aantal verschillende waarden: " << mijnMeetserie.getAantalVerschillendeWaarden() << endl;
				break;
			case 'v':
                cout << "Geef meetwaarde op : ";
                cin >> meetw;
                cin.ignore();
                cout << "Meetwaarde " << meetw << " komt " << mijnMeetserie.getAantalKeer(meetw) << " keer voor" << endl;
				break;
			case 's':
                {
                	Meetserie m1("m1");
                	m1.voegToe(8); m1.voegToe(9);
                	m1.save();
                }
				break;
			case 'l':
				{
					Meetserie m1 = Meetserie::load();
					int aantal = 0;
					 m1.bepAantalMeetwaarden(aantal);
					cout << "Naam: " << m1.getNaam() << endl;
					cout << "Aantal waardes: " << aantal << endl;
				}
				break;
			case 'd':
				mijnMeetserie.save();
				cout << "Meetserie opgeslagen in meetserieextra.txt" << endl;
				break;
			case 'k':
				mijnMeetserie = MeetserieExtra::load();
				cout << "Meetserie geladen uit meetserieextra.txt" << endl;
				break;
			case 'q' :
				stoppen = true;
				break;
			default:
				cout << "\n\nVerkeerde keuze";
				break;
		}
	}
	return 0;
}
