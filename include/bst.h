#pragma once
<<<<<<< HEAD
#include "node.h"

class BST
{
public:
    virtual bool isEmpty() = 0;
    virtual void addBST(int data) = 0;
    virtual bool removeBST(int keyToDelete) = 0;
    virtual bool searchBST(int targetkey) = 0;
    node *HEAD;
=======
#include <iostream>
using namespace std;
class BST{
    public:
     virtual bool isEmpty()=0;
     virtual void add(int data)=0;
     virtual bool remove(int key)=0;
     virtual bool search(int targetkey)=0;
     virtual ~BST(){};
>>>>>>> ca50fba5616f5f24732a113c1b3d486e328e2d32
};