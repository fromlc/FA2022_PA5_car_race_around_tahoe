//------------------------------------------------------------------------------
// driver.cpp
//------------------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "RaceCar.h"

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int DRIVE_MILES = 10;
constexpr float ADD_GALLONS = 1;

constexpr int MIN_SPEED = 60;
constexpr int MAX_SPEED = 80;
constexpr int CRASH_FACTOR = 5;

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;
using std::fixed;
using std::setprecision;
using std::showpoint;
using std::vector;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
float race(RaceCar& rc);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	RaceCar c;
	c.print();

	// set numeric display format
	cout << setprecision(1) << fixed << showpoint;

	// gas up
	float gallonsAdded = c.fillUp();
	cout << "Gassed up with " << gallonsAdded << " gallons.\n";
	cout << "Let's drive around Lake Tahoe!\n";

	// let's drive!
	float milesDriven = race(c);

	cout << "\nDrove " << milesDriven << " miles.\n";
	cout << "Fuel left: " << c.readFuelGauge() << " gallons.\n";
	cout << "Miles left in this tank: " << c.canDriveMiles() << ".\n";

	return 0;
}

//------------------------------------------------------------------------------
// run the race loop
//------------------------------------------------------------------------------
float race(RaceCar& rc) {
	float driven;
	float totalMiles = 0;
	int loopCount = 1;

	vector<string> scenery = {
		"Zephyr Cove",
		"Fallen Leaf Lake",
		"Rubicon Point",
		"Sugar Pine Point",
		"Tahoe City",
		"Carnelian Bay",
		"Crystal Bay",
		"Sand Harbor",
		"Thunderbird Lodge",
		"Spooner Lake",
	};

	cout << "\nStarting at " << scenery.back() << "\n";

	for (auto scene : scenery) {
		driven = rc.drive(DRIVE_MILES);
		int speed = rc.getSpeed();

		cout << loopCount++ << ": Driving " << driven << " miles to "
			<< scene << " at " << rc.getSpeed() << "mph\n";

		if (speed > MAX_SPEED) {
			cout << "CRASH!@! at " << speed << "mph\n";
			totalMiles += (rand() % DRIVE_MILES);
			break;
		}
		else {
			totalMiles += driven;

			// set speed for next stage
			rc.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
		}
	}

	return totalMiles;
}



