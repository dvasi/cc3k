#ifndef __ENEMYFACTORY_H__
#define __ENEMYFACTORY_H__
#include "enemy.h"
class EnemyFactory{
	
	public:
		EnemyFactory();
		Enemy* getEnemy(char enemyChar);		
};
#endif
