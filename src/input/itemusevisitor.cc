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

ItemUseVisitor::ItemUseVisitor(): tempAtkDelta(0),tempDefDelta(0){ player = Player::getInstance(); }

ItemUseVisitor::~ItemUseVisitor(){}

void ItemUseVisitor::visit(BAPot *potion){
	int magnitude = potion->getMagnitude();
	player->alterAtk(magnitude);
	tempAtkDelta += magnitude;
	BAPot::revealPotion();
}

void ItemUseVisitor::visit(BDPot *potion){
	int magnitude = potion->getMagnitude();
	player->alterDef(magnitude);
	tempDefDelta += magnitude;
	BDPot::revealPotion();
}

void ItemUseVisitor::visit(PHPot *potion){
	int magnitude = potion->getMagnitude();
    if (player->getRace() == 'e'){
        player->alterHp(abs(magnitude));
    }
    else{
        player->alterHp(magnitude);
    }
	PHPot::revealPotion();
}

void ItemUseVisitor::visit(RHPot *potion){
	int magnitude = potion->getMagnitude();
	player->alterHp(magnitude);
	RHPot::revealPotion();
}

void ItemUseVisitor::visit(WAPot *potion){
	int magnitude = potion->getMagnitude();
    if (player->getRace() == 'e'){
        player->alterAtk(abs(magnitude));
        tempAtkDelta += abs(magnitude);
    }
    else{
        player->alterAtk(magnitude);
        tempAtkDelta += magnitude;
    }
    WAPot::revealPotion();
}

void ItemUseVisitor::visit(WDPot *potion){
	int magnitude = potion->getMagnitude();
    if (player->getRace() == 'e'){
        player->alterDef(abs(magnitude));
        tempDefDelta += abs(magnitude);
    }
    else{
        player->alterDef(magnitude);
        tempDefDelta += magnitude;
    }
    WDPot::revealPotion();
}

void ItemUseVisitor::visit(Gold *gold){
    double value = gold->getValue();
    if (player->getRace() == 'd')
    {
        value = value * 2;
    }
    if (player->getRace() == 'o')
    {
        value = value / 2;
    }
    double currentGold = player->getGold();
    player->setGold(currentGold + value);
}

int ItemUseVisitor::getTempAtkDelta(){ return tempAtkDelta; }

int ItemUseVisitor::getTempDefDelta(){ return tempDefDelta; }
