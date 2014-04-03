#ifndef __COMMANDINTERPRETER_H__
#define __COMMANDINTERPRETER_H__
#include <string>

class Character;
class Command;

class CommandInterpreter{

protected:
    std::string actionStr;
    CommandInterpreter();
    virtual ~CommandInterpreter() = 0;
    virtual bool isCommandAdjacent(Character* ch, Command &cmd);
public:
    virtual void interpretCommand(Character* ch);
};
#endif
