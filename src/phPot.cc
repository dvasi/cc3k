#include "phPot.h"
#include <string>
using namespace std;

PHPot::PHPot(int id): Potion(id,-10){}

bool PHPot::isRevealed(){ return PHPot::revealed; }

string PHPot::getName(){ return "PH potion"; }

bool PHPot::revealed = false;
