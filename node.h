#ifndef NODE_H
#define NODE_H

#include <string>


using namespace std;

class Node {
    private:
    string question;
    Node* left;
    Node* right;
    
public:
    Node(string question);

    string getQuestion();
    Node* getLeft();
    Node* getRight();

    void setQuestion(string question);
    void setLeft(Node* left);
    void setRight(Node* right);
};
#include "node.cpp"

#endif  // NODE_H
