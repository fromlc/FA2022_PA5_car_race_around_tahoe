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
// globals
//------------------------------------------------------------------------------
string g_scenery[] = {
	"Stage 1", "Stage 2", "Stage 3", "Stage 4", "Stage 5",
	"Stage 6", "Stage 7", "Stage 8", "Stage 9", "Stage 10",
};

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	Car c;
	c.print();

	// set numeric display format
	cout << setprecision(1) << fixed << showpoint;

	// gas 'er up
	float gallonsAdded = c.fillUp();
	cout << "\nGassed up with " << gallonsAdded << " gallons.\n";

	// add 1 gallon of fuel
	gallonsAdded = c.addFuel(ADD_GALLONS);
	cout << "Added " << gallonsAdded << " gallons.\n";

	// loop setup
	cout << "Let's drive!\n\n";
	float driven;
	float totalMiles = 0;
	int times = sizeof(g_scenery) / sizeof(string);

	for (int i = 0; i < times; i++) {
		driven = c.drive(DRIVE_MILES);
		cout << i << ": Driving " << g_scenery[i] << ": " << driven << " miles.\n";
		
		totalMiles += driven;
	}

	cout << "\nDrove " << totalMiles << " miles.\n";
	cout << "Gallons of gas left: " << c.readFuelGauge() << "\n";
	cout << "Miles left in this tank: " << c.canDriveMiles() << "\n";

	return 0;
}