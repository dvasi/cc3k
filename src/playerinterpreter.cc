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

const char MOVE_UP = '8';
const char MOVE_DOWN = '5';
const char MOVE_LEFT = '4';
const char MOVE_RIGHT = '6';
const char MOVE_UP_LEFT = '7';
const char MOVE_UP_RIGHT = '9';
const char MOVE_DOWN_LEFT = '1';
const char MOVE_DOWN_RIGHT = '3';
const char USE = 'u';
const char ATTACK = 'a';
const char CHOOSE_HUMAN = 'h';
const char CHOOSE_ELF = 'e';
const char CHOOSE_DWARF = 'd';
const char CHOOSE_ORC = 'o';
const char RESTART = 'r';
const char QUIT = 'q';


PlayerInterpreter::~PlayerInterpreter(){}

PlayerInterpreter::PlayerInterpreter(){ 
	game = Game::getInstance(); 
}
	
void PlayerInterpreter::interpretCommand(Player* player){
	
	char cmd;
	cmd = getch();
	
	if (cmd == MOVE_UP){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos());	
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);			
	}
	if (cmd == MOVE_DOWN){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos());
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
		else interpretCommand(player);
	}
	if (cmd == MOVE_LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos(), player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);		
	}
	if (cmd == MOVE_RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos(), player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);		
	}
	if (cmd == MOVE_UP_LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);	
		else interpretCommand(player);	
	}
	if (cmd == MOVE_UP_RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);	
		else interpretCommand(player);	
	}
	if (cmd == MOVE_DOWN_LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);		
	}
	if (cmd == MOVE_DOWN_RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);	
		else interpretCommand(player);	
	}
	
	
}	

void PlayerInterpreter::movePlayer(MoveCommand &cmd){

	Character *ch = Player::getInstance();
	int currentX = ch->getXPos();
	int currentY = ch->getYPos();
	int newX = cmd.getXPos();
	int newY = cmd.getYPos();
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* currentCell = currentFloor->getCellAt(currentX,currentY);
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	TextDisplay *td = currentFloor->getTextDisplay();
	
	ch->setPos(newX,newY);
	
	if (newCell->getCellType() == Cell::Stairs){
		game->setCurrentFloor(game->getCurrentFloor() + 1);
	}
	
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

bool PlayerInterpreter::isMoveValid(MoveCommand &cmd){
	Character *ch = Player::getInstance();
	int currentX = ch->getXPos();
	int currentY = ch->getYPos();
	int newX = cmd.getXPos();
	int newY = cmd.getYPos();	
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	
	if ((abs(currentX-newX) <=1)&&(abs(currentY-newY) <=1)){	
		if ((newCell->getCellType() != Cell::Wall)&&(newCell->getCellType() != Cell::Empty)){		
			if (!newCell->hasEnemy()){										
				if (newCell->hasItem()){					
					if (newCell->symbolToDisplayChar(newCell->getCellSymbol()) == 'G'){
						return true;
					}
					else{
						return false;
					}
				}
				return true;
			}
		}
	}
							
	return false;
}

