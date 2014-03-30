#ifndef __ITEMUSEVISITOR_H__
#define __ITEMUSEVISITOR_H__
#include "visitor.h"

class Potion;
class Gold;
class Player;

class ItemUseVisitor : public Visitor{

	Player *player;
	public:
		ItemUseVisitor();
		~ItemUseVisitor();
		void visit(Potion *potion);
		void visit(Gold *gold);
};
#endif
