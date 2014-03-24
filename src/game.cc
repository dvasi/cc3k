#include <cstdlib>
#include <fstream>
#include <iostream>
#include "game.h"
#include "world.h"
#include "fileparser.h"
#include "character.h"
using namespace std;

Game::Game()
{
    worldInstance = World::getInstance();
}

Game::~Game() {}

Game *Game::getInstance()
{

    if (!gameInstance)
    {
        gameInstance = new Game();
        atexit(cleanup);
    }
    return gameInstance;
}

void Game::cleanup()
{

    delete gameInstance;
    gameInstance = NULL;
}

void Game::initializeWorld(string layoutFileName)
{

    FileParser parser = FileParser();
    vector<vector<char> > layout = parser.parseFloorLayout(DEFAULT_LAYOUT_CONFIG_FILE);
    worldInstance->initializeFloors(layout);
    worldInstance->layoutGiven = (layoutFileName == DEFAULT_LAYOUT_CONFIG_FILE) ?
                                 false :
                                 true;

}

void Game::displayWorld()
{

    //OVERLOAD THE PRINT FOR WORLD OR SOMETHING

}

void Game::chooseRace()
{
    cout << "Please choose a race, or any key to begin as a human." << endl;
    cout << "(d)warf" << endl << "(e)lf" << endl << "(o)rc" << endl;
    char c;
    cin >> c;
    Character *player;
    if (c == 'd')
    {
        player = new Character('d');
        cout << "Beginning game as dwarf." << endl;
    }
    else if (c == 'e')
    {
        player = new Character('e');
        cout << "Beginning game as elf." << endl;
    }
    else if (c == 'o')
    {
        player = new Character('o');
        cout << "Beginning game as orc." << endl;
    }
    else
    {
        player = new Character();
        cout << "Begining game as human." << endl;
    }
    player->displayInfo();
}

Game *Game::gameInstance = NULL;
