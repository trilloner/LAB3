//
// Created by mamko on 02.05.2020.
//

#ifndef THREAD_QUEUE_QUEUE_H
#define THREAD_QUEUE_QUEUE_H

#include <cstddef>
#include "Node.h"
template <class  T>
class Queue{
public:
    Queue();
    ~Queue();
    void insert(T data);
    void popFront();
    int getSize();
    bool empty();
    T getFront();
    T getBack();
    void display();
private:
    int size;
    Node<T>*front,*rear;
};

#include "Queue.inl"
#endif //THREAD_QUEUE_QUEUE_H
