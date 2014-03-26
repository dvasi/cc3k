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

    printf("The following block is a test of spawning enemies (in the amount of 20, per floor)");
    Floor *f = new Floor();
    f->generateEnemies();
    for (int i = 0; i < 20; ++i)
    {
        printf("The hp of this enemy is: %d \n", f->spawnedEnemies[i]->getHp());
    }
    return 0;
}
