#include "visitor.h"
#include "character.h"
#include "enemy.h"
#include "merchant.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "rhpot.h"
#include "wapot.h"
#include "wdpot.h"
#include "gold.h"
#include <iostream>
using namespace std;

Visitor::Visitor(){
}

Visitor::~Visitor(){
}

int Visitor::visit(Character *ch){
    return 0;
}

int Visitor::visit(Enemy* enemy){
    return 0;
}

int Visitor::visit(Merchant *merchant){
    return 0;
}

int Visitor::visit(Dragon* dragon){
    return 0;
}

void Visitor::visit(BAPot* potion){
}

void Visitor::visit(BDPot* potion){
}

void Visitor::visit(PHPot* potion){
}

void Visitor::visit(RHPot* potion){
}

void Visitor::visit(WAPot* potion){
}

void Visitor::visit(WDPot* potion){
}

void Visitor::visit(Gold *gold){
}
