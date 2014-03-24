#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include <iostream>
#include <vector>
#include "cell.h"
class Passage{

	std::vector<std::vector<Cell*> > cell;
	
public:
	void setCells();
	Passage();
	~Passage();
	
};
#endif
