#include <iostream>
#include <vector>
#include "floor.h"
#include "world.h"
#include "cell.h"
#include "fileparser.h"
#include <cstdlib>

using namespace std;

Floor::Floor(): dragons(0) {}

Floor::~Floor()
{

    for (unsigned int i = 0; i < allCells.size(); ++i)
    {
        while (!allCells.at(i).empty())
        {
            delete allCells.at(i).back();
            allCells.at(i).pop_back();
        }
    }

}

void Floor::initializeChambers()
{
    //TODO
}

void Floor::initializePassages()
{
    //TODO
}

void Floor::initializeCells(vector<vector<char> > floorLayout)
{

    FileParser parser = FileParser();

    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        vector<Cell *> row;
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            int cellType = parser.charToCellType((floorLayout.at(i)).at(j));
            row.push_back(new Cell(i, j, cellType));
        }
        allCells.push_back(row);
    }

    initializeChambers();
    initializePassages();

    //For debugging
    for (int i = 0; i < BOARD_HEIGHT; ++i)
    {
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            cout << floorLayout.at(i).at(j);
        }
        cout << endl;
    }
}

void Floor::generateEnemies()
{
    int random;
    for (int i = 0; i < dragons; ++i) //set number of dragons first, determined by number of dragon hoards
    {
        enemy[i] = dragons;
    }

    random = rand() % 18 + 1; //random number between 1 and 18

    for (int i = dragons; i < numEnemies; ++i)
    {
        if (random >= 1 && random <= 4) // 2/9 chance of being werewolf
        {
            enemy[i] = 'w';
        }
        else if (random >= 5 && random <= 7) // 3/18 chance of being vampire
        {
            enemy[i] = 'v';
        }
        else if (random >= 8 && random <= 12) // 5/18 of being goblin
        {
            enemy[i] = 'g';
        }
        else if (random >= 13 && random <= 14) // 1/18 troll
        {
            enemy[i] = 't';
        }
        else if (random >= 15 && random <= 16) // 1/18 phoenix
        {
            enemy[i] = 'p';
        }
        else // 1/18 merchant
        {
            enemy[i] = 'm';
        }

    }
}

void Floor::generateGoldPiles() //randomly generate the 10 gold piles
{
    int random;
    for (int i = 0; i < numGoldPiles; ++i)
    {
        random = rand() % 8 + 1; //random number between 1 and 8
        if (random == 1) // 1/8 chance of dragon hoard
        {
            goldPiles[i] = 'd';
            dragons++;
        }
        else if (random > 1 && random <= 6) // 5/8 chance of normal hoard
        {
            goldPiles[i] = 'n';
        }
        else // 2/8 chance of small hoard
        {
            goldPiles[i] = 's';
        }
    }

}