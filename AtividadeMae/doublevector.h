#ifndef DOUBLEVECTOR_H
#define DOUBLEVECTOR_H

class DoubleVector{
private:
    int* m_list {nullptr}; // ponteiro para a lista
    int m_size {0};       // numero de elementos na lista
    int m_capacity {0};   // capacidade total da lista
    int m_head;
    int m_tail;
public:
    DoubleVector();
    DoubleVector(int size);
    ~DoubleVector();
    int size();
    bool empty();
    void push_back(int value);
    int pop_back();
    void push_front(int value);
    int pop_front();
    int at(int index);
    void shift_left(int value);
    void shift_right(int value);
    void removeAt(int index);
    void removeAll(int value);
    void print();
    void printReverse();
    void concat(DoubleVector& list);
    bool equal(DoubleVector& list);
};
#endif
