#ifndef __GAME_H__
#define __GAME_H__
#include <cstdlib>
#include "world.h"

const std::string DEFAULT_LAYOUT_CONFIG_FILE = "defaultLayout.txt";

class Game{

    World* worldInstance;
    static Game* gameInstance;
    static void cleanup();
    Game();
    ~Game();

public:
	static Game* getInstance();
<<<<<<< HEAD
	void chooseRace();
=======
>>>>>>> 1aeeadf45f3190acfa69d09b6fc53abe9f699bdb
	void initializeWorld(std::string layoutFileName=DEFAULT_LAYOUT_CONFIG_FILE);
	void displayWorld();

};
#endif
