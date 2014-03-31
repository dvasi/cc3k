#include "baPot.h"
using namespace std;

BAPot::BAPot(int id): Potion(id, 5){}

bool BAPot::isRevealed(){ return BAPot::revealed; }

bool BAPot::revealed = false;
