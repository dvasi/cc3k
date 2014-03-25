#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "character.h"
class Player : public Character
{
protected:
	int gold;
	char race;
	static Player* playerInstance;
    static void cleanup();
    Player(int hp, int atk, int def, int x, int y, char race, int id);
public:
    static Player* getInstance();
    virtual ~Player() = 0;
};
#endif
