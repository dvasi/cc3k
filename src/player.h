#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"
#include "playerinterpreter.h"
#include <string>
class Player : public Character
{
protected:
	int gold;
	char race;
	PlayerInterpreter* input;
	static Player* playerInstance;
    static void cleanup();
    Player(int hp, int atk, int def, int x, int y, char race, int id);
public:
    static Player* getInstance();
    static std::string charToRace(char ch);
    void update();
    char getSymbol();
    int getGold();
    void setGold(int gold);
    virtual ~Player() = 0;
};
#endif
