#include "player.h"

#include "level.h"
#include <iostream>

using namespace std;


class Game
{
    private:
        Level* _firstRoom;


        
       
        size_t listSize;

    public:
        Game();
        ~Game();

        bool empty();
        size_t size();

        void push(Level*);
        void pop();
        Level top();
        

       
};

// set to nullptr and initialize listSize
Game::Game()
{   
   //pushing final level
    Villain joker("Joker", 100, 25);
    Villain *pointerJoker = &joker;
    string description = "you enter the final floor to see your opponent is joker";
    Level finalLevel(description, pointerJoker);

    


}

// iteratively delete the list starting at _head
Game::~Game()
{
    Level* currentLevel = _firstRoom;
    while(currentLevel != nullptr){
        Level* levelToDelete = currentLevel;
        currentLevel = currentLevel->getNext();
        delete levelToDelete;
    }
    
    
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
bool Game::empty()
{
    if(_firstRoom == nullptr){
        return true;
    }else{
        return false;
    }
}

// return number of elements in list
size_t Game::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
void Game::push(Level *newLevel)
{   
    if(_firstRoom == nullptr){
        _firstRoom = newLevel;
        
        listSize++;

    }
    else{
        newLevel->setNext(_firstRoom);
        _firstRoom = newLevel;
        listSize++;
    }
    
   return;

}


Level Game::top(){
    return *_firstRoom;
}




// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;


void Game::pop()
{
    if(empty()){
        return;
    }
    
    Level* tempLevel = _firstRoom;
    _firstRoom = _firstRoom->getNext();
    delete tempLevel;
    listSize--;
    return;

}

