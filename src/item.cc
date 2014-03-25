#include <iostream>
#include "item.h"
using namespace std;

Item::Item(int id): id(id) {}

Item::~Item() {}

void Item::use(){ cout << "Using item " << endl; } 

int Item::generateId(){
	idCount++;
	return idCount;
}


int Item::getId(){ return id; }

int Item::idCount = 0;
