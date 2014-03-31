#include "wdPot.h"
using namespace std;

WDPot::WDPot(int id): Potion(id,-5){}

bool WDPot::isRevealed(){ return WDPot::revealed; }

bool WDPot::revealed = false;

