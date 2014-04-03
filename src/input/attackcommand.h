#ifndef __ATTACKCOMMAND_H__
#define __ATTACKCOMMAND_H__
#include "command.h"

class Character;

class AttackCommand: public Command{

    Character *attacker;
public:
    AttackCommand(Character *attacker, int attackXPos, int attackYPos);
    ~AttackCommand();
    Character* getAttacker();
};
#endif
