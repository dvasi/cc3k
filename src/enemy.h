#ifndef __ENEMY_H__
#define __ENEMY_H__

class Enemy(){
protected:
int hp, atk, def;
bool isHostile; //for merchants and dragons
public:
	virtual int takeDamage(int);
};

#endif