#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
<<<<<<< HEAD
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
=======
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
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
	Floor();
	~Floor();
	
};
#endif
