#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "node.h"

class BinaryTree{
private:
  Node* root;
  string* sintomas;
  int num_sintomas; // quantidade de sintomas

public:
  BinaryTree();
  ~BinaryTree();
  string* getSintomas();
  string realizarConsulta(int sintomas[]);
  Node* getRoot();
  int getNumeroSintomas();
  void setRoot(Node* root);
  void clear();
};

#endif
