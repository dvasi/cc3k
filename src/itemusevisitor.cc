#include "itemusevisitor.h"
#include "potion.h"
#include "gold.h"
#include "player.h"

ItemUseVisitor::ItemUseVisitor(){ player = Player::getInstance(); }

ItemUseVisitor::~ItemUseVisitor(){}

void ItemUseVisitor::visit(Potion *potion){

	//Hard code for HP boost for now
	player->alterHp(10);
}

void ItemUseVisitor::visit(Gold *gold){

	int value = gold->getValue();
	int currentGold = player->getGold();
	player->setGold(currentGold+value);
}
		
