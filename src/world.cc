#include <cstdlib>
#include <vector>
#include "world.h"
#include "floor.h"
using namespace std;

<<<<<<< HEAD
World::World(): layoutGiven(false) {}
=======
World::World(): layoutGiven(false), currentFloor(0) {}
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb

World::~World(){

	while (!floors.empty()){
		delete floors.back();
		floors.pop_back();
	}
}

World* World::getInstance(){

	if (!worldInstance){
		worldInstance = new World();
		atexit(cleanup);
	}
	return worldInstance;
}

void World::cleanup(){

	delete worldInstance;
	worldInstance = NULL;
}

void World::initializeFloors(vector<vector<char> > floorLayout){

<<<<<<< HEAD
	//IN PROGRESS, TODO
	Floor *floor = new Floor();
	floor->initializeCells(floorLayout);
	delete floor;
=======
	for (int i = 0; i < NUM_FLOORS; ++i){
		Floor *floor = new Floor();
		floor->initializeCells(floorLayout);
		floor->initializeChambers(floorLayout);
		floors.push_back(floor);
	}
}

void World::displayFloors(){
	(floors.at(currentFloor))->display();
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
}

World* World::worldInstance = NULL;
