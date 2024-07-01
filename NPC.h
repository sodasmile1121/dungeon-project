#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item> commodity;
public:
    NPC();
    NPC(string, string, vector<Item>);
    void objectScript();
    void listCommodity(); 
    void triggerEvent(Object*);

    void setScript(string);
    void setCommodity(vector<Item>);
    string getScript();
    vector<Item> getCommodity();
};


#endif 
