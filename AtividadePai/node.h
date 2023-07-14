#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

using namespace std;

class Node{
private:
  vector<string>* doencas; // VETOR DE DOENÇAS
  Node* left; // NAO
  Node* right; // SIM
public:
  Node(Node* left, Node* right);
  ~Node();
  Node* getLeft();
  Node* getRight();
  vector<string>* getDoencas();
  void adicionarDoenca(string doenca);
  void setLeft(Node* left);
  void setRight(Node* right);
};
#endif
