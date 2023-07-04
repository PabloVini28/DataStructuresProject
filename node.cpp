#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"

Node::Node(string pergunta, Node *l, Node *r){
    string sintoma = pergunta;
    left = l;
    right = r;
}

Node* Node::getLeft(){
    return this->left;
}

void Node::setLeft(Node* newLeft){
    this->left = newLeft;
}

Node* Node::getRight(){
    return this->right;
}

void Node::setRight(Node* newRight){
    this->right = newRight;
}

string Node::getCode(){
    return this->code;
}

void Node::setCode(string newCode){
    this->code = newCode;
}

#endif
