#include "visitor.h"
#include <iostream>
using namespace std;

Visitor::Visitor(){}

Visitor::~Visitor(){}

int Visitor::visit(Character *ch){ return 0; }

void Visitor::visit(Potion *potion){}

void Visitor::visit(Gold *gold){}
