#include "dragon.h"
#include "enemyinterpreter.h"
#include "gold.h"
#include "visitor.h"
using namespace std;

Dragon::Dragon(int x, int y, int id): Enemy(15,20,20,x,y,'D',id, new EnemyInterpreter(), true, false), guardedHoard(0){}

Dragon::~Dragon(){}

void Dragon::guard(Gold *hoard){
	guardedHoard = hoard;
	guardedHoard->lootable = false;
}

void Dragon::freeHoard(){
	if (guardedHoard) guardedHoard->lootable = true;
}

int Dragon::accept(Visitor &v){ return v.visit(this); }
