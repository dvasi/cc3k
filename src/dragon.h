#ifndef __DRAGON_H__
#define __DRAGON_H__

class Dragon(): public enemy
{
    int hp, atk, def;
    bool isHostile;
public:
	void takeDamage(int);
	Dragon();
	~Dragon();


};


#endif