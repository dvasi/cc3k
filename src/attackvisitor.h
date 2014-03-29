#ifndef __ATTACKVISITOR_H__
#define __ATTACKVISITOR_H__
#include "visitor.h"
class Character;

class AttackVisitor : public Visitor{

	Character *attacker;
	public:
		AttackVisitor(Character* ch);
		~AttackVisitor();
		void visit(Character* defender);
};
#endif
