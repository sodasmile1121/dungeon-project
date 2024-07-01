#include "Poison.h"
#include "Player.h"

Poison::Poison(){}
Poison::Poison(string name, int toxicity, int duration):Object(name, "Poison"){
    this->toxicity = toxicity;
    this->duration = duration;
}

void Poison::triggerEvent(Object* object){
    Player* player = (Player*) object;
    player->addPoison(*this);
    player->getCurrentRoom()->popObject(this);
    return;
}

int Poison::getToxicity(){
    return this->toxicity;
}

int Poison::getDuration(){
    return this->duration;
}

void Poison::setToxicity(int toxicity){
    this->toxicity = toxicity;
}

void Poison::setDuration(int duration){
    this->duration = duration;
}