#include "phpot.h"
#include "visitor.h"
#include <string>
using namespace std;

PHPot::PHPot(int id): Potion(id,-10){}

bool PHPot::isRevealed(){ return PHPot::revealed; }

void PHPot::revealPotion(){ PHPot::revealed = true; }

string PHPot::getName(){ return "PH potion"; }

void PHPot::accept(Visitor &v){ v.visit(this); }

bool PHPot::revealed = false;
