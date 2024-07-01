#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "GameCharacter.h"
#include "Player.h"
#include "Poison.h"

using namespace std;

class Monster: public GameCharacter
{
private:
    Poison poison;
public:
    Monster();
    Monster(string);
    Monster(string, string, int, int, int, int, int, int);
    void objectScript();
    void increaseStates(int,int,int);
    void triggerEvent(Object*);
};


#endif