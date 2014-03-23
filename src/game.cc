#include <cstdlib>
#include <fstream>
#include <iostream>
#include "game.h"
#include "world.h"
#include "fileparser.h"
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

Game* Game::gameInstance = NULL;
