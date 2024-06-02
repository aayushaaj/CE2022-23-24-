#include "../include/LinkedlistBST.h"
#include <iostream>

LinkedlistBST::LinkedlistBST()
{
     root = nullptr;
}

bool LinkedlistBST::isEmpty()
{
     return root == nullptr;
}

void LinkedlistBST::addBST(int data)
{
     if (root == nullptr)
     {
          root = new node(data);
     }
     else
     {
          addNode(root, data);
     }
}

void LinkedlistBST::addNode(node *newNode, int data)
{
     if (data < newNode->key)
     {
          if (newNode->left == nullptr)
          {
               newNode->left = new node(data);
          }
          else
          {
               addNode(newNode->left, data);
          }
     }
     else if (data > newNode->key)
     {
          if (newNode->right == nullptr)
          {
               newNode->right = new node(data);
          }
          else
          {
               addNode(newNode->right, data);
          }
     }
}

bool LinkedlistBST::removeBST(int key)
{

     bool isRemoved = false;
     root = removeNode(root, key, isRemoved);
     return isRemoved;
}

node *LinkedlistBST::removeNode(node *root, int keyToDelete, bool &isRemoved)
{
     if (isEmpty())
     {
          return nullptr;
     }
     if (keyToDelete < root->key)
     {
          root->left = removeNode(root->left, keyToDelete, isRemoved);
     }
     else if (keyToDelete > root->key)
     {
          root->right = removeNode(root->right, keyToDelete, isRemoved);
     }
     else
     {
          isRemoved = true;
          if (root->left == nullptr)
          {
               node *temp = root->right;
               delete root;
               return temp;
          }
          else if (root->right == nullptr)
          {
               node *temp = root->left;
               delete root;
               return temp;
          }
          node *temp = findMin(root->right);
          root->key = temp->key;
          root->right = removeNode(root->right, temp->key, isRemoved);
     }
     return root;
}

node *LinkedlistBST::findMin(node *current) const
{
     while (current->left != nullptr)
     {
          current = current->left;
     }
     return current;
}

bool LinkedlistBST::searchBST(int targetkey)
{
     if (isEmpty())
     {
          return false;
     }
     if (targetkey < root->key)
     {
          return searchNode(root->left, targetkey);
     }
     else if (targetkey > root->key)
     {
          return searchNode(root->right, targetkey);
     }
     else
     {
          return true;
     }
}

bool LinkedlistBST::searchNode(node *current, int targetkey) const
{
     if (current == nullptr)
     {
          return false;
     }
     if (targetkey == current->key)
     {
          return true;
     }
     else if (targetkey < current->key)
     {
          return searchNode(current->left, targetkey);
     }
     else
     {
          return searchNode(current->right, targetkey);
     }
}
