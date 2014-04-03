#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "character.h"

class EnemyInterpreter;
class Visitor;

class Enemy: public Character{

protected:
    EnemyInterpreter* input;
    char type;
    bool hostile;
    bool mobile;
    Enemy(int hp, int atk, int def, int x, int y, char type, int id,
        EnemyInterpreter* input, bool hostile = true, bool mobile = true);
public:
    virtual ~Enemy();
    virtual bool isHostile();
    virtual void update();
    void takeDamage(int damage);
    char getSymbol();
    bool isMobile();
    int accept(Visitor &v);
};
#endif
