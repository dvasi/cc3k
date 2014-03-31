#include "character.h"
#include "attackvisitor.h"
#include <cmath>
#include <cstdlib>
#include <ncurses.h>
#include <sstream>
#include <string>
#include <iostream>
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "wapot.h"
#include "rhpot.h"
#include "wdpot.h"
using namespace std;

AttackVisitor::AttackVisitor(Character* ch): attacker(ch){}

AttackVisitor::~AttackVisitor(){}

int AttackVisitor::visit(Character *defender){
	double atk = static_cast<double>(attacker->getAtk());
	double def = static_cast<double>(defender->getDef());
	int damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));
	
    defender->takeDmg(damage);
    return damage;
}

void AttackVisitor::visit(BAPot* potion){}

void AttackVisitor::visit(BDPot* potion){}

void AttackVisitor::visit(PHPot* potion){}

void AttackVisitor::visit(RHPot* potion){}

void AttackVisitor::visit(WAPot* potion){}

void AttackVisitor::visit(WDPot* potion){cout<<"VISITING";}
