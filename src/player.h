#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"
#include "playerinterpreter.h"
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
    void update();
    char getSymbol();
    virtual ~Player() = 0;
};
#endif
