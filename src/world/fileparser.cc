#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "fileparser.h"
#include "floor.h"
#include "cell.h"

using namespace std;

FileParser::FileParser() {}

vector<vector<vector<char> > > FileParser::parseFloorLayouts(string fileName){

	//Vector of floor layouts, which are 2D vectors of characters
	vector<vector<vector<char> > > floors;
	
	ifstream file(fileName.c_str());
	
	//Intentionally read whitespace
	file.unsetf(ios_base::skipws);
	
	char c;
	for(int i = 0; i < NUM_FLOORS; ++i){
		vector<vector<char> > cells;
		for(int j = 0; j < BOARD_HEIGHT; ++j){
			vector<char> row;
			for(int k = 0; k < BOARD_WIDTH; ++k){
				file >> c;
				row.push_back(c);
			}
			//Accounts for the newline after each board row
			file.ignore();
			cells.push_back(row);
		}
		floors.push_back(cells);
	}
	file.close();
	return floors;
}

int FileParser::charToCellType(char c){

	if (c == ' ') return Cell::Empty;
	
	if ((c == '|')||(c == '-')) return Cell::Wall;
	
	if (c == '+') return Cell::Doorway;
	
	if (c == '#') return Cell::Passage;
	
	if (c == '/') return Cell::Stairs;
	
	else return Cell::Floor;
}
