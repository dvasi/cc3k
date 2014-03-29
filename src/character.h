#ifndef __CHARACTER_H__
#define __CHARACTER_H__
class Visitor;

class Character
{
	static int idCount;
	
protected:
    int hp, atk, def;
    int x, y;
    int id;
    int maxHp, currentAtk, currentDef; //For debuffs
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
    int getMaxHp();
    int getXPos();
    int getYPos();
    void takeDmg(int dmg);
    void setPos(int xPos, int yPos);
    virtual void accept(Visitor &v);
    virtual char getSymbol();
};
#endif
