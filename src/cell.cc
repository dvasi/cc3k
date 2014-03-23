#include <iostream>
#include <vector>
#include "cell.h"
using namespace std;

Cell::Cell(int xPos, int yPos, int type): x(xPos), y(yPos), cellType(type), enemy(false), item(false), player(false), occupiedId(-1) {}

Cell::Cell(int xPos, int yPos, int type, bool hasEnemy, bool hasItem, bool hasPlayer, int id):
	x(xPos), y(yPos), cellType(type), enemy(hasEnemy), item(hasItem), player(hasPlayer), occupiedId(id){}

Cell::~Cell(){}
	
void Cell::setOccupiedId(int id) { occupiedId = id; }

int Cell::getOccupiedId() { return occupiedId; }

bool Cell::hasItem() { return item; }

bool Cell::hasEnemy() { return enemy; }

bool Cell::hasPlayer() { return player; }

void Cell::setOccupation(bool hasEnemy, bool hasItem, bool hasPlayer, int id){

	enemy = hasEnemy;
	item = hasItem;
	player = hasPlayer;
	occupiedId = id;
}

void Cell::setCellType(int type) { cellType = type; }

int Cell::getCellType() { return cellType; }

void Cell::notifyDisplay(TextDisplay &td){
	//
}
