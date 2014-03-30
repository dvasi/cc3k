#ifndef __RHPOT_H__
#define __RHPOT_H__
#include "potion.h"
#include "item.h"

class rhPot: public Potion
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
public:
    //int getMagnitude();
    rhPot(int id);

};

#endif