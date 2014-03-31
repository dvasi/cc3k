#include "bdPot.h"
using namespace std;

BDPot::BDPot(int id): Potion(id,5){}

bool BDPot::isRevealed(){ return BDPot::revealed; }

bool BDPot::revealed = false;
