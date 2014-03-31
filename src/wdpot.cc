#include "wdpot.h"
#include "visitor.h"
#include <string>
using namespace std;

WDPot::WDPot(int id): Potion(id,-5){}

bool WDPot::isRevealed(){ return WDPot::revealed; }

void WDPot::revealPotion(){ WDPot::revealed = true; }

string WDPot::getName(){ return "WD potion"; }

void WDPot::accept(Visitor &v){ v.visit(this); }

bool WDPot::revealed = false;

