//------------------------------------------------------------------------------
// driver.cpp
//------------------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "RaceCar.h"
#include "RaceScenery.h"

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
	RaceScenery scenery;

	float totalMiles = 0;
	int loopCount = 1;

	// start and end race at last checkpoint
	cout << "\nStarting at " << scenery.getLastScene() << "\n";

	int sceneCount = scenery.getSceneCount();

	for (int i = 0; i < sceneCount; i++) {
		// initial speed set in RaceCar constructor
		int speed = rc.getSpeed();

		string scene = scenery.getNextScene();

		// try driving to next checkpoint
		cout << loopCount++ << ": Driving " << DRIVE_MILES << " miles to "
			<< scene << " at " << rc.getSpeed() << "mph\n";

		// drive random miles to high speed crash
		if (speed > MAX_SPEED) {
			cout << "CRASH!@! at " << speed << "mph - "
				<< scenery.getRandomCrash() << ".\n";

			return totalMiles + rc.drive(rand() % DRIVE_MILES);
		}

		// speed ok, log full distance to checkpoint
		totalMiles += rc.drive(DRIVE_MILES);

		// set speed for next stage
		rc.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
	}

	return totalMiles;
}



