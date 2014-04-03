#ifndef __ENEMYINTERPRETER_H__
#define __ENEMYINTERPRETER_H__
#include <string>
#include "commandinterpreter.h"

class Game;
class Enemy;
class TextDisplay;
class MoveCommand;
class AttackCommand;

class EnemyInterpreter: public CommandInterpreter{

    Game* game;
    std::string actionStr;

protected:
    std::pair<int, int> getPositionFromNum(int cmd);
    void randomMoveEnemy(Enemy* enemy);
    bool isMoveValid(MoveCommand &cmd);
    bool canMove(Enemy *enemy);
    void moveEnemy(MoveCommand &cmd);
    virtual bool playerInRange(Enemy* enemy);
    void enemyAttack(AttackCommand &cmd);
    void notifyDisplay(TextDisplay &td, std::string action);
public:
    EnemyInterpreter();
    ~EnemyInterpreter();
    virtual void interpretCommand(Enemy* enemy);
};
#endif
