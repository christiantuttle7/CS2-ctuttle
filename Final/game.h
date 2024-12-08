#pragma once
#include "node.h"
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

        void push(Villain, string, string);
        int pop();
        int top();
        

       
};

// set to nullptr and initialize listSize
Game::Game()
{
    _firstRoom = nullptr;
    listSize = 0;


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
bool List::empty()
{
    if(_firstRoom == nullptr){
        return true;
    }else{
        return false;
    }
}

// return number of elements in list
size_t List::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
void Game::push(Villain villain)
{   
    if(_firstRoom == nullptr ){
        _firstRoom = new Level;
        _firstRoom->setVillain(villain);
        listSize++;

    }
    else{
        Node* newNode = new Node;
        newNode->setData(data);
        newNode->setNext(_head);
        _head = newNode;
        listSize++;
    }
    
   return;

}
// return the first element in the list.
// if the list is empty, print that out and return 0

int List::top()
{
    if(empty()){
        return 0;
    }else{
        return _head->getData();
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;


int List::pop()
{
    if(empty()){
        return 0;
    }
    int dataToReturn = _head->getData();
    
    Node* tempNode = _head;
    _head = _head->getNext();
    delete tempNode;
    listSize--;
    return dataToReturn;

}

