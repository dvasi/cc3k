#include "bdpot.h"
#include "visitor.h"
#include <string>
using namespace std;

BDPot::BDPot(int id): Potion(id,5){}

bool BDPot::isRevealed(){ return BDPot::revealed; }

void BDPot::revealPotion(){ BDPot::revealed = true; }

void BDPot::concealPotion(){ BDPot::revealed = false; }

string BDPot::getName(){ return "BD potion"; }

void BDPot::accept(Visitor &v){ v.visit(this); }

bool BDPot::revealed = false;
