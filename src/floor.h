#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <map>
#include "cell.h"
#include "item.h"
#include "chamber.h"
#include "textdisplay.h"

const int BOARD_WIDTH = 79;
const int BOARD_HEIGHT = 25;
// hello
class Floor{

	friend class World;
	TextDisplay *td;
	
	//Layout management
	std::vector<Chamber*> chambers;
	std::vector<std::vector<Cell*> > allCells;
	
	//Game object management
	std::map<int,Item*> floorItems;
	
public:
	void floodFillChamber(int xStartPos, int yStartPos, char floodChar, std::vector<std::vector<char> > &floorLayout);
	void createChamber(std::vector<std::vector<char> > floorLayout);
	void initializeChambers(std::vector<std::vector<char> > floorLayout);
	void initializeCells(std::vector<std::vector<char> > floorLayout);
	void display();
	Cell* generateCell(int xPos, int yPos, char symbol);
	Floor();
	~Floor();
	
};
#endif
