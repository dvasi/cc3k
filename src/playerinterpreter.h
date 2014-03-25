#ifndef __PLAYERINTERPRETER_H__
#define __PLAYERINTERPRETER_H__
#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"
class PlayerInterpreter: public CommandInterpreter{

	public:
		//Assumes cmdName is already in the Command Map
		PlayerInterpreter();
		~PlayerInterpreter();
		void interpretCommand();		
};
#endif
