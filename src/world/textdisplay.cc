#include <vector>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <string>
#include "textdisplay.h"
#include "player.h"
#include "game.h"
using namespace std;

TextDisplay::TextDisplay(int width, int height) :
    actionStr("Player character has spawned."){
    for (int i = 0; i < height; ++i){
        vector<char> row;
        for (int j = 0; j < width; ++j){
            row.push_back(' ');
        }
        gameDisplay.push_back(row);
    }
}

void TextDisplay::notify(int xPos, int yPos, char symbol){
    gameDisplay.at(xPos).at(yPos) = symbol;
}

void TextDisplay::notify(std::string gameAction){
    actionStr += gameAction;
}

void TextDisplay::resetGameActions(){
    actionStr = "";
}

ostream &operator<<(ostream &out, const TextDisplay &td){
    refresh();

    for (unsigned int i = 0; i < td.gameDisplay.size(); ++i){
        for (unsigned int j = 0; j < td.gameDisplay.at(i).size(); ++j){
            char current = td.gameDisplay.at(i).at(j);

            //Bold all important game objects
            if ((current >= 64) && (current <= 90))
            attron(A_BOLD);

            //Color our character blue
            if (current == '@')
            attron(COLOR_PAIR(2));

            //Color gold piles yellow
            if (current == 'G')
            attron(COLOR_PAIR(3));

            //Color potions red
            if (current == 'P')
            attron(COLOR_PAIR(4));

            //Color dragons green
            if (current == 'D')
            attron(COLOR_PAIR(5));

            //Color merchants magenta
            if (current == 'M')
            attron(COLOR_PAIR(6));

            //Make staircases stand out more
            if (current == '/')
            attron(A_STANDOUT);

            //Draw character and refresh to see added attributes
            mvaddch(i, j, current);
            refresh();

            if (current == '@')
            attroff(COLOR_PAIR(2));

            if (current == 'G')
            attroff(COLOR_PAIR(3));

            if (current == 'P')
            attroff(COLOR_PAIR(4));

            if (current == 'D')
            attroff(COLOR_PAIR(5));

            if (current == 'M')
            attroff(COLOR_PAIR(6));

            if (current == '/')
            attroff(A_STANDOUT);

            if (((current >= 64) && (current <= 90)) || (current == 47))
            attroff(A_BOLD);
        }
    }

    Player *player = Player::getInstance();
    Game *game = Game::getInstance();
    ostringstream convert;

    string race = Player::charToRace(player->getSymbol());
    double gold = player->getGold();
    int hp = player->getHp();
    if (hp < 0) hp = 0; //as to not display negative hp
    int atk = player->getAtk();
    int def = player->getDef();
    int floorNum = game->getCurrentFloor() + 1;

    string raceStr = "Race: " + race;
    string goldStr = "Gold: ";
    convert << gold;
    goldStr += convert.str();
    convert.str("");
    convert.clear();
    string hpStr = "HP: ";
    convert << hp;
    hpStr += convert.str();
    convert.str("");
    convert.clear();
    string atkStr = "Atk: ";
    convert << atk;
    atkStr += convert.str();
    convert.str("");
    convert.clear();
    string defStr = "Def: ";
    convert << def;
    defStr += convert.str();
    convert.str("");
    convert.clear();
    string turnActions = "Actions: " + td.actionStr;
    string floorStr = "Floor ";
    convert << floorNum;
    floorStr += convert.str();
    convert.str("");
    convert.clear();

    move(BOARD_HEIGHT, 0);
    clrtoeol();
    mvprintw(BOARD_HEIGHT, 0, "%s", raceStr.c_str());

    mvprintw(BOARD_HEIGHT, raceStr.length() + 1, "%s", goldStr.c_str());
    mvprintw(BOARD_HEIGHT, BOARD_WIDTH - floorStr.length() - 1, "%s", floorStr.c_str());

    move(BOARD_HEIGHT + 1, 0);
    clrtoeol();
    mvprintw(BOARD_HEIGHT + 1, 0, "%s", hpStr.c_str());

    move(BOARD_HEIGHT + 2, 0);
    clrtoeol();
    mvprintw(BOARD_HEIGHT + 2, 0, "%s", atkStr.c_str());

    move(BOARD_HEIGHT + 3, 0);
    clrtoeol();
    mvprintw(BOARD_HEIGHT + 3, 0, "%s", defStr.c_str());

    move(BOARD_HEIGHT + 4, 0);
    clrtoeol();
    mvprintw(BOARD_HEIGHT + 4, 0, "%s", turnActions.c_str());
    return out;
}
