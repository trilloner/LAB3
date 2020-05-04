/**
 * 2nd Course K-28
 * Lab 3a
 * Task: Create multithreading queue
 *
 * Purpose: contains implementation about single Queue
 *
 *@author Bogdan Volokhonenko
 *@version 4/5/20
 */
#ifndef THREAD_QUEUE_QUEUE_H
#define THREAD_QUEUE_QUEUE_H


#include "QueueInterface.h"
#include "Node.h"


template<typename T>
class Queue:public QueueInterface<T>{
public:
    Queue();
    ~Queue();
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
};


#include "Queue.inl"
#endif //THREAD_QUEUE_QUEUE_H
