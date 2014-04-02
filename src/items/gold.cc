#include <iostream>
#include "gold.h"
#include "visitor.h"
using namespace std;

Gold::Gold(int id, double value, bool lootable): Item(id,lootable,false), value(value){}

Gold::~Gold(){}

double Gold::getValue(){ return value; }

void Gold::setValue(int value) { this->value = value; }

void Gold::accept(Visitor &v) { v.visit(this); }