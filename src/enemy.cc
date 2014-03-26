#include "enemy.h"
#include <math.h>
#include <iostream>
using namespace std;

Enemy::Enemy(int hp, int atk, int def, int x, int y, char type, int id): Character(hp,atk,def,x,y,id), isHostile(true), type(type){}
/*Enemy::Enemy(char type)
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

}*/

double Enemy::takeDamage(int playerAtk)
{
    double damage = ceil((100.00 / (100.00 + def)) * playerAtk);
    hp -= damage;
    return damage;
}
