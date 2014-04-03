#include "movecommand.h"
#include "character.h"

MoveCommand::MoveCommand(Character *character, int xPos, int yPos) :
    Command(xPos,yPos), character(character){
}

MoveCommand::~MoveCommand(){
}

Character* MoveCommand::getCharacter(){
    return character;
}

