#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <iostream>
#include <vector>
#include "cell.h"
class Chamber{

	std::vector<std::vector<Cell*> > cells;
	
public:
	void setCells();
	Chamber();
	~Chamber();
	
};
#endif
