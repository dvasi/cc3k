#include <iostream>
#include <vector>
#include "chamber.h"
using namespace std;

class Cell;

Chamber::Chamber(vector<Cell*> cells): cells(cells){}

Chamber::~Chamber(){}
