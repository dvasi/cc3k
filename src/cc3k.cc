#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "enemy.h"
#include "playerinterpreter.h"
using namespace std;

int main(int argc, char *argv[]){

	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_WHITE,COLOR_BLACK);
	init_pair(2, COLOR_BLUE,COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED,COLOR_BLACK);
	init_pair(5, COLOR_GREEN,COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);

	Game *cc3k = Game::getInstance();
	PlayerInterpreter interpreter = PlayerInterpreter();
	cc3k->initializeWorld();	
	cc3k->displayWelcomeScreen();
	cc3k->displayRaceSelectionScreen();
	interpreter.interpretCommand();
	cc3k->displayWorld();
	getch();
	endwin();
	
	
	return 0;
}
