#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <iostream>
#include <vector>
#
class Cell;

class Chamber{


	//Only need a 1d vector for chamber cells
	//Mainly used for random object generation
	std::vector<Cell*> cells;
	
public:
	Chamber(std::vector<Cell*> cells);
	~Chamber();
	
};
#endif
