#ifndef __waPot_H__
#define __waPot_H__
#include "potion.h"
#include "item.h"

class waPot: public Potion
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
public:
    //int getMagnitude();
    waPot(int id);
};

#endif