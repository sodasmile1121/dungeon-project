#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Object.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class Chest: public GameCharacter
{
private:
    string script;
    Item item;
public:
    Chest();
    Chest(string, string, Item);
    void objectScript();
    void showItem();        
    void triggerEvent(Object*);

    void setScript(string);
    void setItem(Item);
    string getScript();
    Item getItem();
};

#endif 