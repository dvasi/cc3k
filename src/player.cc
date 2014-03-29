#include <cstdlib>
#include <iostream>
#include "player.h"
using namespace std;

Player::Player(int hp, int atk, int def, int x, int y, char race, int id): Character(hp,atk,def,x,y,id), gold(0), race(race) { 
	playerInstance = this;
	input = new PlayerInterpreter();
	atexit(cleanup); 
}

Player::~Player(){ delete input; }

//Assumes a player is only explicitly created once during race selection
Player* Player::getInstance() { return playerInstance; }

void Player::cleanup(){
	delete playerInstance;
	playerInstance = NULL;
}

void Player::update(){
	input->interpretCommand(this);
}

char Player::getSymbol(){ return race; }

int Player::getGold(){ return gold; }

void Player::setGold(int gold) { this->gold = gold; }

Player* Player::playerInstance = NULL;
