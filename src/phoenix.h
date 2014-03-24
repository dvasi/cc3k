#ifndef __PHOENIX_H__
#define __PHOENIX_H__

class Phoenix(): public enemy
{
    int hp, atk, def;
public:
	void takeDamage(int);
	Phoenix();
	~Phoenix();


};


#endif