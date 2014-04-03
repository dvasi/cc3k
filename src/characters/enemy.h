#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "character.h"

class EnemyInterpreter;
class Visitor;

class Enemy: public Character{

    void takeDamage(int damage); 
protected:
    EnemyInterpreter* input;
    char type;
    bool hostile;
    bool mobile;
    Enemy(int hp, int atk, int def, int x, int y, char type, int id,
    EnemyInterpreter * input, bool hostile = true, bool mobile = true);
public:
    char getSymbol();
    bool isMobile();
    int accept(Visitor & v);
    virtual ~Enemy();
    virtual bool isHostile();
    virtual void update();
};
#endif
