#include "itemfactory.h"
#include "rhpot.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "wapot.h"
#include "wdpot.h"
#include "smallgold.h"
#include "normalgold.h"
#include "dragongold.h"
#include <cstdlib>

ItemFactory::ItemFactory() {}

Item *ItemFactory::getItem(char itemChar){

    Item *newItem;

    if (itemChar == '0') //RH
        newItem =  new RHPot(Item::generateId());
    else if (itemChar == '1') //BA
        newItem =  new BAPot(Item::generateId());
    else if (itemChar == '2') //BD
        newItem =  new BDPot(Item::generateId());
    else if (itemChar == '3') //PH
        newItem =  new PHPot(Item::generateId());
    else if (itemChar == '4') //WA
        newItem =  new WAPot(Item::generateId());
    else if (itemChar == '5') //WD
        newItem =  new WDPot(Item::generateId());
    else if (itemChar == '6') //normal gold pile
        newItem =  new NormalGold(Item::generateId());
    else if (itemChar == '7') //small hoard
        newItem =  new SmallGold(Item::generateId());
    else if (itemChar == '8') //merchant hoard
        newItem =  new Gold(Item::generateId(), 4, '8');
    else //dragon hoard, itemChar '9'
        newItem =  new DragonGold(Item::generateId());

    return newItem;
}


Item* ItemFactory::getPotion(){

    Item *newItem;
    int random;
    random = (rand()%6) + 1;

    if (random == 1)
    	newItem =  new RHPot(Item::generateId());
    else if (random == 2)
    	newItem =  new PHPot(Item::generateId());
    else if (random == 3)
    	newItem =  new BAPot(Item::generateId());
    else if (random == 4)
    	newItem =  new BDPot(Item::generateId());
    else if (random == 5)
    	newItem =  new WAPot(Item::generateId());
    else
    	newItem =  new WDPot(Item::generateId());

    return newItem;
}

Item* ItemFactory::getGold(){

	Item *newItem;
	int random;
	random = (rand()%8) + 1;

	if (random == 1)
		newItem = new DragonGold(Item::generateId());

	else if ((random >= 2)&&(random <=6))
		newItem =  new NormalGold(Item::generateId());

	else
		newItem =  new SmallGold(Item::generateId());

    return newItem;
}
