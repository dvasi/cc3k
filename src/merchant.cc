#include "merchant.h"
#include "enemyinterpreter.h"
using namespace std;

Merchant::Merchant(int x, int y, int id): Enemy(30,70,5,x,y,'M',id, new EnemyInterpreter()){}

Merchant::~Merchant(){}
