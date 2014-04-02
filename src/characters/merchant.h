#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "enemy.h"

class Visitor;

class Merchant: public Enemy{

    static bool hostile;
public:
    Merchant(int x, int y, int id);
    ~Merchant();
    int accept(Visitor &v);
    bool isHostile();
    static void setAngryMode(bool angry = true);
};
#endif
