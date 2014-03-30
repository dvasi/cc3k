#ifndef __bdPot_H__
#define __bdPot_H__
#include "potion.h"
#include "item.h"

class bdPot: public Potion
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
public:
    //int getMagnitude();
    bdPot(int id);

};

#endif