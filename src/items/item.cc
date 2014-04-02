#include <iostream>
#include <string>
#include "item.h"
#include "visitor.h"
using namespace std;

Item::Item(int id, char type, bool lootable, bool useable, int x, int y) :
    id(id), type(type), lootable(lootable), useable(useable), x(x), y(y){
}

Item::~Item(){
}

int Item::generateId(){
    idCount++;
    return idCount;
}

int Item::getId(){
    return id;
}

bool Item::canPickUp(){
    return lootable;
}

bool Item::canUse(){
    return useable;
}

void Item::setPos(int xPos, int yPos){
    x = xPos;
    y = yPos;
}

int Item::getXPos(){
    return x;
}

int Item::getYPos(){
    return y;
}

string Item::getName(){
    return "Item";
}

char Item::getSymbol(){
    return type;
}

bool Item::isRevealed(){
    return true;
}

void Item::accept(Visitor &v){
}

int Item::idCount = 0;
