#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "player.h"

class Human: public Player{

public:
    Human(int x, int y, int id);
    ~Human();
};
#endif
