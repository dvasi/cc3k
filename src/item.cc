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

<<<<<<< HEAD
=======
int Item::getId(){ return id; }

>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
int Item::idCount = 0;
