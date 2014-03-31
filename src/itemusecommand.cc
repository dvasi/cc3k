#include "itemusecommand.h"
#include "item.h"

ItemUseCommand::ItemUseCommand(Item *item, int itemXPos, int itemYPos):
		item(item),itemXPos(itemXPos),itemYPos(itemYPos){}

ItemUseCommand::~ItemUseCommand(){}

Item* ItemUseCommand::getItem(){ return item; }

int ItemUseCommand::getXPos(){ return itemXPos; }

int ItemUseCommand::getYPos(){ return itemYPos; }

