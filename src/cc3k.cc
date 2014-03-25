#include <cstdlib>
#include <iostream>
#include "game.h"
using namespace std;

<<<<<<< HEAD
int main(int argc, char *argv[])
{

    Game *cc3k = Game::getInstance();
    cc3k->initializeWorld();
    cc3k->chooseRace();
    cc3k->displayWorld();
    return 0;
=======
int main(int argc, char *argv[]){

	Game *cc3k = Game::getInstance();
	cc3k->initializeWorld();
	cc3k->displayWorld();
	return 0;
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb

}
