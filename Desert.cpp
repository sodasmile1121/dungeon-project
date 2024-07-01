#include "Desert.h"

Desert::Desert(){}
Desert::Desert(bool isExit, int index, vector<Object*> objects):Room(isExit, index, objects){}

void Desert::normalTrigger(Object* object){
    sleep(1);
    cout << "Welcome to Desert!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's thirst value decreases by 20." << endl;
    player->increaseStates(0, 0, 0, 0, -20, 0); 
    sleep(1);
};
void Desert::sandStormTrigger(Object* object){
    sleep(1);
    cout << "Sandstorm is coming!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's hunger value decreases by 20, and player's thirst value decreases by 50." << endl;
    player->increaseStates(0, 0, 0, -20, -50, 0); 
    sleep(1);
};
void Desert::oasisTrigger(Object* object){
    sleep(1);
    cout << "Here is oasis!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's thirst value increases by 50." << endl;
    player->increaseStates(0, 0, 0, 0, 50, 0); 
    sleep(1);
};
void Desert::triggerEnviron(Object* object){
    srand(time(0));
    normalTrigger(object);
    if (rand()%100 < 10){
        sandStormTrigger(object);
    }
    if (rand()%100 < 10){
        oasisTrigger(object);
    }
    cout << "\n";
};