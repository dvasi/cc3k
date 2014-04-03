#ifndef __ITEMUSECOMMAND_H__
#define __ITEMUSECOMMAND_H__
#include "command.h"

class Character;

class ItemUseCommand: public Command{

    Character* user;
public:
    ItemUseCommand(Character *user, int itemXPos, int itemYPos);
    ~ItemUseCommand();
    Character *getUser();
};
#endif

