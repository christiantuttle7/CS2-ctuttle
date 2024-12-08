#pragma once
#include "player.h"
#include "villain.h"


class Level
{
    private:
    Villain _villain;
    string description;

    Level* _next;

    public:
    Level(string, Villain);
    void setVillain(Villain);
    void setNext(Level*);
    int getVillain();
    Level* getNext();
};


Level::Level(string, Villain)
{

    _next = nullptr;
}


void Level::setVillain(Villain newBoss)
{
    boss = newBoss;
}




void Level::setNext(Level* next)
{
    _next = next;
}


int Level::getVillain()
{
    return _villain;
}


Level* Level::getNext()
{
    return _next;
}