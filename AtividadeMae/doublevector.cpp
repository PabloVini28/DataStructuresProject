#ifndef DOUBLEVECTOR_CPP
#define DOUBLEVECTOR_CPP
#include <iostream>
#include "doublevector.h"

using namespace std;

DoubleVector::DoubleVector()
{
    m_capacity = 16;         // Construtor da classe modo default
    m_size = 0;
    m_head = 7;
    m_tail = m_head + 1;
    m_list = new int[m_capacity];
}

DoubleVector::DoubleVector(int n)
{
    m_capacity = n;                 // Construtor da classe fornecendo um tamanho como parâmetro e adotando
    m_size = 0;                     // suas respectivas posições no que tange m_head e m_tail e criando uma lista com a capacidade.
    m_head = (m_capacity / 2) - 1;
    m_tail = m_head + 1;
    m_list = new int[m_capacity];
}

DoubleVector::~DoubleVector()
{
    delete[] m_list;                // Destrutor da classe.
}

int DoubleVector::size()
{
    return m_size;                  // Retorna o tamanho.
}

//verifica se a lista esta vazia
bool DoubleVector::empty(){ 
    if (m_size == 0)
    {
        return true;               // Verifica se a lista está vazia.
    }
    else
        return false;
}

int DoubleVector::at(int index){

    index = index + m_head + 1;
    if (index == m_head + 1){      
        return m_list[m_head + 1]; 
    }                              
    else if (index == m_tail - 1)                      //Converte o indice do parâmetro para o índice da lista
    {                                                  // com isso, podemos usar essa conversão para retornar
        return m_list[m_tail - 1];                     // o elemento da lista no indície caso ele esteja mo começo, final ou no meio
    }
    else if (index > m_head + 1 && index < m_tail - 1)
    {
        return m_list[index];
    }
    else
    {
        return -1;
    }
}

void DoubleVector::push_back(int value)
{
    if (m_tail < m_capacity)                     
    {                                            
        m_list[m_tail] = value;                // Caso haja espaço para a direita, ele adiciona o valor na lista.
        m_tail++;
        m_size++;
    }
    else if (m_tail >= m_capacity && m_head >= 0)
    {                                          
        int aux = (m_capacity - m_size) / 2;   // Caso a lista lote por completo para a direita guardamos em um auxiliar o número de movimentações.
        shift_left(aux);                       // Aplicamos o shift para esquerda.
        m_list[m_tail] = value;                // Após ele fazer o deslocamento, ele adiciona no espaço livre. 
        m_tail++;
        m_size++;
    }
    else if(m_size == m_capacity){             // E caso a lista fique totalmente cheia, usamos o redimensionamento.
        resize();                              // Com isso, dobramos a capacidade da lista, possibilitando adicionar mais elementos
        m_list[m_tail] = value;
        m_tail++;
        m_size++;;
    }
}

int DoubleVector::pop_back()
{
    if (!empty())                  // Verifica se a lista está vazia.
    {
        m_tail--;                 // Reduz o indície de m_tail para o último elemento da lista.
        int aux = m_list[m_tail]; // Pega o último valor
        m_size--;                 // Diminui o tamanho
        return aux;               // Retorna esse valor
    }
    else
    {
        return -1;                // Caso não tenha nada na lista, ele retorna -1.
    }
}

int DoubleVector::pop_front(){
    if (empty()){               // Verifica se a lista está vazia.
        return -1;              // Caso esteja, retorna -1.
    }
    else{
       int aux = m_head+1;     // Guarda o primeiro valor da lista.
       removeAt(0);            // Usa a função removeAt para remover o primeiro da lista.
       return aux;             // Retorna o valor guardado.
    }
}

void DoubleVector::push_front(int value)
{
    if (m_head >= 0)                   // Verifica se há espaço no lado esquerdo.
    {
        m_list[m_head] = value;       // Caso haja, um novo elemento é adicionado na esquerda.
        m_head--;                   
        m_size++;
    }
    else if (m_head == -1 && m_tail < m_capacity) // Caso não haja espaço na esquerda e somente na direita.
    {
        int aux = (m_capacity - m_size) / 2;     // Calcula-se o número de movimentações.
        shift_right(aux);                       // É feito os deslocamento.
        m_list[m_head] = value;                 // Após o deslocamento, adiciona-se o novo valor.
        m_head--;
    }
    else if(m_size == m_capacity)               //Caso a lista esteja cheia, é feito um redimensionamento
    {                                           //Após isso um valor pode adicionado.
        resize();
        m_list[m_head] = value;
        m_head--;
        m_size++;
    }
}

void DoubleVector::shift_right(int value)
{
        int aux = value;                                                                 
        for (int i = 0; i < aux; i--)               // Essa função será executada caso a lista esteja cheia para a esquerda.
        {        
            m_list[m_tail] = m_list[m_tail-1];     // O  m_tail vai receber o ultimo elemento da lista.
            for(int i = m_tail-1 ; i > m_head ; i--) // Percorre mudando os valores e no final incrementando m_head e m_tail.
            {
                m_list[i] = m_list[i-1];
            }                               
            m_head++;
            m_tail++;                  
        }
        
}


void DoubleVector::shift_left(int value)
{
    int aux = value;                             //Analogamente ao que é feito no shift rigth, o shift vai ter o mesmo comportamento.
    for (int i = 0; i < aux; i++)                //Dessa vez, percorrendo e realocando a esquerda.
    {
        m_list[m_head] = m_list[m_head + 1];
        for (int i = m_head + 1; i < m_tail; i++)
        {
            m_list[i] = m_list[i + 1];
        }
        m_tail--;
        m_head--;
    }
}

void DoubleVector::print(){
    
    for (int i = 0; i < m_size; i++)        //Função para printar os valores da lista.
    {                                       // Usamos o at para ir testando ele também.
        cout << at(i) << " ";;
    }
    cout << endl;
}

void DoubleVector::printReverse()
{
    for (int i = m_size - 1; i >= 0; i--) //Mesmo comportamento do print, porém imprimindo ao contrário 
    {
        cout << at(i) << " ";
    }
    cout << endl;
}

void DoubleVector::resize()
{                                 
                                 // Aqui ocorrerá o redimensionamento da lista.

    int *aux = new int[m_size];  // Um vetor auxiliar que guardará o tamanho da lista.

    for (int i = 0; i < m_size; i++)
    {
        aux[i] = m_list[m_head + 1 + i];  // Preencher o vetor com lista antiga.
    }

    m_capacity = m_capacity * 2;         // Dobrando a capacidade, obedecendo ao que diz o pdf. Deletando a lista e criando outra com 
    delete[] m_list;                     // a nova capacidade.
    m_list = new int[m_capacity];

    m_head = ((m_capacity - m_size) / 2) - 1; //Calculamos e guardamos o valores dos indicies que ficarão em m_head e m_tail.
    m_tail = (m_head + m_size) + 1;           

    for (int i = 0; i < m_size; i++)
    {
        m_list[m_head + i + 1] = aux[i];    //Preenchemos nova lista com os valores guardados na passada.
    }
     
    delete[] aux;                          // Lista auxiliar é deletada.
    
}

void DoubleVector::removeAt(int index)
{                             
    if (empty())
    {
        return;
    }
    index = m_head + index + 1;
    if (index == m_head + 1)
    {
        m_list[m_head] = m_list[m_head + 1];
        for (int i = index; i < m_tail; i++)     // Esta função removerá no indície escolhido pelo usuário.
        {                                        // Primeiro é feito o cálculo do indície que deve ser removido na lista 
            m_list[i] = m_list[i + 1];           // obedecendo o pdf da atividade mãe
        }                                        // Caso o indicie seja o primeiro, retiramos e realocamos a lista,
        m_tail--;                                // caso seja o último só diminuímos o tamanho e m_tail 
        m_size--;                                // e caso indície esteja no meio ele, analogamente ele realoca e remove
    }
    else if (index == m_tail - 1)
    {
        m_tail--;
        m_size--;
    }
    else if (index > m_head + 1 && index < m_tail - 1)
    {
        m_list[index] = 0;
        m_list[m_head] = m_list[m_head + 1];
        for (int i = index; i < m_tail - 1; i++)
        {
            m_list[i] = m_list[i + 1];
        }
        m_tail--;
        m_size--;
    }
}

void DoubleVector::removeAll(int value)
{
    int cont = 0;
    if (!empty())
    {
        for (int i = m_head + 1; i < m_tail; i++)
        {
            if (m_list[i] == value)
            {
                cont++;                          // Essa função guarda o número de ocorrências do valor o qual o usuário
            }                                    // quer remover. Logo em seguida, usa esse valor como contador para remover
        }                                        // o valor, percorrendo a lista e, caso encontre, remova e realoque.
        for (int i = 0; i < cont; i++)
        {
            for (int i = m_head + 1; i < m_tail; i++)
            {
                if (m_list[i] == value)
                {
                    int aux = i;
                    for (int i = aux; i < m_tail; i++)
                    {
                        m_list[i] = m_list[i + 1];
                    }
                    m_tail--;
                    m_size--;
                }
            }
        }
    }
}

void DoubleVector::concat(DoubleVector &lst)
{
    int cont = 0;
    for (int i = lst.m_head + 1; i < lst.m_tail; i++)
    {
        cont++;
    }
    for (int i = lst.m_head + 1; i < lst.m_head + cont + 1; i++)  // Esta função concatenará duas listas primeiro adotando um contador
    {                                                             // contendo o tamanho da lista passada como parâmetro, logo em seguida
        push_back(lst.m_list[i]);                                 // Adicionará a no final usando a função push_back.
    }
}

bool DoubleVector::equal(DoubleVector &lst)
{

    if (m_size != lst.m_size)
    {
        cout << "Listas Diferentes" << endl;                     // Essa função comparará se a lista principal é igual a lista
        return false;                                            // passada como parâmetro, ou seja, se possuem capacidade e 
    }                                                            // elementos iguais.
    for (int i = m_head + 1; i < m_tail; i++)
    {
        if (m_list[i] != lst.m_list[i])
        {
            cout << "Listas Diferentes" << endl;
            return false;
        }
    }
    cout << "Listas iguais" << endl;
    return true;
}

#endif
