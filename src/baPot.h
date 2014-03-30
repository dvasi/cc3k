#ifndef __baPot_H__
#define __baPot_H__
#include "potion.h"
#include "item.h"

class baPot: public Potion
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
public:
    //int getMagnitude();
    baPot(int id);

};

#endif