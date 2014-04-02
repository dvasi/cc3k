#ifndef __ENEMYINTERPRETER_H__
#define __ENEMYINTERPRETER_H__
#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"

class Game;
class Enemy;
class TextDisplay;
class MoveCommand;
class AttackCommand;

class EnemyInterpreter : public CommandInterpreter{

	Game* game;
	std::string actionStr;
	public:
		EnemyInterpreter();
		~EnemyInterpreter();
		virtual void interpretCommand(Enemy* enemy);
		virtual bool isMoveValid(MoveCommand &cmd);
		virtual void moveEnemy(MoveCommand &cmd);	
		virtual bool playerInRange(Enemy* enemy);
		virtual void enemyAttack(AttackCommand &cmd);
		void notifyDisplay(TextDisplay &td, std::string action);
};
#endif
