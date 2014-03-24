#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character
{
protected:
    int hp, atk, def;
    int currentAtk, currentDef; //for potion boosts that only last the floor
    int gold;
    char race;
public:
	Character();
	Character(char);
	int getHp();
	int getAtk();
	int getDef();
	void doubleGold(); //for dwarf class
	//void negBadPotion(); //elf class
	void halveGold(); //orc class
};


#endif