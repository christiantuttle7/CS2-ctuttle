
#include <iostream>
#include "game.h"
#include "item.h"
using namespace std;

void clearScreen();

int main(){

    cout << "Your Name is Bruce Wayne, you reieve a letter from the joker saying he is holdin your butler," <<
                " Alfred hostage and wants 42 million dollars" << endl;

    //creating game
    Game theGame;
    //creating player
    Player *user = new Player;

    //pushing final level
    Player joker("Joker", 100, 25);
    Player *pointerJoker = &joker;
    string description = "You enter the final floor to see your opponent is The Joker" ;
    item healthBoostTwo("HEALTH BOOST - 100", 100, "health");
    item *pointerItem3 = &healthBoostTwo;
    Level finalLevel(description, pointerJoker, pointerItem3);
    Level *finalLevelPointer = &finalLevel;
    theGame.push(finalLevelPointer);

    //pushing second level
    Player bane("Bane", 100, 20);
    Player *pointerbane = &bane;
    string descriptionBane = "You enter the second floor to see your opponent is Bane";
    item powerBoost("DAMAGE BOOST - 25", 10, "damage");
    item *pointerItem2 = &powerBoost;
    Level secondLevel(descriptionBane, pointerbane, pointerItem2);
    Level *secondLevelPointer = &secondLevel;
    theGame.push(secondLevelPointer);

    //pushing thid level
    Player ivy("Poison Ivy", 100,15);
    Player *pointerIvy = &ivy;
    string descriptionIvy = "You enter the first floor to see your opponent is Poison Ivy";
    item healthBoost("HEALTH BOOST - 50", 50, "health");
    item *pointerItem1 = &healthBoost;
    Level firstLevel(descriptionIvy, pointerIvy, pointerItem1);
    Level *firstLevelPointer = &firstLevel;
    theGame.push(firstLevelPointer);

    int inputInt;

    cout << "Enter 1 to Go find Joker and save Alred: ";
    cin >>inputInt;
    cin.ignore();

    //while loop that goes to the next level until user wins/dies
    while(true){
        clearScreen();   

        user->setHP(100); 
        //getting all level info
        Level currentLevel = theGame.top();
        Player *currentVillain = currentLevel.getVillain();
        item *currentItem = currentLevel.getItem();
        //using item
        cout << currentLevel.getDescription() << endl;
        cout << "You have recieved an item: " << currentItem->getName() << endl;
        cout <<"Enter 1 to use: ";
        cin >> inputInt;
        cin.ignore();
        currentItem->use(user);
        cout << "Item Used" << endl;

        
        //While loop that goes until the villain is dead
        while(currentVillain->getHP() >= 0 ){
            
            //villain hits user
            currentVillain->attack(user);
            cout << currentVillain->getName() << " hit you for " << currentVillain->getDamage() << endl;

            //checking if user is dead
            if(user->getHP() <= 0 ){
                cout << "You have died";
                return 0;
            }

            //user can now hit the villain
            cout << "Enter 1 to punch "  << endl;
            cout << "Enter 2 to throw a Batarang: " ;
            int attackType;
            cin >> attackType;
            cin.ignore();
            
                user->attack(currentVillain, attackType);

        }
        
        cout << "You have Defeated: " << currentVillain->getName() << endl;

        theGame.pop();
        if(theGame.empty()){
            cout << "You won!";
            return 0;
        }

        cout << "Type 1 to go to next floor";
        cin >> inputInt;
        cin.ignore();

    }

 return 0;
}


 void clearScreen(){
     #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
 }