#ifndef NODE_CPP
#define NODE_CPP

#include <vector>
#include "node.h"

Node::Node(Node* left, Node* right){
  this->doencas = nullptr;
  this->left = left;
  this->right = right;
}

Node::~Node(){
  delete this->doencas;
}

Node* Node::getLeft(){
  return this->left;
}

Node* Node::getRight(){
  return this->right;
}

void Node::setLeft(Node* left){
  this->left = left;
}

void Node::setRight(Node* right){
  this->right = right;
}

vector<string>* Node::getDoencas(){
  return this->doencas;
}

void Node::adicionarDoenca(string doenca){
  if (this->doencas == nullptr){
    this->doencas = new vector<string>();
  }
  this->doencas->push_back(doenca);
}

#endif
