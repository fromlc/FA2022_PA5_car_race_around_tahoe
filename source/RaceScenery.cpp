//------------------------------------------------------------------------------
// RaceScenery 
//------------------------------------------------------------------------------
#ifndef RACESCENERY_H
#define RACESCENERY_H

#include <string>

using std::string;

class RaceScenery {
private:
	vector<string> scenery = {
		"Zephyr Cove",
		"Fallen Leaf Lake",
		"Rubicon Point",
		"Sugar Pine Point",
		"Tahoe City",
		"Carnelian Bay",
		"Crystal Bay",
		"Sand Harbor",
		"Thunderbird Lodge",
		"Spooner Lake",
	};

	int sceneIndex;

	vector<string> crashes = {
		"bent around a big tree",
		"pitched into the drink",
		"took that corner too fast",
		"hit a robo-meter maid",
		"hit a fence and flipped over",
	};

public:
	string& getNextScene();
	string& getFirstScene();
	string& getLastScene();

	string& getRandomCrash();
};
#endif // RACESCENERY_H
