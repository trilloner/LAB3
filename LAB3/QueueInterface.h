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

/**
 * Template interface class for single and parallel Queue
 *
 * @tparam T
 */
template <class T>
class QueueInterface{
public:
    /**
     * Virtual function that add data to the single queue
     *
     * @param data
     */
    virtual void insert(const T& data)=0;

    /**
     * Virtual function that delete first element in queue
     */
    virtual void popFront()=0;

    /**
     * Virtual function that return size of queue
     *
     * @return size
     */
    virtual int getSize() {return 0;}

    /**
     * Virtual function that check the single queue is empty or not
     *
     * @return bool
     */
    virtual bool isEmpty(){return 0;}

    /**
     * Virtual function that return first element in the single queue
     *
     * @return front
     */
    virtual T getFront(){return 0;}

    /**
     *Virtual function that return last element in the single queue
     *
     * @return rear
     */
    virtual T getBack(){return 0;}

    /**
     *Virtual function that display all single queue on screen
     */
    virtual void display()=0;

};



#endif //THREAD_QUEUE_QUEUEINTERFACE_H
