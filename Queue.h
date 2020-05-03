//
// Created by mamko on 02.05.2020.
//

#ifndef THREAD_QUEUE_QUEUE_H
#define THREAD_QUEUE_QUEUE_H
#include <iostream>
#include <cstddef>
#include "Node.h"
#include <condition_variable>
#include <assert.h>

template <class  T>
class Queue{
public:
    Queue(): mtx(), full(), empty(),front(NULL),rear(NULL),size(0){ }
    ~Queue();
    void insert(const T& data);
    void popFront();
    int getSize();
    bool isEmpty();
    T getFront();
    T getBack();
    void display();
private:
    int size;
    Node<T>*front,*rear;
    mutable std::mutex mtx;
    std::condition_variable full;
    std::condition_variable empty;
};

#include "Queue.inl"
#endif //THREAD_QUEUE_QUEUE_H
