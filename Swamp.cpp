#include "Swamp.h"

Swamp::Swamp(){}
Swamp::Swamp(bool isExit, int index, vector<Object*> objects):Room(isExit, index, objects){}

void Swamp::normalTrigger(Object* object){
    sleep(1);
    cout << "Welcome to Swamp!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's state decreases by 30" << endl;
    player->increaseStates(-30, -30, -30, -30, -30, 0); 
    sleep(1);
    cout << "Swamp has a poison for you" << endl;
    Poison poison("bacteriaLiquid", 10, 10);    
    player->addPoison(poison);
    sleep(1);
};
void Swamp::deadlyTrigger(Object* object){
    sleep(1);
    cout << "You have been trapped in swamp" << endl;
    sleep(1);
    cout << "Player's health decreases to 0" << endl;
    sleep(1);
    Player* player = (Player*) object;
    player->setCurrentHealth(0);
    sleep(1);
};
void Swamp::triggerEnviron(Object* object){
    srand(time(0));
    normalTrigger(object);
    if (rand()%100 < 10){
        deadlyTrigger(object);
    }
    cout << "\n";
};