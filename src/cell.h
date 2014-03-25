#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include <vector>
<<<<<<< HEAD
=======
#include "textdisplay.h"
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb

class Cell{

	int x, y;
	int cellType;
<<<<<<< HEAD
	bool hasEnemy, hasItem, hasPlayer;
=======
	char cellSymbol;
	bool enemy, item, player;
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
	int occupiedId;
	
public:
	enum{		//Cell types
		Wall=0,
		Floor,
		Doorway,
		Passage,
		Empty
	};
	void setCellType(int type);
	int getCellType();
<<<<<<< HEAD
	Cell(int xPos, int yPos, int type);
=======
	
	void setCellSymbol(char symbol);
	char getCellSymbol();
	
	void setOccupiedId(int id);
	int getOccupiedId();
	
	bool hasEnemy();
	bool hasItem();
	bool hasPlayer();
	void setOccupation(bool hasEnemy, bool hasItem, bool hasPlayer, int id=-1);
	
	char symbolToDisplayChar(char cellSymbol);
	void notifyDisplay(TextDisplay &td);
	
	Cell(int xPos, int yPos, int type, char symbol);
	Cell(int xPos, int yPos, int type, char symbol, bool hasEnemy, bool hasItem, bool hasPlayer, int id);
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
	~Cell();
	
};
#endif
