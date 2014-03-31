#include "baPot.h"
#include <string>
using namespace std;

BAPot::BAPot(int id): Potion(id, 5){}

bool BAPot::isRevealed(){ return BAPot::revealed; }

string BAPot::getName(){ return "BA potion"; }

bool BAPot::revealed = false;
