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
<<<<<<< HEAD
	
	void initializeFloors(std::vector<std::vector<char> > floorLayout);
=======
	int currentFloor;
	
	void initializeFloors(std::vector<std::vector<char> > floorLayout);
	void displayFloors();
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
	World();
	~World();
	
public:
	static World* getInstance();
	
};
#endif
