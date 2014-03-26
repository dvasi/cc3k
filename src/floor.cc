#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "floor.h"
#include "cell.h"
#include "chamber.h"
#include "fileparser.h"
#include "itemfactory.h"
#include "enemyfactory.h"
#include "player.h"
#include "game.h" 
using namespace std;

Floor::Floor(): dragons(0){
	td = new TextDisplay(BOARD_WIDTH, BOARD_HEIGHT);
}

Floor::~Floor(){

	for (unsigned int i = 0; i < allCells.size(); ++i){
		while(!allCells.at(i).empty()){
			delete allCells.at(i).back();
			allCells.at(i).pop_back();
		}
	}
	delete td;
	
	while(!chambers.empty()){
		delete chambers.back();
		chambers.pop_back();
	}
	
	for (map<int,Item*>::iterator i = floorItems.begin(); i != floorItems.end(); ++i){
		delete i->second;
		floorItems.erase(i);
	}
	

}

void Floor::floodFillChamber(int xStartPos, int yStartPos, char floodChar, vector<vector<char> > &floorLayout){
	char current = floorLayout.at(yStartPos).at(xStartPos);
	if ((current == floodChar)||
		(current == '-')||
		(current == '|')||
		(current == '+')||
		(current == '#')) return;
	floorLayout.at(yStartPos).at(xStartPos) = floodChar;
	floodFillChamber(xStartPos-1,yStartPos, floodChar, floorLayout);
	floodFillChamber(xStartPos+1,yStartPos, floodChar, floorLayout);
	floodFillChamber(xStartPos,yStartPos-1, floodChar, floorLayout);
	floodFillChamber(xStartPos,yStartPos+1, floodChar, floorLayout);
}

void Floor::createChamber(vector<vector<char> > floorLayout){

	vector<Cell*> chamberCells;
	char current;
	for (unsigned int i = 0; i < floorLayout.size(); ++i){
		for (unsigned int j = 0; j < floorLayout.at(i).size(); ++j){
			current = floorLayout.at(i).at(j);
			if (current == 'X'){
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
void Floor::initializeChambers(vector<vector<char> > floorLayout){
	
	char current;
	vector<vector<char> > floorLayoutCopy = floorLayout;
	vector<vector<char> > floodFillAcc = floorLayout;
	for (unsigned int i = 0; i < floorLayoutCopy.size(); ++i){
		for (unsigned int j = 0; j < floorLayoutCopy.at(i).size(); ++j){
			current = floorLayoutCopy.at(i).at(j);
			if (current == '.'){
				floodFillChamber(j,i,'X',floorLayoutCopy);
				floodFillChamber(j,i,'X',floodFillAcc);
				createChamber(floodFillAcc);
				floodFillChamber(j,i,'.',floodFillAcc);				
			}			
		}
	}
}

void Floor::initializeCells(vector<vector<char> > floorLayout){ 

	char current;
	for (int i = 0; i < BOARD_HEIGHT; ++i){
		vector<Cell*> row;
		for (int j = 0; j < BOARD_WIDTH; ++j){
			
			current = floorLayout.at(i).at(j);
			Cell *parsedCell = generateCell(i,j,current);
			parsedCell->notifyDisplay(*td);
			row.push_back(parsedCell);
		}
		allCells.push_back(row);		
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

		//Item case
		if (isdigit(symbol)){
			ItemFactory itFactory = ItemFactory();
			Item* newItem = itFactory.getItem(symbol);
			hasItem = true;
			id = newItem->getId();
			floorItems[id] = newItem;
		}
		
		//Enemy case
		if  ((symbol == 'V')||
			(symbol == 'W')||
			(symbol == 'N')||
			(symbol == 'M')||
			(symbol == 'X')||
			(symbol == 'T')||
			(symbol == 'M')){
			EnemyFactory enFactory = EnemyFactory();			
			Enemy *newEnemy = enFactory.getEnemy(symbol);
			newEnemy->setPos(xPos,yPos);
			hasEnemy = true;
			id = newEnemy->getId();
			floorCharacters[id] = newEnemy;
		}
		
		//Player case
		if (symbol == '@'){
			hasPlayer = true;
			Player *player = Player::getInstance();
			player->setPos(xPos,yPos);
			id = player->getId();		
			floorCharacters[id] = player;
		}
		
		parsedCell = new Cell(xPos,yPos,cellType,symbol,hasEnemy,hasItem,hasPlayer,id);
	}
	
	else{
		parsedCell = new Cell(xPos,yPos,cellType,symbol);
	}
	
	return parsedCell;
}

void Floor::display(){
	cout << *td;
}

void Floor::generateEnemies()
{
    int random;
    for (int i = 0; i < dragons; ++i) //set number of dragons first, determined by number of dragon hoards
    {
        enemy[i] = dragons;
    }

    random = rand() % 18 + 1; //random number between 1 and 18

    for (int i = dragons; i < numEnemies; ++i)
    {
        if (random >= 1 && random <= 4) // 2/9 chance of being werewolf
        {
            enemy[i] = 'w';
        }
        else if (random >= 5 && random <= 7) // 3/18 chance of being vampire
        {
            enemy[i] = 'v';
        }
        else if (random >= 8 && random <= 12) // 5/18 of being goblin
        {
            enemy[i] = 'g';
        }
        else if (random >= 13 && random <= 14) // 1/18 troll
        {
            enemy[i] = 't';
        }
        else if (random >= 15 && random <= 16) // 1/18 phoenix
        {
            enemy[i] = 'p';
        }
        else // 1/18 merchant
        {
            enemy[i] = 'm';
        }

    }
}


void Floor::generateGoldPiles() //randomly generate the 10 gold piles
{
    int random;
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

void Floor::removeItem(int id){
	
	delete floorItems[id];
	floorItems.erase(id);
}

TextDisplay* Floor::getTextDisplay(){ return td; }

Cell* Floor::getCellAt(int xPos, int yPos) { return allCells.at(xPos).at(yPos); }
