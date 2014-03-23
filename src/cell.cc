#include <iostream>
#include <vector>
#include "cell.h"
using namespace std;

Cell::Cell(int xPos, int yPos, int type): x(xPos), y(yPos), cellType(type), hasEnemy(false), hasItem(false), hasPlayer(false), occupiedId(-1) {}

Cell::~Cell(){}

void Cell::setCellType(int type) { cellType = type; }

int Cell::getCellType() { return cellType; }

int Cell::charToCellType(char c){

	if (c == ' ') return Cell::Empty;
	
	if ((c == '|')||(c == '-')) return Cell::Wall;
	
	if (c == '+') return Cell::Doorway;
	
	if (c == '#') return Cell::Passage;
	
	else return Cell::Floor;

}
