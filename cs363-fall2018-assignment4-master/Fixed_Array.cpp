// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
#include <iostream>
#include <exception>

/* Creates a Fixed Array of a predetermined size*/
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void) : 
    Base_Array<T>(N)
{

}

//
// Fixed_Array
//
/* Constructs a copy of another Fixed Array*/
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> &arr) :
    Base_Array<T>(arr)
{
}

//
// Fixed_Array
//
/* Fill constructor that uses Array's fill constructor*/
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill) : 
    Base_Array<T>(N, fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{}


