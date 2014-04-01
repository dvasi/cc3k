#include "itemusevisitor.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "rhpot.h"
#include "wapot.h"
#include "wdpot.h"
#include "gold.h"
#include "player.h"
#include "stdlib.h"

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
    if (player->race == 'e'){
        player->alterHp(abs(potion->getMagnitude()));
    }
    else{
        player->alterHp(potion->getMagnitude());
    }
	PHPot::revealPotion();
}

void ItemUseVisitor::visit(RHPot *potion){
	player->alterHp(potion->getMagnitude());
	RHPot::revealPotion();
}

void ItemUseVisitor::visit(WAPot *potion){
    if (player->race == 'e')
    {
        player->alterAtk(abs(potion->getMagnitude()));
    }
    else
    {
        player->alterAtk(potion->getMagnitude());
    }
    WAPot::revealPotion();
}

void ItemUseVisitor::visit(WDPot *potion)
{
    if (player->race == 'e')
    {
        player->alterDef(abs(potion->getMagnitude()));
    }
    else
    {
        player->alterDef(potion->getMagnitude());
    }
    WDPot::revealPotion();
}

void ItemUseVisitor::visit(Gold *gold){
    int value = gold->getValue();
    if (player->race == 'd')
    {
        value = value * 2;
    }
    if (player->race == 'o')
    {
        value = value / 2;
    }
    int currentGold = player->getGold();
    player->setGold(currentGold + value);
}
