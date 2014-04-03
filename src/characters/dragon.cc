#include "dragon.h"
#include "dragoninterpreter.h"
#include "dragongold.h"
#include "visitor.h"
using namespace std;

Dragon::Dragon(int x, int y, int id) :
    Enemy(150, 20, 20, x, y, 'D', id, new DragonInterpreter(), true, false),
        guardedHoard(0){
}

Dragon::~Dragon(){
}

void Dragon::guard(DragonGold *hoard){
    guardedHoard = hoard;
    guardedHoard->lootable = false;
}

void Dragon::freeHoard(){
    if (guardedHoard) guardedHoard->lootable = true;
}

int Dragon::accept(Visitor &v){
    return v.visit(this);
}

int Dragon::getHoardXPos(){
    return guardedHoard->getXPos();
}

int Dragon::getHoardYPos(){
    return guardedHoard->getYPos();
}
