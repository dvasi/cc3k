#ifndef __ITEMUSECOMMAND_H__
#define __ITEMUSECOMMAND_H__
#include "command.h"
class Item;

class ItemUseCommand: public Command {

	Item* item;
	int itemXPos, itemYPos;
public:
	ItemUseCommand(Item *item, int itemXPos, int itemYPos);
	~ItemUseCommand();
	Item *getItem();
	int getXPos();
	int getYPos();
};
#endif

