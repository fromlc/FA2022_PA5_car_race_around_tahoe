//----------------------------------------------------------------------
// Car : class declaration
//----------------------------------------------------------------------
#ifndef CAR_H
#define CAR_H

#include <string>

#include "Odometer.h"
#include "FuelGauge.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::string;

//----------------------------------------------------------------------
// Car
//----------------------------------------------------------------------
class Car {
protected:
	string make;
	string model;
	string year;
	string description;
	Odometer odo;
	FuelGauge fg;

public:
	// constructors
	Car();
	Car(const string& year, const string& make, const string& model);

	// getters
	const string& getMake() const;
	const string& getModel() const;
	const string& getYear() const;
	// derived class getter will override this one
	virtual string& getDescription();

	// util
	float getMilesDriven() const;

	//----------------------------------------------------------------------
	// causes Odomether mileage and FuelGauge gallonsLeft to change
	// derived classes must implement this method
	//----------------------------------------------------------------------
	virtual float drive(float miles) = 0;

	// add enough fuel to fill up the tank, return gallons added
	float fillUp();

	// returns number of gallons actually added
	float addFuel(float gallons);

	// returns number of gallons remaining
	float readFuelGauge() const;

	// returns number of miles remaining given fuel level
	float canDriveMiles() const;

	// reset number of miles driven to zero
	void resetMilesDriven();
};
#endif	// CAR_H

