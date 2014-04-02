#ifndef __MOVECOMMAND_H__
#define __MOVECOMMAND_H__
#include "command.h"

class Character;

class MoveCommand: public Command{

    Character* character;
    int xPos, yPos;
public:
    MoveCommand(Character *character, int xPos, int yPos);
    ~MoveCommand();
    Character* getCharacter();
    int getXPos();
    int getYPos();
};
#endif
