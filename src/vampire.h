#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

class Vampire(): public enemy
{
    int hp, atk, def;
public:
	void takeDamage(int);
	Vampire();
	~Vampire();


};


#endif