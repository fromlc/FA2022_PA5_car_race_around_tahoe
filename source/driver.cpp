//------------------------------------------------------------------------------
// driver.cpp
//------------------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <string>

#include "ansi_colors.h"

#include "RaceCar.h"
#include "RaceScenery.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;
using std::showpoint;
using std::vector;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
// constexpr int MILES_TO_CHECKPOINT = 10;
constexpr int MIN_SPEED = 60;
constexpr int MAX_SPEED = 80;
// crash factor <= 10, higher means more crashes
constexpr int CRASH_FACTOR = 3;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
RaceCar g_c1;
RaceCar g_c2("1965", "Ford", "Mustang");
RaceScenery g_scenery;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void preRace();
void raceLoop();
void race();
void driveStage(RaceCar& rc, float miles);
void declareWinner();

// inline functions call RaceCar method for both cars
inline void driveStage(float miles);
inline void setRandomSpeed();
inline void reset();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	// set numeric display format
	cout << setprecision(1) << fixed << showpoint;
	// display banner, car info
	preRace();
	// race until user quits
	raceLoop();

	return 0;
}

//------------------------------------------------------------------------------
// pre-race display
//------------------------------------------------------------------------------
void preRace() {
	cout << CYAN << "\nRACE AROUND LAKE TAHOE\n\n" << RESET_COLORS;

	// car descriptions
	cout << "Stock " << g_c1.getDescription() << " takes on souped-up ";
	cout << g_c2.getDescription() << ".\n";

	// races starts and ends at last checkpoint
	cout << "\nThe race starts and ends at "
		<< g_scenery.getLastScene() << ".\n";
}

//------------------------------------------------------------------------------
// run races until user quits
//------------------------------------------------------------------------------
void raceLoop() {

	char chCmd = 'y';
	while (chCmd == 'y' || chCmd == 'Y') {
		// clear crash flags, gas up, zero miles driven
		reset();
		// drive!
		race();
		declareWinner();

		cout << YELLOW << "Race again (y/n)? " << RESET_COLORS;
		cin >> chCmd;
		cout << "\n";
	}

	cout << "Goodbye!\n\n";
}

//------------------------------------------------------------------------------
// run one race
//------------------------------------------------------------------------------
void race() {
	int sceneCount = g_scenery.getSceneCount();

	for (int i = 0; i < sceneCount; i++) {

		// set out on next stage
		float miles = g_scenery.getNextDistance();

		cout << CYAN << "Stage " << i + 1 << ": "
			<< miles << " miles to " << g_scenery.getNextScene()
			<< RESET_COLORS << "\n";

		// drive both cars to next checkpoint
		driveStage(miles);
		cout << "\n";

		if (g_c1.getCrash() || g_c2.getCrash())
			return;

		// set both cars' speed for next stage
		setRandomSpeed();
	}
}

//------------------------------------------------------------------------------
// returns true if car exceeds max speed and crashes, false otherwise
//------------------------------------------------------------------------------
void driveStage(RaceCar& rc, float miles) {

	int speed = rc.getSpeed();
	cout << "The " << rc.getModel() << " averaged " << speed << " mph";

	// speed too high -> drive part way to checkpoint
	if (speed > MAX_SPEED) {
		cout << " but it " << RED << "CRASHED!@!" << RESET_COLORS <<
			" It " << g_scenery.getRandomCrash() << ".\n";

		rc.drive((float)(rand() % (int)miles));
		rc.setCrash();
		return;
	}

	cout << "\n";
	rc.drive(miles);
}

//------------------------------------------------------------------------------
// display race outcome
//------------------------------------------------------------------------------
void declareWinner() {
	// set up local vars
	bool rc1Crash = g_c1.getCrash();
	bool rc2Crash = g_c2.getCrash();

	float rc1Avg = g_c1.getAverageSpeed();
	float rc2Avg = g_c2.getAverageSpeed();

	string rc1Model = g_c1.getModel();
	string rc2Model = g_c2.getModel();

	// winner has fastest average speed with no crash
	if (rc1Crash && rc2Crash) {
		cout << YELLOW << "No winner - both cars crashed.\n"
			<< RESET_COLORS;
	}
	else if (rc1Crash) {
		cout << YELLOW << "The " << rc2Model << " won!" << RESET_COLORS;
		cout << "\nThe poor mangled " << rc1Model
			<< " is waiting for a tow truck.\n";
	}
	else if (rc2Crash) {
		cout << YELLOW << "The " << rc2Model << " won!" << RESET_COLORS;
		cout << "\nWhat's left of the " << rc1Model
			<< " is sadly hanging from a stinger.\n";
	}
	else if (rc1Avg > rc2Avg) {
		cout << YELLOW << rc1Model << " won!\n" << RESET_COLORS;
	}
	else if (rc2Avg > rc1Avg) {
		cout << YELLOW << rc2Model << " won!\n" << RESET_COLORS;
	}
	else {
		cout << GREEN << "It's a dead heat!\n" << RESET_COLORS;
	}

	// display distances driven and average speeds
	cout << "\n";
	cout << "The " << rc1Model << " drove "
		<< g_c1.getMilesDriven() << " miles. Average speed: "
		<< rc1Avg << " mph\n";
	cout << "The " << rc2Model << " drove "
		<< g_c2.getMilesDriven() << " miles. Average speed: "
		<< rc2Avg << " mph\n";
	cout << "\n";
}

//------------------------------------------------------------------------------
inline void driveStage(float miles) {
	driveStage(g_c1, miles);
	driveStage(g_c2, miles);
}

//------------------------------------------------------------------------------
inline void setRandomSpeed() {
	g_c1.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
	g_c2.setRandomSpeed(MIN_SPEED, MAX_SPEED + CRASH_FACTOR);
}

inline void reset() {
	g_scenery.reset();
	// zero miles driven
	g_c1.reset();
	g_c2.reset();
	// gas up both cars
	g_c1.fillUp();
	g_c2.fillUp();

	cout << "Both cars are gassed up and ready to go!\n\n";
}