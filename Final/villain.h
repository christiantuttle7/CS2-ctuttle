#pragma once
#include <iostream>
#include "level.h"
using namespace std;


class Villain{
    private:
        string Name;
        int hp;
        int damage;

    public:
        Villain(string, int, int);
        void attack(Player*);
       
        
        void setHP(int);
        int getHP();
        string getName();
        int getDamage();





};


Villain::Villain(string newname, int newhp, int newdamage){
    Name = newname;
    hp = newhp;
    damage = newdamage;

}
void Villain::attack(Player* user){
    user->setHP(user->getHP() - damage);
    
}



int Villain::getHP(){
    return hp;
}

void Villain::setHP(int newHP){
    hp = newHP;
}

string Villain::getName(){
    return Name;
}

int Villain::getDamage(){
    return damage;
}

