#include "visitor.h"
#include <iostream>
using namespace std;

Visitor::Visitor(){}

Visitor::~Visitor(){}

void Visitor::visit(Character *ch){}

void Visitor::visit(Potion *potion){}

void Visitor::visit(Gold *gold){}
