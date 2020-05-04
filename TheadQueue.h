//
// Created by mamko on 02.05.2020.
//

#ifndef THREAD_QUEUE_THEADQUEUE_H
#define THREAD_QUEUE_THEADQUEUE_H
#include <iostream>
#include <cstddef>
#include "Node.h"
#include <condition_variable>
#include <assert.h>
#include "QueueInterface.h"
template <class  T>
class TheadQueue:public QueueInterface<T>{
public:
    TheadQueue(): mtx(), full(), empty(),front(NULL),rear(NULL),size(0){ }
    ~TheadQueue();
    void insert(const T& data) override;
    void popFront() override;
    int getSize() override;
    bool isEmpty() override;
    T getFront() override;
    T getBack() override;
    void display() override;
private:
    int size;
    Node<T>*front,*rear;
    mutable std::mutex mtx;
    std::condition_variable full;
    std::condition_variable empty;
};

#include "TheadQueue.inl"
#endif //THREAD_QUEUE_THEADQUEUE_H
