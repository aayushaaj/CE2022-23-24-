#pragma once
#include <iostream>
using namespace std;
class BST{
    public:
     virtual bool isEmpty()=0;
     virtual void add(int data)=0;
     virtual bool remove(int key)=0;
     virtual bool search(int targetkey)=0;
     virtual ~BST(){};
};