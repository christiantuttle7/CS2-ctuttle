#pragma once
#include <iostream>
using namespace std;


class player{
    private:
        string name;
        int hp;
    public:
        void attack();
        int getHP();
        void setHP(int);



};

int player::getHP(){
    return hp;
}


void player::setHP(int newHP){
    hp = newHP;
}