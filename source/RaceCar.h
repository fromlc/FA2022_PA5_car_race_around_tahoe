//----------------------------------------------------------------------
// RaceCar : derived class declaration
//----------------------------------------------------------------------
#ifndef RACECAR_H
#define RACECAR_H

#include <string>
#include <vector>

#include "Car.h"

using std::string;
using std::vector;

//----------------------------------------------------------------------
// RaceCar
//----------------------------------------------------------------------
class RaceCar : public Car {
private:
	static constexpr int MIN_SPEED = 60;
	static constexpr int MAX_SPEED = 80;
	int speed;
	vector<int> speedLog;
	bool crash;

public:
	// constructors
	RaceCar();
	RaceCar(const string& year, const string& make, const string& model);

	// implements virtual Car::drive()
	virtual float drive(float miles);

	// setters
	void setSpeed(int speed);
	void setCrash();

	// getters
	int getSpeed() const;
	bool getCrash() const;

	// util
	int setRandomSpeed(int minSpeed, int maxSpeed);
	float getAverageSpeed();
};
#endif	// RACECAR_H



