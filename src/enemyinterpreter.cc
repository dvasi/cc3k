#include "enemyinterpreter.h"
#include "enemy.h"
#include "game.h"
#include "movecommand.h"
#include <cstdlib>
using namespace std;

EnemyInterpreter::~EnemyInterpreter(){}

EnemyInterpreter::EnemyInterpreter(){ 
	game = Game::getInstance(); 
}

void EnemyInterpreter::interpretCommand(Enemy* enemy){

	//PRIORITIZE ATTACKING FIRST THOUGH LATER
	
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
