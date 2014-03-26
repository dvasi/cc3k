#include <ncurses.h>
#include <map>
#include <string>
#include <cmath>
#include "playerinterpreter.h"
#include "human.h"
#include "game.h"
#include "movecommand.h"
#include "textdisplay.h"
using namespace std;

map<string,char> buildCommandMap(){

	//Default commands for Player
	map<string,char> cmdMap;
	cmdMap["moveUp"] = '8';
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
		while  ((cmd != commandMap["chooseHuman"])&&
				(cmd != commandMap["chooseDwarf"])&&
				(cmd != commandMap["chooseElf"])&&
				(cmd != commandMap["chooseOrc"])){
			cmd = getch();
		}
		raceSelected = true;
		setPlayer(new Human(0,0,Character::generateId()));	
		game->setPlayer(player);
		clear();	
		return;
	}
	
	if (cmd == commandMap["moveUp"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos()-1, player->getYPos());
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	if (cmd == commandMap["moveDown"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos()+1, player->getYPos());
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	if (cmd == commandMap["moveLeft"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos(), player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	if (cmd == commandMap["moveRight"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos(), player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	if (cmd == commandMap["moveUpLeft"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos()-1, player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	if (cmd == commandMap["moveUpRight"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos()-1, player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	if (cmd == commandMap["moveDownLeft"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos()+1, player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	if (cmd == commandMap["moveDownRight"]){
		MoveCommand* playerMove = new MoveCommand(player, player->getXPos()+1, player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
	}
	
}	

void PlayerInterpreter::setPlayer(Player* player) { this->player = player; }

Player* PlayerInterpreter::getPlayer() { return player; }

void PlayerInterpreter::movePlayer(MoveCommand* cmd){

	Character *ch = cmd->getCharacter();
	int currentX = ch->getXPos();
	int currentY = ch->getYPos();
	int newX = cmd->getXPos();
	int newY = cmd->getYPos();
	Floor* currentFloor = game->getFloors().at(game->getCurrentFloor());
	Cell* currentCell = currentFloor->getCellAt(currentX,currentY);
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	TextDisplay *td = currentFloor->getTextDisplay();
	
	ch->setPos(newX,newY);
	
	//Set up our new cell
	if ((newCell->hasItem())&&(newCell->symbolToDisplayChar(newCell->getCellSymbol()) == 'G')){
		//Add gold to player TODO
		currentFloor->removeItem(newCell->getOccupiedId());			
	}
	newCell->setOccupation(false,false,true,ch->getId());
	newCell->setCellSymbol('@');	
	
	//Change our old one
	currentCell->setOccupation(false,false,false);
	currentCell->setCellSymbol(currentCell->typeToDisplayChar(currentCell->getCellType()));
	
	//Notify our display
	currentCell->notifyDisplay(*td);
	newCell->notifyDisplay(*td);
}

bool PlayerInterpreter::isMoveValid(MoveCommand* cmd){

	Character *ch = cmd->getCharacter();
	int currentX = ch->getXPos();
	int currentY = ch->getYPos();
	int newX = cmd->getXPos();
	int newY = cmd->getYPos();
	Floor* currentFloor = game->getFloors().at(game->getCurrentFloor());
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	
	if ((abs(currentX-newX) <=1)&&(abs(currentY-newY) <=1)){	
		if (newCell->getCellType() != Cell::Wall){		
			if (!newCell->hasEnemy()){										
				if (newCell->hasItem()){					
					if (newCell->symbolToDisplayChar(newCell->getCellSymbol()) == 'G'){
						return true;
					}
				}
				return true;
			}
		}
	}
							
	return false;
}

