#include "enemyfactory.h"
#include "vampire.h"

EnemyFactory::EnemyFactory(){}

Enemy* EnemyFactory::getEnemy(char enemyChar){

	Enemy *newEnemy;
	if (enemyChar == 'V')
		newEnemy = new Vampire(0,0,Character::generateId());
	return newEnemy;
}
