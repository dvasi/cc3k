#include "potion.h"
#include "visitor.h"
using namespace std;

int Potion::getMagnitude(){
    return magnitude;
}

Potion::Potion(int id, int magnitude): Item (id,false,true), magnitude(magnitude){}

bool Potion::isRevealed(){ return false; }

void Potion::accept(Visitor &v) { v.visit(this); }
