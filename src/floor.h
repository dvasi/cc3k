#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <map>
#include "cell.h"
#include "item.h"
#include "textdisplay.h"

const int BOARD_WIDTH = 79;
const int BOARD_HEIGHT = 25;

class Floor{

	friend class World;
	TextDisplay *td;
	
	//Layout management
	std::vector<int> chambers;
	std::vector<int> passages;
	std::vector<std::vector<Cell*> > allCells;
	
	//Game object management
	std::map<int,Item*> floorItems;
	
public:
	void initializeChambers();
	void initializePassages();
	void initializeCells(std::vector<std::vector<char> > floorLayout);
	Cell* generateCell(int xPos, int yPos, char symbol);
	Floor();
	~Floor();
	
};
#endif
