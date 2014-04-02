#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "cell.h"
#include "item.h"
#include "enemy.h"

class Chamber;
class TextDisplay;
class Player;
class Dragon;
class DragonGold;
class ItemUseVisitor;

const int BOARD_WIDTH = 79;
const int BOARD_HEIGHT = 25;
const int NUM_FLOORS = 5;
const int NUM_POTIONS = 10;
const int NUM_GOLD = 10;
const int NUM_ENEMIES = 20;

class Floor{

	friend class Game;
	TextDisplay *td;
	ItemUseVisitor *itemStatMonitor;
	
	//Layout management
	std::vector<Chamber*> chambers;
	std::vector<std::vector<Cell*> > allCells;
	int startXPos, startYPos;
	
	//Game object management
	std::map<int,Item*> floorItems;
	std::map<int,Enemy*> floorEnemies;
	std::queue<Enemy*> enemyActionQueue;
	std::vector<Dragon*> floorDragons;
	std::vector<DragonGold*> floorDragonHoards;

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
	void spawnItem(int xPos, int yPos, char symbol);
	Cell* getCellAt(int xPos, int yPos);
	int getStartXPos();
	int getStartYPos();
	void negateTempStats();
	void generateStairCase(Cell *currentCell);
	void generatePlayer(Cell *currentCell);
	void generateEnemy(Cell *currentCell);
	void generatePotion(Cell *currentCell);
	void generateGold(Cell *curentCell);
	void matchDragonHoards();
	void generateFloor();
	TextDisplay* getTextDisplay();
	ItemUseVisitor* getItemStatMonitor();
	Floor();
	~Floor();
};
#endif
