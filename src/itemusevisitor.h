#ifndef __ITEMUSEVISITOR_H__
#define __ITEMUSEVISITOR_H__
#include "visitor.h"

class BAPot;
class BDPot;
class PHPot;
class RHPot;
class WAPot;
class WDPot;
class Gold;
class Player;

class ItemUseVisitor : public Visitor{

	Player *player;
	int tempAtkDelta;
	int tempDefDelta;
	public:
		ItemUseVisitor();
		~ItemUseVisitor();
		void visit(BAPot *potion);
		void visit(BDPot *potion);
		void visit(PHPot *potion);
		void visit(RHPot *potion);
		void visit(WAPot *potion);
		void visit(WDPot *potion);
		void visit(Gold *gold);
		int getTempAtkDelta();
		int getTempDefDelta();
};
#endif
