#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "character.h"
class Enemy : public Character{
protected:
bool isHostile; //for merchants and dragons
char type;
public:
	Enemy(int hp, int atk, int def, int x, int y, char type, int id);
	double takeDamage(int);
};

#endif
