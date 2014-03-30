#include "enemyfactory.h"
#include "vampire.h"

EnemyFactory::EnemyFactory() {}

Enemy *EnemyFactory::getEnemy(char enemyChar)
{

    Enemy *newEnemy;
    
    if (enemyChar == 'V')
        newEnemy = new Vampire(0, 0, Character::generateId());
    else if (enemyChar == 'W')
        newEnemy = new Werewolf(0, 0, Character::generateId());
    else if (enemyChar == 'T')
        newEnemy = new Troll(0, 0, Character::generateId());
    else if (enemyChar == 'G')
        newEnemy = new Goblin(0, 0, Character::generateId());
    else if (enemyChar == 'M')
        newEnemy = new Merchant(0, 0, Character::generateId());
    else if (enemyChar == 'D')
        newEnemy = new Dragon(0, 0, Character::generateId());
    else // if (enemyChar == 'P')
        newEnemy = new Phoenix(0, 0, Character::generateId());

    return newEnemy;
}
