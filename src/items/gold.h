#ifndef __GOLD_H__
#define __GOLD_H__
#include "item.h"

class Visitor;

class Gold: public Item{

protected:
    double value;
public:
    Gold(int id, double value, char type, bool lootable = true);
    ~Gold();
    double getValue();
    virtual void accept(Visitor &v);
};
#endif
