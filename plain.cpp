#include "Plain.h"

Plain::Plain(){}
Plain::Plain(bool isExit, int index, vector<Object*> objects):Room(isExit, index, objects){}

void Plain::normalTrigger(Object* object){
    sleep(1);
    cout << "Welcome to Plain!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's state increases by 50." << endl;
    player->increaseStates(50, 50, 50, 50, 50, 0); 
    sleep(1);
    cout << "Plain has a gift for you" << endl;
    Item item("plainRice", 10, 10, 10, 10, 10, 0);    
    player->addItem(item);
    sleep(1);
};
void Plain::fortuneTrigger(Object* object){
    sleep(1);
    cout << "You are fortunate! There is a bottle of milk for you!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    player->addItem(Item("milk", 10, 10, 10, 10, 10, 0));
    sleep(1);
};
void Plain::triggerEnviron(Object* object){
    srand(time(0));
    normalTrigger(object);
    if (rand()%100 < 10){
        fortuneTrigger(object);
    }
    cout << "\n";
};