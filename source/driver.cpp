//------------------------------------------------------------------------------
// driver.cpp
//------------------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <string>

#include "Car.h"

constexpr float DRIVE_MILES = 10;
constexpr float ADD_GALLONS = 1;

using std::cout;
using std::fixed;
using std::setprecision;
using std::showpoint;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	Car c;
	c.print();

	// set numeric display format
	cout << setprecision(5) << fixed << showpoint;

	// gas 'er up
	float gallonsAdded = c.fillUp();
	cout << "\nGassed up with " << gallonsAdded << " gallons.\n";

	// add 1 gallon of fuel
	gallonsAdded = c.addFuel(ADD_GALLONS);
	cout << "Added " << gallonsAdded << " gallons.\n";

	// loop setup
	float driven;
	float totalMiles = 0;
	int loopCount = 0;
	cout << "Let's drive!\n\n";

	while ((driven = c.drive(DRIVE_MILES)) > 0) {
		cout << ++loopCount << ": Driving " << driven << " miles.\n";
		
		totalMiles += driven;
	}

	cout << "\nDrove " << totalMiles << " miles.\n";
	cout << "Ran out of gas!\n";

	return 0;
}