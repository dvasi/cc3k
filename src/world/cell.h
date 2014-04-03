#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include <vector>
#include "textdisplay.h"

class Cell{

    int x, y;
    int cellType;
    char cellSymbol;
    bool enemy, item, player;
    int occupiedId;
public:
    enum {		//Cell types
        Wall = 0, Floor, Doorway, Passage, Stairs, Empty
    };
    void setCellType(int type);
    int getCellType();

    void setCellSymbol(char symbol);
    char getCellSymbol();

    void setOccupiedId(int id);
    int getOccupiedId();

    bool hasEnemy();
    bool hasItem();
    bool hasGold();
    bool hasPotion();
    bool hasPlayer();
    void setOccupation(bool hasEnemy, bool hasItem, bool hasPlayer, int id = -1);
    bool isOccupied();
    int getXPos();
    int getYPos();

    char symbolToDisplayChar(char cellSymbol);
    char typeToDisplayChar(int cellType);
    void notifyDisplay(TextDisplay &td);

    Cell(int xPos, int yPos, int type, char symbol);
    Cell(int xPos, int yPos, int type, char symbol, bool hasEnemy, bool hasItem,
        bool hasPlayer, int id);
    ~Cell();
};
#endif
