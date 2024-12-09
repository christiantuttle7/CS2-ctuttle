#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1>* _head;
       
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push(T1);
        T1 pop();
        T1 top();
        

       
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    listSize = 0;


}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    Node<T1>* currentNode = _head;
    while(currentNode != nullptr){
        Node<T1>* nodeToDelete = currentNode;
        currentNode = currentNode->getNext();
        delete nodeToDelete;
    }
    
    
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if(_head == nullptr){
        return true;
    }else{
        return false;
    }
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push(T1 data)
{   
    if(_head == nullptr ){
        _head = new Node<T1>;
        _head->setData(data);
        listSize++;

    }
    else{
        Node<T1>* newNode = new Node<T1>;
        newNode->setData(data);
        newNode->setNext(_head);
        _head = newNode;
        listSize++;
    }
    
   return;

}
// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::top()
{
    if(empty()){
        return 0;
    }else{
        return _head->getData();
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;

template <class T1>
T1 List<T1>::pop()
{
    if(empty()){
        return 0;
    }
    float dataToReturn = _head->getData();
    
    Node<T1>* tempNode = _head;
    _head = _head->getNext();
    delete tempNode;
    listSize--;
    return dataToReturn;

}

