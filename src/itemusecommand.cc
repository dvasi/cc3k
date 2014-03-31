#include "itemusecommand.h"
#include "character.h"

ItemUseCommand::ItemUseCommand(Character *user, int itemXPos, int itemYPos):
		user(user),itemXPos(itemXPos),itemYPos(itemYPos){}

ItemUseCommand::~ItemUseCommand(){}

Character* ItemUseCommand::getUser(){ return user; }

int ItemUseCommand::getXPos(){ return itemXPos; }

int ItemUseCommand::getYPos(){ return itemYPos; }

