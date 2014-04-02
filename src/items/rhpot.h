#ifndef __RHPOT_H__
#define __RHPOT_H__
#include "potion.h"
#include <string>

class Visitor;

class RHPot: public Potion{

    static bool revealed;
public:
    RHPot(int id);
    bool isRevealed();
    static void revealPotion();
    static void concealPotion();
    std::string getName();
    void accept(Visitor &v);
};
#endif
