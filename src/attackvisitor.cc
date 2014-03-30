#include "character.h"
#include "attackvisitor.h"
#include <cmath>
#include <cstdlib>
#include <ncurses.h>
#include <sstream>
#include <string>
using namespace std;

AttackVisitor::AttackVisitor(Character* ch): attacker(ch){}

AttackVisitor::~AttackVisitor(){}

void AttackVisitor::visit(Character *defender){
	double atk = static_cast<double>(attacker->getAtk());
	double def = static_cast<double>(defender->getDef());
	int damage = static_cast<int>(ceil((100.00 / (100.00 + def)) * atk));
	
    defender->takeDmg(damage);
}
