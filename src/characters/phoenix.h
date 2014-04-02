#ifndef __PHOENIX_H__
#define __PHOENIX_H__
#include "enemy.h"

class Phoenix: public Enemy{

public:
    Phoenix(int x, int y, int id);
    ~Phoenix();
};
#endif
