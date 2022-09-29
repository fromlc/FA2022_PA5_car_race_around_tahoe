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
// higher crash factor makes crashes more likely
constexpr int CRASH_FACTOR = 5;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
RaceCar g_c1;
RaceCar g_c2("1965", "Ford", "Mustang");

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
	RaceScenery scenery;

	// start and end race at last checkpoint
	cout << "\nStarting at " << scenery.getLastScene() << "\n\n";

	int sceneCount = scenery.getSceneCount();

	for (int i = 0; i < sceneCount; i++) {
		// initial speed set in RaceCar constructor
		int speed1 = g_c1.getSpeed();
		int speed2 = g_c2.getSpeed();

		string scene = scenery.getNextScene();

		// try driving to next checkpoint
		cout << "Stage " << i + 1 << ": "
			<< MILES_TO_CHECKPOINT << " miles to " << scene << "\n";

		g_c1.print();
		cout << ": " << g_c1.getSpeed() << " mph\n";
		g_c2.print();
		cout << ": " << g_c2.getSpeed() << " mph\n";
		cout << "\n";

		// crash flag
		bool crash = false;


		// speed too high -> drive random miles
		if (speed1 > MAX_SPEED) {
			g_c1.print();
			cout << " CRASHED!@! at " << speed1 << " mph - "
				<< scenery.getRandomCrash() << ".\n";

			g_c1.drive((float)(rand() % MILES_TO_CHECKPOINT));
			g_c1.setCrash();
			crash = true;
		}
		else {
			g_c1.drive(MILES_TO_CHECKPOINT);
		}

		// drive random miles to high speed crash
		if (speed2 > MAX_SPEED) {
			g_c2.print();
			cout << " CRASHED!@! at " << speed2 << " mph - "
				<< scenery.getRandomCrash() << ".\n";

			g_c2.drive((float)(rand() % MILES_TO_CHECKPOINT));
			g_c2.setCrash();
			crash = true;
		}
		else {
			g_c2.drive(MILES_TO_CHECKPOINT);
		}
		
		if (crash)
			return;

		// set speed for next stage
		g_c1.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
		g_c2.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
	}
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
