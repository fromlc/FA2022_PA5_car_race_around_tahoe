//------------------------------------------------------------------------------
// Odometer : class declaration and definition
//------------------------------------------------------------------------------
#ifndef ODOMETER_H
#define ODOMETER_H

constexpr int MAX_MILESDRIVEN = 999999;

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
	//--------------------------------------------------------------------------
	// bump odometer miles, roll over to zero at MAX_MILESDRIVEN
	//--------------------------------------------------------------------------
	void addMilesDriven(float miles) {
		// get integer and fractional parts
		int iMiles = static_cast<int>(milesDriven + miles);
		float fMiles = milesDriven + miles;
		float fraction = fMiles - iMiles;

		// roll over or not
		iMiles = iMiles % MAX_MILESDRIVEN;

		// tack on fractional part
		milesDriven = iMiles + fraction;
	}
};
#endif	// ODOMETER_H