#include "Chest.h"

Chest::Chest(){}
Chest::Chest(string name, string script, Item item):GameCharacter(name, 0, 0, 0, 0){
    this->setTag("Chest");
    this->script = script;
    this->item = item;
}

void Chest::objectScript(){
    cout << "Open the chest - " << this->getName() << endl;  
}

void Chest::showItem(){
    cout << "Here's my item. Please enter Y to obtain or N to do nothing." << endl;
    sleep(1);
    if (item.getName() == "Nope"){
        cout << "Sorry, it is already be exchanged" << endl;
    }
    else{
        cout << " - " << item.getName() << endl;
    } 
}

void Chest::triggerEvent(Object* object){
    Player* player = (Player*)object;
    cout << this->getScript();
    this->showItem();

    if (item.getName() == "Nope"){
        return ;
    }
    else{
        char action;
        cin >> action;
        while (action != 'Y' && action != 'N'){
            cout << "Please type in Y or N only" << endl;
            cin >> action;
        }
        if (action == 'Y'){ 
            player->addItem(item);
            item.setName("Nope");
        }
        return;
    }
}

void Chest::setScript(string script){
    this->script = script;
}

void Chest::setItem(Item item){
    this->item = item;
}

string Chest::getScript(){
    return this->script;
}

Item Chest::getItem(){
    return item;
}