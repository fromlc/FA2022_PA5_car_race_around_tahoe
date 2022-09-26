//------------------------------------------------------------------------------
// Car : class definition
//------------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Odometer.h"
#include "FuelGauge.h"
#include "Car.h"

using std::cout;
using std::string;

//------------------------------------------------------------------------------
// default constructor
//------------------------------------------------------------------------------
Car::Car() : Car("2022", "Kia", "Rio") {}

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
Car::Car(const string& year, const string& make, const string& model) {
	this->year = year;
	this->make = make;
	this->model = model;
}

//------------------------------------------------------------------------------
// add enough fuel to fill up the tank, return gallons added
//------------------------------------------------------------------------------
float Car::fillUp() {
	return fg.fillUp();
}

//------------------------------------------------------------------------------
// returns number of gallons actually added
//------------------------------------------------------------------------------
float Car::addFuel(float gallons) {
	return fg.addGallons(gallons);
}

//------------------------------------------------------------------------------
// returns number of miles on odometer
//------------------------------------------------------------------------------
float Car::getMilesDriven() const {
	return odo.getMilesDriven();
}

//------------------------------------------------------------------------------
// returns number of fuel gallons remaining
//------------------------------------------------------------------------------
float Car::readFuelGauge() const { return fg.getGallonsLeft(); }

//------------------------------------------------------------------------------
// returns number of miles remaining given fuel level
//------------------------------------------------------------------------------
float Car::canDriveMiles() const { return fg.canDriveMiles(); }

//------------------------------------------------------------------------------
// pretty print year, make, model, odometer reading, fuel level, MPG
//------------------------------------------------------------------------------
void Car::print() const {
	cout << year << " " << make << " " << model;
}



