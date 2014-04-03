#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"

class Gold;
class Visitor;

class Dragon: public Enemy{

    Gold *guardedHoard;

public:
    Dragon(int x, int y, int id);
    void guard(Gold * hoard);
    void freeHoard();
    int getHoardXPos();
    int getHoardYPos();
    int accept(Visitor &v);
    ~Dragon();

};
#endif
