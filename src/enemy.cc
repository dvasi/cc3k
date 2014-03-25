#include "enemy.h"
#include <math.h>
using namespace std;


Enemy::Enemy(char type)
{
    switch (type)
    {
case 'v':
        hp = 50;
        atk = 25;
        def = 25;
        break;
case 'w':
        hp = 120;
        atk = 30;
        def = 5;
        break;
case 't':
        hp = 120;
        atk = 25;
        def = 15;
        break;
case 'g':
        hp = 70;
        atk = 5;
        def = 10;
        break;
case 'm':
        hp = 30;
        atk = 70;
        def = 5;
        break;
case 'd':
        hp = 150;
        atk = 20;
        def = 20;
        break;
case 'p':
        hp = 50;
        atk = 35;
        def = 20;
        break;
    }

}


int Enemy::takeDamage(int playerAtk)
{
    return ceil((100 / (100 + def)) * playerAtk);
}


int Enemy::getHp()
{
	return hp;
}

int Enemy::getAtk()
{
	return atk;
}

int Enemy::getDef()
{
	return def;
}