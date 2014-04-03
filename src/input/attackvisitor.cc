#include "character.h"
#include "player.h"
#include "merchant.h"
#include "dragon.h"
#include "attackvisitor.h"
#include "itemusevisitor.h"
#include "gold.h"
#include "normalgold.h"
#include <cmath>
#include <cstdlib>

using namespace std;

class BAPot;
class BDPot;
class PHPot;
class RHPot;
class WAPot;
class WDPot;

AttackVisitor::AttackVisitor(Character* ch) :
    attacker(ch){
}

AttackVisitor::~AttackVisitor(){
}

int AttackVisitor::visit(Character *defender){
    double atk = static_cast<double>(attacker->getAtk());
    double def = static_cast<double>(defender->getDef());

    //50% chance to miss attacks on non-enemy defenders (in this case PC)
    int random = (rand() % 2);

    int damage;
    if (random == 0) damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));
    else damage = 0;

    defender->takeDmg(damage);
    return damage;
}

int AttackVisitor::visit(Enemy* defender){
    double atk = static_cast<double>(attacker->getAtk());
    double def = static_cast<double>(defender->getDef());
    int damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));

    defender->takeDmg(damage);
    if (defender->getHp() <= 0){
        Gold loot = NormalGold(-1);
        ItemUseVisitor lootVisitor = ItemUseVisitor();
        loot.accept(lootVisitor);
    }
    return damage;
}

int AttackVisitor::visit(Merchant *defender){
    double atk = static_cast<double>(attacker->getAtk());
    double def = static_cast<double>(defender->getDef());
    int damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));

    defender->takeDmg(damage);
    if (!defender->isHostile()) Merchant::setAngryMode();

    return damage;
}

int AttackVisitor::visit(Dragon* defender){
    double atk = static_cast<double>(attacker->getAtk());
    double def = static_cast<double>(defender->getDef());
    int damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));

    defender->takeDmg(damage);
    if (defender->getHp() <= 0) defender->freeHoard();
    return damage;
}
