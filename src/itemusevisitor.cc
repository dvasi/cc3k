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
}

void ItemUseVisitor::visit(BDPot *potion){
	player->alterDef(potion->getMagnitude());
}

void ItemUseVisitor::visit(PHPot *potion){
	player->alterHp(potion->getMagnitude());
}

void ItemUseVisitor::visit(RHPot *potion){
	player->alterHp(potion->getMagnitude());
}

void ItemUseVisitor::visit(WAPot *potion){
	player->alterAtk(potion->getMagnitude());
}

void ItemUseVisitor::visit(WDPot *potion){
	player->alterDef(potion->getMagnitude());
}
void ItemUseVisitor::visit(Gold *gold){

	int value = gold->getValue();
	int currentGold = player->getGold();
	player->setGold(currentGold+value);
}
