//------------------------------------------------------------------------------
// FuelGauge : class definition
//------------------------------------------------------------------------------
#include "FuelGauge.h"
#include "Odometer.h"

//------------------------------------------------------------------------------
// default constructor
//------------------------------------------------------------------------------
FuelGauge::FuelGauge() : FuelGauge(0.0) {}

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
FuelGauge::FuelGauge(float initialGallons) { gallonsLeft = initialGallons; }

//------------------------------------------------------------------------------
// return fuel economy (MPG)
//------------------------------------------------------------------------------
float FuelGauge::getMPG() const { return MPG; }

//------------------------------------------------------------------------------
// return tank capacity
//------------------------------------------------------------------------------
float FuelGauge::getTankCapacity() const { return TANK_CAPACITY; }

//------------------------------------------------------------------------------
// return how many gallons of fuel remain
//------------------------------------------------------------------------------
float FuelGauge::getGallonsLeft() const { return gallonsLeft; }

//------------------------------------------------------------------------------
// fill the tank, return how many gallons were added
//------------------------------------------------------------------------------
float FuelGauge::fillUp() {
	float gallonsAdded = TANK_CAPACITY - gallonsLeft;
	gallonsLeft = TANK_CAPACITY;
	return gallonsAdded;
}

//------------------------------------------------------------------------------
// add fuel, return how many gallons added
//------------------------------------------------------------------------------
float FuelGauge::addGallons(float gallons) {
	float canAddGallons = TANK_CAPACITY - gallonsLeft;

	if (canAddGallons >= gallons) {
		gallonsLeft += gallons;
		return gallons;
	}

	gallonsLeft += canAddGallons;
	return canAddGallons;
}

//------------------------------------------------------------------------------
// decrease fuel amount, return gallons left after decrease
//------------------------------------------------------------------------------
float FuelGauge::useGallons(float gallons) {
	float g = gallonsLeft - gallons;

	gallonsLeft = g <= 0 ? 0 : g;
	return g;
}

//------------------------------------------------------------------------------
// return how many miles can be driven given remaining fuel
//------------------------------------------------------------------------------
float FuelGauge::canDriveMiles() const {
	return gallonsLeft * MPG;
}

//------------------------------------------------------------------------------
// return how many miles were driven given remaining fuel
//------------------------------------------------------------------------------
float FuelGauge::driveMiles(float miles) {
	float milesLeft = canDriveMiles();

	// enough fuel remaing case
	if (milesLeft >= miles) {
		gallonsLeft -= miles / MPG;
		return miles;
	}

	gallonsLeft = 0;
	return milesLeft;
}

//------------------------------------------------------------------------------
// set gallonsLeft to 0
//------------------------------------------------------------------------------
void FuelGauge::makeEmpty() {
	gallonsLeft = 0;
}
