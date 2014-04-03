#include <cstdlib>
#include <string>
#include "player.h"
#include "playerinterpreter.h"
using namespace std;

Player::Player(int hp, int atk, int def, int x, int y, char race, int id) :
    Character(hp, atk, def, x, y, id), gold(0), race(race){
    input = new PlayerInterpreter();
    playerInstance = this;
    atexit(cleanup);
}

Player::~Player(){
    delete input;
}

//Assumes a player is only explicitly created once during race selection
Player* Player::getInstance(){
    return playerInstance;
}

void Player::cleanup(){
    delete playerInstance;
    playerInstance = NULL;
}

void Player::update(){
    input->interpretCommand(this);
}

char Player::getSymbol(){
    return race;
}

double Player::getGold(){
    return gold;
}

void Player::setGold(double gold){
    this->gold = gold;
}

char Player::getRace(){
    return race;
}

string Player::charToRace(char ch){
    if (ch == 'h'){
        return "Human";
    }
    if (ch == 'd'){
        return "Dwarf";
    }
    if (ch == 'e'){
        return "Elf";
    }
    if (ch == 'o'){
        return "Orc";
    }
    return "Human";
}

Player* Player::playerInstance = NULL;
