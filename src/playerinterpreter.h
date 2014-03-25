#ifndef __PLAYERINTERPRETER_H__
#define __PLAYERINTERPRETER_H__
#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"
#include "player.h"
#include "game.h"
class PlayerInterpreter: public CommandInterpreter{

	bool raceSelected;
	Player* player;
	Game* game;
	public:
		//Assumes cmdName is already in the Command Map
		PlayerInterpreter(Game* game);
		~PlayerInterpreter();
		void interpretCommand();
		void setPlayer(Player* player);
		Player* getPlayer();		
};
#endif
