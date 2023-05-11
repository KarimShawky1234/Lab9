//
//  Tree.h
//  Lab9Question2
//
//  Created by kareem ahmed shawky on 5/11/23.
//

#ifndef Tree_h
#define Tree_h

#include <iostream>

class Tree {
private:
    struct Node {
        int num;
        int height;
        Node* left;
        Node* right;

        Node(int n) {
            num = n;
            height = 1;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    int height(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* insert(Node* node, int num);
    Node* deleteNode(Node* node, int num);
    void inorderTraversal(Node* node, std::ostream& os);
    void printInorderHelper(Node* node);

public:
    Tree();
    void insert(int val);
    void deleteNode(int val);
    void printInorder();
};


#endif /* Tree_h */
