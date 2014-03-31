#include "rhPot.h"
using namespace std;

RHPot::RHPot(int id): Potion(id,10){}

bool RHPot::isRevealed(){ return RHPot::revealed; }

bool RHPot::revealed = false;
