#include <iostream>
#include <vector>
#include <cstdlib>
#include "cell.h"
using namespace std;

Cell::Cell(int xPos, int yPos, int type, char symbol) :
    x(xPos), y(yPos), cellType(type), cellSymbol(symbol), enemy(false),
        item(false), player(false), occupiedId(-1){
}

Cell::Cell(int xPos, int yPos, int type, char symbol, bool hasEnemy,
    bool hasItem, bool hasPlayer, int id) :
    x(xPos), y(yPos), cellType(type), cellSymbol(symbol), enemy(hasEnemy),
        item(hasItem), player(hasPlayer), occupiedId(id){
}

Cell::~Cell(){
}

void Cell::setOccupiedId(int id){
    occupiedId = id;
}

int Cell::getOccupiedId(){
    return occupiedId;
}

bool Cell::hasItem(){
    return item;
}

bool Cell::hasGold(){
    return ((item) && (symbolToDisplayChar(cellSymbol) == 'G'));
}

bool Cell::hasPotion(){
    return ((item) && (symbolToDisplayChar(cellSymbol) == 'P'));
}

bool Cell::hasEnemy(){
    return enemy;
}

bool Cell::hasPlayer(){
    return player;
}

void Cell::setOccupation(bool hasEnemy, bool hasItem, bool hasPlayer, int id){
    enemy = hasEnemy;
    item = hasItem;
    player = hasPlayer;
    occupiedId = id;
}

bool Cell::isOccupied(){
    return (enemy || item || player);
}

void Cell::setCellType(int type){
    cellType = type;
}

int Cell::getCellType(){
    return cellType;
}

void Cell::setCellSymbol(char symbol){
    cellSymbol = symbol;
}

char Cell::getCellSymbol(){
    return cellSymbol;
}

int Cell::getXPos(){
    return x;
}

int Cell::getYPos(){
    return y;
}

char Cell::symbolToDisplayChar(char cellSymbol){
    if (!isdigit(cellSymbol)) return cellSymbol;

    //Potions represented by 0-5  in layout files
    if ((cellSymbol >= 48) && (cellSymbol <= 53)) return 'P';

    //Gold represented by 6-9 in layout files
    if ((cellSymbol >= 54) && (cellSymbol <= 57)) return 'G';

    else return ' ';
}

char Cell::typeToDisplayChar(int cellType){
    if (cellType == Cell::Doorway) return '+';
    if (cellType == Cell::Passage) return '#';
    if (cellType == Cell::Floor) return '.';
    return ' ';
}

void Cell::notifyDisplay(TextDisplay &td){
    td.notify(x, y, symbolToDisplayChar(cellSymbol));
}
