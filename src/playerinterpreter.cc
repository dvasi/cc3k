#include <ncurses.h>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include "playerinterpreter.h"
#include "human.h"
#include "game.h"
#include "movecommand.h"
#include "attackcommand.h"
#include "textdisplay.h"
#include "attackvisitor.h"
using namespace std;

const char UP = '8';
const char DOWN = '5';
const char LEFT = '4';
const char RIGHT = '6';
const char UP_LEFT = '7';
const char UP_RIGHT = '9';
const char DOWN_LEFT = '1';
const char DOWN_RIGHT = '3';
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
	
	if (cmd == UP){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos());	
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);			
	}
	if (cmd == DOWN){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos());
		if (isMoveValid(playerMove)) movePlayer(playerMove);		
		else interpretCommand(player);
	}
	if (cmd == LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos(), player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);		
	}
	if (cmd == RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos(), player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);		
	}
	if (cmd == UP_LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);	
		else interpretCommand(player);	
	}
	if (cmd == UP_RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);	
		else interpretCommand(player);	
	}
	if (cmd == DOWN_LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos()-1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);
		else interpretCommand(player);		
	}
	if (cmd == DOWN_RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos()+1);
		if (isMoveValid(playerMove)) movePlayer(playerMove);	
		else interpretCommand(player);	
	}
	
	if (cmd == ATTACK){
		cmd = getch();
		
		if (cmd == UP){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()-1, player->getYPos());	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);			
		}
		if (cmd == DOWN){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()+1, player->getYPos());	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);	
		}
		if (cmd == LEFT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos(), player->getYPos()-1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);			
		}
		if (cmd == RIGHT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos(), player->getYPos()+1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);			
		}
		if (cmd == UP_LEFT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()-1, player->getYPos()-1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);
		}
		if (cmd == UP_RIGHT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()-1, player->getYPos()+1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);
		}
		if (cmd == DOWN_LEFT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()+1, player->getYPos()-1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);	
		}
		if (cmd == DOWN_RIGHT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()+1, player->getYPos()+1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);
		}	
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

bool PlayerInterpreter::isAttackValid(AttackCommand &cmd){
	Player *ch = Player::getInstance();
	int currentX = ch->getXPos();
	int currentY = ch->getYPos();
	int newX = cmd.getXPos();
	int newY = cmd.getYPos();	
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	
	if ((abs(currentX-newX) <=1)&&(abs(currentY-newY) <=1)){	
		if ((newCell->getCellType() != Cell::Wall)&&(newCell->getCellType() != Cell::Empty)){		
			if (newCell->hasEnemy()){										
				return true;
			}
		}
	}							
	return false;
}

void PlayerInterpreter::playerAttack(AttackCommand &cmd){

	Player *ch = Player::getInstance();
	int newX = cmd.getXPos();
	int newY = cmd.getYPos();
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	Enemy *enemy = currentFloor->getEnemy(newCell->getOccupiedId());
	TextDisplay *td = currentFloor->getTextDisplay();
	
	//Attack enemy
	AttackVisitor atkVisitor = AttackVisitor(ch);
	enemy->accept(atkVisitor);
	
	//If enemy is dead remove it and add gold appropriately
	if (enemy->getHp() <= 0){
		newCell->setOccupation(false,false,false);
		newCell->setCellSymbol('.');
		currentFloor->removeEnemy(newCell->getOccupiedId());
		ch->setGold(ch->getGold()+1);
	}	
	
	//Notify our display
	newCell->notifyDisplay(*td);
}


