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

    //FROM HERE TO RETURN CAN BE COMMENTED OUT, ALL TESTING
    printf("The following block is a test of spawning enemies/gold (in the amount of 20/10, per floor)");
    Floor *f = new Floor();
    f->generateGoldPiles(); //gold piles must be generated before enemies to determine number of dragons
    f->generateEnemies();
    for (int i = 0; i < 20; ++i)
    {
        printf("The following monster is: %c \n", f->enemy[i]);
        printf("It has hp: %d \n", f->spawnedEnemies[i]->getHp());
    }
    for (int i = 0; i < 10; ++i)
    {
        //cout << f->goldPiles[i] << endl;
        printf("The following gold pile is of size: %c \n", f->goldPiles[i]);
    }
    return 0;
}
