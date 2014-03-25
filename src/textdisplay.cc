#include <vector>
#include <iostream>
#include <ncurses.h>
#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(int width, int height){
	for (int i = 0; i < height; ++i){
		vector<char> row;
		for (int j = 0; j < width; ++j){
			row.push_back(' ');
		}
		gameDisplay.push_back(row);
	}		
}

void TextDisplay::notify(int xPos, int yPos, char symbol){
	gameDisplay.at(xPos).at(yPos) = symbol;
}

ostream &operator<<(ostream &out, const TextDisplay &td){

	for (unsigned int i = 0; i < td.gameDisplay.size(); ++i){
		for (unsigned int j = 0; j < td.gameDisplay.at(i).size(); ++j){
			mvaddch(i,j,td.gameDisplay.at(i).at(j));
		}
	}
	return out;
}
