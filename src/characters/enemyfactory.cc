#include "enemyfactory.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "goblin.h"
#include "merchant.h"
#include "dragon.h"
#include "phoenix.h"

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
    else if (enemyChar == 'N')
        newEnemy = new Goblin(0, 0, Character::generateId());
    else if (enemyChar == 'M')
        newEnemy = new Merchant(0, 0, Character::generateId());
    else if (enemyChar == 'D')
        newEnemy = new Dragon(0, 0, Character::generateId());
    else if (enemyChar == 'X')
        newEnemy = new Phoenix(0, 0, Character::generateId());

    return newEnemy;
}
