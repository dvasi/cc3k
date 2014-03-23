#include <iostream>
#include "gold.h"
using namespace std;

Gold::Gold(int id, int value): Item(id), value(value){}

Gold::~Gold(){}

void Gold::use(){ cout << "Using gold item" << endl;}

int Gold::getValue(){ return value; }

void Gold::setValue(int value) { this->value = value; }
