
#include "Z_Obj.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

Z_Obj::Z_Obj(int zip, string city, string state, string abbr, string county, float lat, float lon)
: zip(zip), city(city), state(state), abbr(abbr), county(county), lat(lat), lon(lon)
{
}

void Z_Obj::printZ() {
    cout << zip << ", " << city << ", " << state << ", " << abbr << ", " << county << ", " << lat << ", " << lon << endl; 
}
// friend ostream& operator<<(ostream& os, const Z_Obj& z);
// If you want to override << so you can just use cout to print your Z_Objs.

bool Z_Obj::lessThan(Z_Obj *z) {
    return zip < z->zip;
}

