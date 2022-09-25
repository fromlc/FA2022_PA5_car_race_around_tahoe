//------------------------------------------------------------------------------
// driver.cpp
//------------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Car.h"

constexpr float DRIVE_MILES = 10;
constexpr float ADD_GALLONS = 1;

using std::cout;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	Car c;
	c.print();

	// add 1 gallon of fuel
	float gallonsAdded = c.addFuel(ADD_GALLONS);

	float driven;
	do {
		driven = c.drive(DRIVE_MILES);
		cout << "Trying to drive "
			<< DRIVE_MILES 
			<<  " miles.Miles driven : "
			<< driven << "\n";
	} while (driven > 0);
}