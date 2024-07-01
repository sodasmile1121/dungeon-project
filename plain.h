#ifndef PLAIN_H_INCLUDED
#define PLAIN_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Room.h"
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"

using namespace std;

class Plain: public Room
{ 
public:
    Plain();
    Plain(bool, int, vector<Object*>);
    void normalTrigger(Object*);
    void fortuneTrigger(Object*);
    void triggerEnviron(Object*);
};

#endif 