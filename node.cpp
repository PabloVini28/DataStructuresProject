#include "node.h"

using namespace std;

Node::Node(string question){
    setQuestion(question);
    setLeft(nullptr);
    setRight(nullptr);
} 

string Node::getQuestion(){
    return question;
}

Node* Node::getLeft(){
    return left;
}

Node* Node::getRight() {
    return right;
}

void Node::setQuestion(string question) {
    this->question = question;
}

void Node::setLeft(Node* left) {
    this->left = left;
}

void Node::setRight(Node* right) {
    this->right = right;
}
