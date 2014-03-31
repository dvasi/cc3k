#include "bdPot.h"
#include <string>
using namespace std;

BDPot::BDPot(int id): Potion(id,5){}

bool BDPot::isRevealed(){ return BDPot::revealed; }

string BDPot::getName(){ return "BD potion"; }

bool BDPot::revealed = false;
