#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
#include "enemy.h"

class Vampire: public Enemy{

public:
    Vampire(int x, int y, int id);
    ~Vampire();
};
#endif
