#include "phoenix.h"
#include "enemyinterpreter.h"
using namespace std;

Phoenix::Phoenix(int x, int y, int id): Enemy(50,35,20,x,y,'X',id, new EnemyInterpreter()){}

Phoenix::~Phoenix(){}
