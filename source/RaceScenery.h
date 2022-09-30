//------------------------------------------------------------------------------
// RaceScenery class declaration and definition
//------------------------------------------------------------------------------
#ifndef RACESCENERY_H
#define RACESCENERY_H

#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::string;
using std::vector;

//------------------------------------------------------------------------------
// RaceScenery
//------------------------------------------------------------------------------
class RaceScenery {
private:
	//--------------------------------------------------------------------------
	// race checkpoints
	//--------------------------------------------------------------------------
	vector<string> scenery = {
		"Zephyr Cove",
		"Fallen Leaf Lake",
		"Rubicon Point",
		//"Sugar Pine Point",
		"Tahoe City",
		"Carnelian Bay",
		//"Crystal Bay",
		"Sand Harbor",
		//"Thunderbird Lodge",
		"Spooner Lake",
	};

	vector<float> distances = {
		12.5, // to Zephyr Cove
		13.0, // to Fallen Leaf Lake
		15.5, // to Rubicon Point
		16.0, // to Tahoe City
		13.5, // to Carnelian Bay
		14.0, // to Sand Harbor
		17.5, // to Spooner Lake
	};

	// name of and distance to next checkpoint
	int sceneIndex;
	int distanceIndex;

	//--------------------------------------------------------------------------
	// crash scenes
	//--------------------------------------------------------------------------
	vector<string> crashes = {
		"bent around a big sugar pine",
		"pitched into the drink",
		"took that corner too fast",
		"hit a robo-meter maid",
		"hit a fence and flipped over",
		"hit a yeti",
		"skidded on gravel and spun out",
	};

public:
	//--------------------------------------------------------------------------
	// constructor
	//--------------------------------------------------------------------------
	RaceScenery() {
		sceneIndex = 0;
		distanceIndex = 0;
		srand((unsigned int) time(0));
	}

	//--------------------------------------------------------------------------
	// return reference to next checkpoint description
	//--------------------------------------------------------------------------
	int getSceneCount() {
		return (int) scenery.size();
	}

	//--------------------------------------------------------------------------
	// return reference to next checkpoint description
	//--------------------------------------------------------------------------
	string& getNextScene() {
		return scenery.at(sceneIndex++);
	}

	//--------------------------------------------------------------------------
	// return distance to next checkpoint
	//--------------------------------------------------------------------------
	float getNextDistance() {
		return distances.at(distanceIndex++);
	}

	//--------------------------------------------------------------------------
	// return reference to first checkpoint description
	//--------------------------------------------------------------------------
	string& getFirstScene() {
		return scenery.front();
	}

	//--------------------------------------------------------------------------
	// return reference to last checkpoint description
	//--------------------------------------------------------------------------
	string& getLastScene() {
		return scenery.back();
	}

	//--------------------------------------------------------------------------
	// return reference to random crash scene
	//--------------------------------------------------------------------------
	string& getRandomCrash() {
		int index = rand() % crashes.size();
		return crashes.at(index);
	}

	//--------------------------------------------------------------------------
	// reset scenery and distances vectors
	//--------------------------------------------------------------------------
	void reset() {
		sceneIndex = 0;
		distanceIndex = 0;
	}
};
#endif // RACESCENERY_H
