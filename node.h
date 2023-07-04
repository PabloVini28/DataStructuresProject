#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;


class Node {
private: 
    string code;
    Node *left;  // ponteiro para filho esquerdo
    Node *right;  // ponteiro para filho direito
    
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e os ponteiros para os 
     * filhos esquerdo e direito, respectivamente.
     * */
    Node(string pergunta,Node*l, Node *r);
    
    /**
    Métodos gets e sets dos atributos
    **/
    Node* getLeft();
    Node* getRight();
    string getCode();
    
    
    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
    void setCode(string newCode);
};
#include "node.cpp"
#endif
