#include "visitor.h"
#include "character.h"
#include "potion.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "rhpot.h"
#include "wapot.h"
#include "wdpot.h"
#include "gold.h"
#include <iostream>
using namespace std;

Visitor::Visitor(){}

Visitor::~Visitor(){}

int Visitor::visit(Character *ch){ return 0; }

void Visitor::visit(Potion *potion){}

void Visitor::visit(BAPot* potion){}

void Visitor::visit(BDPot* potion){}

void Visitor::visit(PHPot* potion){}

void Visitor::visit(RHPot* potion){}

void Visitor::visit(WAPot* potion){}

void Visitor::visit(WDPot* potion){cout<<"VISITING";}

void Visitor::visit(Gold *gold){}
