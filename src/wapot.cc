#include "wapot.h"
#include "visitor.h"
#include <string>
using namespace std;

WAPot::WAPot(int id): Potion(id,-5){}

bool WAPot::isRevealed(){ return WAPot::revealed; }

string WAPot::getName(){ return "WA potion"; }

void WAPot::accept(Visitor &v){ v.visit(this); }

bool WAPot::revealed = false;
