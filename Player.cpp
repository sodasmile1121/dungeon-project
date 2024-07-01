#include "Player.h"

Player::Player(){}
Player::Player(string name) : GameCharacter(name, 100, 100, 100, 100) {
    this->setTag("Player");
    this->hunger = 100;
    this->thirst = 100;
    this->longevity = 0;
}

void Player::addItem(Item item){
    inventory.push_back(item);
    this->increaseStates(item.getHealth(), item.getAttack(), item.getDefense(), item.getHunger(), item.getThirst(), item.getLongevity());
    cout << ">>> Adding item " << item.getName() << endl; 
    sleep(1);
    cout << "increasing state" << endl;
    cout << "health: " << item.getHealth() << endl;
    cout << "attack: " << item.getAttack() << endl;
    cout << "defense: " << item.getDefense() << endl;
    cout << "hunger: " << item.getHunger() << endl;
    cout << "thirst: " << item.getThirst() << endl;
    cout << "longevity: " << item.getLongevity() << endl;
    sleep(1);
}

void Player::addPoison(Poison poison){
    cout << ">>> Adding poison: " << poison.getName() << endl;
    poisons.push_back(poison);
    sleep(1);
    cout << "poison's info" << endl;
    cout << "toxicity: " << poison.getToxicity() << endl;
    cout << "duration: " << poison.getDuration() << endl;
    sleep(1);
}

void Player::popPoison(Poison poison){
    poisons.erase(poisons.begin());
}

void Player::increaseStates(int currentHealth, int attack, int defense, int hunger, int thirst, int longevity){
    this->setCurrentHealth(this->getCurrentHealth()+currentHealth);
    this->setAttack(this->getAttack()+attack);
    this->setDefense(this->getDefense()+defense);
    this->setHunger(this->getHunger()+hunger);
    this->setThirst(this->getThirst()+thirst);
    this->setLongevity(this->getLongevity()+longevity);
}

void Player::changeRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}

void Player::triggerEvent(Object*){
    cout << "Status: \n" << this->getName() << "\n" <<
    ">CurrentRoom: " << this->getCurrentRoom()->getIndex() << "\n" <<
    ">Health: " << this->getCurrentHealth() << "/" << this->getMaxHealth() << "\n" <<
    ">Attack: " << this->getAttack() << "\n" <<
    ">Defense: " << this->getDefense() << "\n" <<
    ">Hunger: " << this->getHunger() << "\n" <<
    ">Thirst: " << this->getThirst() << "\n" <<
    ">Longevity: " << this->getLongevity() << "\n" <<
    ">Items:\n"; this->showItem();
    cout << ">Poisons:\n"; this->showPoison();
    return;
};

void Player::objectScript(){
    cout << "Check Status" << endl;  
}

void Player::setCurrentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}

void Player::setPreviousRoom(Room* previousRoom){
    this->previousRoom = previousRoom;
}

void Player::setInventory(vector<Item> inventory){
    this->inventory = inventory;
}

void Player::setPoison(vector<Poison> poisons){
    this->poisons = poisons;
}

void Player::setThirst(int thirst){
    this->thirst = thirst;
}

void Player::setHunger(int hunger){
    this->hunger = hunger;
}

void Player::setLongevity(int longevity){
    this->longevity = longevity;
}

void Player::setState(float ratio){
    this->setCurrentHealth(this->getCurrentHealth()*ratio);
    this->setAttack(this->getAttack()*ratio);
    this->setDefense(this->getDefense()*ratio);
    this->setHunger(this->getHunger()*ratio);
    this->setThirst(this->getThirst()*ratio);
}

void Player::checkHunger(){
    sleep(1);
    cout << ">>> checking hunger status" << endl;
    sleep(1);
    if (hunger < 0){
        cout << "hunger value <0, decreasing health by 10" << endl;
        this->setCurrentHealth(this->getCurrentHealth()-10);
    }
    else{
        cout << "it's fine" << endl;
    }
}

void Player::checkThirst(){
    sleep(1);
    cout << ">>> checking thirst status" << endl;
    sleep(1);
    if (thirst < 0){
        cout << "thirst value < 0, decreasing health by 10" << endl;
        this->setCurrentHealth(this->getCurrentHealth()-10);
        sleep(1);
        cout << "thirst value < 0, decreasing defense by 50" << endl;
        this->setDefense(this->getDefense()-50); // debuff
        sleep(1);
    }
    else{
        cout << "it's fine" << endl;
    }
}

void Player::checkPoison(){
    sleep(1);
    cout << ">>> checking poisons" << endl;
    if (poisons.size() == 0){
        cout << "it's empty" << endl;
    }
    else{
        cout << "There are " << poisons.size() << " poisons" << endl;
        int antidoteCount=0;
        for (int i=0; i<inventory.size(); i++){
            if (inventory[i].getName() == "milk"){
                antidoteCount++;
            }
        }
        cout << ">>> checking antidote" << endl;
        cout << "antidote count is " << antidoteCount << endl;
        sleep(1);
        cout << "poisons count is " << poisons.size() << endl;
        sleep(1);
        if (antidoteCount >= poisons.size()){
            cout << "clearing all poisons" << endl;
            clearPoison();
            sleep(1);
        }
        else{
            for (int i=0; i<antidoteCount; i++){
                cout << "erasing first poison: " << poisons[i].getName() << endl;
                poisons.erase(poisons.begin());
                sleep(1);
            }
        }

        cout << ">>> checking remaining poisons" << endl;
        for (int i=0; i<poisons.size(); i++){
            sleep(1);
            cout << "decreasing health by toxicity: " << poisons[i].getToxicity() << endl;
            this->setCurrentHealth(this->getCurrentHealth()-poisons[i].getToxicity());
            poisons[i].setDuration(poisons[i].getDuration()-1);
            if (poisons[i].getDuration() == 0){ // if the poison's duration is expired, then remove it
                sleep(1);
                cout << "erasing poison " << poisons[i].getName() << " which is expired"<< endl;
                poisons.erase(poisons.begin() + i);
                i--;
                sleep(1);
            }
        }
    }
    cout << "\n";
}

void Player::clearPoison(){
    poisons.clear();
}

Room* Player::getCurrentRoom(){
    return this->currentRoom;
}

Room* Player::getPreviousRoom(){
    return this->previousRoom;
}

vector<Item> Player::getInventory(){
    return this->inventory;
}

vector<Poison> Player::getPoison(){
    return this->poisons;
}

int Player::getThirst(){
    return this->thirst;
}

int Player::getHunger(){
    return this->hunger;
}

int Player::getLongevity(){
    return this->longevity;
}

void Player::showItem(){
    if (inventory.size() == 0){
        cout << "empty" << endl;
    }
    else{
        for (Item item: inventory){
            cout << item.getName() << endl;
        }
    }
}

void Player::showPoison(){
    if (poisons.size() == 0){
        cout << "empty\n" << endl;
    }
    else{
        for (Poison poison: poisons){
            cout << poison.getName() << endl;
            cout << "toxicity: " << poison.getToxicity() << endl;
            cout << "duration: " << poison.getDuration() << endl;
        }
    }
}
