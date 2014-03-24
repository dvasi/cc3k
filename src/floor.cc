#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "floor.h"
#include "world.h"
#include "cell.h"
#include "chamber.h"
#include "fileparser.h"
#include "itemfactory.h"

using namespace std;

Floor::Floor(){
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
	
		bool hasItem = false;
		bool hasEnemy = false;
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
		
		//Player case
		
		parsedCell = new Cell(xPos,yPos,cellType,symbol,hasItem,hasEnemy,hasPlayer,id);
	}
	
	else{
		parsedCell = new Cell(xPos,yPos,cellType,symbol);
	}
	
	return parsedCell;
}

void Floor::display(){
	cout << *td;
}
