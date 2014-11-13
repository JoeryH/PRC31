#ifndef VRACHTWAGENH
#define VRACHTWAGENH

#include "car.h"

class Truck : public Car
{
  private:
    int *vermogen;

  public:
	Truck(const string &type, const string &matSoort, int diam,int aantalWheelen, int vermogen);
    /* pre : diam > 0 en aantalWheelen > 2 en vermogen > 0
       post: Er is een object Truck gecreerd met vermogen gelijk aan vermogen en het object
             bevat aantalwielen Wheel objecten met materiaalsoort
             en diameter van de wielen respectivelijk type, matsoort en diam
    */

	virtual ~Truck();
	/* pre : -
	   post: het object Truck is opgeruimd inclusief het beheerd geheugen.
	*/

	int getVermogen();
	/* pre : -
	   post: het vermogen is opgeleverd
	*/

	Truck(const Truck &mijnTruck);
    /* pre : -
	   post: er is een object Truck aangemaakt met behulp van de eigenschappen van
	         mijnTruck waarbij objecten zijn gekopieerd en NIET alleen de pointers
    */

	Truck& operator=(const Truck &mijnTruck);
	/* pre : -
	   post: de eigenschappen van dit object zijn vervangen door de eigenschappen
	         van mijnTruck waarij beheerde objecten in mijnTruck zijn gekopieerd
	*/
};
#endif
