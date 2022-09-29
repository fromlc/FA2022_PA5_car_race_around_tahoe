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
constexpr int MILES_TO_CHECKPOINT = 10;

constexpr int MIN_SPEED = 60;
constexpr int MAX_SPEED = 80;
constexpr int CRASH_FACTOR = 8;

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

	RaceCar c1("2002", "Lambo", "Murcielago");
	c1.print();
	cout << "\n";
	RaceCar c2("1965", "Ford", "Mustang");
	c2.print();
	cout << "\n";

	// gas up
	c1.fillUp();
	c2.fillUp();
	cout << "\nBoth gassed up and ready to race!\n";

	// set numeric display format
	cout << setprecision(1) << fixed << showpoint;

	// let's drive!
	race(c1, c2);
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
			<< MILES_TO_CHECKPOINT << " miles to " << scene << "\n";

		rc1.print();
		cout << ": " << rc1.getSpeed() << " mph\n";
		rc2.print();
		cout << ": " << rc2.getSpeed() << " mph\n";
		cout << "\n";

		// crash flag
		bool crash = false;


		// speed too high -> drive random miles
		if (speed1 > MAX_SPEED) {
			rc1.print();
			cout << " CRASHED!@! at " << speed1 << " mph - "
				<< scenery.getRandomCrash() << ".\n";

			rc1.drive((float)(rand() % MILES_TO_CHECKPOINT));
			rc1.setCrash();
			crash = true;
		}
		else {
			rc1.drive(MILES_TO_CHECKPOINT);
		}

		// drive random miles to high speed crash
		if (speed2 > MAX_SPEED) {
			rc2.print();
			cout << " CRASHED!@! at " << speed2 << " mph - "
				<< scenery.getRandomCrash() << ".\n";

			rc2.drive((float)(rand() % MILES_TO_CHECKPOINT));
			rc2.setCrash();
			crash = true;
		}
		else {
			rc2.drive(MILES_TO_CHECKPOINT);
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

	bool rc1Crash = rc1.getCrash();
	bool rc2Crash = rc2.getCrash();

	float rc1Avg = rc1.getAverageSpeed();
	float rc2Avg = rc2.getAverageSpeed();

	// determine winner - fastest average speed with no crash
	if (rc1Crash && rc2Crash) {
		cout << "No winner - both cars crashed.\n";
	}
	else if (rc1Crash) {
		rc2.print();
		cout << " won! The other car crashed.\n";
	}
	else if (rc2Crash) {
		rc1.print();
		cout << " won! The other car crashed.\n";
	}
	else if (rc1Avg > rc2Avg) {
		rc1.print();
		cout << " won!\n";
	}
	else if (rc2Avg > rc1Avg) {
		rc2.print();
		cout << " won!\n";
	}
	else {
		cout << "It's a dead heat!\n";
	}

	// display distances driven
	cout << "\n";
	rc1.print();
	cout << " drove " << rc1.getMilesDriven() << " miles.\n";
	rc2.print();
	cout << " drove " << rc2.getMilesDriven() << " miles.\n";

	// display average speeds
	cout << "\n";
	rc1.print();
	cout << " average speed: " << rc1.getAverageSpeed() << " mph\n";
	rc2.print();
	cout << " average speed: " << rc2.getAverageSpeed() << " mph\n";
	cout << "\n";
}



