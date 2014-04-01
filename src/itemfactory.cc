#include "itemfactory.h"
#include "gold.h"
#include "rhpot.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "wapot.h"
#include "wdpot.h"

ItemFactory::ItemFactory() {}

Item *ItemFactory::getItem(char itemChar)
{

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
        newItem =  new Gold(Item::generateId(), 1);
    else if (itemChar == '7') //small hoard
        newItem =  new Gold(Item::generateId(), 2);
    else if (itemChar == '8') //merchant hoard
        newItem =  new Gold(Item::generateId(), 4);
    else //dragon hoard, itemChar '9'
        newItem =  new Gold(Item::generateId(), 6,false);

    return newItem;
}
