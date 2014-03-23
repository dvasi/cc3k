#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "floor.h"
#include "world.h"
#include "cell.h"
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

}

void Floor::initializeChambers(){
	//TODO
}

void Floor::initializePassages(){
	//TODO
}

void Floor::initializeCells(vector<vector<char> > floorLayout){ 

	char current;
	for (int i = 0; i < BOARD_HEIGHT; ++i){
		vector<Cell*> row;
		for (int j = 0; j < BOARD_WIDTH; ++j){
			
			current = floorLayout.at(i).at(j);
			Cell *parsedCell = generateCell(i,j,current);
			row.push_back(parsedCell);
		}
		allCells.push_back(row);		
	}
	
	initializeChambers();
	initializePassages();
	
	//For debugging
	for(int i = 0; i < BOARD_HEIGHT; ++i){	
		for(int j = 0; j < BOARD_WIDTH; ++j){
			cout << floorLayout.at(i).at(j);
		}
		cout << endl;
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
		
		parsedCell = new Cell(xPos,yPos,cellType,hasItem,hasEnemy,hasPlayer,id);
	}
	
	else{
		parsedCell = new Cell(xPos,yPos,cellType);
	}
	
	return parsedCell;
}
