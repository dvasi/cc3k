#ifndef __WDPOT_H__
#define __WDPOT_H__
#include "potion.h"
#include "item.h"

class wdPot: public Potion
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
public:
    //int getMagnitude();
    wdPot(int id);

};

#endif

