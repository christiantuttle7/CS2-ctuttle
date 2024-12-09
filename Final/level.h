#pragma once
#include "player.h"
#include "villain.h"



class Level
{
    private:
    Villain *_villain;
    string _description;

    Level* _next;

    public:
    Level();
    Level(string, Villain*);
    void setVillain(Villain*);
    void setNext(Level*);
    void setDescription(string);
    Villain* getVillain();
    string getDescription();
    Level* getNext();

};


Level::Level(string description, Villain *villain)
{
    _villain = villain;
    _description = description;

    _next = nullptr;
}


void Level::setVillain(Villain *newBoss)
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


Villain* Level::getVillain()
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