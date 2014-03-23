#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include <vector>

class Cell{

	int x, y;
	int cellType;
	bool enemy, item, player;
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
	void setOccupiedId(int id);
	int getOccupiedId();
	bool hasEnemy();
	bool hasItem();
	bool hasPlayer();
	void setOccupation(bool hasEnemy, bool hasItem, bool hasPlayer, int id=-1);
	
	Cell(int xPos, int yPos, int type);
	Cell(int xPos, int yPos, int type, bool hasEnemy, bool hasItem, bool hasPlayer, int id);
	~Cell();
	
};
#endif
