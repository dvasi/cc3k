#include "vampire.h"
#include "enemyinterpreter.h"
using namespace std;

Vampire::Vampire(int x, int y, int id): Enemy(50,25,25,x,y,'V',id, new EnemyInterpreter()){}

Vampire::~Vampire(){}
