#ifndef _QUEUE_H_
#define _QUEUE_H_


#include <exception>
#include "Array.h"

template <typename T>
class Queue{
    public:
        /* Default constructor */
        Queue();

        /* Copy Constructor */
        Queue(const Queue &q);

        /* Destructor */
        ~Queue();

        /* adds the element to the end of the list */
        void enqueue(T element);

        /*
        * removes the element at the front of the list. If there are not elements in the queue,  
        * this method throws empty_exception, similar to the stack
        */
        T dequeue();

        /* test if the queue is empty. If the queue is empty, return true, otherwise return false. */
        bool is_empty() const;

        bool is_full() const;
        /* returns the size of the queue */
        size_t size() const;

        /* clears all elements from the queue */
        void clear();

        /* Assignment operator that returns a reference to self */
        const Queue &operator = (const Queue &rhs);

    private:
        size_t rear_;
        size_t front_; 
  // COMMENT There is no need to allocate the array on the heap. Always try to
  // allocate on the stack to reduce the complexity of your code.
  /* RESPONSE used stack allocation instead of pointer */
        Array<T> arr_;
};

#include "Queue.cpp"

#include "Queue.inl"

#endif
