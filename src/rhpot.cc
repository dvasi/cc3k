#include "rhpot.h"
#include "visitor.h"
#include <string>
using namespace std;

RHPot::RHPot(int id): Potion(id,10){}

bool RHPot::isRevealed(){ return RHPot::revealed; }

string RHPot::getName(){ return "RH potion"; }

void RHPot::accept(Visitor &v){ v.visit(this); }

bool RHPot::revealed = false;
