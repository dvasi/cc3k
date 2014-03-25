#include <cstdlib>
#include "player.h"
using namespace std;

Player::Player(int hp, int atk, int def, int x, int y, char race, int id): Character(hp,atk,def,x,y,id), gold(0), race(race) { 
	playerInstance = this;
	atexit(cleanup); 
}

Player::~Player(){}

//Assumes a player is only explicitly created once during race selection
Player* Player::getInstance() { return playerInstance; }

void Player::cleanup(){
	delete playerInstance;
	playerInstance = NULL;
}

Player* Player::playerInstance = NULL;
