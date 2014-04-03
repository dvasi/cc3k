#ifndef __MOVECOMMAND_H__
#define __MOVECOMMAND_H__
#include "command.h"

class Character;

class MoveCommand: public Command{

    Character* character;
public:
    MoveCommand(Character *character, int xPos, int yPos);
    ~MoveCommand();
    Character* getCharacter();
};
#endif
