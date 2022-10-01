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
	Odometer();
	Odometer(float initialMiles);

	// getters
	float getMilesDriven() const;

	// setters
	void addMilesDriven(float miles);

	// util
	void reset();
};
#endif	// ODOMETER_H