// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void) :
    Base_Array<T>(),
    max_size_(SIZE)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length) : 
    Base_Array<T>(length),
    max_size_(length)
{

}
//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array(size_t length, T fill) :
    Base_Array<T>(length, fill),
    max_size_(length)
{

}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array(const Array &array) : 
    Base_Array<T>(array.max_size()),
    max_size_(array.max_size_)
{
    this->cur_size_ = array.cur_size_;
    for (int i = 0; i < array.cur_size_; ++i)
    {
        this->data_[i] = array[i];
    }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
}

//
// operator =
//
template <typename T>
const Array <T> &Array <T>::operator = (const Array &rhs)
{

    if (this != &rhs)
    {
        for (int i = 0; i < rhs.cur_size_; ++i)
        {
            this->data_[i] = rhs.data_[i];
        }

        this->cur_size_ = rhs.cur_size_;

        this->max_size_ = rhs.max_size_;
        return *this;
    }
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    int size = this->cur_size_;
    this->cur_size_ = new_size;
    
    if (new_size > this->max_size_)
    {
        T *resizedArray = new T[new_size];
        this->max_size_ = new_size;
        for (int i = 0; i < size; ++i)
        {
            resizedArray[i] = this->data_[i];
        }
        T * temp = nullptr;

        temp = this->data_;
        this->data_ = resizedArray;
        resizedArray = temp;

        delete[] temp;
        temp = nullptr;
        resizedArray = nullptr;
    }
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array &rhs) const
{
    if (this != &rhs)
    {
        for (int i = 0; i < this->cur_size_; ++i)
        {
            if (this->data_[i] != rhs[i])
            {
                return false;
            }
        }
    }
    return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array &rhs) const
{
    return (!Array<T>::operator==(rhs));
}

template <typename T>
void Array<T>::shrink(void)
{

    if (this->max_size_ > this->cur_size_)
    {

        T *shrunkArray = new T[this->cur_size_];
        this->max_size_ = this->cur_size_;

        for (int i = 0; i < this->cur_size_; ++i)
        {
            shrunkArray[i] = this->data_[i];
        }

        T *temp = nullptr;

        temp = this->data_;
        this->data_ = shrunkArray;
        shrunkArray = temp;

        delete[] temp;
        temp = nullptr;
        shrunkArray = nullptr;
    }
}