#ifndef __GAME_H__
#define __GAME_H__
#include <cstdlib>
#include <vector>
#include <string>
#include "player.h"
#include "floor.h"

const std::string DEFAULT_LAYOUT_CONFIG_FILE = "src/defaultLayout.txt";

class Game{

    Player* player;
    static Game* gameInstance;
    static void cleanup();
    bool layoutGiven;
    std::string layoutFileName;
    int currentFloor;
    bool isOver;
    bool victorious;
    std::vector<Floor*> *floors;
    void initializeFloors(
        std::vector<std::vector<std::vector<char> > > floorLayouts);
    void displayFloors();
    Game();
    ~Game();

public:
    static Game* getInstance();
    void initializeWorld();
    void displayWorld();
    void displayWelcomeScreen();
    void displayRaceSelectionScreen();
    void displayEndScreen();
    void displayDefeatScreen();
    void displayInstructions();
    void selectRace();
    void selectEndGameCommand();
    void setPlayer(Player* player);
    int getCurrentFloor();
    void setCurrentFloor(int floorNum);
    void updateState();
    void getInput();
    void restartGame();
    void clearGame();
    bool gameFinished();
    void generateFloors();
    void setGameOver(bool victorious = false);
    void setLayout(std::string layoutFileName);
    std::vector<Floor*>* getFloors();
    Player* getPlayer();
};
#endif
