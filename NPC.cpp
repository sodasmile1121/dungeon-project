#include "NPC.h"

NPC::NPC(){}
NPC::NPC(string name, string script, vector<Item> commodity):GameCharacter(name, 0, 0, 0, 0){
    this->setTag("NPC");
    this->script = script;
    this->commodity = commodity;
}

void NPC::objectScript(){
    cout << "Trade with NPC - " << this->getName() << endl;  
}

void NPC::listCommodity(){
    cout << "Here's my commodity list. Type in the index of the item that you want or type in 0 to do nothing" << endl;
    if (commodity.size() == 0){
        cout << "Sorry, it is empty now" << endl;
    }
    else{
        for (int i=0; i<commodity.size(); i++){
            cout << i+1 << ". " << commodity[i].getName() << endl;
        }  
    } 
}

void NPC::triggerEvent(Object* object){
    Player* player = (Player*)object;
    cout << this->getScript();
    this->listCommodity();

    if (commodity.size() == 0){
        return;
    }
    else{
        int chooseIndex;
        cin >> chooseIndex;
        if (chooseIndex!=0){ // 如果0的話代表不想交易
            player->addItem(commodity[chooseIndex-1]);
            commodity.erase(commodity.begin()+chooseIndex-1);
        }
        return;
    }
}

void NPC::setScript(string script){
    this->script = script;
}

void NPC::setCommodity(vector<Item> commodity){
    this->commodity = commodity;
}

string NPC::getScript(){
    return this->script;
}

vector<Item> NPC::getCommodity(){
    return this->commodity;
}
