/**
 * 2nd Course K-28
 * Lab 3a
 * Task: Create multithreading queue
 *
 * Purpose: contains implementation about parallel Queue
 *
 *@author Bogdan Volokhonenko
 *@version 4/5/20
 */
#ifndef THREAD_QUEUE_THEADQUEUE_INL
#define THREAD_QUEUE_THEADQUEUE_INL

#include "TheadQueue.h"

/**
     * Destructor of parallel thread safe Queue
     */
template <class T>
TheadQueue<T>::~TheadQueue() {
    while(front!=NULL)
    {
        Node <T>* temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
    size=0;
}

/**
    * Override function that add data to the  parallel thread safe Queue
    *
    * @param data
    */
template <class T>
void TheadQueue<T>::insert(const T& data) {
    std::cout << std::this_thread::get_id() << " thread waiting to add  " << data << " to the queue"<<std::endl;

    std::unique_lock<std::mutex> lock(mtx);///< lock another threads while one thread using it
    Node<T> *temp=new Node<T>;
    temp->data=data;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    size++;
    empty.notify_all();///<continue all threads
    std::cout << std::this_thread::get_id() << " thread added  " << data << " to the queue"<<std::endl;

}

/**
    * Override function that check parallel thread safe Queue is empty or not
    *
    * @return true if empty,false if not empty
    */
template <class T>
bool TheadQueue<T>::isEmpty() {
    std::cout << std::this_thread::get_id() <<" thread checks if the queue is empty or not"<<std::endl;
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

/**
    * Override function that delete first element in parallel thread safe Queue
    */
template <class T>
void TheadQueue<T>::popFront() {
    std::unique_lock<std::mutex> lock(mtx);///< lock another threads while one thread using it
    while(isEmpty()){
        std::cout << std::this_thread::get_id() <<" thread  stops  until an element will be added "<<std::endl;
        empty.wait(lock); ///<stop all threads and waiting while in queue will be added value
    }

    assert(!isEmpty());
 if(front==rear){
    delete (front);
    front=rear=NULL;
    size--;
}
else{
    Node <T>*temp = front;
    front = front->next;
    delete(temp);
    size--;
}
    std::cout << std::this_thread::get_id() <<" thread  deleted first element from queue "<<std::endl;

}


/**
    *Override function that return last element from parallel thread safe Queue
    *
    * @return rear data
    */
template <class T>
T TheadQueue<T>::getBack() {

    std::unique_lock<std::mutex> lock(mtx);///< lock another threads while one thread using it
    assert(rear!=NULL);
    std::cout << std::this_thread::get_id() << " thread returned element from back"<<std::endl;

    return rear->data;
}

/**
 * Override function that return first element  from parallel thread safe Queue
 *
 * @return front data
 */
template <class T>
T TheadQueue<T>::getFront() {
    std::unique_lock<std::mutex> lock(mtx);///< lock another threads while one thread using it
    assert(front!=NULL);
    std::cout << std::this_thread::get_id() << " thread returned element from front"<<std::endl;

    return front->data;
}

/**
     * Override function that return size of parallel thread safe Queue
     *
     * @return size
     */
template <class T>
int TheadQueue<T>::getSize() {
    std::unique_lock<std::mutex> lock(mtx);///< lock another threads while one thread using it
    return size;
}

    /**
     *Override function that display all values from parallel thread safe Queue on screen
     */
template <class T>
void TheadQueue<T>::display() {
    std::unique_lock<std::mutex> lock(mtx); ///< lock another threads while one thread using it
    while(front==NULL){
        empty.wait(lock); ///<stop all threads and waiting while in queue will be added value
    }
    assert(front!=NULL);
    Node<T> *temp=front;
    //will check until NULL is not found
    std::cout << "Display queue: "<<" ";
    while(temp){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}
#endif //THREAD_QUEUE_THEADQUEUE_INL
