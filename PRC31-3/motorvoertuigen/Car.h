//---------------------------------------------------------------------------
#ifndef CarH
#define CarH
//---------------------------------------------------------------------------

#include "Wheel.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Car
{
  private:
     vector<Wheel*> wiel;
     string kenteken;
     string type;
  public:
    Car(const string &type, const string &matSoort, int diam,int aantalWheelen);
    /* pre : diam > 0 en aantalWheelen > 2
       post: Er is een object Car gecreerd en het object Car
             bevat aantalwielen Wheel objecten met materiaalsoort
             en diameter van de wielen espectivelijk type, matsoort en diam
    */

   virtual ~Car();
   	/* pre : -
	   post: het object Car is opgeruimd inclusief het beheerd geheugen.
	*/

    string getType();
    /* pre : -
       post: getType()=type van <Car>
    */

    void setKenteken(const string &kenteken);
    /* pre : -
       post: kenteken van <Car> is kenteken
    */

    string getKenteken();
    /* pre : -
       post: getKenteken()= kenteken van <Car>
    */

    int getAantalWheelen();
    /* pre : -
       post: getAantalWheelen()=aantal wielen van <Car>
    */

    Wheel* getWheel(int i);
    /* pre : 0<=i<aantal wielen van <wagen>
       post: getWheel(i) = het i-de wiel van <Car>
    */

    void verwijderWheel(int i);
    /* pre : -
       post: Als 0<=i<aantal wielen van <wagen>
             Dan is het i-de wiel van <Car> verwijderd
             Anders out_of_range exception met tekst "verkeerde index"
               opgeworpen
    */

	void voegWheelToe(int d, const string &mat);
	/* pre : d > 0
	   post: er is een wiel met diameter d van materiaal mat toegevoegd aan Car
	*/

	Car(const Car &mijnCar);
    /* pre : -
	   post: er is een object Car aangemaakt met behulp van de eigenschappen van
	         mijnCar waarbij objecten zijn gekopieerd en NIET alleen de pointers
    */

	Car& operator=(const Car &mijnCar);
	/* pre : -
	   post: de eigenschappen van dit object zijn vervangen door de eigenschappen
	         van mijnCar waarij beheerde objecten in mijnCar zijn gekopieerd
	*/
};

#endif
