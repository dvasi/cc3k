#include "attackcommand.h"

AttackCommand::AttackCommand(Character *attacker, int attackXPos, int attackYPos) :
    Command(attackXPos, attackYPos), attacker(attacker){
}

AttackCommand::~AttackCommand(){
}

Character* AttackCommand::getAttacker(){
    return attacker;
}

