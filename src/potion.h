#ifndef __POTION_H__
#define __POTION_H__

class Potion: public Item
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
    bool beneficial; //good potion or bad potion
public:
    int getMagnitude();
};

#endif