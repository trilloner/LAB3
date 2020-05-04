/**
 * 2nd Course K-28
 * Lab 3a
 * Task: Create multithreading queue
 *
 * Purpose: contains declaration about single Queue
 *
 *@author Bogdan Volokhonenko
 *@version 4/5/20
 */
#ifndef THREAD_QUEUE_QUEUE_H
#define THREAD_QUEUE_QUEUE_H


#include "QueueInterface.h"
#include "Node.h"

/**
 * Template class of single Queue
 *
 * @tparam T
 */
template<typename T>
class Queue:public QueueInterface<T>{
public:
    /**
     * Constructor of single queue
     */
    Queue();

    /**
     * Destructor of single queue
     */
    ~Queue();
    /**
     * Override function that add data to the single queue
     *
     * @param data
     */
    void insert(const T& data) override;

    /**
     * Override function that delete first element in queue
     */
    void popFront() override;

    /**
     * Override function that return size of queue
     *
     * @return size
     */
    int getSize() override;

    /**
     * Override function that check the single queue is empty or not
     *
     * @return bool
     */
    bool isEmpty() override;

    /**
     * Override function that return first element in the single queue
     *
     * @return front
     */
    T getFront() override;

    /**
     *Override function that return last element in the single queue
     *
     * @return rear
     */
    T getBack() override;

    /**
     *Override function that display all single queue on screen
     */
    void display() override;

private:
    int size;
    Node<T>*front,*rear;
};


#include "Queue.inl"
#endif //THREAD_QUEUE_QUEUE_H
