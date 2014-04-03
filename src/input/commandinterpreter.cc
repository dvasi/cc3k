#include <ncurses.h>
#include <map>
#include <string>
#include <cstdlib>
#include "commandinterpreter.h"
#include "command.h"
#include "character.h"
using namespace std;

CommandInterpreter::~CommandInterpreter(){
}

CommandInterpreter::CommandInterpreter() :
    actionStr(""){
}

bool CommandInterpreter::isCommandAdjacent(Character* ch, Command &cmd){
    int currentX = ch->getXPos();
    int currentY = ch->getYPos();
    int newX = cmd.getXPos();
    int newY = cmd.getYPos();

    if ((abs(currentX - newX) <= 1)&&(abs(currentY - newY) <= 1))
        return true;
    return false;
}

void CommandInterpreter::interpretCommand(Character* ch){
}
