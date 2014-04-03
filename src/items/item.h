#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>

class Visitor;

class Item{

    static int idCount;
protected:
    int id;
    char type;
    bool lootable;
    bool useable;
    int x, y;

public:
    Item();
    Item(int id, char type, bool lootable = false, bool useable = true, int x = 0, int y = 0);
    static int generateId();
    int getId();
    bool canPickUp();
    bool canUse();
    void setPos(int xPos, int yPos);
    int getXPos();
    int getYPos();
    virtual std::string getName();
    char getSymbol();
    virtual bool isRevealed();
    virtual ~Item() = 0;
    virtual void accept(Visitor &v);
};
#endif
