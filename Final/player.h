#pragma once
#include <iostream>
#include "level.h"

using namespace std;



class Player{
    private:
        string name;
        int hp;

    public:
        Player();
        void attack(Villain*);
        int getHP();
        void setHP(int);



};

Player::Player(){
    name = "";
    hp = 100;
}


int Player::getHP(){
    return hp;
}


void Player::setHP(int newHP){
    hp = newHP;
}

void Player::attack(Villain *boss){
    boss->setHP(boss->getHP() - 25);
    return;
}