#include "binaryTree.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream file("doencas.txt");

    if(!file.is_open())
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return 0;
    }

    int TotalDoencas,TotalSintomas;
    string doencas[41];

    file >> TotalDoencas >> TotalSintomas;
    
    for(int i = 0 ; i < TotalDoencas ; i++){
        file >> doencas[i];
    }

    // imprima os inteiros
    cout << "Total de doencas: " << TotalDoencas << endl;
    cout << "Total de sintomas: " << TotalSintomas << endl;

    for(int i = 0 ; i < TotalDoencas ; i++){
        cout << "Doenca: " << doencas[i] << endl;
    }
    

}
