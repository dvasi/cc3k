#include <iostream>
#include <vector>
#include "cell.h"
using namespace std;

Cell::Cell(int xPos, int yPos, int type): x(xPos), y(yPos), cellType(type), hasEnemy(false), hasItem(false), hasPlayer(false), occupiedId(-1) {}

Cell::~Cell(){}

void Cell::setCellType(int type) { cellType = type; }

int Cell::getCellType() { return cellType; }
