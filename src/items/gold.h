#ifndef __GOLD_H__
#define __GOLD_H__
#include "item.h"

class Visitor;

class Gold: public Item{

    friend class Dragon;
protected:
    double value;
public:
    Gold(int id, double value, char type, bool lootable = true);
    ~Gold();
    virtual double getValue();
    virtual void setValue(int value);
    virtual void accept(Visitor &v);
};
#endif
