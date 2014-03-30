#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"
class Dragon : public Enemy
{
public:
    Dragon(int x, int y, int id);
    ~Dragon();
};
#endif
