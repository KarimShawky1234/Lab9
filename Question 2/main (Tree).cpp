//
//  main.cpp
//  Lab9Question2
//
//[9,11,18,3,6,12,3,4,2,20]
//  Created by kareem ahmed shawky on 5/11/23.
//

#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree BST;
    BST.insert(9);
    BST.insert(11);
    BST.insert(18);
    BST.insert(3);
    BST.insert(6);
    BST.insert(12);
    BST.insert(3);
    BST.insert(4);
    BST.insert(2);
    BST.insert(20);
    
    cout << "The Inorder traversal of the balanced tree is: ";
    BST.printInorder();
    cout << endl;
    
    return 0;
}
