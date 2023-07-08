#include <iostream>
#include "binarytree.h"

using namespace std;

int main(){
  BinaryTree bt;
  string* sintomas = bt.getSintomas();
  while (true){
    int vet[bt.getNumeroSintomas()];
    char resposta;
    cout << "[S] Voce quer realizar uma consulta? ";
    cin >> resposta;
    if (resposta == 'S'){
      for (int i = 0; i < bt.getNumeroSintomas(); i++){
        cout << "Voce está com " + sintomas[i] << "? ";
        cin >> vet[i];
      }
      cout << "[Resultado da Consulta]" << endl;
      string diagnostico = bt.realizarConsulta(vet);
      if (diagnostico == ""){
        cout << "Homem esse menino ta eh bom" << endl;
      }
      cout << diagnostico;
    } else {
      break;
    }
  }
