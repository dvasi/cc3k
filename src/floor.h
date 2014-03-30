#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "cell.h"
#include "item.h"
#include "chamber.h"
#include "textdisplay.h"
#include "player.h"
#include "enemy.h"

const int BOARD_WIDTH = 79;
const int BOARD_HEIGHT = 25;
const int numEnemies = 20;
const int numGoldPiles = 10;

class Floor{

	friend class Game;
	TextDisplay *td;
	
	//Layout management
	std::vector<Chamber*> chambers;
	std::vector<std::vector<Cell*> > allCells;
	int startXPos, startYPos;
	
	//Game object management
	std::map<int,Item*> floorItems;
	std::map<int,Enemy*> floorEnemies;
	std::queue<Enemy*> enemyActionQueue;
	char enemy[numEnemies]; //20 enemies per floor
	char goldPiles[numGoldPiles]; //10 piles of gold per floor

protected:
    int dragons; //number of dragons on the floor

public:
	void generateEnemies(); 
	void generateGoldPiles();
	void floodFillChamber(int xStartPos, int yStartPos, char floodChar, std::vector<std::vector<char> > &floorLayout);
	void createChamber(std::vector<std::vector<char> > floorLayout);
	void initializeChambers(std::vector<std::vector<char> > floorLayout);
	void initializeCells(std::vector<std::vector<char> > floorLayout);
	void display();
	void updateState();
	void removeItem(int id);
	void removeEnemy(int id);
	Enemy* getEnemy(int id);
	Item* getItem(int id);
	Cell* generateCell(int xPos, int yPos, char symbol);
	Cell* getCellAt(int xPos, int yPos);
	int getStartXPos();
	int getStartYPos();
	TextDisplay* getTextDisplay();
	Floor();
	~Floor();
};
#endif
