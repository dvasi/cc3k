#include "phPot.h"
using namespace std;

PHPot::PHPot(int id): Potion(id,-10){}

bool PHPot::isRevealed(){ return PHPot::revealed; }

bool PHPot::revealed = false;
