#include "Forest.h"

Forest::Forest(){}
Forest::Forest(bool isExit, int index, vector<Object*> objects):Room(isExit, index, objects){}

void Forest::normalTrigger(Object* object){
    sleep(1);
    cout << "Welcome to Forest!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's hunger value decreases by 20." << endl;
    player->increaseStates(0, 0, 0, -20, 0, 0); 
    sleep(1);
};
void Forest::bearTrigger(Object* object){
    sleep(1);
    cout << "Oops! You've encountered me! I'm the king of bears!" << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's state decreases by 50%." << endl;
    player->setState(0.5); 
    cout << "However, I have a gift for you haha" << endl;
    Item item("fish", 30, 30, 30, 30, 30, 0);    
    player->addItem(item);
    sleep(1);
};
void Forest::tigerTrigger(Object* object){
    sleep(1);
    cout << "How dare you come here? I'm the tiger king." << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's state decreases by 90%." << endl;
    player->setState(0.1);
    sleep(1);
};
void Forest::lakeTrigger(Object* object){
    sleep(1);
    cout << "God bless you! Here's a lake for you to replenish water." << endl;
    sleep(1);
    Player* player = (Player*) object;
    cout << "Player's thirst value increases by 50." << endl;
    player->increaseStates(0, 0, 0, 0, 50, 0); 
    sleep(1);
}
void Forest::triggerEnviron(Object* object){
    srand(time(0));
    normalTrigger(object);
    if (rand()%100 < 10){
        bearTrigger(object);
    }
    if (rand()%100 < 10){
        tigerTrigger(object);
    }
    if (rand()%100 < 10){
        lakeTrigger(object);
    }
    cout << "\n";
};