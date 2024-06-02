#include <iostream>
#include "../include/bst.h"
using namespace std;

#define MAX 100
int arr[MAX] = {0}; 

class ArrayBST : public BST {
public:
    bool isEmpty() override;
    void add(int data) override;
    bool remove(int key) override;
    bool search(int targetkey) override;
    void printInOrder(int index = 0);
private:
    int findMin(int index);
    int findIndex(int value);
};

bool ArrayBST::isEmpty() {
    return arr[0] == 0;
}

void ArrayBST::add(int data) {
    int index = 0;
    while (index < MAX) {
        if (arr[index] == 0) { 
            arr[index] = data;
            return;
        } else if (data < arr[index]) {
            index = 2 * index + 1; 
        } else {
            index = 2 * index + 2; 
        }
    }
    cout << "Array is full. Cannot insert " << data << endl;
}

bool ArrayBST::search(int targetkey) {
    int index = 0;
    while (index < MAX && arr[index] != 0) {
        if (arr[index] == targetkey) {
            return true;
        } else if (targetkey < arr[index]) {
            index = 2 * index + 1; 
        } else {
            index = 2 * index + 2; 
        }
    }
    return false;
}

bool ArrayBST::remove(int key) {
    int index = findIndex(key);
    if (index == -1) {
        cout << "Value " << key << " not found in the tree." << endl;
        return false;
    }

    
    if (arr[2 * index + 1] == 0 && arr[2 * index + 2] == 0) {
        
        arr[index] = 0;
    } else if (arr[2 * index + 1] != 0 && arr[2 * index + 2] != 0) {
        
        int minIndex = findMin(2 * index + 2);
        arr[index] = arr[minIndex];
        remove(arr[minIndex]);
    } else {
        
        int childIndex = (arr[2 * index + 1] != 0) ? 2 * index + 1 : 2 * index + 2;
        arr[index] = arr[childIndex];
        arr[childIndex] = 0;
        if (arr[2 * childIndex + 1] != 0 || arr[2 * childIndex + 2] != 0) {
            remove(arr[index]);
        }
    }
    return true;
}

void ArrayBST::printInOrder(int index) {
    if (index >= MAX || arr[index] == 0) return;
    printInOrder(2 * index + 1); 
    cout << arr[index] << " "; 
    printInOrder(2 * index + 2); 
}

int ArrayBST::findMin(int index) {
    while (2 * index + 1 < MAX && arr[2 * index + 1] != 0) {
        index = 2 * index + 1;
    }
    return index;
}

int ArrayBST::findIndex(int value) {
    int index = 0;
    while (index < MAX && arr[index] != 0) {
        if (arr[index] == value) {
            return index;
        } else if (value < arr[index]) {
            index = 2 * index + 1;
        } else {
            index = 2 * index + 2;
        }
    }
    return -1; 
}

int main() {
    ArrayBST tree;
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);

    cout << "In-order traversal: ";
    tree.printInOrder();
    cout << endl;

    cout << "Search 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (tree.search(20) ? "Found" : "Not Found") << endl;

    tree.remove(10);
    cout << "In-order traversal after removing 10: ";
    tree.printInOrder();
    cout << endl;

    return 0;
}
