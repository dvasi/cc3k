#ifndef __ENEMYINTERPRETER_H__
#define __ENEMYINTERPRETER_H__
#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"
#include "movecommand.h"
#include "attackcommand.h"

class Game;
class Enemy;

class EnemyInterpreter : public CommandInterpreter{

	Game* game;
	public:
		EnemyInterpreter();
		~EnemyInterpreter();
		virtual void interpretCommand(Enemy* enemy);
		virtual bool isMoveValid(MoveCommand &cmd);
		virtual void moveEnemy(MoveCommand &cmd);	
		virtual void enemyAttack(AttackCommand &cmd);
};
#endif
