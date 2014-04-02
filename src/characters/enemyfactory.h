#ifndef __ENEMYFACTORY_H__
#define __ENEMYFACTORY_H__

class Enemy;

class EnemyFactory{

public:
    EnemyFactory();
    Enemy* getEnemy(char enemyChar);
    Enemy* getEnemy();
};
#endif
