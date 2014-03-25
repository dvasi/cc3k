#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "game.h"
#include "playerinterpreter.h"
using namespace std;

int main(int argc, char *argv[]){

	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	curs_set(0);

	Game *cc3k = Game::getInstance();
	cc3k->initializeWorld();
	
	PlayerInterpreter interpreter = PlayerInterpreter();	
	
	printw("NCurses is working!");
	getch();
	cc3k->displayWorld();
	interpreter.interpretCommand();
	endwin();
	
	
	return 0;

}
