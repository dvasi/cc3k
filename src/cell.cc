#include <iostream>
#include <vector>
<<<<<<< HEAD
#include "cell.h"
using namespace std;

Cell::Cell(int xPos, int yPos, int type): x(xPos), y(yPos), cellType(type), hasEnemy(false), hasItem(false), hasPlayer(false), occupiedId(-1) {}

Cell::~Cell(){}
=======
#include <cstdlib>
#include "cell.h"
using namespace std;

Cell::Cell(int xPos, int yPos, int type, char symbol): x(xPos), y(yPos), cellType(type), cellSymbol(symbol), enemy(false), item(false), player(false), occupiedId(-1) {}

Cell::Cell(int xPos, int yPos, int type, char symbol, bool hasEnemy, bool hasItem, bool hasPlayer, int id):
	x(xPos), y(yPos), cellType(type), cellSymbol(symbol), enemy(hasEnemy), item(hasItem), player(hasPlayer), occupiedId(id){}

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
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb

void Cell::setCellType(int type) { cellType = type; }

int Cell::getCellType() { return cellType; }
<<<<<<< HEAD
=======

void Cell::setCellSymbol(char symbol) { cellSymbol = symbol; }

char Cell::getCellSymbol() { return cellSymbol; }

char Cell::symbolToDisplayChar(char cellSymbol){

	if (!isdigit(cellSymbol)) return cellSymbol;
	
	//Potions represented by 0-5  in layout files
	if ((cellSymbol >= 48)&&(cellSymbol <= 53)) return 'P';
	
	//Gold represented by 6-9 in layout files
	if ((cellSymbol >= 54)&&(cellSymbol <=57)) return 'G';
	
	else return ' ';
}

void Cell::notifyDisplay(TextDisplay &td){
	td.notify(x,y,symbolToDisplayChar(cellSymbol));
}
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
