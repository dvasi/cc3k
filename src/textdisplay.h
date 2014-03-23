#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <vector>
#include <iostream>
class TextDisplay{
	
	std::vector<std::vector<char> > gameDisplay;
	public:
		TextDisplay(int width, int height);
		
		void notify(int xPos, int yPos, char symbol);
		
		friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
