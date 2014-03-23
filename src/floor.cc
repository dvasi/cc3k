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

Floor::Floor(){}

Floor::~Floor(){

	for (unsigned int i = 0; i < allCells.size(); ++i){
		while(!allCells.at(i).empty()){
			delete allCells.at(i).back();
			allCells.at(i).pop_back();
		}
	}

}

void Floor::initializeChambers(){
	//TODO
}

void Floor::initializePassages(){
	//TODO
}

void Floor::initializeCells(vector<vector<char> > floorLayout){ 


	//REFACTOR THIS FUNCTION LATER, SO SPAGHETTI LIKE AND LONG AND UGLY
	FileParser parser = FileParser();
	char current;
	for (int i = 0; i < BOARD_HEIGHT; ++i){
		vector<Cell*> row;
		for (int j = 0; j < BOARD_WIDTH; ++j){
			
			current = floorLayout.at(i).at(j);
			int cellType = parser.charToCellType(current);
			Cell *parsedCell;
			if (cellType == Cell::Floor){
			
				bool hasItem = false;
				bool hasEnemy = false;
				bool hasPlayer = false;
				int id = -1;

				//Item case - char is a digit
				if (isdigit(current)){
					ItemFactory itFactory = ItemFactory();
					Item* newItem = itFactory.getItem(current);
					hasItem = true;
					id = newItem->getId();
					floorItems[id] = newItem;
				}
				
				//Enemy case
				
				//Player case possibly
				
				parsedCell = new Cell(i,j,cellType,hasItem,hasEnemy,hasPlayer,id);
			}
			else{
				parsedCell = new Cell(i,j,cellType);
			}
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
