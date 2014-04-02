#include "enemyfactory.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "goblin.h"
#include "merchant.h"
#include "dragon.h"
#include "phoenix.h"
#include <cstdlib>

EnemyFactory::EnemyFactory(){
}

Enemy *EnemyFactory::getEnemy(char enemyChar){
    Enemy *newEnemy;

    if (enemyChar == 'V') newEnemy = new Vampire(0, 0, Character::generateId());
    else if (enemyChar == 'W') newEnemy = new Werewolf(0, 0,
        Character::generateId());
    else if (enemyChar == 'T') newEnemy = new Troll(0, 0,
        Character::generateId());
    else if (enemyChar == 'N') newEnemy = new Goblin(0, 0,
        Character::generateId());
    else if (enemyChar == 'M') newEnemy = new Merchant(0, 0,
        Character::generateId());
    else if (enemyChar == 'D') newEnemy = new Dragon(0, 0,
        Character::generateId());
    else if (enemyChar == 'X') newEnemy = new Phoenix(0, 0,
        Character::generateId());

    return newEnemy;
}

Enemy *EnemyFactory::getEnemy(){
    Enemy *newEnemy;
    int random;
    random = (rand() % 18) + 1;

    if (random >= 1 && random <= 4) newEnemy = new Werewolf(0, 0,
        Character::generateId());

    else if (random >= 5 && random <= 7) newEnemy = new Vampire(0, 0,
        Character::generateId());

    else if (random >= 8 && random <= 12) newEnemy = new Goblin(0, 0,
        Character::generateId());

    else if (random >= 13 && random <= 14) newEnemy = new Troll(0, 0,
        Character::generateId());

    else if (random >= 15 && random <= 16) newEnemy = new Phoenix(0, 0,
        Character::generateId());

    else newEnemy = new Merchant(0, 0, Character::generateId());

    return newEnemy;
}
