/**
 * 2nd Course K-28
 * Lab 3a
 * Task: Create multithreading queue
 *
 * Purpose: contains declaration about parallel Queue
 *
 *@author Bogdan Volokhonenko
 *@version 4/5/20
 */

#ifndef THREAD_QUEUE_THEADQUEUE_H
#define THREAD_QUEUE_THEADQUEUE_H
#include <iostream>
#include <cstddef>
#include "Node.h"
#include <condition_variable>
#include <assert.h>
#include "QueueInterface.h"
/**
 * Template class of parallel thread safe Queue
 *
 * @tparam T
 */
template <class  T>
class TheadQueue:public QueueInterface<T>{
public:
    /**
     * Constructor of parallel thread safe Queue
     */
    TheadQueue(): mtx(),empty(),front(NULL),rear(NULL),size(0){ }

    /**
     * Destructor of parallel thread safe Queue
     */
    ~TheadQueue();

    /**
    * Override function that add data to the  parallel thread safe Queue
    *
    * @param data
    */
    void insert(const T& data) override;

    /**
     * Override function that delete first element in parallel thread safe Queue
     */
    void popFront() override;

    /**
     * Override function that return size of parallel thread safe Queue
     *
     * @return size
     */
    int getSize() override;

    /**
     * Override function that check parallel thread safe Queue is empty or not
     *
     * @return bool
     */
    bool isEmpty() override;

    /**
     * Override function that return first element  from parallel thread safe Queue
     *
     * @return front
     */
    T getFront() override;

    /**
     *Override function that return last element from parallel thread safe Queue
     *
     * @return rear
     */
    T getBack() override;

    /**
     *Override function that display all values from parallel thread safe Queue on screen
     */
    void display() override;

private:
    int size;
    Node<T>*front,*rear;
    mutable std::mutex mtx; ///< lock another threads while one thread using it
    std::condition_variable empty; ///<to stop and continue  all threads
};

#include "TheadQueue.inl"
#endif //THREAD_QUEUE_THEADQUEUE_H
