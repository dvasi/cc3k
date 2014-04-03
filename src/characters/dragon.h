#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"
#include "dragongold.h"

class Gold;
class Visitor;

class Dragon: public Enemy{

    DragonGold *guardedHoard;
public:
    Dragon(int x, int y, int id);
    ~Dragon();
    void guard(DragonGold *hoard);
    void freeHoard();
    int accept(Visitor &v);
    int getHoardXPos();
    int getHoardYPos();
};
#endif
