#include "character.h"
using namespace std;

Character::Character(): hp(140), atk(20), def(20), gold(0)
{
    currentAtk = atk;
    currentDef = def;
    race = 'h';
}

Character::Character(char selectedRace): gold(0)
{
    race = selectedRace;
    hp = getHp();
    atk = getAtk();
    def = getDef();
    currentAtk = atk;
    currentDef = def;
}

int Character::getHp()
{
    if (race == 'd')
    {
        return 100;
    }
    else if (race == 'e')
    {
        return 140;
    }
    else if (race == 'o')
    {
        return 180;
    }
    else
    {
        return 140; //if human for some reason
    }
}

int Character::getAtk()
{
    if (race == 'd')
    {
        return 20;
    }
    else if (race == 'e' || race == 'o')
    {
        return 30;
    }
    else
    {
        return 20; //if human for some reason
    }
}

int Character::getDef()
{
    if (race == 'd')
    {
        return 30;
    }
    else if (race == 'e')
    {
        return 10;
    }
    else if (race == 'o')
    {
        return 25;
    }
    else
    {
        return 20; //if human for some reason
    }
}

void Character::doubleGold()
{
    if (race == 'd') //double-check the race
    {
        gold *= 2;
    }
}

//void Character::negBadPotion()
//{
 //   if (race == "elf")
   // {
//potion
    //}
//}

void Character::halveGold()
{
    if (race == 'o')
    {
        gold *= .5;
    }
}