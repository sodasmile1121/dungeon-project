#ifndef DESERT_H_INCLUDED
#define DESERT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Room.h"
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Desert: public Room
{ 
public:
    Desert();
    Desert(bool, int, vector<Object*>);
    void normalTrigger(Object*);
    void sandStormTrigger(Object*);
    void oasisTrigger(Object*);
    void triggerEnviron(Object*);
};

#endif 