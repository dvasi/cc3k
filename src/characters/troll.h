#ifndef __TROLL_H__
#define __TROLL_H__
#include "enemy.h"
class Troll: public Enemy{
public:
    Troll(int x, int y, int id);
    ~Troll();
};
#endif
