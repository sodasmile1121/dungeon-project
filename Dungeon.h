#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <unistd.h>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Chest.h"
#include "Room.h"
#include "Desert.h"
#include "Forest.h"
#include "Swamp.h"

using namespace std;

class Dungeon{
private:
    Player player;
    vector<Room*> rooms;
public:
    Dungeon();
    ~Dungeon();
    void createPlayer(); 
    void createMap();
    void handleMovement();
    void handleEvent(Object*);
    void startGame();
    void chooseAction(); 
    int randomDungeon();
    bool checkGameLogic();
    void runDungeon();
};

#endif 