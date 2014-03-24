#ifndef __MERCHANT_H__
#define __MERCHANT_H__

class Merchant(): public enemy
{
    int hp, atk, def;
    bool isHostile;
public:
	void takeDamage(int);
	Merchant();
	~Merchant();


};


#endif