#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#include <ncurses.h>
#include <sstream>
#include "floor.h"
#include "cell.h"
#include "chamber.h"
#include "fileparser.h"
#include "itemfactory.h"
#include "itemusevisitor.h"
#include "enemyfactory.h"
#include "player.h"
#include "game.h"
#include "dragon.h"
#include "gold.h"
#include "dragongold.h"
using namespace std;

Floor::Floor() :
    startXPos(3), startYPos(3){
    td = new TextDisplay(BOARD_WIDTH, BOARD_HEIGHT);
    itemStatMonitor = new ItemUseVisitor();
}

Floor::~Floor(){
    for (unsigned int i = 0; i < allCells.size(); ++i){
        while (!allCells.at(i).empty()){
            delete allCells.at(i).back();
            allCells.at(i).pop_back();
        }
    }
    delete td;
    delete itemStatMonitor;

    while (!chambers.empty()){
        delete chambers.back();
        chambers.pop_back();
    }

    for (map<int, Item*>::iterator i = floorItems.begin(); i != floorItems.end(); ++i){
        delete i->second;
        floorItems.erase(i);
    }

    for (map<int, Enemy*>::iterator i = floorEnemies.begin(); i != floorEnemies.end();
        ++i){
        delete i->second;
        floorEnemies.erase(i);
    }
}

void Floor::floodFillChamber(int xStartPos, int yStartPos, char floodChar,
    vector<vector<char> > &floorLayout){
    char current = floorLayout.at(yStartPos).at(xStartPos);
    if ((current == floodChar) || (current == '-') || (current == '|') || (current == '+') || (current == '#')) return;
    floorLayout.at(yStartPos).at(xStartPos) = floodChar;
    floodFillChamber(xStartPos - 1, yStartPos, floodChar, floorLayout);
    floodFillChamber(xStartPos + 1, yStartPos, floodChar, floorLayout);
    floodFillChamber(xStartPos, yStartPos - 1, floodChar, floorLayout);
    floodFillChamber(xStartPos, yStartPos + 1, floodChar, floorLayout);
}

void Floor::createChamber(vector<vector<char> > floorLayout){
    vector<Cell *> chamberCells;
    char current;
    for (unsigned int i = 0; i < floorLayout.size(); ++i){
        for (unsigned int j = 0; j < floorLayout.at(i).size(); ++j){
            current = floorLayout.at(i).at(j);
            if (current == 'X'){
                chamberCells.push_back(allCells.at(i).at(j));
            }
        }
    }
    Chamber *newChamber = new Chamber(chamberCells);
    chambers.push_back(newChamber);
}

//Loops through original layout until it finds a floor cell,
//then uses "Flood Fill" to mark all tiles in that chamber.
//Now that the chamber is identified, we can initialize it
//with the appropriate cells from our layout. After
//a chamber is found we unmark it and proceed to find a new one.
//We do this until our layout is exhausted, and hence all chambers are found.
void Floor::initializeChambers(vector<vector<char> > floorLayout){
    char current;
    vector<vector<char> > floorLayoutCopy = floorLayout;
    vector<vector<char> > floodFillAcc = floorLayout;
    for (unsigned int i = 0; i < floorLayoutCopy.size(); ++i){
        for (unsigned int j = 0; j < floorLayoutCopy.at(i).size(); ++j){
            current = floorLayoutCopy.at(i).at(j);
            if (current == '.'){
                floodFillChamber(j, i, 'X', floorLayoutCopy);
                floodFillChamber(j, i, 'X', floodFillAcc);
                createChamber(floodFillAcc);
                floodFillChamber(j, i, '.', floodFillAcc);
            }
        }
    }
}

void Floor::initializeCells(vector<vector<char> > floorLayout){
    char current;

    //Generate cells based on given layout
    for (int i = 0; i < BOARD_HEIGHT; ++i){
        vector<Cell *> row;
        for (int j = 0; j < BOARD_WIDTH; ++j){
            current = floorLayout.at(i).at(j);
            Cell *parsedCell = generateCell(i, j, current);
            parsedCell->notifyDisplay(*td);
            row.push_back(parsedCell);
        }
        allCells.push_back(row);
    }
    matchDragonHoards();
}

void Floor::matchDragonHoards(){
    Dragon *dragon;
    DragonGold *hoard;
    for (unsigned int i = 0; i < floorDragons.size(); ++i){
        dragon = floorDragons.at(i);
        for (unsigned int j = 0; j < floorDragonHoards.size(); ++j){
            hoard = floorDragonHoards.at(j);
            int dragonXPos = dragon->getXPos();
            int dragonYPos = dragon->getYPos();
            int hoardXPos = hoard->getXPos();
            int hoardYPos = hoard->getYPos();
            if ((abs(dragonXPos - hoardXPos) <= 1) && (abs(dragonYPos - hoardYPos) <= 1)){
                dragon->guard(hoard);
                break;
            }
        }
    }
}

Cell* Floor::generateCell(int xPos, int yPos, char symbol){
    FileParser parser = FileParser();
    int cellType = parser.charToCellType(symbol);
    Cell *parsedCell;

    //Could have an object occupying it possibly
    if (cellType == Cell::Floor){
        bool hasEnemy = false;
        bool hasItem = false;
        bool hasPlayer = false;
        int id = -1;

        //Special dragon hoard case, to match it with a Dragon after
        if (symbol == '9'){
            Gold* hoard = new DragonGold(Item::generateId());
            hoard->setPos(xPos, yPos);
            hasItem = true;
            id = hoard->getId();
            floorDragonHoards.push_back(static_cast<DragonGold*>(hoard));
            floorItems[id] = hoard;
        }

        //Other item case
        else if (isdigit(symbol)){
            ItemFactory itFactory = ItemFactory();
            Item* newItem = itFactory.getItem(symbol);
            newItem->setPos(xPos, yPos);
            hasItem = true;
            id = newItem->getId();
            floorItems[id] = newItem;
        }

        //Special Dragon case, to match it with a dragon hoard after.
        else if (symbol == 'D'){
            Dragon* dragon = new Dragon(0, 0, Character::generateId());
            dragon->setPos(xPos, yPos);
            hasEnemy = true;
            id = dragon->getId();
            floorDragons.push_back(dragon);
            floorEnemies[id] = dragon;
            enemyActionQueue.push(dragon);
        }

        //Enemy case
        else if ((symbol == 'V') || (symbol == 'W') || (symbol == 'N') || (symbol == 'M') || (symbol == 'X') || (symbol == 'T')){
            EnemyFactory enFactory = EnemyFactory();
            Enemy *newEnemy = enFactory.getEnemy(symbol);
            newEnemy->setPos(xPos, yPos);
            hasEnemy = true;
            id = newEnemy->getId();
            floorEnemies[id] = newEnemy;
            enemyActionQueue.push(newEnemy);
        }

        //Player case
        else if (symbol == '@'){
            hasPlayer = true;
            Player *player = Player::getInstance();
            player->setPos(xPos, yPos);
            startXPos = xPos;
            startYPos = yPos;
        }
        parsedCell = new Cell(xPos, yPos, cellType, symbol, hasEnemy, hasItem, hasPlayer, id);
    }
    else{
        parsedCell = new Cell(xPos, yPos, cellType, symbol);
    }
    return parsedCell;
}

void Floor::display(){
    cout << *td;
    td->resetGameActions();
}

void Floor::removeItem(int id){
    delete floorItems[id];
    floorItems.erase(id);
}

void Floor::removeEnemy(int id){
    delete floorEnemies[id];
    floorEnemies.erase(id);
}

Enemy* Floor::getEnemy(int id){
    return floorEnemies[id];
}

Item* Floor::getItem(int id){
    return floorItems[id];
}

void Floor::spawnItem(int xPos, int yPos, char symbol){
    ItemFactory itFactory = ItemFactory();
    Item *item = itFactory.getItem(symbol);
    Cell *currentCell = allCells.at(xPos).at(yPos);
    currentCell->setOccupation(false, true, false, item->getId());
    currentCell->setCellSymbol(symbol);
    item->setPos(xPos, yPos);
    floorItems[item->getId()] = item;
    currentCell->notifyDisplay(*td);
}

void Floor::setPlayerStaircase(){ //generate player and staircase in different cells
    int random;
    int playerChamberNum;
    Chamber *currentChamber;
    Cell *currentCell;

    //Randomly select a chamber
    random = (rand() % 5);
    playerChamberNum = random;
    currentChamber = chambers.at(random);

    //Randomly select a cell from the chamber
    random = (rand() % (currentChamber->cells.size()));
    currentCell = currentChamber->cells.at(random);

    generatePlayer(currentCell);

    //Randomly select a chamber
    random = (rand() % 5);
    currentChamber = chambers.at(random);

    //Make sure player and staircase are in distinct chambers
    while (playerChamberNum == random){
        random = (rand() % 5);
        currentChamber = chambers.at(random);
    }

    //Randomly select a cell from the chamber
    random = (rand() % (currentChamber->cells.size()));
    currentCell = currentChamber->cells.at(random);

    generateStairCase(currentCell);
}

void Floor::setPotions(){ //generate the potions
    int random;
    Chamber *currentChamber;
    Cell *currentCell;

    random = (rand() % 5);
    for (int i = 0; i < NUM_POTIONS; ++i){
        random = (rand() % 5);
        currentChamber = chambers.at(random);

        //Randomly select an unoccupied cell from the chamber
        random = (rand() % (currentChamber->cells.size()));
        currentCell = currentChamber->cells.at(random);
        while ((currentCell->isOccupied()) || (currentCell->getCellType() == Cell::Stairs)){
            random = (rand() % (currentChamber->cells.size()));
            currentCell = currentChamber->cells.at(random);
        }
        generatePotion(currentCell);
    }
}

void Floor::setGold(){ //generate the gold
    int random;
    Chamber *currentChamber;
    Cell *currentCell;

    random = (rand() % 5);
    for (int i = 0; i < NUM_GOLD; ++i){
        random = (rand() % 5);
        currentChamber = chambers.at(random);

        random = (rand() % (currentChamber->cells.size()));
        currentCell = currentChamber->cells.at(random);
        while ((currentCell->isOccupied()) || (currentCell->getCellType() == Cell::Stairs)){
            random = (rand() % (currentChamber->cells.size()));
            currentCell = currentChamber->cells.at(random);
        }
        generateGold(currentCell);
    }

}

void Floor::setEnemies(){ //generate the enemies
    int random;
    Chamber *currentChamber;
    Cell *currentCell;

    random = (rand() % 5);
    for (int i = 0; i < NUM_ENEMIES; ++i){
        random = (rand() % 5);
        currentChamber = chambers.at(random);

        random = (rand() % (currentChamber->cells.size()));
        currentCell = currentChamber->cells.at(random);
        while ((currentCell->isOccupied()) || (currentCell->getCellType() == Cell::Stairs)){
            random = (rand() % (currentChamber->cells.size()));
            currentCell = currentChamber->cells.at(random);
        }
        generateEnemy(currentCell);
    }
}

void Floor::generateFloor(){
    setPlayerStaircase();
    setPotions();
    setGold();
    setEnemies();
    spawnDragon();
    initialActionQueue();
}

void Floor::spawnDragon(){ //Spawn a dragon for each corresponding dragon hoard
    Cell *currentCell;
    bool dragonMatched = false;
    for (unsigned int i = 0; i < allCells.size(); ++i){
        for (unsigned int j = 0; j < allCells.at(i).size(); ++j){
            currentCell = allCells.at(i).at(j);
            if (currentCell->getCellSymbol() == '9'){
                dragonMatched = false;
                //We guarantee this cell has a dragon hoard
                floorDragonHoards.push_back(static_cast<DragonGold *>(floorItems[currentCell->getOccupiedId()]));
                for (int n = -1; n <= 1; ++n){
                    for (int m = -1; m <= 1; ++m){
                        currentCell = allCells.at(i + n).at(j + m);
                        if ((!currentCell->isOccupied()) && (!dragonMatched) && (currentCell->getCellType() == Cell::Floor)){
                            spawnDragonAt(i + n, j + m);
                            dragonMatched = true;
                        }
                    }
                }
            }
        }
    }

    matchDragonHoards();
}

void Floor::spawnDragonAt(int xPos, int yPos){
    Cell *currentCell = allCells.at(xPos).at(yPos);
    Dragon *newDragon = new Dragon(xPos, yPos, Character::generateId());
    int id = newDragon->getId();
    floorEnemies[id] = newDragon;
    floorDragons.push_back(newDragon);
    currentCell->setOccupation(true, false, false, id);
    currentCell->setCellSymbol('D');
    currentCell->notifyDisplay(*td);
}

void Floor::initialActionQueue(){ //Create our initial action queue
    Cell *currentCell;
    for (unsigned int i = 0; i < allCells.size(); ++i){
        for (unsigned int j = 0; j < allCells.at(i).size(); ++j){
            currentCell = allCells.at(i).at(j);
            if (currentCell->hasEnemy()){
                Enemy *enemy = floorEnemies[currentCell->getOccupiedId()];
                enemyActionQueue.push(enemy);
            }
        }
    }
}

void Floor::generateStairCase(Cell *currentCell){
    if (!currentCell->isOccupied()){
        currentCell->setOccupation(false, false, false);
        currentCell->setCellType(Cell::Stairs);
        currentCell->setCellSymbol('/');
        currentCell->notifyDisplay(*td);
    }
}

void Floor::generatePlayer(Cell *currentCell){
    Player *player = Player::getInstance();
    if (!currentCell->isOccupied()){
        currentCell->setOccupation(false, false, true, player->getId());
        currentCell->setCellSymbol('@');
        currentCell->notifyDisplay(*td);
        player->setPos(currentCell->getXPos(), currentCell->getYPos());
        startXPos = currentCell->getXPos();
        startYPos = currentCell->getYPos();
    }
}

void Floor::generateEnemy(Cell *currentCell){
    if (!currentCell->isOccupied()){
        EnemyFactory enFactory = EnemyFactory();
        Enemy *newEnemy = enFactory.getEnemy();
        int id = newEnemy->getId();
        newEnemy->setPos(currentCell->getXPos(), currentCell->getYPos());
        currentCell->setOccupation(true, false, false, id);
        currentCell->setCellSymbol(newEnemy->getSymbol());
        currentCell->notifyDisplay(*td);
        floorEnemies[id] = newEnemy;
    }
}

void Floor::generatePotion(Cell *currentCell){
    if (!currentCell->isOccupied()){
        ItemFactory itFactory = ItemFactory();
        Item *newItem = itFactory.getPotion();
        int id = newItem->getId();
        newItem->setPos(currentCell->getXPos(), currentCell->getYPos());
        currentCell->setOccupation(false, true, false, id);
        currentCell->setCellSymbol(newItem->getSymbol());
        currentCell->notifyDisplay(*td);
        floorItems[id] = newItem;
    }
}

void Floor::generateGold(Cell *currentCell){
    if (!currentCell->isOccupied()){
        ItemFactory itFactory = ItemFactory();
        Item *newItem = itFactory.getGold();
        int id = newItem->getId();
        newItem->setPos(currentCell->getXPos(), currentCell->getYPos());
        currentCell->setOccupation(false, true, false, id);
        currentCell->setCellSymbol(newItem->getSymbol());
        currentCell->notifyDisplay(*td);
        floorItems[id] = newItem;
    }
}

void Floor::updateState(){
    //Make our enemy action queue for proper ordering
    for (unsigned int i = 0; i < allCells.size(); ++i){
        for (unsigned int j = 0; j < allCells.at(i).size(); ++j){
            Cell *current = allCells.at(i).at(j);
            if (current->hasEnemy()){
                int enemyId = current->getOccupiedId();
                Enemy* nextEnemy = floorEnemies[enemyId];
                enemyActionQueue.push(nextEnemy);
            }
        }
    }
    while (!enemyActionQueue.empty()){
        Enemy* currentEnemy = enemyActionQueue.front();
        currentEnemy->update();
        enemyActionQueue.pop();
    }
}

int Floor::getStartXPos(){
    return startXPos;
}

int Floor::getStartYPos(){
    return startYPos;
}

TextDisplay* Floor::getTextDisplay(){
    return td;
}

ItemUseVisitor* Floor::getItemStatMonitor(){
    return itemStatMonitor;
}

void Floor::negateTempStats(){
    Player *player = Player::getInstance();
    player->alterAtk(-(itemStatMonitor->getTempAtkDelta()));
    player->alterDef(-(itemStatMonitor->getTempDefDelta()));
}

Cell* Floor::getCellAt(int xPos, int yPos){
    return allCells.at(xPos).at(yPos);
}
