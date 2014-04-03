#include "command.h"

Command::Command(int x, int y) :
    x(x), y(y){
}

Command::~Command(){
}

int Command::getXPos(){
    return x;
}

int Command::getYPos(){
    return y;
}
