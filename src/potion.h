#ifndef __POTION_H__
#define __POTION_H__
#include "item.h"
class Visitor;

class Potion: public Item
{
protected:
    int magnitude;
    bool revealed; //whether or not the player knows the potion's effect
public:
	Potion(int id);
    int getMagnitude();
    bool isRevealed();
    void accept(Visitor &v);
};

#endif
