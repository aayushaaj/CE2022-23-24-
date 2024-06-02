#pragma once
#include "bst.h"

class LinkedlistBST : public BST
{
public:
    LinkedlistBST();
    ~LinkedlistBST() {}
    bool isEmpty();
    void addBST(int data);
    bool removeBST(int keyToDelete);
    bool searchBST(int targetkey);
    void addNode(node *newNode, int data);
    bool searchNode(node *current, int targetkey) const;
    node *removeNode(node *current, int keyToDelete, bool &isRemoved);
    node *findMin(node *current) const;
};