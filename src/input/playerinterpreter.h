#ifndef __PLAYERINTERPRETER_H__
#define __PLAYERINTERPRETER_H__
//#include <ncurses.h>
#include <map>
#include <string>
#include "commandinterpreter.h"

class Game;
class Player;
class TextDisplay;
class MoveCommand;
class AttackCommand;
class ItemUseCommand;

class PlayerInterpreter: public CommandInterpreter{

    Game* game;
    std::string actionStr;
public:
    PlayerInterpreter();
    ~PlayerInterpreter();
    void interpretCommand(Player* player);
    bool isMoveValid(MoveCommand &cmd);
    void movePlayer(MoveCommand &cmd);
    bool isAttackValid(AttackCommand &cmd);
    void playerAttack(AttackCommand &cmd);
    bool isUseValid(ItemUseCommand &cmd);
    void playerUseItem(ItemUseCommand &cmd);
    void notifyDisplay(TextDisplay &td, std::string action);
    Player* getPlayer();
};
#endif
