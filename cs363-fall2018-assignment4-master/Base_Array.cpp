#include "Base_Array.h"
#include <stdexcept>
#define SIZE 100
/* default constructor with default Size*/
template <typename T>
Base_Array<T>::Base_Array(void) : 
    data_(new T[SIZE]),
    cur_size_(SIZE)
{

}

/**
 * Initializing constructor that takes some length to determine the size
 * and sets the current size to the length given.
 */
template <typename T>
Base_Array<T>::Base_Array(size_t length) : 
    data_(new T[length]),
    cur_size_(length)
{
}

/**
 * Initializing constructor that takes some length and some value. 
 * Size is initialized to the given length value and then the array is filled
 * with the given fill value.
 */
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill) : 
    data_(new T[length]),
    cur_size_(length)
{
    for (int i = 0; i < length; ++i)
    {
        this->data_[i] = fill;
    }
}

/* default destructor. deletes the pointer to the data contained in the array */
template <typename T>
Base_Array<T>::~Base_Array(void)
{
    delete[] this->data_;
}

/* returns the value at the given index. immutable */
template <typename T>
T Base_Array<T>::get(size_t index) const
{
    if (index >= this->cur_size_)
    {
        throw std::out_of_range("The index provided is not contained in the array.");
    }

    return this->data_[index];
}

/* sets the value at the given index to some given value */
template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
    if (index >= this->cur_size_)
    {
        throw std::out_of_range("The index provided is not contained in the array.");
    }

    this->data_[index] = value;
}

/**
 * overloaded indexing operator: returns the value at the 
 * given index in the array.
 * Mutable
 */
template <typename T>
T & Base_Array<T>::operator [] (size_t index)
{
    if (index >= this->cur_size_)
    {
        throw std::out_of_range("The index provided is not contained in the array.");
    }

    return this->data_[index];
}

/**
 * overloaded indexing operator: returns the value at the 
 * given index in the array.
 * Immutable
 */
template <typename T>
const T & Base_Array<T>::operator [] (size_t index) const
{
    if (index >= this->cur_size_)
    {
        throw std::out_of_range("The index provided is not contained in the array.");
    }

    return this->data_[index];
}


// returns an immutable integer that indicates where the given value was found at.
template <typename T>
int Base_Array<T>::find(T value) const
{
    for (int i = 0; i < this->cur_size_; ++i)
    {
        if (this->data_[i] == value)
        {
            return i;
        }
    }
    return -1;
}

/**
 * returns an immutable integer that indicates where the given value 
 * was found at, starting from a given position.
 */
template <typename T>
int Base_Array<T>::find(T val, size_t start) const
{
    if (start >= this->cur_size_)
    {
        throw std::out_of_range("The index provided is not contained in the array.");
    }
    for (start; start < this->cur_size_; ++start)
    {
        if (this->data_[start] == val)
        {
            return start;
        }
    }
    return -1;
}

/* Fills the array with some given value, overriding whatever was previously there */
template <typename T>
void Base_Array<T>::fill(T value)
{
    for (int i = 0; i < this->cur_size_; ++i)
    {
        this->data_[i] = value;
    }
}