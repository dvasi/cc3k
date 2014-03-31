#include "bdpot.h"
#include "visitor.h"
#include <string>
using namespace std;

BDPot::BDPot(int id): Potion(id,5){}

bool BDPot::isRevealed(){ return BDPot::revealed; }

string BDPot::getName(){ return "BD potion"; }

void BDPot::accept(Visitor &v){ v.visit(this); }

bool BDPot::revealed = false;
