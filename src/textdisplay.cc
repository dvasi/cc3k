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
			char current = td.gameDisplay.at(i).at(j);
			
			//Bold all important game objects
			if ((current >= 64)&&(current <=90)) attron(A_BOLD);
			
			//Color our character blue
			if (current == '@') attron(COLOR_PAIR(2));
			
			//Color gold piles yellow
			if (current == 'G') attron(COLOR_PAIR(3));
			
			//Color potions red
			if (current == 'P') attron(COLOR_PAIR(4));
			
			//Color dragons green
			if (current == 'D') attron(COLOR_PAIR(5));
			
			//Color merchants magenta
			if (current == 'M') attron(COLOR_PAIR(6));
			
			//Make staircases stand out more
			if (current == '/') attron(A_STANDOUT);
			
			//Draw character and refresh to see added attributes
			mvaddch(i,j,current);
			refresh();
			
			if (current == '@') attroff(COLOR_PAIR(2));

			if (current == 'G') attroff(COLOR_PAIR(3));
			
			if (current == 'P') attroff(COLOR_PAIR(4));
			
			if (current == 'D') attroff(COLOR_PAIR(5));
			
			if (current == 'M') attroff(COLOR_PAIR(6));
			
			if (current == '/') attroff(A_STANDOUT);
			
			if (((current >= 64)&&(current <=90))||(current == 47)) attroff(A_BOLD);
			
			
			
		}
	}
	return out;
}
