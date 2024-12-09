
#include <iostream>
#include "game.h"
#include "player.h"
using namespace std;

int main(){

    cout << "Your Name is Batman and you have to save alfred who is being hostage by joker";

    //creating game
    Game theGame;
    //creating player
    Player *user = new Player;

    //pushing final level
    Villain joker("Joker", 100, 25);
    Villain *pointerJoker = &joker;
    string description = "you enter the final floor to see your opponent is The Joker";
    Level finalLevel(description, pointerJoker);
    Level *finalLevelPointer = &finalLevel;
    theGame.push(finalLevelPointer);

    //pushing second level
    Villain bane("Bane", 100, 20);
    Villain *pointerbane = &bane;
    string descriptionBane = "You enter the final floor to see your opponent is Bane";
    Level secondLevel(descriptionBane, pointerbane);
    Level *secondLevelPointer = &secondLevel;
    theGame.push(secondLevelPointer);

    //pushing thid level
    Villain ivy("Poison Ivy", 100,15);
    Villain *pointerIvy = &ivy;
    string descriptionIvy = "you enter the final floor to see your opponent is Bane";
    Level firstLevel(descriptionIvy, pointerIvy);
    Level *firstLevelPointer = &firstLevel;
    theGame.push(firstLevelPointer);


    while(true){
        Level currentLevel = theGame.top();
        Villain *currentVillain = currentLevel.getVillain();
        cout << currentLevel.getDescription();
        
        //While loop that goes until the villain is dead
        while(currentVillain->getHP() >= 0 ){
            
            //villain hits user
            currentVillain->attack(user);
            cout << currentVillain->getName() << " hit you for " << currentVillain->getDamage() << endl;

            //checking if user is dead
            if(user->getHP() <= 0 ){
                cout << "You have died";
                exit(0);
            }

            //user can now hit the villain
            cout << "Enter 1 to hit " << currentVillain->getName();
            int input;
            cin >> input;
            cin.ignore();
            if(input == 1){
                user->attack(currentVillain);
            }

        }
    }








 return 0;
}