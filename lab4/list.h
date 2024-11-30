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
        //T1 pop_front();
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
    int i = 0;
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if(_head == nullptr && _tail ==nullptr){
        return true;
    }else{
        return false;
    }
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    int elements = 0;
    while(_head->getNext() != nullptr){
        elements++;
    }
    return elements;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{   
    /*
    Node<T1>* newNode;
    Node currentNode = _head;
    while(currentNode->_next != nullptr){
        currentNode = currentNode.next;
    }
    currentNode.next = newNode;
    newNode->_next = _tail;
    newNode->_prev = currentNode;
    */
   return;

}
// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if(_head->_next == nullptr){
        return 0;
    }else{
        return _head->_next;
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
/*
template <class T1>
T1 List<T1>::pop_front()
{
    
}
*/
// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    //creating new node
    Node<T1>* newNode = new Node<T1>;
    newNode->setData(data);

    if(_tail == nullptr){
        _tail = new Node<T1>;
        _head = new Node<T1>;
        _tail->setPrev(newNode);
        _head->setNext(newNode);
        return;
    }
    
    
    Node<T1>* lastNode = _tail->getPrev() ;
    
    //figuring out what the last node in the list is then setting the next node to the new node
    //lastNode->_next = newNode;
    lastNode->setNext(newNode);
    //configuring new node
    //newNode->prev = lastNode;
    newNode->setPrev(lastNode);
    //newNode->_next = _tail;
    newNode->setNext(_tail);


}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if(_tail->_prev == nullptr){
        return 0;
    }
    else{
        return _tail->_prev;
    }
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    int dataToReturn = _tail->_prev->getData();
    _tail->setPrev(_tail);
    //_tail->_prev = _tail;
    return dataToReturn;
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    Node<T1>* currentNode = list->_head;
    while(currentNode->_next != nullptr){
        cout << currentNode->_next->getData();
        currentNode = currentNode->getNext();
    }
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
 return true;
}