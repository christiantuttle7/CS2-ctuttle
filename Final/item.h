#pragma once
#include "villain.h"

class item{
    private: 
        string name;
        int power;
        string effect;
    public:
        item(string, int, string);
        void use(Player*);
        string getName();
};

item::item(string newName, int newPower, string newEffect){
    name = newName;
    power = newPower;
    effect = newEffect;
}


void item::use(Player* user){
    if (effect == "healing"){
        user->setHP(user->getHP() + power);
    }
    if(effect == "damage"){
        user->setDamage(user->getDamage() + power);
    }

}


string item::getName(){
    return name;
}
