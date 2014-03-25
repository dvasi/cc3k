#include <cstdlib>
#include <iostream>
#include "game.h"
#include "enemy.h"
using namespace std;

int main(int argc, char *argv[])
{

    //Game *cc3k = Game::getInstance();
    //cc3k->initializeWorld();
    //cc3k->chooseRace();
    //cc3k->displayWorld();
    Enemy *vam=new Enemy('v');
    cout << vam->getHp() << endl;
    return 0;
}
