#include "binaryTree.h"
#include <iostream>
using namespace std;

int main(){

    // crie uma arvore binaria chamada tree
    BinaryTree tree;

    // Construindo a árvore com perguntas
    tree.insertNode("Tem febre?");
    tree.insertNode("Tem tosse?");
    tree.insertNode("Tem dor de cabeça?");
    tree.insertNode("Tem dor no corpo?");
    tree.insertNode("Respireiu ar poluído recentemente?");
    tree.insertNode("Teve contato com alguém doente?");
    tree.insertNode("Tem dor de garganta?");
    tree.insertNode("Tem congestão nasal?");

    // Percorrendo a árvore e fazendo perguntas ao usuário
    Node* NoAtual = tree.getRoot();
    while (NoAtual != nullptr) {
        cout << NoAtual->getQuestion() << " (Responda 1 para Sim, 0 para Não): ";
        int resposta;
        cin >> resposta;

        if (resposta == 1) {
        NoAtual =NoAtual->getLeft();
        } else {
        NoAtual =NoAtual->getRight();
        }
    }

    // Imprimindo a doença correspondente quando chega a uma folha
    string disease =NoAtual->getQuestion();
    cout << "Você está com a doença: " << disease << endl;

    return 0;
}
