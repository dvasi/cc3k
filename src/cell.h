#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include <vector>

class Cell{

	int x, y;
	int cellType;
	bool hasEnemy, hasItem, hasPlayer;
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
	static int charToCellType(char c);
	Cell(int xPos, int yPos, int type);
	~Cell();
	
};
#endif
