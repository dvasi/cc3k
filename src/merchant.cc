#include "merchant.h"
#include "enemyinterpreter.h"
#include "visitor.h"
using namespace std;

Merchant::Merchant(int x, int y, int id): Enemy(30,70,5,x,y,'M',id, new EnemyInterpreter(),false,true){}

Merchant::~Merchant(){}

int Merchant::accept(Visitor &v){ return v.visit(this); }

bool Merchant::isHostile(){ return Merchant::hostile; }

void Merchant::setAngryMode(bool angry){ Merchant::hostile = angry; }

bool Merchant::hostile = false;
