#ifndef __BDPOT_H__
#define __BDPOT_H__
#include "potion.h"
#include <string>

class Visitor;

class BDPot: public Potion
{
	static bool revealed;
public:
    BDPot(int id);
    bool isRevealed();
    static void revealPotion();
    static void concealPotion();
    std::string getName();
    void accept(Visitor &v);
};

#endif
