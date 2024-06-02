#include "BST.h"

class LinkedlistBST:public BST{
    public:
     bool isEmpty();
     void add(int data);
     bool remove(int key);
     bool search(int targetkey);
};