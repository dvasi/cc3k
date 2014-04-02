#include "goblin.h"
#include "enemyinterpreter.h"
using namespace std;

Goblin::Goblin(int x, int y, int id) :
    Enemy(70, 5, 10, x, y, 'N', id, new EnemyInterpreter()){
}

Goblin::~Goblin(){
}
