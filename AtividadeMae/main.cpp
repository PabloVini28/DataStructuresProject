#include "doublevector.h"
#include <iostream>

using namespace std;

// DUPLA :
// ALUNO : PABLO VINICIOS DA SILVA ARAUJO || MATRÍCULA : 538616
// ALUNO : DAVID SILVA FERNANDES DE OLIVEIRA || MATRÍCULA : 539402
// PROFESSOR : FÁBIO CARLOS SOUSA

// OBS : USAMOS SUA MAIN, PROFESSOR, COMO BASE PARA FAZER A NOSSA E TESTAR AS FUNÇÕES.

int main()
{
	// Em primeiro plano, começamos adotando um tamanho para as listas, par e ímpar, e
	// o usuário começa o preenchimento delas.
	// Os números pares e ímpares irão para suas respectivas listas

	cout << "Informe o um valor que preenchera as listas (Par e Impar)"<<endl; 

	int n, k;
	cin >> n;

	DoubleVector listaPares(n), listaImpares(n);

	cout << "preencha com o numero de elementos que voce adotou anteriormente" << endl;

	for (int i = 0; i < n; ++i){
		cin>>k;
		if (k % 2 == 0){
				listaPares.push_back(k);
		}else{
			listaImpares.push_back(k);
		}
	}

	cout << endl;

	//Com base nas listas preenchidas, o usuário poderá agora usar as funções
	//que lhe serão apresentadas durante o desenrolar da execução

	cout << "Testa o construtor default, funcoes push_back e at" << endl;
	cout << "Lista par e Lista impar, respectivamente"<<endl;
	listaPares.print();
	listaImpares.print();

	cout<<endl;

	cout << "Testa a funcao print reverso" << endl;
	listaPares.printReverse();
	listaImpares.printReverse();

	cout << endl;

	cout << "Testa a funcao pop_back, removendo o ultimo elemento em cada lista" << endl;

	listaPares.pop_back();
	listaImpares.pop_back();
	listaPares.print();
	listaImpares.print();

	cout << endl;

	cout << "Testa a funcao removeAt" << endl;
	cout << "Informe dois INDICIES, um para a lista par e outro para lista impar,"<< endl;
	cout << "Eles serao removidos, respectivamente" << endl;
	int index;
	cin >> index;
	listaPares.removeAt(index);
	int index2;
	cin >> index2;
	listaImpares.removeAt(index2);
	cout << "Lista par e impar, respectivamente, com seus indicies removidos" << endl;
	listaPares.print();
	listaImpares.print();
	
	cout << endl;

	cout << "Testa a funcao removeAll" << endl;
	cout << "informe o elemento o qual queira remover as ocorrencias dele na lista par, logo em seguida,na impar"<< endl;
	int value;
	cin >> value;
	listaPares.removeAll(value);
	int value2;
	cin >> value2;
	listaImpares.removeAll(value2);
	cout << "Lista par e impar, respectivamente, com suas ocorrencias removidas" << endl;
	listaPares.print();
	listaImpares.print();

	cout << endl;

	cout << "Testa a funcao push_front" << endl;
	cout << "Informe qual valor inserir na lista par, logo em seguida na impar" << endl;
	int p;
	cin >> p;
	listaPares.push_front(p);
	cin >> p;
	listaImpares.push_front(p);
	cout << "Lista par e impar, respectivamente com os novos valores alocados" << endl;
	listaPares.print();
	listaImpares.print();

	cout << endl;
	// Nesse momento, a função concat irá concatenar as listas e
	// logo em seguida, a lista par continuará a ser modificada.
	// Foram feitos testes concatenando ambas e decidimos não usar 
	// a função de copy, para guardar a lista anterior antes de concatenar.
	
	cout << "Testa a funcao concat" << endl;
	cout << "A lista par esta concatenando com impar" << endl;
	listaPares.concat(listaImpares);
	cout << "Lista par e impar, respectivamente, com seus valores concatenados" << endl;
	listaPares.print();
	cout << endl;
	// A função pop será executada removendo uma vez no início de cada lista
	// Logo em seguida mostrará ao usuário

	cout << endl;

	cout << "Testa a funcao pop front" << endl;
	listaPares.pop_front();
	listaImpares.pop_front();
	cout << "Lista par e impar, respectivamente, com o primeiro elemento removido"<<endl;
	listaPares.print();
	listaImpares.print();

	cout << endl;

	// Nesse momento decidimos usar a seguinte estratégia para testar a equals
	// Criamos duas listas do mesmo tamanho, e de acordo com o preenchimento e tamanho
	// retornará se elas são iguais ou não.
	cout << "Testa a funcao equals" << endl;
	cout << "Informe o tamanho das listas que serao comparadas" << endl;
	
	int tam,tam2;
	cin >> tam;
	cin>> tam2;

	cout << "Preencha as listas com seus respectivos tamanhos" << endl;

	DoubleVector novaLista(tam);
	DoubleVector novaLista2(tam2);
	for(int i = 0; i < tam; i++){
		int val;
		cin >> val;
		novaLista.push_back(val);
	}
	for (int i = 0; i < tam2; i++){
		int val;
		cin >> val;
		novaLista2.push_back(val);
	}
	novaLista.equal(novaLista2);

}