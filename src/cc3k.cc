#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "enemy.h"
#include "playerinterpreter.h"
#include "floor.h"
using namespace std;

int main(int argc, char *argv[])
{

    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    srand(time(0));

	
    Game *cc3k = Game::getInstance();
    cc3k->displayWelcomeScreen();
    cc3k->displayRaceSelectionScreen();
    cc3k->selectRace();
    Player *player = Player::getInstance();
    cc3k->initializeWorld();
    cc3k->displayWorld();
    
    while (true){
		player->update();
		if (cc3k->gameFinished()){
			cc3k->restartGame();
			player = Player::getInstance();
			cc3k->displayWorld();
		}
		else{
			cc3k->updateState();
			if (cc3k->gameFinished()){
				cc3k->displayEndScreen();
				cc3k->selectEndGameCommand();

				player = Player::getInstance();
				cc3k->displayWorld();
			}
			else cc3k->displayWorld();
		}
	}
	
    endwin();
    return 0;
}
