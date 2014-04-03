#include "enemy.h"
#include "enemyinterpreter.h"
#include "visitor.h"
#include <math.h>
#include <iostream>
using namespace std;

Enemy::Enemy(int hp, int atk, int def, int x, int y, char type, int id,
    EnemyInterpreter* input, bool hostile, bool mobile) :
    Character(hp, atk, def, x, y, id), input(input), type(type), hostile(hostile),
        mobile(mobile){
}

Enemy::~Enemy(){
    delete input;
}

void Enemy::takeDamage(int damage){
    hp -= damage;
}

void Enemy::update(){
    input->interpretCommand(this);
}

char Enemy::getSymbol(){
    return type;
}

bool Enemy::isHostile(){
    return hostile;
}

bool Enemy::isMobile(){
    return mobile;
}

int Enemy::accept(Visitor &v){
    return v.visit(this);
}
