#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <iostream>
#include <vector>
#include "cell.h"
class Chamber{

<<<<<<< HEAD
	std::vector<std::vector<Cell*> > cells;
	
public:
	void setCells();
	Chamber();
=======
	//Only need a 1d vector for chamber cells
	//Mainly used for random object generation
	std::vector<Cell*> cells;
	
public:
	Chamber(std::vector<Cell*> cells);
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
	~Chamber();
	
};
#endif
