#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"
#include <string>

class PlayerInterpreter;

class Player: public Character{

protected:
    double gold;
    char race;
    PlayerInterpreter* input;
    static Player* playerInstance;
    static void cleanup();
    Player(int hp, int atk, int def, int x, int y, char race, int id);
public:
    char getRace();
    static Player* getInstance();
    static std::string charToRace(char ch);
    void update();
    char getSymbol();
    double getGold();
    void setGold(double gold);
    virtual ~Player() = 0;
};
#endif
