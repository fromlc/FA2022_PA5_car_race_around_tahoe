//------------------------------------------------------------------------------
// Odometer : class declaration and definition
//------------------------------------------------------------------------------
#ifndef ODOMETER_H
#define ODOMETER_H

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MAX_MILES = 999999;

//------------------------------------------------------------------------------
// Odometer
// 
// #TODO add trip meter
//------------------------------------------------------------------------------
class Odometer {
private:
	float milesDriven;

public:
	// constructors
	Odometer() : Odometer(0.0) {}
	Odometer(float initialMiles) { milesDriven = initialMiles; };

	// getters
	float getMilesDriven() const { return milesDriven; };

	// setters
	void setMilesDriven(float miles) {
		float xs = miles - MAX_MILES;
		// odometer reading wraps to zero
		milesDriven = xs > 0 ? xs : miles;
	}

	// util
	void addMilesDriven(float miles) {
		milesDriven += miles;
		float xs = milesDriven - MAX_MILES;
		// odometer reading wraps to zero
		if (xs > 0)
			milesDriven = xs;
	};

	void reset() { milesDriven = 0; };
};
#endif	// ODOMETER_H