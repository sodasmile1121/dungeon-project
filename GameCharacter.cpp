#include "GameCharacter.h"

GameCharacter::GameCharacter(){}
GameCharacter::GameCharacter(string name, int maxHealth, int currentHealth, int attack, int defense):Object(name, "GameCharacter"){
    this->maxHealth = maxHealth;
    this->currentHealth = currentHealth;
    this->attack = attack;
    this->defense = defense;
}

void GameCharacter::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}
void GameCharacter::setCurrentHealth(int currentHealth){
    this->currentHealth = currentHealth;
}
void GameCharacter::setAttack(int attack){
    this->attack = attack;
}
void GameCharacter::setDefense(int defense){
    this->defense = defense;
}
int GameCharacter::getMaxHealth(){
    return this->maxHealth;
}
int GameCharacter::getCurrentHealth(){
    return this->currentHealth;
}
int GameCharacter::getAttack(){
    return this->attack;
}
int GameCharacter::getDefense(){
    return this->defense;
}