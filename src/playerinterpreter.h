#ifndef __PLAYERINTERPRETER_H__
#define __PLAYERINTERPRETER_H__
#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"
#include "movecommand.h"

class Game;
class Player;

class PlayerInterpreter: public CommandInterpreter{

	Game* game;
	public:
		//Assumes cmdName is already in the Command Map
		PlayerInterpreter();
		~PlayerInterpreter();
		void interpretCommand(Player* player);
		bool isMoveValid(MoveCommand &cmd);
		void movePlayer(MoveCommand &cmd);
		Player* getPlayer();		
};
#endif
