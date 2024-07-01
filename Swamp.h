#ifndef SWAMP_H_INCLUDED
#define SWAMP_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Room.h"
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Swamp: public Room
{ 
public:
    Swamp();
    Swamp(bool, int, vector<Object*>);
    void normalTrigger(Object*);
    void deadlyTrigger(Object*);
    void triggerEnviron(Object*);
};

#endif 