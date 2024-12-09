#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;


class Player{
    private:
        string Name;
        int hp;
        int damage;

    public:
        Player();
        Player(string, int, int);
        void attack(Player*, int);
        void attack(Player*);
       
        
        void setHP(int);
        int getDamage();
        int getHP();
        string getName();
        void setDamage(int);





};

Player::Player(){
    Name = "BATMAN";
    hp = 100;
    damage = 34;
}

Player::Player(string newname, int newhp, int newdamage){
    Name = newname;
    hp = newhp;
    damage = newdamage;

}
//villain attacking the user
void Player::attack(Player* user){
    user->setHP(user->getHP() - damage);
    
}

//user attacking the villain
void Player::attack(Player* villain, int attackType){
    if(attackType == 1){
        villain->setHP(villain->getHP() - damage);
    }
    if(attackType == 2){
        int randomNum = rand() % 10001;
        if(randomNum % 2 == 0){
            villain->setHP(villain->getHP() - damage);
            cout << "Batarang Hit!" << endl;
        }else{
            cout << "Batarang Missed :(" << endl;
        }

    }
}


int Player::getHP(){
    return hp;
}

void Player::setHP(int newHP){
    hp = newHP;
}

string Player::getName(){
    return Name;
}

int Player::getDamage(){
    return damage;
}

void Player::setDamage(int newDamage){
    damage = newDamage;;
}

