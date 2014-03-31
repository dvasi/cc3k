#include <iostream>
#include <string>
#include "item.h"
#include "visitor.h"
using namespace std;

Item::Item(int id, bool lootable, bool useable): id(id), lootable(lootable), useable(useable) {}

Item::~Item() {}

int Item::generateId(){
	idCount++;
	return idCount;
}


int Item::getId(){ return id; }

bool Item::canPickUp(){ return lootable; }

bool Item::canUse(){ return useable; }

string Item::getName(){ return "Item"; }

bool Item::isRevealed(){ return true; }

void Item::accept(Visitor &v) {}

int Item::idCount = 0;
