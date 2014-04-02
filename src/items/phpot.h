#ifndef __PHPOT_H__
#define __PHPOT_H__
#include "potion.h"
#include <string>

class Visitor;

class PHPot: public Potion{

    static bool revealed;
public:
    PHPot(int id);
    bool isRevealed();
    static void revealPotion();
    static void concealPotion();
    std::string getName();
    void accept(Visitor &v);
};
#endif
