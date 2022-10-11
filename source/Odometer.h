//------------------------------------------------------------------------------
// Odometer : class declaration
//------------------------------------------------------------------------------
#ifndef ODOMETER_H
#define ODOMETER_H

//------------------------------------------------------------------------------
// Odometer
//------------------------------------------------------------------------------
class Odometer {
private:
	float milesDriven;

public:
	// constructors
	Odometer() : Odometer(0.0) {}
	Odometer(float initialMiles) { milesDriven = initialMiles; }

	// getters
	float getMilesDriven() const { return milesDriven; }

	// setters
	void addMilesDriven(float miles);
};
#endif	// ODOMETER_H