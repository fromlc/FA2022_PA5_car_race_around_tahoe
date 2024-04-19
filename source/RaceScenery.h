//------------------------------------------------------------------------------
// RaceScenery class declaration and definition
//------------------------------------------------------------------------------
#ifndef RACESCENERY_H
#define RACESCENERY_H

#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

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
		"Sugar Pine Point",
		"Tahoe City",
		"Carnelian Bay",
		"Crystal Bay",
		"Sand Harbor",
		"Thunderbird Lodge",
		"Spooner Lake",
	};

	// current checkpoint
	int sceneIndex;

	//--------------------------------------------------------------------------
	// crash scenes
	//--------------------------------------------------------------------------
	vector<string> crashes = {
		"bent around a big tree",
		"pitched into the drink",
		"took that corner too fast",
		"hit a robo-meter maid",
		"hit a fence and flipped over",
	};

public:
	//--------------------------------------------------------------------------
	// constructor
	//--------------------------------------------------------------------------
	RaceScenery() {
		sceneIndex = 0;
		srand((unsigned int)time(0));
	}

	//--------------------------------------------------------------------------
	// return reference to next checkpoint description
	//--------------------------------------------------------------------------
	int getSceneCount() const {
		return static_cast<int>(scenery.size());
	}

	//--------------------------------------------------------------------------
	// return reference to next checkpoint description
	//--------------------------------------------------------------------------
	const string& getNextScene() {
		return scenery.at(sceneIndex++);
	}

	//--------------------------------------------------------------------------
	// return reference to first checkpoint description
	//--------------------------------------------------------------------------
	const string& getFirstScene() const {
		return scenery.front();
	}

	//--------------------------------------------------------------------------
	// return reference to last checkpoint description
	//--------------------------------------------------------------------------
	const string& getLastScene() const {
		return scenery.back();
	}

	//--------------------------------------------------------------------------
	// return reference to random crash scene
	//--------------------------------------------------------------------------
	const string& getRandomCrash() const {
		int index = rand() % crashes.size();
		return crashes.at(index);
	}
};
#endif // RACESCENERY_H
