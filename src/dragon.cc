#include "dragon.h"
#include "enemyinterpreter.h"
using namespace std;

Dragon::Dragon(int x, int y, int id): Enemy(150,20,20,x,y,'D',id, new EnemyInterpreter()){}

Dragon::~Dragon(){}
