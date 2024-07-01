#include "Item.h"
#include "Player.h"

Item::Item():Object(){}
Item::Item(string name, int health, int attack, int defense, int hunger, int thirst, int longevity):Object(name, "Item"){
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->hunger = hunger;
    this->thirst = thirst;
    this->longevity = longevity;
}

void Item::triggerEvent(Object* object){
    Player* player = (Player*) object;
    player->addItem(*this);
    player->increaseStates(this->getHealth(), this->getAttack(), 
        this->getDefense(), this->getHunger(), this->getThirst(), this->getLongevity());
    vector <Object*> objects = player->getCurrentRoom()->getObjects();
    objects.erase(remove(objects.begin(), objects.end(), this), objects.end());
    player->getCurrentRoom()->setObjects(objects);
    return;
}

int Item::getHealth(){
    return health;
}
int Item::getAttack(){
    return attack;
}
int Item::getDefense(){
    return defense;
}
int Item::getHunger(){
    return hunger;
}
int Item::getThirst(){
    return thirst;
}
int Item::getLongevity(){
    return longevity;
}
void Item::setHealth(int health){
    this->health = health;
}
void Item::setAttack(int attack){
    this->attack = attack;
}
void Item::setDefense(int defense){
    this->defense = defense;
}
void Item::setHunger(int hunger){
    this->hunger = hunger;
}
void Item::setThirst(int thirst){
    this->thirst = thirst;
}
void Item::setLongevity(int longevity){
    this->longevity = longevity;
}