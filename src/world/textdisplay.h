#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <vector>
#include <iostream>
#include <string>

class TextDisplay{

    std::vector<std::vector<char> > gameDisplay;
    std::string actionStr;
public:
    TextDisplay(int width, int height);
    void notify(int xPos, int yPos, char symbol);
    void notify(std::string gameAction);
    void resetGameActions();
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
