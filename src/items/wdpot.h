#ifndef __WDPOT_H__
#define __WDPOT_H__
#include "potion.h"
#include <string>

class Visitor;

class WDPot: public Potion{
    static bool revealed;
public:
    WDPot(int id);
    bool isRevealed();
    static void revealPotion();
    static void concealPotion();
    std::string getName();
    void accept(Visitor &v);
};

#endif

