#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"
using namespace std;

CommandInterpreter::~CommandInterpreter(){}

CommandInterpreter::CommandInterpreter(): actionStr("") {}

void CommandInterpreter::interpretCommand(Character* ch){}
