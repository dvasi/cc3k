#ifndef __WEREWOLF_H__
#define __WEREWOLF_H__

class Werewolf(): public enemy
{
    int hp, atk, def;
public:
	int takeDamage(int);
	Werewolf();
	//~Werewolf();


};


#endif