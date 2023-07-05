#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree(string);
    bool isEmpty();
    Node* getRoot();
    void setRoot(Node* root);
    void insertNode(string question);
    void printQuestions();
    void destroyTree(Node* node);

    
    
};
#include "binarytree.cpp"

#endif
