#ifndef __WORLD_H__
#define __WORLD_H__
#include <cstdlib>
#include <vector>
#include "world.h"
#include "floor.h"

const int NUM_FLOORS = 5;

class World{

	friend class Game;
	bool layoutGiven;
	std::vector <Floor*> floors;
	static World* worldInstance;
	static void cleanup();
	int currentFloor;
	
	void initializeFloors(std::vector<std::vector<char> > floorLayout);
	void displayFloors();
	World();
	~World();
	
public:
	static World* getInstance();
	
};
#endif
