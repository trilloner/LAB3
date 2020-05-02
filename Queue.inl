//
// Created by mamko on 02.05.2020.
//

#ifndef THREAD_QUEUE_QUEUE_INL
#define THREAD_QUEUE_QUEUE_INL
#include <iostream>
#include "Queue.h"
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
}
template <class T>
void Queue<T>::insert(T data) {
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
void Queue<T>::popFront() {
if(empty())
    return;
else if(front==rear){
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
bool Queue<T>::empty() {
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
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
    if(front==NULL){
        return;
    }
    Node<T> *temp=front;
    //will check until NULL is not found
    while(temp){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}
#endif //THREAD_QUEUE_QUEUE_INL
