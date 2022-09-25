//----------------------------------------------------------------------
// FuelGauge : class declaration
//----------------------------------------------------------------------
#ifndef FUELGAUGE_H
#define FUELGAUGE_H

//----------------------------------------------------------------------
// FuelGauge
//----------------------------------------------------------------------
class FuelGauge {
private:
	float gallonsLeft;
	static constexpr float TANK_CAPACITY = 15.0;
	static constexpr float MPG = 24.0;

public:

	// constructors
	FuelGauge();
	FuelGauge(float initialGallons);

	// return fuel economy (MPG)
	float getMPG();

	// return tank capacity
	float getTankCapacity();

	// return how many gallons of fuel remain
	float getGallonsLeft();

	// return how many miles can be driven given remaining fuel
	float canDriveMiles();

	// return how many miles were driven given remaining fuel
	float driveMiles(float miles);

	// fill the tank, return how many gallons added
	float fillUp();

	// add fuel, return how many gallons added
	float addGallons(float gallons);

	// decrease fuel amount, return gallons left after decrease
	float useGallons(float gallons);

	// set gallonsLeft to 0
	void makeEmpty();
};
#endif	// FUELGAUGE_H
