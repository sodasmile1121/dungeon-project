#include "Room.h"

Room::Room(){}
Room::Room(bool isExit, int index, vector<Object*> objects){
    this->isExit = isExit;
    this->index = index;
    this->objects = objects;
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
}

void Room::popObject(Object* object){
    for (int i=0; i<objects.size(); i++){
        if (objects[i] == object){
            objects.erase(objects.begin() + i);
        }
    }
}

void Room::setUpRoom(Room* upRoom){
    this->upRoom = upRoom;
}
void Room::setDownRoom(Room* downRoom){
    this->downRoom = downRoom;
}
void Room::setLeftRoom(Room* leftRoom){
    this->leftRoom = leftRoom;
}
void Room::setRightRoom(Room* rightRoom){
    this->rightRoom = rightRoom;
}
void Room::setIsExit(bool isExit){
    this->isExit = isExit;
}
void Room::setIndex(int index){
    this->index = index;
}
void Room::setObjects(vector<Object*> objects){
    this->objects = objects;
}
bool Room::getIsExit(){
    return this->isExit;
}
int Room::getIndex(){
    return this->index;
}
vector<Object*> Room::getObjects(){
    return this->objects;
}
Room* Room::getUpRoom(){
    return this->upRoom;
}
Room* Room::getDownRoom(){
    return this->downRoom;
}
Room* Room::getLeftRoom(){
    return this->leftRoom;
}
Room* Room::getRightRoom(){
    return this->rightRoom;
}