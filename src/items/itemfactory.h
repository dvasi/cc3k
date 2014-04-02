#ifndef __ITEMFACTORY_H__
#define __ITEMFACTORY_H__
#include "item.h"
class ItemFactory{
	
	public:
		ItemFactory();
		Item* getItem(char itemChar);
		Item* getPotion();
		Item* getGold();
};
#endif
