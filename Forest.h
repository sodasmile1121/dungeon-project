#ifndef FOREST_H_INCLUDED
#define FOREST_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Room.h"
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Forest: public Room
{ 
public:
    Forest();
    Forest(bool, int, vector<Object*>);
    void normalTrigger(Object*);
    void bearTrigger(Object*);
    void tigerTrigger(Object*);
    void lakeTrigger(Object*);
    void triggerEnviron(Object*);
};

#endif 