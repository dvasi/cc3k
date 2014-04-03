#include "dragoninterpreter.h"
#include "enemy.h"
#include "player.h"
#include "dragon.h"
#include <cmath>
using namespace std;

DragonInterpreter::DragonInterpreter() :
    EnemyInterpreter(){
}

DragonInterpreter::~DragonInterpreter(){
}

bool DragonInterpreter::playerInRange(Enemy* enemy){
    //Yeah yeah static casting is bad here I know. But #YOLO.
    //Only dragons should use dragon interpreter anyway.
    Dragon *dragon = static_cast<Dragon*>(enemy);

    Player *player = Player::getInstance();
    int playerXPos = player->getXPos();
    int playerYPos = player->getYPos();
    int enemyXPos = dragon->getXPos();
    int enemyYPos = dragon->getYPos();
    int hoardXPos = dragon->getHoardXPos();
    int hoardYPos = dragon->getHoardYPos();

    //Player is within attacking vicinity and adjacent to the gold hoard
    if (((abs(playerXPos - enemyXPos) <= 1) && (abs(playerYPos - enemyYPos) <= 1)) && ((abs(playerXPos - hoardXPos) <= 1) && (abs(playerYPos - hoardYPos) <= 1))) return true;
    return false;
}
