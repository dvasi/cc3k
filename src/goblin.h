#ifndef __GOBLIN_H__
#define __GOBLIN_H__

class Goblin(): public enemy
{
    int hp, atk, def;
public:
	void takeDamage(int);
	Goblin();
	~Goblin();


};


#endif