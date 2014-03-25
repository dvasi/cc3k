#include <ncurses.h>
#include <map>
#include <string>
#include "playerinterpreter.h"
#include "human.h"
#include "game.h"
using namespace std;

map<string,char> buildCommandMap(){

	//Default commands for Player
	map<string,char> cmdMap;
	cmdMap["moveup"] = '8';
	cmdMap["moveDown"] = '5';
	cmdMap["moveLeft"] = '4';
	cmdMap["moveRight"] = '6';
	cmdMap["moveUpLeft"] = '7';
	cmdMap["moveUpRight"] = '9';
	cmdMap["moveDownLeft"] = '1';
	cmdMap["moveDownRight"] = '3';
	cmdMap["use"] = 'u';
	cmdMap["attack"] = 'a';
	cmdMap["chooseHuman"] = 'h';
	cmdMap["chooseElf"] = 'e';
	cmdMap["chooseDwarf"] = 'd';
	cmdMap["chooseOrc"] = 'o';
	cmdMap["restart"] = 'r';
	cmdMap["quit"] = 'q';
	return cmdMap;
}

PlayerInterpreter::~PlayerInterpreter(){}

PlayerInterpreter::PlayerInterpreter(Game* game):
	CommandInterpreter(buildCommandMap()), raceSelected(false), game(game){}

void PlayerInterpreter::interpretCommand(){
	
	char cmd;
	cmd = getch();
	if (!raceSelected){
		while ((cmd != 'h')&&(cmd != 'd')&&(cmd != 'e')&&(cmd != 'o')){
			cmd = getch();
		}
		raceSelected = true;
		setPlayer(new Human(0,0,Character::generateId()));	
		game->setPlayer(player);
		clear();	
	}
}	

void PlayerInterpreter::setPlayer(Player* player) { this->player = player; }

Player* PlayerInterpreter::getPlayer() { return player; }

