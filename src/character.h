#ifndef __CHARACTER_H__
#define __CHARACTER_H__
class Character
{

	static int idCount;
	
protected:
    int hp, atk, def;
    int x, y;
    int id;
    int currentAtk, currentDef; //For debuffs
public:
    Character(int hp, int atk, int def, int x, int y, int id);
    virtual ~Character() = 0;
    static int generateId();
	int getId();
    int getHp();
    int getAtk();
    int getDef();
    int getBaseAtk();
    int getBaseDef();
    void setPos(int xPos, int yPos);
};
#endif
