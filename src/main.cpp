#include <iostream>
#include "../include/LinkedlistBST.h"
int main()
{

    LinkedlistBST bst;

    if (bst.isEmpty())
    {
        std::cout << "Binary Tree is empty" << std::endl;
    }
    std::cout << "\n";

    // Adding some nodes
    bst.addBST(50);
    bst.addBST(30);
    bst.addBST(20);
    bst.addBST(40);
    bst.addBST(70);
    bst.addBST(60);
    bst.addBST(80);

    std::cout << "After adding some nodes" << std::endl;
    std::cout << "\n";

    bst.isEmpty() ? std::cout << "BST is empty" << std::endl : std::cout << "BST is not empty" << std::endl;
    std::cout << "\n";

    // Removing a node
    std::cout << "Removing 20 from the BST" << std::endl;
    bst.removeBST(20) ? std::cout << "20 removed from the BST" << std::endl : std::cout << "Key not found" << std::endl;
    std::cout << "\n";
    // Searching for a node
    std::cout << "Searching 30" << std::endl;
    if (bst.searchBST(30))
    {
        std::cout << "Node 30 found in the BST" << std::endl;
    }
    else
    {
        std::cout << "Node 30 not found in the BST" << std::endl;
    }
    std::cout << "\n";
    return 0;
}