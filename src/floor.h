#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include "cell.h"

const int BOARD_WIDTH = 79;
const int BOARD_HEIGHT = 25;

class Floor{

	friend class World;
	
	//Layout management
	std::vector<int> chambers;
	std::vector<int> passages;
	std::vector<std::vector<Cell*> > allCells;
	
	//Game object management
	
	
public:
	void initializeChambers();
	void initializePassages();
	void initializeCells(std::vector<std::vector<char> > floorLayout);
	Floor();
	~Floor();
	
};
#endif
