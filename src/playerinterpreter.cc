#include <ncurses.h>
#include <map>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include "playerinterpreter.h"
#include "game.h"
#include "movecommand.h"
#include "attackcommand.h"
#include "itemusecommand.h"
#include "textdisplay.h"
#include "attackvisitor.h"
#include "itemusevisitor.h"
#include "cell.h"
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

PlayerInterpreter::PlayerInterpreter(): actionStr(""){
	game = Game::getInstance(); 
}
	
void PlayerInterpreter::interpretCommand(Player* player){
	
	char cmd;
	cmd = getch();
	actionStr = "PC";
	
	if (cmd == UP){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos());	
		if (isMoveValid(playerMove)){
			actionStr += " moves North";
			movePlayer(playerMove);			
		}
		else interpretCommand(player);			
	}
	else if (cmd == DOWN){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos());
		if (isMoveValid(playerMove)){
			actionStr += " moves South";
			movePlayer(playerMove);	
		}		
		else interpretCommand(player);
	}
	else if (cmd == LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos(), player->getYPos()-1);
		if (isMoveValid(playerMove)){
			actionStr += " moves West";
			movePlayer(playerMove);	
		}
		else interpretCommand(player);		
	}
	else if (cmd == RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos(), player->getYPos()+1);
		if (isMoveValid(playerMove)){
			actionStr += " moves East";
			movePlayer(playerMove);	
		}
		else interpretCommand(player);
	}
	else if (cmd == UP_LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos()-1);
		if (isMoveValid(playerMove)){
			actionStr += " moves North West";
			movePlayer(playerMove);	
		}	
		else interpretCommand(player);	
	}
	else if (cmd == UP_RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()-1, player->getYPos()+1);
		if (isMoveValid(playerMove)){
			actionStr += " moves North East";
			movePlayer(playerMove);	
		}	
		else interpretCommand(player);	
	}
	else if (cmd == DOWN_LEFT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos()-1);
		if (isMoveValid(playerMove)){
			actionStr += " moves South West";
			movePlayer(playerMove);	
		}
		else interpretCommand(player);		
	}
	else if (cmd == DOWN_RIGHT){
		MoveCommand playerMove = MoveCommand(player, player->getXPos()+1, player->getYPos()+1);
		if (isMoveValid(playerMove)){
			actionStr += " moves South East";
			movePlayer(playerMove);	
		}	
		else interpretCommand(player);	
	}
	
	else if (cmd == ATTACK){
		cmd = getch();
		
		if (cmd == UP){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()-1, player->getYPos());	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);			
		}
		else if (cmd == DOWN){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()+1, player->getYPos());	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);	
		}
		else if (cmd == LEFT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos(), player->getYPos()-1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);			
		}
		else if (cmd == RIGHT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos(), player->getYPos()+1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);			
		}
		else if (cmd == UP_LEFT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()-1, player->getYPos()-1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);
		}
		else if (cmd == UP_RIGHT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()-1, player->getYPos()+1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);
		}
		else if (cmd == DOWN_LEFT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()+1, player->getYPos()-1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);	
		}
		else if (cmd == DOWN_RIGHT){
			AttackCommand atkCmd = AttackCommand(player, player->getXPos()+1, player->getYPos()+1);	
			if (isAttackValid(atkCmd)) playerAttack(atkCmd);
			else interpretCommand(player);
		}
		else interpretCommand(player);	
	}

	else if (cmd == USE){
		cmd = getch();

		if (cmd == UP){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos()-1, player->getYPos());
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else if (cmd == DOWN){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos()+1, player->getYPos());
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else if (cmd == LEFT){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos(), player->getYPos()-1);
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else if (cmd == RIGHT){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos(), player->getYPos()+1);
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else if (cmd == UP_LEFT){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos()-1, player->getYPos()-1);
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else if (cmd == UP_RIGHT){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos()-1, player->getYPos()+1);
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else if (cmd == DOWN_LEFT){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos()+1, player->getYPos()-1);
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else if (cmd == DOWN_RIGHT){
			ItemUseCommand itemCmd = ItemUseCommand(player, player->getXPos()+1, player->getYPos()+1);
			if (isUseValid(itemCmd)) playerUseItem(itemCmd);
			else interpretCommand(player);
		}
		else interpretCommand(player);
	}

	else if (cmd == RESTART){
		game->setGameOver();
		return;
	}

	else if (cmd == QUIT){
		clear();
		endwin();
		exit(0);
	}
	else interpretCommand(player);
}	

void PlayerInterpreter::movePlayer(MoveCommand &cmd){

	Player *ch = Player::getInstance();
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
		int floorNum = game->getCurrentFloor();
		//Handle victory
		if (floorNum == NUM_FLOORS-1){
			game->setGameOver(true);
			return;
		}
		game->setCurrentFloor(game->getCurrentFloor() + 1);
		Floor *nextFloor = game->getFloors()->at(game->getCurrentFloor());
		TextDisplay *nextTd = nextFloor->getTextDisplay();
		nextTd->resetGameActions();
		nextTd->notify("PC advances to the next floor.");
	}
	
	//Check for gold to pick up
	if (newCell->hasGold()){
		Item *gold = currentFloor->getItem(newCell->getOccupiedId());	
		int oldGold = ch->getGold();	
		ItemUseVisitor itemVisitor = ItemUseVisitor();
		gold->accept(itemVisitor);
		int newGold = ch->getGold();
		ostringstream convert;
		convert << (newGold-oldGold);	
		actionStr += " and picks up " + convert.str() + " gold";
		currentFloor->removeItem(newCell->getOccupiedId());			
	}

	//Check for potions adjacent to our new position
	Cell* adjacentCell;
	for (int deltaX = -1; deltaX <= 1; ++deltaX){
		for (int deltaY = -1; deltaY <=1; ++deltaY){
			adjacentCell = currentFloor->getCellAt(newX+deltaX,newY+deltaY);
			if (adjacentCell->hasPotion()){
				Item *potion = currentFloor->getItem(adjacentCell->getOccupiedId());
				actionStr += " and sees a";
				if (potion->isRevealed()){
					actionStr += " ";
					actionStr += potion->getName();
				}
				else{
					actionStr += "n unknown potion";
				}
				break;
			}
		}
	}

	//Set up our new cell
	newCell->setOccupation(false,false,true,ch->getId());
	newCell->setCellSymbol('@');

	
	//Change our old one
	currentCell->setOccupation(false,false,false);
	currentCell->setCellSymbol(currentCell->typeToDisplayChar(currentCell->getCellType()));
	
	//Notify our display
	currentCell->notifyDisplay(*td);
	newCell->notifyDisplay(*td);
	actionStr += ". ";
	notifyDisplay(*td,actionStr);
	actionStr = "";
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
					Item *item = currentFloor->getItem(newCell->getOccupiedId());
					if (item->canPickUp()) return true;
				}
				else return true;
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
	int damageDealt = enemy->accept(atkVisitor);
	int currentEnemyHp = enemy->getHp();
	if (currentEnemyHp <= 0) currentEnemyHp = 0;
	char enemyName = enemy->getSymbol();
	ostringstream convert;
	actionStr += " deals ";
	convert << damageDealt;
	actionStr += convert.str();
	convert.str("");
	convert.clear();
	convert << currentEnemyHp;
	actionStr += " damage to ";
	actionStr+= enemyName;
	actionStr+= " (" + convert.str() + " HP)";


	
	//If enemy is dead remove it and add gold appropriately
	if (currentEnemyHp == 0){
		//Spawn merchant hoard upon merchant death
		if (enemy->getSymbol() == 'M'){
			currentFloor->spawnItem(newX,newY,'8');
		}
		else{
			newCell->setOccupation(false,false,false);
			newCell->setCellSymbol('.');
			ch->setGold(ch->getGold()+1);
		}
		currentFloor->removeEnemy(newCell->getOccupiedId());
	}	
	
	//Notify our display
	newCell->notifyDisplay(*td);
	actionStr += ". ";
	notifyDisplay(*td,actionStr);
	actionStr = "";
}

void PlayerInterpreter::notifyDisplay(TextDisplay &td, string action){
	td.notify(action);
}

bool PlayerInterpreter::isUseValid(ItemUseCommand &cmd) {
	Player *ch = Player::getInstance();
	int currentX = ch->getXPos();
	int currentY = ch->getYPos();
	int newX = cmd.getXPos();
	int newY = cmd.getYPos();
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* newCell = currentFloor->getCellAt(newX,newY);

	if ((abs(currentX-newX) <=1)&&(abs(currentY-newY) <=1)){
		if ((newCell->getCellType() != Cell::Wall)&&(newCell->getCellType() != Cell::Empty)){
			if (newCell->hasItem()){
				Item *item = currentFloor->getItem(newCell->getOccupiedId());
				if (item->canUse()) return true;
			}
		}
	}
	return false;
}

void PlayerInterpreter::playerUseItem(ItemUseCommand &cmd) {

	int newX = cmd.getXPos();
	int newY = cmd.getYPos();
	Floor* currentFloor = game->getFloors()->at(game->getCurrentFloor());
	Cell* newCell = currentFloor->getCellAt(newX,newY);
	Item *item = currentFloor->getItem(newCell->getOccupiedId());
	TextDisplay *td = currentFloor->getTextDisplay();

	//Use Item
	ItemUseVisitor itemVisitor = ItemUseVisitor();
	item->accept(itemVisitor);
	actionStr += " uses ";
	actionStr += item->getName();

	//Remove Item
	newCell->setOccupation(false,false,false);
	newCell->setCellSymbol('.');
	currentFloor->removeItem(newCell->getOccupiedId());

	//Notify our display
	newCell->notifyDisplay(*td);
	actionStr += ". ";
	notifyDisplay(*td,actionStr);
	actionStr = "";
}
