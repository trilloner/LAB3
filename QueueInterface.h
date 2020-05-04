/**
 * 2nd Course K-28
 * Lab 3a
 * Task: Create multithreading queue
 *
 * Purpose: contains declaration about QueueInterface
 *
 *@author Bogdan Volokhonenko
 *@version 4/5/20
 */
#ifndef THREAD_QUEUE_QUEUEINTERFACE_H
#define THREAD_QUEUE_QUEUEINTERFACE_H

template <class T>
class QueueInterface{
public:
    virtual void insert(const T& data)=0;

    virtual void popFront()=0;

    virtual int getSize() {return 0;}

    virtual bool isEmpty(){return 0;}

    virtual T getFront(){return 0;}

    virtual T getBack(){return 0;}

    virtual void display()=0;
};



#endif //THREAD_QUEUE_QUEUEINTERFACE_H
