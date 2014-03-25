#include "itemfactory.h"
#include "gold.h"

ItemFactory::ItemFactory(){}

Item* ItemFactory::getItem(char itemChar){

	Item* newItem = new Gold(Item::generateId());
	return newItem;
}
