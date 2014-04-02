#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "enemyinterpreter.h"
#include "enemy.h"
#include "player.h"
#include "game.h"
#include "movecommand.h"
#include "attackcommand.h"
#include "attackvisitor.h"
using namespace std;

EnemyInterpreter::~EnemyInterpreter(){}

EnemyInterpreter::EnemyInterpreter(): actionStr(""){
	game = Game::getInstance(); 
}

void EnemyInterpreter::interpretCommand(Enemy* enemy){

	//Prioritize Attacking for enemy AI
	if (enemy->isHostile()){
		Player *player = Player::getInstance();
		//Player is within attacking vicinity
		if (playerInRange(enemy)){
			AttackCommand atkCmd = AttackCommand(enemy,player->getXPos(),player->getYPos());
			enemyAttack(atkCmd);
		}
		
		else if ((enemy->isMobile())&&(canMove(enemy))){
			int random;
			random = (rand()%8) + 1; //random number between 1 and 8 for direction
			if (random == 1){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()-1, enemy->getYPos());
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
			if (random == 2){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()+1, enemy->getYPos());
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
			if (random == 3){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos(), enemy->getYPos()-1);
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
			if (random == 4){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos(), enemy->getYPos()+1);
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
			if (random == 5){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()-1, enemy->getYPos()-1);
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
			if (random == 6){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()-1, enemy->getYPos()+1);
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
			if (random == 7){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()+1, enemy->getYPos()-1);
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
			if (random == 8){
				MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()+1, enemy->getYPos()+1);
				if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
				else interpretCommand(enemy);
			}
		}
	}
	else if ((enemy->isMobile())&&(canMove(enemy))){
		int random;
		random = (rand()%8) + 1; //random number between 1 and 8 for direction
		if (random == 1){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()-1, enemy->getYPos());
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
		if (random == 2){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()+1, enemy->getYPos());
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
		if (random == 3){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos(), enemy->getYPos()-1);
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
		if (random == 4){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos(), enemy->getYPos()+1);
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
		if (random == 5){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()-1, enemy->getYPos()-1);
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
		if (random == 6){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()-1, enemy->getYPos()+1);
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
		if (random == 7){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()+1, enemy->getYPos()-1);
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
		if (random == 8){
			MoveCommand enemyMove = MoveCommand(enemy, enemy->getXPos()+1, enemy->getYPos()+1);
			if (isMoveValid(enemyMove)) moveEnemy(enemyMove);
			else interpretCommand(enemy);
		}
	}
}

bool EnemyInterpreter::isMoveValid(MoveCommand &cmd){

	Character* enemy = cmd.getCharacter();
	int currentX = enemy->getXPos();
	int currentY = enemy->getYPos();
	int newX = cmd.getXPos();
	int newY = cmd.getYPos();
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	
	if ((abs(currentX-newX) <=1)&&(abs(currentY-newY) <=1)){	
		if (newCell->getCellType() == Cell::Floor){		
			if (!newCell->hasEnemy()){										
				if ((newCell->hasItem())||(newCell->hasPlayer())){					
					return false;
				}
				return true;
			}
		}
	}						
	return false;
}

bool EnemyInterpreter::canMove(Enemy *enemy){
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* newCell;
	int enemyXPos = enemy->getXPos();
	int enemyYPos = enemy->getYPos();
	bool availableCell = false;
	for (int i = -1; i <= 1; ++i){
		for (int j = -1; j <= 1; ++j){
			newCell = currentFloor->getCellAt(enemyXPos+i,enemyYPos+j);
			if ((!newCell->isOccupied())&&(newCell->getCellType() == Cell::Floor))
				availableCell = true;
		}
	}
	return availableCell;
}

bool EnemyInterpreter::playerInRange(Enemy* enemy){

	Player *player = Player::getInstance();
	int playerXPos = player->getXPos();
	int playerYPos = player->getYPos();
	int enemyXPos = enemy->getXPos();
	int enemyYPos = enemy->getYPos();

	//Player is within attacking vicinity
	if ((abs(playerXPos-enemyXPos) <=1)&&(abs(playerYPos-enemyYPos) <=1)) return true;
	return false;
}

void EnemyInterpreter::moveEnemy(MoveCommand &cmd){

	Character* enemy = cmd.getCharacter();
	int currentX = enemy->getXPos();
	int currentY = enemy->getYPos();
	int newX = cmd.getXPos();
	int newY = cmd.getYPos();
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* currentCell = currentFloor->getCellAt(currentX,currentY);
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	TextDisplay *td = currentFloor->getTextDisplay();
	
	enemy->setPos(newX,newY);
	
	//Set up our new cell
	newCell->setOccupation(true,false,false,enemy->getId());
	newCell->setCellSymbol(enemy->getSymbol());	
	
	//Change our old one
	currentCell->setOccupation(false,false,false);
	currentCell->setCellSymbol('.');
	
	//Notify our display
	currentCell->notifyDisplay(*td);
	newCell->notifyDisplay(*td);
}

void EnemyInterpreter::enemyAttack(AttackCommand &cmd){

	Character *enemy = cmd.getAttacker();
	Player *ch = Player::getInstance();
	Floor *currentFloor = game->getFloors()->at(game->getCurrentFloor());
	TextDisplay *td = currentFloor->getTextDisplay();
	
	//Attack enemy
	AttackVisitor atkVisitor = AttackVisitor(enemy);
	int damageDealt = ch->accept(atkVisitor);
	char enemyName = enemy->getSymbol();
	ostringstream convert;
	actionStr = enemyName;
	if (damageDealt > 0){
		actionStr += " deals ";
		convert << damageDealt;
		actionStr += convert.str();
		actionStr += " damage to PC";
	}
	else{
		actionStr += " misses its attack on PC";
	}
	
	//If player is dead restart game
	if (ch->getHp() <= 0){
		game->setGameOver(false);
	}
	//Notify display
	actionStr += ". ";
	notifyDisplay(*td,actionStr);
	actionStr = "";
}

void EnemyInterpreter::notifyDisplay(TextDisplay &td, string action){
	td.notify(action);
}
