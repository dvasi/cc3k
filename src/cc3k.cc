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

    /*    initscr();
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

        Game *cc3k = Game::getInstance();


        PlayerInterpreter interpreter = PlayerInterpreter(cc3k);
        cout << "INTERPRETER MADE" << endl;
        cc3k->displayWelcomeScreen();
        cc3k->displayRaceSelectionScreen();
        interpreter.interpretCommand();
        cc3k->initializeWorld();
        cout << "WORLD INITIALIZED" << endl;
        cc3k->displayWorld();
        getch();
        endwin();
    */

     //Game *cc3k = Game::getInstance();
     //cc3k->initializeWorld();
     //cc3k->displayWorld();
        Floor *f = new Floor();
        f->generateEnemies();
          for (int i = 0; i < 10; ++i)
     {
         cout << f->enemy[i] << endl;
     }
    return 0;
}
