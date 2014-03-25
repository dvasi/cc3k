#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"
using namespace std;

CommandInterpreter::~CommandInterpreter(){}

CommandInterpreter::CommandInterpreter(map<string,char> cmdMap): commandMap(cmdMap){}

void CommandInterpreter::setCommand(string cmdName, char cmdChar){
	commandMap[cmdName] = cmdChar;
}

char CommandInterpreter::getCommand(string cmdName){
	return commandMap[cmdName];
}
