//----------------------------------------------------------------------
// RaceCar : derived class declaration
//----------------------------------------------------------------------
#ifndef RACECAR_H
#define RACECAR_H

#include <string>

#include "Car.h"

using std::string;

//----------------------------------------------------------------------
// RaceCar
//----------------------------------------------------------------------
class RaceCar : public Car {
private:
	int speed;
	static constexpr int MIN_SPEED = 60;
	static constexpr int MAX_SPEED = 80;

public:
	// constructors
	RaceCar();
	RaceCar(const string& year, const string& make, const string& model);

	// implements virtual Car::drive()
	virtual float drive(float miles);

	// setters
	void setSpeed(int speed);

	// getters
	int getSpeed() const;

	// util
	int setRandomSpeed(int minSpeed, int maxSpeed);
};
#endif	// RACECAR_H



