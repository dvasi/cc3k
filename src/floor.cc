#include <iostream>
#include <vector>
#include "floor.h"
#include "world.h"
#include "cell.h"

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

	for (int i = 0; i < BOARD_HEIGHT; ++i){
		vector<Cell*> row;
		for (int j = 0; j < BOARD_WIDTH; ++j){
			int cellType = Cell::charToCellType((floorLayout.at(i)).at(j));
			row.push_back(new Cell(i,j,cellType));
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
