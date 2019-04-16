// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return arr_.size();
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    /**
     * checks to see if the stack is empty and throws an error if it is, otherwise
     * return the top element
     */ 
    if(this->is_empty()){
        empty_exception myexcept("Cannot access top element. The Stack is empty.");
        throw myexcept;
    }
    return this->arr_.get(this->top_ - 1);
}

//
// is_empty
//
/* returns if the stack is empty or not */
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return this->top_ == 0;
}
