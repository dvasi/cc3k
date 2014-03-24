#include <cstdlib>
#include <vector>
#include "world.h"
#include "floor.h"
using namespace std;

World::World(): layoutGiven(false), currentFloor(0) {}

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

	for (int i = 0; i < NUM_FLOORS; ++i){
		Floor *floor = new Floor();
		floor->initializeCells(floorLayout);
		floor->initializeChambers(floorLayout);
		floors.push_back(floor);
	}
}

void World::displayFloors(){
	(floors.at(currentFloor))->display();
}

World* World::worldInstance = NULL;