#include <iostream>
#include "binarytree.h"

// DISCENTES : 
// PABLO VINÍCIOS DA SILVA ARAÚJO - 538616
// DAVID SILVA FERNANDES DE OLIVEIRA - 539402

// PROFESSOR, CRIAMOS ESSE PEQUENO MENU INTERATIVO PARA ATENDER AO QUE FOI REQUISITADO
// NA DESCRIÇÃO DO PDF DA ATIVIDADE PAI!

using namespace std;

int main(){

  // A princípio, a main.cpp englobará a criação e tratamento da árvore
  // de acordo com os inteiros no começo do arquivo dataset. Após receber os parâmetros um laço
  // for ficará responsável por percorrer todos os sintomas e fazer a leitura do 0 ou 1
  // caso o preenchimento tenha sido congruente com o arquivo, o código retornará a doença
  // ou caso seja incompatível, impimirá uma mensagem de diagnóstico não encontrado. 

  BinaryTree bt;
  string* sintomas = bt.getSintomas();
  while (true){
    int vet[bt.getNumeroSintomas()];
    char resposta;
    cout << "Voce quer realizar uma consulta? [S/N]";
    cin >> resposta;
    if (resposta == 'S'|| resposta == 's'){
      for (int i = 0; i < bt.getNumeroSintomas(); i++){
        cout << "You are feeling " + sintomas[i] << "? ";
        cin >> vet[i];
      }
      cout << "[Resultado da Consulta]" << endl;
      string diagnostico = bt.realizarConsulta(vet);
      if (diagnostico == ""){
        cout << "Diagnostico nao encontrado" << endl;
      }
      cout << diagnostico;
    } else {
      break;
    }
  }
}
