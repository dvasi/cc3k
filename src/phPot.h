#ifndef __phPot_H__
#define __phPot_H__
#include "potion.h"
#include "item.h"

class phPot: public Potion
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
public:
    //int getMagnitude();
    phPot(int id);

};

#endif