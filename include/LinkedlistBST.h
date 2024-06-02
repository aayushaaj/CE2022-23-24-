#include "BST.h"

class LinkedlistBST:public BST{

    public:
     bool isEmpty();
     void addBST(int data);
     bool removeBST(int keyToDeelete);
     bool searchBST(int targetkey);
};