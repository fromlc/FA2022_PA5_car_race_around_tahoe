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
	float getMilesDriven();

	// setters
	void addMilesDriven(float miles);
};
#endif	// ODOMETER_H