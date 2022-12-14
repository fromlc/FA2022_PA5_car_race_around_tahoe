//------------------------------------------------------------------------------
// RaceCar : derived class definition
//------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <string>

#include "Odometer.h"
#include "FuelGauge.h"
#include "RaceCar.h"

using std::cout;
using std::rand;
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
	speed = rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
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
}

//------------------------------------------------------------------------------
// set speed to passed value
// returns miles actually driven given fuel remaining
//------------------------------------------------------------------------------
int RaceCar::setRandomSpeed(int minSpeed, int maxSpeed) {
	speed = rand() % (maxSpeed - minSpeed) + minSpeed;
	return speed;
}

//------------------------------------------------------------------------------
// returns speed value
//------------------------------------------------------------------------------
int RaceCar::getSpeed() const {
	return speed;
}
