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
constexpr int MILES_TO_CHECKPOINT = 10; //#TODO
constexpr int MIN_SPEED = 60;
constexpr int MAX_SPEED = 80;
// higher crash factor makes crashes more likely
constexpr int CRASH_FACTOR = 5;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
RaceCar g_c1;
RaceCar g_c2("1965", "Ford", "Mustang");
RaceScenery g_scenery;

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
void preRaceDisplay();
void race();
bool checkForCrash(RaceCar& rc);
void declareWinner();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	// set numeric display format
	cout << setprecision(1) << fixed << showpoint;

	preRaceDisplay();

	// let's drive!
	race();
	declareWinner();

	return 0;
}

//------------------------------------------------------------------------------
// pre-race display
//------------------------------------------------------------------------------
void preRaceDisplay() {
	cout << "RACE AROUND LAKE TAHOE\n\n";

	// car descriptions
	g_c1.print();
	cout << "\n";
	g_c2.print();
	cout << "\n";

	// gas up
	g_c1.fillUp();
	g_c2.fillUp();
	cout << "\nBoth gassed up and ready to race!\n";
}

//------------------------------------------------------------------------------
// run the race loop
//------------------------------------------------------------------------------
void race() {
	// start and end race at last checkpoint
	cout << "\nStarting at " << g_scenery.getLastScene() << "\n\n";

	int sceneCount = g_scenery.getSceneCount();

	for (int i = 0; i < sceneCount; i++) {
		// set out for next checkpoint
		cout << "Stage " << i + 1 << ": "
			<< MILES_TO_CHECKPOINT << " miles to " 
			<< g_scenery.getNextScene() << "\n";

		// force both cars to drive
		bool crash1 = checkForCrash(g_c1);
		bool crash2 = checkForCrash(g_c2);

		cout << "\n";

		if (crash1 || crash2)
			return;

		// set speed for next stage
		g_c1.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
		g_c2.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
	}
}

//------------------------------------------------------------------------------
// returns true if rc exceeds max speed, false otherwise
//------------------------------------------------------------------------------
bool checkForCrash(RaceCar& rc) {

	float speed = rc.getSpeed();
	rc.print();
	cout << ": " << speed << " mph\n";
	 
	// speed too high -> drive random miles
	if (speed > MAX_SPEED) {
		rc.print();
		cout << " CRASHED!@! at " << speed << " mph - "
			<< g_scenery.getRandomCrash() << ".\n";

		rc.drive((float)(rand() % MILES_TO_CHECKPOINT));
		rc.setCrash();
		return true;
	}

	rc.drive(MILES_TO_CHECKPOINT);
	return false;
}

//------------------------------------------------------------------------------
// display race outcome
//------------------------------------------------------------------------------
void declareWinner() {
	cout << "\n";

	bool rc1Crash = g_c1.getCrash();
	bool rc2Crash = g_c2.getCrash();

	float rc1Avg = g_c1.getAverageSpeed();
	float rc2Avg = g_c2.getAverageSpeed();

	// determine winner - fastest average speed with no crash
	if (rc1Crash && rc2Crash) {
		cout << "No winner - both cars crashed.\n";
	}
	else if (rc1Crash) {
		g_c2.print();
		cout << " won! The other car crashed.\n";
	}
	else if (rc2Crash) {
		g_c1.print();
		cout << " won! The other car crashed.\n";
	}
	else if (rc1Avg > rc2Avg) {
		g_c1.print();
		cout << " won!\n";
	}
	else if (rc2Avg > rc1Avg) {
		g_c2.print();
		cout << " won!\n";
	}
	else {
		cout << "It's a dead heat!\n";
	}

	// display distances driven
	cout << "\n";
	g_c1.print();
	cout << " drove " << g_c1.getMilesDriven() << " miles.\n";
	g_c2.print();
	cout << " drove " << g_c2.getMilesDriven() << " miles.\n";

	// display average speeds
	cout << "\n";
	g_c1.print();
	cout << " average speed: " << g_c1.getAverageSpeed() << " mph\n";
	g_c2.print();
	cout << " average speed: " << g_c2.getAverageSpeed() << " mph\n";
	cout << "\n";
}
