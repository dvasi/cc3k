#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include "game.h"
#include "fileparser.h"
#include "human.h"
#include "merchant.h"
#include "floor.h"
using namespace std;

Game::Game(): layoutGiven(false), currentFloor(0), isOver(false),victorious(false){ }

Game::~Game(){
	while (!floors->empty()){
        delete floors->back();
        floors->pop_back();
    }
    delete floors;
}

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
	initializeFloors(layout);
	layoutGiven = (layoutFileName == DEFAULT_LAYOUT_CONFIG_FILE) ?
								 false :
								 true;

}

void Game::displayWorld(){
	displayFloors();
}

void Game::displayWelcomeScreen(){

	
	string continueMsg = "Press any key to continue";
	string authorMsg = "Made by Tyler Sanderson and Steve Weng";
	
	vector<string> titleArt;
	titleArt.push_back(" _____ _                     _               ");
	titleArt.push_back("/  __ \\ |                   | |              ");
	titleArt.push_back("| /  \\/ |__   __ _ _ __ ___ | |__   ___ _ __ ");
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
	for (unsigned int i = 0; i < titleArt.size(); ++i){
		mvprintw(i,(col-strlen(titleArt.at(0).c_str()))/2,"%s",titleArt.at(i).c_str());	
	}
	for (unsigned int i = 0; i < titleArt2.size(); ++i){
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

void Game::displayRaceSelectionScreen(){
	
	string raceSelectMsg = "Press the appropriate key to select your race!";
	string authorMsg = "Made by Tyler Sanderson and Steve Weng";
	
	vector<string> race1;
	race1.push_back("Human");
	race1.push_back("140 HP");
	race1.push_back("20 Atk");
	race1.push_back("20 Def");
	race1.push_back("Score x 1.5");
	race1.push_back("");
	race1.push_back("h");
	
	vector<string> race2;
	race2.push_back("Dwarf");
	race2.push_back("100 HP");
	race2.push_back("20 Atk");
	race2.push_back("30 Def");
	race2.push_back("Gold x 2");
	race2.push_back("");
	race2.push_back("d");
	
	vector<string> race3;
	race3.push_back("Elf");
	race3.push_back("140 HP");
	race3.push_back("30 Atk");
	race3.push_back("10 Def");
	race3.push_back("Pot- = Pot+");
	race3.push_back("");
	race3.push_back("e");
	
	vector<string> race4;
	race4.push_back("Orc");
	race4.push_back("180 HP");
	race4.push_back("30 Atk");
	race4.push_back("25 Def");
	race4.push_back("Gold x 0.5");
	race4.push_back("");
	race4.push_back("o");
	
	vector<vector<string> > races;
	races.push_back(race1);
	races.push_back(race2);
	races.push_back(race3);
	races.push_back(race4);
	
	vector<string> titleArt;
	titleArt.push_back(" _____ _                     _               ");
	titleArt.push_back("/  __ \\ |                   | |              ");
	titleArt.push_back("| /  \\/ |__   __ _ _ __ ___ | |__   ___ _ __ ");
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
	for (unsigned int i = 0; i < titleArt.size(); ++i){
		mvprintw(i,(col-strlen(titleArt.at(0).c_str()))/2,"%s",titleArt.at(i).c_str());	
	}
	for (unsigned int i = 0; i < titleArt2.size(); ++i){
		mvprintw(i+titleArt.size(),(col-strlen(titleArt2.at(0).c_str()))/2,"%s",titleArt2.at(i).c_str());	
	}
	
	
	attron(A_BOLD);
	mvprintw(titleArt.size()+titleArt2.size()+1,(col-raceSelectMsg.length())/2,raceSelectMsg.c_str());
	refresh();
	attroff(A_BOLD);
	
	for (unsigned int i = 0; i < races.size(); ++i){
		for (unsigned int j = 0; j < races.at(i).size(); ++j){
			string current = races.at(i).at(j);
			
			//Decorate each race header properly
			if (current == "Human") attron(COLOR_PAIR(2)); attron(A_BOLD);
			if (current == "Dwarf") attron(COLOR_PAIR(4)); attron(A_BOLD);
			if (current == "Elf") attron(COLOR_PAIR(6)); attron(A_BOLD);
			if (current == "Orc") attron(COLOR_PAIR(5)); attron(A_BOLD);
			
			refresh();
			mvprintw(row/2 + j,(i+1)*((col-strlen(races.at(i).at(0).c_str()))/5),"%s",races.at(i).at(j).c_str());
			
			if (current == "Human") attroff(COLOR_PAIR(2)); attroff(A_BOLD);
			if (current == "Dwarf") attroff(COLOR_PAIR(4)); attroff(A_BOLD);
			if (current == "Elf") attroff(COLOR_PAIR(6)); attroff(A_BOLD);
			if (current == "Orc") attroff(COLOR_PAIR(5)); attroff(A_BOLD);
		}
	}

	
	mvprintw(row-2,(col-authorMsg.length())/2,authorMsg.c_str());
	attroff(COLOR_PAIR(1));
}

void Game::displayEndScreen(){

	clear();

	string scoreMsg = "Your final score is: ";
	ostringstream convert;
	Player *player = Player::getInstance();
	int finalScore = player->getGold();
	convert << finalScore;
	scoreMsg += convert.str();

	string commandMsg = "Press 'r' to restart, 'q' to quit";
	string authorMsg = "Made by Tyler Sanderson and Steve Weng";

	 vector<string> victoryArt;
	 if (victorious){
	 victoryArt.push_back("__      ___      _                   _");
	 victoryArt.push_back("\\ \\    / (_)    | |                 | |");
	 victoryArt.push_back(" \\ \\  / / _  ___| |_ ___  _ __ _   _| |");
	 victoryArt.push_back("  \\ \\/ / | |/ __| __/ _ \\| '__| | | | |");
	 victoryArt.push_back("   \\  /  | | (__| || (_) | |  | |_| |_|");
	 victoryArt.push_back("    \\/   |_|\\___|\\__\\___/|_|   \\__, (_)");
	 victoryArt.push_back("                                __/ |  ");
	 victoryArt.push_back("                               |___/   ");
	}
    //okay so this defeat word is not the same font as victory...and might have to change method name
	else{
	 victoryArt.push_back("________          _____              __   ");
	 victoryArt.push_back("\\______ \\   _____/ ____\\____ _____ _/  |_");
	 victoryArt.push_back(" |    |  \\_/ __ \\   __\\/ __ \\__  \\   __\\ ");
	 victoryArt.push_back(" |    |  \\_/ __ \\   __\\/ __ \\__  \\   __\\ ");
	 victoryArt.push_back(" |    `   \\  ___/|  | \\  ___/ / __ \\|  |  ");
	 victoryArt.push_back("/_______  /\\___  >__|  \\___  >____  /__|  ");
	 victoryArt.push_back("        \\/     \\/          \\/     \\/      ");
	}

	 vector<string> swordArt;
	 swordArt.push_back("          /\\          ");
	 swordArt.push_back("         /  \\         ");
	 swordArt.push_back("        |    |        ");
	 swordArt.push_back("        |    |        ");
	 swordArt.push_back("        |    |        ");
	 swordArt.push_back("        |    |        ");

	 vector<string> swordArt2;
	 swordArt2.push_back("        |    |        ");
	 swordArt2.push_back("        | /\\ |        ");
	 swordArt2.push_back(":\\______|/  \\|______/:");
	 swordArt2.push_back(" \\__________________/");
	 swordArt2.push_back("        | /\\ |        ");
	 swordArt2.push_back("        ||  ||        ");
	 swordArt2.push_back("        ||  ||        ");
	 swordArt2.push_back("        ||  ||        ");
	 swordArt2.push_back("        | \\/ |        ");
	 swordArt2.push_back("        \\____/        ");
	 swordArt2.push_back("        (____)        ");


	int row, col;
	getmaxyx(stdscr,row,col);

	attron(COLOR_PAIR(1));
	for (unsigned int i = 0; i < victoryArt.size(); ++i){
		mvprintw(i,(col-strlen(victoryArt.at(0).c_str()))/2,"%s",victoryArt.at(i).c_str());
	}
	for (unsigned int i = 0; i < swordArt.size(); ++i){
			mvprintw(victoryArt.size()+1+i,(col-strlen(swordArt.at(0).c_str()))/2,"%s",swordArt.at(i).c_str());
	}
	attron(A_BOLD);
	mvprintw(victoryArt.size()+swordArt.size()+1,col/2-strlen(scoreMsg.c_str())/2,"%s",scoreMsg.c_str());
	mvprintw(victoryArt.size()+swordArt.size()+2,col/2-strlen(commandMsg.c_str())/2,"%s",commandMsg.c_str());
	attroff(A_BOLD);
	refresh();
	for (unsigned int i = 0; i < swordArt2.size(); ++i){
		mvprintw(victoryArt.size()+swordArt.size()+3+i,(col-strlen(swordArt2.at(0).c_str()))/2,"%s",swordArt2.at(i).c_str());
	}

	mvprintw(row-2,(col-authorMsg.length())/2,authorMsg.c_str());
	attroff(COLOR_PAIR(1));
}

void Game::setPlayer(Player* player){
	this->player = player;
}

void Game::selectRace(){
	char cmd;
	cmd = getch();
	while  ((cmd != 'h')&&
			(cmd != 'd')&&
			(cmd != 'e')&&
			(cmd != 'o')){
		cmd = getch();
	}	
	//make options available for selecing other races
	setPlayer(new Human(0,0,Character::generateId()));
	clear();	
	return;	
}

void Game::selectEndGameCommand(){
	char cmd;
	cmd = getch();
	while ((cmd != 'r')&&(cmd != 'q')) cmd = getch();
	if (cmd == 'r') {
		restartGame();
	}
	return;
}

void Game::restartGame(){

	clearGame();
	displayRaceSelectionScreen();
	selectRace();
	initializeWorld();
	return;
}

void Game::clearGame(){

	while (!floors->empty()){
		delete floors->back();
		floors->pop_back();
    }
    delete floors;

    victorious = false;
    isOver = false;
    currentFloor = 0;
    Merchant::setAngryMode(false);
    clear();
    return;
}

void Game::initializeFloors(vector<vector<char> > floorLayout){

	floors = new vector<Floor*>();
	for (int i = 0; i < NUM_FLOORS; ++i){
		Floor *floor = new Floor();
		floor->initializeCells(floorLayout);
		floor->initializeChambers(floorLayout);
		floors->push_back(floor);
	}
	int startXPos = floors->at(0)->getStartXPos();
	int startYPos = floors->at(0)->getStartYPos();
	player->setPos(startXPos,startYPos);
	return;
}

void Game::displayFloors(){
	(floors->at(currentFloor))->display();
}

void Game::updateState(){
	(floors->at(currentFloor))->updateState();
}

vector <Floor*>* Game::getFloors() { return floors; }

int Game::getCurrentFloor() { return currentFloor; }

void Game::setCurrentFloor(int floorNum) { 
	currentFloor = floorNum; 
	int startXPos = floors->at(currentFloor)->getStartXPos();
	int startYPos = floors->at(currentFloor)->getStartYPos();
	player->setPos(startXPos,startYPos);	
}

bool Game::gameFinished(){ return isOver; }

void Game::setGameOver(bool victorious){
	isOver = true;
	this->victorious = victorious;
}


Player* Game::getPlayer(){ return player; }

Game* Game::gameInstance = NULL;


/*void Game::displayVictoryScreen(){

	clear();

	string scoreMsg = "Your final score is: ";
	ostringstream convert;
	Player *player = Player::getInstance();
	int finalScore = player->getGold();
	convert << finalScore;
	scoreMsg += convert.str();

	string commandMsg = "Press 'r' to restart, 'q' to quit";
	string authorMsg = "Made by Tyler Sanderson and Steve Weng";

	 vector<string> victoryArt;

	 victoryArt.push_back("__      ___      _                   _");
	 victoryArt.push_back("\\ \\    / (_)    | |                 | |");
	 victoryArt.push_back(" \\ \\  / / _  ___| |_ ___  _ __ _   _| |");
	 victoryArt.push_back("  \\ \\/ / | |/ __| __/ _ \\| '__| | | | |");
	 victoryArt.push_back("   \\  /  | | (__| || (_) | |  | |_| |_|");
	 victoryArt.push_back("    \\/   |_|\\___|\\__\\___/|_|   \\__, (_)");
	 victoryArt.push_back("                                __/ |  ");
	 victoryArt.push_back("                               |___/   ");
	

	 vector<string> swordArt;
	 swordArt.push_back("          /\\          ");
	 swordArt.push_back("         /  \\         ");
	 swordArt.push_back("        |    |        ");
	 swordArt.push_back("        |    |        ");
	 swordArt.push_back("        |    |        ");
	 swordArt.push_back("        |    |        ");

	 vector<string> swordArt2;
	 swordArt2.push_back("        |    |        ");
	 swordArt2.push_back("        | /\\ |        ");
	 swordArt2.push_back(":\\______|/  \\|______/:");
	 swordArt2.push_back(" \\__________________/");
	 swordArt2.push_back("        | /\\ |        ");
	 swordArt2.push_back("        ||  ||        ");
	 swordArt2.push_back("        ||  ||        ");
	 swordArt2.push_back("        ||  ||        ");
	 swordArt2.push_back("        | \\/ |        ");
	 swordArt2.push_back("        \\____/        ");
	 swordArt2.push_back("        (____)        ");


	int row, col;
	getmaxyx(stdscr,row,col);

	attron(COLOR_PAIR(1));
	for (unsigned int i = 0; i < victoryArt.size(); ++i){
		mvprintw(i,(col-strlen(victoryArt.at(0).c_str()))/2,"%s",victoryArt.at(i).c_str());
	}
	for (unsigned int i = 0; i < swordArt.size(); ++i){
			mvprintw(victoryArt.size()+1+i,(col-strlen(swordArt.at(0).c_str()))/2,"%s",swordArt.at(i).c_str());
	}
	attron(A_BOLD);
	mvprintw(victoryArt.size()+swordArt.size()+1,col/2-strlen(scoreMsg.c_str())/2,"%s",scoreMsg.c_str());
	mvprintw(victoryArt.size()+swordArt.size()+2,col/2-strlen(commandMsg.c_str())/2,"%s",commandMsg.c_str());
	attroff(A_BOLD);
	refresh();
	for (unsigned int i = 0; i < swordArt2.size(); ++i){
		mvprintw(victoryArt.size()+swordArt.size()+3+i,(col-strlen(swordArt2.at(0).c_str()))/2,"%s",swordArt2.at(i).c_str());
	}

	mvprintw(row-2,(col-authorMsg.length())/2,authorMsg.c_str());
	attroff(COLOR_PAIR(1));
}
*/
