#ifndef __TROLL_H__
#define __TROLL_H__

class Troll(): public enemy
{
    int hp, atk, def;
public:
	void takeDamage(int);
	Troll();
	~Troll();


};


#endif