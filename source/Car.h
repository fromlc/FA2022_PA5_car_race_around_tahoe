//----------------------------------------------------------------------
// Car : class declaration
//----------------------------------------------------------------------
#ifndef CAR_H
#define CAR_H

#include <string>

#include "Odometer.h"
#include "FuelGauge.h"

using std::string;

//----------------------------------------------------------------------
// Car
//----------------------------------------------------------------------
class Car {
private:
	string make;
	string model;
	string year;
	Odometer odo;
	FuelGauge fg;

public:
	// constructors
	Car();
	Car(const string&& year, const string&& make, const string&& model);

	// causes Odomether mileage and FuelGauge gallonsLeft to change
	float drive(float miles);

	// add enough fuel to fill up the tank, return gallons added
	float fillUp();

	// returns number of gallons actually added
	float addFuel(float gallons);

	// returns number of gallons remaining
	float readFuelGauge();

	// returns number of miles remaining given fuel level
	float canDriveMiles();

	// pretty print year, make, model, odometer reading, fuel level, MPG
	void print();
};
#endif	// CAR_H



