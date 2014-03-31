#include "bapot.h"
#include "visitor.h"
#include <string>
using namespace std;

BAPot::BAPot(int id): Potion(id, 5){}

bool BAPot::isRevealed(){ return BAPot::revealed; }

string BAPot::getName(){ return "BA potion"; }

void BAPot::accept(Visitor &v) { v.visit(this); }

bool BAPot::revealed = false;
