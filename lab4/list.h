#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr;
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
void List<T1>::push_front(T1 data)
{   
    if(_head == nullptr && _tail == nullptr){
        _head == new Node<T1>;
        _head->setData(data);
        _tail = _head;
        listSize++;

    }
    else{
        Node<T1>* newNode = new Node<T1>;
        newNode->setData(data);
        newNode->setNext(_head);
        _head->setPrev(newNode);
        _head = newNode;
        listSize++;
    }
    
   return;

}
// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
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
T1 List<T1>::pop_front()
{
    T1 dataToReturn = _head->getData();
    
    Node<T1>* tempNode = _head;
    _head = _head->getNext();
    delete tempNode;
    listSize--;
    return dataToReturn;
    
    
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    if(_head == nullptr && _tail == nullptr){
        _tail = new Node<T1>;
        _tail->setData(data);
        _head = _tail;
        listSize++;

    }
    else{
        Node<T1>* newNode = new Node<T1>;
        newNode->setData(data);
        newNode->setPrev(_tail);
        _tail->setNext(newNode);
        _tail = newNode;
        listSize++;
    }


}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if(empty()){
        cout << "list is empty" << endl;;
        return 0;
    }
    else{
        return _tail->getData();
    }
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    
    if(empty()){
        cout << "Empty List";
        return 0;
    }
    //getting the correct data to return
    T1 dataToReturn = _tail->getData();
    
    //creating a temporary node setting it to the current tail node
    Node<T1>* tempNode = _tail;
    //setting the tail node to the second last node
    _tail = _tail->getPrev();
    _tail->setNext(nullptr);
    //delete the previous tail node
    delete tempNode;

    
    listSize-=1;
    
    return dataToReturn;
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    //go through each node and print out each node until you hit a nullptr
    Node<T1>* currentNode = list._head;
    while(currentNode != nullptr)
    {

        os << currentNode->getData() << " ";
        currentNode = currentNode->getNext();
    }
    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    bool matches = true;
    //if the list sizes dont match we can automatticaly assume that the lists dont match
    if(listSize != rhs.listSize){
        matches = false;
        return matches;
    }
    //make two new nodes to help iterate through each list
    Node<T1>* currentNodeOne = _head;
    Node<T1>* currentNodeTwo = rhs->_head;
    //go through the list one node at a time 
    while(currentNodeOne->getNext != nullptr && currentNodeTwo->getNext() != nullptr){
        if(currentNodeOne != currentNodeTwo){
            matches = false;
        }
        currentNodeOne = currentNodeOne->getNext();
        currentNodeTwo = currentNodeTwo->getNext();
    }

 return true;
}