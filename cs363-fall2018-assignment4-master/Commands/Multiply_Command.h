#ifndef MULTIPLY_COMMAND
#define MULTIPLY_COMMAND

#include "Binary_Op_Command.h"

class Multiply_Command: public Binary_Op_Command
{
  public:
    /** Intializing constructor 
      * @param   s   reference to a Stack
      * @param   prec    integer representing operators precedence
    */
    Multiply_Command(Stack<int> &s, int prec);

    /* ~Multiply_Command */
    ~Multiply_Command();

    /** @brief Multiplication of two numbers popped off the stack 
      *  @param  num1    the first number to be popped off the stack
      *  @param  num2    the second number to be popped off the stack
      *  @return int     the result of the multiplication of two numbers
    */
    int evaluate(int num1, int num2) const;
};

#endif