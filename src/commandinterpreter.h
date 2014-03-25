#ifndef __COMMANDINTERPRETER_H__
#define __COMMANDINTERPRETER_H__
#include <ncurses.h>
#include <map>
#include <string>
class CommandInterpreter{
	
	protected:
		std::map<std::string,char> commandMap;
		CommandInterpreter(std::map<std::string,char> cmdMap);
		virtual ~CommandInterpreter() = 0;
	public:
		//Assumes cmdName is already in the Command Map
		void setCommand(std::string cmdName, char cmdChar);
		char getCommand(std::string cmdName);
		virtual void interpretCommand() = 0;		
};
#endif
