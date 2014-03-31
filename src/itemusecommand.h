#ifndef __ITEMUSECOMMAND_H__
#define __ITEMUSECOMMAND_H__
#include "command.h"

class Character;

class ItemUseCommand: public Command {

	Character* user;
	int itemXPos, itemYPos;
public:
	ItemUseCommand(Character *user, int itemXPos, int itemYPos);
	~ItemUseCommand();
	Character *getUser();
	int getXPos();
	int getYPos();
};
#endif

