#include "Monster.h"
#define ENERGYSPENT 30

Monster::Monster(){}
Monster::Monster(string name):GameCharacter(name, 100, 100, 100, 100){
    this->setTag("Monster");
}
Monster::Monster(string name, string poisonName, int maxHealth, int currentHealth, int attack, int defense, int toxicity, int duration):GameCharacter(name, maxHealth, currentHealth, attack, defense){
    this->setTag("Monster");
    poison.setName(poisonName);
    poison.setToxicity(toxicity);
    poison.setDuration(duration);
}

void Monster::objectScript(){
    cout << "Fight with Monster - " << this->getName() << endl;  
}

void Monster::increaseStates(int currentHealth, int attack, int defense){
    this->setCurrentHealth(this->getCurrentHealth()+currentHealth);
    this->setAttack(this->getAttack()+attack);
    this->setDefense(this->getDefense()+defense);
}

void Monster::triggerEvent(Object* object){ // 可以pop掉player所有的毒藥，數據值會轉移至player數據值
    Player* player = (Player*) object;
    int monsterHealth = this->getCurrentHealth();
    int monsterAttack = this->getAttack();
    int monsterDefense = this->getDefense();

    bool playerState = 1;
    bool monsterState = 1;
    while (playerState && monsterState){
        sleep(1);
        cout << "The fight would only be continueing when each side's health, attack, defense > 0" << endl;
        sleep(1);
        cout << "This is the info of " << this->getName() << endl;
        sleep(1);
        cout << "Monster: " << this->getCurrentHealth() << ", " << this->getAttack() << ", " << this->getDefense() << endl;
        sleep(1);
        cout << "Do you want to retreat(R), fight(F) or defense(D)." << endl;
        char action;
        cin >> action;
        while (action != 'R' && action != 'F' && action != 'D'){
            cout << "Please type in R, F, or D only" << endl;
            cin >> action;
        }
        Room* currentRoom = player->getCurrentRoom();
        switch (action)
        {
            case 'R':
                if (player->getPreviousRoom() != nullptr){
                    player->setCurrentRoom(player->getPreviousRoom());
                    player->setPreviousRoom(currentRoom);
                }
                else{
                    cout << "Since you are in Room 1 , so you will remain in the same room" << endl;
                    sleep(1);
                }
                break;
            case 'F':
                cout << "Player's health and attack decrease by 30" << endl;
                player->increaseStates(-ENERGYSPENT, -ENERGYSPENT, 0, 0, 0, 0); 
                sleep(1);
                cout << "Monster's health and defense decrease by 30" << endl;
                this->increaseStates(-ENERGYSPENT, 0, -ENERGYSPENT); 
                sleep(1); 
                cout << "Player and Monster's info: " << "health, attack, defense" << endl;
                sleep(1);
                cout << "Player: " << player->getCurrentHealth() << ", " << player->getAttack() << ", " << player->getDefense() << endl;
                sleep(1);
                cout << "Monster: " << this->getCurrentHealth() << ", " << this->getAttack() << ", " << this->getDefense() << endl;
                sleep(1);
                break;
            case 'D':
                cout << "Player's health and defense decrease by 30" << endl;
                player->increaseStates(-ENERGYSPENT, 0, -ENERGYSPENT, 0, 0, 0); 
                sleep(1);
                cout << "Monster's health and attack decrease by 30" << endl;
                this->increaseStates(-ENERGYSPENT, -ENERGYSPENT, 0); 
                sleep(1); 
                cout << "Player and Monster's info: " << "health, attack, defense" << endl;
                sleep(1);
                cout << "Player: " << player->getCurrentHealth() << ", " << player->getAttack() << ", " << player->getDefense() << endl;
                sleep(1);
                cout << "Monster: " << this->getCurrentHealth() << ", " << this->getAttack() << ", " << this->getDefense() << endl;
                sleep(1);
                break;
            default:
                break;
        }
        if (action == 'R'){
            break;
        }
        else{
            playerState = player->getCurrentHealth() >0 && player->getAttack() > 0 && player->getDefense() > 0;
            monsterState = this->getCurrentHealth() >0 && this->getAttack() > 0 && this->getDefense() > 0;
        }
    }
    
    if (playerState && !monsterState){
        sleep(1);
        cout << ">>> You've beaten the monster." << endl;
        sleep(1);
        cout << this->getName() << " was dead" << endl;
        player->getCurrentRoom()->popObject(this);
        sleep(1);
        cout << "clearing all poisons" << endl;
        player->clearPoison();
        sleep(1);
        cout << "increasing states" << endl;
        sleep(1);
        player->increaseStates(monsterHealth, monsterAttack, monsterDefense, 0, 0, 20);
        player->triggerEvent(player);
        sleep(1);
        return; 
    }
    else if (!playerState && monsterState){
        sleep(1);
        cout << ">>> You've been beaten by monster " << this->getName() << endl;
        sleep(1);
        player->addPoison(poison);
        sleep(1);
        return;
    }
    else{
        sleep(1);
        cout << ">>> No winner and loser" << endl;
        sleep(1);
    }
    return;
}