#include <cstdlib>
#include <iostream>
#include "game.h"
using namespace std;

int main(int argc, char *argv[]){

	Game *cc3k = Game::getInstance();
	cc3k->chooseRace();
	//cc3k->initializeWorld();
	cc3k->displayWorld();
	return 0;

}
