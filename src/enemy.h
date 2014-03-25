#ifndef __ENEMY_H__
#define __ENEMY_H__

class Enemy{
protected:
int hp, atk, def;
bool isHostile; //for merchants and dragons
public:
	Enemy(char);
	int takeDamage(int);
	int getHp();
	int getAtk();
	int getDef();
};

#endif