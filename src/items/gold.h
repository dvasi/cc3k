#ifndef __GOLD_H__
#define __GOLD_H__
#include "item.h"

class Visitor;

class Gold : public Item
{
	friend class Dragon;
    double value;
public:
    Gold(int id, double value=2, bool lootable=true);
    ~Gold();
    double getValue();
    void setValue(int value);
    void accept(Visitor &v);
};
#endif
