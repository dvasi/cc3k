#ifndef __RHPOT_H__
#define __RHPOT_H__
#include "potion.h"
#include "item.h"
#include <string>

class Visitor;

class RHPot: public Potion
{
	static bool revealed;
public:
    RHPot(int id);
    bool isRevealed();
    static void revealPotion();
    std::string getName();
    void accept(Visitor &v);
};

#endif
