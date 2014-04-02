#ifndef __ATTACKVISITOR_H__
#define __ATTACKVISITOR_H__
#include "visitor.h"

class Character;
class Enemy;
class Merchant;
class BAPot;
class BDPot;
class PHPot;
class RHPot;
class WAPot;
class WDPot;

class AttackVisitor: public Visitor{

    Character *attacker;
public:
    AttackVisitor(Character* ch);
    ~AttackVisitor();
    int visit(Character* defender);
    int visit(Enemy* enemy);
    int visit(Merchant* merchant);
    int visit(Dragon* dragon);
    void visit(BAPot* potion);
    void visit(BDPot* potion);
    void visit(PHPot* potion);
    void visit(RHPot* potion);
    void visit(WAPot* potion);
    void visit(WDPot* potion);
};
#endif
