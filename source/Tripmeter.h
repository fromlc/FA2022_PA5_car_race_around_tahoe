//------------------------------------------------------------------------------
// Tripmeter : class declaration
//------------------------------------------------------------------------------
#ifndef TRIPMETER_H
#define TRIPMETER_H

#include "Odometer.h"

//------------------------------------------------------------------------------
// Tripmeter
//------------------------------------------------------------------------------
class Tripmeter : public Odometer {
private:
	float tripMiles;

public:
	// constructors
	Tripmeter() : Odometer(0.0) { reset(); }

	// getters
	float getTripMiles() const { return tripMiles; }

	// setters
	//--------------------------------------------------------------------------
	// bump Tripmeter and Odometer miles
	//--------------------------------------------------------------------------
	void addTripMiles(float miles) {
		tripMiles += miles;
		// update odometer miles too
		this->addMilesDriven(miles);
	}

	//--------------------------------------------------------------------------
	void reset() { tripMiles = 0.0; }
};
#endif	// TRIPMETER_H