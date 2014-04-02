#ifndef __WAPOT_H__
#define __WAPOT_H__
#include "potion.h"
#include <string>

class Visitor;

class WAPot: public Potion{

    static bool revealed;
public:
    WAPot(int id);
    bool isRevealed();
    static void revealPotion();
    static void concealPotion();
    std::string getName();
    void accept(Visitor &v);
};
#endif
