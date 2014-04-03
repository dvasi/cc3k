#include "itemusecommand.h"
#include "character.h"

ItemUseCommand::ItemUseCommand(Character *user, int itemXPos, int itemYPos) :
    Command(itemXPos, itemYPos), user(user){
}

ItemUseCommand::~ItemUseCommand(){
}

Character* ItemUseCommand::getUser(){
    return user;
}
