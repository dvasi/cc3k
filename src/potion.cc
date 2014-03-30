#include "potion.h"
#include "visitor.h"
using namespace std;

int Potion::getMagnitude()
{
    return magnitude;
}

bool Potion::isRevealed(){ return revealed; }

void Potion::accept(Visitor &v) { v.visit(this); }
