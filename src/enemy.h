#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "character.h"

class EnemyInterpreter;

class Enemy : public Character{
protected:
	bool isHostile; //for merchants and dragons
	char type;
	EnemyInterpreter* input;
	Enemy(int hp, int atk, int def, int x, int y, char type, int id, EnemyInterpreter* input);
public:
	double takeDamage(int);
	virtual char getType();
	virtual void update();
	virtual ~Enemy();
	char getSymbol();
};

#endif
