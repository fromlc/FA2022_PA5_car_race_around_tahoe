//------------------------------------------------------------------------------
// RaceCar : derived class definition
//------------------------------------------------------------------------------
#include <cstdlib>
#include <ctime>
#include <string>

#include "RaceCar.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::rand;
using std::srand;
using std::string;

//------------------------------------------------------------------------------
// default constructor
//------------------------------------------------------------------------------
RaceCar::RaceCar() : RaceCar("2022", "Corvette", "Z-06") {}

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
RaceCar::RaceCar(const string& year, const string& make, const string& model) :
	Car(year, make, model) {

	srand((unsigned int) time(0));
	reset();
}

//------------------------------------------------------------------------------
// causes Odomether mileage and FuelGauge gallonsLeft to change
// returns miles actually driven given fuel remaining
//------------------------------------------------------------------------------
float RaceCar::drive(float miles) {
	float driven = fg.driveMiles(miles);
	odo.addMilesDriven(driven);

	return driven;
}

//------------------------------------------------------------------------------
// set speed to passed value
// returns miles actually driven given fuel remaining
//------------------------------------------------------------------------------
void RaceCar::setSpeed(int speed) {
	this->speed = speed;
	speedLog.push_back(speed);
}

//------------------------------------------------------------------------------
// set speed to passed value
// returns miles actually driven given fuel remaining
//------------------------------------------------------------------------------
int RaceCar::setRandomSpeed(int minSpeed, int maxSpeed) {
	int range = maxSpeed - minSpeed + 1;
	speed = rand() % range + minSpeed;
	speedLog.push_back(speed);

	return speed;
}

//------------------------------------------------------------------------------
// returns speed value
//------------------------------------------------------------------------------
int RaceCar::getSpeed() const {
	return speed;
}

//------------------------------------------------------------------------------
// sets crash flag
//------------------------------------------------------------------------------
void RaceCar::setCrash() {
	crash = true;
}

//------------------------------------------------------------------------------
// returns crash flag
//------------------------------------------------------------------------------
bool RaceCar::getCrash() const {
	return crash;
}

//------------------------------------------------------------------------------
// returns average speed
//------------------------------------------------------------------------------
float RaceCar::getAverageSpeed() {
	int accumulateSpeed = 0;
	for (int s : speedLog) {
		accumulateSpeed += s;
	}
	return (float) accumulateSpeed / (float) speedLog.size();
}

//------------------------------------------------------------------------------
// resets car data
//------------------------------------------------------------------------------
void RaceCar::reset() {
	odo.reset();
	crash = false;

	speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
	speedLog.clear();
	speedLog.push_back(speed);
}
