// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include <iostream>
//
// Stack
//

/**
 * Default constructor which assigns the Stack's Array pointer
 * to a new Array object. 
 * Then set the top_ index to 0
 */
template <typename T>
Stack <T>::Stack (void) :
    arr_(Array<T>()),
    top_(0)
{

}

//
// Stack
//
/**
 * Copy constructor uses the Array copy constructor and sets the
 * top_ to be the same as the stack passed to it
 */
template <typename T>
Stack <T>::Stack (const Stack &stack) :
    arr_(Array<T>(stack.arr_)),
    top_(stack.top_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
}

//
// push
//
/**
 * Increment the top_ to indicate the top of the stack changing.
 * resize the stack to the new top value and then set the top 
 * value to the element desired.
 */
template <typename T>
void Stack <T>::push (T element)
{
    ++this->top_;
    this->arr_.resize(this->top_);
    this->arr_.set(this->top_ - 1, element);
}

//
// pop
//
/* Removes the top element of the Stack*/
template <typename T>
void Stack <T>::pop (void)
{
    /**
     * First check if the stack is empty and throw an error if it is.
     * If it is not empty then decrement the top to indicate where the 
     * new top element will be
     */ 
    if(this->is_empty()){
        Stack::empty_exception myexcept;
        throw myexcept;
    }
    --this->top_;
    /**
     * Resize the Array object belonging to the Stack to the size indicated
     * by the top.
     */
    this->arr_.resize(this->top_);
  // COMMENT You have resized the array, and now you are making a copy of
  // it. You are basically doing the same thing twice since resize will do
  // the same as what you are doing below.
    /* RESPONSE removed the problem code and used shrink to delete the element */
    this->arr_.shrink();
}

//
// operator =
//
/**
 * Make sure the Stack is empty. IF not, clear it. 
 * Then copy the elements from the right hand side to the left and return
 * a reference to self
 */
template <typename T>
const Stack <T> &Stack <T>::operator = (const Stack &rhs)
{
    if(this->top_ > 0){
        this->clear();
    }
    if(this != &rhs){
        for (int i = 0; i < rhs.size(); ++i){
            this->push(rhs.arr_.get(i));
        }
    }
    return *this;
}

//
// clear
//
/* Loops through the Stack and pops every element off of the Stack*/
template <typename T>
void Stack <T>::clear (void)
{
  // COMMENT Just reset the variables instead popping each element, which
  // is expensive.
  /* RESPONSE resets the array variable to a new one of the same current size and resets the top */
    this->arr_ = Array<T>(this->size());
    this->top_ = 0;
}
