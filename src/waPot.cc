#include "waPot.h"
#include <string>
using namespace std;

WAPot::WAPot(int id): Potion(id,-5){}

bool WAPot::isRevealed(){ return WAPot::revealed; }

string WAPot::getName(){ return "WA potion"; }

bool WAPot::revealed = false;
