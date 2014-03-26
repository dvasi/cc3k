#include "movecommand.h"
#include "character.h"

MoveCommand::MoveCommand(Character *character, int xPos, int yPos):
	character(character),xPos(xPos),yPos(yPos){}
	
MoveCommand::~MoveCommand(){}

Character* MoveCommand::getCharacter(){ return character; }

int MoveCommand::getXPos() { return xPos; }
		
int MoveCommand::getYPos() { return yPos; }

