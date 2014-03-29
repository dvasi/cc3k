#include "character.h"
#include "visitor.h"
#include <iostream>
using namespace std;

Character::Character(int hp, int atk, int def, int x, int y,int id): hp(hp), atk(atk), def(def), x(x), y(y), id(id), maxHp(hp), currentAtk(atk), currentDef(def){}

Character::~Character(){}

int Character::getHp()
{
    return hp;
}

int Character::getAtk()
{
	return currentAtk;
}

int Character::getDef()
{
	return currentDef;
}

int Character::getBaseAtk(){
	return atk;
}

int Character::getBaseDef(){
	return def;
}

void Character::setPos(int xPos, int yPos){ 
	
	x = xPos;
	y = yPos;
}

int Character::getXPos(){ return x; }

int Character::getYPos(){ return y; }

int Character::generateId(){
	idCount++;
	return idCount;
}

int Character::getId(){
	return id;
}

int Character::getMaxHp(){
	return maxHp;
}

char Character::getSymbol(){ return 'h'; }

void Character::accept(Visitor* v){ v->visit(this); }

void Character::takeDmg(int dmg) { hp -= dmg; }

int Character::idCount = 0;
