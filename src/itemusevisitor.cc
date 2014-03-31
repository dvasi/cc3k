#include "itemusevisitor.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "rhpot.h"
#include "wapot.h"
#include "wdpot.h"
#include "gold.h"
#include "player.h"

ItemUseVisitor::ItemUseVisitor(){ player = Player::getInstance(); }

ItemUseVisitor::~ItemUseVisitor(){}

void ItemUseVisitor::visit(BAPot *potion){
	player->alterAtk(potion->getMagnitude());
	BAPot::revealPotion();
}

void ItemUseVisitor::visit(BDPot *potion){
	player->alterDef(potion->getMagnitude());
	BDPot::revealPotion();
}

void ItemUseVisitor::visit(PHPot *potion){
	player->alterHp(potion->getMagnitude());
	PHPot::revealPotion();
}

void ItemUseVisitor::visit(RHPot *potion){
	player->alterHp(potion->getMagnitude());
	RHPot::revealPotion();
}

void ItemUseVisitor::visit(WAPot *potion){
	player->alterAtk(potion->getMagnitude());
	WAPot::revealPotion();
}

void ItemUseVisitor::visit(WDPot *potion){
	player->alterDef(potion->getMagnitude());
	WDPot::revealPotion();
}
void ItemUseVisitor::visit(Gold *gold){

	int value = gold->getValue();
	int currentGold = player->getGold();
	player->setGold(currentGold+value);
}
