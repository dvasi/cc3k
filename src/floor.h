#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include "cell.h"

const int BOARD_WIDTH = 79;
const int BOARD_HEIGHT = 25;
const int numEnemies = 20;
const int numGoldPiles = 10;

class Floor{

	friend class World;
	
	//Layout management
	std::vector<int> chambers;
	std::vector<int> passages;
	std::vector<std::vector<Cell*> > allCells;
	
	//Game object management
	char enemy[numEnemies]; //20 enemies per floor
	char goldPiles[numGoldPiles]; //10 piles of gold per floor
protected:
	int dragons; //number of dragons on the floor

public:
	void generateEnemies(); 
	void generateGoldPiles();
	void initializeChambers();
	void initializePassages();
	void initializeCells(std::vector<std::vector<char> > floorLayout);
	Floor();
	~Floor();
	
};
#endif
