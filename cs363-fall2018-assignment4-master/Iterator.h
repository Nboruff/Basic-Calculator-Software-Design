
#ifndef ARRAY_ITER_H
#define ARRAY_ITER_H
#include "Array.h"

template <typename T>
class Array_Iterator
{
  public:
    Array_Iterator(Array<T> &a);
    ~Array_Iterator(void);
    bool is_done(void);
    bool advance(void);
    T &operator*(void);
    T *operator->(void);
  private:
    Array<T> &arr_;
    size_t curr_;
};  

#include "Iterator.cpp"

#endif