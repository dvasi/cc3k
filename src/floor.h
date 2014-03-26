#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <map>
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

class Floor
{

    friend class World;
    TextDisplay *td;

    //Layout management
    std::vector<Chamber *> chambers;
    std::vector<std::vector<Cell *> > allCells;

    //Game object management
    std::map<int, Item *> floorItems;
    std::map<int, Character *> floorCharacters;
    // std::vector<char> enemy;
    //char enemy[numEnemies]; //20 enemies per floor
protected:
    int dragons; //number of dragons on the floor


public:
    char enemy[numEnemies]; //20 enemies per floor
    Enemy *spawnedEnemies[numEnemies];
    char goldPiles[numGoldPiles]; //10 piles of gold per floor
    //change above three declarations to protected/private once moved to right file 

    //std::vector<char> enemy;
    //std::vector<Enemy *> spawnedEnemies;
    void generateEnemies();
    void generateGoldPiles();
    void floodFillChamber(int xStartPos, int yStartPos, char floodChar, std::vector<std::vector<char> > &floorLayout);
    void createChamber(std::vector<std::vector<char> > floorLayout);
    void initializeChambers(std::vector<std::vector<char> > floorLayout);
    void initializeCells(std::vector<std::vector<char> > floorLayout);
    void display();
    Cell *generateCell(int xPos, int yPos, char symbol);
    Floor();
    ~Floor();

};
#endif
