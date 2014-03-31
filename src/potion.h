#ifndef __POTION_H__
#define __POTION_H__
#include "item.h"
class Visitor;

class Potion: public Item
{
protected:
    int magnitude;
public:
	Potion(int id, int magnitude);
    int getMagnitude();
    virtual bool isRevealed();
    void accept(Visitor &v);
};

#endif
