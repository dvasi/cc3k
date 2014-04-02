#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#include <ncurses.h>
#include <sstream>
#include "floor.h"
#include "cell.h"
#include "chamber.h"
#include "fileparser.h"
#include "itemfactory.h"
#include "itemusevisitor.h"
#include "enemyfactory.h"
#include "player.h"
#include "game.h"
#include "dragon.h"
#include "gold.h"
using namespace std;

Floor::Floor(): startXPos(3), startYPos(3), dragons(0)
{
    td = new TextDisplay(BOARD_WIDTH, BOARD_HEIGHT);
    itemStatMonitor = new ItemUseVisitor();
}

Floor::~Floor(){
    for (unsigned int i = 0; i < allCells.size(); ++i){
        while (!allCells.at(i).empty()){
            delete allCells.at(i).back();
            allCells.at(i).pop_back();
        }
    }
    delete td;
    delete itemStatMonitor;

    while (!chambers.empty()){
        delete chambers.back();
        chambers.pop_back();
    }

    for (map<int, Item*>::iterator i = floorItems.begin(); i != floorItems.end(); ++i){
        delete i->second;
        floorItems.erase(i);
    }
    
    for (map<int, Enemy*>::iterator i = floorEnemies.begin(); i != floorEnemies.end(); ++i){
        delete i->second;
        floorEnemies.erase(i);
    }
}

void Floor::floodFillChamber(int xStartPos, int yStartPos, char floodChar, vector<vector<char> > &floorLayout)
{
    char current = floorLayout.at(yStartPos).at(xStartPos);
    if ((current == floodChar) ||
            (current == '-') ||
            (current == '|') ||
            (current == '+') ||
            (current == '#')) return;
    floorLayout.at(yStartPos).at(xStartPos) = floodChar;
    floodFillChamber(xStartPos - 1, yStartPos, floodChar, floorLayout);
    floodFillChamber(xStartPos + 1, yStartPos, floodChar, floorLayout);
    floodFillChamber(xStartPos, yStartPos - 1, floodChar, floorLayout);
    floodFillChamber(xStartPos, yStartPos + 1, floodChar, floorLayout);
}

void Floor::createChamber(vector<vector<char> > floorLayout)
{

    vector<Cell *> chamberCells;
    char current;
    for (unsigned int i = 0; i < floorLayout.size(); ++i)
    {
        for (unsigned int j = 0; j < floorLayout.at(i).size(); ++j)
        {
            current = floorLayout.at(i).at(j);
            if (current == 'X')
            {
                chamberCells.push_back(allCells.at(i).at(j));
            }
        }
    }
    Chamber *newChamber = new Chamber(chamberCells);
    chambers.push_back(newChamber);
}

//Loops through original layout until it finds a floor cell,
//then uses "Flood Fill" to mark all tiles in that chamber.
//Now that the chamber is identified, we can initialize it
//with the appropriate cells from our layout. After
//a chamber is found we unmark it and proceed to find a new one.
//We do this until our layout is exhausted, and hence all chambers are found.
void Floor::initializeChambers(vector<vector<char> > floorLayout)
{

    char current;
    vector<vector<char> > floorLayoutCopy = floorLayout;
    vector<vector<char> > floodFillAcc = floorLayout;
    for (unsigned int i = 0; i < floorLayoutCopy.size(); ++i)
    {
        for (unsigned int j = 0; j < floorLayoutCopy.at(i).size(); ++j)
        {
            current = floorLayoutCopy.at(i).at(j);
            if (current == '.')
            {
                floodFillChamber(j, i, 'X', floorLayoutCopy);
                floodFillChamber(j, i, 'X', floodFillAcc);
                createChamber(floodFillAcc);
                floodFillChamber(j, i, '.', floodFillAcc);
            }
        }
    }
}

void Floor::initializeCells(vector<vector<char> > floorLayout)
{

    char current;

    //Generate cells based on given layout
    for (int i = 0; i < BOARD_HEIGHT; ++i){
        vector<Cell *> row;
        for (int j = 0; j < BOARD_WIDTH; ++j){
            current = floorLayout.at(i).at(j);
            Cell *parsedCell = generateCell(i, j, current);
            parsedCell->notifyDisplay(*td);
            row.push_back(parsedCell);
        }
        allCells.push_back(row);
    }

    //Match up Dragons and Dragon Hoards
    Dragon *dragon;
    Gold *hoard;
    for (unsigned int i = 0; i < floorDragons.size(); ++i){
    	dragon = floorDragons.at(i);
    	for (unsigned int j = 0; j < floorDragonHoards.size(); ++j){
    		hoard = floorDragonHoards.at(j);
    		int dragonXPos = dragon->getXPos();
    		int dragonYPos = dragon->getYPos();
    		int hoardXPos = hoard->getXPos();
    		int hoardYPos = hoard->getYPos();
    		if ((abs(dragonXPos-hoardXPos) <= 1)&&(abs(dragonYPos-hoardYPos) <=1)){
    			dragon->guard(hoard);
    			break;
    		}
    	}
    }
}

Cell* Floor::generateCell(int xPos, int yPos, char symbol){

	FileParser parser = FileParser();
	int cellType = parser.charToCellType(symbol);
	Cell *parsedCell;
	
	//Could have an object occupying it possibly
	if (cellType == Cell::Floor){
	
		bool hasEnemy = false;
		bool hasItem = false;
		bool hasPlayer = false;
		int id = -1;

		//Special dragon hoard case, to match it with a Dragon after
		if (symbol == '9'){
			Gold* hoard = new Gold(Item::generateId(),6);
			hoard->setPos(xPos,yPos);
			hasItem = true;
			id = hoard->getId();
			floorDragonHoards.push_back(hoard);
			floorItems[id] = hoard;
		}

		//Other item case
		else if (isdigit(symbol)){
			ItemFactory itFactory = ItemFactory();
			Item* newItem = itFactory.getItem(symbol);
			newItem->setPos(xPos,yPos);
			hasItem = true;
			id = newItem->getId();
			floorItems[id] = newItem;
		}
		
		//Special Dragon case, to match it with a dragon hoard after.

		else if (symbol == 'D'){
			Dragon* dragon = new Dragon(0,0,Character::generateId());
			dragon->setPos(xPos,yPos);
			hasEnemy = true;
			id = dragon->getId();
			floorDragons.push_back(dragon);
			floorEnemies[id] = dragon;
			enemyActionQueue.push(dragon);
		}

		//Enemy case
		else if  ((symbol == 'V')||
			(symbol == 'W')||
			(symbol == 'N')||
			(symbol == 'M')||
			(symbol == 'X')||
			(symbol == 'T')){
			EnemyFactory enFactory = EnemyFactory();			
			Enemy *newEnemy = enFactory.getEnemy(symbol);
			newEnemy->setPos(xPos,yPos);
			hasEnemy = true;
			id = newEnemy->getId();
			floorEnemies[id] = newEnemy;
			enemyActionQueue.push(newEnemy);
		}
		
		//Player case
		else if (symbol == '@'){
			hasPlayer = true;
			Player *player = Player::getInstance();
			player->setPos(xPos,yPos);
			startXPos = xPos;
			startYPos = yPos;
		}
		
		parsedCell = new Cell(xPos,yPos,cellType,symbol,hasEnemy,hasItem,hasPlayer,id);
	}
	
	else{
		parsedCell = new Cell(xPos,yPos,cellType,symbol);
	}
	
	return parsedCell;
}

void Floor::display()
{
    cout << *td;
    td->resetGameActions();
}

//WE WILL USE THESE AFTER OUR SUBCLASSES GET REFINED
/*
void Floor::generateEnemies()
{
    int random;
    for (int i = 0; i < dragons; ++i) //set number of dragons first, determined by number of dragon hoards
    {
        //enemy.assign(dragons, 'd');
        enemy[i] = 'd';
        //enemy.at(i)=dragons;
    }
    srand(time(0));

    for (int i = dragons; i < numEnemies; ++i)
    {
        random = rand() % 18 + 1; //random number between 1 and 18
        if (random >= 1 && random <= 4) // 2/9 chance of being werewolf
        {
            //enemy.assign(1, 'w');
            enemy[i] = 'w';
        }
        else if (random >= 5 && random <= 7) // 3/18 chance of being vampire
        {
            //enemy.assign(1, 'v');
            enemy[i] = 'v';
        }
        else if (random >= 8 && random <= 12) // 5/18 of being goblin
        {
            //enemy.assign(1, 'g');
            enemy[i] = 'g';
        }
        else if (random >= 13 && random <= 14) // 1/18 troll
        {
            //enemy.assign(1, 't');
            enemy[i] = 't';
        }
        else if (random >= 15 && random <= 16) // 1/18 phoenix
        {
            //enemy.assign(1, 'p');
            enemy[i] = 'p';
        }
        else // 1/18 merchant
        {
            //enemy.assign(1, 'm');
            enemy[i] = 'm';
        }

    }

    for (int i = 0; i < numEnemies; ++i)
    {

        spawnedEnemies[i] = new Enemy(enemy[i]);
    }

}
*/

/*
void Floor::generateGoldPiles() //randomly generate the 10 gold piles
{
    int random;
    srand(time(0));
    for (int i = 0; i < numGoldPiles; ++i)
    {
        random = rand() % 8 + 1; //random number between 1 and 8
        if (random == 1) // 1/8 chance of dragon hoard
        {
            goldPiles[i] = 'd';
            dragons++;
        }
        else if (random > 1 && random <= 6) // 5/8 chance of normal hoard
        {
            goldPiles[i] = 'n';
        }
        else // 2/8 chance of small hoard
        {
            goldPiles[i] = 's';
        }
    }

}
*/

void Floor::removeItem(int id){	
	delete floorItems[id];
	floorItems.erase(id);
}

void Floor::removeEnemy(int id){
	delete floorEnemies[id];
	floorEnemies.erase(id);
}

Enemy* Floor::getEnemy(int id){
	return floorEnemies[id];
}

Item* Floor::getItem(int id){
	return floorItems[id];
}

void Floor::spawnItem(int xPos, int yPos, char symbol){
	ItemFactory itFactory = ItemFactory();
	Item *item = itFactory.getItem(symbol);
	Cell *currentCell = allCells.at(xPos).at(yPos);
	currentCell->setOccupation(false,true,false,item->getId());
	currentCell->setCellSymbol(symbol);
	item->setPos(xPos,yPos);
	floorItems[item->getId()] = item;
}

void Floor::updateState(){

	//Make our enemy action queue for proper ordering
	for (unsigned int i = 0; i < allCells.size(); ++i){
        for(unsigned int j = 0; j < allCells.at(i).size(); ++j){
        	Cell *current = allCells.at(i).at(j);
        	if (current->hasEnemy()){
        		int enemyId = current->getOccupiedId();
        		Enemy* nextEnemy = floorEnemies[enemyId];
        		enemyActionQueue.push(nextEnemy);
        	}
        }
    }
	while (!enemyActionQueue.empty()){
		Enemy* currentEnemy = enemyActionQueue.front();
		currentEnemy->update();
		enemyActionQueue.pop();
	}	

	
}

int Floor::getStartXPos(){ return startXPos; }

int Floor::getStartYPos(){ return startYPos; }

TextDisplay* Floor::getTextDisplay(){ return td; }

ItemUseVisitor* Floor::getItemStatMonitor(){ return itemStatMonitor; }

void Floor::negateTempStats(){
	Player *player = Player::getInstance();
	player->alterAtk(-(itemStatMonitor->getTempAtkDelta()));
	player->alterDef(-(itemStatMonitor->getTempDefDelta()));
}

Cell* Floor::getCellAt(int xPos, int yPos) { return allCells.at(xPos).at(yPos); }