#ifndef __COMMANDINTERPRETER_H__
#define __COMMANDINTERPRETER_H__
#include <ncurses.h>
#include <map>
#include <string>
#include "character.h"
class CommandInterpreter{
	
	protected:
		std::string actionStr;
		CommandInterpreter();
		virtual ~CommandInterpreter() = 0;
	public:
		virtual void interpretCommand(Character* ch);		
};
#endif
