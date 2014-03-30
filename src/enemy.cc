#include "enemy.h"
#include "enemyinterpreter.h"
#include <math.h>
#include <iostream>
using namespace std;

Enemy::Enemy(int hp, int atk, int def, int x, int y, char type, int id, EnemyInterpreter* input, bool hostile, bool mobile): Character(hp,atk,def,x,y,id), input(input), type(type), hostile(hostile), mobile(mobile) {}

Enemy::~Enemy(){ delete input; }

double Enemy::takeDamage(int playerAtk)
{
    double damage = ceil((100.00 / (100.00 + def)) * playerAtk);
    hp -= damage;
    return damage;
}

void Enemy::update(){
	input->interpretCommand(this);
}

char Enemy::getSymbol(){ return type; }

bool Enemy::isHostile(){ return hostile; }

bool Enemy::isMobile(){ return mobile; }
