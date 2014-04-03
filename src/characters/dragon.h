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
    void guard(DragonGold *hoard);
    void freeHoard();
    int getHoardXPos();
    int getHoardYPos();
    int accept(Visitor &v);
    ~Dragon();

};
#endif
