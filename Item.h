#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

class Item: public Object
{
private:
    int health, attack, defense, hunger, thirst, longevity;
public:
    Item();
    Item(string, int, int, int, int, int, int);
    void triggerEvent(Object*);
    int getHealth();
    int getAttack();
    int getDefense();
    int getHunger();
    int getThirst();
    int getLongevity();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setHunger(int);
    void setThirst(int);
    void setLongevity(int);
};

#endif // ITEM_H_INCLUDED