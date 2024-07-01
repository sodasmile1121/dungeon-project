#include "Dungeon.h"

Dungeon::Dungeon(){}
Dungeon::~Dungeon(){
    for (Room* room:rooms){
        for (Object* object:room->getObjects()){
            if(object->getTag() == "NPC"){
                delete (NPC*) object;
            }
            else if (object->getTag() == "Monster"){
                delete (Monster*) object;
            }
            else if (object->getTag() == "Chest"){
                delete (Chest*) object;
            }
        }
    }
}
void Dungeon::createPlayer(){
    string name;
    cout << "Plese enter your name: " << endl;
    cin >> name;
    player = Player(name);
    cout << ">>> The player has been created successfully" << endl;
    sleep(1);
}
void Dungeon::createMap(){
    NPC* npc1 = new NPC("Amy", "I'm NPC Amy\n", {Item("milk", 10, 10, 10, 10, 10, 0), Item("water", 20, 20, 20, 20, 100, 30), Item("cola", -30, -30, -30, -30, -30, 0)});
    NPC* npc2 = new NPC("Bob", "I'm NPC Bob\n", {Item("bread", -40, 40, 40, 40, 40, 0), Item("burger", -50, 50, 50, 50, 50, 0), Item("cookie", 60, 60, 60, 60, 60, 0)});
    NPC* npc3 = new NPC("Caro", "I'm NPC Caro\n", {Item("rice", 7, 7, 7, 7, 7, 0), Item("noodle", 8, 8, 8, 8, 8, 0), Item("dish", 9, 9, 9, 9, 9, 0)});
    NPC* npc4 = new NPC("David", "I'm NPC David\n", {Item("vegetable", 10, 10, 10, 10, 10, 20), Item("cake", 20, 20, 20, 20, 20, 0), Item("fruit", 30, 30, 30, 30, 30, 20)});
    NPC* npc5 = new NPC("Eason", "I'm NPC Eason\n", {Item("meal", 40, 40, 40, 40, 40, 0), Item("grape", 50, 50, 50, 50, 50, 0), Item("apple", 60, 60, 60, 60, 60, 0)});
    NPC* npc6 = new NPC("Frank", "I'm NPC Frank\n", {Item("meat", -7, 7, 7, 7, 7, 0), Item("orange", 8, 8, 8, 8, 8, 0), Item("pineapple", 9, 9, 9, 9, 9, 0)});
    NPC* npc7 = new NPC("Gino", "I'm NPC Gino\n", {Item("watermelon", 10, 10, 10, 10, 100, 0), Item("kiwi", 20, 20, 20, 20, 20, 0), Item("pan", 30, 30, 30, 30, 30, 0)});
    NPC* npc8 = new NPC("Hank", "I'm NPC Hank\n", {Item("drink", -40, -40, 40, 40, -40, 0), Item("chicken", 50, 50, 50, 50, 50, 0), Item("pork", -60, 60, 60, -60, -60, 0)});
    NPC* npc9 = new NPC("Jason", "I'm NPC Jason\n", {Item("beef", 70, 7, 7, 7, 7, 0), Item("egg", 8, 8, 8, 8, 8, 20), Item("lakewater", 90, 90, 9, 9, 100, 10)});
    Monster* monster1 = new Monster("Wayne", "socks", 8, 8, 130, 130, 5, 3);
    Monster* monster2 = new Monster("Kitty");
    Monster* monster3 = new Monster("Peterson");
    Monster* monster4 = new Monster("Katherine");
    Monster* monster5 = new Monster("Cherry");
    Chest* chest1 = new Chest("Asia", "Welcome to Asian chest", Item("sashimi", 80, 10, 10, 10, 10, 80));
    Chest* chest2 = new Chest("American", "Welcome to Ameerican chest", Item("hotDog", -80, 0, 0, 0, 0, -80));
    Chest* chest3 = new Chest("Africa", "Welcome to Africa chest", Item("lion", 90, 50, 50, 0, 0, 90));
    rooms = {
            new Desert(false, 1, {&player, npc1, monster1}), 
            new Forest(false, 2, {npc2, npc3}), 
            new Swamp(false, 3, {chest1, chest2}),
            new Forest(false, 4, {npc4, npc5, monster2}), 
            new Desert(false, 5, {monster3, monster4}), 
            new Forest(false, 6, {npc6}), 
            new Desert(false, 7, {npc7, monster5, chest3}),
            new Swamp(false, 8, {npc8, npc9}),
            new Swamp(true, 9, {}),
        };
    player.setCurrentRoom(rooms[0]);
    player.setPreviousRoom(NULL);
    rooms[0]->setRightRoom(rooms[1]);
    rooms[0]->setUpRoom(rooms[3]);
    rooms[1]->setLeftRoom(rooms[0]);
    rooms[1]->setUpRoom(rooms[4]);
    rooms[1]->setRightRoom(rooms[2]);
    rooms[2]->setLeftRoom(rooms[1]);
    rooms[2]->setUpRoom(rooms[5]);
    rooms[3]->setDownRoom(rooms[0]);
    rooms[3]->setRightRoom(rooms[4]);
    rooms[3]->setUpRoom(rooms[6]);
    rooms[4]->setLeftRoom(rooms[3]);
    rooms[4]->setDownRoom(rooms[1]);
    rooms[4]->setRightRoom(rooms[5]);
    rooms[4]->setUpRoom(rooms[7]);
    rooms[5]->setLeftRoom(rooms[4]);
    rooms[5]->setDownRoom(rooms[2]);
    rooms[5]->setUpRoom(rooms[8]);
    rooms[6]->setDownRoom(rooms[3]);
    rooms[6]->setRightRoom(rooms[7]);
    rooms[7]->setLeftRoom(rooms[6]);
    rooms[7]->setDownRoom(rooms[4]);
    rooms[7]->setRightRoom(rooms[8]);
    rooms[8]->setLeftRoom(rooms[7]);
    rooms[8]->setDownRoom(rooms[5]);

    cout << ">>> The map has been created successfully" << endl;
    sleep(1);
    cout << ">>> Player's info" << endl;
    player.triggerEvent(&player);
    sleep(1);
}

void Dungeon::handleMovement(){
    char action;
    cout << "Where do you want to go?" << endl;
    cout << "A. go up\n" << "B. go down\n" << "C. go left\n" << "D. go right" << endl;
    cin >> action;

    while ((action == 'A' && player.getCurrentRoom()->getUpRoom() == nullptr) || 
        (action == 'B' && player.getCurrentRoom()->getDownRoom() == nullptr) || 
        (action == 'C' && player.getCurrentRoom()->getLeftRoom() == nullptr) ||
        (action == 'D' && player.getCurrentRoom()->getRightRoom() == nullptr)){
        cout << "There is no room. Please type in another direction." << endl;
        cin >> action;
    } // Illegal Movement Handling

    player.setPreviousRoom(player.getCurrentRoom());
    switch (action){
        case 'A':
            player.setCurrentRoom(player.getCurrentRoom()->getUpRoom());
            break;
        case 'B':
            player.setCurrentRoom(player.getCurrentRoom()->getDownRoom()); 
            break;     
        case 'C':
            player.setCurrentRoom(player.getCurrentRoom()->getLeftRoom());
            break;
        case 'D':
            player.setCurrentRoom(player.getCurrentRoom()->getRightRoom());
            break;
        default:
            break;
    }
}

void Dungeon::handleEvent(Object* object){
    object->triggerEvent(&player);
}

void Dungeon::chooseAction(){
    while(true){
        Room* currentRoom = player.getCurrentRoom();
        currentRoom->triggerEnviron(&player); 
        if (checkGameLogic()){break;}
        vector <Object*> objects = player.getCurrentRoom()->getObjects();
        cout << "What do you want to do?" << endl;
        cout << "A. Move" << endl;

        objects.erase(remove_if(objects.begin(), objects.end(), 
            [](Object* object){return object->getTag() == "Player";}), objects.end()); 
        objects.insert(objects.begin(), &player); // 將Player移到該房間的第一個物件

        char initialChar = 'B';
        for (Object* object: objects){
            cout << initialChar << ". ";
            ((GameCharacter*)object)->objectScript();
            initialChar += 1;
        }

        char action;
        cin >> action;
        while (action < 'A' || action >= initialChar){
            cout << "Please type in A~" << (char)(initialChar-1) << " only" << endl;
            cin >> action;
        }

        switch (action)
        {
            case 'A':
                handleMovement();
                break;
            default:
                handleEvent(objects[action-'B']);
                break;
        }

        player.checkHunger();
        player.checkThirst();
        player.checkPoison();
        if (checkGameLogic()){break;}
        if (randomDungeon()){break;}
    }
}

void Dungeon::startGame(){
    cout << "Are you ready for adventure?" << endl;
    sleep(1);
    this->createPlayer();
    this->createMap();
    sleep(1);
}

int Dungeon::randomDungeon(){
    cout << "See whether dungeon has special events" << endl;
    srand(time(0));
    if (rand()%100 < 5){
        cout << "Dungeon special gift: you will be sent to the exit room" << endl;
        player.setCurrentRoom(rooms.back());
        return checkGameLogic();
    }
    sleep(1);
    if (rand()%100 < 5){
        cout << "Dungeon has crashed: you will be sent to the first room" << endl;
        player.setCurrentRoom(rooms[0]);
        return checkGameLogic();
    } 
    cout << "No special event\n" << endl;
    return 0;
}

bool Dungeon::checkGameLogic(){
    if (player.getCurrentHealth() <= 0){
        cout << "Sorry, your health value is <= 0" << endl;
        cout << "You lose!!" << endl;
        return 1;
    }
    else if (player.getCurrentHealth() > 0 && player.getCurrentRoom()->getIsExit() == 1){
        cout << "Congrats! You have reached the exit room" << endl;
        cout << "You win!!" << endl;
        return 1;
    }
    else if (player.getLongevity() >= 100){
        cout << "Congrats! Your longevity is >= 100" << endl;
        cout << "You win!!" << endl;
        return 1;        
    }
    return 0;
}
void Dungeon::runDungeon(){
    cout << "Adventure starts now" << endl;
    sleep(1);
    chooseAction();
}