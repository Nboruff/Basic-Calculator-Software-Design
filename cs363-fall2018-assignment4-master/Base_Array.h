#ifndef BASE_ARRAY_H
#define BASE_ARRAY_H
#include <cstring>

template <typename T>
class Base_Array{
    public:
      /* default constructor */
      Base_Array();

      /* initializing constructor that takes some length */
      Base_Array(size_t length);

      /**
       * initializing constructor that takes some length as well as a value
       * to fill the array with.
       */
      Base_Array(size_t length, T fill);

      /* default destructor */
      ~Base_Array();

  // COMMENT There is no need to make this method virtual since it will
  // be the same for all arrays.
  /* RESPONSE removed pure virtual for normal declaration */
      /* overloaded indexing operators */
      T & operator [] (size_t index);
        
  // COMMENT There is no need to make this method virtual since it will
  // be the same for all arrays.
  /* RESPONSE removed pure virtual for normal declaration */
      const T & operator [] (size_t index) const;

  // COMMENT There is no need to make this method virtual since it will
  // be the same for all arrays.
  /* RESPONSE removed pure virtual for normal declaration */
      /* find methods that will return the position at which the requested element was found */
      int find(T element) const;

  // COMMENT There is no need to make this method virtual since it will
  // be the same for all arrays.
  /* RESPONSE removed pure virtual for normal declaration */
      int find(T element, size_t start) const;

  // COMMENT There is no need to make this method virtual since it will
  // be the same for all arrays.
  /* RESPONSE removed pure virtual for normal declaration */
      /* fill method to fill array with given element*/
      void fill(T element);

      /* utility function to set the value of a position in the array of data */
      void set(size_t index, T value);

      /* returns the size of the array, usable by all children */
      size_t size() const;

      /* gets the value at the index provided */
      T get(size_t index) const;

    protected:
        /* pointer to data contained in some array */
        T * data_;

        /* current size of the array. Some children may change this. */
        size_t cur_size_;
};

#include "Base_Array.cpp"
#include "Base_Array.inl"
#endif
