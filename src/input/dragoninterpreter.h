#ifndef __DRAGONINTERPRETER_H__
#define __DRAGONINTERPRETER_H__
#include "enemyinterpreter.h"

class Game;
class Enemy;

class DragonInterpreter: public EnemyInterpreter{

public:
    DragonInterpreter();
    ~DragonInterpreter();
    bool playerInRange(Enemy* enemy);
};
#endif

