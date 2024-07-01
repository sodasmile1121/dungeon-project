#ifndef POISON_H_INCLUDED
#define POISON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
using namespace std;

class Poison: public Object
{
private:
    int toxicity;
    int duration;
public:
    Poison();
    Poison(string, int, int);
    void triggerEvent(Object*);
    int getToxicity();
    int getDuration();
    void setToxicity(int);
    void setDuration(int);

};

#endif