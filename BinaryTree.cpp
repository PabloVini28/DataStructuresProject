#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP
#include "binaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    setRoot(nullptr);
}

BinaryTree::~BinaryTree() {
    destroyTree(getRoot());
}

BinaryTree::BinaryTree(string pergunta) {
    setRoot(new Node(pergunta));
}

bool BinaryTree::isEmpty() {
    return getRoot() == nullptr;
}

Node* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::setRoot(Node* root) {
    this->root = root;
}

void BinaryTree::insertNode(string pergunta) {
    Node* NovoNo = new Node(pergunta);
    Node* atual = getRoot();
    Node* parent = nullptr;

    if (isEmpty()) {
        setRoot(NovoNo);
    } else {
        while (atual != nullptr) {
            parent = atual;
            if (pergunta < atual->getQuestion()) {
                atual = atual->getLeft();
            } else {
                atual = atual->getRight();
            }
        }
        if (pergunta < parent->getQuestion()) {
            parent->setLeft(NovoNo);
        } else {
            parent->setRight(NovoNo);
        }
    }
}

void BinaryTree::printQuestions() {
    Node* atual = getRoot();
    if (isEmpty()) {
        cout << "Arvore vazia." << endl;
    } else {
        while (atual != nullptr) {
            cout << atual->getQuestion() << endl;
            atual = atual->getLeft();
        }
    }
}

void BinaryTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}

#endif
// Path: main.cpp
