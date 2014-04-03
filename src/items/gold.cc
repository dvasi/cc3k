#include <iostream>
#include "gold.h"
#include "visitor.h"
using namespace std;

Gold::Gold(int id, double value, char type, bool lootable) :
    Item(id, type, lootable, false), value(value){
}

Gold::~Gold(){
}

double Gold::getValue(){
    return value;
}

void Gold::accept(Visitor &v){
    v.visit(this);
}
