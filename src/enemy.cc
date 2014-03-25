#include "enemy.h"
using namespace std;


int Enemy::takeDamage(int playerAtk){
return ceil((100/(100+currentDef))*playerAtk);
}