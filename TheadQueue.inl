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
template <class T>
void TheadQueue<T>::insert(const T& data) {
    std::unique_lock<std::mutex> lock(mtx);
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
    empty.notify_all();
}
template <class T>
bool TheadQueue<T>::isEmpty() {
    //std::unique_lock<std::mutex> lock(mtx);
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

template <class T>
void TheadQueue<T>::popFront() {
    std::unique_lock<std::mutex> lock(mtx);
    while(isEmpty()){
        empty.wait(lock);
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
}



template <class T>
T TheadQueue<T>::getBack() {

    std::unique_lock<std::mutex> lock(mtx);
    assert(rear!=NULL);

    return rear->data;
}
template <class T>
T TheadQueue<T>::getFront() {
    std::unique_lock<std::mutex> lock(mtx);
    assert(front!=NULL);

    return front->data;
}

template <class T>
int TheadQueue<T>::getSize() {
    std::unique_lock<std::mutex> lock(mtx);
    return size;
}
template <class T>
void TheadQueue<T>::display() {
    std::unique_lock<std::mutex> lock(mtx);
    while(front==NULL){
        empty.wait(lock);
    }
    assert(front!=NULL);
    Node<T> *temp=front;
    //will check until NULL is not found
    while(temp){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}
#endif //THREAD_QUEUE_THEADQUEUE_INL
