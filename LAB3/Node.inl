/**
 * 2nd Course K-28
 * Lab 3a
 * Task: Create multithreading queue
 *
 * Purpose: contains implementation about Node for queue
 *
 *@author Bogdan Volokhonenko
 *@version 4/5/20
 */
#ifndef THREAD_QUEUE_NODE_INL
#define THREAD_QUEUE_NODE_INL
#include "Node.h"
/**
* Default constructor
*/
template <class T>
Node<T>::Node() {
    next=0;
    prev=0;
}
/**
 * Constructor with Template param
 *
 * @param value will be added in templatized data stored in node
 */
template <class T>
Node<T>::Node(T value) {
    data = value;
    next= 0;
    prev= 0;
}
/**
 * Returns templatized data stored in node
 *
 * @return data
 */
template <class T>
T Node<T>::getData() const {
    return data;
}

/**
 * Returns pointer to the next Node in the list
 *
 * @return next
 */
template<class T>
Node<T>* Node<T>::getNext() const {
    return next;
}
/**
 * Returns pointer to the previous Node in the list
 *
 * @return prev
 */
template<class T>
Node<T>* Node<T>::getPrevious() const {
    return prev;
}

#endif //THREAD_QUEUE_NODE_INL
