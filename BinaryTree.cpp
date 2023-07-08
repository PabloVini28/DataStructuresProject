#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "binarytree.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(){
  ifstream arquivo("SintomasMenor.txt");

  this->root = new Node(nullptr, nullptr);

  if (arquivo.is_open()){
    int num_doencas;
    arquivo >> num_doencas;
    arquivo >> this->num_sintomas;

    this->sintomas = new string[num_sintomas];

    // Usado para consumir o nome dos sintomas (informações nao utilizadas)
    string buffer;

    arquivo.ignore();

    string doencas[num_doencas];

    for (int i = 0; i < num_doencas; i++){
      getline(arquivo, doencas[i]);
    }

    for (int i = 0; i < this->num_sintomas; i++){
      getline(arquivo, this->sintomas[i]);
    }

    while(getline(arquivo, buffer)){
      int id_doenca;
      int indice;

      stringstream ss(buffer);

      ss >> id_doenca;

      Node* no_atual = this->root;
      for(int i = 0; i < this->num_sintomas; i++){
        ss >> indice;

        if (indice == 0){
          if (no_atual->getLeft() == nullptr){
            no_atual->setLeft(new Node(nullptr, nullptr));
            no_atual = no_atual->getLeft();
          } else {
            no_atual = no_atual->getLeft();
          }
        }

        else if (indice == 1){
          if (no_atual->getRight() == nullptr){
            no_atual->setRight(new Node(nullptr, nullptr));
            no_atual = no_atual->getRight();
          } else {
            no_atual = no_atual->getRight();
          }
        }
      }

      no_atual->adicionarDoenca(doencas[id_doenca-1]);
    }
    arquivo.close();
  } else {
    cout << "Erro ao abrir o arquivo 'SintomasMenor.txt'\n";
  }

}

BinaryTree::~BinaryTree(){
  clear();
}

string* BinaryTree::getSintomas(){
  return this->sintomas;
}

int BinaryTree::getNumeroSintomas(){
  return this->num_sintomas;
}

string BinaryTree::realizarConsulta(int sintomas[]){
  Node* no_atual = this->root;

  for(int i = 0; i < this->num_sintomas; i++){
    if (no_atual == nullptr){
      return "";
    } else if (sintomas[i] == 0){
      no_atual = no_atual->getLeft();
    } else {
      no_atual = no_atual->getRight();
    }
  }

  string consulta = "";
  for (string doenca : *no_atual->getDoencas()){
    consulta += doenca + "\n";
  }
  
  if (no_atual != nullptr){
    return consulta;
  } else {
    return "";
  }
}

void clear_rec(Node* node) {
    if(node != nullptr) {
        clear_rec(node->getLeft());
        clear_rec(node->getRight());
        delete node;
    }
}

void BinaryTree::clear(){
  clear_rec(root);
  root = nullptr;
}

Node* BinaryTree::getRoot(){
  return this->root;
}

void BinaryTree::setRoot(Node* root){
  this->root = root;
}

#endif
