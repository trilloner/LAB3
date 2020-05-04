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

#include "Queue.h"
#include <iostream>
#include <assert.h>

template <class T>
Queue<T>::Queue() {
    front=rear=NULL;
    size=0;
}
template <class T>
Queue<T>::~Queue() {
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
void Queue<T>::insert(const T& data) {
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
}
template <class T>
bool Queue<T>::isEmpty() {
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

template <class T>
void Queue<T>::popFront() {
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
T Queue<T>::getBack() {
    assert(rear!=NULL);

    return rear->data;
}
template <class T>
T Queue<T>::getFront() {
    assert(front!=NULL);

    return front->data;
}

template <class T>
int Queue<T>::getSize() {
    return size;
}
template <class T>
void Queue<T>::display() {
    assert(front!=NULL);
    Node<T> *temp=front;
    //will check until NULL is not found
    while(temp){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}
