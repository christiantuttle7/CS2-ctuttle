#pragma once
#include "node.h"

template <class T1>
class BST
{
    private:
    Node<T1>* _root;
    Node<T1>* insertNode(Node<T1>*, T1);
    void inOrderPrint(Node<T1>*);
    Node<T1>* searchData(Node<T1>*, T1);
    Node<T1>* removeData(Node<T1>*, T1);
    Node<T1>* minVal(Node<T1>*);

    public:
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1);
    void increment(T1);
    ~BST();
};

// Destructor, should check if root exists and then delete it. Each node will handle deleting its leaf nodes.
template <class T1>
BST<T1>::~BST()
{
    if(_root == nullptr){
        return;
    }
    
    

    delete _root;
}

// Public method that takes in some data and passes that into the removeData method. Don't forget to update _root as you may end up deleting the original root.
template <class T1>
void BST<T1>::remove(T1 data)
{
    removeData(_root, data);
}

// Private method to recursively walk the tree until the data is found.
// Then using the process built in class, check if there is only one leaf, if so then move that leaf into the root position.
// If there are two leafs, find the smallest value in the right subtree (or the largest value in the left subtree but you would have to rename minVal method) and then replace
// the current node with that.
// Don't forget to clean up your memory!
template <class T1>
Node<T1>* BST<T1>::removeData(Node<T1>* root, T1 data)
{
    if(root == nullptr) return root;
    
    if(root->getData() > data)
    {
        root->setLeft(removeData(root->getLeft(), data));
    }
    else if (root->getData() < data)
    {
        root->setRight(removeData(root->getRight(), data));
    }
    else
    {
        if(root->getLeft() == nullptr)
        {
            Node<T1>* tmpNode = root->getRight();
            delete root;
            return tmpNode;
        }
        else if(root->getRight() == nullptr)
        {
            Node<T1>* tmpNode = root->getLeft();
            delete root;
            return tmpNode;
        }
        Node<T1>* minNode = minVal(root->getRight());

        root->setData(minNode->getData());
        root->setRight(removeData(root->getRight(), minNode->getData()));
    }
    return root;
}

// Given a node, find the smallest value in that subtree. Return that node
template <class T1>
Node<T1>* BST<T1>::minVal(Node<T1>* root)
{
    if(root->getLeft() == nullptr){
        return root;
    }
    minVal(root->getLeft());
    
}

// Given data and a node, recursively walk the tree to find that node if it exists.
template <class T1>
Node<T1>* BST<T1>::searchData(Node<T1>* root, T1 data)
{
    if(root == nullptr){
        return nullptr;
    }
    if(root->getData() == data ){
        return root;
    }
    if(root->getData() < data){
        
        return searchData(root->getRight(), data);
    }
    if(root->getData() > data){
        
         return searchData(root->getLeft(), data);
    }
    return nullptr;
    
}

// Wrapper function for searchData. Pass data, root into searchData and return true if data found, return false if data not found.
template <class T1>
bool BST<T1>::search(T1 data)
{
    Node<T1>* foundNode;
    foundNode = searchData(_root, data);

    if(foundNode == nullptr) return false;
    return true;
}



// Given a node, recursively walk the tree to print out the inOrder format. That's left->root->right.
// Make sure you cout with a space separating each value as I based my tests on that!
// For example, you would end up cout (do not add the "): "1 2 3 4 5 "
// Notice that there is an extra space at the end.
template <class T1>
void BST<T1>::inOrderPrint(Node<T1>* root)
{
    if(root == nullptr) return;
    
    inOrderPrint(root->getLeft());
    std::cout << root->getData() << " ";
    inOrderPrint(root->getRight());
}

// Wrapper for inOrderPrint
template <class T1>
void BST<T1>::inOrder()
{
    inOrderPrint(_root);
}

// Give some data and a node, recursively walk the tree until you get to a nullptr and store the value there.
// You should ensure that if data < the current node's data, you walk the left. If data > current node's data, walk right.
// You should check if the value already exists and say so (it's just adding an else with a cout).
template <class T1>
Node<T1>* BST<T1>::insertNode(Node<T1>* root, T1 data)
{
    
    
    if(root == nullptr){
        Node<T1>* newNode = new Node<T1>;
        newNode->setData(data);
        return newNode;
    }
    if(root->getData() > data){
        root->setLeft(insertNode(root->getLeft(), data));
    }
    else if(root->getData() < data){
        root->setRight(insertNode(root->getRight(), data));
    }
     else if(root->getData() == data){
         root->setRight(insertNode(root->getRight(), data));
     }
    
    return root;
}

// Wrapper for insertNode. Take in data to pass that and _root to insertNode. Ensure you update _root since if the tree is empty, that would be the new _root.
template <class T1>
void BST<T1>::insert(T1 data)
{
    if(_root == nullptr){
        _root = new Node<T1>;
        _root->setData(data);
        return;
        
    }
    _root = insertNode(_root, data);
}

// Search for the word by calling searchData passing in _root and data.
// If node is found, setData on that node with getData++
template <class T1>
void BST<T1>::increment(T1 data)
{
    
    Node<T1>* tempNode = searchData(_root, data);
    //
    if(tempNode != nullptr){
        T1 newData = tempNode->getData()++;
        tempNode->setData(newData);
    }
}