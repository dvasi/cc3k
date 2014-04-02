#ifndef __WEREWOLF_H__
#define __WEREWOLF_H__
#include "enemy.h"
class Werewolf : public Enemy
{
public:
    Werewolf(int x, int y, int id);
    ~Werewolf();
};
#endif
