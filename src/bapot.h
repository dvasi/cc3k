#ifndef __BAPOT_H__
#define __BAPOT_H__
#include <string>
#include "potion.h"
#include "item.h"

class Visitor;

class BAPot: public Potion
{
	static bool revealed;
public:
    BAPot(int id);
    bool isRevealed();
    static void revealPotion();
    std::string getName();
    void accept(Visitor &v);
};

#endif
