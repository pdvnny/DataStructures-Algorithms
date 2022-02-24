#include<iostream>
#include<string>
#include<vector>

#include "BinarySearchTree.h"

using namespace std;

int main()
{

    BST t; // A Binary Search Tree
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
 
    cout << "Traversal of the constructed tree is ";
    t.traverse();
 
    // int k = 6;
    // (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";
 
    // k = 15;
    // (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";
 
    return 0;
}