#include "werewolf.h"
#include "enemyinterpreter.h"
using namespace std;

Werewolf::Werewolf(int x, int y, int id): Enemy(120,30,5,x,y,'W',id, new EnemyInterpreter()){}

Werewolf::~Werewolf(){}
