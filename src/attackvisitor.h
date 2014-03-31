#ifndef __ATTACKVISITOR_H__
#define __ATTACKVISITOR_H__
#include "visitor.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "wapot.h"
#include "rhpot.h"
#include "wdpot.h"
class Character;

class AttackVisitor : public Visitor{

	Character *attacker;
	public:
		AttackVisitor(Character* ch);
		~AttackVisitor();
		int visit(Character* defender);
		void visit(BAPot* potion);
		void visit(BDPot* potion);
		void visit(PHPot* potion);
		void visit(RHPot* potion);
		void visit(WAPot* potion);
		void visit(WDPot* potion);
};
#endif
