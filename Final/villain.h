#pragma once
#include <iostream>
#include "player.h"
using namespace std;


class Villain{
    private:
        string Name;
        int hp;
        int damage;

    public:
        void attack(player);
       
        void add_to_inventory();
        void setHP(int );
        int getHP();





};

void Villain::attack(player user){
    user.setHP(user.getHP() - damage);
}



int Villain::getHP(){
    return hp;
}

void Villain::setHP(int newHP){
    hp = newHP;
}

