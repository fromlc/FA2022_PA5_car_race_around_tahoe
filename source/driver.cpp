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
void race(RaceCar& rc1, RaceCar& rc2);
void declareWinner(RaceCar& rc1, RaceCar& rc2);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	cout << "RACE AROUND LAKE TAHOE\n\n";

	RaceCar c1;
	c1.print();
	cout << "\n";
	RaceCar c2("1965", "Ford", "Mustang");
	c2.print();
	cout << "\n";

	// gas up
	c1.fillUp();
	c2.fillUp();

	// set numeric display format
	cout << setprecision(1) << fixed << showpoint;
	
	cout << "\nBoth gassed up and ready to race!\n";

	// let's drive!
	race(c1, c2);

	// display distances driven
	cout << "\n";
	c1.print();
	cout << " drove " << c1.getMilesDriven() << " miles.\n";
	c2.print();
	cout << " drove " << c2.getMilesDriven() << " miles.\n";

	declareWinner(c1, c2);

	return 0;
}

//------------------------------------------------------------------------------
// run the race loop
//------------------------------------------------------------------------------
void race(RaceCar& rc1, RaceCar& rc2) {
	RaceScenery scenery;

	// start and end race at last checkpoint
	cout << "\nStarting at " << scenery.getLastScene() << "\n\n";

	int sceneCount = scenery.getSceneCount();

	for (int i = 0; i < sceneCount; i++) {
		// initial speed set in RaceCar constructor
		int speed1 = rc1.getSpeed();
		int speed2 = rc2.getSpeed();

		string scene = scenery.getNextScene();

		// try driving to next checkpoint
		cout << "Stage " << i + 1 << ": "
			<< DRIVE_MILES << " miles to " << scene << "\n";

		rc1.print();
		cout << ": " << rc1.getSpeed() << "mph\n";
		rc2.print();
		cout << ": " << rc2.getSpeed() << "mph\n";
		cout << "\n";

		// crash flag
		bool crash = false;

		// drive random miles to high speed crash
		if (speed1 > MAX_SPEED) {
			rc1.print();
			cout << " CRASHED!@! at " << speed1 << "mph - "
				<< scenery.getRandomCrash() << ".\n";

			rc1.drive((float)(rand() % DRIVE_MILES));
			rc1.setCrash();
			crash = true;
		}
		else {
			rc1.drive(DRIVE_MILES);
		}

		// drive random miles to high speed crash
		if (speed2 > MAX_SPEED) {
			rc2.print();
			cout << " CRASHED!@! at " << speed2 << "mph - "
				<< scenery.getRandomCrash() << ".\n";

			rc2.drive((float)(rand() % DRIVE_MILES));
			rc2.setCrash();
			crash = true;
		}
		else {
			rc2.drive(DRIVE_MILES);
		}
		
		if (crash)
			return;

		// set speed for next stage
		rc1.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
		rc2.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
	}
}

//------------------------------------------------------------------------------
// display race outcome
//------------------------------------------------------------------------------
void declareWinner(RaceCar& rc1, RaceCar& rc2) {
	cout << "\n";

	// determine winner - most miles driven, no crash
	if (rc1.getCrash() && rc2.getCrash())
		cout << "\nNo winner - both cars crashed.";
	else if (rc1.getCrash()) {
		rc2.print();
		cout << " won - the other car crashed.";
	}
	else if (rc2.getCrash()) {
		rc1.print();
		cout << " won - the other car crashed.";
	}
	else if (rc1.getAverageSpeed() > rc2.getAverageSpeed()) {
		rc1.print();
		cout << " won!\n";
		rc1.print();
		cout << " average speed : " << rc1.getAverageSpeed() << "\n";
		rc2.print();
		cout << " average speed : " << rc2.getAverageSpeed() << "\n";
	}
	else if (rc2.getAverageSpeed() > rc1.getAverageSpeed()) {
		rc2.print();
		cout << " won!\n";
		rc2.print();
		cout << " average speed : " << rc2.getAverageSpeed() << "\n";
		rc1.print();
		cout << " average speed : " << rc1.getAverageSpeed() << "\n";
	}
	else {
		cout << "It's a dead heat!\n";
		rc1.print();
		cout << " average speed: " << rc1.getAverageSpeed() << "\n";
		rc2.print();
		cout << " average speed: " << rc2.getAverageSpeed() << "\n";
	}

	cout << "\n";
}



