#pragma once


class Node
{
    private:
    int _data;
    Node* _next;

    public:
    Node();
    void setData(int);
    void setNext(Node*);
    int getData();
    Node* getNext();
};


Node::Node()
{
    
    _next = nullptr;
}


void Node::setData(int data)
{
    _data = data;
}




void Node::setNext(Node* next)
{
    _next = next;
}


int Node::getData()
{
    return _data;
}


Node* Node::getNext()
{
    return _next;
}