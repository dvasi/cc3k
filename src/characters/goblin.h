#ifndef __GOBLIN_H__
#define __GOBLIN_H__
#include "enemy.h"
class Goblin: public Enemy{
public:
    Goblin(int x, int y, int id);
    ~Goblin();
};
#endif
