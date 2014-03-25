#ifndef __GAME_H__
#define __GAME_H__
#include <cstdlib>
#include <vector>
#include <string>
#include "player.h"
#include "floor.h"

const std::string DEFAULT_LAYOUT_CONFIG_FILE = "defaultLayout.txt";
const int NUM_FLOORS = 5;
      
class Game{

    Player* player;
    static Game* gameInstance;
    static void cleanup();
    bool layoutGiven;
    int currentFloor;
	std::vector <Floor*> floors;
	void initializeFloors(std::vector<std::vector<char> > floorLayout);
	void displayFloors();
    Game();
    ~Game();

public:
	static Game* getInstance();
	void initializeWorld(std::string layoutFileName=DEFAULT_LAYOUT_CONFIG_FILE);
	void displayWorld();
	void displayWelcomeScreen();
	void displayRaceSelectionScreen();
	void setPlayer(Player* player);
	Player* getPlayer();

};
#endif
