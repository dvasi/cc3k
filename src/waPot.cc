#include "waPot.h"
using namespace std;

WAPot::WAPot(int id): Potion(id,-5){}

bool WAPot::isRevealed(){ return WAPot::revealed; }

bool WAPot::revealed = false;
