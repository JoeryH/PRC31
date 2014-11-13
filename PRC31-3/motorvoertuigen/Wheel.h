//---------------------------------------------------------------------------

#ifndef WheelH
#define WheelH
//---------------------------------------------------------------------------

#include <string>
using std::string;

/*
 *  destructor, copy constructor en operator= overloading is niet nodig, want er zitten 
 *  geen pointers die wijzen naar objecten die beheerd worden (geen new en delete)
*/

class Wheel
{
  private:
    int diameter;
    string materiaal;
  public:
    Wheel(int d, const string &mat);
    /* pre : d > 0
       post: Er is een object Wheel gecreerd met diameter en materiaal van
             Wheel is respectivelijk d en mat
    */
    string getMateriaal();
    /* pre : -
       post: getMateriaal()= materiaal van <Wheel>
    */

    void setMateriaal(const string &mat);
    /* pre : -
       post: Het materiaal van object <Wheel> is mat
    */

    int getDiameter();
    /* pre : -
       post getDiameter() = diameter van <Wheel>
    */

};

#endif
 