#ifndef __BAPOT_H__
#define __BAPOT_H__
#include <string>
#include "potion.h"

class Visitor;

class BAPot: public Potion{
    static bool revealed;
public:
    BAPot(int id);
    bool isRevealed();
    static void revealPotion();
    static void concealPotion();
    std::string getName();
    void accept(Visitor &v);
};

#endif
