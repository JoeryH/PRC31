//---------------------------------------------------------------------------
#ifndef WagenH
#define WagenH
//---------------------------------------------------------------------------

#include "Wiel.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Wagen
{
  private:
     vector<Wiel*> wiel;
     string kenteken;
     string type;
  public:
    Wagen(const string &type, const string &matSoort, int diam,int aantalWielen);
    /* pre : diam > 0 en aantalWielen > 2
       post: Er is een object Wagen gecreerd en het object Wagen
             bevat aantalwielen Wiel objecten met materiaalsoort
             en diameter van de wielen espectivelijk type, matsoort en diam
    */

   virtual ~Wagen();
   	/* pre : -
	   post: het object Wagen is opgeruimd inclusief het beheerd geheugen.
	*/

    string getType();
    /* pre : -
       post: getType()=type van <Wagen>
    */

    void setKenteken(const string &kenteken);
    /* pre : -
       post: kenteken van <Wagen> is kenteken
    */

    string getKenteken();
    /* pre : -
       post: getKenteken()= kenteken van <Wagen>
    */

    int getAantalWielen();
    /* pre : -
       post: getAantalWielen()=aantal wielen van <Wagen>
    */

    Wiel* getWiel(int i);
    /* pre : 0<=i<aantal wielen van <wagen>
       post: getWiel(i) = het i-de wiel van <Wagen>
    */

    void verwijderWiel(int i);
    /* pre : -
       post: Als 0<=i<aantal wielen van <wagen>
             Dan is het i-de wiel van <Wagen> verwijderd
             Anders out_of_range exception met tekst "verkeerde index"
               opgeworpen
    */

	void voegWielToe(int d, const string &mat);
	/* pre : d > 0
	   post: er is een wiel met diameter d van materiaal mat toegevoegd aan Wagen
	*/

	Wagen(const Wagen &mijnWagen);
    /* pre : -
	   post: er is een object Wagen aangemaakt met behulp van de eigenschappen van
	         mijnWagen waarbij objecten zijn gekopieerd en NIET alleen de pointers
    */

	Wagen& operator=(const Wagen &mijnWagen);
	/* pre : -
	   post: de eigenschappen van dit object zijn vervangen door de eigenschappen
	         van mijnWagen waarij beheerde objecten in mijnWagen zijn gekopieerd
	*/
};

#endif
