#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
private:
    string name;
    string tag;
public:
    Object();
    Object(string,string);
    virtual void triggerEvent(Object*) = 0;
    void setName(string);
    void setTag(string);
    string getName();
    string getTag();
};

#endif

