#include <cstdlib>
#include <vector>
#include "world.h"
#include "floor.h"
using namespace std;

World::World(): layoutGiven(false) {}

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

	//IN PROGRESS, TODO
	Floor *floor = new Floor();
	floor->initializeCells(floorLayout);
	delete floor;
}

World* World::worldInstance = NULL;
