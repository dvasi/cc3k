#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <vector>
#include "game.h"
#include "world.h"
#include "fileparser.h"
#include "character.h"
using namespace std;

Game::Game(){
	worldInstance = World::getInstance();
}

Game::~Game(){}

Game* Game::getInstance(){

	if (!gameInstance){
		gameInstance = new Game();
		atexit(cleanup);
	}
	return gameInstance;
}

void Game::cleanup(){

	delete gameInstance;
	gameInstance = NULL;
}

void Game::initializeWorld(string layoutFileName){

	FileParser parser = FileParser();
	vector<vector<char> > layout = parser.parseFloorLayout("testLayout.txt");
	worldInstance->initializeFloors(layout);
	worldInstance->layoutGiven = (layoutFileName == DEFAULT_LAYOUT_CONFIG_FILE) ?
								 false :
								 true;

}

void Game::displayWorld(){

	//OVERLOAD THE PRINT FOR WORLD OR SOMETHING
	worldInstance->displayFloors();

}

void Game::displayWelcomeScreen(){

	
	string continueMsg = "Press any key to continue";
	string authorMsg = "Made by Tyler Sanderson and Steve Weng";
	
	vector<string> titleArt;
	titleArt.push_back(" _____ _                     _               ");
	titleArt.push_back("/  __ \\ |                   | |              ");
	titleArt.push_back("| \/  \\/ |__   __ _ _ __ ___ | |__   ___ _ __ ");
	titleArt.push_back("| |   | '_ \\ / _` | '_ ` _ \\| '_ \\ / _ \\ '__|");
	titleArt.push_back("| \\__/\\ | | | (_| | | | | | | |_) |  __/ |   ");
	titleArt.push_back(" \\____/_| |_|\\__,_|_| |_| |_|_.__/ \\___|_|   ");
	
	vector<string> titleArt2;
	titleArt2.push_back(" _____                    _             _____ _    ");
	titleArt2.push_back("/  __ \\                  | |           |____ | |   ");
	titleArt2.push_back("| /  \\/_ __ __ ___      _| | ___ _ __      / / | __");
	titleArt2.push_back("| |   | '__/ _` \\ \\ /\\ / / |/ _ \\ '__|     \\ \\ |/ /");
	titleArt2.push_back("| \\__/\\ | | (_| |\\ V  V /| |  __/ |    .___/ /   < ");
	titleArt2.push_back(" \\____/_|  \\__,_| \\_/\\_/ |_|\\___|_|    \\____/|_|\\_\\");

	
	int row, col;
	getmaxyx(stdscr,row,col);
	
	attron(COLOR_PAIR(1));
	for (int i = 0; i < titleArt.size(); ++i){
		mvprintw(i,(col-strlen(titleArt.at(0).c_str()))/2,"%s",titleArt.at(i).c_str());	
	}
	for (int i = 0; i < titleArt2.size(); ++i){
		mvprintw(i+titleArt.size(),(col-strlen(titleArt2.at(0).c_str()))/2,"%s",titleArt2.at(i).c_str());	
	}
	attron(A_BOLD);
	mvprintw(row/2,(col-continueMsg.length())/2,continueMsg.c_str());
	refresh();
	attroff(A_BOLD);
	mvprintw(row-2,(col-authorMsg.length())/2,authorMsg.c_str());
	attroff(COLOR_PAIR(1));
	getch();
	clear();
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

Game* Game::gameInstance = NULL;
