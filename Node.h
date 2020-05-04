/**
 * 2nd Course K-28
 * Lab 3a
 * Task: Create multithreading queue
 *
 * Purpose: contains declaration about Node for queue
 *
 *@author Bogdan Volokhonenko
 *@version 4/5/20
 */
#ifndef THREAD_QUEUE_NODE_H
#define THREAD_QUEUE_NODE_H


/**
 * Template Queue class that Node will use
 */
template <typename T>
class Queue;
/**
 * Template Thread Queue class that Node will use
 *
 */
template <class T>
class TheadQueue;

/**
 * Template class of the Node to be contained in the lists
 */
template <typename T>
class Node
{
    friend class Queue<T>; ///< friend class which will be using Node structure
    friend class TheadQueue<T>; ///< friend class which will be using Node structure
public:

    /**
    * Default constructor
    */
    Node();

    /**
    * Constructor with Template param
    *
    * @param value will be added templatized data stored in node
    */
    Node(T node);

    /**
     * Returns templatized data stored in node
     *
    * @return data
    */
    T getData() const;

    /**
     * Returns pointer to the next Node in the list
    *
    * @return next
    */
    Node<T>*getNext() const;

    /**
    * Returns pointer to the previous Node in the list
    *
    * @return prev
    */
    Node<T>*getPrevious() const;

private:
    T data; ///<templatized data stored in node
    Node<T>*next;///<pointer to the next node in list
    Node<T>*prev;///<pointer to the prev node in list

};

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



#endif //THREAD_QUEUE_NODE_H
