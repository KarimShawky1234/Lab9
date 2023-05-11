//
//  BalancedBST.cpp
//  Lab9Question2
//
//  Created by kareem ahmed shawky on 5/11/23.
//

#include "Tree.h"
using namespace std;

Tree::Tree() {
    root = nullptr;
}

int Tree::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int Tree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Tree::Node* Tree::rotateRight(Node* node) {
    Node* leftChild = node->left;
    Node* rightGrandChild = leftChild->right;

    leftChild->right = node;
    node->left = rightGrandChild;

    node->height = max(height(node->left), height(node->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

    return leftChild;
}

Tree::Node* Tree::rotateLeft(Node* node) {
    Node* rightChild = node->right;
    Node* leftGrandChild = rightChild->left;

    rightChild->left = node;
    node->right = leftGrandChild;

    node->height = max(height(node->left), height(node->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

    return rightChild;
}

Tree::Node* Tree::insert(Node* node, int num) {
    if (node == nullptr)
    {
        return new Node(num);
    }
    
    if (num < node->num)
    {
        node->left = insert(node->left, num);
    }
    else if (num > node->num)
    {
        node->right = insert(node->right, num);
    }
    else
    {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && num < node->left->num) {
        return rotateRight(node);
    }

    if (balance < -1 && num > node->right->num) {
        return rotateLeft(node);
    }

    if (balance > 1 && num > node->left->num) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && num < node->right->num) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Tree::Node* Tree::deleteNode(Node* node, int num) {
    if (node == nullptr) {
        return node;
    }

    if (num < node->num) {
        node->left = deleteNode(node->left, num);
    } else if (num > node->num) {
        node->right = deleteNode(node->right, num);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            Node* temp = node->right;

            while (temp->left != nullptr) {
                temp = temp->left;
            }

            node->num = temp->num;
            node->right = deleteNode(node->right, temp->num);
        }
    }

    if (node == nullptr) {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
        return rotateLeft(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void Tree::insert(int num) {
root = insert(root, num);
}

void Tree::deleteNode(int num) {
root = deleteNode(root, num);
}

void Tree::printInorder() {
    printInorderHelper(root);
}

void Tree::printInorderHelper(Node* node) {
    if (node == nullptr) {
        return;
    }

    printInorderHelper(node->left);
    cout << node->num << " ";
    printInorderHelper(node->right);
}




