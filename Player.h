#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Poison.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    vector<Poison> poisons;
    int hunger;
    int thirst;
    int longevity;
public:
    Player();
    Player(string); 
    void addItem(Item);
    void addPoison(Poison);
    void popPoison(Poison);
    void increaseStates(int,int,int,int,int,int);
    void changeRoom(Room*);
    void objectScript();
    void triggerEvent(Object*);

    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    void setPoison(vector<Poison>);
    void setThirst(int);
    void setHunger(int);
    void setLongevity(int);
    void setState(float);
    void checkHunger();
    void checkThirst();
    void checkPoison();
    void clearPoison();
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
    vector<Poison> getPoison();
    int getHunger();
    int getThirst();
    int getLongevity();

    void showItem();
    void showPoison();
};

#endif 