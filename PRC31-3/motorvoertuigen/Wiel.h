//---------------------------------------------------------------------------

#ifndef WielH
#define WielH
//---------------------------------------------------------------------------

#include <string>
using std::string;

/*
 *  destructor, copy constructor en operator= overloading is niet nodig, want er zitten 
 *  geen pointers die wijzen naar objecten die beheerd worden (geen new en delete)
*/

class Wiel
{
  private:
    int diameter;
    string materiaal;
  public:
    Wiel(int d, const string &mat);
    /* pre : d > 0
       post: Er is een object Wiel gecreerd met diameter en materiaal van
             Wiel is respectivelijk d en mat
    */
    string getMateriaal();
    /* pre : -
       post: getMateriaal()= materiaal van <Wiel>
    */

    void setMateriaal(const string &mat);
    /* pre : -
       post: Het materiaal van object <Wiel> is mat
    */

    int getDiameter();
    /* pre : -
       post getDiameter() = diameter van <Wiel>
    */

};

#endif
 