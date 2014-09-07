#ifndef VRACHTWAGENH
#define VRACHTWAGENH

#include "wagen.h"

class Vrachtwagen : public Wagen
{
  private:
    int *vermogen;

  public:
	Vrachtwagen(const string &type, const string &matSoort, int diam,int aantalWielen, int vermogen);
    /* pre : diam > 0 en aantalWielen > 2 en vermogen > 0
       post: Er is een object Vrachtwagen gecreerd met vermogen gelijk aan vermogen en het object
             bevat aantalwielen Wiel objecten met materiaalsoort
             en diameter van de wielen respectivelijk type, matsoort en diam
    */

	virtual ~Vrachtwagen();
	/* pre : -
	   post: het object Vrachtwagen is opgeruimd inclusief het beheerd geheugen.
	*/

	int getVermogen();
	/* pre : -
	   post: het vermogen is opgeleverd
	*/

	Vrachtwagen(const Vrachtwagen &mijnVrachtwagen);
    /* pre : -
	   post: er is een object Vrachtwagen aangemaakt met behulp van de eigenschappen van
	         mijnVrachtwagen waarbij objecten zijn gekopieerd en NIET alleen de pointers
    */

	Vrachtwagen& operator=(const Vrachtwagen &mijnVrachtwagen);
	/* pre : -
	   post: de eigenschappen van dit object zijn vervangen door de eigenschappen
	         van mijnVrachtwagen waarij beheerde objecten in mijnVrachtwagen zijn gekopieerd
	*/
};
#endif
