#include "troll.h"
#include "enemyinterpreter.h"
using namespace std;

Troll::Troll(int x, int y, int id) :
    Enemy(120, 25, 15, x, y, 'T', id, new EnemyInterpreter()){
}

Troll::~Troll(){
}
