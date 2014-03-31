#include "rhPot.h"
#include <string>
using namespace std;

RHPot::RHPot(int id): Potion(id,10){}

bool RHPot::isRevealed(){ return RHPot::revealed; }

string RHPot::getName(){ return "RH potion"; }

bool RHPot::revealed = false;
