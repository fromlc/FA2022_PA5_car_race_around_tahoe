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
// constants
//------------------------------------------------------------------------------
// constexpr int MILES_TO_CHECKPOINT = 10;
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
void driveStage(RaceCar& rc, float miles);
void declareWinner();

// call RaceCar method for both cars
inline void reset();
inline void driveStage(float miles);
inline void setRandomSpeed();

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
	cout << CYAN;
	cout << "\nRACE AROUND LAKE TAHOE\n\n";
	cout << RESET_COLORS;

	// car descriptions
	cout << "A stock " << g_c1.getDescription() << " takes on a souped ";
	cout << g_c2.getDescription() << ".\n";

	// races starts and ends at last checkpoint
	cout << "\nThe race starts and ends at "
		<< g_scenery.getLastScene() << ".\n";
	// set up next race
	reset();

	cout << "Both cars are gassed up and ready to go!\n\n";
}

//------------------------------------------------------------------------------
// run the race loop
//------------------------------------------------------------------------------
void race() {
	int sceneCount = g_scenery.getSceneCount();

	for (int i = 0; i < sceneCount; i++) {

		// miles to next checkpoint
		float miles = g_scenery.getNextDistance();

		// set out for next checkpoint
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
	cout << rc.getModel() << " averaged " << speed << " mph";
	 
	// speed too high -> drive part way to checkpoint
	if (speed > MAX_SPEED) {
		cout << " but it " << RED << "CRASHED!@!" << RESET_COLORS <<
			" It " << g_scenery.getRandomCrash() 
			<< YELLOW << ". Everybody's OK!\n" << RESET_COLORS;

		rc.drive((float)(rand() % (int) miles));
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

	string rc1Desc = g_c1.getDescription();
	string rc2Desc = g_c2.getDescription();

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
			<< g_scenery.getRandomAftermath() << "\n";
	}
	else if (rc2Crash) {
		cout << YELLOW << "The " << rc2Model << " won!" << RESET_COLORS;
		cout << "\nWhat's left of the " << rc2Model
			<< g_scenery.getRandomAftermath() << "\n";
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

	// display distances driven
	cout << "\n";
	cout << rc1Desc << " drove "
		<< g_c1.getMilesDriven() << " miles.\n";
	cout << rc2Desc << " drove "
		<< g_c2.getMilesDriven() << " miles.\n";

	// display average speeds
	cout << "\n";
	cout << rc1Desc << " average speed: "
		<< rc1Avg << " mph\n";
	cout << rc2Desc << " average speed: "
		<< rc2Avg << " mph\n";
	cout << "\n";
}

//------------------------------------------------------------------------------
// inline functions
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

//------------------------------------------------------------------------------
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