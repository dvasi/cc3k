#include "character.h"
#include "player.h"
#include "merchant.h"
#include "dragon.h"
#include "attackvisitor.h"
#include <cmath>
#include <cstdlib>
#include <ncurses.h>
#include <sstream>
#include <string>

using namespace std;

class BAPot;
class BDPot;
class PHPot;
class RHPot;
class WAPot;
class WDPot;

AttackVisitor::AttackVisitor(Character* ch): attacker(ch){}

AttackVisitor::~AttackVisitor(){}

int AttackVisitor::visit(Character *defender){
	double atk = static_cast<double>(attacker->getAtk());
	double def = static_cast<double>(defender->getDef());
	int damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));
	
    defender->takeDmg(damage);
    return damage;
}

int AttackVisitor::visit(Enemy* defender){
	double atk = static_cast<double>(attacker->getAtk());
	double def = static_cast<double>(defender->getDef());
	int damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));

	defender->takeDmg(damage);
	if (defender->getHp() <=0 ){
		Player *player = Player::getInstance();
		player->setGold(player->getGold()+1);
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

void AttackVisitor::visit(BAPot* potion){}

void AttackVisitor::visit(BDPot* potion){}

void AttackVisitor::visit(PHPot* potion){}

void AttackVisitor::visit(RHPot* potion){}

void AttackVisitor::visit(WAPot* potion){}

void AttackVisitor::visit(WDPot* potion){}
