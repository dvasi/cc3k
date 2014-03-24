#include <iostream>
#include <vector>
#include "chamber.h"
#include "cell.h"
using namespace std; 

Chamber::Chamber(vector<Cell*> cells): cells(cells){}

Chamber::~Chamber(){}
