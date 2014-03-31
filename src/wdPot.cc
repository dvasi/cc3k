#include "wdPot.h"
#include <string>
using namespace std;

WDPot::WDPot(int id): Potion(id,-5){}

bool WDPot::isRevealed(){ return WDPot::revealed; }

string WDPot::getName(){ return "WD potion"; }

bool WDPot::revealed = false;

