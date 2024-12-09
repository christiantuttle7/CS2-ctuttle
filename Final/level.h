#pragma once
#include "item.h"
#include "villain.h"



class Level
{
    private:
    Player *_villain;
    string _description;
    item *_item;

    Level* _next;

    public:
    Level();
    Level(string, Player*, item*);
    void setVillain(Player*);
    void setNext(Level*);
    void setDescription(string);
    Player* getVillain();
    string getDescription();
    Level* getNext();
    item* getItem();

};


Level::Level(string description, Player *villain, item *newItem)
{
    _villain = villain;
    _description = description;
    _item = newItem;

    _next = nullptr;
}


void Level::setVillain(Player *newBoss)
{
    _villain = newBoss;
}




void Level::setNext(Level* next)
{
    _next = next;
}

void Level::setDescription(string newDes){
    _description = newDes;
}


Player* Level::getVillain()
{

    return _villain;
}

string Level::getDescription(){
    return _description;
}


Level* Level::getNext()
{
    return _next;
}

item* Level::getItem(){
    return _item;
}