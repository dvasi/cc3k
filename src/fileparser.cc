#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "fileparser.h"
#include "cell.h"
#include "floor.h"

using namespace std;

FileParser::FileParser() {}

vector<vector<char> > FileParser::parseFloorLayout(string fileName){

	vector<vector<char> > cells;
	
	ifstream file(fileName.c_str());
	
	//Intentionally read whitespace
	file.unsetf(ios_base::skipws);
	
	char c;
	for(int i = 0; i < BOARD_HEIGHT; ++i){	
		vector<char> row;
		for(int j = 0; j < BOARD_WIDTH; ++j){
			file >> c;
			row.push_back(c);
		}
		//Accounts for the newline after each board row
		file.ignore();
		cells.push_back(row);
	}
	file.close();
	return cells;
}

int FileParser::charToCellType(char c){

	if (c == ' ') return Cell::Empty;
	
	if ((c == '|')||(c == '-')) return Cell::Wall;
	
	if (c == '+') return Cell::Doorway;
	
	if (c == '#') return Cell::Passage;
	
	else return Cell::Floor;
}
