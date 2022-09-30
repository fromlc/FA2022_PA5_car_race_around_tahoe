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
void preRace();
void race();
bool driveStage(RaceCar& rc, float miles);
void declareWinner();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	// set numeric display format
	cout << setprecision(1) << fixed << showpoint;

	// display banner, car info
	preRace();

	// let's drive!
	race();
	declareWinner();

	return 0;
}

//------------------------------------------------------------------------------
// pre-race display
//------------------------------------------------------------------------------
void preRace() {
	cout << "RACE AROUND LAKE TAHOE\n\n";

	// car descriptions
	cout << g_c1.getDescription() << "\n";
	cout << g_c2.getDescription() << "\n";

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

		// miles to next checkpoint
		float miles = g_scenery.getNextDistance();

		// set out for next checkpoint
		cout << "Stage " << i + 1 << ": " << miles
			<< " miles to " << g_scenery.getNextScene() << "\n";

		// force both cars to drive
		bool crash1 = driveStage(g_c1, miles);
		bool crash2 = driveStage(g_c2, miles);

		cout << "\n";

		if (crash1 || crash2)
			return;

		// set speed for next stage
		g_c1.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
		g_c2.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
	}
}

//------------------------------------------------------------------------------
// returns true if car exceeds max speed and crashes, false otherwise
//------------------------------------------------------------------------------
bool driveStage(RaceCar& rc, float miles) {

	int speed = rc.getSpeed();
	cout << rc.getDescription() << ": " << speed << " mph";
	 
	// speed too high -> drive part way to checkpoint
	if (speed > MAX_SPEED) {
		cout << " CRASHED!@! - " 
			<< g_scenery.getRandomCrash() << ".\n";

		rc.drive((float)(rand() % (int) miles));
		rc.setCrash();
		return true;
	}

	cout << "\n";
	rc.drive(miles);
	
	return false;
}

//------------------------------------------------------------------------------
// display race outcome
//------------------------------------------------------------------------------
void declareWinner() {
	bool rc1Crash = g_c1.getCrash();
	bool rc2Crash = g_c2.getCrash();

	float rc1Avg = g_c1.getAverageSpeed();
	float rc2Avg = g_c2.getAverageSpeed();

	// determine winner - fastest average speed with no crash
	if (rc1Crash && rc2Crash) {
		cout << "No winner - both cars crashed.\n";
	}
	else if (rc1Crash) {
		cout << g_c2.getDescription()  
			<< " won! The other car crashed.\n";
	}
	else if (rc2Crash) {
		cout << g_c1.getDescription() << " won! The other car crashed.\n";
	}
	else if (rc1Avg > rc2Avg) {
		cout << g_c1.getDescription() << " won!\n";
	}
	else if (rc2Avg > rc1Avg) {
		cout << g_c2.getDescription() << " won!\n";
	}
	else {
		cout << "It's a dead heat!\n";
	}

	// display distances driven
	cout << "\n";
	cout << g_c1.getDescription() << " drove " 
		<< g_c1.getMilesDriven() << " miles.\n";
	cout << g_c2.getDescription() << " drove "
		<< g_c2.getMilesDriven() << " miles.\n";

	// display average speeds
	cout << "\n";
	cout << g_c1.getDescription() << " average speed: "
		<< g_c1.getAverageSpeed() << " mph\n";
	cout << g_c2.getDescription() << " average speed: "
		<< g_c2.getAverageSpeed() << " mph\n";
	cout << "\n";
}
