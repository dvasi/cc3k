#include "attackcommand.h"

AttackCommand::AttackCommand(Character *attacker, int attackXPos,
    int attackYPos) :
    attacker(attacker), attackXPos(attackXPos), attackYPos(attackYPos){
}

AttackCommand::~AttackCommand(){
}

Character* AttackCommand::getAttacker(){
    return attacker;
}

int AttackCommand::getXPos(){
    return attackXPos;
}

int AttackCommand::getYPos(){
    return attackYPos;
}

